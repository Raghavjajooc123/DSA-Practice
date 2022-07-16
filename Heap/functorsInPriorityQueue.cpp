#include <iostream>
#include <queue>

using namespace std;

class person{
    public:
    string name;
    int age;
    person(){
        name = "Default";
        age = 30;
    }
    person(string n, int a){
        name = n;
        age = a;
    }
};

class personCompare{
    public:
    bool operator()(person A, person B){
        return A.age < B.age;
    }
};

int main() {
	// using functor for comparision in priority queue
	int n;
	cin>>n;
	priority_queue<person, vector<person>, personCompare> pq;
	for(int i=0; i<n; i++){
	    string name;
	    int age;
	    cin>>name>>age;
	    person p(name, age);
	    pq.push(p);
	}
	
	while(!pq.empty()){
	    person p = pq.top();
	    cout<<p.name<<" "<<p.age<<endl;
	    pq.pop();
	}
	return 0;
}
