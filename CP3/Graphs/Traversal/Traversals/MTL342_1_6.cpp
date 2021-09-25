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

vi BFS(int s, vector<vi >& edges)
{
    vi d(edges.size(),-1);
    d[s] = 0;
    queue<int> q;
    q.push(s);
    while(!q.empty())
    {
        int r = q.front();
        q.pop();
        for(int v : edges[r])
        {
            if(d[v] == -1)
            {
                q.push(v);
                d[v] = d[r]+1;
            }
        }
    }
    return d;
}

int findCutVertex(int& s, vector<vi>& edges, vector<bool>& mark)
{
    if(edges[s].size()==0)
    {
        cout<<"Nothing Found!"<<endl;
        return -1;
    }
    if(edges[s].size() == 1)
        return edges[s][0];
    for(int x: edges[s])
        mark[x] = false;
    vi nAdj;
    for(int x: edges[s])
    {
        for(int y: edges[x])
        {
            if(mark[y])
            {
                nAdj.pb(y);
                mark[y] = false;
            }
        }
    }
    edges[s] = nAdj;
    return findCutVertex(s,edges,mark);
}

void solve(int n, int m, int s, int t)
{
    vector<vi > edges(n,vi(0));
    while(m--)
    {
        int x,y;
        cin>>x>>y;
        edges[x].pb(y);
        edges[y].pb(x);
    }
    vi d = BFS(s,edges);
    cout<<d[t]<<endl;
    vector<bool> mark(n,true);
    mark[s] = false;
    cout<<findCutVertex(s,edges,mark)<<endl;
    return;
}


int main()
{
    #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif
    int n,m,s,t;
    cin>>n>>m>>s>>t;
    solve(n,m,s,t);
}