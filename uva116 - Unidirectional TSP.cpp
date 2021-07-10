
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

ll dp[12][102],mat[12][102],path[12][102];
ll n,m;


ll solve(ll r,ll c)
{
    if(c==m-1) return mat[r][c];

    if(dp[r][c]!=-1) return dp[r][c];

    ll s=LLONG_MAX;

    ll x1=r-1;
    ll y1=c+1;
    if(x1<0) x1+=n;

    ll s1=mat[r][c]+solve(x1,y1);

    if(s1<s)
    {
        s=s1;
        path[r][c]=x1;

    }
    else if(s1==s)
    {
        if(path[r][c]>x1)
        {
             s=s1;
          path[r][c]=x1;

        }
    }

    ll s2=mat[r][c]+solve(r,c+1);

    if(s2<s)
    {
        s=s2;
        path[r][c]=r;

    }
    else if(s2==s)
    {
        if(path[r][c]>r)
        {
             s=s2;
          path[r][c]=r;

        }
    }


    ll x2=r+1;
    ll y2=c+1;
    if(x2==n) x2-=n;

    ll s3=mat[r][c]+solve(x2,y2);

    if(s3<s)
    {
        s=s3;
        path[r][c]=x2;

    }
    else if(s3==s)
    {
        if(path[r][c]>x2)
        {
             s=s3;
          path[r][c]=x2;

        }
    }

    return dp[r][c]=s;

}


int main()
{


    ll i,j;

    while(scanf("%lld %lld",&n,&m)!=EOF)
    {
        memset(dp,-1,sizeof(dp));

        for(i=0;i<12;i++)
        {
            for(j=0;j<102;j++) path[i][j]=LLONG_MAX;
        }

        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                scanf("%lld",&mat[i][j]);
            }
        }

     /// /*
        ll ans=LLONG_MAX,st;

        for(i=0;i<n;i++)
        {
            ll s=solve(i,0);
            if(ans>s)
            {
                ans=s;
                st=i;
            }
            else if(ans==s)
            {
                if(st>i)
                {
                    ans=s;
                    st=i;
                }
            }
        }

       /// */

        /*
        cout<<"ANS "<<ans<<endl;

        cout<<"ST "<<st<<endl;

        cout<<st+1<<" ";

        for(i=0;i<m-1;i++)
        {
            cout<<path[st][i]+1<<" ";
            st=path[st][i];
        }
        cout<<endl;

        */


        printf("%lld",st+1);

        for(i=0;i<m-1;i++)
        {
            printf(" %lld",path[st][i]+1);
            st=path[st][i];
        }
        printf("\n");

        printf("%lld\n",ans);






    }

    return 0;

}

/*

5 6
3 4 1 2 8 6
6 1 8 2 7 4
5 9 3 9 9 5
8 4 1 3 2 6
3 7 2 8 6 4
5 6
3 4 1 2 8 6
6 1 8 2 7 4
5 9 3 9 9 5
8 4 1 3 2 6
3 7 2 1 2 3
2 2
9 10 9 10

*/



