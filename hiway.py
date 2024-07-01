n,m=map(int,input().split())
s,t=map(int,input().split())
e=[[] for j in range(n+1)]
c=[[0 for i in range(n+1)] for j in range(n+1)]
d=[[0 for i in range(n+1)] for j in range(n+1)]
for _ in range(m):
    x,y,z=map(int,input().split())
    d[x-1][y-1]=z
    d[y-1][x-1]=z
    e[x-1]+=[y-1]
    e[y-1]+=[x-1]
    c[x-1][y-1]=c[y-1][x-1]=1
e[n]+=[s-1]
e[s-1]+=[n]
c[n][s-1]=2
dp=[0]*(n+1)
check=[1]*(n+1)
trace=[-1]*(n+1)
flow=[[0 for i in range(n+1)] for j in range(n+1)]
def find_path(s,t):
    global trace
    for i in range(n+1):
        check[i]=0
        dp[i]=float('inf')
    dp[n]=0
    check[n]=1
    queue=[n]
    while queue:
        u=queue.pop(0)
        check[u]=0
        for v in e[u]:
            if flow[u][v]>=c[u][v]:
                continue
            if flow[u][v]<0: w=-d[u][v]
            else: w=d[u][v]
            if dp[u]+w<dp[v]:
                    dp[v]=dp[u]+w
                    trace[v]=u
                    if not check[v]:
                        check[v]=1
                        queue+=[v]
    return dp[t]<float('inf')
maxflow=0
mincost=0
def max_flow(s,t):
    global maxflow,mincost,c,flow
    mi=float('inf')
    u=t
    while u!=s:
        k=trace[u]
        if flow[k][u]<0: x=-flow[k][u]
        else: x=c[k][u]-flow[k][u]
        mi=min(mi,x)
        u=k
    u=t
    while u!=s:
        k=trace[u]
        flow[k][u]+=mi
        flow[u][k]-=mi
        u=k
    maxflow+=mi
    mincost+=dp[t]
visit=[1]*(n+1)
path=[]
def show_path(u):
    global path
    visit[u]=0
    path+=[u+1]
    for v in e[u]:
        if flow[u][v]>0 and visit[v]:
            show_path(v)
            break
while find_path(n,t-1):
    max_flow(n,t-1)
if maxflow<2: print(-1);exit()
print(mincost)
show_path(s-1)
print(len(path),*path)
visit[t-1]=1
path=[]
show_path(s-1)
print(len(path),*path)