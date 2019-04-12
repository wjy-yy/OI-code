#include<cstdio>
#include<cstring>
#define ll long long
int p;
ll n;
int Plus(int x,int y){return x+y>=p?x+y-p:x+y;}
int Mul(int x,int y){return 1ll*x*y%p;}
int pri[1000100],cnt=0;
bool is[5000100],used[2500];
int f[5000100],phi[5000100];
int g[2500],inv,inv6;
int calc2(ll x)
{
    return Mul(Mul(x%p,x%p+1),Mul(Mul(2,x%p)+1,inv6));
}
int calc(ll x)
{
    if(x<=5000000)
        return f[x];
    ll t=n/x;
    if(used[t])
        return g[t];
    used[t]=1;
    int ans=Mul(Mul(Mul(x%p,x%p),Mul(x%p+1,x%p+1)),inv);
    for(ll i=2;i<=x;++i)
    {
        ll nxt=x/(x/i);
        ans=Plus(ans,p-Mul(Plus(calc2(nxt),p-calc2(i-1)),calc(x/i)));
        i=nxt;
    }
    return g[t]=ans;
}
int qpow(int x,int y)
{
    int ans=1;
    while(y)
    {
        if(y&1)
            ans=Mul(ans,x);
        x=Mul(x,x);
        y>>=1;
    }
    return ans;
}
int main()
{
    scanf("%d%lld",&p,&n);
    is[0]=is[1]=1;
    f[1]=phi[1]=1;
    for(int i=2;i<=5000000;++i)
    {
        if(!is[i])
        {
            pri[++cnt]=i;
            phi[i]=i-1;
            f[i]=Mul(Mul(i,i),i-1);
        }
        for(int j=1;j<=cnt&&i*pri[j]<=5000000;++j)
        {
            is[i*pri[j]]=1;
            if(i%pri[j]==0)
            {
                phi[i*pri[j]]=Mul(phi[i],pri[j]);
                f[i*pri[j]]=Mul(Mul(i*pri[j],i*pri[j]),phi[i*pri[j]]);
                break;
            }
            else
            {
                phi[i*pri[j]]=Mul(phi[i],pri[j]-1);
                f[i*pri[j]]=Mul(Mul(i*pri[j],i*pri[j]),phi[i*pri[j]]);
            }
        }
        f[i]=Plus(f[i-1],f[i]);
    }
    int ans=0;
    inv=qpow(4,p-2),inv6=qpow(6,p-2);
    for(ll i=1;i<=n;++i)
    {
        ll nxt=n/(n/i);
        ans=Plus(ans,Mul(Plus(calc(nxt),p-calc(i-1)),Mul(Mul(n/i%p,n/i%p),Mul(n/i%p+1,n/i%p+1))));
        i=nxt;
    }
    printf("%d\n",Mul(ans,inv));
    return 0;
}