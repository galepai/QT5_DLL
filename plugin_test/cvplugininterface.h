#ifndef CVPLUGININTERFACE_H
#define CVPLUGININTERFACE_H

#include <QtPlugin>
//#include <QObject>
#include <QString>

class CvPluginInterface
{
public:
    virtual ~CvPluginInterface() {}
    virtual QString description() = 0;
    virtual void process(int a, int b, int&c) = 0;
};

#define CVPLUGININTERFACE_IID "com.touchSkyer"
Q_DECLARE_INTERFACE(CvPluginInterface, CVPLUGININTERFACE_IID)

#endif // CVPLUGININTERFACE_H
