#include <iostream>
#include <algorithm>
using namespace std;

int min_length(int* whiteDots, int* blackdots, int n){
    int length = 0;
    sort(whiteDots, whiteDots+n);
    sort(blackdots, blackdots+n);
    for(int i=0 ; i<n; i++){
        length+=abs(whiteDots[i]-blackdots[i]);
    }
    return length;
}

int main() {
	// connecting wires
	int n;
	cin>>n;
	
	int whiteDots[100], blackdots[100];
	for(int i=0; i<n; i++){
	    cin>>whiteDots[i];
	}
	for(int i=0; i<n; i++){
	    cin>>blackdots[i];
	}
	
	cout<<min_length(whiteDots, blackdots, n)<<endl;
	
	return 0;
}
