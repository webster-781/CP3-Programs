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
vi path;
int countSCC, counter;
vector<bool> vis;
vector<vi> edges;

class UnionFind{
    private: vi p, size;
    public:
    UnionFind(int n)
    {
        p.assign(n,0);
        size.assign(n,1);
        loop(i,0,n)
            p[i]= i;
    }
    int findSet(int i)
    {
        if(p[i] == i)
            return i;
        p[i] = findSet(p[i]);
        return p[i];
    }
    bool isSameSet(int i, int j)
    {
        return (findSet(i) == findSet(j));
    }
    void unionSet(int i, int j)
    {
        if(!isSameSet(i,j))
        {
            int x = findSet(i), y = findSet(j);
            if(size[x] > size[y])
            {
                p[y] = x;
                size[x] += size[y];
            }
            else
            {
                p[x] = y;
                size[y] += size[x];
            }
        }
    }
};

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
            dfs[u].se = min(dfs[v].se,dfs[u].se);
    }
    if(dfs[u].fi == dfs[u].se)
    {
        // printf("SCC %d: ",countSCC+1);
        int t;
        do{
            t = path.back();
            path.pop_back();
            vis[t] = false;
            // printf("%d ",t);
        }while(t != u);
        // cout<<endl;
        countSCC++;
    }
}

void solve(int n, int m)
{
    UnionFind uf = UnionFind(n);
    dfs.assign(n,pii(-1,-1));
    edges.assign(n,vi(0));
    vis.assign(n,false);
    vector<pii> E;
    while(m--)
    {
        int x,y,z;
        cin>>x>>y>>z;
        if(z==1)
            E.pb(pii(x-1,y-1));
        else
            uf.unionSet(x-1,y-1);
    }
    for(auto e: E)
        if(!uf.isSameSet(e.fi,e.se))
            edges[uf.findSet(e.fi)].pb(uf.findSet(e.se));
    countSCC = counter = 0;
    loop(i,0,n)
        if(uf.findSet(i) == i && dfs[i].fi == -1)
            tarjanSCC(i);
    cout<<(countSCC==1)<<endl;
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
    }
}