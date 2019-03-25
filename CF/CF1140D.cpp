#include<cstdio>
int main()
{
    long long ans=0;
    int n;
    scanf("%d",&n);
    for(int i=2;i<n;++i)
        ans+=i*(i+1);
    printf("%d\n",ans);
    return 0;
}