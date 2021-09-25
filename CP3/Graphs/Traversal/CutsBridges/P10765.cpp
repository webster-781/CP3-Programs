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

vi dfs_parent;
vector<pii> dfs;
vi path, ans;
int counter;
int V;
void DFS(int u, vector<vi>& edges, int& root, vi& ans)
{
    // printf("Visiting %d %d\n",u,counter);
    dfs[u].fi = dfs[u].se = counter++;
    path.pb(u);

    for(int v: edges[u])
    {
        if(dfs[v].fi == -1)
        {
            dfs_parent[v] = u;
            DFS(v,edges,root,ans);
            if(dfs[v].se >= dfs[u].fi)
            {
                ans[u]++;  
                // printf("%d is cut because of %d %d\n",u,v,dfs[v].se);
            }
        }
    }
    for(int v : edges[u])
    {
        if(v != dfs_parent[u])
            dfs[u].se = min(dfs[v].se,dfs[u].se);
    }
    if(u == root && ans[root] == 0)
        ans[root] ++;
    // printf("Leaving %d %d\n",u,dfs[u].se);
}

void solve(int n,int m)
{
    dfs_parent.clear();dfs.clear();path.clear();
    V = n;
    vector<vi> edges(n,vi(0));
    ans.assign(n,1);
    int x,y;
    while(cin>>x>>y && x!=-1)
    {
        edges[x].pb(y);
        edges[y].pb(x);
    }
    dfs_parent.assign(V,-1);
    dfs.assign(V,pii(-1,-1));
    loop(i,0,n)
    {
        if(dfs[i].fi == -1)
        {
            counter = 0;
            ans[i]  = 0;
            DFS(i,edges,i,ans);
        }
    }

    set<pii> s;
    loop(i,0,n)
        s.insert(pii(n-ans[i],i));
    for(pii x: s)
    {
        if(m--)
            printf("%d %d\n",x.se,n - x.fi);
        else
            break;
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif
    int n,m;
    while(cin>>n>>m && n>0)
    {
        solve(n,m);
        cout<<endl;
    }
}