#include<cstdio>
#include<cstring>
#define ll long long
const int mxm=1048576;
int pri[1<<19],cnt=0,n;
ll phi[1145141],mu[1145141];
bool is[1145141];
ll f[1145141],g[1145141];
bool used[2000];
ll calc(int x)
{
    if(x<=mxm)
        return phi[x];
    int t=n/x;
    if(used[t])
        return g[t];
    used[t]=1;
    ll ans=(ll)(x+1)*x/2;
    for(int i=2;i<=x;++i)
    {
        int nxt=x/(x/i);
        ans-=calc(x/i)*(nxt-i+1);
        i=nxt;
        if(i==2147483647)
            break;
    }
    return g[t]=ans;
}
ll calc1(int x)
{
    if(x<=mxm)
        return mu[x];
    int t=n/x;
    if(used[t])
        return g[t];
    used[t]=1;
    ll ans=1;
    for(int i=2;i<=x;++i)
    {
        int nxt=x/(x/i);
        ans-=calc1(x/i)*(nxt-i+1);
        i=nxt;
    }
    return g[t]=ans;
}
int main()
{
    is[0]=is[1]=1;
    phi[1]=1;
    mu[1]=1;
    for(int i=2;i<=mxm;++i)
    {
        if(!is[i])
        {
            pri[++cnt]=i;
            mu[i]=-1;
            phi[i]=i-1;
        }
        for(int j=1;j<=cnt&&i*pri[j]<=mxm;++j)
        {
            is[i*pri[j]]=1;
            if(i%pri[j]==0)
            {
                mu[i*pri[j]]=0;
                phi[i*pri[j]]=pri[j]*phi[i];
                break;
            }
            else
            {
                mu[i*pri[j]]=-mu[i];
                phi[i*pri[j]]=(pri[j]-1)*phi[i];
            }
        }
        mu[i]+=mu[i-1];
        phi[i]+=phi[i-1];
    }
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        memset(used,0,sizeof(used));
        printf("%lld ",calc(n));
        memset(used,0,sizeof(used));
        printf("%lld\n",calc1(n));
    }
    return 0;
}
