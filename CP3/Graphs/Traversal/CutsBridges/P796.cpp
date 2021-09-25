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

void DFS(int v, vector<vi>& edges, vector<pii>& dfs, vi& dfs_parent, set<pii>& bridges, int& counter)
{
    dfs[v].fi = dfs[v].se = counter++;
    for(int u: edges[v])
    {
        if(dfs[u].fi == -1) // UNVISITED
        {
            dfs_parent[u] = v;
            DFS(u,edges,dfs,dfs_parent,bridges,counter);

            if(dfs[u].se > dfs[v].fi)
                bridges.insert(pii(min(u,v),max(u,v)));
            
            dfs[v].se = min(dfs[u].se,dfs[v].se);
        }
        else if(u != dfs_parent[v])
            dfs[v].se = min(dfs[u].se,dfs[v].se);
    }
}

void solve(int n)
{
    vector<vi> edges(n,vi(0));
    loop(i,0,n)
    {
        string s;
        while(getline(cin,s) && s.empty());
        stringstream ss(s);
        int x,y; ss>>x;
        char c;
        while(ss>>c && c!=')');
        while(ss>>y)
        {
            edges[x].pb(y);
            edges[y].pb(x);
        }
    }
    vector<pii> dfs(n,pii(-1,-1)); vector<int> dfs_parent(n,-1); set<pii> bridges;
    int counter = 0;
    loop(i,0,n)
    {
        if(dfs[i].fi == -1)
            DFS(i,edges,dfs,dfs_parent,bridges,counter);
    }
    printf("%d critical links\n",(int)bridges.size());
    for(pii e : bridges)
        printf("%d - %d\n",e.fi,e.se);
    cout<<endl;
}

int main()
{
    #ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
    int n;
    while(cin>>n)
    {
        solve(n);
    }
}