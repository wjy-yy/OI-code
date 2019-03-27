#include<cstdio>
#include<cstring>
int Min(int x,int y){return x<y?x:y;}
int t[5050],c[5050],f[5050];
int main()
{
    int n,s;
    scanf("%d%d",&n,&s);
    for(int i=1;i<=n;++i)
    {
        scanf("%d%d",&t[i],&c[i]);
        t[i]+=t[i-1];
        c[i]+=c[i-1];
    }
    for(int i=1;i<=n;++i)
    {
        f[i]=1e9;
        for(int j=0;j<i;++j)
            f[i]=Min(f[i],f[j]+(s+t[i]-t[j])*(c[n]-c[j]));
    }
    printf("%d\n",f[n]);
    return 0;
}