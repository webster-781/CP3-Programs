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
    int t;
    cin>>t;

    while(t--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        ll A[a][b][c];
        // bool flag = false;
        ll mx = -1e18;
        loop(i,0,a)
            loop(j,0,b)
                loop(k,0,c)
                {
                    cin>>A[i][j][k];
                    mx = max(mx,A[i][j][k]);
                }

        if(mx<0)
        {
            cout<<mx<<endl;
            if(t>0)
                cout<<endl;
            continue;
        }
        loop(i,0,a)
            loop(j,0,b)
                loop(k,0,c)
                {
                    if(i>0)
                        A[i][j][k] += A[i-1][j][k];
                    if(j>0)
                        A[i][j][k] += A[i][j-1][k];
                    if(i*j > 0)
                        A[i][j][k] -= A[i-1][j-1][k];
                }
        ll ans = 0;
        loop(i1,0,a)
            loop(j1,0,b)
                loop(i2,i1,a)
                    loop(j2,j1,b)
                    {
                        // cout<<i1<<" "<<j1<<" "<<i2<<" "<<j2<<endl;
                        ll sum = 0;
                        loop(k,0,c)
                        {
                            ll sub = A[i2][j2][k];
                            if(i1>0)
                                sub -= A[i1-1][j2][k];
                            if(j1>0)
                                sub -= A[i2][j1-1][k];
                            if(i1*j1>0)
                                sub += A[i1-1][j1-1][k];
                            
                            sum = max(0LL, sum + sub);
                            ans = max(ans,sum);
                        }
                    }

            cout<<ans<<endl;
            if(t>0)
                cout<<endl;
    }
}