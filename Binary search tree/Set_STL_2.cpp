#include <iostream>
#include <set>
using namespace std;

int main() {
	set <pair<int, int>>s;
	s.insert(make_pair(10,1));
	s.insert(make_pair(20,4));
	s.insert(make_pair(10,3));
	s.insert(make_pair(30,9));
	s.insert(make_pair(10,1));
	s.insert(make_pair(100,1));
	s.insert(make_pair(5,1));
	s.insert(make_pair(3,1));
	
	s.erase(make_pair(3,1));
	s.insert(make_pair(3,2));
	
	for(auto it : s){
	    cout<<(it.first)<<" "<<(it.second)<<endl;
	}
	cout<<endl;
	
	auto a = s.find(make_pair(5,1));
	s.erase(a);
	
	for(auto it : s){
	    cout<<(it.first)<<" "<<(it.second)<<endl;
	}
	
	a = s.upper_bound(make_pair(10,1));
	cout<<a->first<<" , "<<a->second<<endl;
	
	a = s.lower_bound(make_pair(10,1));
	cout<<a->first<<" , "<<a->second<<endl;
	
	return 0;
}
