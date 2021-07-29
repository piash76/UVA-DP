
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

const int N=500005;
ll a[N],dp[N];


int main()
{



    ll t,i,j,cas=0;

    while(1)
    {
        ll x;scanf("%lld",&x);

        ll idx=0;

        if(x==-1) break;

        a[idx++]=x;

        while(1)
        {
           scanf("%lld",&x);

            if(x==-1) break;

            a[idx++]=x;
        }
        reverse(a,a+idx);

        ll ans=0;

        for(i=0;i<idx;i++) dp[i]=1;


        for(i=1;i<idx;i++)
        {
            for(j=0;j<i;j++)
            {
                if(a[i]>a[j])
                {
                    dp[i]=max(dp[i],dp[j]+1);
                }
            }

        }

        for(i=0;i<idx;i++) ans=max(ans,dp[i]);

        if(cas!=0) printf("\n");

        printf("Test #%lld:\n", ++cas);
        printf("  maximum possible interceptions: %lld\n", ans);





    }

    return 0;

}

/*

389
207
155
300
299
170
158
65
-1
23
34
21
-1
-1


*/


