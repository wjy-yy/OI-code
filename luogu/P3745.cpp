#include<cstdio>
#include<cstring>
#define ll long long
ll read()
{
    ll x=0;
    char ch=getchar();
    while(ch<'0'||ch>'9')
        ch=getchar();
    while(ch>='0'&&ch<='9')
    {
        x=x*10+ch-'0';
        ch=getchar();
    }
    return x;
}
int sum[100100],n,m,mx=0,mn=1e9;
ll Sum[100100],A,B,C;//Sum
ll sumb[100100],Sumb[100100];
ll calc(int x)
{
    ll ans=((ll)sum[x]*x-Sum[x])*C;
    if(B<A)
        ans+=(Sumb[mx]-Sumb[x]-(m-sumb[x])*x)*B;
    else
    {
        ll pre=sumb[x]*x-Sumb[x],suc=Sumb[mx]-Sumb[x]-(m-sumb[x])*x;
        if(suc<pre)
            ans+=suc*A;
        else
            ans+=pre*A+(suc-pre)*B;
    }
    return ans;
}
int main()
{
    freopen("a.in","r",stdin);
    A=read();
    B=read();
    C=read();
    n=read();
    m=read();
    int u;
    for(int i=1;i<=n;++i)
    {
        u=read();
        ++sum[u];
        mx=mx>u?mx:u;
        mn=mn<u?mn:u;
    }
    for(int i=1;i<=m;++i)
    {
        u=read();
        ++sumb[u];
        mx=mx>u?mx:u;
        //mn=mn<u?mn:u;
    }
    for(int i=1;i<=mx;++i)
    {
        Sum[i]=Sum[i-1]+(ll)sum[i]*i;
        sum[i]+=sum[i-1];
        Sumb[i]=Sumb[i-1]+(ll)sumb[i]*i;
        sumb[i]+=sumb[i-1];
    }
    if(C==10000000000000000)
    {
        printf("%lld\n",calc(mn));
        return 0;
    }
    int l=1,r=mx,mid;
    while(l<r)
    {
        mid=(l+r)>>1;
        ll t1=calc(mid),t2=calc(mid+1);
        if(t1==t2)
        {
            l=mid;
            break;
        }
        if(t1<t2)
            r=mid;
        else
            l=mid+1;
    }
    printf("%lld\n",calc(l));
    return 0;
}