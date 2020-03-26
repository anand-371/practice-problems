/*
Given three increasingly sorted arrays A, B, C of sizes N1, N2, and N3 respectively, you need to print all common elements
 in these arrays.

Note: Please avoid printing the same common element more than once.

Input:
First line contains a single integer T denoting the total number of test cases. T testcases follow. Each testcase contains
 four lines of input. First line consists of 3 integers N1, N2 and N3, denoting the sizes of arrays A, B, C respectively. 
 The second line contains N1 elements of A array. The third lines contains N2 elements of B array. 
 The fourth lines contains N3 elements of C array.

Output:
For each testcase, print the common elements of array. If not possible then print -1.


**even a hashmap based approach can be utilised for doing the same** that uses O(1) space complexity**
The following code used a time complexity of O(n1+n2+n3)
*/

#include <iostream>
using namespace std;

int main() {
	int t,n1,n2,n3;
	cin>>t;
	while(t--){
	    cin>>n1>>n2>>n3;
	    int arr1[n1],arr2[n2],arr3[n3];
	    for(int i=0;i<n1;i++){
	        cin>>arr1[i];
	    }
	    for(int i=0;i<n2;i++){
	        cin>>arr2[i];
	    }
	    for(int i=0;i<n3;i++){
	        cin>>arr3[i];
	    }
	    int i=0,j=0,k=0;
	    bool flag=true;
	    while(i<n1 && j< n2 && k<n3){
	        if(arr1[i]==arr2[j] && arr2[j]==arr3[k]){
	            cout<<arr1[i]<<" ";
	            flag=false;
	            i++;
	            j++;
	            k++;
	        }
	        else if(arr1[i]<arr2[j]){i++;}
	        else if(arr2[j]<arr3[k]){j++;}
	        else{k++;}
	    }
	    if(flag==true){cout<<"-1";}
	    cout<<endl;
	}
	return 0;
}