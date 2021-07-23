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
const ll MOD = 34943;

ll compute(string s, int i) // computes s[0..i]%MOD
{
    ll t = (int)(s[i]);
    if(i==0)
        return t;
    return ((compute(s,i-1)*256)%MOD + t)%MOD;
}

int main()
{
    string s;
    while(getline(cin,s))
    {
        if(s.compare("#") == 0)
            break;
        else
        {
            ll x = 0;
            if(s.length() > 0)
                x = compute(s,s.length()-1);
            x = (x*65536)%MOD;
            ll rem = (MOD-x)%MOD;
            int x1 = rem/256;
            int x2 = rem%256;
            printf("%02X %02X\n",x1,x2);
        }
    }
}