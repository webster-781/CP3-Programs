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
    while(getline(cin,s) && s.compare("END")!=0)
    {
        stringstream ss(s);
        double n;
        ss>>n;

        ll t = (ll)(n*1e6);
        n = (double)t/(double)1e6;
        int iter = 20;
        ll d = floorl(n*3.0);
        while(iter-- && d!=1)
        {
            // cout<<n<<" ";
            n *= 3;
            d = floorl(n);
            n -= d;
        }
        if(d==1)
            cout<<"NON-MEMBER\n";
        else
            cout<<"MEMBER\n";
    }
    return 0;
}