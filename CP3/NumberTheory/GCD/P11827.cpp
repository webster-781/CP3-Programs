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
const long maxN = 500;

int nump[maxN+1];

ll gcd(ll a, ll b)
{
    return (b==0)?abs(a):gcd(abs(b),abs(a)%abs(b));
}

void solve()
{
    string str; 
    getline(cin, str); // For reading complete line with spaces 
    
    stringstream ss(str); 
    
    vl arr; 
    int x; 
    while(ss >> x){ 
        arr.push_back(x); 
	    if(ss.peek() == ' ')ss.ignore(); 
    }
    
    ll mg = 1;
    loop(i,0,arr.size())
    {
        loop(j,i+1,arr.size())
        {
            mg = max(mg,gcd(arr[i],arr[j]));
        }
    }
    cout<<mg<<endl;
}

int main()
{
    string str; 
    getline(cin, str); 
    stringstream ss(str); 
    int t;
    ss>>t;

    while(t--)
    {
        solve();
    }
}