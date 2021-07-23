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
const long maxN = 1e8;

ll gcd(ll a, ll b)
{
    return (b==0)?a:gcd(b,a%b);
}

int dec(string s)
{
    return s.length()-2;
}

ll number(string s, int i, int j)
{
    ll n = 0;
    loop(x,i,j+1)
    {
        n = n*10 + (int)(s[x] - 48);
    }
    return n;
}

void solve(int i, int j, string s)
{
    int d = dec(s);
    ll x1,x2,den,x,g;
    if(j>0){
        int k = d-j;
        x2 = number(s,2,k+1);
        x1 = number(s,2,k+1+j);
        den = pow(10,k+j) - pow(10,k);
        x = x1 - x2;
    }
    else
    {
        x = number(s,2,s.length()-1);
        den = pow(10,s.length()-2);
    }
    g = gcd(x,den);
    x = x/g;
    den = den/g;
    cout<<"Case "<<i<<": "<<x<<"/"<<den<<endl;
}

int main()
{
    int j;
    string s;
    int i = 1; 
    while(cin>>j)
    {
        if(j == -1)
            break;
        cin>>s;
        solve(i,j,s);
        i++;
    }
}