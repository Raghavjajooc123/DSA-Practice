#include <iostream>
#include <queue>
using namespace std;

int main() {
	// Running Stream
	queue<char> q;
	int freq[27] = {0};
	
	char ch;
	cin>>ch;
	while(ch != '.'){
	    //inserting in the queue and freq table
	    q.push(ch);
	    freq[ch - 'a']++;
	    
	    //query
	    while(!q.empty()){
	        int idx = q.front()-'a';
	        if(freq[idx] > 1){
	            q.pop();   
	        }
	        else{
	            cout<<q.front()<<" ";
	            break;
	        }
	    }
	    if(q.empty()){
	        cout<<"-1";
	    }
	    
	    cin>>ch;
	}
	return 0;
}
