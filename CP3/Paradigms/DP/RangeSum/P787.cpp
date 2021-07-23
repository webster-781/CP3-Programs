//MAKER CODE

#include<bits/stdc++.h>
#define loop(x,i,n) for(int x = i; x < n; ++ x)
#define looprev(x,i,n) for(int x = i;x>=n;x--)
#define lloop(x,i,n) for(ll x = i; x < n; ++ x)
#define pb push_back
#define fi first
#define se second
using namespace std;
typedef unsigned long long LLU;
typedef long long int ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair <int,int> pii;
typedef map<int,int> mi;
typedef pair<long,long> pll;

int main()
{
    string s;
    ll t;
    while(cin>>t)
    {
        vl v;
        v.pb(t);
        while(cin>>t && t!= -999999)
            v.pb(t);
        int n = v.size();
        ll ans =  -1e18;
        loop(i,0,n)
        {
            ll prod = v[i];
            ans = max(ans,prod);
            loop(j,i+1,n)
            {
                prod *= v[j];
                ans = max(ans,prod);
            }
        }
        cout<<((ans == -1e18)?0:ans)<<endl;
    }
    return 0;
}