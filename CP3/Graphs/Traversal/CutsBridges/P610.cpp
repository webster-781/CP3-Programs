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
const int inf  = 1e8;

void DFS(int u, vi& dfs_parent,vector<vi>& edges, vector<pii>& dfs, map<pii,bool>& bridges, int& root, int &counter)
{
    dfs[u].fi = dfs[u].se = ++counter;

    for(int v: edges[u])
    {
        if(dfs[v].fi == -1)     // UNVISITED
        {
            dfs_parent[v] = u;
            DFS(v,dfs_parent,edges,dfs,bridges,root,counter);
            if(dfs[u].fi < dfs[v].se)   // Bridge
            {
                bridges[pii(min(u,v),max(u,v))] = true;
            }    // cout<<u<<" "<<v<<endl;
            
        }
    }
    for(int v: edges[u])
        if(v != dfs_parent[u])
            dfs[u].se = min(dfs[v].se,dfs[u].se);
}

void solve(int n, int m)
{
    vector<vi>edges(n,vi(0));
    map<pii,bool> bridges;
    vector<pii> dfs(n,pii(-1,-1));
    vi dfs_parent(n,-1);
    set<pii> E;
    int x,y;
    while(m--)
    {
        cin>>x>>y;
        if(x>=1 && x<=n && y>=1 && y<=n)
        {
        edges[x-1].pb(y-1);
        edges[y-1].pb(x-1);
        E.insert(pii(min(x-1,y-1),max(x-1,y-1)));
        }
    }
    int counter = 0;
    loop(i,0,n)
    {
        int root = i; 
        if(dfs[i].fi ==-1)
            DFS(i,dfs_parent,edges,dfs,bridges,root,counter);
        // printf("%d : %d %d %d\n",i+1,dfs[i].fi,dfs[i].se,dfs_parent[i]+1);
    }
    set<pii> out;
    for(auto e: E)
    {
        int x = e.fi, y = e.se;
        if(!bridges[e])
        {
            if(dfs_parent[x] == y)  // go y to x
                out.insert(pii(y,x));
            else if(dfs_parent[y] == x)     // go x to y
                out.insert(e);
            else    // cyclic back edge
            {
                if(dfs[y].fi > dfs[x].fi)   // go y to x
                    out.insert(pii(y,x));
                else    // go x to y
                    out.insert(e);
            }
        }
        else
        {
            out.insert(e);
            out.insert(pii(e.se,e.fi));
        }
    }
    for(auto e: out)
        cout<<e.fi+1<<" "<<e.se+1<<endl;
    cout<<"#"<<endl;
}

int main()
{
    #ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
    int n,m;
    int it = 0;
    while(cin>>n>>m && n!=0)
    {
        cout<<++it<<endl<<endl;
        solve(n,m);
    }
}