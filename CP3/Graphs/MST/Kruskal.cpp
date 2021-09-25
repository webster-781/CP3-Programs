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
set<pair<int,pii> > E;

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
        p[i]=findSet(p[i]);
        return p[i];
    }
    bool isSameSet(int i, int j)
    {
        return findSet(i) == findSet(j);
    }

    void unionSet(int i, int j)
    {
        if(!isSameSet(i,j))
        {
            int x = findSet(i), y= findSet(j);
            if(size[x]>size[y])
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

void solve(int n, int m)
{
    edges.assign(n,vector<pii>(0));
    vector<pair<int,pii> > mst;
    E.clear();
    while(m--)
    {
        int x,y,w;
        cin>>x>>y>>w;
        // edges[x-1].pb(pii(y-1,w));
        // edges[y-1].pb(pii(x-1,w));
        E.insert(make_pair(w,pii(x-1,y-1)));
    }
    auto it = E.begin();
    UnionFind uf = UnionFind(n);
    int x = (*it).second.first;
    int y = (*it).second.second;
    loop(_,0,n-1)
    {
        while(uf.isSameSet(x,y))
        {
            advance(it,1);
            x = (*it).second.first;
            y = (*it).second.second;
        }
        uf.unionSet(x,y);
        mst.pb(*it);
    }
    loop(i,0,n)
        cout<<uf.findSet(i)<<" ";
        cout<<endl;
    for(auto x: mst)
        cout<<x.se.fi+1<<" "<<x.se.se+1<<" "<<x.fi<<endl;
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