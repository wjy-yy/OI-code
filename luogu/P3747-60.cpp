#include<cstdio>
#include<cstring>
#include<set>
#include<algorithm>
#define ll long long
#define lowbit(x) (x&(-x))
using std::set;
int gugugu;
int qpow(int x,int y,int p)
{
    int ans=1,gugu=0;
    while(y)
    {
        if(y&1)
        {
            if((ll)ans*x>=p||gugu)
                gugugu=1;
            ans=(ll)ans*x%p;
        }
        if((ll)x*x>=p)
            gugu=1;
        x=(ll)x*x%p;
        y>>=1;
    }
    return ans;
}
int phi[100],n,c;
int Phi(int x)
{
    int ans=x;
    for(int i=2;i*i<=x;++i)
    {
        if(x%i==0)
        {
            ans=ans/i*(i-1);
            while(x%i==0)
                x/=i;
        }
    }
    if(x>1)
        ans=ans/x*(x-1);
    return ans;
}
int gcd(int x,int y)
{
    while(y)
    {
        int t=x%y;
        x=y;
        y=t;
    }
    return x;
}
int calc(int x,int t)//t 层迭代
{
    int tmp=x;
    for(int i=t;i>=0;--i)
    {
        gugugu=0;
        tmp=qpow(c,tmp,phi[i]);
        if(i>0&&gugugu&&gcd(c,phi[i-1])!=1)
            tmp=tmp+phi[i];
    }
    return tmp;
}
ll b[50050];
void add(int p,int x)
{
    while(p<=n)
    {
        b[p]+=x;
        p+=lowbit(p);
    }
}
ll ask(int p)
{
    ll ans=0;
    while(p)
    {
        ans+=b[p];
        p-=lowbit(p);
    }
    return ans;
}
int a[50050],cnt[50050];
set<int> s;
int kkk[100][50050];
int main()
{
    memset(cnt,-1,sizeof(cnt));
    int m,p,op,l,r;
    scanf("%d%d%d%d",&n,&m,&p,&c);
    int tot=0;
    phi[0]=p;
    while(phi[tot]>1)
    {
        phi[tot+1]=Phi(phi[tot]);
        ++tot;
    }
    for(int i=1;i<=n;++i)
    {
        scanf("%d",&a[i]);
        for(int j=0;j<=tot;++j)
            kkk[j][i]=calc(a[i],j);
        add(i,a[i]);
        s.insert(i);
    }
    s.insert(n+1);
    while(m--)
    {
        scanf("%d%d%d",&op,&l,&r);
        if(op==0)
        {
            set<int>::iterator it=std::lower_bound(s.begin(),s.end(),l);
            while(it!=s.end()&&(*it)<=r)
            {
                int u=*it;
                if(cnt[u]==-1)
                    add(u,kkk[cnt[u]+1][u]-a[u]);
                    
                else
                    add(u,kkk[cnt[u]+1][u]-kkk[cnt[u]][u]);
                ++cnt[u];
                ++it;
                if(cnt[u]>=tot)
                    s.erase(u);
            }
        }
        else
            printf("%lld\n",(ask(r)-ask(l-1))%p);
    }
    return 0;
}