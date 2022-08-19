int calculateMinPatforms(int at[], int dt[], int n) {
    sort(dt, dt+n);
    sort(at, at+n);
    int j = 0;
    int i = 1;
    int maxP = 1;
    int platforms = 1;
    while(i<n && j<n){
        if(dt[j]>=at[i]){
            platforms++;
            i++;
        }
        else{
            platforms--;
            j++;
        }
        maxP = max(platforms, maxP);
    }
    return maxP;
}
