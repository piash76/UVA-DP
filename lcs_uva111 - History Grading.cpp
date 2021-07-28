
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

const int N=22;
ll a[N],dp[N],b[N],c[N];

ll n;

int main()
{


    ll t,i,j;

    scanf("%lld",&n);
    map<ll,ll> ori1;

    for(i=1;i<=n;i++)
    {
        ll x;scanf("%lld",&x);
        ori1[x]=i;   ///x=kaj, i=ordering

    }

    for(ll kaj=1;kaj<=n;kaj++)
    {
        a[kaj]=ori1[kaj];
    }



    ///for(i=1;i<=n;i++) cout<<a[i]<<" ";
   /// cout<<endl;



    ll tmp,id=1;
    while(scanf("%lld",&tmp)==1)
    {

        map<ll,ll> ori2;

        ori2[tmp]=id++;

        for(i=1;i<n;i++)
        {
            scanf("%lld",&tmp);
            ori2[tmp]=id++;
        }

        for(ll kaj=1;kaj<=n;kaj++)
        {
            b[kaj]=ori2[kaj];
        }



        ///for(i=1;i<=n;i++) cout<<b[i]<<" ";
        /// cout<<endl;

        map<ll,ll> m;
        for(i=1;i<=n;i++)
        {
            m[a[i]]=i;
        }

        ll idx=0;
        for(i=1;i<=n;i++)
        {
            c[idx++]=m[b[i]];
        }




        for(i=0;i<n;i++) dp[i]=1;

        ll ans=0;

        for(i=1;i<n;i++)
        {
            for(j=0;j<i;j++)
            {
                if(c[i]>c[j])
                {
                    dp[i]=max(dp[i],dp[j]+1);
                }
            }
        }

        for(i=0;i<n;i++) ans=max(ans,dp[i]);

        printf("%lld\n",ans);

        id=1;

    }

    return 0;

}




