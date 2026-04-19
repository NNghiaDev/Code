#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

struct node{
    char s;
    struct node * next;

};
typedef struct node node;
typedef node * list;
bool empty(list l){
    return (l==NULL);
}
void push(list &l, char dau){
    node *p=new node;
    p->s=dau;
    p->next=l;
    l=p;

}
void pop(list &l){
    if(empty(l)) return ;
    l=l->next;

}
char top(list l){
    return l->s;
}
bool check(string s){
    list st=NULL;
    for(char c:s){
        if(c=='(' || c=='{' || c=='[') push(st,c);
        else{
            if(empty(st)) return 0;
            char t=top(st);
            if((c == ')' && t != '(') ||
               (c == '}' && t != '{') ||
               (c == ']' && t != '[')){
                return false;
            }
            pop(st);
        }
    }
    return empty(st);

}
int main(){
    string s;
    cin>>s;
    if(check(s)) cout<<"Yes"<<"\n";
    else cout<<"No"<<"\n";

}
