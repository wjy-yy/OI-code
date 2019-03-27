#include<cstdio>
#include<cstring>
#define ll long long
ll f[50050],g[50050];
ll x[50050],y[50050];//优化常数
int q[50050],l=0,r=0;
int main()
{
    int n;
    ll L;
    scanf("%d%lld",&n,&L);
    ++L;
    for(int i=1;i<=n;++i)
    {
        scanf("%lld",&g[i]);
        g[i]+=g[i-1]+1;
    }
    x[0]=0,y[0]=0;
    q[++r]=0;
    for(int i=1;i<=n;++i)
    {
        ll k=2*g[i];
        while(r-l>=2&&y[q[l+2]]-y[q[l+1]]<k*(x[q[l+2]]-x[q[l+1]]))
            ++l;
        int j=q[l+1];
        f[i]=f[j]+g[i]*g[i]+g[j]*g[j]+L*L-2*g[i]*g[j]-2*L*g[i]+2*L*g[j];
        x[i]=g[i];
        y[i]=f[i]+g[i]*g[i]+2*L*g[i];
        while(r-l>=2&&x[q[r]]*y[i]-x[q[r]]*y[q[r]]-x[q[r-1]]*y[i]+x[q[r-1]]*y[q[r]]<
                    x[i]*y[q[r]]-x[i]*y[q[r-1]]-x[q[r]]*y[q[r]]+x[q[r]]*y[q[r-1]])
            --r;
        q[++r]=i;
    }
    printf("%lld\n",f[n]);
    return 0;
}