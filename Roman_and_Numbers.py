from collections import Counter
n,m=map(int,input().split())
n=list(map(int,str(n)))
dp=[[0 for i in range(m)] for j in range(1<<len(n))]
dp[0][0]=1
d=Counter(n)
k=len(n)
for mask in range(1<<(len(n))):
    for i in range(k):
        if mask==0 and n[i]==0: continue
        if not mask&(1<<i):
            for r in range(m):
                    dp[mask|(1<<i)][(r*10+n[i])%m]+=dp[mask][r]
x=dp[(1<<k)-1][0]
for i in d:
    for j in range(1,d[i]+1):
        x//=j
print(x)