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

bool inside(int R, int C, pii x)
{
    return  (x.first < R && x.first >= 0 && x.second < C && x.second >= 0);
}

void solve()
{
    int R,C,M,N;
    cin>>R>>C>>M>>N;
    vector<int> m1,m2;
    map<pii,bool> vis;
    map<pii,bool> allow;

    int k;
    cin>>k;
    while(k--)
    {
        int x,y;
        cin>>x>>y;
        allow[pii(x,y)] = true;
    }

    if(M==0 && N==0)
    {
        cout<<"1 0\n";
        return;
    }
    
    int temp = min(M,N);
    N = M + N - temp;
    M = temp;

    if(M==0)
    {
        m1.pb(M);   m2.pb(N);
        m1.pb(M);   m2.pb(-N);
        m2.pb(M);   m1.pb(N);
        m2.pb(M);   m1.pb(-N);
    }

    else
    {
    m1.pb(M);   m1.pb(M);   m1.pb(-M);  m1.pb(-M);
    m2.pb(N);   m2.pb(-N);  m2.pb(N);   m2.pb(-N);
    
    if(M!=N)
    {

        m2.pb(M);   m2.pb(M);   m2.pb(-M);  m2.pb(-M);
        m1.pb(N);   m1.pb(-N);  m1.pb(N);   m1.pb(-N);
    }
    }
    int odd = 0,even = 0;
    queue<pii> q;
    q.push(make_pair(0,0));
    vis[pii(0,0)] = true;
    while(!q.empty())
    {
        pii r = q.front();
        q.pop();
        int cnt= 0;
        for(int i = 0; i< m1.size(); i++)
        {
            pii v = pii(r.first+m1[i],r.second+m2[i]);
            if(inside(R,C,v) && !allow[v])
            {
                cnt++;
                if(vis[v] == 0)
                {
                    q.push(v);
                    vis[v] = true;
                }
            }
        }
        if(cnt%2)
            odd++;
        else
            even++;
        // cout<<r.first<<" "<<r.second<<" "<<cnt[r]<<endl;
    }
    cout<<even<<" "<<odd<<"\n";
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