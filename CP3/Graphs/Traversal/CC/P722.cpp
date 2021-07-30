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

bool inside(vector<string> &graph, pii x)
{
    return (x.first >= 0 && x.first < graph.size() && x.second >= 0 && x.second < graph[0].length() && graph[x.first][x.second] == '0');
}

int bfs(vector<string> &graph, pii x)
{
    if(graph[x.first][x.second] == '1')
        return 0;
    int m1[] = {0,0,1,-1};
    int m2[] = {1,-1,0,0};

    queue<pii> q;
    q.push(x);
    graph[x.first][x.second] = '1';
    int count = 1;
    while(!q.empty())
    {
        pii r = q.front();
        q.pop();
        loop(i,0,4)
        {
            pii n = pii(r.first+m1[i],r.second+m2[i]);
            if(inside(graph,n))
            {
                graph[n.first][n.second] = 1;
                count++;
                q.push(n);
            }
        }
    }
    return count;
}

int main()
{
    int t;
    cin>>t;
    string s;
    while(getline(cin,s) && s.size()==0);
    while(t--)
    {   pii x;
        stringstream ss(s);
        ss>>x.first>>x.second;
        vector<string> graph;
        while(getline(cin,s) && (s.size() <3 || s[2]!=' '))
        {
            // cout<<"GOT: "<<s;
            if(s.size() > 0)
                graph.push_back(s);
            else if(s.size() == 5)
                break;
        }
        cout<<bfs(graph,pii(x.first-1,x.second-1))<<endl;
        if(t>0)
            cout<<endl;
    }
}