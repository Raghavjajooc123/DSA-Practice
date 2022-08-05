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
        name = NULL;
    }
    //paramertized constructor
    Car(float p, int m, char * n){
        price = p;
        model_no = m; 
        name = new char [strlen(n)+1];
        strcpy(name,n);
    }
    //the default copy constructor makes a shallow copy
    //copy constructor for deep copy
    Car(Car & x){
        price = x.price;
        model_no = x.model_no;
        name = new char [strlen(x.name)+1];
        strcpy(name,x.name);
    }
    
    //overriding the equals to operator
    void operator= (Car &x){
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
    
    //objects are destructed in reverse order of their creation
    ~Car(){
        cout<<"Inside destructor of car "<<name<<endl;
        if(name!=NULL){
            delete [] name;
        }
    }
};

int main() {
    // constructors and others
    Car c(100, 222, "BMW");//paramertized constructor
    
    Car d(c);//copy constructor
    d.name[0] = 'A';
    
    c.print();
    d.print();
    
    // we can delete a dynamically created car manually by calling destructor by:-
    Car * e = new Car(10, 20, "Ferrari");
    e->print();
    delete e;

	return 0;
}
