/*
created by: Yian Xie
ID: a1702241
*/
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "display.cpp"
using namespace std;

int main(int argc, char *argv[]){
    freopen(argv[1],"r",stdin);
    vector <string> in;
    string inputa;
    int size = 0;

    while(getline(cin,inputa)){
        in.push_back(inputa);
        size++;
    }
    
    Customer customs[size];
    
    int loop = 0;
    while(loop<size){
        vector<string> valueArray;
        string buf;
        stringstream iss(in[loop]);
        
        while (getline(iss, buf, ' '))
        {
            string out = buf;
            valueArray.push_back(out);
        }
        string name = valueArray[0];
        int n1 = stoi(valueArray[1]);
        int n2 = stoi(valueArray[2]);
        int n3 = stoi(valueArray[3]);
        int n4 = stoi(valueArray[4]);
        customs[loop] = Customer(name, n1, n2, n3, n4);
        loop++;
    } 

    
    Customer * customers = order_priority(customs,size);
    
    Customer s_queue1[size];
    Customer s_queue2[size];
    int queue1_size = 0;
    int queue2_size = 0;
    
    int l = size;
    for (int i = 0 ; i < l; i++)
    {
        bool check = (customers[i].countqueue() == 1);
        check ? s_queue1[queue1_size] = customers[i] : s_queue2[queue2_size] = customers[i];
        check ? queue1_size++ : queue2_size++;
    }
    
    Customer * queue1 = order_arrivaledTime(s_queue1,queue1_size);
    Customer * queue2 = order_arrivaledTime(s_queue2,queue2_size);
    
    int** out = update_statue(customers, size);
   
    print_process(queue1,queue2,queue1_size,queue2_size,out[2]);

    queue1_size = 0;
    queue2_size = 0;

    int loop1 = 1;
    while (loop1 <= size ){
    bool check = (queue1[loop1-1].end != 0);
       check ?  queue1_size ++ : NULL;
        loop1++;
    } 
    
    int loop2 = 1;
    while (loop2 <= size ){
    bool check = (queue2[loop2-1].end != 0);
       check ?  queue2_size ++ : NULL;
        loop2++;
    } 
    

    int si1 = queue1_size;
    int si2 = queue2_size;
    int l1 = 0;
    int l2 = 0;

    while(l1 < queue1_size){
        customers[l1] = queue1[l1];
        l1++;
    }
    while(l2 < queue2_size){
        customers[l2+queue1_size] = queue1[l2];
        l2++;
    }

    
 


    cout << "name   arrival   end   ready   running   waiting" << endl;
    printOutput(customers,size);
    return 0;
}
