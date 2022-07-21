#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

int main() {
	// implementing phonebook
	unordered_map<string, vector<string>> Phonebook;
	Phonebook["Raghav"].push_back("6375446338");
	Phonebook["Raghav"].push_back("9999788393");
	Phonebook["Shradha"].push_back("6366677722");
	Phonebook["Shradha"].push_back("7788993343");
	Phonebook["Shradha"].push_back("9898776533");
	Phonebook["Kunal"].push_back("6378999111");
	
	//iterating 
	for(auto c:Phonebook){
	    cout<<c.first<<" -> ";
	    for(string no:c.second){
	        cout<<no<<" ";
	    }
	    cout<<endl;
	}
	return 0;
}
