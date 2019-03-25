#include<cstdio>
#include<cstring>
#include<vector>
#define ll long long
#define p 1000000007
using std::vector;
vector<int> v[100100];
ll qpow(ll x,ll y)
{
    ll ans=1;
    while(y)
    {
        if(y&1)
            ans=ans*x%p;
        x=x*x%p;
        y>>=1;
    }
    return ans;
}
bool is[100100];
int pri[100100],mu[100100],cnt=0;
ll f[100100];
int n;
int calc(int x,int y)//1~n 中 gcd(x,i)=y 的数的个数
{
    int g=x/y,ans=0;
    for(int i=0;i<v[g].size();++i)
        ans+=mu[v[g][i]]*(n/v[g][i]/y);
    return ans;
}
int main()
{
    scanf("%d",&n);
    f[1]=1;
    mu[1]=1;
    for(int i=2;i<=n;++i)
    {
        if(!is[i])
        {
            pri[++cnt]=i;
            mu[i]=-1;
        }
        for(int j=1;j<=cnt&&i*pri[j]<=n;++j)
        {
            is[i*pri[j]]=1;
            if(i%pri[j])
                mu[i*pri[j]]=-mu[i];
            else
            {
                mu[i*pri[j]]=0;
                break;
            }
        }
    }
    for(int i=1;i<=n;++i)
        for(int j=i;j<=n;j+=i)
            v[j].push_back(i);
    ll ans=1,inv=qpow(n,p-2);
    for(int i=2;i<=n;++i)
    {
        for(int j=0;j<v[i].size()-1;++j)
            f[i]=(f[i]+calc(i,v[i][j])*f[v[i][j]]%p)%p;
        f[i]=(f[i]*inv+1)%p;
        ll g=n-calc(i,i);
        f[i]=f[i]*n%p*qpow(g,p-2)%p;
        ans=(ans+f[i])%p;
    }
    printf("%lld\n",ans*qpow(n,p-2)%p);
    return 0;
}

