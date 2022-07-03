#include <iostream>
#include<deque>
using namespace std;

int main() {
	// Deque-Q1
	int n;
	int a[100000];
	int k;
	
	cin>>n;
	for(int i=0; i<n; i++){
	    cin>>a[i];
	}
	
	cin>>k;
	
	deque<int> Q(k);
	int i;
	for(i=0; i<k; i++){
	    while(!Q.empty()&&a[Q.back()]<=a[i]){
	        Q.pop_back();
	    }
	    Q.push_back(i);
	}
	for(;i<n;i++){
	    cout<<a[Q.front()]<<" ";
	    //elements which are not the part of the window
	    while(!Q.empty()&&Q.front()<=i-k){
	        Q.pop_front();
	    }
	    while(!Q.empty()&&a[Q.back()]<=a[i]){
	        Q.pop_back();
	    }
	    Q.push_back(i);
	}
	cout<<a[Q.front()]<<" ";
	return 0;
}
