
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

const int N=105;
ll a[N],dp[N][N];
ll n;
///A-(B-(A-B))
///A-(B-(A-(B-A)))


ll solve(ll lft,ll rt)
{
    if(lft>rt) return 0;
    if(dp[lft][rt]!=-1) return dp[lft][rt];

    ll s=LLONG_MIN;

    ///left turn

    ll sum=0;
    for(ll i=lft;i<=rt;i++)
    {
        sum+=a[i];

        ll temp=sum-solve(i+1,rt);

        s=max(s,temp);
    }

    /// right turn

    sum=0;

    for(ll i=rt;i>=lft;i--)
    {
        sum+=a[i];

        ll temp=sum-solve(lft,i-1);

        s=max(s,temp);
    }


    return dp[lft][rt]=s;

}

int main()
{


    ll t,i,j;

    while(1)
    {
        scanf("%lld",&n);
        if(n==0) break;

        memset(dp,-1,sizeof(dp));

        for(i=0;i<n;i++) scanf("%lld",&a[i]);

        ll ans=solve(0,n-1);

        printf("%lld\n",ans);

       /// cout<<"ANS "<<ans<<endl;
    }


    return 0;

}

/*

4
4 -10 -20 7
4
1 2 3 4
0

*/


