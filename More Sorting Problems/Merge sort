#include <iostream>
using namespace std;
void merge(int *arr, int start, int end){
    int mid = (start+end)/2;
    
    int i=start;
    int j = mid+1;
    int k = start;
    
    int temp[20];
    
    while(i<=mid && j<=end){
        if(arr[i]<arr[j]){
            temp[k++] = arr[i++];
        }
        else if(arr[i]>=arr[j]){
            temp[k++] = arr[j++];
        }
    }
    while(j<=end){
        temp[k++] = arr[j++];
    }
    while(i<=mid){
        temp[k++] = arr[i++];
    }
    
    for(int i=start; i<=end; i++){
        arr[i] = temp[i];
    }
}
void mergesort(int *arr, int start, int end){
    //base case
    if(start>=end){
        return;
    }
    
    //rec case
    int mid = (start+end)/2;
    
    mergesort(arr, start, mid);
    mergesort(arr, mid+1, end);
    
    merge(arr, start, end);
}

int main() {
	// Merge sort
    int n;
    cin>>n;
    int arr[20];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    mergesort(arr, 0, n);
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    
	return 0;
}
