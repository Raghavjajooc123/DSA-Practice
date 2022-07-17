#include <iostream>
#include <queue>
using namespace std;
int joinRopes(int * ropes, int n){
    priority_queue<int, vector<int>,greater<int>> pq(ropes, ropes+n);
    int answer = 0;
    while(pq.size()>1){
        int rope1 = pq.top();
        pq.pop();
        int rope2 = pq.top();
        pq.pop();
        answer = answer + rope1 + rope2;
        pq.push(rope1+rope2);
    }
    return answer;
}

int main() {
	// Join Ropes Question
	int ropes[] = {4,3,2,6};
	int n = 4;
	
	cout<<joinRopes(ropes, n);
	return 0;
}
