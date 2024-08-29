#include<bits/stdc++.h>
using namespace std;

struct TNode{
	TNode* l; 
	TNode* r; 
	int length;
};

struct List{
	TNode* root; 
	List* next;
};

List* start=NULL;
List* End=NULL;
List* m;
List* t1;
List* t2;

void getnode(){
	m=new List;
	m->root=new TNode;
	cout<<"\nEnter the data: ";  
	cin>>m->root->length;
	m->root->l=NULL;
	m->root->r=NULL;
	m->next=NULL;
}

void traverse(){
	t1=start;
	while(t1!=NULL){
    	cout<<t1->root->length<<" ";
    	t1=t1->next;
	}
}
void insertAtFirst(){
	m->next=start;
	start=m;
}

void insertAtLast(){
	End->next=m;
	End=m;
}

void insertAtPos(){
	t1=start;
	while(t1->root->length < m->root->length ){
    	t2=t1;  
		t1=t1->next;
	}
    m->next=t1;
    t2->next=m;
}

void insert(){
	if(start==NULL){  
		start=m; 
		End=m; 
	}
	else if(m->root->length <= start->root->length)  
		insertAtFirst();
	else if(m->root->length >= End->root->length)  
		insertAtLast();
	else  
		insertAtPos();
}


int main(){
	int n;
	cout<<"Number of Files: "; 
	cin>>n;
    for(int i=0;i<n;i++){
    	getnode();
    	insert();
    	traverse();
    }
	return 0;
}
