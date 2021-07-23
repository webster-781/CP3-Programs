//MAKER CODE

#include<bits/stdc++.h>
#define loop(x,i,n) for(int x = i; x < n; ++ x)
#define looprev(x,i,n) for(int x = i;x>=n;x--)
#define lloop(x,i,n) for(ll x = i; x < n; ++ x)
#define pb push_back
using namespace std;
typedef long double ld;
typedef unsigned long long LLU;
typedef long long int ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair <int,int> pii;
typedef map<int,int> mi;

LLU power(LLU B,LLU P,int M)
{
    if(P==0)
        return 1;
    if(P==1)
        return B;
    LLU x = power(B,P>>1,M);
    if(P&1)
        return (B*(x*x % M) % M);
    else
        return (x*x % M);
}

int main()
{

    LLU B,P;
    int M;
    while(cin>>B>>P>>M)
        cout<<power(B,P,M)<<endl;
}