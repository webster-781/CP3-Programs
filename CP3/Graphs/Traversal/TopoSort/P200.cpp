//MAKER CODE

#include<bits/stdc++.h>
#include<unordered_set>
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

pair<char,char> findEdge(string x, string y)    // x<y, find the first chars in both which differ
{
    loop(i,0,min(x.length(),y.length()))
        if(x[i] != y[i])
            return make_pair(x[i],y[i]);
    return make_pair('1','2');
}

void topoSort(char v, map<char,vector<char> >& edges, map<char,bool>& vis, vector<char>& tps)
{
    vis[v] = true;
    if(edges.count(v))
    {
        for(char r: edges[v])
        {
            if(!vis[r])
                topoSort(r,edges,vis,tps);
        }
    }
    tps.push_back(v);
}

void solve(vector<string>& v)
{
    map<char,vector<char> > edges;
    unordered_set <char> ver ;
    map<char,bool> vis;
    for(string s: v)
        loop(i,0,s.length())
            ver.insert(s[i]);
    int n = v.size();
    loop(i,0,v.size()-1)
    {
        pair<char,char> x = findEdge(v[i],v[i+1]);
        edges[x.first].pb(x.second);
    }
    vector<char>tps;
    for(char v: ver)
    {
        if(!vis[v])
            topoSort(v,edges,vis,tps);
    }
    reverse(tps.begin(),tps.end());
    for(char c: tps)
        cout<<c;
    cout<<endl;
}

int main()
{
    string s;
    while(cin>>s && s!="#")
    {
        vector<string> v;
        v.pb(s);
        while(cin>>s && s!="#")
            v.pb(s);
        solve(v);
    }
}