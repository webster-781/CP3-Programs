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

bool comp(string l, string s)
{
    return (l.compare(s)<0);
}

void allTopologicalSorts(vi &result, vector<bool> &visited, vi &inDegree, vector<vi> &edges, map<int,char> &val, vector<string> &outs)
{
    bool flag = false;
    int n = edges.size();
    loop(i,0,n)
    {
        if(inDegree[i] == 0 && !visited[i])
        {
            for(int j : edges[i])   // remove i from this graph
                inDegree[j]--;

            visited[i] = true;
            result.push_back(i);
            allTopologicalSorts(result,visited,inDegree,edges,val,outs);

            visited[i] = false;
            result.pop_back();

            for(int j : edges[i])   // remove i from this graph
                inDegree[j]++;
            flag = true;
        }
    }

    if(!flag)
    {
        string ans = "";
        for(int i : result)
            ans += val[i];
        outs.push_back(ans);
    }
}


void solve(string s)
{
    map<char,int> m;
    map<int,char> val;
    int sz = 0;
    for(char c: s)
    {
        if(c!= ' ')
        {
            m[c] = sz;
            val[sz++] = c;
        }
    }
    vector<vi> edges;
    loop(i,0,sz)
    {
        vi np;
        edges.push_back(np);
    }
    vi inDegree(sz,0);
    string t;
    getline(cin,t);
    int i = 0;
    while(i<t.length())
    {
        edges[m[t[i]]].push_back(m[t[i+2]]);
        inDegree[m[t[i+2]]]++;
        i += 4;
    }
    vi result;
    vector<bool> visited(sz,false);
    vector<string> outs;
    allTopologicalSorts(result,visited,inDegree,edges,val,outs);

    sort(outs.begin(),outs.end(),comp);
    for(auto ans: outs)
        cout<<ans<<endl;
}

int main()
{
    string s;
    int it= 0;
    while(getline(cin,s))
    {
        if(it++ > 0)
            cout<<endl;
        solve(s);
    }
}