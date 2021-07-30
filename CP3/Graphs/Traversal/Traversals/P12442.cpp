//MAKER CODE

#include<bits/stdc++.h>
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

void tarjanSCC(int v, vi &dfs_num, vi &dfs_low, vi &length, vector<bool> &visited, vi &to, int &counter, stack<int> &s, mi &m)
{
    // cout<<v<<" "<<counter<<" "<<to[v]<<endl;
    m[counter] = v;
    dfs_num[v] = dfs_low[v] = counter++;
    s.push(v);
    visited[v] = true;
    int r = to[v];
    if(dfs_num[r] == -1)    // r hasn't been visited yet
        tarjanSCC(r,dfs_num,dfs_low, length,visited,to,counter,s,m);
    if(visited[r])  // v is a part of SCC of r
        dfs_low[v] = min(dfs_low[v],dfs_low[r]);
    if(dfs_low[v] == dfs_num[v])        // SCC
    {   vi tc;
        int t = 0;
        while(true)
        {
            int x = s.top();
            t++;
            length[x] = t;
            visited[x] = false;
            s.pop();
            tc.push_back(x);
            if(x == v)
                break;
        }
        // cout<<v+1<<" "<<to[v]+1<<" "<<length[to[v]]<<endl;
        length[v] = length[to[v]] + 1;
        for(int x: tc)
            length[x] = length[v];
    }
}

void solve()
{
    int n;
    cin>>n;
    vi to(n,0);
    loop(_,0,n)
    {
        int x,y;
        cin>>x>>y;
        to[x-1] = y-1;
    }
    vi dfs_num(n,-1),dfs_low(n,-1),length(n,0);
    vector<bool> visited(n,false);stack<int> s;
    mi m;
    int counter = 0;
    loop(i,0,n)
    {
        if(dfs_num[i] == -1)
            tarjanSCC(i,dfs_num,dfs_low,length,visited,to,counter,s,m);
    }
    int mxi = 0;
    loop(i,0,n)
    {
        if(length[mxi]<length[i])
            mxi = i;
        // printf("%d, %d\n",i+1,length[i]);
    }
    cout<<mxi+1<<endl;
}

int main()
{
    int t;
    cin>>t;
    loop(i,1,t+1)
    {
        cout<<"Case "<<i<<": ";
        solve();
    }
}