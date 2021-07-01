
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

vector<ll> v[25];
ll m,c;

ll dp[205][25];

ll solve(ll money,ll id)
{
    if(money<0) return -inf;

    if(id>=c) return m-money;

    if(dp[money][id]!=-1) return dp[money][id];

    ll s=LLONG_MIN;

    for(ll i=0;i<v[id].size();i++)
    {
        s=max(s,solve(money-v[id][i],id+1));
    }

    return dp[money][id]=s;
}

int main()
{


    ll t,i,j;
    scanf("%lld",&t);
    while(t--)
    {
        memset(dp,-1,sizeof(dp));
        for(i=0;i<25;i++) v[i].clear();

        scanf("%lld %lld",&m,&c);

        for(i=0;i<c;i++)
        {
            ll no;scanf("%lld",&no);
            for(j=1;j<=no;j++)
            {
                ll x;scanf("%lld",&x);
                v[i].push_back(x);
            }
        }


        ll ans=solve(m,0); ///money, id

        if(ans==-inf) printf("no solution\n");
        else printf("%lld\n",ans);

       /// cout<<"ANS "<<ans<<endl;






    }

    return 0;

}

/*

3
100 4
3 8 6 4
2 5 10
4 1 3 3 7
4 50 14 23 8
20 3
3 4 6 8
2 5 10
4 1 3 5 5
5 3
3 6 4 8
2 10 6
4 7 3 1 7


*/



