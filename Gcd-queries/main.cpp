#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define EB emplace_back
#define NL cout<<"\n"
#define GCD(x,y) __gcd(x, y)
#define MOD 1000000007
#define VI vector <int>

int main() {
  
    int size,a,b,c,gcd;
    cin>>size;
    int max;
    VI arr;
    for(int i=0;i<size;i++)
    {
        cin>>a;
        arr.EB(a); 
    }
    cin>>size;
    for(int i=0;i<size;i++)
    {
        cin>>a>>b>>c;
        if(a==1)
        {
            arr[b-1]=c;
        }
        else
        {
            gcd=arr[b-1];
            for(int j=b;b<c;b++)
            {
                gcd=GCD(arr[b],gcd);
            }
            cout<<gcd;
            NL;                
        }
    }
    return 0;
}
