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
const ll maxN = 2e6;

vl msep(maxN+1,1);
vl depth(maxN+1,0);
vl sodf(maxN+1,0);
void modifiedSieve()
{
    lloop(i,2,maxN+1)
        msep[i] = i;

    lloop(i,2,maxN+1)
        if(msep[i]==i)  // i is prime
            for(ll j = i; j<=maxN; j+=i)
                msep[j] -= msep[j]/i;

    depth[1] = 0;
    depth[2] = 1;
    sodf[2] = 1;
    lloop(i,3,maxN+1)
    {
        depth[i] = depth[msep[i]] + 1;
        sodf[i] = sodf[i-1] + depth[i];
    }
}

int main()
{
    modifiedSieve();
    int t;
    cin>>t;
    while(t--)
    {
        ll x,y;
        cin>>x>>y;
        cout<<sodf[y] - sodf[x-1]<<endl;
    }
}