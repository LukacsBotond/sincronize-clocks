#include <iostream>
#include "./kliensSup.hpp"
#include "./kliensSync.hpp"

using namespace std;
struct thread_data
{
};

void *sync(void *threadarg)
{
    int recfrom = kliensSinkron->kliensServer->SockToServ;
    while (true)
    {
        kliensSinkron->szemafor->semdown();
        cout<<"start synk"<<endl;
        int currTime = kliensSinkron->ORA->getTime();
        string send = kliensSinkron->encode.getString("time");
        string ret;
        //timing
        
        auto begin = std::chrono::high_resolution_clock::now();
        kliensSinkron->kliensServer->Sending(send);
        auto end = std::chrono::high_resolution_clock::now();
        
        auto beginrec = std::chrono::high_resolution_clock::now();
        ret = kliensSinkron->kliensServer->Recive(recfrom);
        auto endrec = std::chrono::high_resolution_clock::now();
        
        double T0 = chrono::duration_cast<std::chrono::nanoseconds>(end-begin).count();
        cout << T0/1000000 << "ms" << std::endl;

        double T1 = chrono::duration_cast<std::chrono::nanoseconds>(endrec-beginrec).count();
        cout << T1/1000000 << "ms" << std::endl;

        int szerverTime = kliensSinkron->decode.decInt(ret);
        cout<<"szerverTime:" << szerverTime<<endl;
    }
}

int main()
{
    atexit(cleanup);
    signal(SIGINT, signalHandler);
    signal(SIGTERM, signalHandler);

    initTimer(10);
    kliensSinkron = new kliensSync();
    pthread_t threads[1];
    struct thread_data td[1];
    int rc = pthread_create(&threads[0], NULL, sync, (void *)&td[0]);
    if (rc)
    {
        cout << "nameSzerv: "
             << "Error:unable to create thread," << rc << endl;
        exit(-1);
    }

    string a;
    while (1)
    {
        cin>>a;
    }

    return 0;
}