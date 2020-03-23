/*
Given two arrays A1[] and A2[] of size N and M respectively. 
The task is to sort A1 in such a way that the relative order among the elements will be same as those in A2. For the elements not present in A2, append them at last in sorted order. It is also given that the number of elements in A2[] are smaller than or equal to number of elements in A1[] and A2[] has all distinct elements.

First line of input contains number of testcases. For each testcase,
 first line of input contains length of arrays N and M and next two line contains N and M elements respectively.
*/include<bits/stdc++.h>
using namespace std;
main()
{

    int t;
    cin>>t;
    while(t--)
    {
        int n1,n2,j;
        cin>>n1>>n2;
        int a[n2];
        map<int,int> m;
        for(int i=0;i<n1;i++)
        {
            cin>>j;
            m[j]++;                                                      
        }
        for(int i=0;i<n2;i++)
        cin>>a[i];

        for(int i=0;i<n2;i++)
        {
            for(int j=0;j<m[a[i]];j++)
                cout<<a[i]<<" ";                                          
                m[a[i]]=0;                                                       
        }
        for(auto it=m.begin();it!=m.end();it++)
        {
            if(it->second!=0)
            {
                for(int i=0;i<it->second;i++)                              
                    cout<<it->first<<" ";
            }
        }
       cout<<endl;
    }
}
