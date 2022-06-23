#include <iostream>
#include <queue>
using namespace std;

int main() {
	// Running Stream
	queue<char> q;
	int freq[27] = {0};
	
	char ch;
	cin>>ch;
	while(ch!='.'){
	    //inserting in the queue and freq table
	    q.push(ch);
	    freq[ch-'a']++;
	    while(freq[q.front()-'a'] != 1 and !q.empty()){
	        q.pop();
	    }
	    if(q.empty()){
	        cout<<"-1"<<" ";
	    }
	    else{
	        cout<<q.front()<<" ";	    
	    }
	    
	    cin>>ch;
	};
}
