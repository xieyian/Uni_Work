/*
created by: Yian Xie
ID: a1702241
*/
using namespace std;
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "customer.cpp"
#include "utils.cpp"




bool arrivedOrNot(Customer * queue1, Customer * queue2, int queue1_size, int queue2_size, int time, int start)
{
    Customer * arrivals = new Customer[queue1_size];
    int arrivals_num = 0;
    int index[queue1_size];
    
    for (int i = 0; i < queue1_size; i++)
    {
        bool c1 = (start == 0);
        bool c2 = (queue1[i].arrivaledTime == time);
        bool c3 =(start > 0);
        bool c4 = (queue1[i].arrivaledTime == time);
        if (c1 && c2)
        {
            return true;
        }
        else if (c3 && c4)
        {
            arrivals[arrivals_num] = queue1[i];
            index[arrivals_num] = i;
            arrivals_num ++;
        }
    }

    bool check1 = (arrivals_num > 0);
    bool out;
    
    if (check1)
    {
        Customer * new_queue1 = new Customer[queue1_size];
        int num = 0;
        int j = 0;
        while(j <queue1_size){
            int jnum = 0;
            for (int k = 0; k < arrivals_num; k++)
            {
                bool check2 = (j != index[k]) ;
                if (check2){
                    jnum ++;
                }
            }
            bool check3 = (jnum == arrivals_num);
            if (check3){
                new_queue1[num] = queue1[j];
                num ++;
            }
            j++;
        }

        int a1 = 0;
        while(a1<arrivals_num){
            new_queue1[num+a1] = queue1[index[a1]];
            a1++;
        }
        int a2=0;
        while(a2<queue1_size){
            queue1[a2] = new_queue1[a2];
            a2++;
        }
        return true;
    }
    int count1 = 0;
    while(count1<queue2_size){
        bool ch = (queue2[count1].arrivaledTime == time);
        if(ch){
            return true;
        }
        count1++;
    } 
    out = false;
    return out;
}

bool arrival_queue1(Customer * queue1, Customer * queue2, int queue1_size, int queue2_size, int time, int start, string update_item)
{
    bool check;
    int arrivals_num = 0;
    for (int i = 0; i < queue1_size; i++)
    {
        bool check1 = (start > 0);
        bool check2 = (queue1[i].arrivaledTime == time);
        bool check3 = (queue1[i].id_name == update_item);
        if (check1 && check2 && check3){   
            check = true;
        }
    }
    check=false;
    return check;
}

string update_permission(Customer * queue1, Customer * queue2, int queue1_size, int queue2_size, int time)
{
    int i = 0;
    while(i< queue1_size){
        bool check1 = (queue1[i].arrivaledTime+1 <= time);
        bool check2 = (queue1[i].ticketsNumber > 0);
        if (check1 && check2)
        {
            (queue1[i].ready == -1) ? queue1[i].ready = time - 1 : NULL ;
            return queue1[i].id_name;
        }
        i++;
    } 
    for (int i = 0; i < queue2_size; i++)
    {
        bool check1 = (queue2[i].arrivaledTime+1 <= time);
        bool check2 = (queue2[i].ticketsNumber > 0);
        if (check1 && check2)
        {
            (queue2[i].ready == -1) ? queue2[i].ready = time - 1 : NULL;
            return queue2[i].id_name;
        }
    }
    return "have error!!!";
}

string find_permission(Customer * queue1, Customer * queue2, int queue1_size, int queue2_size, int time)
{
    int i = 0;
    while(i < queue1_size){
        bool check1 = (queue1[i].arrivaledTime <= time);
        bool check2 = (queue1[i].ticketsNumber > 0);
        if (check1 && check2){
            return queue1[i].id_name;
        }
        i++;
    }

    for (int i = 0; i < queue2_size; i++)
    {
        bool check1 = (queue2[i].arrivaledTime <= time);
        bool check2 = (queue2[i].ticketsNumber > 0);
        
        if (check1 && check2)
        {
            return queue2[i].id_name;
        }
    }
    return "have error!!!";
}

