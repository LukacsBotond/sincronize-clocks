#ifndef klinesSync_H
#define klinesSync_H

#include "../common/Server.h"
#include "../common/Ora.h"
#include "../common/DeValues.h"
#include "../common/EnValues.h"
#include "../common/support.h"
#include "../common/NameSem.h"
#include <thread>
#include <unistd.h>
#include <fcntl.h>
#include <chrono>

class kliensSync
{
public:
    int counter;
    Ora* ORA;
    Server* kliensServer;
    NameSem* szemafor;
    EnValues encode;
    DeValues decode;

    kliensSync(/* args */);
    ~kliensSync();

    void incCounter();
    void startSynk();

};

inline kliensSync* kliensSinkron;

#endif