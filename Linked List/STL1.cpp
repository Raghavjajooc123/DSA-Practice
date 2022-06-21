#include <iostream>
#include <list>
using namespace std;

int main() {
	// STL list
	list<int> l;
	
	list<int> l1{1,2,4,6};
	
	list <string> l2{"apple", "mango"};
	
	l2.push_back("banana");
	for(string s:l2){
	    cout<<s<<" ";
	}
	cout<<endl;
	
	l2.sort();
	for(string s:l2){
	    cout<<s<<" ";
	}
	cout<<endl;
	
	l2.reverse();
	for(string s:l2){
	    cout<<s<<" ";
	}
	cout<<endl;
	
	l2.pop_front();
	for(string s:l2){
	    cout<<s<<" ";
	}
	cout<<endl;
	
	l2.push_front("kiwi");
	for(string s:l2){
	    cout<<s<<" ";
	}
	cout<<endl;
	
	l2.pop_back();
	for(string s:l2){
	    cout<<s<<" ";
	}
	cout<<endl;

	
// 	traversing using iterators
    for(auto it = l2.begin(); it!= l2.end(); it++){
        cout<<*it<<" ";
    }
    cout<<endl;


    l2.push_back("banana");
    l2.push_back("guava");
    l2.push_back("carrot");
    l2.push_back("guava");
    for(string s:l2){
	    cout<<s<<" ";
	}
	cout<<endl;
    
    l2.remove("guava");
    for(string s:l2){
	    cout<<s<<" ";
	}
	cout<<endl;
	
	auto it = l2.begin()++;
	it++;
	l2.erase(it);
    for(string s:l2){
	    cout<<s<<" ";
	}
	cout<<endl;
	
	it = l2.begin()++;
	it++;
	l2.insert(it, "Mangooooo");
    for(string s:l2){
	    cout<<s<<" ";
	}
	cout<<endl;
	
	return 0;
}
