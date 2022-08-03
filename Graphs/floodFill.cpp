#include <iostream>
using namespace std;
int R,C;

//ch is the character we want to be replaced
//color is the char we want to fill
void printmat(char input[][50]){
	for(int i=0; i<R; i++){
	    for(int j=0; j<C; j++){
	        cout<<input[i][j]<<" ";
	    }
	    cout<<endl;
	}
	cout<<endl;
	return;
}

void floodFill(char mat[][50], int i, int j, char ch, char color){
    if(i<0||j<0||i>=R; j>=C){
        return;
    }
    
    if(mat[i][j] != ch){
        return;
    }
    
    mat[i][j] = color;
    floodFill(mat, i+1, j, ch, color);
    floodFill(mat, i-1, j, ch, color);
    floodFill(mat, i, j+1, ch, color);
    floodFill(mat, i, j-1, ch, color);
    return;
}

int main() {
	// Flood-Fill algorithm
	cin>>R>>C;
	char input[20][50];
	for(int i=0; i<R; i++){
	    for(int j=0; j<C; j++){
	        cin>>input[i][j];
	    }
	}
	
	printmat(input);
    floodFill(input, 4, 4, '.', 'r');
    floodFill(input, 0, 0, '.', 'b');
    printmat(input);
	return 0;
}

// I/P
// 7 10
// ..........
// ..######..
// ..#....#..
// ..#....#..
// ..#....#..
// ..######..
// ..........
