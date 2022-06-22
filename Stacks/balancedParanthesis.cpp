#include <iostream>
#include <stack>
using namespace std;
bool isValid(char* s){
    int i = 0;
    stack <char> brackets;
    while(s[i] != '\0'){
        if(s[i]=='('){
            brackets.push('(');
        }
        if(s[i] == ')'){
            if(brackets.empty()){
                return false;
            };
            brackets.pop();
        }
        i++;
    }
    if(brackets.empty()){
        return true;
    }
    return false;
}

int main() {
	// Balanced Paranthesis 
	char s[] = "((a+b)+(c-(d+e)))";
	cout<<isValid(s)<<endl;
	return 0;
}
