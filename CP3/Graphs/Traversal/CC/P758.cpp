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

int m1[] = {0,0,1,-1};
int m2[] = {1,-1,0,0};

int cntBalls(vector<string> &graph)
{
    int cnt = 0;
    loop(i,0,10)
        loop(j,0,15)
            cnt += (graph[i][j] != 'E');
    return cnt;
}

bool inside(pii x)
{
    return (x.first >= 0 && x.first < 10 && x.second >= 0 && x.second < 15);
}

int dfs(vector<string> &graph, pii x, map<pii,bool> &visited) // returns the size of cluster starting at x
{
    // cout<<"visiting "<<x.first<<" "<<x.second<<endl;
    visited[x] = true;
    int cnt = 1;
    loop(i,0,4)
    {
        pii n = pii(x.first + m1[i], x.second + m2[i]);
        if(inside(n) && !visited[n] && graph[n.first][n.second] == graph[x.first][x.second])
        {
            visited[n] = false;
            cnt += dfs(graph,n,visited);
        }
    }
    return cnt;
}

int latestEmptyRow(vector<string> &graph)
{
    looprev(i,9,0)
    {
        if(graph[i].compare("EEEEEEEEEEEEEEE") == 0)
            return i+1;
    }
    return 0;
}

int remove(vector<string> &graph, pii x, char c){
    graph[x.first][x.second] = 'E';
    int cnt = 1;
    loop(i,0,4)
    {
        pii n = pii(x.first + m1[i], x.second + m2[i]);
        if(inside(n) && graph[n.first][n.second] == c)
            cnt += remove(graph,n,c);
    }
    return cnt;
}

pii findLargest(vector<string> &graph)
{
    map<pii,bool> visited;
    int mxSize = 0;
    pii mx;
    loop(j,0,15)
    {
        looprev(i,9,0)
        {
            if(graph[i][j]!='E' && !visited[pii(i,j)])
            {
                int cnt = dfs(graph,pii(i,j),visited);
                // cout<<i<<" "<<j<<" "<<cnt<<endl;
                if(cnt > mxSize)
                {
                    mxSize = cnt;
                    mx = pii(i,j);
                }
                // else if(cnt == mxSize)
                // {
                //     if(j < mx.second)
                //         mx = pii(i,j);
                //     else if(j == mx.second && i > mx.first)
                //             mx = pii(i,j);
                // }
            }
        }
    }
    if(mxSize < 2)
        return pii(-1,-1);
    return mx;
}

bool emptyCol(vector<string> &graph, int j)
{
    loop(i,0,10)
        if(graph[i][j]!='E')
            return false;
    return true;
}

void swapCol(vector<string> &graph, int j, int k)
{
    if(j==k)
        return;
    loop(i,0,10)
        swap(graph[i][j],graph[i][k]);
}

void shift(vector<string> &graph)
{
    // column wise
    loop(j,0,15)
    {
        int spot = 10;   // lowest empty spot
        looprev(i,9,0)
        {
            if(graph[i][j] != 'E')  // this spot is not empty
            {
                graph[--spot][j] = graph[i][j];
                if(spot != i)
                    graph[i][j] = 'E';
            }
        }
    }

    // row-wise
    int sp = -1;     // right most non-empty col
    loop(j,0,15)
    {
        if(!emptyCol(graph,j))
            swapCol(graph,j,++sp);
    }
}

void solve(vector<string> &graph)
{
    ll score = 0, mv = 1;
    pii rm = findLargest(graph);
    while(rm.first != -1)
    {
        char c = graph[rm.first][rm.second];
        int t = remove(graph,rm,graph[rm.first][rm.second]);
        score += (ll)pow(t-2,2);
        printf("Move %lld at (%d,%d): removed %d balls of color %c, got %lld points.\n",mv++,9 - rm.first + 1,rm.second+1,t,c,(ll)pow(t-2,2));
        shift(graph);
        // loop(i,0,10)
        //     cout<<graph[i]<<endl;
        rm = findLargest(graph);
    }
    if(cntBalls(graph) == 0)
        score += 1000;
    printf("Final score: %lld, with %d balls remaining.\n",score,cntBalls(graph));
    return;
}

int main()
{
    int t;
    cin>>t;
    int  i=1;
    while(t--)
    {   
        vector<string> graph(10,"");
        string s;
        loop(i,0,10)
            cin>>graph[i];
        cout<<"Game "<<i++<<":\n\n";
        solve(graph);
        if(t>0)
            cout<<endl;
    }
}