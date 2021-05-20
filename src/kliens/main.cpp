#include <iostream>
#include "../common/support.h"
#include "../common/Ora.h"
#include "../common/Server.h"
#include "./kliensSup.hpp"

using namespace std;

int main()
{
    atexit(cleanup);
    signal(SIGINT, signalHandler);
    signal(SIGTERM, signalHandler);

    initTimer(10);
    ORA = new Ora(100);

    string a;
    while (1)
    {
        cin>>a;
    }

    return 0;
}