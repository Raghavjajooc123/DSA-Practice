#include <iostream>
using namespace std;
int partition(int *arr, int start, int end){
    int i = start-1; //elements less than the pivot element  
    for(int j=start; j<=end-1; j++){
        if(arr[j]<=arr[end]){
            i++;
            swap(arr[j], arr[i]);
        }
    }
    i=i+1;
    swap(arr[end], arr[i]);
    return i;
}
void quicksort(int *arr, int start, int end){
    
    //base case
    if(start>=end){
        return;
    }
    
    //rec case
    int p = partition(arr, start, end);
    quicksort(arr, start, p-1);
    quicksort(arr, p+1, end);
}

int main() {
	// Quick sort
    int n;
    cin>>n;
    int arr[20];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    
    quicksort(arr, 0, n-1);
    
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
	return 0;
}
