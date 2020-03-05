#include<iostream>
using namespace std;
class node
{
public:
    char data;
    node* left,*right;
    node()
    {
        right=left=NULL;
    }
};
node *root;

class tree
{
public:
    node* Insert(node*);
    node* create();
    void display(node*);
};
char ans;
    node* tree::create()
    {
        node* temp=new node;
        cout<<"\n\t\tenter data:";
        cin>>temp->data;
        return temp;
    }

    node* tree::Insert(node* root)
    {
        cout<<"Do you want to enter "<<root->data<<" left child: ";
        cin>>ans;

            if(ans=='y'||ans=='Y')
            {
                root->left=create();
                Insert(root->left);
            }
        cout<<"Do you want to enter "<<root->data<<" right sibling: ";
        cin>>ans;

           if(ans=='y'||ans=='Y')
            {
                root->right=create();
                Insert(root->right);
            }

        return root;
    }

   void tree::display(node *ptr)
    {
        if(ptr==NULL)
        {
            return;
        }

        cout<<"\n\t"<<ptr->data;
        display(ptr->left);
        display(ptr->right);

    }
return;
}
int main()
{
    root=new node;
    cout<<"\n\tEnter root data: ";
    cin>>root->data;
    tree t;
    t.Insert(root);
    cout<<"\n "<<root->data<<endl;
    t.display(root->left);

    return 0;
}
