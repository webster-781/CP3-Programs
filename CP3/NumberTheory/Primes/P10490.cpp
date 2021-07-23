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
typedef pair <ll,ll> pll;
typedef map<int,int> mi;
const long maxN = 32770;
vl primes;
vector<bool> isPrime;

void sieve()
{
    vector<bool> isp(maxN+1,true);
    isp[0] = false;
    isp[1] = false;
    for(ll i=2; i<=maxN; i++)
    {
        if(isp[i])
        {
            for(ll j = i*i; j<=maxN; j+=i)
                isp[j] =false;
            primes.pb(i);
        }
    }
    isPrime =isp;
    return;
}

void ispr(ll n)
{
    if(n==1)
    {
        cout<<"Perfect: 1!\n";
        return;
    }
    
    ll p1 = pow(2,n-1);
    ll p2 = pow(2,n) -1;
    ll p = p2;
    ll perfect = p2;
    // cout<<p2<<endl;
    bool pr = true;
    for(int i : primes)
    {
        int cnt = 0;
        while(p%i == 0)
        {
            p = p/i;
            if(p>1)
                pr = false;
            cnt ++; 
        }
        perfect *= (pow(i,cnt+1) - 1)/(i-1);
        // if(cnt>0)
        // {
        //     cout<<i<<" "<<cnt<<" "<<perfect<<endl;
        // }
    }
    if(p>1)
        perfect *= (p+1);
    if(isPrime[n] && perfect == 2*p1*p2)
        cout<<"Perfect: "<<perfect/2<<"!"<<endl;
    else if(isPrime[n])
        cout<<"Given number is prime. But, NO perfect number is available.\n";
    else
        cout<<"Given number is NOT prime! NO perfect number is available.\n";
}

int main()
{
    sieve();
    ll n;
    while(cin>>n)
    {
        if(n==0)
            break;
        ispr(n);
    }
    // ll t = 2305843008139952128;
    // cout<<t<<endl;
}