#include <iostream>
using namespace std;

void countingsort(int *arr, int n){
    int max_num = -1 ;
    for(int i=0; i<n; i++){
        max_num = max(max_num, arr[i]);
    }
    
    int freq[max_num+1]={0};
    for(int i=0; i<n; i++){
        freq[arr[i]]=1;
    }
    
    //putting elements back in the array
    int j=0;
    for(int i=0; i<max_num+1; i++){
        while(freq[i]==1){
            arr[j]=i;
            freq[i]--;
            j++;
        }
    }
}

int main() {
	// counting sort
    int n;
    cin>>n;
    int arr[20];
    cout<<"Numbers only between 1 and 20"<<endl;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    
    countingsort(arr, n);
    
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
	return 0;
}
