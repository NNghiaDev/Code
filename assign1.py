t=int(input())
for _ in range(t):
    n=int(input())
    a=[]
    for __ in range(n):
        a+=[list(map(int,input().split()))]
    dp=[[0 for i in range(n+1)] for j in range(1<<n)]
    dp[0][0]=1
    for mask in range(1<<n):
        for i in range(1,n+1):
            for j in range(n):
                if a[j][i-1] and mask&(1<<j):
                    dp[mask][i]+=dp[mask&(~(1<<j))][i-1]
    print(dp[(1<<n)-1][n])