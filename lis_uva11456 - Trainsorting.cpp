///https://www.quora.com/What-is-an-intuitive-explanation-for-UVA-11456-Trainsorting
///http://codingwithsandhu.blogspot.com/2018/05/11456-trainsorting.html


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


const int N=2005;
ll a[N],lis[N],lds[N];


int main()
{

    ll t,i,j;
    scanf("%lld",&t);

    while(t--)
    {
        memset(lis,0,sizeof(lis));
        memset(lds,0,sizeof(lds));

        ll n;scanf("%lld",&n);

        for(i=0;i<n;i++)
        {
            scanf("%lld",&a[i]);
            lis[i]=1;
            lds[i]=1;

        }


        for(i=n-1;i>=0;i--) ///ending
        {
            for(j=i+1;j<n;j++)
            {
                ///ending at a[i] how many numbers are decreasing from it from backward
                if(a[j]<a[i])
                {
                    lds[i]=max(lds[i],lds[j]+1);
                }

                 ///ending at a[i] how many numbers are increasing from it from backward
                if(a[j]>a[i])
                {
                    lis[i]=max(lis[i],lis[j]+1);

                }
            }
        }

        ll ans=0;


        for(i=0;i<n;i++)
        {
            ///possible ending of lis at i
            ///starting of lds at i reversely ending of reverse lis

            ans=max(ans,lis[i]+lds[i]-1);
        }

        printf("%lld\n",ans);


    }

    return 0;

}

/*

100
3
1 2 3
6
10 3 2 12 4 1
*/


