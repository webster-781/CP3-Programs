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

ll fact(int n)
{
    if(n==0)
        return 1;
    return n*fact(n-1);
}

int main()
{
    int n;
    while(cin>>n)
    {
        if(n<=13 && n>=8)
            cout<<fact(n)<<endl;
        else if(n>13 || (n<0 && n%2))
            cout<<"Overflow!\n";
        else
            cout<<"Underflow!\n";
    }
}