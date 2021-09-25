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
typedef map<char,int> mci;
typedef map<int,char> mic;

class UnionFind
{
    private: vi p, size;
    public:
        UnionFind(int N)
        {
            p.assign(N,0);
            size.assign(N,1);
            loop(i,0,N)
                p[i] = i;
        }
        int findSet(int i)
        {
            if(p[i] == i)
                return p[i];
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
        int findSize(int i)
        {
            return size[findSet(i)];
        }
};

void solve()
{
    int n;
    cin>>n;
    int cnt = 0;
    map<string,int> m;
    vector<pair<int,int> > edgelist;
    loop(i,0,n)
    {
        string x,y;
        cin>>x>>y;
        if(m.count(x) == 0)
            m[x] = cnt++;
        if(m.count(y) == 0)
            m[y] = cnt++; 
        edgelist.pb(pii(m[x],m[y])); 
    }
    UnionFind uf = UnionFind(cnt);
    loop(i,0,n)
    {
        uf.unionSet(edgelist[i].fi,edgelist[i].se);
        printf("%d\n",uf.findSize(edgelist[i].fi));
    }
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