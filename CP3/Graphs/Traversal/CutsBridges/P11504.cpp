//MAKER CODE

#include<bits/stdc++.h>
#include<unordered_set>
#define fi first
#define se second
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

vector<pii> dfs;
vi path, SCC;
vector<bool> vis;
vector<vi> edges;
int counter, countSCC;

void tarjanSCC(int u)
{
    dfs[u].fi = dfs[u].se = counter++;
    vis[u] = true;
    path.pb(u);

    for(int v: edges[u])
    {
        if(dfs[v].fi == -1)
            tarjanSCC(v);
        if(vis[v])
            dfs[u].se = min(dfs[u].se,dfs[v].se);
    }

    if(dfs[u].fi == dfs[u].se)
    {
        int t;
        do{
            t = path.back();
            path.pop_back();
            vis[t] = false;
            SCC[t] = countSCC;
        }
        while(t != u);
        countSCC++;
    }
}

void solve(int n,int m)
{
    // cout<<"HI";
    path.clear();
    SCC.assign(n,-1);
    edges.assign(n,vi(0));
    dfs.assign(n,pii(-1,-1));
    vis.assign(n,false);
    countSCC = counter = 0;
    while(m--)
    {
        int x,y;
        cin>>x>>y;
        edges[x-1].pb(y-1);
    }
    loop(i,0,n)
    {
        if(dfs[i].fi == -1)
            tarjanSCC(i);
    }
    vector<bool> right(countSCC,true);
    loop(i,0,n)
    {
        for(int v: edges[i])
            if(SCC[v]!=SCC[i])
                right[SCC[v]] = false;
    }
    int cnt = 0;
    for(bool x : right)
        cnt += x;
    cout<<cnt<<endl;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        solve(n,m);
    }
}