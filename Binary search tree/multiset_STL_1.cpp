#include <iostream>
#include <set>
using namespace std;

typedef multiset<int>::iterator It;

int main() {
	int arr[] = {10, 20 ,30 ,10 ,10 ,20};
	
	multiset<int> m(arr, arr+6);
	
	for(int x:m){
	    cout<<x<<" ";
	}
	cout<<endl;
	
	m.erase(20);
	for(int x:m){
	    cout<<x<<" ";
	}
	cout<<endl;
	
	m.insert(30);
	m.insert(30);
	m.insert(30);
	for(int x:m){
	    cout<<x<<" ";
	}
	cout<<endl;
	
	cout<<m.count(10)<<endl;
	
	auto a = m.find(30);
	cout<<*a<<endl;
	
	pair<It, It> pos = m.equal_range(30);
	for(auto it = pos.first; it!=pos.second; it++){
	    cout<<*it<<" - ";
	}
	
	return 0;
}
