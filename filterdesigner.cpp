#include "filterdesigner.h"
#include "ui_filterdesigner.h"

#include "FFTObj.h"

FilterDesigner::FilterDesigner(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::FilterDesigner)
{
    ui->setupUi(this);

    ui->FilterSellector->addItem(QString("Low Pass"));
    ui->FilterSellector->addItem(QString("High Pass"));


    ui->WindowTypeSellector->addItem(QString("Rectangular"));
    ui->WindowTypeSellector->addItem(QString("Hamming"));
    ui->WindowTypeSellector->addItem(QString("Hann"));
    ui->GainPlotter->addGraph();
    coeff.resize(1024);
    window.resize(1024);
    std::fill(coeff.begin(),coeff.end(),1);
    std::fill(window.begin(),window.end(),1);


}

FilterDesigner::~FilterDesigner()
{
    delete ui;
}

void FilterDesigner::on_DesignButton_clicked()
{
    performFilterBuilding();
}



void FilterDesigner::performFilterBuilding()
{
    isDesigned=true;
    float x[1024],y[1024];
    int M=ui->FilterOrder->text().toInt();
    int Fc=ui->CuttOffFrequency->text().toInt();
    int Fs=ui->SampleFrequency->text().toInt();
    double nFc=0.5f*(double)Fc/((double)Fs*0.5);

    // take filter coeff
    if(ui->FilterSellector->currentIndex()==0)
    {
        coeff=mCoeffGenerator.getCoefficient(FilterType::LOWPASS,nFc,M);
    }
    else if(ui->FilterSellector->currentIndex()==1)
    {
        coeff=mCoeffGenerator.getCoefficient(FilterType::HIGHPASS,nFc,M);
    }


    if(ui->WindowTypeSellector->currentIndex()==0)
    {
        window=mWindowDesigner.getWindow(WindowType::Rectegular,M);
    }
    else if(ui->WindowTypeSellector->currentIndex()==1)
    {
        window=mWindowDesigner.getWindow(WindowType::Hamming,M);
    }
    else if(ui->WindowTypeSellector->currentIndex()==2)
    {
        window=mWindowDesigner.getWindow(WindowType::Hann,M);
    }



    // Make filter windowed
    for(int i=0;i<coeff.size();i++)
    {
        coeff[i]=coeff[i]*window[i];
    }

    // Padding
    for(int i=0;i<1024;i++)
    {
        if(i<coeff.size())
        {
            x[i]=coeff[i];
        }
        else
        {
            x[i]=0;
        }
    }

    // Do fft
    fft_object.do_fft(y,x);


    // Create plot values
    QVector<double> xAxis,yAxis;
    for(int i=0;i<512;i++)
    {
        xAxis.push_back(((double)i/512.0)*(double)Fs*0.5);
        yAxis.push_back(sqrt(y[i]*y[i]+y[i+512]*y[i+512]));
    }

    ui->GainPlotter->graph(0)->setData(xAxis,yAxis);
    ui->GainPlotter->xAxis->setRange(0,(double)Fs*0.5f);
    ui->GainPlotter->yAxis->setRange(*std::min_element(yAxis.constBegin(),yAxis.constEnd()),*std::max_element(yAxis.constBegin(),yAxis.constEnd())*1.1);
    ui->GainPlotter->replot();
}

void FilterDesigner::on_pushButton_clicked()
{
    QString filename= QFileDialog::getSaveFileName(this,
                                                   tr("Save Filter Coefficient"), "",
                                                   tr("Text Files (.txt)"));
    if(isDesigned && filename.size()>0)
    {
        std::ofstream ofs;
        ofs.open(filename.append(".txt").toStdString());
        for(auto e:coeff)
        {
            ofs<<e<<std::endl;
        }

    }

}
