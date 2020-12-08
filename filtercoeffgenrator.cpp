#include "filtercoeffgenrator.h"

FilterCoeffGenrator::FilterCoeffGenrator()
{

}

QVector<double> FilterCoeffGenrator::getCoefficient(FilterType type,double Fc,size_t order)
{
    QVector<double> coeff;
    coeff.resize(order+1);
    for(size_t i=0;i<=order/2;i++)
    {
        switch (type)
        {
            case FilterType::LOWPASS :
            {
                if(i==(order/2))
                {
                    coeff[i]=sin(2*3.14159265f*Fc*(1.0/order))/(1.0/order);
                }
                else
                {
                    double instant_value=sin(2*3.14159265f*Fc*(order/2-i))/(order/2-i);
                    coeff[i]=instant_value;
                    coeff[order-i]=instant_value;

                }
                break;
            }
            case FilterType::HIGHPASS :
            {
                if(i==(order/2))
                {
                    coeff[i]=pow(-1,i)*sin(2*3.14159265f*Fc*(1.0/order))/(1.0/order);
                }
                else
                {
                    double instant_value=pow(-1,i)*sin(2*3.14159265f*Fc*(order/2-i))/(order/2-i);
                    coeff[i]=instant_value;
                    coeff[order-i]=instant_value;

                }
                break;
            }
            default:
                coeff[i]=1;

        }
    }


    return coeff;
}