void updateRunningTime(Customer * queue, int size, int time, string update_item)
{
    int j = 0;
    while(j < size){
        bool check1 = (update_item == queue[j].id_name);
        bool check2 = (queue[j].end == 0);
        bool check3 = (update_item != queue[j].id_name );
        bool check4 = (queue[j].ready != -1);
        bool check5 = (queue[j].end == 0);
        if (check1 && check2)
        {
            queue[j].runTime = time - queue[j].ready - queue[j].waitiTime;
        }
        else if (check3 && check4 && check5)
        {   
            int a = queue[j].waitiTime;
            a++;
            queue[j].waitiTime=a; 
        }
        j++;
    }

}

void update_lastRun(Customer * queue, int size, string update_item, int time)
{
    for (int j = 0; j < size; j++)
    {
        (update_item == queue[j].id_name) ?  queue[j].lastRun = queue[j].runTime : NULL;
    }
}

void updateTicketNumber(Customer * queue, int size, string update_item)
{
    for (int j = 0; j < size; j++)
    {
        (update_item == queue[j].id_name) ? queue[j].ticketsNumber = queue[j].ticketsNumber - 1: NULL ; 
    }
}

void updateAgeNumbe(Customer * queue, int size, int time, string update_item)
{
    for (int j = 0; j < size; j++)
    {
        bool check1 = (queue[j].ticketsNumber > 0);
        bool check2 = (queue[j].arrivaledTime+1 <= time);
        bool check3 = (queue[j].id_name != update_item);
        bool check4 = (queue[j].promoteTime == -1);
        bool check5 = (queue[j].promoteTime != -1);
        bool check6 = (queue[j].id_name == update_item);

        if (check1 && check2 && check3 && check4)
        {
            int calage = (queue[j].oPriority-queue[j].priority)*100;
            int calsetage = time - queue[j].arrivaledTime - queue[j].runTime;
            (queue[j].lastTime != 0) ? queue[j].age = time - queue[j].lastTime : queue[j].age = calage - calsetage;
        }
        else if (check1 && check2 && check3 && check5)
        {
            queue[j].age = time - queue[j].promoteTime;
        }
        else if (check6)
        {
            int time = queue[j].runTime + 1 - queue[j].lastRun - queue[j].lastTime;
            queue[j].age = time;
        }
    }
}

void update_lastAge(Customer * queue, int size, string update_item)
{
    for (int j = 0; j < size; j++)
    {
       
        (queue[j].id_name == update_item) ? (queue[j].lastAge = queue[j].age) : NULL;
    }
}

void updateQ2Priority(Customer * queue2, int queue2_size, int time)
{
    for (int j = 0; j < queue2_size; j++)
    {
        (queue2[j].age != queue2[j].countAge) ?  queue2[j].age = queue2[j].countAge : NULL ;
    }
    
    for (int j = 0; j < queue2_size; j++)
    {
        if (queue2[j].age >= 100)
        {
            int setq2priorty = queue2[j].priority - 1;
            (queue2[j].priority  < 2) ? ( queue2[j].priority = 1) : (queue2[j].priority = setq2priorty);
            int a = 100;
            queue2[j].age = queue2[j].age - a;
        }
    }
}

void updateQ2Priority(Customer * queue2, int queue2_size)
{
    for (int j = 0; j < queue2_size; j++)
    {
        (queue2[j].age != queue2[j].countAge) ?  (queue2[j].age = queue2[j].countAge) : NULL ;
    }
    
    for (int j = 0; j < queue2_size; j++)
    {
        if (queue2[j].age >= 100)
        {
            int setage1 =  queue2[j].age - 100;
            int setpriority1 = queue2[j].priority - 1;
            (queue2[j].priority < 2) ? (queue2[j].priority = 1): (queue2[j].priority = setpriority1);
            queue2[j].age = setage1;
        }
    }
}


