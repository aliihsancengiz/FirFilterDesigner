#include "windowfunction.h"

QVector<double> WindowFunction::getWindow(WindowType type,size_t M)
{
    QVector<double> temp;
    M++;
    temp.resize(M);
    for(size_t i=0;i<M;i++)
    {
        switch (type)
        {
            case WindowType::Rectegular:
            {
                temp[i]=1;
                break;
            }
            case WindowType::Hamming:
            {

                temp[i]=0.54f-0.46*cos(2*M_PI*(double)i/M);
                break;
            }
            case WindowType::Hann:
            {
                temp[i]=0.5f-0.5f*cos(2*M_PI*(double)i/M);
                break;
            }
            default:
                temp[i]=1;

        }
    }
    return temp;
}

WindowFunction::WindowFunction()
{

}
