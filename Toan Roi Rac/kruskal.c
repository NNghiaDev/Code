#include <stdio.h>
#include <stdlib.h>
#define inf 100000000
int parent[10000];
struct node{
    int u;
    int v;
    int w;
};

int cmp(const void *a, const void *b) {
    struct node *nodeA=(struct node *)a;
    struct node *nodeB=(struct node *)b;
    return nodeA->w-nodeB->w;
}

int find_parent(int u){
    if (u==parent[u]) return u;
    parent[u]=find_parent(parent[u]);
    return parent[u];
}
int union_v(int a, int b){
    int u=find_parent(a);
    int v=find_parent(b);
    if (u==v) return 0;
    parent[u]=v;
    return 1;
}
int main(){
    int n,m,x,y,w;
    scanf("%d %d", &n, &m);
    struct node e[m];
    for(int i=0; i<n; i++) parent[i]=i;
    for(int i=0; i<m; i++){
        scanf("%d %d %d", &x, &y, &w);
        x--;
        y--;
        e[i].u=x;
        e[i].v=y;
        e[i].w=w;
    }
    qsort(e, m, sizeof(struct node), cmp);
    int ans=0;
    for(int i=0; i<m; i++){
        int v=e[i].v;
        int u=e[i].u;
        int w=e[i].w;
        if(union_v(u,v)){
        ans+=w;}
    }
    printf("%d",ans);
}
