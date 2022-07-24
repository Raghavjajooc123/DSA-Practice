#include <iostream>
#include <climits>
using namespace std;
int min_steps(int n, int* steps){
    //base case
    if(n == 1){
        return 0;
    }
    //dynamic programming
    if(steps[n] != 0){
        return steps[n];
    }
    //rec case
    int devidetwo = INT_MAX;
    int devidethree = INT_MAX;
    if(n%3 == 0){
        devidethree  = min_steps(n/3 , steps);
    }
    if(n%2 == 0){
        devidetwo  = min_steps(n/2 , steps);
    }
    steps[n] = min(min_steps(n-1, steps),min(devidetwo, devidethree)) + 1;
    return steps[n];
}

int min_steps_bottomUp(int n){
    int steps[1000];
    steps[1] = 0;
    for(int i=2; i<=n; i++){
        int devideTwo = INT_MAX;
        int devideThree = INT_MAX;
        if(i%3 == 0){
            devideThree = steps[i/3];
        }
        if(i%2 == 0){
            devideTwo = steps[i/2];
        }
        steps[i] = min(steps[i-1],min(devideTwo, devideThree)) + 1;
    }
    return steps[n];
}

int main() {
	// minimum steps to one
	int n; 
	cin>>n;
	int steps[1000] = {0};
	cout<<min_steps(n, steps)<<endl;
	cout<<min_steps_bottomUp(n)<<endl;
	return 0;
}
