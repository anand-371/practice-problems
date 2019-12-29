/*Circular tour
Suppose there is a circle. There are N petrol pumps on that circle. You will be given two sets of data.
1. The amount of petrol that every petrol pump has.
2. Distance from that petrol pump to the next petrol pump.

Your task is to complete the function tour() which returns an integer denoting the first point from where a truck will be able 
to complete the circle (The truck will stop at each petrol pump and it has infinite capacity).

Note :  Assume for 1 litre petrol, the truck can go 1 unit of distance.

Input:
The first line of input will be the number of test cases. Then T test cases follow. 
Each Test case contains 2 lines. The first line will contain an integer N denoting the number of petrol pumps and in the 
next line are N space separated values petrol and distance denoting the amount of petrol every petrol pump has and the distance
 to next petrol pump respectively .
*/
{
#include<bits/stdc++.h>
using namespace std;
struct petrolPump
{
    int petrol;
    int distance;
};
int tour(petrolPump [],int );
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        petrolPump p[n];
        for(int i=0;i<n;i++)
            cin>>p[i].petrol>>p[i].distance;
        cout<<tour(p,n)<<endl;
    }
}

}
/*This is a function problem.You only need to complete the function given below*/
/*
The structure of petrolPump is 
struct petrolPump
{
    int petrol;
    int distance;
};*/
/*You are required to complete this method*/
int tour(petrolPump p[],int n)
{
   int i=0,cap=0,start=0,difference=0;
   for(int i=0;i<n;i++){
       cap+=p[i].petrol-p[i].distance;
       if(cap<0){
           start=i+1;
           difference+=cap;
           cap=0;
       }
   }
   if(cap+difference<0){
       return -1;
   }else{
       return start;
   }
}
