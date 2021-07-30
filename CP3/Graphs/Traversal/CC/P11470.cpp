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
const int INF = 2e5;
string symbol[] = {"W","A","K","J","S","D"};
ll m1[] = {0,0,1,-1,1,1,-1,-1};
ll m2[] = {1,-1,0,0,1,-1,1,-1};

bool inside(ll n, pii x)    // checks if (i,j) is inside the graph or not
{
    ll i = x.first, j = x.second;
    return (i>=0 && i<n && j>=0 && j<n);
}
void bfs(ll n, vector<vl> &g)
{
    vector<ll> out;
    queue<pii> q;
    ll dist[n][n];
    loop(i,0,n)
        loop(j,0,n)
            dist[i][j] = n+1;
    ll d = 0;
    ll sum = 0;
    if(n&1)
    {
        q.push(pii(n/2,n/2));
        dist[n/2][n/2] = 0;
    }
    else
    {
        ll a1[] ={0,0,1,1};
        ll a2[] ={0,1,1,0};
        ll x1 = (n/2) -1, x2= (n/2) -1;
        loop(i,0,4)
        {
            q.push(pii(x1+a1[i],x2+a2[i]));
            dist[x1+a1[i]][x2+a2[i]] = 0;
        }
    }
    while(!q.empty())
    {
        pii x = q.front();
        ll x1 = x.first, x2 =x.second;
        q.pop();
        if(dist[x1][x2]>d)
        {
            d++;
            out.push_back(sum);
            sum = g[x1][x2];
        }
        else{
            sum += g[x1][x2];
        }
        loop(i,0,8)
        {
            ll s1 = x1+m1[i], s2 = x2+m2[i];
            if(inside(n,pii(s1,s2)) && dist[s1][s2] > dist[x1][x2]+1)
            {
                dist[s1][s2] = dist[x1][x2] + 1;
                q.push(pii(s1,s2));
            }
        }
    }
    out.push_back(sum);
    reverse(out.begin(),out.end());
    loop(i,0,out.size()-1)
        cout<<out[i]<<" ";
    cout<<out.back()<<endl;
}

int main()
{
    ll n;
    ll it=1;
    while(cin>>n && n>0)
    {
        vector<vl> g;
        loop(i,0,n)
        {
            vl x(n,0);
            loop(j,0,n)
                cin>>x[j];
           g.push_back(x);
        }
        cout<<"Case "<<it++<<": ";
        bfs(n,g);
    }
}