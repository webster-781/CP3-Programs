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

bool in(pll left, pll x)   // if x lies after left
{
    return ((x.se*left.fi) < (x.fi*left.se));
}

bool equals(pll x, pll y)
{
    return x.fi*y.se == x.se*y.fi;
}

void find(pll left, pll right, pll x)// if I am currently b/w left and right
{
    pll mid = make_pair(left.fi+right.fi,left.se+right.se);
    // cout<<left.fi<<"/"<<left.se<<" "<<mid.fi<<"/"<<mid.se<<" "<<right.fi<<"/"<<right.se<<endl;
    if(equals(mid,x))
        return;
    if(in(mid,x))
    {
        cout<<"R";
        find(mid,right,x);
    }
    else
    {
        cout<<"L";
        find(left,mid,x);
    }
    return;
}

int main()
{   
    pll x = make_pair(0,0);
    while(cin>>x.fi>>x.se)
    {
        if(x.fi == 1 && x.se ==1)
            break;
        if(x.fi < x.se)
        {
            cout<<"L";
            find(make_pair(0l,1l),make_pair(1l,1l),x);
        }
            
        else 
        {
            cout<<"R";
            find(make_pair(1l,1l),make_pair(1l,0l),x);
        }
        cout<<endl;
    }
}