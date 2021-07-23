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
const long maxN = 1e8;

ll gcd(ll a, ll b)
{
    return (b==0)?a:gcd(b,a%b);
}

void solve(int n)
{
    int A[n];
    loop(i,0,n)
        cin>>A[i];

    ll cnt = 0;
    loop(i,0,n)
    {
        loop(j,i+1,n)
        {
            if(gcd(A[i],A[j]) == 1)
                cnt ++;
        }
    }
    if(cnt == 0)
        cout<<"No estimate for this data set."<<endl;
    else
    {
        double m = (n)*(n-1)/2;
        cout<<fixed;
        cout<<setprecision(6);
        cout<<sqrt(6.0*m/((double)cnt))<<endl;
    }
}

int main()
{
    int n;
    while(cin>>n)
    {
        if(n==0)
            break;
        solve(n);
    }
}