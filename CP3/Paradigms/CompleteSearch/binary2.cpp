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

int val[10000][10000];
int n;

bool inside(pii p, int v)
{
    if(p.first<0 || p.first>=n || p.second<0 || p.second>=n)
        return false;
    if(val[p.first][p.second]>v)
        return false;
    return true;
}

bool possible(int x1, int y1, int x2, int y2, int value)
{
    bool poss[n][n];
    loop(i,0,n)
        loop(j,0,n)
            poss[i][j] = false;
    pii arr [4] = {pii(0,1),pii(0,-1),pii(1,0),pii(-1,0)};
    if(val[x1][y1]>value)
        return false;
    queue<pii> points;
    points.push(pii(x1,y1));
    while(points.size()>0)
    {
        pii r = points.front();
        points.pop();
        for(auto ch: arr)
        {
            pii np = pii(r.first+ch.first,r.second+ch.second);
            if(inside(np,value) && poss[np.first][np.second] == false)
            {
                points.push(np);
                poss[np.first][np.second] = true;
            }
        }
    }
    return poss[x2][y2];
}

int main()
{
    cin>>n;
    int q;
    cin>>q;
    set<int> x;
    loop(i,0,n)
        loop(j,0,n)
        {
            cin>>val[i][j];
            x.insert(val[i][j]);
        }
    vi s;
    for(int i: x)
        s.pb(i);
    while(q--)
    {
        int x1,x2,y1,y2;
        cin>>x1>>y1>>x2>>y2;

        int l = 0, r = s.size()-1;
        while(l<r-1)
        {
            // cout<<l<<" "<<r<<endl;
            int mid = (double)(r+l)/2;
            bool p = possible(x1,y1,x2,y2,s[mid]);

            if(p)
                r = mid;
            else
                l = mid+1; 
        }
        if(possible(x1,y1,x2,y2,s[l]))
            cout<<s[l]<<endl;
        else
            cout<<s[r]<<endl;
    }
}