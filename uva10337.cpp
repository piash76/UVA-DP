
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

const ll inf=1e9;


ll mat[12][10005],dp[12][10005];
ll n,m;


ll solve(ll r,ll c)
{
    if(r<0 or r>9 or c<0 or c>m) return inf;

   if(c==m)
   {
       if(r==0) return 0;
       else return inf;
   }

   if(dp[r][c]!=-1) return dp[r][c];

   ll s=LLONG_MAX;

   ll x1=r+1;
   ll y1=c+1;

   s=min(s,60-mat[r][c]+solve(x1,y1)); ///up


   ll x2=r;
   ll y2=c+1;
    ///same
    s=min(s,30-mat[r][c]+solve(x2,y2));


   ll x3=r-1;
   ll y3=c+1;

   ///if(c!=m-1)
    s=min(s,20-mat[r][c]+solve(x3,y3));  ///down




   return dp[r][c]=s;


}

int main()
{


    ll t,i,j;
    scanf("%lld",&t);
    while(t--)
    {

        memset(dp,-1,sizeof(dp));
        ll x;scanf("%lld",&x);

        n=10,m=x/100;

        for(i=9;i>=0;i--)
        {
            for(j=0;j<m;j++)
            {
                scanf("%lld",&mat[i][j]);
            }
        }

        ll ans=solve(0,0);
        printf("%lld\n\n",ans);

       /// cout<<"ANS "<<ans<<endl;



    }

    return 0;

}

/*

2
400
1 1 1 1
1 1 1 1
1 1 1 1
1 1 1 1
1 1 1 1
1 1 1 1
1 1 1 1
1 1 1 1
1 9 9 1
1 -9 -9 1
1000
9 9 9 9 9 9 9 9 9 9
9 9 9 9 9 9 9 9 9 9
9 9 9 9 9 9 9 9 9 9
9 9 9 9 9 9 9 9 9 9
9 9 9 9 9 9 9 9 9 9
9 9 9 9 9 9 9 9 9 9
7 7 7 7 7 7 7 7 7 7
-5 -5 -5 -5 -5 -5 -5 -5 -5 -5
-7 -3 -7 -7 -7 -7 -7 -7 -7 -7
-9 -9 -9 -9 -9 -9 -9 -9 -9 -9


*/



