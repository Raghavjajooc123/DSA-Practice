#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
	// Unordered map STL
	unordered_map<string, int> um;
	um.insert(make_pair("Mango", 100));
	um.insert(make_pair("Banana", 40));
	um.insert(make_pair("Apple", 90));
	um.insert(make_pair("Kiwi", 140));
	
	string key;
	cin>>key;
	
	auto it = um.find(key);
	if(it!=um.end()){
	    cout<<"Price of "<<key<<" is "<<um[key]<<endl;
	}
	else{
	    cout<<"Fruit not present"<<endl;
	}
	
	um.erase("Mango");
	
	it = um.find(key);
	if(it!=um.end()){
	    cout<<"Price of "<<key<<" is "<<um[key]<<endl;
	}
	else{
	    cout<<"Fruit not present"<<endl;
	}
	
	return 0;
}
