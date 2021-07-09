
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

const int N=18;

pair<ll,ll> a[N];

double dp[(1<<N)];
ll n;

double getdist(pair<ll,ll> x,pair<ll,ll> y)
{
    double x1=x.ff;
    double y1=x.ss;
    double x2=y.ff;
    double y2=y.ss;

    double dis=sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));

    return dis;
}

double solve(ll mask)
{
   /// cout<<"MASK "<<mask<<endl;

    if(mask==(1<<n)-1)
    {
       /// cout<<"END "<<endl;
        return 0;
    }

    if(dp[mask]!=-1)
    {
        ///cout<<"DP mask "<<dp[mask]<<endl;
        return dp[mask];
    }

    double s=1e9;

    for(ll i=0;i<n;i++)
    {
       /// ll d=mask&(1<<i);
        /// cout<<"MASK BIT "<<d<<endl;

        if( (mask&(1<<i)) ==0)
        {
            ///cout<<"I "<<i<<endl;

            for(ll j=0;j<n;j++)
            {
                if( (mask&(1<<j))==0 and i!=j)
                {
                   /// cout<<"J "<<j<<endl;

                    s=min(s,getdist(a[i],a[j])+ solve( mask | (1<<i) | (1<<j) ) );

                }
            }
        }
    }

    ///cout<<"S "<<s<<endl;

    return dp[mask]=s;
}

int main()
{



    ll t,i,j,cas=0;

    while(1)
    {
        scanf("%lld",&n);
        if(n==0) break;

        for(i=0;i<(1<<N);i++) dp[i]=-1;

        n*=2;

        for(i=0;i<n;i++)
        {
            string s;cin>>s;

           scanf("%lld %lld",&a[i].ff,&a[i].ss);
        }

        double ans=solve(0);

       /// cout<<"ANS "<<ans<<endl;

        printf("Case %lld: %.2f\n",++cas,ans);



    }

    return 0;

}

/*

5
sohel 10 10
mahmud 20 10
sanny 5 5
prince 1 1
per 120 3
mf 6 6
kugel 50 60
joey 3 24
limon 6 9
manzoor 0 0
1
derek 9 9
jimmy 10 10
0

*/

