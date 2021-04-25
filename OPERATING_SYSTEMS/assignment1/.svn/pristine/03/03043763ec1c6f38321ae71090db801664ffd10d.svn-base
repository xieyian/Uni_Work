/*
created by: Yian Xie
ID: a1702241
*/

#include <iostream>
#include <string>
#include <map>

using namespace std;

static int queue1_size = 0;
static int queue2_size = 0;

class Customer
{
public:
    string id_name;
    int arrivaledTime, runTime, lastRun, lastTime, lastUpdate, waitiTime, promoteTime, priority, oPriority, weightedTime, age, countAge, lastAge, runs, ticketsNumber, ticketsNumber1, end, ready, running, waiting;
    map<int, std::string> timeI;
    
    Customer()
    {
        id_name = "";
        arrivaledTime = runTime = lastRun = lastTime = lastUpdate = waitiTime =  priority = oPriority = weightedTime = age = lastAge = countAge = runs = ticketsNumber = ticketsNumber1 = end = running = waiting = 0;
        promoteTime = ready = -1;
        timeI[0] = "x";
    }

    Customer(string id, int time, int c_priority, int c_age, int ticket_num)
    {
        id_name = id;
        arrivaledTime = time;
        runTime = lastRun = lastTime = waitiTime = lastAge = runs = end = waiting = 0;
        promoteTime = -1;
        priority = c_priority;
        oPriority = c_priority;
        weightedTime = (10 - priority) * 10;
        age = c_age;
        ticketsNumber = ticket_num;
        ticketsNumber1 = ticket_num;
        timeI[0] = "x";
        ready = -1;
        running = ticketsNumber * 5;
    }


    int countqueue()
    {
        int countqueue = 0;
        bool check =( priority <= 3);
        countqueue = check ? countqueue = 1 : countqueue = 2;
        return countqueue;
    }

};
