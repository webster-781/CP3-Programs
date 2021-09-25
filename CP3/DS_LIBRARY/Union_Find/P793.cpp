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

class UnionFind
{
    private: vi rank, p;
    public:
        UnionFind(int n)
        {
            rank.assign(n,0);
            p.assign(n,0);
            loop(i,0,n)
                p[i]= i;
        }
        int findSet(int i)
        {
            if(p[i] == i)
                return i;
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
                int x = findSet(i); int y = findSet(j);
                if(rank[x]>rank[y])
                    p[y] = x;
                else if(rank[x] < rank[y])
                    p[x] = y;
                else
                {
                    p[x] = y;
                    rank[y]++;
                }
            }
        }
};

void solve()
{
    int n;
    cin>>n;
    UnionFind uf= UnionFind(n);
    string s;
    int cnt0 = 0, cnt1 = 0;
    while(getline(cin,s) && s.size()==0);
    do
    {
        stringstream ss(s);
        char c; int x,y;
        ss>>c;
        ss>>x>>y;
        if(c == 'c')
            uf.unionSet(x-1,y-1);
        else{
            if(uf.isSameSet(x-1,y-1))
                cnt1++;
            else
                cnt0++;
        }
        // cout<<c<<" "<<x<<" "<<y<<endl;
    }while(getline(cin,s) && s.size()>0);
    cout<<cnt1<<","<<cnt0<<endl; 
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
        if(t>0)
            cout<<endl;
    }
}