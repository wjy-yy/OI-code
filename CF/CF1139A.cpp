#include<cstdio>
char s[66666];
int main()
{
    int n;
    long long ans=0;
    scanf("%d",&n);
    scanf("%s",s+1);
    for(int i=1;i<=n;++i)
        if(!(s[i]&1))
            ans+=i;
    printf("%I64d\n",ans);
    return 0;
}
