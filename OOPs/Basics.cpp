#include <iostream>
using namespace std;
class Car{
    private:
    int price;
    
    public:
    int model_no;
    char name[20];
    
    void print(){
        cout<<"Price: "<<price<<endl;
        cout<<"Name: "<<name<<endl;
        cout<<"Model Number: "<<model_no<<endl;
    }
    
    int getDiscount(float x){
        return price = price*(1-x);
    }
    
    //getters and setters
    int getPrice(){
        return price;
    }
    void setprice(int x){
        if(x>0)
            price = x;
        else 
            price = 112;
    }
};

int main() {
    // Car arr[20];  --------- array of 20 cars
	Car c;
	cout<<sizeof(c)<<endl;
// 	c.price = 100;
    c.setprice(100);
	c.model_no = 112;
	c.name[0] = 'B';
	c.name[1] = 'M';
	c.name[2] = 'W';
	c.name[3] = '\0';
	
	cout<<c.getPrice()<<" "<<c.model_no<<" "<<c.name<<" "<<endl;
	
	cout<<"How much discount do you want: "<<endl;
	float dis;
	cin>>dis;
	cout<<"Discounted price: "<<c.getDiscount(dis)<<endl;
	
	c.print();
	
	c.setprice(-100);
	
	c.print();
	return 0;
}
