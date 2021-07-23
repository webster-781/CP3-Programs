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
const long maxN = 1e8;

bool done[1000001];

bool isps(long t)
{
    if(t<=0)
        return false;
    long y = sqrt(t);
    return (y*y == t);
}

long gcd(long a, long b)
{
    return (b==0)?a:gcd(b,a%b);
}

void add(long x, long m)
{
    for(int i = x; m > 0; i+=x, m--)
    {
        done[i] = true;
    }
}

void solve(long n)
{
    loop(i,0,n+1)
    {
        done[i] = false;
    }
    long count = 0;
    for(long r = 1; r <= sqrt(n); r++)
    {
        for(long s = r+1; r*r + s*s <= n; s++)
        {
            if(gcd(r,s) == 1 && (((r^s)&1) == 1))
            {
                // cout<<r<<" "<<s<<endl;
                count ++;
                long m = n/(r*r + s*s);
                add(s*s - r*r,m);
                add(2*r*s,m);
                add(s*s + r*r,m);
            }
        }
    }
    
    long cnt2 = 0;
    loop(i,1,n+1)
        cnt2 += done[i]?0:1;

    cout<<(count)<<" "<<cnt2<<endl;
}

int main()
{
    long n;
    while(cin>>n)
    {
        solve(n);
    }
}