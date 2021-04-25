/*
created by: Yian Xie
ID: a1702241
*/

#include <iostream>
#include <string>

using namespace std;

Customer * order_arrivaledTime(Customer * customers, int size){
    int a = size -1;
    for (a ; a > 0; a--)
    {
        for (int j = 0; j < a; j++)
        {
            bool check = (customers[j].arrivaledTime > customers[j+1].arrivaledTime);
            int c = 0;
            check ? c=1  : c=2;
            if(c == 1){
                swap(customers[j], customers[j+1]);
            }
        }
    }
    return customers;
}

Customer * order_end_time(Customer * customers, int size){
    int a = size - 1;
    for (a ; a > 0; a--)
    {
        for (int j = 0; j < a; j++)
        {
            bool check = (customers[j].end > customers[j+1].end);
            int c = 0;
            check ? c=1  : c=2;
            if(c == 1){
                swap(customers[j], customers[j+1]);
            }
        }
    }
    return customers;
}

Customer * order_priority(Customer * customers, int size){
    int a = size -1;
    for (a ; a > 0; a--)
    {
        for (int j = 0; j < a; j++)
        {
            bool check = (customers[j].priority > customers[j+1].priority);
            int c = 0;
            check ? c=1  : c=2;
            if(c == 1){
                swap(customers[j], customers[j+1]);
            }
        }
    }
    return customers;
}


void order_q1_priority(Customer * queue1, int queue1S, string update_item){
    int nu1 = queue1S;
    Customer * new_queue1_front = new Customer[nu1];
    Customer * new_queue1_back = new Customer[nu1];
    int front_num, back_num ;
    front_num = back_num = 0;
    
    
    for (int i = 0; i < nu1; i++)
    {
        bool check1 = (queue1[i].id_name == update_item);
        if (check1)
        {
            for (int j = 0; j < nu1; j++)
            {
                bool check2 = (queue1[j].priority < queue1[i].priority);
                check2 ? new_queue1_front[front_num] = queue1[j]:new_queue1_back[back_num] = queue1[j];
                check2 ? front_num ++ : back_num ++;
            }
        }
    }
    
    for (int x = 0; x < nu1; x++){
        bool check3 = (x < front_num);
        bool check4 = (x < front_num + back_num);
        if (check3){
            queue1[x] = new_queue1_front[x];
        }else if (check4){
            int step = x - front_num;
            queue1[x] = new_queue1_back[step];
        }
    }
}

Customer * order_runs(Customer * queue1, int queue1S, string update_item, int time)
{
    int front_num, back_num ;
    front_num = back_num = 0;
    
    int si = queue1S;
    
    for (int i = 0; i < si; i++)
    {
        bool checkname = (queue1[i].id_name == update_item) ;
        bool checkruntime = (queue1[i].runTime == queue1[i].lastRun + queue1[i].weightedTime);
        bool checkage = (queue1[i].lastAge != queue1[i].age);

        bool check1 = (checkname && checkruntime && checkage);
        if (check1){
            if (checkruntime)
            {
                Customer * new_queue1_front = new Customer[queue1S];
                Customer * new_queue1_back = new Customer[queue1S];
                for (int j = 0; j < si; j++)
                {
                    bool jnoi = (j != i);
                    if (jnoi)
                    {
                        bool check2 = (queue1[j].priority <= queue1[i].priority);
                        check2 ?  new_queue1_front[front_num] = queue1[j]: new_queue1_back[back_num] = queue1[j];
                        check2 ? front_num ++ : back_num ++;
                    }
                }
                new_queue1_front[front_num] = queue1[i];
                front_num ++;
                
                for (int x = 0; x < si; x++)
                {
                    bool check3 = (x < front_num);
                    bool check4 = (x < front_num + back_num);
                    if (check3)
                    {
                        queue1[x] = new_queue1_front[x];
                    }
                    else if (check4){
                        queue1[x] = new_queue1_back[x - front_num];
                    }
                }
                return queue1;
            }
        }
    }
    return queue1;
}

/* order Q2 */
Customer * order_ticket(Customer * customers, int size)
{
    int o =0;
    for (int i = size-1; i > o; i--)
    {
        for (int j = 0; j < i; j++)
        {
            bool check1 = (customers[j].ticketsNumber > customers[j+1].ticketsNumber);
            bool c1 = (customers[j].ticketsNumber >= customers[j+1].ticketsNumber);
            bool c2 = (customers[j].arrivaledTime > customers[j+1].arrivaledTime);
            bool check2 = (c2 && c2);
            if (check1)
            {
                swap(customers[j], customers[j+1]);
            }
            else if (check2)
            {
                swap(customers[j], customers[j+1]);
            }
        }
    }
    return customers;
}


void update_queues(Customer * customers, int size, int time)
{
    int new_queue1S, new_queue2S;
    new_queue1S = new_queue2S = 0;
    Customer * new_queue1 = new Customer[size];
    Customer * new_queue2 = new Customer[size];
    int s = size+1;
    
    for (int i = 1; i < s; i++)
    {
        bool check = (customers[i-1].countqueue() == 1);
        check ? new_queue1[new_queue1S] = customers[i-1] : new_queue2[new_queue2S] = customers[i-1];
        check ? new_queue1S++ : new_queue2S++ ;

    }
}


int ** update_statue(Customer * customers, int size){
    int * arrivaledTime = new int[size];
    int * runTime = new int[size];
    int * end_time = new int[size];
    int * ready_time = new int[size];
    ready_time[0] = customers[0].arrivaledTime;
    int **out;
    out = new int*[4];
    out[0]=new int[size];
    out[1]=new int[size];
    out[2]=new int[size];
    out[3]=new int[size];
    for (int i = 0; i < size; i++)
    {

        out[0][i] = customers[i].arrivaledTime;
        out[1][i] = customers[i].runTime;
        out[2][i] = ready_time[i-1] + runTime[i-1];
        out[3][i] = ready_time[i] + runTime[i];
    }
    

    return out;
}
