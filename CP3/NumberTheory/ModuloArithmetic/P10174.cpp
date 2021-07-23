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

int main()
{
    string s;
    while(getline(cin,s))
    {
        stringstream ss(s);
        ll a = LONG_MAX,b = LONG_MIN;
        ss>>a>>b;
        if(b==LONG_MIN)
        {
            if(a==0)
            {
                cout<<"0 0\n";
                continue;
            }
            if(a%4 == 2)
                cout<<"Bachelor Number.\n";
            else
            {
                ll x = (a%2)?(abs(a)+1)/2:abs(a)/4 + 1;
                ll y = (a%2)?(abs(a)-1)/2:abs(a)/4 - 1;
                if(a<0)
                    swap(x,y);
                cout<<x<<" "<<y<<endl;
            }
        }
        else
        {
            // if(b<a)
            // {
            //     cout<<0<<endl;
            //     continue;
            // }
            // int x = a%4;
            // int y = b%4;
            // ll z = a/4;
            // ll w = b/4;
            // ll cnt = (w-z);
            // if(x==3)
            //     cnt -= 1;
            // if(y>=2)
            //     cnt += 1;
            // cout<<(cnt)<<endl;
            ll cnt = 0;
            loop(i,a,b+1)
                if(i%4==2)
                    cnt++;
            cout<<cnt<<endl;
        }
    }
}