//MAKER CODE

#include<bits/stdc++.h>
#define loop(x,i,n) for(int x = i; x < n; ++ x)
#define looprev(x,i,n) for(int x = i;x>=n;x--)
#define lloop(x,i,n) for(ll x = i; x < n; ++ x)
#define pb push_back
using namespace std;
typedef long long int ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair <int,int> pii;
typedef map<int,int> mi;

long maxNode;

int travel(long node, long balls)   // if this is the balls'th ball at this node, then the last node to be reached
{
    long left = node*2, right = left+1;
    if(left < maxNode && right < maxNode)
        if(balls % 2 == 0)
            return travel(right,balls/2);
        else
            return travel(left,balls/2 + 1);
    else
        return node;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long h,x;
        cin>>h>>x;
        maxNode = pow(2,h);
        cout<<travel(1,x)<<endl;
    }
    cin>>t;
}