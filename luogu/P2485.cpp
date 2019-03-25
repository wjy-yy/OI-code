#include<cstdio>
#include<map>
#include<cmath>
#define ll long long
using std::map;
ll p;
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
ll exgcd(ll a,ll b,ll &x,ll &y)
{
    if(!b)
    {
        x=1,y=0;
        return a;
    }
    ll g=exgcd(b,a%b,y,x);
    y-=a/b*x;
    return g;
}
int main()
{
    //freopen("data.in","r",stdin);
    //freopen("bf.out","w",stdout);
    int T,ty;
    ll a,b;
    scanf("%d%d",&T,&ty);
    while(T--)
    {
        scanf("%lld%lld%lld",&a,&b,&p);
        if(ty==1)
            printf("%lld\n",qpow(a,b));
        else if(ty==2)
        {
            ll x,y;
            ll g=exgcd(a,p,x,y);
            if(b%g)
            {
                puts("Orz, I cannot find x!");
                continue;
            }
            x=(x*b/g)%p;
            printf("%lld\n",(x%p+p)%p);
        }
        else
        {
            if(a%p==0)
            {
                puts("Orz, I cannot find x!");
                continue;
            }
            map<int,int> f;
            ll t=ceil(sqrt(p));
            for(int i=1;i<=t;++i)
            {
                ll x=qpow(a,i);
                f[x*b%p]=i;//尽可能大
            }
            int flag=0;
            for(int k=t;k<=p+t;k+=t)
            {
                ll x=qpow(a,k);
                if(f.find(x)!=f.end())
                {
                    printf("%d\n",k-f[x]);
                    flag=1;
                    break;
                }
            }
            if(!flag)
                puts("Orz, I cannot find x!");
        }
    }
    return 0;
}
