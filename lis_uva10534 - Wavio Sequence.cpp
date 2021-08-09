
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

const int N=10005;
ll a[N],b[N],c[N],lis[N],lds[N];


int main()
{


    ll t,i,j,cas=0;

    ll n;
    while(scanf("%lld",&n)!=EOF)
    {
        for(i=0;i<n;i++)
        {
            scanf("%lld",&a[i]);
            b[i]=c[i]=lis[i]=lds[i]=0;
        }

        ll idx1=0,idx2=0,ans=1,lislen=0,ldslen=0;

        for(i=0;i<n;i++)
        {
            idx1=lower_bound(b,b+lislen,a[i])-b;


            lislen=max(lislen,idx1+1);

            b[idx1]=a[i];

            lis[i]=idx1+1;

        }

        for(i=n-1;i>=0;i--)
        {
            idx2=lower_bound(c,c+ldslen,a[i])-c;

           /// cout<<"IDX2 "<<idx2<<endl;

            ldslen=max(ldslen,idx2+1);

            lds[i]=idx2+1;
            c[idx2]=a[i];
        }

        /*cout<<"LDS "<<endl;

        for(i=n-1;i>=0;i--) cout<<lds[i]<<" ";
        cout<<endl;*/


        for(i=0;i<n;i++)
        {

          ///  cout<<"LIS "<<lis[it1]<<" ";
           /// cout<<"LDS "<<lds[it2]<<" ";
           ll x=min(lis[i],lds[i]);

           ans=max(ans,(2*x)-1);


        }

        ///cout<<endl;


       ///cout<<"AMS "<<ans<<endl;

      /// if(cas) printf("\n");

       printf("%lld\n",ans);

       ///cas++;


    }

    return 0;

}

/*

10
1 2 3 4 5 4 3 2 1 10
19
1 2 3 2 1 2 3 4 3 2 1 5 4 1 2 3 2 2 1
5
1 2 3 4 5
4
1 2 5 4

///corner case


*/


