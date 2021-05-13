#include <iostream>
#include <csignal>
#include <ctime>
#include <sys/time.h>

using namespace std;

#define INTERVAL 500

void signalAlarm(int signum)
{
    cout << "Alarm signal (" << signum << ") received.\n";
}

int main()
{
    struct itimerval it_val; /* for setting itimer */

    /* Upon SIGALRM, call DoStuff().
   * Set interval timer.  We want frequency in ms, 
   * but the setitimer call needs seconds and useconds. */
    if (signal(SIGALRM, (void (*)(int))signalAlarm) == SIG_ERR)
    {
        perror("Unable to catch SIGALRM");
        exit(1);
    }
    it_val.it_value.tv_sec = INTERVAL / 1000;
    it_val.it_value.tv_usec = (INTERVAL * 1000) % 1000000;
    it_val.it_interval = it_val.it_value;
    if (setitimer(ITIMER_REAL, &it_val, NULL) == -1)
    {
        perror("error calling setitimer()");
        exit(1);
    }

    while (1)
    {
        //printf("asdffas");
    }

    return 0;
}