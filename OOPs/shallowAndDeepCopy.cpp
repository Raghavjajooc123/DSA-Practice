#include <iostream>
#include <cstring>
using namespace std;
class Car{
private:
    float price;
public:
    int model_no;
    char * name;
    
    //below is the case of constructor overloading
    //called only once while creating the object
    Car(){
        cout<<"Default Constructor"<<endl;
    }
    //paramertized constructor
    Car(float p, int m, char * n){
        price = p;
        model_no = m; 
        name = new char [strlen(n)+1];
        strcpy(name,n);
    }
    //in shallow copy when we change the 
    //copy constructor for deep copy
    Car(Car & x){
        price = x.price;
        model_no = x.model_no;
        name = new char [strlen(x.name)+1];
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
    Car c(100, 222, "BMW");//paramertized constructor
    
    Car d(c);//copy constructor
    d.name[0] = 'A';
    
    d.print();
    c.print();
    
    
	return 0;
}
