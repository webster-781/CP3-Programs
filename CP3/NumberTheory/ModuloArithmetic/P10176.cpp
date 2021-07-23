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
const ll d = 131071;

bool divisible(vl arr, ll n, ll i)
{
    if(i>=arr.size() && n==0)
        return true;
    else if(i>=arr.size())
        return false;
    n = (n<<1) + arr[i];
    n = n%d;
    return divisible(arr,n,i+1);
}

int main()
{
    vl arr;
    string s = "";
    bool end = false;
    while(cin>>s)
    {
        while(!end)
        {
            for(char c: s)
            {
                if(c=='0' || c=='1')
                    arr.pb(c-48);
                if(c=='#')
                {
                    end = true;
                    s = "";
                }
            }
            if(!end)
                cin>>s;
        }
        end = false;
        cout<<(divisible(arr,0,0)?"YES":"NO")<<endl;
        arr.clear();
    }
}