bool end_or_not(Customer * queue1, Customer * queue2, int queue1_size, int queue2_size, string update_item, int time)
{
    bool out;
    for (int i = 0; i < queue1_size; i++)
    {   
        bool check1 = (queue1[i].id_name == update_item);
        int chtime = queue1[i].ready + queue1[i].runTime;
        int chtime1 = chtime +queue1[i].waitiTime + queue1[i].ticketsNumber*5;
        bool check2 = (chtime1  == time);
        if (check1 && check2)
        {
            queue1[i].end = time; 
            return true;
        }
    }
    for (int i = 0; i < queue2_size; i++)
    {
        int chtime = queue2[i].ready + queue2[i].runTime;
        int chtime1 = chtime +queue2[i].waitiTime + queue2[i].ticketsNumber*5;
        bool check1 = (queue2[i].id_name == update_item);
        bool check2 = (chtime1 == time);
        if (check1 && check2)
        {
            queue2[i].end = time;
            out = true; 
            return out;
        }
    }
    out = false;
    return out;
}

void update_runs(Customer * queue1, int queue1_size, string update_item, int time)
{
    int i = 0;
    while(i < queue1_size) {
        queue1[i].weightedTime = (10 - queue1[i].priority) * 10;
        bool check1 = (queue1[i].id_name == update_item);
        bool check2 = (queue1[i].runTime == queue1[i].lastRun + queue1[i].weightedTime);

        if (check1 && check2)
        {
            bool check3 = (queue1[i].runTime == queue1[i].lastRun + queue1[i].weightedTime);
            if (check3)
            {
                update_lastAge(queue1,queue1_size,update_item);
                bool check4 = (queue1[i].age == 0);
                if (check4)
                {
                    queue1[i].age = 1;
                }
                else
                {
                    queue1[i].age = 0;
                    queue1[i].priority = queue1[i].priority + 1; 
                    
                }
            }
        }
        i++;
    }
}

bool update_runs_or_not(Customer * queue1, int queue1_size, string update_item, int time)
{
    int qs = queue1_size;
    for (int i = 0; i < queue1_size; i++)
    {
        qs = time+qs;
        queue1[i].weightedTime = (10 - queue1[i].priority) * 10;
        
        bool check1 = (queue1[i].id_name == update_item);
        bool check2 = (queue1[i].runTime == queue1[i].lastRun + queue1[i].weightedTime);
        if (check1 && check2)
        {
            int cheek3 = queue1[i].lastRun + queue1[i].weightedTime;
            bool check3 = (queue1[i].runTime == cheek3); 
            if (check3)
            {
                return true;
            }
        }
    }
    return false;
}

bool loop_end_or_not(Customer * queue1, Customer * queue2, int queue1_size, int queue2_size, int time)
{
    int q1_num, q2_num, q1_index, q2_index;
    q1_num = q2_num = q1_index = q2_index = 0;
    
    for (int i = 0; i < queue1_size; i++)
    {
        bool check1 = (queue1[i].ticketsNumber > 0);
        if (check1)
        {
            q1_index = i;
            q1_num ++;
            
        }
    }
    for (int i = 0; i < queue2_size; i++)
    {
        bool check2 = (queue2[i].ticketsNumber > 0);
        if (check2)
        {
            q2_index = i;
            q2_num ++;
        }
    }
    bool check3 = ((q1_num + q2_num) > 1);
    if (check3)
    {
        return true;
    }
    bool check4 = (q2_num == 1);
    if (check4)
    {
        bool check5 = (queue2[q2_index].end == time);
        if (check5)
        {
            return false;
        }
    }
    bool check6 = (q1_num > 0);
    bool c2 = (q2_num > 0);
    if (check6)
    {
        bool check7 = (queue1[q1_index].ticketsNumber > 0);
        bool check8 = (queue1[q1_index].age == 0 );
        bool check9 = (queue1[q1_index].arrivaledTime < time);
        if (check7 && check8 && check9)
        {
            queue1[q1_index].end = time - 1 + queue1[q1_index].ticketsNumber * 5;
        }else{
            return true;
        }
        
        bool c1 = (queue1[q1_index].ready == -1);
        if (c1){
            queue1[q1_index].ready = time - 1;
        }
    }
    else if(c2)
    {
        bool c3 = (queue2[q2_index].ticketsNumber > 0);
        bool c4 = (queue2[q2_index].arrivaledTime < time);
        if (c3 && queue2[q2_index].age == 0 && queue2[q2_index].arrivaledTime < time)
        {
            int calend = time - 1 + queue2[q2_index].ticketsNumber * 5;
            queue2[q2_index].end = calend;
        }
        else
        {
            return true;
        }
        
        (queue2[q2_index].ready == -1) ?  queue2[q2_index].ready = time - 1: NULL ;

    }
    return false;
}

