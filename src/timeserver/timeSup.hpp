#ifndef timeSup_H
#define timeSup_H

#include <iostream>
#include "../common/Ora.h"
#include "../common/Server.h"
#include "../common/EnValues.h"
#include "../common/support.h"
#include "../common/NameSem.h"
#include <chrono>
#include <thread>

void cleanup(void);

void signalHandler( int signum );

int elsoUresSzal();

void threadExit(int id, int sock);

inline int szal[10] = {0};

#endif