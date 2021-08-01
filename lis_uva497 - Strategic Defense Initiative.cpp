
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
int a[N],dp[N];


int main()
{

    int t,i,j,cas=0;
    scanf("%d",&t);
    getchar();

    char s[20];
    gets(s);

    while(t--)
    {

        int idx=0;
        while(gets(s) and strlen(s))
        {
            ///cout<<"S "<<s<<endl;
            a[idx++]=atoi(s);

        }

        ///cout<<"IDX "<<idx<<endl;

        int lis=0;

        for(i=0;i<idx;i++) dp[i]=1;

        for(i=1;i<idx;i++)
        {
            for(j=0;j<i;j++)
            {
                if(a[j]<a[i])
                {
                    dp[i]=max(dp[i],dp[j]+1);
                }
            }
        }

       /* cout<<"DP "<<endl;
        for(i=0;i<idx;i++) cout<<dp[i]<<" ";
        cout<<endl;*/

        vector<int> ans;
        int prev_lis_idx,prev_lis_val;

        for(i=0;i<idx;i++)
        {
            if(dp[i]>lis)
            {
                lis=dp[i];
                prev_lis_idx=i;

            }

        }

        ans.push_back(a[prev_lis_idx]);

        prev_lis_val=lis-1;

        for(i=prev_lis_idx-1;i>=0;i--)
        {
            if(dp[i]==prev_lis_val)
            {
                if(a[i]<a[prev_lis_idx])
                {
                    ans.push_back(a[i]);
                    prev_lis_idx=i;
                    prev_lis_val--;
                }
            }
        }

        reverse(ans.begin(),ans.end());


        if(cas) printf("\n");

        cas++;

        printf ("Max hits: %d\n", lis);

        for(i=0;i<ans.size();i++) printf("%d\n",ans[i]);


    }

    return 0;

}

/*

1

1
6
2
3
5

*/