bool update_permission_or_not(Customer * queue1, Customer * queue2, int queue1_size, int queue2_size, int time)
{
    bool print_update = false;
    bool out;
    bool in_queue2 = false;
    string update_item = find_permission(queue1,queue2,queue1_size,queue2_size,time);
    
    for (int j = 0; j < queue2_size; j++)
    {
        bool check1 = (queue2[j].lastUpdate != time );
        string cal = queue2[j].timeI.find(queue2[j].lastUpdate)->second;
        bool check1a = (cal != update_item);


        if (check1 &&  check1a)
        {
            print_update = true;
            break;
        }
    }
    
    for (int j = 0; j < queue2_size; j++)
    {
        bool check3 = (queue2[j].arrivaledTime == time);
        if (check3)
        {
            queue2[j].lastUpdate = time;
            int timea = time;   
            queue2[j].timeI[time] = update_item;
        }
    }
    
    for (int j = 0; j < queue2_size; j++)
    {
        bool check4 = (queue2[j].id_name == update_item);
        if (check4)
        {
            in_queue2 = true;
            break;
        }
    }
    
    if ( in_queue2){
        if(print_update){
            for (int j = 0; j < queue2_size; j++){
                queue2[j].lastUpdate = time;
                int timea = time;
                queue2[j].timeI[timea] = update_item;
            }
            out =true;
            return out;
        }
    }
    out = false;
    return out;
}


