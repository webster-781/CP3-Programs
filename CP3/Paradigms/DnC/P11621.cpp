//MAKER CODE

#include<bits/stdc++.h>
#define loop(x,i,n) for(int x = i; x < n; ++ x)
#define looprev(x,i,n) for(int x = i;x>=n;x--)
#define lloop(x,i,n) for(ll x = i; x < n; ++ x)
#define pb push_back
#define fi first
#define se second
using namespace std;
typedef long long int ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair <int,int> pii;
typedef map<int,int> mi;
typedef pair<long,long> pll;

int main()
{
    ll x;
    while(cin>>x && x>0)
    {
        ll t = 1;
        while(t<x)
            t = (t<<1);
        
        // now t is the smallest power of 2 which is not less that x
        ll dmin = t-x;
        while(t%2 == 0)
        {
            t *= 3;
            while(t%2==0 && (t/2)>=x)
                t /= 2;
            if(t-x < dmin)
                dmin = t-x;
        }
        cout<<x+dmin<<endl;
    }
}