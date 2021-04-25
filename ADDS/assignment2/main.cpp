#include <string>
#include <iostream>
using namespace std;
#include "Referee.h"
#include "Human.h"
#include "Computer.h"

int main(){
    
    Human h;
    Computer c;
    Referee r;
    
    h.setHumRPS();
    
    c.setComRPS(h.getgames());
    
    r.printoutput(h,c);
    

return 0;
}
