#include <iostream>
using namespace std;
class complex{
    int real;
    int img;
    
    public:
    complex(){
        real = 0;
        img = 0;
    }
    complex(int r, int i){
        real = r;
        img = i;
    }
    
    void setReal(const int r){
        real = r;
    }
    void setImg(const int i){
        img = i;
    }
    int getReal() const{
        return real;
    }
    int getImg() const{
        return img;
    }
    
    void operator+ (const complex &x){
        real = real + x.real;
        img = img + x.img;
    }
    void operator! (){
        img = img*-1;
    }
    int operator[] (string s){
        if(s=="real")
            return real;
        else if(s == "img")
            return img;
        else
            return 0;
    }
    
    void print() const{
        if(img>0)
            cout<<real<<" + "<<img<<"i"<<endl;
        else
            cout<<real<<" - "<<(-img)<<"i"<<endl;
    }
};

// istream and ostream overloading

istream & operator>>(istream & is, complex & c){
    int i, r;
    cin>>r>>i;
    c.setReal(r);
    c.setImg(i);
    return is;
}

ostream& operator<<(ostream & os, complex & c){
    int real = c.getReal();
    int img = c.getImg();
    if(img>0)
        cout<<real<<" + "<<img<<"i"<<endl;
    else
        cout<<real<<" - "<<(-img)<<"i"<<endl;
        
    return os;
}

int main() {
	// operator overloading
	complex c1(5,3);
	c1.print();
	
	complex c2;
	c2.setReal(3);
	c2.setImg(-1);
	c2.print();
	
	//overloading the operators
	c1 + c2;
	c1.print();
	
	!c2;
	c2.print();  
	
	cout<<c1["real"]<<endl;
	cout<<c1["img"]<<endl;
	cout<<c1["im"]<<endl;;
	
	//overloading <<, >>
	complex d, e;
	cin>>d>>e;
	cout<<d<<e;
	
	return 0;
}
