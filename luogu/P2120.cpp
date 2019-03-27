#include<cstdio>
#include<cstring>
#define ll long long
int read()
{
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9')
    {
        if(ch=='-')
            f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9')
    {
        x=x*10+ch-'0';
        ch=getchar();
    }
    return x*f;
}
int X[1000100],c[1000100];
//坐标，个数，花费
ll f[1000100],g[1000100],h[1000100];
ll x[1000100],y[1000100];
int q[1000100],l=0,r=0;
int main()
{
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
    int n;
    n=read();
    for(int i=1;i<=n;++i)
    {
        X[i]=read();
        g[i]=read();
        c[i]=read();
        h[i]=h[i-1]+g[i]*X[i];
        g[i]+=g[i-1];
    }
    q[++r]=0;
    for(int i=1;i<=n;++i)
    {
        ll k=X[i];
        while(r-l>=2&&y[q[l+2]]-y[q[l+1]]<k*(x[q[l+2]]-x[q[l+1]]))
            ++l;
        f[i]=y[q[l+1]]-h[i]+X[i]*g[i]-k*x[q[l+1]]+c[i];
        x[i]=g[i];
        y[i]=f[i]+h[i];
        while(r-l>=2&&(y[i]-y[q[r]])*(x[q[r]]-x[q[r-1]])<(y[q[r]]-y[q[r-1]])*(x[i]-x[q[r]]))
            --r;
        q[++r]=i;
    }
    printf("%lld\n",f[n]);
    return 0;
}