#include <iostream>
#include <cstdio>
#include <set>
#include <cmath>
#include <fstream>
#include <cassert>
using namespace std;
typedef long long ll;
template<typename T> T gcd(T a, T b) {
    return (b ? __gcd(a,b) : a);
}

const int N = 2e5;


int n;
int seg[2*N];

void build(){
    for(int i = n-1; i>0;i--) seg[i] = gcd(seg[i<<1],seg[i<<1|1]);
}

void modify(int p, int val)
{
    for(seg[p+=n]=val;p>1;p>>=1) seg[p>>1] = gcd(seg[p],seg[p^1]);
}

int query(int l, int r)
{
    int res = -1;
    for(l+=n,r+=n;l<r;l>>=1,r>>=1)
    {
        if(l&1)
        {
            if(res==-1)
                res = seg[l++];
            else
                res = gcd(res,seg[l++]);
        }
        if(r&1)
        {
            if(res==-1)
                res = seg[--r];
            else
                res = gcd(seg[--r],res);
        }
    }
    return res;
}

int main(int argc, char* argv[])
{
    ifstream cin(argv[1]);
    ofstream cout(argv[2]);
    cin>>n;
    for(int i = 0;i<n;i++)
    {
        cin>>seg[i+n];
    }
    build();
    int q;
    cin>>q;
    while(q--)
    {
        int t;
        cin>>t;
        int l,r;
        cin>>l>>r;
        l--,r--;
        if(t==1)
        {
            modify(l,r+1);
        }
        else
        {
            cout<<query(l,r+1)<<endl;
        }
    }
}
