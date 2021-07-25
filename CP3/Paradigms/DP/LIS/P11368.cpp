//MAKER CODE

#include<bits/stdc++.h>
#define loop(x,i,n) for(int x = i; x < n; ++ x)
#define looprev(x,i,n) for(int x = i;x>=n;x--)
#define lloop(x,i,n) for(ll x = i; x < n; ++ x)
#define pb push_back
#define fi first
#define se second
using namespace std;
typedef unsigned long long LLU;
typedef long long int ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair <int,int> pii;
typedef map<int,int> mi;
typedef pair<long,long> pll;
int inf = 1e9;

bool comp(pii x, pii y)
{
    if(x.fi > y.fi && x.se > y.se)
        return true;
    else if(x.fi > y.fi)
        return true;
    else
        return false;
}

int LIS(vector<pii> v)
{
    int n = v.size();
    if(n==0)
        return 0;
    int ans = 0;
    vector<bool> end(n,false);      // represents the fact that this doll has been put inside other or not
    loop(i,1,n)
    {
        int find = -1;
        loop(j,0,i)
        {
            if(v[i].se < v[j].se && v[i].fi < v[j].fi && !end[j])
                find = j;
        }
        if(find !=-1)
            end[find] = true;
    }
    
    loop(i,0,n)
        ans += (!end[i]);
    return ans;
}



int main()
{
    int n;
    int t;
    cin>>t;
    int it = 0;
    loop(_,0,t)
    {
        cin>>n;
        vector <pii> v;
        int a,b;
        loop(i,0,n)
        {
            cin>>a>>b;
            v.pb(pii(a,b));
        }
        sort(v.begin(),v.end(),comp);
        // cout<<"SORTED: \n";
        // for(auto i : v)
        //     cout<<i.a<<" "<<i.b<<" "<<i.c<<endl;
        printf("%d\n",LIS(v));
    }
}