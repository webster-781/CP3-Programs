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

void solve(ll n)
{
    if(n==0)
    {
        cout<<-1<<endl;
        return;
    }
    else if(n==1)
    {
        cout<<n<<endl;
        return;
    }
    int primes[8] = {9,8,7,6,5,4,3,2};
    ll t = abs(n);
    vi num;
    for(int y: primes)
    {
        while(t%y == 0)
        {
            t=t/y;
            num.pb(y);
        }
    }
    if(t>1)
        cout<<-1;
    else{
        sort(num.begin(),num.end());
        for(int i: num)
            cout<<i;
    }
    cout<<endl;
}

int main()
{
    int t;
    cin>>t;
    ll n;
    while(t--)
    {
        cin>>n;
        solve(n);
    }
}