
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


const int N=500005;
ll a[N],lis[N],lds[N],b[N]; ///a for array, b for weight


int main()
{



    ll t,i,j,cas=0;

    scanf("%lld",&t);
    while(t--)
    {
        ll n;scanf("%lld",&n);

        for(i=0;i<n;i++)
        {
            scanf("%lld",&a[i]);
            lis[i]=lds[i]=0;
        }

        for(i=0;i<n;i++)
        {
            scanf("%lld",&b[i]);
        }

        for(i=0;i<n;i++)
        {
            lis[i]=b[i];
            lds[i]=b[i];
        }

        for(i=1;i<n;i++)
        {
            for(j=0;j<i;j++)
            {
                if(a[i]>a[j])
                {
                    lis[i]=max(lis[i],lis[j]+b[i]);
                }

                if(a[i]<a[j])
                {
                    lds[i]=max(lds[i],lds[j]+b[i]);
                }

            }
        }

        ll mx_i=0,mx_d=0;

        ///cout<<"LIS ";
        for(i=0;i<n;i++)
        {
           /// cout<<lis[i]<<" ";
            mx_i=max(lis[i],mx_i);
            mx_d=max(lds[i],mx_d);
        }
       /// cout<<endl;

        ///cout<<mx_i<<" "<<mx_d<<endl;

        printf("Case %lld. ",++cas);

        if(mx_i>=mx_d)
        {
            printf("Increasing (%lld). Decreasing (%lld).\n",mx_i,mx_d);

        }
        else
        {
            printf("Decreasing (%lld). Increasing (%lld).\n",mx_d,mx_i);

        }







    }

    return 0;

}


/*



3
6
10 100 50 30 80 10
50 10 10 15 20 10
4
30 20 20 10
20 30 40 50
3
80 80 80
15 25 20



*/



