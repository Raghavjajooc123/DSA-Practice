#include <iostream>
#include <climits>
using namespace std;
int optimal_game(int * game, int s, int e){
    if(s>e){
        return 0;
    }
    int op1 = game[s] + min(optimal_game(game, s+2, e), optimal_game(game, s+1, e-1));
    int op2 = game[e] + min(optimal_game(game, s, e-2), optimal_game(game, s+1, e-1));
    return max(op1, op2);
}

int main() {
	// optimal game problem
	int n;
	cin>>n;
	int game[100];
	for(int i=0; i<n; i++){
	    cin>>game[i];
	}
	cout<<optimal_game(game, 0, n-1)<<endl;
	return 0;
}
