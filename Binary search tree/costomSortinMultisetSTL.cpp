#include <iostream>
#include <set>
using namespace std;

class people_compare{
    public:
    bool operator()(pair<string,int> p1, pair<string,int> p2){
        return p1.second>p2.second;
    }
};

int main() {
	multiset<pair<string, int>, people_compare> m;
	
	pair<string, int> p1 = make_pair("Raghav", 99);
	pair<string, int> p2 = make_pair("Shradha", 98);
	pair<string, int> p3 = make_pair("Chhavi", 90);
	pair<string, int> p4 = make_pair("RajaJi", 70);
	
	m.insert(p1);
	m.insert(p2);
	m.insert(p3);
	m.insert(p4);
	
	//sorts acc to names by default but since we have used the compare function we will sort by marks
	for(auto x:m){
	    cout<<x.first<<" "<<x.second<<endl;
	}
	cout<<endl;
	
	
	
	return 0;
}
