import math
T=int(input())
while T>0:
    n=int(input())
    up=int(math.sqrt(n))
    if up*up==n:
        print("infty")
        T-=1
        continue
    if n%4!=0:
        print("0 0")
    else:
        n/=4
        up=int(math.sqrt(n))
        cnt=0
        ans=0
        for i in range (1,up+1):
            if n%i==0 and n/i+i>up:
                cnt+=1
                ans+=n*(n/i+i)
        print(cnt,int(ans%1000000007))
    T-=1