//MAKER CODE

#include<bits/stdc++.h>
#define loop(x,i,n) for(int x = i; x < n; ++ x)
#define looprev(x,i,n) for(int x = i;x>=n;x--)
#define lloop(x,i,n) for(ll x = i; x < n; ++ x)
#define pb push_back
using namespace std;
typedef long double ld;
typedef long long int ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair <int,int> pii;
typedef map<int,int> mi;
const long maxN = 20;
const int digmax = 50;
int f [maxN+1][digmax];

ll fact(int n)
{
    return (n==0)?1:n*fact(n-1);
}

vi split(string s)
{
    int n = s.length();
    int cnt = 1;
    vi sp,x;
    for(char c: s)
        x.pb((int)c);
    sort(x.begin(),x.end());
    loop(i,1,n)
    {
        if(x[i] == x[i-1])
            cnt++;
        else
        {
            sp.pb(cnt);
            cnt = 1;
        }
    }
    sp.pb(cnt);
    return sp;
}

int main()
{
    int sn;
    cin>>sn;
    string s;
    loop(c,1,sn+1)
    {
        cin>>s;
        ll f = fact(s.length());
        vi sp= split(s);
        for(int x : sp)
            f = f/fact(x);
        cout<<"Data set "<<c<<": "<<f<<endl;
    }
}