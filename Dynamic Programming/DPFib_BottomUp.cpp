#include <iostream>
#include <vector>
using namespace std;

int fib_BU(int n){
    int fib[100];
    fib[0] = 0;
    fib[1] = 1;
    for(int i=2; i<=n; i++){
        fib[i] = fib[i-1]+fib[i-2];
    }
    return fib[n];
}

int fib_space(int n){
    int a = 0;
    int b = 1;
    int c;
    for(int i=2; i<=n; i++){
        c = a+b;
        a = b;
        b = c;
    }
    return c;
}

int main() {
	// Dynamic programming starts
	int n;
	cin>>n;
	
	cout<<fib_space(n)<<endl;
	cout<<fib_BU(n)<<endl;
	return 0;
}
