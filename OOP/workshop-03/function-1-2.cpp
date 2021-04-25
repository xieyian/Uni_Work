#include <iostream>
#include <string>

void print_class(std::string courses[4], std::string students[], int report_card[][4], int nstudents){
    for(int i = 0;i < nstudents; i++){
        std::cout << students[i]<<"| ";
        for(int j = 0; j < 4; j++){
            std::cout << courses[j]<<"| ";
        }
        std::cout << "\n" ;
    }
    
}

int main(){
    std::string courses[4]={"a","b","c","d"};
    std::string students[3]={"s1","s2","s3"};
    int report_card[3][4];
    int nstudents=3;
    
    print_class(courses, students, report_card, nstudents);
    
    return 0;
}
