#include <iostream>
#include <ctime>
#include <csignal>
#include <unistd.h>
#include <signal.h>
#include <vector>
#include <unordered_map>
#include <pthread.h>

using namespace std;

vector< pair<void*(*)(void*),int> > f_table;
unordered_map <void*(*)(void*),int > f_map;

void print_time (void)
{
    time_t rawtime;
    struct tm * timeinfo;
    time ( &rawtime );
    timeinfo = localtime ( &rawtime );
    cout<<"Current local time and date:"<<asctime(timeinfo);

}

void p_time_handler (int sigval)
{
    cout<<"handler 1 sigval: "<<sigval<<endl;
    print_time();
  //  alarm(4);
   // signal(SIGALRM, p_time_handler);
}

void p_time_handler1 (int sigval)
{
    cout<<"handler 2 sigval: "<<sigval<<endl;
    print_time();
  //  alarm(5);
    //signal(SIGALRM, p_time_handler);
}


int DoItLater(void (*func)(int), int delay_s) 
{
   
    f_table.push_back(make_pair((void *(*)(void *))func, delay_s));
    f_map[(void *(*)(void *))func] = delay_s;

    return 0;
}

void* timer_thread(void *arg) 
{
    //cout << "timer thread"<<endl;
    while (1) {
        //cout << "timer thread"<<endl;
        for (int i = 0 ; i < f_table.size(); i++) {
            if (f_table[i].second == 1) {
                (f_table[i].first)((void *)1);
                f_table[i].second = f_map[f_table[i].first];
            } else {
                f_table[i].second--;
            }
        }
        sleep(1);
    }

}


int main (void) 
{
    pthread_t p_tid;

    int rc = pthread_create(&p_tid, NULL, &timer_thread, NULL);
    if (rc ) {
        cout<<"thread creatd failed"<<endl;
    }
    //print_time();
    void (*ptr)(int) = p_time_handler;
    //print_time();
    DoItLater(ptr, 10);
    ptr = p_time_handler1;
    DoItLater(ptr, 5);

    // signal(SIGALRM, p_time_handler);
    // p_time_handler(0);
    //while (1) {}
     pthread_join( p_tid, NULL);

    return 0;
}