void print_process(Customer * queue1, Customer * queue2, int queue1_size, int queue2_size, int * ready_time)
{
    int time, settime, start;
    settime = 0;
    time = start = settime;
    
    while (loop_end_or_not(queue1,queue2,queue1_size,queue2_size,time)){
        bool upornot = false;
        queue2 = order_ticket(queue2,queue2_size);
        
        string update_item = update_permission(queue1,queue2,queue1_size,queue2_size,time);
        bool Q1_updated = upornot;
        
        bool c11 = (time % 5 == 0);
        if (c11)
        {
            for (int j = 0; j < queue1_size; j++)
            {
                (update_item == queue1[j].id_name) ? queue1[j].ticketsNumber = queue1[j].ticketsNumber - 1: NULL ; 
            }
            for (int j = 0; j < queue2_size; j++)
            {
                (update_item == queue2[j].id_name) ? queue2[j].ticketsNumber = queue2[j].ticketsNumber - 1: NULL ; 
            }
        }
        updateRunningTime(queue1,queue1_size,time,update_item);
        updateRunningTime(queue2,queue2_size,time,update_item);
        
 
        int j = 0;
        while(j < queue2_size){
            bool ch1 = (queue2[j].arrivaledTime < time);
            bool ch2 = (queue2[j].id_name != update_item);
            (ch1 && ch2) ? queue2[j].countAge ++ : NULL ;
            bool ch3 = (queue2[j].countAge >= 100);
            if (ch3)
            {
                queue2[j].priority --;
                queue2[j].countAge = 0;
                
            }
            j++;    
        }
        int calcount=queue1_size;
        
        updateAgeNumbe(queue2,queue2_size,time,update_item);
        updateQ2Priority(queue2,queue2_size,time);
        
        int queue1_index = 0;
        int oQueue1S = calcount;
        calcount = time;
        Customer * new_queue1 = new Customer[oQueue1S];
        for (int i = 0; i < oQueue1S; i++)
        {
            bool check1 = (queue1[i].priority > 3);
            if (check1)
            {
                queue2[queue2_size] = queue1[i];
                queue2[queue2_size].promoteTime = time;
                queue1_size --;
                queue2_size ++;
            }
            else{
                int count = queue1_index;
                new_queue1[queue1_index] = queue1[i];
                queue1_index ++;
            }
        }
        int i = 0;
        while(i<queue1_size){
            queue1[i] = new_queue1[i];
            i++;
        }
        queue2 = order_ticket(queue2,queue2_size);
        
        string promote_item = "";
        int q2toq1_num, queue2_index;
        q2toq1_num = queue2_index = 0;
        int o_queue2_size = queue2_size;
        Customer * new_queue2 = new Customer[o_queue2_size];
        for (int i = 0; i < o_queue2_size; i++)
        {
            bool c1 = (queue2[i].priority <= 3);
            bool c2 = (queue2[i].priority > 3);
            if (c1)
            {
                queue1[queue1_size] = queue2[i];
                int setage1 = 0;
                queue1[queue1_size].promoteTime = time;
                queue1[queue1_size].age = setage1;
                promote_item = queue1[queue1_size].id_name;
                bool c2 = true;
                queue2_size --;
                q2toq1_num ++;
                queue1_size ++;
                Q1_updated = c2;
            }
            else if (c2)
            {
                new_queue2[queue2_index] = queue2[i];
                queue2_index ++;
            }
        }
        if (Q1_updated)
        {
            int ic1 = 0;
            while(ic1 < queue2_size){
                queue2[ic1] = new_queue2[ic1];
                ic1++;
            }
        }

        bool checkupdate = (Q1_updated == true && q2toq1_num > 0);
        if (checkupdate)
        {
            int end_items = 0;
            for (int i = 0; i < queue1_size; i++)
            {
                for (int j = 0; j < q2toq1_num; j++)
                {
                    (queue1[i].id_name == promote_item && queue1[i].end > 0) ? (end_items ++) : NULL;
                }
            }
            (end_items == q2toq1_num) ? Q1_updated = false : NULL;
        }
        bool checkend = end_or_not(queue1,queue2,queue1_size,queue2_size,update_item,time);
        if (checkend)
        {
            updateRunningTime(queue2,queue2_size,time,update_item);
            updateQ2Priority(queue2,queue2_size);
            int set_index = 0;
            int queue1_index = set_index;
            int oQueue1S = queue1_size;
            Customer * new_queue1 = new Customer[oQueue1S];
            for (int i = 0; i < oQueue1S; i++)
            {
                int settime = time;
                bool chec1 = (queue1[i].priority > 3);
                bool chec2 = (queue1[i].priority <= 3);
                if (chec1)
                {
                    queue2[queue2_size] = queue1[i];
                    queue2[queue2_size].promoteTime = settime;
                    queue1_size --;
                    queue2_size ++;
                }
                else if (chec2)
                {
                    new_queue1[queue1_index] = queue1[i];
                    queue1_index ++;
                }
            }
            int counti =0;
            while(counti < queue1_size){
                queue1[counti] = new_queue1[counti];
                counti++;
            }
            queue2 = order_ticket(queue2,queue2_size);
            
            int setQueue2size = queue2_size;
            string setpitem = "";
            int setq2index = 0;
            string promote_item = setpitem;
            int o_queue2_size = setQueue2size;
            int queue2_index = setq2index;
            
            Customer * new_queue2 = new Customer[o_queue2_size];
            for (int i = 0; i < o_queue2_size; i++)
            {
                bool check1 = (queue2[i].priority <= 3);
                bool check2 =  (queue2[i].priority > 3);
                if (check1)
                {

                    queue1[queue1_size] = queue2[i];
                    int setagenow = -1;
                    queue1[queue1_size].promoteTime = time;
                    queue1[queue1_size].age = setagenow + 1;
                    promote_item = queue1[queue1_size].id_name;
                     
                    queue2_size --;
                    queue1_size ++;
                    Q1_updated = true;
                }
                else if (check2)
                {
                    new_queue2[queue2_index] = queue2[i];
                    queue2_index ++;
                }
            }
            if (Q1_updated)
            {
                int i = 0;
                while(i < queue2_size){
                    queue2[i] = new_queue2[i];
                    i++;
                }
            }
        }
        
        bool c1 = arrivedOrNot(queue1,queue2,queue1_size,queue2_size,time,start);
        if (c1)
        {
            update_item = find_permission(queue1,queue2,queue1_size,queue2_size,time);
            bool c2 = arrival_queue1(queue1,queue2,queue1_size,queue2_size,time,start,update_item);
            if (c2)
            {
                for (int j = 0; j < queue2_size; j++)
                {
                    string c3 =  queue2[j].timeI.find(queue2[j].lastUpdate)->second;
                    bool c4 = (queue2[j].id_name == c3);
                    bool c5 = (queue2_size > 0);
                    if (c4 && c5)
                    {
                        update_item = find_permission(queue1,queue2,queue1_size,queue2_size,time);
                        update_lastRun(queue1,queue1_size,update_item,time); 
                        int setage = 0;
                        queue2[j].countAge = setage;
                        queue2[j].age = setage;
                    }

                    bool c6 = (queue2[j].lastUpdate != time);
                    string c8 = queue2[j].timeI.find(queue2[j].lastUpdate)->second;
                    bool c7 = (c8 != update_item);
                    if (c6 && c7)
                    {   
                        
                        queue2[j].lastUpdate = time;
                        int settime = time+1;
                        queue2[j].timeI[settime-1] = update_item;
                    }
                }
            }   
            start ++;
            updateRunningTime(queue2,queue2_size,time,update_item);
            int setstart = start;
            updateQ2Priority(queue2,queue2_size);
            queue2 = order_ticket(queue2,queue2_size);

        }
        bool checkQ1 = !Q1_updated;
        if (!checkQ1)
        {
            bool print_update = false;
            update_item = find_permission(queue1,queue2,queue1_size,queue2_size,time);
            
            for (int j = 0; j < queue2_size; j++)
            {
                bool checkequal = (Q1_updated == true);
                bool checkequal1 = (queue2[j].id_name == queue2[j].timeI.find(queue2[j].lastUpdate)->second);
                bool checkequal2 = (queue2_size > 0);
                if (checkequal1 && checkequal2  && checkequal )
                {
                    update_item = find_permission(queue1,queue2,queue1_size,queue2_size,time);
                    update_lastRun(queue1,queue1_size,update_item,time); 
                    int setcurrentage = 0;
                    queue2[j].countAge = queue2[j].age = setcurrentage;
                }
                bool notequal = (queue2[j].lastUpdate != time);
                bool notequal1 = (queue2[j].timeI.find(queue2[j].lastUpdate)->second != update_item);
                int setnotequaltime = time;
                
                if ( notequal && notequal1){
                    queue2[j].lastUpdate = setnotequaltime;
                    queue2[j].timeI[time] = update_item;
                    bool checktheupdat = false;
                    print_update = !checktheupdat;
                }
            }
        }
        bool checkupdateornot = update_runs_or_not(queue1,queue1_size,update_item,time);
        if (checkupdateornot)
        {
            int ti1 = time;
            int q1size1 = queue1_size;
            int q2size1 = queue2_size ;
            update_runs(queue1,queue1_size,update_item,time);
            updateAgeNumbe(queue2,queue2_size,time,update_item);
            int q2size2 = queue2_size ;
            updateQ2Priority(queue2,queue2_size);
            queue1 = order_runs(queue1,queue1_size,update_item,time);
            update_lastRun(queue1,queue1_size,update_item,time); 
            int ti2 = time - 1;
            update_item = find_permission(queue1,queue2,queue1_size,queue2_size,time);
            order_q1_priority(queue1,queue1_size,update_item);
            int setq1sindex = -1;
            int queue1_index = setq1sindex + 1;
            int oQueue1S = queue1_size;
            Customer * new_queue1 = new Customer[oQueue1S];
            for (int i = 0; i < oQueue1S; i++)
            {
                bool check1pri = (queue1[i].priority > 3);
                bool check2pri = (queue1[i].priority <= 3);
                if (check1pri)
                {
                    int settime = time;
                    queue2[queue2_size] = queue1[i];
                    queue2[queue2_size].promoteTime = settime;
                    queue1_size --;
                    queue2_size ++;
                }
                else if(check2pri)
                {
                    new_queue1[queue1_index] = queue1[i];
                    queue1_index ++;
                }
            }

            int i2 = 0;
            while(i2 < queue1_size){
                queue1[i2] = new_queue1[i2];
                i2++;
            }

            queue2 = order_ticket(queue2,queue2_size);
            int setq2index = 0;
            string promote_item = "";
            int queue2_index = setq2index;
            int o_queue2_size = queue2_size;
            Customer * new_queue2 = new Customer[o_queue2_size];
            for (int i = 0; i < o_queue2_size; i++)
            {
                bool check1p = (queue2[i].priority <= 3);
                if (check1p)
                {
                    int setage = -1;
                    int settime = time;
                    queue1[queue1_size] = queue2[i];
                    queue1[queue1_size].promoteTime = settime + 1;
                    promote_item = queue1[queue1_size].id_name; 
                    queue1[queue1_size].age = setage;
                    bool checkq1update = false;
                    queue2_size --;
                    queue1_size ++;
                    Q1_updated = !checkq1update;
                }
                else if (queue2[i].priority > 3)
                {
                    new_queue2[queue2_index] = queue2[i];
                    queue2_index ++;
                }
            }
            if (Q1_updated)
            {
                int counti1 = 0;
                while(counti1 < queue2_size){
                     queue2[counti1] = new_queue2[counti1];
                     counti1++;
                }
            }
            int t = time + 1;
            update_item = find_permission(queue1,queue2,queue1_size,queue2_size,time);
            queue1 = order_runs(queue1,queue1_size,update_item,time);
            int q1size = queue1_size;
            int q2size = queue2_size ;
            update_lastRun(queue1,queue1_size,update_item,time); 
        
        }
        
        time++;
    }
}


void printOutput(Customer * customers, int size)
{
    customers = order_end_time(customers,size);
    
    for (int i = 0; i < size; i++)
    {
        cout << customers[i].id_name;
        
        string str1 = to_string(customers[i].arrivaledTime);
        int loop1 = 10-str1.length();
        for (int i = 0; i < loop1; i++)
        {
            cout << " ";
        }
        cout << customers[i].arrivaledTime;

        string str2 = to_string(customers[i].end);
        int loop2 = 10-str2.length();
        for (int i = 0; i < loop2; i++)
        {
            cout << " ";
        }
        cout << customers[i].end;

        string str3 = to_string(customers[i].ready);
        int loop3 = 10-str3.length();
        for (int i = 0; i < loop3; i++)
        {
            cout << " ";
        }
        cout << customers[i].ready;

        string str4 = to_string(customers[i].running);
        int loop4 = 10-str4.length();
        for (int i = 0; i < loop4; i++)
        {
            cout << " ";
        }
        cout << customers[i].running;

        string str5 = to_string(customers[i].waitiTime);
        int loop5 = 10-str5.length();
        for (int i = 0; i < loop5; i++)
        {
            cout << " ";
        }
        cout << customers[i].waitiTime;
        cout << endl;
    }
}

