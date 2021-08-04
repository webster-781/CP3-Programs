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

int bfs(int x, vector<vi>& edges, vi& color)
{
    int n = edges.size();
    
    bool flag = false;
    int c0 = 0, c1 = 0;
    color[x] = 0;
    queue<int> q;
    q.push(x);
    while(!q.empty())
    {
        int v = q.front();
        if(color[v] == 0)
            c0++;
        else
            c1++;
        q.pop();
        // cout<<v+1<<" "<<c0<<" "<<c1<<endl;
        for(int u: edges[v])
        {
            if(color[u] == color[v])
                flag = true;
            if(color[u] == -1)
            {
                q.push(u);
                color[u] = 1-color[v];
            }
        }
    }
    // cout<<x<<" "<<color[4]<<" "<<color[8]<<endl;
    if(flag)
        return -1;
    if(min(c0,c1) == 0)
        return max(c0,c1);
    return min(c0,c1);
}

void solve()
{
    int n;
    cin>>n;
    vector<vi> edges;
    loop(i,0,n)
    {
        vi x;
        edges.push_back(x);
    }
    int m;
    cin>>m;
    while(m--)
    {int x,y;

        cin>>x>>y;
        edges[x].pb(y);
        edges[y].pb(x);
    }
    int mxcnt= 0;
    vi color(n,-1);
    loop(i,0,n)
        if(color[i] == -1)
        {
            int t = bfs(i,edges,color);
            if(t == -1)
            {
                cout<<-1<<endl;
                return;
            }
            mxcnt += t;
        }
    cout<<mxcnt<<endl;
}

int main()
{
    #ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
    
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
}