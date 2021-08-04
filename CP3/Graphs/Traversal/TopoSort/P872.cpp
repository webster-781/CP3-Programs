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
vector<string> out;

bool comp(string s, string t)
{
    return s.compare(t)<0;
}

void allTopoLogicalSorts(vector<vi>& edges, vector<int>& inDegree, vi& result, vector<bool>& vis, map<int,char>& val, map<char,int>& m)
{
    bool flag = true;
    loop(x,0,edges.size())
    {
        char x1 = val[x];
        if(!vis[x] && inDegree[x] == 0)
        {
            vis[x] = true;
            result.push_back(x);
            for(int c: edges[x])
                inDegree[c]--;
            allTopoLogicalSorts(edges,inDegree,result,vis,val,m);
            result.pop_back();
            for(int c: edges[x])
                inDegree[c]++;
            vis[x] = false;
            flag=false;
        }
    }
    if(flag && result.size() == edges.size())
    {
        string t = "";
        for(int tx: result)
        {
            t+= val[tx];
            t+= " ";
        }
        out.push_back(t.substr(0,t.length()-1));
    }
}

void solve(string s, string t)
{
    map<int,char> val;
    map<char,int> m;
    int counter = 0;
    for(char c: s)
        if(c!=' ')
        {
            val[counter] = c;
            m[c] = counter++;
        }
    
    vector<vi> edges;
    loop(i,0,counter)
    {
        vi x;
        edges.pb(x);
    }
    vector<int>inDegree(counter,0);
    int i = 0;
    while(i<t.length())
    {
        edges[m[t[i]]].push_back(m[t[i+2]]);
        inDegree[m[t[i+2]]]++;
        i += 4;
    }
    vi result ;
    vector<bool> vis(counter,false);
    int cnt = 0;
    allTopoLogicalSorts(edges,inDegree,result,vis,val,m);
    sort(out.begin(),out.end(),comp);
    for(string o: out)
        cout<<o<<endl;
    if(out.size()==0)
        cout<<"NO\n";
    out.clear();
    return;
}

int main()
{
    #ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
    
    int n;
    cin>>n;
    while(n--)
    {
        string s,t;
        while(getline(cin,s) && s.length()==0);
        getline(cin,t);
        solve(s,t);
        if(n>0)
            cout<<endl;
    }
}