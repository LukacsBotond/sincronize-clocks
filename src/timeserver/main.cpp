#include "./timeSup.hpp"
#include "./timeServer.hpp"

using namespace std;

int main()
{   
    pthread_t threads[1];
    struct thread_data td[1];
    timeserver = new timeServer;
    //start the accept thread
    int rc = pthread_create(&threads[0], NULL, acc, (void *)&td[0]);
    if (rc)
    {
        cout << "timeServ: "
             << "Error:unable to create thread," << rc << endl;
        exit(-1);
    }
    string a;
    initTimer(10);
    while (1)
    {
        cin>>a;
    }

    return 0;
}