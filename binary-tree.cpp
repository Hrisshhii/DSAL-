#include<iostream>
#include<cstring>
using namespace std;

class node{
	public:
	node*right,*left;
	char key[100],mean[100];
	node()
	{
		right=NULL;
		left=NULL;
	}
};

class Tree
{
	public:
	node *root=NULL;
	node* create();
	void display(node*root);
	void insert(node*& root,node*temp);
	void update(node*root);
	void search(node* root, char k[]);
    void Ascending(node* root);
    void Descending(node* root);
};

node* Tree::create(){
	int ch;
	do{
		node*temp=new node;
		cout<<"ENTER THE KEYWORD: "<<endl;
		cin>>temp->key;
		cout<<"ENTER THE MEANING: "<<endl;
		cin>>temp->mean;
		temp->left=NULL;
		temp->right=NULL;
		insert(root,temp);
		cout<<"DO YOU WANT TO CONTINUE: 1/0"<<endl;
		cin>>ch;
	}while(ch!=0);
}

void Tree::insert(node*&root,node* temp){
	if(root==NULL)
	{
		root=temp;
	}
	else{
		if(strcmp(temp->key,root->key)<0){
			if(root->left==NULL)
				root->left=temp;
			else
				insert(root->left,temp);
		}
		else{
			if(root->right==NULL)
				root->right=temp;
			else
				insert(root->right,temp);
		}
	}
}

void Tree::display(node*root){
	if(root==NULL)
		return;
	else
	{
		cout<<"KEYWORD: "<<root->key<<endl;
		cout<<"MEANING: "<<root->mean<<endl;
		display(root->left);
		display(root->right);
	}
}

void Tree::update(node* root) {
    char k[100],meaning[100];
    cout<<"ENTER THE KEY TO BE UPDATED: "<<endl;
    cin>>k;

    while (root!=NULL){
        if (strcmp(root->key,k)==0){
            cout<<"ENTER THE NEW MEANING: "<<endl;
            cin>>meaning;
            strcpy(root->mean,meaning);
            cout<<"MEANING UPDATED SUCCESSFULLY!"<<endl;
            return;
        } else if (strcmp(root->key,k)>0){
            root=root->left;
        } else{
            root=root->right;
        }
	}
    cout<<"KEY DOES NOT EXIST!!!"<<endl;
}

void Tree::search(node* root,char k[])
{
	int comparisons = 0;
    while (root != NULL) {
        comparisons++;
        if (strcmp(root->key, k) == 0) {
            cout<<"KEY FOUND!"<<endl;
            cout<<"KEYWORD: "<<root->key<<endl;
            cout<<"MEANING: "<<root->mean<<endl;
            cout<<"TOTAL COMPARISONS: "<<comparisons<<endl;
            return;
        } else if (strcmp(root->key,k)>0){
            root=root->left;
        } else {
            root=root->right;
        }
    }
    cout<<"KEY NOT FOUND! TOTAL COMPARISONS: "<<comparisons<<endl;
}

void Tree::Ascending(node* root) {
    if (root==NULL)
        return;
    Ascending(root->left);
    cout<<"KEYWORD: "<<root->key<<" -> MEANING: "<<root->mean<<endl;
    Ascending(root->right);
}

void Tree::Descending(node* root) {
    if (root==NULL)
        return;
    Descending(root->right);
    cout<<"KEYWORD: "<<root->key<<" -> MEANING: "<<root->mean<<endl;
    Descending(root->left);
}

int main()
{
	Tree t;
	int choice;
	char key[100];
	do{
		cout<<"\n1.CREATE A BINARY TREE\n2.DISPLAY BINARY TREE\n3.UPDATE KEYWORD\n4.SEARCH\n5.DISPLAY IN ASCENDING ORDER\n6.DISPLAY IN DESCENDING ORDER\n7.EXIT"<<endl;
		cout<<"\nENTER YOUR CHOICE: "<<endl;
		cin>>choice;
		switch(choice){
			case 1:
				t.create();
				break;
			case 2:
				t.display(t.root);
				break;
			case 3:
				t.update(t.root);
				break;
			case 4:
				cout<<"ENTER THE KEY TO SEARCH: ";
                cin>>key;
                t.search(t.root,key);
                break;
			case 5:
				cout<<"DICTIONARY IN ASCENDING ORDER:\n";
				t.Ascending(t.root);
				break;
			case 6:
				cout<<"DICTIONARY IN DESCENDING ORDER:\n";
                t.Descending(t.root);
                break;
			case 7:
				cout<<"EXITING............:)"<<endl;
				break;
			default:
				cout<<"INVALID CHOICE!!!"<<endl;
				break;
		}
	}while(choice!=7);
	return 0;
}
