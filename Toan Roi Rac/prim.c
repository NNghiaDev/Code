#include <stdio.h>
#define inf 10000000
int n=7;
int matrix[7][7]={
        {inf,8,inf,5,inf,inf,inf },
        {8,inf,10,2,18,inf,inf },
        {5,10,inf,3,inf,inf,16},
        {inf,2,3,inf,12,14, 30},
        {inf,18,inf,12,inf,4,inf },
        {inf,inf,inf,14,4,inf,26 },
        {inf,inf,16,30,inf,26,inf }
};
void prim(int s){
    int cnt=0;
    int ans=0;
    int visited[n];
    for(int i=0; i<n; i++) visited[i]=0;
    visited[s-1]=1;
    while(cnt<n-1){
        int minw=inf;
        int x=-1;int y=-1;
        for(int u=0; u<n; u++){
            if(!visited[u])continue;
            for(int v=0; v<n; v++){
                if(!visited[v] && matrix[u][v]<minw && matrix[u][v]!=inf){
                    minw=matrix[u][v];
                    x=u; y=v;
                }
            }
        }
        if(x==-1 && y==-1) continue;
        cnt++;
        ans+=minw;
        visited[y]=1;
        printf("%d %d\n", x+1,y+1);
    }
    printf("%d",ans);
}
int main(){
    prim(1);
}
