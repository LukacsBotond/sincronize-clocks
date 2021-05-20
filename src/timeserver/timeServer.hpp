#ifndef timeServ_H
#define timeServ_H

#include "./timeSup.hpp"

struct thread_data
{
    int id;
    int ksock;
};

void *acc(void *threadarg);
void *recv(void *threadarg);

class timeServer
{
public:
    NameSem *semafor;
    Server *timeserver;
    EnValues encode;
    Ora *ORA;

    timeServer(/* args */);
    ~timeServer();
};

inline timeServer *timeserver;

#endif