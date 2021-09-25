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

void solve(int n)
{
    vi m(26,-1);
    int M;
    cin>>M;
    vector<vi> edges(n,vi(0));
    string s,t;
    cin>>s;
    int cnt = 0;
    while(M--)
    {
        cin>>t;
        char c1 = t[0], c2 = t[1];
        // cout<<c1<<" "<<c2<<" "<<m[c1-65]<<" "<<m[c2-65]<<endl;
        if(m[c1-65] == -1)
            m[c1 - 65] = cnt++;
        if(m[c2-65] == -1)
            m[c2 - 65] = cnt++;
        edges[m[c1-65]].pb(m[c2-65]);
        edges[m[c2-65]].pb(m[c1-65]);
    }
    vector<int> awake(n,-1);
    vi toWake;
    if(m[s[0]-65] == -1)
            m[s[0] - 65] = cnt++;
    if(m[s[1]-65] == -1)
            m[s[1] - 65] = cnt++;
    if(m[s[2]-65] == -1)
            m[s[2] - 65] = cnt++;
    toWake.pb(m[s[0]-65]);
    toWake.pb(m[s[1]-65]);
    toWake.pb(m[s[2]-65]);
    int y = 0;
    while(!toWake.empty())
    {
        for(int i : toWake)
            awake[i] =y;
        toWake.clear();
        loop(i,0,n)
        {
            if(awake[i] == -1)
            {
                int cnt = 0;
                for(int j : edges[i])
                    if(awake[j]>=0)
                        cnt++;
                if(cnt>=3)
                    toWake.pb(i);
            }
        }
        y++;
    }
    // cout<<cnt<<endl;
    loop(i,0,n)
    {
        if(awake[i] == -1)
        {
            cout<<"THIS BRAIN NEVER WAKES UP\n";
            return;
        }
    }
    printf("WAKE UP IN, %d, YEARS\n",y-1);
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif
    int n;
    while(cin>>n)
    {
        solve(n);
    }
}