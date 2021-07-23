//MAKER CODE

#include<bits/stdc++.h>
#define loop(x,i,n) for(int x = i; x < n; ++ x)
#define looprev(x,i,n) for(int x = i;x>=n;x--)
#define lloop(x,i,n) for(ll x = i; x < n; ++ x)
#define pb push_back
using namespace std;
typedef long long int ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair <int,int> pii;
typedef map<int,int> mi;

vl out;

vi sieve(int n)
{
    vector<bool> isp(n+1,true);
    vi ans;
    ans.pb(1);
    loop(i,2,n+1)
    {
        if(isp[i])
        {
            for(int j = i*i; j<=n; j+=i)
                isp[j] = false;
            ans.pb(i);
        }
    }
    return ans;
}

void solve(int n, int c)
{
    vi primes = sieve(n);
    int m = (primes.size())/2;
    cout<<n<<" "<<c<<": ";
    if(primes.size()%2==0)
    {
        if(primes.size()<=(2*c))
        {
            loop(i,0,primes.size()-1)
                cout<<primes[i]<<" ";
            cout<<primes.back();
            cout<<"\n\n";
        }
        else    
        {
            loop(i,m-c,m+c-1)
                cout<<primes[i]<<" "; 
            cout<<primes[m+c-1];
            cout<<"\n\n";
        }
    }
    else
    {
        if(primes.size()<=(2*c-1))
        {
            loop(i,0,primes.size()-1)
                cout<<primes[i]<<" ";
            cout<<primes.back();
            cout<<"\n\n";
        }
        else
        {
            loop(i,m-c+1,m+c-1)
                cout<<primes[i]<<" ";    
            cout<<primes[m+c-1];  
            cout<<"\n\n";
        }
    }
}

int main()
{
    int n,k;
    while(cin>>n>>k)
        solve(n,k);
}