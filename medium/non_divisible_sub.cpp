/*
Given an array of integer numbers, we need to find maximum size of a subset such that sum of each pair of this subset is not divisible by K.
Examples :

Input :  arr[] = [3, 7, 2, 9, 1]        
         K = 3
Output : 3
Maximum size subset whose each pair sum 
is not divisible by K is [3, 7, 1] because,
3+7 = 10,    
3+1 = 4,    
7+1 = 8        all are not divisible by 3.
It is not possible to get a subset of size 
bigger than 3 with the above-mentioned property.

Input : arr[] = [3, 17, 12, 9, 11, 15]
        K = 5
Output : 4  
*/
int min(int a,int b){
    if (a>b)
    {
        return b;
    }else{
        return a;
    }
}
int max(int a,int b){
    if (a>b)
    {
        return a;
    }
    return b;
}

int nonDivisibleSubset(int k, vector<int> s) {
    int arr[k];
    for (int i = 0; i < k; ++i)
    {
        arr[i]=0;
    }
    for (int i = 0; i < s.size(); ++i)
    {
        arr[s[i]%k]++;
    }
    if (k%2==0)
    {
        arr[k/2]=min(arr[k/2],1);
    }
    int result=min(arr[0],1);
    for (int i = 1; i <=k/2 ; ++i)
    {
        result+=max(arr[i],arr[k-i]);
    }
    return result;

}
