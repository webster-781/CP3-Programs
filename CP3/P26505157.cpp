//MAKER CODE

#include<bits/stdc++.h>
#define loop(x,i,n) for(int x = i; x < n; ++ x)
#define looprev(x,i,n) for(int x = i;x>=n;x--)
#define lloop(x,i,n) for(ll x = i; x < n; ++ x)
using namespace std;
typedef long long int ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair <int,int> pii;
typedef map<int,int> mi;

int main(){
bool flag = true;
char s[10000];
int i;
while(gets(s))
{
    for(i = 0; s[i]; i++)
    {
        if(s[i] == '\"')
        {
            if(flag)
                printf("``");
            else
                printf("''");
            flag = !flag;
        }
        else
            putchar(s[i]);
    }
    puts("");
}
}