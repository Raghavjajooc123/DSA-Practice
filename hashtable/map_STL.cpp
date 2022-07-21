#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
	// map STL
	map<string, int> m;
	
	//inserting in map
	m.insert(make_pair("Mango", 100));
	
	pair<string, int> p;
	p.first = "Apple";
	p.second = 80;
	m.insert(p);
	
	m["Banana"] = 40;
	
	//search in map
	string key;
	cin>>key;
	
	auto it = m.find(key);
	if(it!=m.end()){
	    cout<<"Price of "<<key<<" is "<<m[key]<<endl;
	}
	else{
	    cout<<key<<" not found"<<endl;
	}
	
	//another way to find
	m["Banana"] += 10;
	
	if(m.count(key)){
	    cout<<"Price of "<<key<<" is "<<m[key]<<endl;
	}
	else{
	    cout<<"Could not find"<<endl;
	}
	
	//erasing the data
	m.erase(key);
	
	if(m.count(key)){
	    cout<<"Price of "<<key<<" is "<<m[key]<<endl;
	}
	else{
	    cout<<"Could not find"<<endl;
	}
	
	m["Lichi"] = 60;
	m["Kiwi"] = 150;
	m["Banana"] = 30; 
	
	//iterating over all key value pairs
	for(auto it = m.begin(); it!=m.end(); it++){
	    cout<<(*it).first<<" "<<it->second<<endl;
	}
	
	//using foreach loop
	for(auto p:m){
	    cout<<p.first<<" and "<<p.second<<endl;
	}
	
	return 0;
}
