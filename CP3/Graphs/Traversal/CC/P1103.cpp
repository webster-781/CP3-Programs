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
int m1[] = {0,0,1,-1};
int m2[] = {1,-1,0,0};

bool inside(vector<string> &g, int i, int j)    // checks if (i,j) is inside the graph or not
{
    return (i>=0 && i<g.size() && j>=0 && j<g[0].length());
}

void dfset(vector<string> &g, int x, int y, const char &c)     // sets c to all cells connected to i,j
{
    g[x][y] = c;
    loop(i,0,4)
    {
        int s1 = x+m1[i], s2 = y+m2[i];
        if(inside(g,s1,s2) && g[s1][s2] == 'W')
            dfset(g,s1,s2,c);
    }
}

void dfs(vector<string> &g, int x, int y, int &counter)
{
    g[x][y] = 'D';  // this black is done
    loop(i,0,4)
    {
        int s1 = x+m1[i], s2 = y+m2[i];
        if(inside(g,s1,s2) && g[s1][s2] == 'W')
        {
            counter ++;
            dfset(g,s1,s2,'0'+counter);
        }
        else if(inside(g,s1,s2) && g[s1][s2] == 'B')
        {
            dfs(g,s1,s2,counter);
        }
    }
}

void solve(int m, int n, vector<string> &g)
{
    loop(i,0,m)
    {
        if(g[i][0] == 'W')
            dfset(g,i,0,'O');   // sets outside to 'O';
        if(g[i][n-1] == 'W')
            dfset(g,i,n-1,'O');
    }
    loop(j,0,n)
    {
        if(g[0][j] == 'W')
            dfset(g,0,j,'O');   // sets outside to 'O';
        if(g[m-1][j] == 'W')
            dfset(g,m-1,j,'O');
    }
    string out = "";
    loop(j,0,n) // first colum wise
    {
        loop(i,0,m)
        {
            if(g[i][j] == 'B')  // new symbol
            {
                int counter = 0;    // no. of whites inside this figure
                dfs(g,i,j,counter);
                out += symbol[counter];
            }
        }
    }
    sort(out.begin(),out.end());
    cout<<out<<endl;
    // for(string s: g)
    //     cout<<s<<endl;
}

int main()
{
    int it= 1;
    int m,n;
    while(cin>>m>>n && m>0)
    {
        vector<string> graph(m,"");
        loop(i,0,m)
            cin>>graph[i];
        
        vector<string> g(m,"");
        loop(i,0,m)
        {
            loop(j,0,n)
            {
                stringstream ss;
                string s(1,graph[i][j]);
                s = "0x" + s;
                ss<<std::hex<<s;
                int t;
                ss>>t;
                string ans = "";
                loop(i,0,4)
                {
                    ans = ((t%2)?"B":"W") + ans;
                    t/=2;
                }
                g[i] += ans;
            }
        }
        cout<<"Case "<<it++<<": ";
        solve(m,n*4,g);
    }
}