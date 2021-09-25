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

int DFS(int v, vector<pii>& dfs, vector<vi>& edges, int& counter, set<int>& cuts, vi& dfs_parent, int& root)
{
    // cout<<"At "<<v+1<<endl;
    dfs[v].fi = dfs[v].se = counter++;
    int cnt = 0;
    for(int u : edges[v])
    {
        if(dfs[u].fi == -1) // UNVISITED
        {
            dfs_parent[u] = v;
            DFS(u,dfs,edges,counter,cuts,dfs_parent,root);
                cnt++;
            if(dfs[u].se>=dfs[v].fi && v!=root)
                cuts.insert(v);
        }
    }
    for(int u : edges[v])
    {
        if(u != dfs_parent[v])
            dfs[v].se = min(dfs[v].se,dfs[u].se);
    }
    // printf("Setting dfs_low[%d] = %d\n",v+1,dfs[v].se);
    return cnt;
}

void solve(int n)
{
    vector<vi> edges(n,vi(0));
    int x,y;
    string s;
    while(getline(cin,s) && s[0]!='0')
    {
        stringstream ss(s);
        ss>>x;
        while(ss>>y)
        {
            edges[x-1].pb(y-1);
            edges[y-1].pb(x-1);
        }
    }
    vi dfs_parent(n,-1);
    int counter = 0;
    set<int> cuts;
    vector<pii> dfs(n,pii(-1,-1));
    loop(i,0,n)
    {
        if(dfs[i].fi==-1)   // unvisited
        {
            if(DFS(i,dfs,edges,counter,cuts,dfs_parent,i) > 1)
                cuts.insert(i);
        }
        // cout<<i+1<<" "<<dfs[i].fi+1<<" "<<dfs[i].se+1<<endl;
    }
    // for(int x: cuts)
        // cout<<x<<" ";
    cout<<cuts.size()<<endl;
}

int main()
{
    #ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
    int n;
    while(cin>>n && n!=0)
    {
        solve(n);
    }
}