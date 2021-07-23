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
int LIS(vi v)
{
    int n = v.size();
    if(n==0)
        return 0;
    int ans = 1;
    vi dp(n+1,inf);     // dp[i] represents the smallest value which is at the last index of i - length increasing subsequence
    dp[0] = -inf;
    auto it = dp.begin();
    advance(it,1);
    loop(i,0,n)
    {
        int ind = distance(dp.begin(),upper_bound(it,dp.end(),v[i]));
        dp[ind] = v[i];
    }
    loop(i,0,n+1)
    {
        if(dp[i] != inf)
            ans = i;
        else
            break;
        // cout<<dp[i]<<" ";
    }
    return ans;
}

int main()
{
    vi v;
    int t;
    while(cin>>t && t!=-1)
    {
        v.pb(t);
        while(cin>>t && t!=-1)
            v.pb(t);
        reverse(v.begin(),v.end());
        cout<<LIS(v)<<endl;
        v.clear();
    }
}