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
vi path,wSCC;
vector<bool> vis;
vector<vi> edges, SCC;
int counter, countSCC;

bool comp(string l, string r)
{
    return l.compare(r)<0;
}

void findAll(int u, set<string>& st, map<int,string>& val)
{
    vis[u] = true;
    for(int v: edges[u])
    {
        if(!vis[v])
        {
            st.insert(val[v]);
            findAll(v,st,val);
        }
    }
}

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
        vi x;
        do{
            t = path.back();
            path.pop_back();
            vis[t] = false;
            x.pb(t);
            wSCC[t] = countSCC;
        }
        while(t != u);
        SCC.pb(x);
        countSCC++;
    }
}

void put(string s, int& cnt, map<int,string>& val, map<string,int>& m)
{
    if(m.count(s) == 0)
    {
        m[s] = cnt;
        val[cnt] = s;
        cnt++;
    }
}

void solve(int n)
{
    map<int,string> val;
    map<string,int> m;
    int cnt = 0;
    // cout<<"HI";
    path.clear();
    SCC.clear();
    wSCC.assign(n,-1);
    edges.assign(n,vi(0));
    dfs.assign(n,pii(-1,-1));
    vis.assign(n,false);
    
    countSCC = counter = 0;
    loop(_,0,n)
    {
        string s;
        while(getline(cin,s) && s.size() == 0);
        stringstream ss(s);
        string x,y;
        ss>>x; put(x,cnt,val,m);
        while(ss>>y)
        {
            put(y,cnt,val,m);
            edges[m[x]].pb(m[y]);
        }
    }
    loop(i,0,n)
    {
        if(dfs[i].fi == -1)
            tarjanSCC(i);
    }
    set<string> st;
    loop(i,0,n)
    {
        if(SCC[wSCC[i]].size()>1)
        {
            for(int x: SCC[wSCC[i]])
            {
                st.insert(val[x]);
                findAll(x,st,val);
            }
        }
    }
    cout<<st.size()<<endl;
    string pr = "";
    for(string s: st)
        pr += s + " ";
    cout<<pr.substr(0,pr.length()-1)<<endl;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif
    int n;
    while(cin>>n && n>0)
    { 
        solve(n);
    }
}