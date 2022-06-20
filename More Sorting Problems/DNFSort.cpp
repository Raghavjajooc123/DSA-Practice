#include <iostream>
using namespace std;

void DNFSort(int *arr, int n){
    int low = 0;
    int high = n-1;
    int mid = 0;
    
    while(mid<=high){
        if(arr[mid]==2){
            swap(arr[mid], arr[high]);
            high--;
        }
        if(arr[mid]==0){
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }
        if(arr[mid]==1){
            mid++;
        }
    }
}

int main() {
	// DNF Sort
    int n;
    cin>>n;
    
    int arr[10000];
    
    // marks are in range od 0 to 100
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    
    DNFSort(arr, n);
    
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
	return 0;
}
