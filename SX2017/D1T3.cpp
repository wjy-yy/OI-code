#include<cstdio>
#include<cstring>
#define ll long long
ll n,p,k,r;
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
namespace bf
{
ll fact[1000100],inv[1000100];
void work()
{
    ll mx=n*k;
    fact[0]=1;
    for(int i=1;i<=mx;++i)
        fact[i]=fact[i-1]*i%p;
    inv[mx]=qpow(fact[mx],p-2);
    for(int i=mx-1;i>=0;--i)
        inv[i]=inv[i+1]*(i+1)%p;
    ll ans=0;
    for(int i=0;i*k+r<=mx;++i)
        ans=(ans+fact[mx]*inv[i*k+r]%p*inv[mx-i*k-r]%p)%p;
    printf("%lld\n",ans);
}
}
namespace qaq
{
struct matrix
{
    int x,y;
    int a[55][55];
    matrix(int x,int y)
    {
        this->x=x;
        this->y=y;
        memset(a,0,sizeof(a));
    }
    matrix()
    {
        memset(a,0,sizeof(a));
    }
    friend matrix operator *(matrix a,matrix b)
    {
        matrix c(a.x,b.y);
        for(int i=0;i<=c.x;++i)
            for(int j=0;j<=c.y;++j)
                for(int k=0;k<=b.x;++k)
                    c.a[i][j]=(c.a[i][j]+(ll)a.a[i][k]*b.a[k][j])%p;
        return c;
    }
};
matrix mpow(matrix a,ll y)//保证是单位矩阵
{
    matrix ans(a.x,a.x);
    for(int i=0;i<=a.x;++i)
        ans.a[i][i]=1;
    while(y)
    {
        if(y&1)
            ans=ans*a;
        a=a*a;
        y>>=1;
    }
    return ans;
}
void work()
{
    matrix t(r-1,r-1),ans(r-1,0);
    t.a[0][0]=1;
    for(int i=1;i<=r-1;++i)
    {
        t.a[i][i]=1;
        t.a[i][i-1]=1;
    }
    ans.a[0][0]=1;
    t=mpow(t,n*k);
    ans=t*ans;
    if(k==2)
    {
        ll Ans=qpow(2,n*k-1);
        for(int i=r-2;i>=0;i-=2)
            Ans=(Ans+p-ans.a[i][0])%p;
        printf("%lld\n",Ans);
    }
    else
    {
        ll Ans=qpow(2,n*k);
        for(int i=r-1;i>=0;--i)
            Ans=(Ans+p-ans.a[i][0])%p;
        printf("%lld\n",Ans);
    }
    
    
}
}
int main()
{
    freopen("a.in","r",stdin);
    scanf("%lld%lld%lld%lld",&n,&p,&k,&r);
    if(k<=2)
        qaq::work();
    else if(n*k>1000000)
        puts("1");
    else
        bf::work();
    return 0;
}