//MAKER CODE

#include<bits/stdc++.h>
#include<utility>
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
typedef long double ld;
typedef pair<double,double> pd;

vector<pd> input(int N)
{
    vector<pd> v;
    double xsum = 0, ysum = 0;
    loop(i,0,N)
    {
        double x,y;
        cin>>x>>y;
        v.pb(make_pair(x,y));
        xsum += x;
        ysum += y;
    }
    double f = xsum/(double)N, l = ysum/(double)N;
    loop(i,0,N)
    {
        v[i].first = v[i].first - f;
        v[i].second = v[i].second - l;
    }
    return v;
}

bool comp(pd x, pd y)
{
    if(x.first - y.first < -1e-10)
        return true;
    else if(abs(x.first - y.first) < 1e-10)
        return (x.second - y.second < -1e-10);
    return false;
}

vector<pd> transform(vector<pd> v, double theta)
{
    vector<pd> tr;
    // cout<<"Transforming: "<<endl;
    for(auto p: v)
    {
        double x = cos(theta)*(p.first)  + sin(theta)*(p.second);
        double y = -sin(theta)*(p.first)  + cos(theta)*(p.second);
        tr.pb(pd(x,y));
        // cout<<p.first<<" "<<p.second<<" "<<x<<" "<<y<<endl;
    }
    return tr;
}

double mod(pd x)
{
    return pow(x.first,2) + pow(x.second,2);
}

bool eq_points(pd x, pd y)
{
    return (abs(x.first - y.first) + abs(x.second - y.second)) < 1e-10;
}

bool checkp(pd x, pd y)
{
    return (abs(mod(x) - mod(y)) < 1e-10);
}

bool check(vector<pd> x, vector<pd> y)
{
    sort(x.begin(),x.end(),comp);
    sort(y.begin(),y.end(),comp);

    // cout<<"After Sorting: "<<endl;

    // for(auto x1 : x)
    //     cout<<x1.first<<" "<<x1.second<<" "<<mod(x1)<<endl;

    // for(auto x2 : y)
    //     cout<<x2.first<<" "<<x2.second<<" "<<mod(x2)<<endl;

    int N = x.size();
    loop(i,0,N)
    {
        // cout<<i<<" "<<eq_points(x[i],y[i])<<endl;
        if(!eq_points(x[i],y[i]))
            return false;
    }
    return true;
}

int main()
{
    int N;
    vector<pd> p1,p2;
    cin>>N;
    p1 = input(N);
    p2 = input(N);

    if(N==1)
    {
        cout<<"Yes"<<endl;
        return 0;
    }
    if(eq_points(p1[0],pd(0.0,0.0))) // if p1[0] is center of gravity
        swap(p1[0],p1[1]);
    
    // for(auto x : p1)
    //     cout<<x.first<<" "<<x.second<<" "<<mod(x)<<endl;

    // for(auto x : p2)
    //     cout<<x.first<<" "<<x.second<<" "<<mod(x)<<endl;

    loop(i,0,N) // p1[0] maps to p2[i]
    {
        if(checkp(p1[0],p2[i]))
        {
            double theta = atan2(p1[0].second, p1[0].first) - atan2(p2[i].second, p2[i].first);
            // cout<<theta<<endl;
            vector<pd> np1 = transform(p1,theta);
            if(check(np1,p2))
            {
                cout<<"Yes"<<endl;
                return 0 ;
            }
        }
    }
    cout<<"No"<<endl;
}