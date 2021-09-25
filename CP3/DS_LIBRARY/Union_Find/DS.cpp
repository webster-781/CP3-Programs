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

class UnionFind{
    private: vi p,rank; int pi;
    public:
    UnionFind(int n)
    {
        p.assign(n,0);
        rank.assign(n,0);
        loop(i,0,n)
            p[i] = i;
    }
    int findSet(int i)
    {
        if(p[i]==i)
        {
            return i;
        }
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
            int x = findSet(i),y = findSet(j);
            if(rank[x] > rank[y])
                p[y] = x;
            else if(rank[y] > rank[x])
                p[x] = y;
            else
            {
                p[x] = y;
                rank[y]++;
            }
        }
    }
};

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif
    UnionFind uf = UnionFind(5);
    uf.unionSet(0,1);
    loop(i,0,5)
        cout<<uf.findSet(i)<<" ";
    cout<<endl;
    uf.unionSet(2,3);
    loop(i,0,5)
        cout<<uf.findSet(i)<<" ";
    cout<<endl;
    uf.unionSet(4,2);
    loop(i,0,5)
        cout<<uf.findSet(i)<<" ";
    cout<<endl;
    uf.unionSet(1,3);
    loop(i,0,5)
        cout<<uf.findSet(i)<<" ";
    cout<<endl;
}