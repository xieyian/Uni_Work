
/*
Name: Yian Xie
ID: a1702241
*/

#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <list>
#include <cmath>
using namespace std;
// FIFO / LRU / ARB / WSARB-1 / WSARB-2

class Read {
    public:
    int pageNumber;
    bool clean;
    // int bytes;
    // int frames;
    // int ref;
    int time;
    int bitSize;
    int counter;
    // int comeintime;
    // int bitsize[];


    Read(){
        pageNumber = -1;
        clean = true;
        // ref= -1;
        time = -1;
        // comeintime = 0;
        // bitsize[0];
        int bitSize=0;

    }

    Read(string in,int bytes){
        // time=1;
        // comeintime = 0;
        if(in[0]=='R'){
            clean=true;
        }else{
            clean=false;
        }
        in = in.substr(2, in.size());
        int x;
        std::stringstream ss;
        ss << std::hex << in;
        ss >> x;
        pageNumber = x/bytes;
    }

    Read(string in,int bytes,int size){
        // time=1;
        // comeintime = 0;
        if(in[0]=='R'){
            clean=true;
        }else{
            clean=false;
        }
        in = in.substr(2, in.size());
        int x;
        std::stringstream ss;
        ss << std::hex << in;
        ss >> x;
        pageNumber = x/bytes;
        bitSize = pow(10, size - 1);
    }

};

void lursort(Read array[], Read a, int frames){
    Read swap = array[frames-1];
    for(int i =0 ;i<frames;i++){
        if(a.pageNumber == array[i].pageNumber){
            array[frames-1]=array[i];
            for(int j=i;j<frames-2;j++){
                array[j]=array[j+1];
            }
            array[frames-2]=swap;
        }
    }
}
int lessbit(Read array[],int frames){
    int number=0;
    bool check = false;
    int count=array[0].bitSize;
    for(int i = 0;i<frames;i++){
        if(count<array[i].bitSize){
            number=i;
            count=array[i].bitSize;
            check = true;
        }
    }

    if(check==true){
        return number;
    }else{
        return -1;
    }
    
}

void sortByBitSize(Read array[],int frames){
    for (int i = 0; i < frames; i++) {
        for (int j = 0; j < frames - 1 - i; j ++) {
            if(array[j].bitSize > array[j + 1].bitSize){
                swap(array[j], array[j + 1]);
            }
        }
    }
}

void sortByCounter(Read array[],int frames){
    for (int i = 0; i < frames; i++) {
        for (int j = 0; j < frames - 1 - i; j ++) {
            if(array[j].counter > array[j + 1].counter){
                swap(array[j], array[j + 1]);
            }
        }
    }
}

int checklessuspage(Read array[], int frames){
    int count=0;
    for(int i = 1; i<frames-1;i++){
        if(array[i-1].time<array[i].time){
            count = i;
        }
    }
        return count;
}


bool checksamepage(Read array[],int a,int frames){
    for(int i=0;i<frames;i++){
        if(array[i].pageNumber==a){
            return true;
        }
    }
    return false;
}

int checksamepage2(Read array[],int a,int frames){
    for(int i=0;i<frames;i++){
        if(array[i].pageNumber==a){
            return i;
        }
    }
    return -1;
}

int checksamebool(Read array[],Read a,int frames){
    for(int i=0;i<frames;i++){
        if(array[i].pageNumber==a.pageNumber && array[i].clean==true && a.clean==false){
            return i;
        }
    }
    return -1;
}

int checksameindex(Read array[],Read a,int frames){
    for(int i=0;i<frames;i++){
        if(array[i].pageNumber==a.pageNumber){
            return i;
        }
    }
    return -1;
}

void shiftleft(Read array[],int frames){
    for(int i=0;i<frames-1;i++){
        array[i]=array[i+1];
    }
}
void shiftright(Read array[],int frames){
    for(int i=frames-1;i>0;i--){
        array[i]=array[i-1];
    }
}



