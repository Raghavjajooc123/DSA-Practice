int findMinimumCoins(int amount) 
{
    int currency[9] = {1,2,5,10,20,50,100,500,1000};
    int coins = 0;
    int s = 0; 
    int e = 8;
    while(s<=e){
        int m = (s+e)/2;
        if(currency[m] <= amount) s = m+1;
        else e = m-1;
    }
    for(int i=e; i>=0; i--){
        coins+=(amount/currency[i]);
        amount = amount%currency[i];
    }
    return coins;
}
