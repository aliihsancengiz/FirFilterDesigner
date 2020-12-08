#ifndef WINDOWFUNCTION_H
#define WINDOWFUNCTION_H

#include <QVector>
#include  <QDebug>

enum class WindowType{Rectegular,
                      Kaiser,
                      Hamming,
                      Hann,
                      Blackman,
                      Gaussian};


class WindowFunction
{
    public:
        static WindowFunction* getInstance();
        QVector<double> getWindow(WindowType type,size_t M);
        WindowFunction();
};

#endif // WINDOWFUNCTION_H
