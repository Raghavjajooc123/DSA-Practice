#include <iostream>
using namespace std;

int main() {
	// dynamic allocation
	int **arr;
	int r,c;
	cin>>r>>c;
	arr = new int*[r];
	for(int i=0; i<r; i++){
	    arr[i] = new int[c];
	    for(int j=0; j<c; j++){
	        cin>>arr[i][j];
	    }
	}
	 
	for(int i=0; i<r; i++){
	    for(int j=0; j<c; j++){
	        cout<<arr[i][j]<<" ";
	    }
	    cout<<endl;
	}
	
	
	return 0;
}


//another code - 1D dynamic array


#include <iostream>
using namespace std;

int main() {
	// dynamic allcation
	int n;
	cin>>n;
	int * ptr = new int[n];
	
	cout<<sizeof(ptr)<<endl;
	
	//taking input in the array
	for(int i=0; i<n; i++){
	    cin>>ptr[i];
	}
	
	for(int i=0; i<n; i++){
	    cout<<ptr[i]<<" ";
	}
	
	
	return 0;
}
