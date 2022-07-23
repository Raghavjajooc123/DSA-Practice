#include <iostream>
#include <algorithm>
using namespace std;

int load_balancer(int *arr, int n, int sum){
    if(sum%n != 0){
        return -1;
    }
    else{
        int final_load = sum/n;
        int max_rounds = 0;
        for(int i=0; i<n-1; i++){
            int sum_left = 0;
            for(int j=0; j<=i; j++){
                sum_left += arr[j];
            }
            int supposed_sum_left = (i+1)*final_load;
            int curr_rounds = abs(supposed_sum_left - sum_left);
            max_rounds = max(max_rounds, curr_rounds);
        }
        return max_rounds;
    }
}

int load_balancer_runningsum(int *arr, int n, int sum){
    if(sum%n != 0){
        return -1;
    }
    else{
        int final_load = sum/n;
        int running_sum = 0;
        int max_rounds = 0;
        for(int i=0; i<n; i++){
            running_sum += arr[i];
            int curr_rounds = abs(running_sum - (i+1)*final_load);
            max_rounds = max(max_rounds, curr_rounds);
        }
        return max_rounds;
    }
}

int main() {
    // Load Balancing
    int n;
    cin>>n;
    
    while(n!=-1){
        int arr[100];
        int sum = 0;
        for(int i=0; i<n; i++){
            cin>>arr[i];
            sum += arr[i];
        }
        cout<<load_balancer_runningsum(arr, n, sum)<<endl;
        cin>>n;
    }
    
    return 0;
}
