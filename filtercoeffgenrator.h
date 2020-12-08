#ifndef FILTERCOEFFGENRATOR_H
#define FILTERCOEFFGENRATOR_H

#include <QVector>
#include <QtMath>

enum class  FilterType{LOWPASS,HIGHPASS,BANDPASS,BANDSTOP};


class FilterCoeffGenrator
{
    public:
        FilterCoeffGenrator();
        QVector<double> getCoefficient(FilterType type,double Fc,size_t order);



};

#endif // FILTERCOEFFGENRATOR_H
