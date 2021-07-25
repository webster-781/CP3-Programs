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
int inf = 1e9;

struct triple
{
    int a,b,c;
    triple(int x, int y, int z)
    {
        a = x;
        b = y;
        c = z;
    }
};

bool comp(triple x, triple y)
{
    if(x.a > y.a && x.b > y.b)
        return true;
    else if(x.a > y.a)
        return true;
    else
        return false;
}

int LIS(vector<triple> v)
{
    int n = v.size();
    if(n==0)
        return 0;
    int ans = 0;
    int dp[n]; // dp[i] contains the max height of a subsequence ending at v[i]
    dp[0]= v[0].c;
    int maxH = v[0].c;
    loop(i,1,n)
    {
        dp[i] = 0;
        loop(j,0,i)
        {
            if(v[i].b < v[j].b && v[i].a < v[j].a)
                dp[i] = max(dp[i],dp[j]);
        }
        dp[i] += v[i].c;
        maxH = max(maxH,dp[i]);
    }
    return maxH;
}



int main()
{
    int n;
    int it = 0;
    while(cin>>n &&  n>0)
    {
        vector <triple> v;
        int a,b,c;
        loop(i,0,n)
        {
            cin>>a>>b>>c;
            v.pb(triple(a,b,c));
            v.pb(triple(b,a,c));
            v.pb(triple(c,a,b));
            v.pb(triple(a,c,b));
            v.pb(triple(b,c,a));
            v.pb(triple(c,b,a));
        }
        sort(v.begin(),v.end(),comp);
        // cout<<"SORTED: \n";
        // for(auto i : v)
        //     cout<<i.a<<" "<<i.b<<" "<<i.c<<endl;
        printf("Case %d: maximum height = %d\n",++it,LIS(v));
    }
}