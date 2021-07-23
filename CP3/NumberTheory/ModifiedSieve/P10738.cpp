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

vl mu(maxN+1,-2);
vl M(maxN+1,0);

void modifiedSieve()
{
    mu[1] = 1;
    M[1] = 1;
    lloop(i,2,maxN+1)
    {
        if(mu[i] == -2) // i is prime
        {
            for(ll j = i; j<=maxN; j+=i)
            {
                if(mu[j] == -2)
                    mu[j] = 1;
                if(j%(i*i))
                    mu[j] *= (-1);
                else
                    mu[j] = 0;
            }
        }
        M[i] = M[i-1] + mu[i];
    }
}

int main()
{
    modifiedSieve();
    ll i;
    while(cin>>i)
    {
        if(i==0)
            break;
        cout<<setw(8)<<right<<i;
        cout<<setw(8)<<right<<mu[i];
        cout<<setw(8)<<right<<M[i]<<endl;
    }
}