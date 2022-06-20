#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

class Student{
    public:
        string name;
        int marks;
};

void bucketsort(Student s[1000], int n){
    vector <Student> v[101];
    for(int i=0; i<n; i++){
        int m = s[i].marks;
        v[m].push_back(s[i]);
    }
    //displaying the students
    for(int i=100; i>=0; i--){
        for(vector<Student>::iterator it = v[i].begin(); it != v[i].end(); it++){
            cout<<(*it).marks<<" "<<(*it).name<<endl;
        }
    }
}

int main() {
	// Bucket Sort
    Student s[1000];
    int n;
    cin>>n;
    // marks are in range od 0 to 100
    for(int i=0; i<n; i++){
        cin>>s[i].name>>s[i].marks;
    }
    
    bucketsort(s, n);
    
	return 0;
}
