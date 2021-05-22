#include "./kliensSup.hpp"
#include "./kliensSync.hpp"

using namespace std;

void signalAlarm(int signum)
{
    kliensSinkron->ORA->tick();
    kliensSinkron->incCounter();
    kliensSinkron->startSynk();
}

void cleanup(void){
    cout <<"nameSzerv: "<<"cleanup"<<endl;
    delete kliensSinkron;
}
void signalHandler( int signum ) {
   cout <<"nameSzerv: " << "Interrupt signal (" << signum << ") received.\n";
   // cleanup and close up stuff here  
   // terminate program  
   exit(signum);  
}