int main(int argc, char const *argv[])
{
    int o1,o2,o3,o4,bytes,frames;
    
    string method;
    stringstream input2 ( *(argv+2));
    stringstream input3 ( *(argv+3));
    stringstream input4 ( *(argv+4));
    int arbin1,arbin2,win1,win2,win3;
    input2 >> bytes;
    input3 >> frames;
    input4 >> method;

    bool startcheck=false;
    o1=o2=o3=o4=0;
    freopen(argv[1],"r",stdin);
    vector <string> in;
    string input;
    int filesize = 0;
    while(getline(cin,input)){
        in.push_back(input);
        filesize++;
    }

    for(int i = 0;i<filesize;i++){
        if(in[i][0]=='#'){
            startcheck=true;
        }
        if(startcheck==true){
            if(in[i][0]=='R' || in[i][0]=='W'){
                o1++;
            }
        }
    }

    vector<Read> page;
    Read memory[frames];
    int bits;
    
    for(int i =0;i<frames;i++){
        memory[i] = Read();
    }

    if(method == "FIFO"){
        for(int i = 1;i<filesize;i++){
            Read read(in[i],bytes);
            page.push_back(read);
        }
        for(int i = 0; i<page.size();i++){
            if(checksamepage(memory,page[i].pageNumber,frames)==false ){
                if(memory[0].clean==false){
                    o3++;
                }
                shiftleft(memory,frames);
                memory[frames-1] = page[i];
                o2++;
                o4++;
            }else {
                int check = checksamebool(memory,page[i],frames);
                if(check!=-1){
                    memory[check]=page[i];
                }
            }
        }

    }else  if(method == "LRU"){
        for(int i = 1;i<filesize;i++){
            Read read(in[i],bytes);
            page.push_back(read);
        }
        for(int i = 0; i<page.size();i++){
            if(checksamepage(memory,page[i].pageNumber,frames)==false ){
                if(memory[0].clean==false){
                    o3++;
                }
                shiftleft(memory,frames);
                memory[frames-1] = page[i];
                
                o2++;
                o4++;
            }else {
                string wor = page[i].clean? "r":"w";
                int check = checksameindex(memory,page[i],frames);
                if(!page[i].clean){
                    memory[check].clean = false;
                }
                Read swap = memory[check];
                for(int i = check; i<frames -1;i++){
                    memory[i] = memory[i + 1];
                }
                memory[frames - 1] = swap;
            }
        }
        
    }else if(method == "ARB"){
        stringstream input5 ( *(argv+5));
        stringstream input6 ( *(argv+6));
        
        int looptime;
        input5>>bits;
        input6>>looptime;
        for(int i = 1;i<filesize;i++){
            Read read(in[i],bytes, bits);
            page.push_back(read);
        }
        for(int i = 0; i<page.size();i++){
//            cout << "Time: " << i + 1 << " ";
            bool shift = i % looptime == 0;
            if(shift){
                for(int j=0;j<frames;j++){
                    memory[j].bitSize = memory[j].bitSize/10;
                }
            }
            if(checksamepage(memory,page[i].pageNumber,frames)==false ){
                Read memory2[frames];
                for (int i = 0; i < frames; i ++) {
                    memory2[i] = memory[i];
                }
                sortByBitSize(memory2, frames);
                if(!memory2[0].clean){
                    o3++;
                }
                int index = checksameindex(memory, memory2[0], frames);
                for(int i = index; i < frames; i ++){
                    memory[i] = memory[i + 1];
                }
                memory[frames-1] = page[i];
                
                o2++;
                o4++;
            }else {
                int check = checksameindex(memory,page[i],frames);
                if(memory[check].bitSize <pow(10,bits-1)){
                    memory[check].bitSize=memory[check].bitSize+pow(10,bits-1);
                }
                if(!page[i].clean){
                    memory[check].clean = false;
                }
            }
        }
    }else  if(method == "WSARB-1"){
        stringstream input5 ( *(argv+5));
        stringstream input6 ( *(argv+6));
        stringstream input7 ( *(argv+7));
        input5>>bits;
        
        int looptime;
        input6>>looptime;
        int wsize;
        input7>>wsize;
        
        for(int i = 1;i<filesize;i++){
            Read read(in[i],bytes,bits);
            page.push_back(read);
        }
        vector<Read> workset;
        for(int i = 0; i<page.size();i++){
            if(workset.size() < wsize){
                workset.push_back(page[i]);
            }else{
                workset.erase(workset.begin());
                workset.push_back(page[i]);
            }
            if(i % looptime == 0){
                for(int j=0;j<frames;j++){
                    memory[j].bitSize = memory[j].bitSize/10;
                }
            }
        
            for (int k = 0; k < frames; k ++) {
                memory[k].counter = 0;
                for (int j = 0; j < workset.size(); j ++) {
                    if(workset[j].pageNumber == memory[k].pageNumber){
                        memory[k].counter ++;
                    }
                }
            }
            
            if(checksamepage(memory,page[i].pageNumber,frames)==false ){
                Read memory2[frames];
                for (int j = 0; j < frames; j ++) {
                    memory2[j] = memory[j];
                }
                //sort counter
                sortByCounter(memory2, frames);
                //choose smallest counter
                vector<Read> smallCountermemory;
                for (int j = 0; j < frames; j ++) {
                    if(memory2[j].counter == memory2[0].counter){
                        smallCountermemory.push_back(memory2[j]);
                    }
                }
                long size = smallCountermemory.size();
                Read memory3[size];
                for (int j = 0; j < size; j ++) {
                    memory3[j] = smallCountermemory[j];
                }
                //sort bit
                sortByBitSize(memory3, (int)size);
                if(!memory3[0].clean){
                    o3++;
                }
                int index = checksameindex(memory, memory3[0], frames);
                for(int j = index; j < frames; j ++){
                    memory[j] = memory[j + 1];
                }
                memory[frames-1] = page[i];
                
                o2++;
                o4++;
            }else {
                int check = checksameindex(memory,page[i],frames);
                if(memory[check].bitSize <pow(10,bits-1)){
                    memory[check].bitSize=memory[check].bitSize+pow(10,bits-1);
                }
                if(!page[i].clean){
                    memory[check].clean = false;
                }
            }
            
        }

    }else  if(method == "WSARB-2"){
        stringstream input5 ( *(argv+5));
        stringstream input6 ( *(argv+6));
        stringstream input7 ( *(argv+7));
        input5>>bits;
        
        int looptime;
        input6>>looptime;
        int wsize;
        input7>>wsize;
        for(int i = 1;i<filesize;i++){
            Read read(in[i],bytes, bits);
            page.push_back(read);
        }
        vector<Read> workset;
        for(int i = 0; i<page.size();i++){
            if(workset.size() < wsize){
                workset.push_back(page[i]);
            }else{
                workset.erase(workset.begin());
                workset.push_back(page[i]);
            }
            
//            cout << "Time: " << i + 1 << " ";
            if(i % looptime == 0){
                for(int j=0;j<frames;j++){
                    memory[j].bitSize = memory[j].bitSize/10;
                }
            }
            
            for (int k = 0; k < frames; k ++) {
                memory[k].counter = 0;
                for (int j = 0; j < workset.size(); j ++) {
                    if(workset[j].pageNumber == memory[k].pageNumber){
                        memory[k].counter ++;
                    }
                }
            }
            
            if(checksamepage(memory,page[i].pageNumber,frames)==false ){
//                cout << "MISS: " << page[i].pageNumber << "      ";
                Read memory2[frames];
                for (int j = 0; j < frames; j ++) {
                    memory2[j] = memory[j];
                }
                //sort bits
                sortByBitSize(memory2, frames);
                //choose smallest bits
                vector<Read> smallCountermemory;
                for (int j = 0; j < frames; j ++) {
                    if(memory2[j].bitSize == memory2[0].bitSize){
                        smallCountermemory.push_back(memory2[j]);
                    }
                }
                long size = smallCountermemory.size();
                Read memory3[size];
                for (int j = 0; j < size; j ++) {
                    memory3[j] = smallCountermemory[j];
                }
                //sort counter
                sortByCounter(memory3, (int)size);
                if(!memory3[0].clean){
//                    cout << "REPLACE: " << memory3[0].pageNumber << "(DIRTY)";
                    o3++;
                }
                int index = checksameindex(memory, memory3[0], frames);
                for(int i = index; i < frames; i ++){
                    memory[i] = memory[i + 1];
                }
                memory[frames-1] = page[i];
                
                o2++;
                o4++;
            }else {
//                cout << "HIT: " << page[i].pageNumber << "   ";
                int check = checksameindex(memory,page[i],frames);
                if(memory[check].bitSize <pow(10,bits-1)){
                    memory[check].bitSize=memory[check].bitSize+pow(10,bits-1);
                }
                if(!page[i].clean){
                    memory[check].clean = false;
                }
            }
        }
    }

    

    cout<< "events in trace:    "<<o1<<endl;
    cout<< "total disk reads:   "<<o2<<endl;
    cout<< "total disk writes:  "<<o3<<endl;
    cout<< "page faults:        "<<o4<<endl;


    return 0;
}
