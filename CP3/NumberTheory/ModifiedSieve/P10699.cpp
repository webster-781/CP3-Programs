//MAKER CODE

#include<bits/stdc++.h>
#define loop(x,i,n) for(int x = i; x < n; ++ x)
#define looprev(x,i,n) for(int x = i;x>=n;x--)
#define lloop(x,i,n) for(ll x = i; x < n; ++ x)
#define pb push_back
using namespace std;
typedef long double ld;
typedef long long int ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair <int,int> pii;
typedef map<int,int> mi;
const ll maxN = 1e6;

vl msep(maxN+1,1);
vl msnumDFPF(maxN+1,0);

void modifiedSieve()
{
    lloop(i,2,maxN+1)
        if(msnumDFPF[i] == 0)   // i is prime
            for(ll j = i; j <= maxN; j+=i)
                msnumDFPF[j]++;
    lloop(i,2,maxN+1)
        msep[i] = i;

    lloop(i,2,maxN+1)
        if(msep[i]==i)  // i is prime
            for(ll j = i; j<=maxN; j+=i)
                msep[j] -= msep[j]/i;
}

int main()
{
    modifiedSieve();
    ll i;
    while(cin>>i)
    {
        if(i==0)
            break;
        cout<<i<<" : "<<msnumDFPF[i]<<endl;
    }
}