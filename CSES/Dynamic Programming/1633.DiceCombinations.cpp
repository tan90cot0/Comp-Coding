/*
Problem: 1633 - Dice Combinations                                                                                                                                    
Link - https://cses.fi/problemset/task/1633/
Author - Aryan Dua
*/

#include<iostream> 
#include<algorithm>
#include<cmath>
#include <math.h> 
#include <vector>
#include<set>
using namespace std;
#define forn(i,n) for(int i = 0;i<n;i++)
 
int main()
{
        int n;  cin>>n;
        int M = 1e9+7;
        vector <int> arr;
        for(int i= 0;i<n+1;i++)
        {
            if(i>=1 && i<=6)
                arr.push_back(1);
            else
                arr.push_back(0);
        }
        for(int i= 1;i<n+1;i++)
        {
            for(int j= 1;j<min(i, 7);j++)
                arr[i]= (arr[i]+arr[i-j])%M;
        }
        cout<<arr[n]<<endl;
            
}