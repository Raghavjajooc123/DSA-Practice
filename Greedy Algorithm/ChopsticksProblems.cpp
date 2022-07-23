#include <iostream>
#include <algorithm>
using namespace std;

int no_of_chopsticks(int* len, int n, int d){
    int chopsticks = 0;
    sort(len, len+n);
    for(int i=0; i<n-1; i++){
        if(len[i+1]-len[i]<=d){
            chopsticks++;
            i++;
        }
    }
    return chopsticks;
}

int main() {
	// Chopstics problem
	int n, d;
	cin>>n>>d;
	int len[100000];
	for(int i=0; i<n; i++){
	    cin>>len[i];
	}
	cout<<no_of_chopsticks(len, n, d)<<endl;
	return 0;
}
