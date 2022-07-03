#include <iostream>
#include <cstring>
using namespace std;

int main() {
	// Length of longest substring with no repeating characters
	char a[1000];
	cin>>a;
	int n = strlen(a);
	int curr_len = 1;
	int max_len = 1;
	
	int visited[256];
	for(int i=0; i<256; i++){
	    visited[i] = -1;
	}
	
	visited[a[0]] = 0;
	
	for(int i=1; i<n; i++){
	    int last_occ = visited[a[i]];
	    if(last_occ == -1 || i-curr_len>last_occ){
	        curr_len+=1;
    	    max_len = max(curr_len, max_len);
	    }
	    else{
    	    max_len = max(curr_len, max_len);
	        curr_len = i-last_occ;
	    }
	    max_len = max(curr_len, max_len);
	    visited[a[i]] = i;
	}
	cout<<max_len<<endl;
	return 0;
}
