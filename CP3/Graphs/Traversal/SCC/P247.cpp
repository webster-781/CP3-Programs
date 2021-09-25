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
vector<bool> vis;
int counter;
void tarjanSCC(int u, vector<vi>& edges, map<int,string>& val)
{
    dfs[u].fi = dfs[u].se = counter++;
    vis[u] = true;
    path.pb(u);
    for(int v: edges[u])
    {
        if(dfs[v].fi == -1)
            tarjanSCC(v,edges,val);
        if(vis[v])
            dfs[u].se = min(dfs[v].se,dfs[u].se);
    }

    if(dfs[u].fi == dfs[u].se)
    {
        int t;
        string s="";
        do
        {
            t = path.back();
            path.pop_back();
            vis[t] = false;
            s += val[t] + ", ";
        }
        while(t != u);
        s = s.substr(0,s.length()-2);
        cout<<s<<endl;
    }
}

void solve(int n, int M)
{
    dfs.assign(n,pii(-1,-1));
    vis.assign(n,false);
    vector<vi> edges(n,vi(0));
    map<string,int> m;
    map<int,string> val;
    int cnt = 0;
    while(M--)
    {
        string x,y;
        cin>>x>>y;
        if(m.count(x) == 0)
        {
            val[cnt] = x;
            m[x] = cnt++;
        }
        if(m.count(y) == 0)
        {
            val[cnt] = y;
            m[y] = cnt++;
        }
        edges[m[x]].pb(m[y]); // directed
    }
    counter = 0;
    loop(i,0,n)
        if(dfs[i].fi == -1)
            tarjanSCC(i,edges,val);
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif
    int n,m;
    int it = 1;
    while(cin>>n>>m && n>0)
    {
        if(it > 1)
        cout<<endl;
        cout<<"Calling circles for data set "<<(it++)<<":\n";
        solve(n,m);
    }
}