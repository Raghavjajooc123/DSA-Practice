#include <iostream>
#include <vector>
using namespace std;

int fib_rec(int n, int* fib_value){
    if(n == 0 || n == 1){
        return n;
    }
    else if(fib_value[n]!=0){
        return fib_value[n];
    }
    int ans = fib_rec(n-1, fib_value)+fib_rec(n-2, fib_value);
    fib_value[n] = ans;
    return ans;
}

int main() {
	// Dynamic programming starts
	int n;
	cin>>n;
	
	int fib_value[100] = {0};
	
	cout<<fib_rec(n, fib_value)<<endl;
	return 0;
}
