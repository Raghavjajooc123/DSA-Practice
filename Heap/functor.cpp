#include <iostream>
#include <cstring>
using namespace std;

class fun{
    public:
    void operator()(string s){
        cout<<"This is "<<s;
    }
};

int main() {
	// functor
	fun f;
	f("C++");
	return 0;
}
