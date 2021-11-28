#include <iostream>
using namespace std;

void incrementvalue(int z){
    z++;
    cout<<"inside function : "<<z<<endl;
}

void incrementbyaddress(int *zptr){
    //&z=*zptr
    *zptr=*zptr +1;
    cout<<"inside function : "<<*(zptr)<<endl;
}

int main() {
	// pointers
    int x = 10;
    
    int *xptr = &x;
    
    cout<<&x<<endl;
    cout<<xptr<<endl;
    
    //reassigning 
    int y = 20;
    xptr = &y;
    cout<<&y<<endl;
    cout<<xptr<<endl;
    
    //accessing the variable from the pointer
    cout<<*(xptr);
	
	//pass by value
	int z = 10;
	incrementvalue(z);
	cout<<"inside main : "<<z<<endl;
	
	//pass by reference by using pointer
	incrementbyaddress(&z);
	cout<<"inside main : "<<z<<endl;
	
	return 0;
}
