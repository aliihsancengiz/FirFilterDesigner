#ifndef FILTERDESIGNER_H
#define FILTERDESIGNER_H

#include <QMainWindow>
#include <QDebug>
#include <QtMath>
#include <QFileDialog>

#include <algorithm>
#include <numeric>
#include <fstream>



#include "fft/FFTReal.h"
#include "qcustomplot.h"
#include "windowfunction.h"
#include "filtercoeffgenrator.h"



QT_BEGIN_NAMESPACE
namespace Ui { class FilterDesigner; }
QT_END_NAMESPACE

class FilterDesigner : public QMainWindow
{
    Q_OBJECT

public:
    FilterDesigner(QWidget *parent = nullptr);
    ~FilterDesigner();

private slots:
    void on_DesignButton_clicked();
    void on_pushButton_clicked();

private:
    Ui::FilterDesigner *ui;
    QVector<double> coeff,window;
    WindowFunction mWindowDesigner;
    FilterCoeffGenrator mCoeffGenerator;
    void performFilterBuilding();
    bool isDesigned=false;
};
#endif // FILTERDESIGNER_H
