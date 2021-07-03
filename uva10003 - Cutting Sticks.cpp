
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

const ll inf=1e18;
const int mod=1e9+7;
const int mod2=2147483647; ///2^31-1

const int N=55;
ll a[N],dp[N][N];
ll n;



ll solve(ll lft,ll rt)  ///assuming left and right part is cut off
{
    if(rt-lft==1) return 0;

    if(dp[lft][rt]!=-1) return dp[lft][rt];

    ll s=LLONG_MAX;

    for(ll i=lft+1;i<rt;i++)
    {
        s=min(s,a[rt]-a[lft]+solve(lft,i)+solve(i,rt));
    }

    return dp[lft][rt]=s;


}

int main()
{


    ll t,i,j;

    while(1)
    {
        ll len;
        scanf("%lld",&len);
        if(len==0) break;

        memset(dp,-1,sizeof(dp));

        scanf("%lld",&n);
        for(i=1;i<=n;i++) scanf("%lld",&a[i]);

        a[0]=0;a[n+1]=len;

        ll ans=solve(0,n+1);

        printf("The minimum cutting is %lld.\n",ans);




    }

    return 0;

}

/*

100
3
25 50 75
10
4
4 5 7 8
0

*/


