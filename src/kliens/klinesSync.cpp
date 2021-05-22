#include "./kliensSync.hpp"

using namespace std;

kliensSync::kliensSync(/* args */)
{
    ORA = new Ora(100);
    kliensServer = new Server(1,54000);
    szemafor = new NameSem();
    szemafor->semdown();
}

kliensSync::~kliensSync()
{
    cout<<"kliens destructor"<<endl;
    delete ORA;
    delete kliensServer;
    delete szemafor;
}

 void kliensSync::incCounter(){
     counter++;
 }

void kliensSync::startSynk(){
    if(counter == 200){
        this->szemafor->semup();
        counter = 0;
    }
 }

