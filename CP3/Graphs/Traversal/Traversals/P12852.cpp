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

int dfs(string &s, int i, int j, map<char,int> &m)    // return no. of edges from s[i]=s[j]
{
    if(i == j-1)
        return 0;
    int cnt = 0;
    int si = i+1;
    int x = i+2;
    while(x<j)
    {
        if(s[x] == s[si])
        {
            cnt++;
            m[s[x]] = dfs(s,si,x,m) + 1;
            si = ++x;
        }
        x++;
    }
    return cnt;
}

void solve()
{
    string s;
    cin>>s;
    map<char,int> m;
    
    m[s[0]] = dfs(s,0,s.length()-1,m);
    for(char c = 'A'; c <= 'Z'; c++)
        if(m[c] > 0)
            printf("%c = %d\n",c,m[c]);
}

int main()
{
    int t;
    cin>>t;
    loop(i,1,t+1)
    {
        cout<<"Case "<<i<<"\n";
        solve();
    }
}