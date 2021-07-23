//MAKER CODE

#include<bits/stdc++.h>
#define loop(x,i,n) for(int x = i; x < n; ++ x)
#define looprev(x,i,n) for(int x = i;x>=n;x--)
#define lloop(x,i,n) for(ll x = i; x < n; ++ x)
#define pb push_back
#define fi first
#define se second
using namespace std;
typedef long long int ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair <int,int> pii;
typedef map<int,int> mi;
typedef pair<long,long> pll;

int main()
{
    string s;
    getline(cin,s);
    map<char,int> m;
    vector<vi> v;
    loop(i,0,52)
    {
        vi x;
        v.pb(x);
    }
    int n = 0;
    for(char c = 'A'; c <= 'Z'; c++)
        m[c] = n++;
    for(char c = 'a'; c <= 'z'; c++)
        m[c] = n++;
    loop(i,0,s.size())
    {
        v[m[s[i]]].pb(i);
    }
    int l;
    cin>>l;
    while(l--)
    {
        int cf = s.size()-1, cl = 0;
        string t;
        cin>>t;
        int curr = -1;
        for(char c: t)
        {
            auto ind = upper_bound(v[m[c]].begin(),v[m[c]].end(),curr);
            if(ind == v[m[c]].end())
            {
                curr = -1;
                break;
            }
            else
            {
                curr = *ind;
                if(curr < cf)
                    cf = curr;
                if(curr > cl)
                    cl = curr;
            }
        }
        if(curr == -1)
            printf("Not matched\n");
        else
            printf("Matched %d %d\n",cf,cl);
    }
}