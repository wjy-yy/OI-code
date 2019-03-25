#include<cstdio>
long long ans=0;
int a[200100];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
        scanf("%d",&a[i]);
    int t=a[n];
    for(int i=n;i>=1;--i)
    {
        t=t<a[i]?t:a[i];
        ans+=t;
        --t;
        if(t<=0)
            break;
    }
    printf("%I64d\n",ans);
    return 0;
}
