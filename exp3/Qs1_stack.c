#include<stdio.h>
#include<stdlib.h>
#define S 10
int s[S],t=-1;
void push(int v){
if(t==S-1)printf("\nFull");
else s[++t]=v;
}
void pop(){
if(t==-1)printf("\nEmpty");
else printf("\nPopped:%d",s[t--]);
}
void disp(){
if(t==-1)printf("\nEmpty");
else{for(int i=t;i>=0;i--)printf("%d ",s[i]);}
}
int main(){
int c,v;
while(1){
printf("\n1.Push 2.Pop 3.Disp 4.Exit:");
scanf("%d",&c);
if(c==1){printf("Val:");scanf("%d",&v);push(v);}
else if(c==2)pop();
else if(c==3)disp();
else if(c==4)exit(0);
}
return 0;
}