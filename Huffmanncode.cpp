#include<bits/stdc++.h>
using namespace std;
int n,sum=0;
struct Tnode{
Tnode *l; int freq; char data; Tnode *r;
};
//***************
struct List{
Tnode *root; List *next;
};
List *start=NULL,*End=NULL, *m, *t1, *t2;
//**************
void getnode()
{
m=new List; m->root=new Tnode;
cout<<"\nEnter the character and frequency:";
cin>>m->root->data>>m->root->freq;
m->root->l=NULL; m->root->r=NULL; m->next=NULL;
}
//****************
void insertfirst()
{
m->next=start; start=m;
}
//**************
void insertlast(){
End->next=m; End=m;
}
//**************
void insertatpos(){
t1=start;
while(t1->root->freq < m->root->freq){
t2=t1; t1=t1->next;
}
m->next=t1;
t2->next=m;
}//*******************
void insert()
{
if(start==NULL){ start=m; End=m; }
else if(m->root->freq <= start->root->freq) insertfirst();
else if(m->root->freq >= End->root->freq) insertlast();
else insertatpos();
}
//*******************
void traverse(){
t1=start;
cout<<"\n************\nList:\n";
while(t1!=NULL){
cout<<t1->root->freq<<" "<<t1->root->data<<endl;
t1=t1->next;
}
cout<<"\n*************\n";
}
//***************
Tnode* Least(Tnode *temp)
{
if(start==End)
{
Tnode *temp1=temp;
start=NULL;
End=NULL;
return temp1;
}
else
{
Tnode* temp1=temp;
start=start->next;
return temp1;
}
}
//**************
void traversecode(Tnode *tmp,string code)
{
if(tmp->l==NULL && tmp->r==NULL)
{
cout<<"Huffman coding for "<<tmp->data<<" is "<<code<<endl;
return;
}
traversecode(tmp->l,code+"0");
traversecode(tmp->r,code+"1");
}
//***************
int main() {
// Write C++ code here
int n;
cout<<"Enter the no. of characters:";
cin>>n;
for(int i=0;i<n;i++){
getnode(); insert(); traverse();
}
for(int i=0;i<n-1;i++)
{
List *newm=new List;
newm->next=NULL;
newm->root=new Tnode;
newm->root->l=Least(start->root);
newm->root->r=Least(start->root);
newm->root->freq= newm->root->l->freq + newm->root->r->freq;
newm->root->data='$';
cout<<"\n Added data is: "<<newm->root->freq<<endl;
m=newm;
insert();
traverse();
}
cout<<"\nThe Huffman coding using Greedy algorithm is as follows:\n";
traversecode(start->root," ");
return 0;
}
