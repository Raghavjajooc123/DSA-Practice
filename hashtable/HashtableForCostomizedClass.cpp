#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class student{
    public:
    string firstname;
    string lastname;
    string rollno;
    student(string f, string l, string r){
        firstname = f;
        lastname = l;
        rollno = r;
    }
    
    bool operator==(const student &s) const {
        return rollno == s.rollno;
    }
};

class HashFn{
    public:
    size_t operator()(const student &s) const {
        return s.firstname.length() + s.lastname.length();
    }
};

int main() {
	// creating hashtable for costomized class
	unordered_map<student, int, HashFn> student_map;
	
	student s1("Raghav", "Jajoo", "94");
	student s2("Shradha", "Somani", "93");
	student s3("Rishubh", "kapoor", "44");
	student s4("Rishubh", "Kishor", "48");
	
	student_map[s1] = 100;
	student_map[s2] = 110;
	student_map[s3] = 80;
	student_map[s4] = 70;
	
	//iterating 
	for(auto s:student_map){
	    cout<<"Marks of "<<s.first.firstname<<" "<<s.first.lastname<<" is "<<s.second<<endl;
	}
	return 0;
}
