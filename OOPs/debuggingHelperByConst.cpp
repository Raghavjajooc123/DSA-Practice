#include <iostream>
#include <cstring>
using namespace std;
class Car{
private:
    float price;
public:
    // this is a constant data member initiated only once
    const int msp;
    int model_no;
    char * name;
    
    //to initiate a constant data member we have to use a initialisation list
    Car():msp(99){
        name = NULL;
    }
    //paramertized constructor
    Car(float p, int m, char * n){
        price = p;
        model_no = m; 
        name = new char [strlen(n)+1];
        strcpy(name,n);
    }
    //another thing here x is only being used as read only mode and no changes are being done to x 
    // so it is advisable to make it const parameters
    Car(const Car & x){
        price = x.price;
        model_no = x.model_no;
        name = new char [strlen(x.name)+1];
        strcpy(name,x.name);
    }
    
    //we can make const functions those which do not update the data members of the class
    void print() const{
        cout<<"Name: "<<name<<endl;
        cout<<"Model: "<<model_no<<endl;
        cout<<"Price: "<<price<<endl;
    }
};

int main() {
    // constructors and others
    Car c(100, 222, "BMW");//paramertized constructor
    
    Car d(c);//copy constructor
    d.name[0] = 'A';
    
    c.print();
    d.print();

	return 0;
}
