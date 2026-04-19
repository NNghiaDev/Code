#include <stdio.h>
#include <iostream>

using namespace std;

struct node{
    int cophieu;
    string cccd;
    string hoten;
    string mck;
    struct node *next;
    struct node *pre;
};
typedef struct node node;
typedef node* list;
void add(list &l,node *p){
    if(!l){
        l=p;
        return;
    }
    node *q=l;
    while(q->next!=NULL){
        q=q->next;
    }
    q->next=p;
    p->pre=q;
}
void find_mck(list l, string mack){
    node *p=l;
    while(p!=NULL){
        if(p->mck==mack){
            cout<<p->cccd<<'\n';
            cout<<p->hoten<<'\n';
            cout<<p->cophieu<<'\n';
        }
        p=p->next;
    }
}
void find_node_max(list l){
    if(!l) return;
    node *q=l;
    node *p=l;
    p=p->next;
    while(p!=NULL){
        if(p->cophieu>q->cophieu){
            q=p;
        }
        p=p->next;
    }
    cout<<q->cccd<<'\n';
    cout<<q->hoten<<'\n';
    cout<<q->cophieu<<'\n';
}
void del_cccd_x(list &l, string cccd){
    node *p=l;
    while(p!=NULL){
        if(p->cccd==cccd){
            if(p==l) l=p->next;
            if(p->next!=NULL) p->next->pre=p->pre;
            if(p->pre!=NULL) p->pre->next=p->next;
            cout<<"Da xoa nguoi co cccd la x"<<'\n';
            delete(p);
            return;
        }
        else{
            p=p->next;
        }
    }
    cout<<"Khong co nguoi nao co cccd la x"<<'\n';
}
int main(){
    int n;
    cin>>n;
    list l=NULL
    for(int i=0; i<n; i++){
        node *p=new node;
        cout<<"Nhap thong tin nguoi thu "<<i+1<<'\n';
        cout<<"Nhap ho ten ";
        cin>>p->hoten;
        cout<<"Nhap cccd";
        cin>>p->cccd;
        cout<<"Nhap so co phieu";
        cin>>p->cophieu;
        cout<<"Nhap ma chung khoan";
        cin>>p->mck;
        add(l,p);
    }
    cout<<"Nhap ma chung khoan";
    string x;
    cin>>x;
    find_mck(l,x);
    find_node_max(l);
    string cccd;
    cout<<"Nhap cccd";
    cin>>cccd;
    del_cccd_x(l,cccd);
}
