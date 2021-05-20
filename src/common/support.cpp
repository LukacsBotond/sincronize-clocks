#include "support.h"
#include <iostream>
#include <csignal>
#include <sys/time.h>
#include "Ora.h"
using namespace std;


//start timer to send SIGALARM at every milisec interval
void initTimer(int milisec)
{
    struct itimerval it_val; /* for setting itimer */
    if (signal(SIGALRM, (void (*)(int))signalAlarm) == SIG_ERR)
    {
        perror("Unable to catch SIGALRM");
        exit(1);
    }
    it_val.it_value.tv_sec = milisec / 1000;
    it_val.it_value.tv_usec = (milisec * 1000) % 1000000;
    it_val.it_interval = it_val.it_value;
    if (setitimer(ITIMER_REAL, &it_val, NULL) == -1)
    {
        perror("error calling setitimer()");
        exit(1);
    }
}