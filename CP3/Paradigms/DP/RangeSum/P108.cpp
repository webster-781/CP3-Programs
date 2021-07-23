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
    int N;
    cin>>N;
    ll A[N][N];
    ll mx = -1e18;
    loop(i,0,N)
        loop(j,0,N)
        {
            mx = max(mx,A[i][j]);
            cin>>A[i][j];
            if(i>0)
                A[i][j] += A[i-1][j];
        }
    if(mx<=0)
    {
        cout<<mx<<endl;
        return 0;
    }
    ll ans = 0;
    loop(i1,0,N)
        loop(i2,i1,N)
        {
            ll sum = 0;
            loop(j,0,N)
            {
                if(i1>0)
                    sum -= A[i1-1][j];
                sum += A[i2][j];
                sum = max(sum,0LL);
                ans = max(ans,sum);
            }
        }

    cout<<ans<<endl;
}