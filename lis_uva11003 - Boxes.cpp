

///Bismillahir Rahmanir Rahim
#include<bits/stdc++.h>

#define ll long long
#define pll  pair<ll,ll>

#define ff    first
#define ss    second

#define  mp  make_pair
#define  pb  push_back

#define cy  cout<<"YES"<<endl
#define cn   cout<<"NO"<<endl


using namespace std;

const ll inf=1e15;
const int mod=1e9+7;


const int N=100005;
ll a[N],w[N],l[N];

ll dp[1005][5010];
ll n;

ll solve(ll cur,ll cap)
{
    ///cout<<"CUR "<<cur<<" "<<cap<<endl;

    if(cur>=n or cap==0)
    {

        return 0;
    }

    if(dp[cur][cap]!=-1) return dp[cur][cap];

    ll s;

    if(w[cur]>cap)
    {
        s=solve(cur+1,cap); ///ignore this item
    }
    else
    {
        s=max( (1+solve(cur+1,min(cap-w[cur],l[cur]))) , solve(cur+1,cap) );  ///take this item or ignore

    }

    return dp[cur][cap]=s;
}

int main()
{



    ll t,i,j;

    while(1)
    {

        scanf("%lld",&n);
        if(n==0) break;

        memset(dp,-1,sizeof(dp));

        for(i=0;i<n;i++)
        {
            scanf("%lld %lld",&w[i],&l[i]);
        }


        ll s=solve(0,5005);

       /// cout<<"ANS "<<s<<endl;

         printf("%lld\n",s);


    }

    return 0;

}

/*

5
19 15
7 13
5 7
6 8
1 2
0

*/


