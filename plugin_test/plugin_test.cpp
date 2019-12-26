#include "plugin_test.h"


Plugin_test::Plugin_test()
{

}

Plugin_test::~Plugin_test()
{

}

QString Plugin_test::description()
{
    return "=======";
}

void Plugin_test::process(int a, int b, int &c)
{
    c = a - b;
}
