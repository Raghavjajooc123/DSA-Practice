#include <iostream>
#include <algorithm>
using namespace std;

int my_min_coins(int n, int currency[], int size){
    int coins = 0;
    while(n!=0){
        int i;
        for(i=0; i<size; i++){
            if(currency[i]>n){
                break;
            }
        }
        coins += (n/currency[i-1]);
        n = n%currency[i-1];
    }
    return coins;
}

int min_coins(int n, int currency[], int size){
    int coins = 0;
    while(n!=0){
        int idx = upper_bound(currency, currency+size, n) - currency - 1;
        coins += n/currency[idx];
        cout<<currency[idx]<<" * "<<n/currency[idx]<<endl;
        n = n%currency[idx];
    }
    return coins;
}

int main() {
	// coin change problem
	int n;
	cin>>n;
	
	int currency[] = {1,2,5,10,20,50,100,200,500,2000}; 
	
	cout<<min_coins(n, currency, 10)<<endl;
	return 0;
}
