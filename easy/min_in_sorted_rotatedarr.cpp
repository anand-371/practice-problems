/*
A sorted array arr[] of size N which is rotated at some
 unknown point. The task is to find the minimum element
  in it. All the elements in the array are distinct.

Note: Expected time complexity is O(logN).

Input:
The first line of input contains an integer T denoting 
the number of test cases. Each test case contains the 
number of elements in the array arr[] as N and next line
 contains space separated n elements in the array arr[].
*/
#include <iostream>
using namespace std;
int binarysearch(int arr[],int n){
    int start=0;
    int last=n-1;
    int se=arr[0];
    int ee=arr[n-1];
    int mid;
    while(start<=last){
        mid=(start+last)/2;
        if(start==last){return start;}
        else if(mid+1<n && mid-1 >=0 && arr[mid-1]>arr[mid] && arr[mid+1]>arr[mid]){
            return mid;
        }else if(arr[mid]<ee){
            last=mid-1;
        }else if(arr[mid]>ee){
            start=mid+1;
        }
    }
    return -1;
}
int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for (int i = 0; i < n; ++i)
        {
            cin>>arr[i];
        }
        int value=binarysearch(arr,n);
        if(value==-1){cout<<0;}
        else{
            cout<<arr[value];
        }
        cout<<endl;
    }
    return 0;
}