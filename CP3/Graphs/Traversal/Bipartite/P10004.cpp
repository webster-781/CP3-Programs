//MAKER CODE

#include<bits/stdc++.h>
#include<unordered_set>
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

bool bfs(int x, vector<vi>& edges, vi& color)
{
    color[x] = 0;
    queue<int> q;
    q.push(x);
    while(!q.empty())
    {
        int v = q.front();
        q.pop();
        for(int u: edges[v])
        {
            if(color[v] == color[u])
                return false;
            if(color[u] == -1)
                q.push(u);
            color[u] = 1-color[v];
        }
    }
    return true;
}

void solve(int n, int m)
{
    vector<vi> edges;
    vi color(n,-1);
    loop(i,0,n)
    {
        vi x;
        edges.push_back(x);
    }
    while(m--)
    {
        int x,y;
        cin>>x>>y;
        edges[x].pb(y);
        edges[y].pb(x);
    }
    loop(i,0,n)
    {
        if(color[i] == -1 && !bfs(i,edges,color))
        {
            cout<<"NOT BICOLORABLE.\n";
            return;
        }
    }
    cout<<"BICOLORABLE.\n";
}

int main()
{
    #ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
    
    int n,m;
    while(cin>>n && n!=0)
    {
        cin>>m;
        solve(n,m);
    }
}