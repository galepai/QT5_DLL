#ifndef PLUGIN_TEST_H
#define PLUGIN_TEST_H

#include "plugin_test_global.h"
#include "cvplugininterface.h"

class PLUGIN_TESTSHARED_EXPORT Plugin_test : public QObject,public CvPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID CVPLUGININTERFACE_IID)
    Q_INTERFACES(CvPluginInterface)

public:
    Plugin_test();
    ~Plugin_test();
    QString description();
    void process(int a,int b,int& c);
};

#endif // PLUGIN_TEST_H
