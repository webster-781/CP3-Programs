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
void sssp(int n, vector<vector<pii> > &edges)
{
    vector<int> time(n,INF);
    time[0] = 0;
    
    priority_queue<pii> pq;
    pq.push(pii(0,0));
    while(!pq.empty())
    {
        pii g = pq.top();
        int v = g.second;
        int t = g.first;
        pq.pop();
        if(t > time[v])
            continue;
        for(pii u: edges[v])
        {
            int r = u.first;
            int w = u.second;

            if(time[r] > time[v] + w)
            {
                time[r] = time[v] + w;
                pq.push(pii(time[r],r));
            }
        }
    }
    double mxT = time[0];
    int mx1 = 0;
    int mx2 = 0;

    loop(i,0,n)
    {
        double t1 = time[i];
        if(t1 > mxT)
        {
            mxT = t1;
            mx1 = i;
            mx2 = i;
        }
    }

    loop(i,0,n)
    {
        double t1 = time[i];
        
        for(pii t : edges[i])
        {
            double t2 = time[t.first];
            double te = t.second;

            double tm = (te + t1 + t2)/2;
            if(tm > mxT + 1e-5)
            {
                mxT = tm;
                mx1 = i;
                mx2 = t.first;
                if(mx1 > mx2)
                    swap(mx1,mx2);
            }
        }
    }
    int mxt = mxT*10;
    mxT = ((double)mxt)/10;
    if(mx1 == mx2)
        printf("The last domino falls after %0.1f seconds, at key domino %d.\n",mxT,mx1+1);
    else
        printf("The last domino falls after %0.1f seconds, between key dominoes %d and %d.\n",mxT,mx1+1,mx2+1);
}

void solve(int n, int m)
{
    vector<vector<pii> > edges;
    loop(i,0,n)
    {
        vector<pii> x;
        edges.push_back(x);
    }
    while(m--)
    {
        int x,y,t;
        cin>>x>>y>>t;
        edges[x-1].push_back(pii(y-1,t));
        edges[y-1].push_back(pii(x-1,t));
    }
    sssp(n,edges);
}

int main()
{
    int i = 1;
    int n,m;
    while(cin>>n>>m && n>0)
    {
        cout<<"System #"<<i++<<"\n";
        solve(n,m);
        cout<<"\n";
    }
}