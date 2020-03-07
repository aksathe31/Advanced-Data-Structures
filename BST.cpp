#include<iostream>
#include<string.h>
using namespace std;
class node
{
public:
	char data[15];
	char meaning[100];
	node* left;
	node* right;
	node()
	{
		right=left=NULL;
	}
};
node* Root=NULL;
class bst
{
public:
	node* create(char data[]);
	void insert(node*,char data[]);
	void display(node*);
	void search(node* ,char data[] );
	void remove(node*);
};

void bst::search(node* root,char key[])
{
	if(root==NULL)
	{
		cout<<"\n\t"<<key<<" is not present in BST!";
		return;
	}
	if(!strcmp(key,root->data))
	{
		cout<<"\n\t"<<root->data<<" is present in the BST";
		cout<<"\n\tMEANING: "<<root->meaning;
	}
	else
	{
		if(strcmp(key,root->data)<0)
		search(root->left,key);
		else
		search(root->right,key);
	}
}

node* bst::create(char x[])
{
	node* ptr=new node;	
	strcpy(ptr->data,x);
	cout<<"\n\tEnter meaning of "<<ptr->data<<": ";
	cin.getline(ptr->meaning,100,'&');
	return ptr;
}

void bst::insert(node* root,char x[])
{

	if(Root==NULL)
	{		
		Root=create(x);	
	}
	else
	{
		
		if(strcmp(x,root->data)<0)
		{
			if(root->left==NULL)
			{
				root->left=create(x);
			}
			else
			{
				root=root->left;
				insert(root,x);
			}		
		}
		else
		{
			if(root->right==NULL)
			{	
				root->right=create(x);
			}
			else
			{
				root=root->right;
				insert(root,x);
			}
		}
	}
	
}

void bst::display(node* root)
{
	if(root==NULL)
	return;

	display(root->left);
	cout<<"\n\tWORD: "<<root->data<<"\n\tMEANING: "<<root->meaning;
	display(root->right);
}


int main()
{int ch;
char x[15];
char ans;
bst tree;
cout<<"\n\n\t###MENU###\n\tPress\n\t1.INSERT\n\t2.DISPLAY\n\t3.SEARCH\n\t4.REMOVE\n\t5.EXIT\n\tCHOICE?: ";
	cin>>ch;
	if(ch==5)
	return 0;
do{	
	switch(ch)
	{case 1: cout<<"\n\tEnter node data: ";
		cin>>x;
		tree.insert(Root,x);
		break;
	case 2: tree.display(Root);
		break;
	case 3: cout<<"\n\tEnter the key to be searched: ";
		char key[15];		
		cin>>key; 
		tree.search(Root,key);
		break;
	default: cout<<"\n\tEnter correct choice!";
		break;
	}
cout<<"\n\tPress\n\t1.INSERT\n\t2.DISPLAY\n\t3.SEARCH\n\t4.REMOVE\n\t5.EXIT\n\tCHOICE?: ";
	cin>>ch;
}while(ch!=5);

return 0;
}
















