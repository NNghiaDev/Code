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
    if(empty(s)) return ' ';
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
typedef float eltf;
struct nodef{
    eltf data;
    nodef *next;
};
typedef nodef* stackf;

void init(stackf &s){
    s=NULL;
}

bool empty(stackf s){
    return s==NULL;
}

void push(stackf &s, eltf x){
    nodef *p=new nodef;
    p->data=x;
    p->next=s;
    s=p;
}
void pop(stackf &s){
    if(empty(s)) return;
    nodef *p=s;
    s=s->next;
    delete p;
}
eltf top(stackf s){
    if(empty(s)) return 0;
    return s->data;
}
float cal(float a, float b, char op){
    switch(op){
        case '+': return b+a;
        case '-': return b-a;
        case '*': return b*a;
        case '/': return b/a;
    }
}
float solve(char b[],int n){
    stackf s;
    init(s);
    for(int i=0; i<n; i++){
        if(!not_number(b[i])) push(s,b[i]-'0');
        else{
            float a=top(s);
            pop(s);
            float b1=top(s);
            pop(s);
            push(s,cal(a,b1,b[i]));
        }
    }
    return top(s);
}
int main(){
    char a[30]="(2*5+3*4-7)*2",b[30];
    hauto(a,b);
    int n=strlen(b);
    for(int i=0; i<n; i++) cout<<b[i];
    cout<<endl;
    cout<<solve(b,n);
}
