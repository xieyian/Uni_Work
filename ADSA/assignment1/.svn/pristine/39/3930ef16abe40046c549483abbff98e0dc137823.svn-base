#include <string>
#include <vector>
using namespace std;
#include <iostream>
//this function is used to make two input same size
//for example 100 and 4 will become 100 and 004 so the for loop in other function can run successful
void samesize(string &a,string &b){
    int n;
    if(a.size()>b.size()){
        n =a.size()-b.size();
        for(int i=0;i<n;i++){
            b="0"+b;
        }
    }
    if(a.size()<b.size()){
        n =b.size()-a.size();
        for(int i=0;i<n;i++){
            a="0"+a;
        }
    }
}

// this funciton is use to calculate the add
string cal_plus(string a, string b, int c){
    samesize(a,b);  //make input a b same size
    string out="";
    int o;
    bool carry=false;
    int size=a.size();
    
    for(int i=size-1;i>=0;i--){
        int n1;
        int n2;
        if(a[i]!='0'){
            n1=int(a[i]-'0');
        }else{
            n1=0;
        }
        
        if(b[i]!='0'){
            n2=int(b[i]-'0');
        }else{
            n2=0;
        }
        
        if(carry==true){
            carry=false;
            if(n1+n2+1>=c){
                carry=true;
                int o=n1+n2+1-c;
                out=to_string(o)+out;
            }else{
                int o=n1+n2+1;
                out=to_string(o)+out;
            }
        }else{
            if(n1+n2>=c){
                carry=true;
                int o=n1+n2-c;
                out=to_string(o)+out;
            }else{
                int o=n1+n2;
                out=to_string(o)+out;
            }
        }
    }
    if(carry==true){
        out="1"+out;
    }

    return out;
}

// this funciton is use to calculate Subtraction
string cal_sub(string a, string b, int c){
    samesize(a,b);  //make input a b same size
    string out="";
    int o;
    bool carry=false;
    int size=a.size();
    
    for(int i=size-1;i>=0;i--){
        int n1;
        int n2;
        if(a[i]!='0'){
            n1=int(a[i]-'0');
        }else{
            n1=0;
        }
        
        if(b[i]!='0'){
            n2=int(b[i]-'0');
        }else{
            n2=0;
        }
        
        if(carry==true){
            carry=false;
            if(n1-n2-1<0){
                carry=true;
                int o=n1+c-n2-1;
                out=to_string(o)+out;
            }else{
                int o=n1-n2-1;
                out=to_string(o)+out;
            }
        }else{
            if(n1-n2<0){
                carry=true;
                int o=c+n1-n2;
                out=to_string(o)+out;
            }else{
                int o=n1-n2;
                out=to_string(o)+out;
            }
        }
    }
    return out;
}

//this function is used to make shifting
string MakeShifting(string str, int stepnum)
{
    string shifted = str;
    for (int i = 0 ; i < stepnum ; i++)
        shifted = shifted + '0';
    return shifted;
}

//this funciont is used to calculate the multiply
string multiply(string a, string b,int c){
    samesize(a,b);
    int n=a.size();
    
    if(n==1){
        int n1=stoi(a);
        int n2=stoi(b);
        int o = n1*n2;
        int out=o;
        if(out>c){
            out= o%c+10*(o/c);
        }else if(out==c){
            out=10;
        }
        
        return to_string(out);
    }
    
    int fh = n/2;
    int sh = (n-fh);
      
    string a0 = a.substr(0, fh);
    string a1 = a.substr(fh, sh);
      
    string b0 = b.substr(0, fh);
    string b1 = b.substr(fh, sh);

    string P1 = multiply(a0, b0,c);
    string P2 = multiply(a1, b1,c);
    string P3 = multiply(cal_plus(a0, a1,c), cal_plus(b0, b1,c),c);
    
    return cal_plus(cal_plus(MakeShifting(P1, 2*(n-n/2)),P2,c),MakeShifting(cal_sub(P3,cal_plus(P1,P2,c),c), n-(n/2)),c);
}


int main(){
    string a, b;
    int c;
    cin>>a>>b>>c;
    
    string o1=cal_plus(a,b,c); // calculate the sum of a b
    string o3=multiply(a,b,c); // calculate the product of ab
    int i =0;
    while(o3[0]=='0'){ // use to delete the 0 in front 00100-> 100
        if(o3[0]=='0'){
            o3=o3.substr(1, o3.size()-1);
            i++;
        }
    }
    cout<<o1<<" "<<o3<<endl;
    
    return 0;
}
