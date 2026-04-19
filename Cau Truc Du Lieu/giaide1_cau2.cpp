#include <stdio.h>
typedef float ele;
struct node{
    string hoten;
    ele diem;
    string msv;
    struct node * next;
};
typedef struct node node;
typedef node * list;
void add_sinhvien(list &l, string hoten, string msv, ele diem){
    node *p=new node;
    p->next=NULL;
    p->hoten=hoten;
    p->msv=msv;
    p->diem=diem;
    if(!l){l=p; return;}
    node *q=l;
    while(q->next!=NULL){
        q=q->next;
    }
    q->next=p;
}
node *find_max_node(list l){
    if(l!=NULL){
        node *ans=l;
        node *q=l;
        q=q->next;
        while(q!=NULL){
            if(ans->diem<q->diem){
                ans=q;
            }
            q=q->next;
        }
        return ans;
    }
}
node *find_by_msv(list l,string msv){
    if(l!=NULL){
        node *q=l;
        while(q!=NULL){
            if(q->msv==msv){
                return q;
            }
            q=q->next;
        }
    }
    return NULL;
}
void del_by_msv(list &l, string msv){
    node *p=find_by_msv(l,msv);
    if(p==NULL){
        printf("Khong co");
        return;
    }
    if(p==l){
        l=l->next;
        delete p;
        return;
    }
    node *q=l;
    while(q->next!=p) q=q->next;
    q->next=p->next;
    delete p;
}
void sort(list l){
    node *q=l;
    while(q!=NULL){
        node *p=find_max_node(q);
        string thoten=q->hoten;
        string tmsv=q->msv;
        ele tdiem=q->diem;
        q->hoten=p->hoten;
        q->diem=p->diem;
        q->msv=p->msv;
        p->hoten=thoten;
        p->msv=tmsv;
        p->diem=tdiem;
        q=q->next;
    }
}
int main(){

}
