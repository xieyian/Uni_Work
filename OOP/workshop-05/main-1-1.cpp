#include<iostream>
using namespace std;

extern int *readNumbers();
extern void printNumbers(int *numbers,int length);

int main(){
	int *pointer;
	pointer=readNumbers();
	printNumbers(pointer,10);

	return 0;
	

}
