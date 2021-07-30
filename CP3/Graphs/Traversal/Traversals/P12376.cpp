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
pair<int,int> dfs(int v, vector<vi> &edges, vi &val)
{
    // cout<<"At "<<v<<endl;
    if(edges[v].size() == 0)
        return pii(v,val[v]);
    int mxI = edges[v][0];
    for(int i: edges[v])
    { 
        if(val[i] > val[mxI])
            mxI = i;
    }
    pii p = dfs(mxI,edges,val);
    return make_pair(p.first,p.second+val[v]);
}

void solve()
{
    int n,m;
    vector<vi> edges;
    cin>>n>>m;
    vi val(n,0);
    loop(_,0,n)
    {
        vi x;
        edges.push_back(x);
    }
    
    loop(i,0,n)
        cin>>val[i];

    while(m--)
    {
        int x,y;
        cin>>x>>y;
        edges[x].pb(y);
    }
    pii ans = dfs(0,edges,val);
    cout<<ans.second<<" "<<ans.first<<endl;
}

int main()
{
    int t;
    cin>>t;
    loop(i,1,t+1)
    {
        cout<<"Case "<<i<<": ";
        solve();
    }
}