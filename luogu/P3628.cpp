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
ll sum[1000100],f[1000100],x[1000100],y[1000100];
int q[1000100],l=0,r=0;
int main()
{
    ll a,b,c;
    int n;
    n=read();
    a=read();
    b=read();
    c=read();
    for(int i=1;i<=n;++i)
    {
        sum[i]=read();
        sum[i]+=sum[i-1];
    }
    q[++r]=0;
    for(int i=1;i<=n;++i)
    {
        ll k=2*a*sum[i];
        while(r-l>=2&&y[q[l+2]]-y[q[l+1]]>k*(x[q[l+2]]-x[q[l+1]]))
            ++l;
        f[i]=y[q[l+1]]-k*x[q[l+1]]+a*sum[i]*sum[i]+b*sum[i]+c;
        x[i]=sum[i];
        y[i]=f[i]+a*sum[i]*sum[i]-b*sum[i];
        while(r-l>=2&&(y[i]-y[q[r]])*(x[q[r]]-x[q[r-1]])>(y[q[r]]-y[q[r-1]])*(x[i]-x[q[r]]))
            --r;
        q[++r]=i;
    }
    printf("%lld\n",f[n]);
    return 0;
}