#include "./timeSup.hpp"
#include "./timeServer.hpp"

using namespace std;

void cleanup(void){
    cout <<"nameSzerv: "<<"cleanup"<<endl;
    delete timeserver;
}

void signalHandler( int signum ) {
   cout <<"nameSzerv: " << "Interrupt signal (" << signum << ") received.\n";
   // cleanup and close up stuff here  
   // terminate program  
   exit(signum);  
}

int elsoUresSzal()
{
    for (int i = 0; i < 10; i++)
    {
        if (szal[i] == 0)
        {
            return i;
        }
    }
    return -1;
}

void threadExit(int id, int sock)
{
    // Close the socket
    close(sock);
    cout << "SZAL lezarasa\n";
    timeserver->semafor->semdown();
    szal[id] = 0;
    timeserver->semafor->semup();
    pthread_exit(NULL);
}



