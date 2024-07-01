n,m,k,s,t=map(int,input().split())
e=[[] for i in range(n+1)]
c=[[0 for i in range(n+1)] for j in range(n+1)]
d=[[0 for i in range(n+1)] for j in range(n+1)]
flow=[[0 for i in range(n+1)] for j in range(n+1)]
for _ in range(m):
    x,y,z=map(int,input().split())
    e[x-1]+=[y-1]
    e[y-1]+=[x-1]
    c[x-1][y-1]=c[y-1][x-1]=1
    d[x-1][y-1]=d[y-1][x-1]=z
c[n][s-1]=k
e[n]+=[s-1]
e[s-1]+=[n]
check=[False]*(n+1)
trace=[-1]*(n+1)
dp=[0]*(n+1)
def find_path(s,t):
    for i in range(n+1):
        check[i]=False
        dp[i]=float('inf')
    check[s]=True
    queue=[s]
    dp[s]=0
    while queue:
        u=queue.pop(0)
        check[u]=False
        for v in e[u]:
            if flow[u][v]>=c[u][v]: continue
            if flow[u][v]<0: w=-d[u][v]
            else: w=d[u][v]
            if dp[u]+w<dp[v]:
                dp[v]=dp[u]+w
                trace[v]=u
                if not check[v]:
                    check[v]=True
                    queue+=[v]
    return dp[t]<float('inf')
maxflow=0
mincost=0
def max_flow(s,t):
    global mincost,maxflow
    u=t
    mi=float('inf')
    while u!=s:
        kk=trace[u]
        if flow[kk][u]<0: x=-flow[kk][u]
        else: x=c[kk][u]-flow[kk][u]
        mi=min(mi,x)
        u=kk
    u=t
    while u!=s:
        kk=trace[u]
        flow[kk][u]+=mi
        flow[u][kk]-=mi
        u=kk
    maxflow+=mi
    mincost+=dp[t]
while find_path(n,t-1):
    max_flow(n,t-1)
if maxflow<k: print(-1)
else:
    visit=[[True for i in range(n+1)] for j in range(n+1)]
    path=[]
    def show_path(u):
        global path
        for v in e[u]:
            if visit[u][v] and flow[u][v]>0:
                visit[u][v]=False
                path+=[v+1]
                show_path(v)
                break
    print(mincost)
    for _ in range(k):
        path=[]
        visit[n][s-1]=True
        show_path(n)
        print(len(path),*path)