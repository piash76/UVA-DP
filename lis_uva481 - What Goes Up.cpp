///http://www.algorithmsandme.com/longest-increasing-subsequence-in-onlogn/
///https://codeforces.com/blog/entry/12274


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
ll a[N],b[N],f[N];

///a for array , b for saving new sequence, f for saving the present ith increasing sequence length


int main()
{


    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);


    ll t,i,j;

    ll x;
    i=0;

    while(cin>>x)
    {
        ///cin>>x;

        a[i++]=x;

    }


    ll lislen=0;

    ll n=i;

    for(i=0;i<n;i++)
    {
      /// ll idx=upper_bound(b,b+lislen,a[i])-b;
      ll idx=lower_bound(b,b+lislen,a[i])-b;
      ///lower bound for strictly increasing



        lislen=max(lislen,idx+1);

        b[idx]=a[i];

        f[i]=idx+1;


    }

    vector<ll> s;

    ll val=lislen;

    for(i=n-1;i>=0;i--)
    {
        if(f[i]==val)
        {
            s.push_back(a[i]);
            val--;
        }

    }

    reverse(s.begin(),s.end());

    ///cout<<"LIS "<<lislen<<endl;

    cout<<lislen<<"\n";
    cout<<"-\n";


    for(auto it:s) cout<<it<<"\n";




    return 0;

}

/*


-7
10
9
2
3
8
8
6


*/


