QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    filtercoeffgenrator.cpp \
    main.cpp \
    filterdesigner.cpp \
    qcustomplot.cpp \
    windowfunction.cpp

HEADERS += \
    filtercoeffgenrator.h \
    filterdesigner.h   \
    qcustomplot.h      \
    fft/Array.h        \
    fft/Array.hpp      \
    fft/def.h          \
    fft/DynArray.h     \
    fft/DynArray.hpp   \
    fft/FFTReal.h      \
    fft/FFTReal.hpp    \
    fft/FFTRealFixLen.h \
    fft/FFTRealFixLen.hpp \
    fft/FFTRealPassDirect.h \
    fft/FFTRealPassDirect.hpp \
    fft/FFTRealPassInverse.h \
    fft/FFTRealPassInverse.hpp \
    fft/FFTRealSelect.h \
    fft/FFTRealSelect.hpp \
    fft/FFTRealUseTrigo.h \
    fft/FFTRealUseTrigo.hpp \
    fft/OscSinCos.h \
    fft/OscSinCos.hpp \
    FFTObj.h \
    windowfunction.h


FORMS += \
    filterdesigner.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
