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

ll calc(ll ** A, ll i1, ll i2, ll j1, ll j2)
{
    ll sub = A[i2][j2];
    if(i1)
        sub -= A[i1-1][j2];
    if(j1)
        sub -= A[i2][j1-1];
    if(i1*j1)
        sub += A[i1-1][j1-1];
    return sub;
}

int main()
{
    int t;
    cin>>t;
    loop(x,0,t)
    {
    int n,m,k;
    cin>>n>>m>>k;
    ll **A;
    A = new ll *[n];
    for(int i = 0; i <n; i++)
        A[i] = new ll[m];
    ll mx = -1e18;
    loop(i,0,n)
        loop(j,0,m)
        {
            cin>>A[i][j];
            mx = max(mx,A[i][j]);
        }
    loop(i,0,n)
        loop(j,0,m)
        {
            if(i>0)
                A[i][j] += A[i-1][j];
            if(j>0)
                A[i][j] += A[i][j-1];
            if(i*j>0)
                A[i][j] -= A[i-1][j-1];
        }
    if(mx<0)
    {
        cout<<mx<<endl;
        continue;
    }
    ll mxA = 0, mxC = 0;
    loop(i1,0,n)
        loop(i2,i1,n)
            loop(j1,0,m)
                loop(j2,j1,m)
                {
                    ll sub = calc(A,i1,i2,j1,j2);
                    ll Ar = (i2-i1+1)*(j2-j1+1);
                    if(sub <= k && Ar >= mxA)
                    {
                        if(Ar == mxA)
                            mxC = min(mxC,sub);
                        else
                            mxC = sub;
                        mxA = Ar;
                    }
                }

    printf("Case #%d: %lld %lld\n",x+1,mxA,mxC);
    }
}