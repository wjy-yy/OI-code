#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
struct plot
{
    int a,b;
    friend bool operator <(plot A,plot B)
    {
        if(A.a!=B.a)
            return A.a<B.a;
        return A.b<B.b;
    }
}a[50050];
int q[50050],l=0,r=0;
ll f[50050],x[50050],y[50050],nxt[50050];
int main()
{
    freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
        scanf("%d%d",&a[i].a,&a[i].b);
    std::sort(a+1,a+1+n);
    for(int i=n;i>=1;)
    {
        int t=i-1;
        while(t&&a[t].b<=a[i].b)
            --t;
        nxt[t]=i;
        //printf("%d ",i);
        i=t;
    }
    q[++r]=0;
    x[0]=a[nxt[0]].b;
    for(int i=nxt[0];i;i=nxt[i])
    {
        ll k=-a[i].a;
        while(r-l>=2&&y[q[l+2]]-y[q[l+1]]<k*(x[q[l+2]]-x[q[l+1]]))
            ++l;
        f[i]=y[q[l+1]]-k*x[q[l+1]];
        x[i]=a[nxt[i]].b;
        y[i]=f[i];
        while(r-l>=2&&(y[i]-y[q[r]])*(x[q[r]]-x[q[r-1]])>(y[q[r]]-y[q[r-1]])*(x[i]-x[q[r]]))
            --r;
        q[++r]=i;
    }
    printf("%lld\n",f[n]);
    return 0;
}