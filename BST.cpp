#include<iostream>
#include<queue>
using namespace std;
struct node{
	int data;
    node *l,*r;

	node(int data){

        this->data=data;
        l=NULL;
        r=NULL;
	}
};
node *root;
static int i=0;
node* insert(node *p,int x){
	node *q=p;
	if(p==NULL){
		node *new1=new node(x);
		new1->data=x;
		new1->l=NULL;
		new1->r=NULL;
		p=new1;
		//cout<<"\nADDED"<<x<<endl;
		return p;
	}
	else{
		if(q->data>=x)
			q->l=insert(q->l,x);
		else
			q->r=insert(q->r,x);
	}
    return q;
}

void inOrderDisplay(node *p){
	node *q=p;
	if(q==NULL)
        return ;
	else{
		inOrderDisplay(q->l);
		cout<<q->data<<" ";
		inOrderDisplay(q->r);
	}

}
void preOrderDisplay(node *p){
	node *q=p;
	if(q==NULL)
        return ;
	else{
        cout<<q->data<<" ";
		preOrderDisplay(q->l);
		preOrderDisplay(q->r);

	}

}
void postOrderDisplay(node *p){
	node *q=p;
	if(q==NULL)
        return ;
	else{

		postOrderDisplay(q->l);
		postOrderDisplay(q->r);
		cout<<q->data<<" ";
	}

}

int search(node *p,int x)
{
	node *q=p;
	if(q==NULL)
		return -1;
	else
	{
		if(q->data==x)
			return 1;
		else
			if(q->data>x)
				search(q->l,x);
			else
				search(q->r,x);
	}

}

void mirrorImageConversion(node *p){

    node *q=p;
    if(q==NULL)
        return;
    else{
        mirrorImageConversion(q->l);
        mirrorImageConversion(q->r);
        node* temp;
        temp=q->l;
        q->l=q->r;
        q->r=temp;
    }

}
void levelOrderDisplay(node *p){

    if(p==NULL)
        return;
    else{
        queue<node*> q;
        q.push(p);
        while(!q.empty()){
            int s=q.size();
            while(s>0){
                node *t=q.front();
                cout<<t->data<<" ";
                q.pop();
                if(t->l!=NULL){
                    q.push(t->l);
                }
                if(t->r!=NULL){
                    q.push(t->r);
                }
                s--;
            }
        }
        cout<<endl;
    }


}

int main()
{
	root=NULL;
	node *w;
	root=insert(root,6);
	root=insert(root,4);
	root=insert(root,2);
	root=insert(root,15);
	root=insert(root,75);
	root=insert(root,55);
	root=insert(root,25);
	root=insert(root,175);
	root=insert(root,50);
	root=insert(root,52);
	root=insert(root,170);
	//root=insert(root,54);
	root=insert(root,5);
    cout<<"\nINORDER\n";
	inOrderDisplay(root);
	cout<<"\nPREORDER\n";
	preOrderDisplay(root);
	cout<<"\nPOSTORDER\n";
	postOrderDisplay(root);
	//MIRRORIMAGE CONVERSION
	//mirrorImageConversion(root);
	cout<<"\nLEVEL ORDER TRAVERSAL\n";
	levelOrderDisplay(root);

    return 0;
}
