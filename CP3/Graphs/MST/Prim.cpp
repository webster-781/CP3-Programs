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
typedef map<int,int>;

vector<vector<pii> > edges;
vector<bool> taken;
priority_queue<pii> pq;
ll mst_cost;
vector<pair<int,pii> > mst;

void process(int u)
{
    taken[u] = true;
    for(auto p: edges[u])
    {
        int v = p.first;
        int w = p.second;
        if(!taken[v])
            pq.push(pii(-w,-v));
    }
}

void solve(int n, int m)
{
    edges.assign(n,vector<pii>(0));
    taken.assign(n,false);
    pq = priority_queue<pii>();
    mst.clear();
    mst_cost = 0;
    while(m--)
    {
        int x,y,w;
        cin>>x>>y>>w;
        edges[x-1].pb(pii(y-1,w));
        edges[y-1].pb(pii(x-1,w));
    }

    process(0);
    while(!pq.empty())
    {
        int v = -pq.top().second;
        int w = -pq.top().first;
        pq.pop();
        if(!taken[v])
        {
            mst_cost += w;
            process(v);
        }
    }

    for(auto x: mst)
        cout<<x.se.fi+1<<" "<<x.se.se+1<<" "<<x.fi<<endl;
    cout<<mst_cost<<endl;
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