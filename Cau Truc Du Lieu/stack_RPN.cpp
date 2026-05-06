#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <string.h>
using namespace std;
typedef char elt;
typedef struct node *stack;
struct node{
    elt data;
    node *next;

};
void init(stack &s){
    s=NULL;
}
bool empty(stack s){
    return (s==NULL);

}
void show(stack s){
    node *p=s;
    if(empty(s))return;
    while(p!=NULL){
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<'\n';
}
void push(stack &s,elt x){
    node *p=new node;
    if(p==NULL) return;
    p->data=x;
    p->next=s;
    s=p;
}

void pop(stack &s){
    node *p=s;
    if(empty(s)) return;
    s=s->next;
    delete p;
}
elt top(stack s){
    if(empty(s)) return '-1';
    return s->data;
}
int uutien(char s){
    if(s=='+' || s=='-') return 1;
    if(s=='*'|| s=='/') return 2;
    return 0;
}
int not_number(char s){
    if(s=='+'||s=='-'||s=='*'||s=='/'||s==')'||s=='(') return 1;
    return 0;
}
void hauto(char a[], char b[]){
    int n=strlen(a);
    stack s;
    elt x;
    init(s);
    int k=0;
    for(int i=0; i<n; i++){
        if(not_number(a[i])){
            if(a[i]=='('){
                push(s,a[i]);
            }
            else if(a[i]==')'){
                while(!empty(s) && top(s)!='('){
                    b[k]=top(s);
                    pop(s);
                    k++;
                }
                pop(s);
            }
            else{
                while(!empty(s) && uutien(top(s))>=uutien(a[i])){
                    b[k]=top(s);
                    pop(s);
                    k++;
                }
                push(s,a[i]);
            }
        }
        else{
            b[k]=a[i];
            k++;
        }
    }
    while(!empty(s)){
        b[k++]=top(s);
        pop(s);
    }
    b[k]='\0';
}
int main(){
    char a[30]="(2+3)*(4-5)",b[30];
    hauto(a,b);
    int n=strlen(b);
    for(int i=0; i<n; i++) cout<<b[i];

}
