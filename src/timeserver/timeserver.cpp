#include "./timeSup.hpp"
#include "./timeServer.hpp"
using namespace std;

void signalAlarm(int signum)
{
    timeserver->ORA->tick();
}

timeServer::timeServer(/* args */)
{
    cout<<"timeServer destruktor"<<endl;
    timeserver = new Server(54000);
    semafor = new NameSem();
    ORA = new Ora(100);
}

timeServer::~timeServer()
{
    delete timeserver;
    delete semafor;
    delete ORA;
}


void* acc(void *threadarg)
{
    pthread_t threads[10];
    struct thread_data td[10];
    cout << "timeSzerv: "
         << "accept loop starts" << endl;
    while (true)
    {
        timeserver->timeserver->accepter();
        int ksock = timeserver->timeserver->connetedToMe.back();
        //create thread for each client
        int i = elsoUresSzal();
        if (i < 0)
        {
            cout << "nem lehet tobb szalat letrehozni,\n probalkozzon kesobb" << endl;
            continue;
        }
        td[i].ksock = ksock;
        td[i].id = i;
        szal[i] = 1;
        int rc = pthread_create(&threads[i], NULL,recv, (void *)&td[i]);
        if (rc)
        {
            cout << "timeServ: "
                 << "Error:unable to create thread," << rc << endl;
            exit(-1);
        }

        cout << "timeSzerv: "
             << "klient connected to timeServ" << endl;
    }
}

//kliensnek kuldi a jelenlegi idot
void* recv(void *threadarg)
{
    struct thread_data *my_data;
    my_data = (struct thread_data *)threadarg;
    int ksock = my_data->ksock;
    string rec;
    while (true)
    {
        try
        {
            //string erkezik a keressel
            timeserver->timeserver->Recive(ksock);
        }
        catch (disconected &e)
        {
            cout << "timeServ: kliens " << ksock << "disconnected" << endl;
            threadExit(my_data->id, my_data->ksock);
            continue;
        }
        catch (noData &e)
        {
            throw out_of_range("not supposed to be here");
        }
        try
        {
            timeserver->timeserver->Sending(timeserver->encode.getString(timeserver->ORA->getTime()), ksock);
        }
        catch (disconected &e)
        {
            cout << "timeServ: kliens " << ksock << "disconnected" << endl;
            threadExit(my_data->id, my_data->ksock);
        }
    }
}

