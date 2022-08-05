#include <iostream>
#include <cstring>
using namespace std;
class Car{
    public:
    
    float price;
    int model_no;
    char name[20];
    
    //below is the case of constructor overloading
    //called only once while creating the object
    Car(){
        cout<<"Inside car constructor"<<endl;
    }
    //paramertized constructor
    Car(float p, int m, char * n){
        price = p;
        model_no = m; 
        strcpy(name,n);
    }
    //copy constructor - also exists by default
    Car(Car &x){
        cout<<"Inside copy constructor"<<endl;
        price = x.price;
        model_no = x.model_no; 
        strcpy(name,x.name);
    }
    void print(){
        cout<<"Name: "<<name<<endl;
        cout<<"Model: "<<model_no<<endl;
        cout<<"Price: "<<price<<endl;
    }
};

int main() {
    // constructors and others
    Car c;
    Car d(111, 222, "BMW");
    cout<<"Car d"<<endl;
    d.print();
    
    Car e(d);
    Car f = e;//copy constructor
    cout<<"Car e"<<endl;
    e.print();
    
	return 0;
}
