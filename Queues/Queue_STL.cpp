#include <iostream>
#include <queue>
using namespace std;

int main() {
	// Queue STL
    queue<int> q;
    for(int i=0; i<5; i++){
        q.push(i);
    }
    q.pop();
    q.pop();
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
	return 0;
}
