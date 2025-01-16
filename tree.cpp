#include<iostream>
#include<string>
using namespace std;

struct book
{
	string name;
	int count;
	
	struct book *sub[10];
}*root;

struct tree
{
	public:
	tree()
	{
		root=NULL;
	}
	
	void add_book()
	{
		root=new book;
		cout<<"ENTER THE NAME OF BOOK: "<<endl;
		cin>>root->name;
		cout<<"ENTER THE NUMBER OF CHAPTERS IN BOOK: "<<endl;
		cin>>root->count;
		for(int i=0;i<root->count;i++)
		{
			root->sub[i]=new book;
			cout<<"ENTER THE NAME OF CHAPTER: "<<endl;
			cin>>root->sub[i]->name;
			cout<<"ENTER THE NUMBER OF SECTIONS: "<<endl;
			cin>>root->sub[i]->count;
			for(int j=0;j<root->sub[i]->count;j++)
			{
				root->sub[i]->sub[j]=new book;
				cout<<"ENTER THE NAME OF SECTION: "<<endl;
				cin>>root->sub[i]->sub[j]->name;
				cout<<"ENTER THE NUMBER OF SUB-SECTIONS: "<<endl;
				cin>>root->sub[i]->sub[j]->count;
				for(int k=0;k<root->sub[i]->sub[j]->count;k++)
				{
					root->sub[i]->sub[j]->sub[k]=new book;
					cout<<"ENTER THE NAME OF SUB-SECTION: "<<endl;
					cin>>root->sub[i]->sub[j]->sub[k]->name;
				}
			}
		}
	}
	
	void display(book *r)
	{
		int i,j,k;
		if(r==NULL)
			cout<<"BOOK NOT CREATED YET!!!"<<endl;
		else
		{
			cout<<"\nNAME OF THE BOOK IS "<<r->name<<endl;
			cout<<"THIS BOOK HAS "<<r->count<<" NUMBER OF CHAPTERS"<<endl;
			for(i=0;i<r->count;i++)
			{
				cout<<"\nNAME OF CHAPTER IS "<<r->sub[i]->name<<endl;
				cout<<"IT HAS "<<r->sub[i]->count<<" SECTIONS"<<endl;
				for(j=0;j<r->sub[i]->count;j++)
				{
					cout<<"\nSECTION NAME: "<<r->sub[i]->sub[j]->name<<endl;
					cout<<"SECTION "<<r->sub[i]->sub[j]->name<<"HAS "<<r->sub[i]->sub[j]->count<<" SUB-SECTIONS"<<endl;
					for(k=0;k<r->sub[i]->sub[j]->count;k++)
					{
						cout<<"\nSUB-SECTION: "<<r->sub[i]->sub[j]->sub[k]->name<<endl;
					}
				}
			}
		}
	}
};

int main()
{
	tree t;
	int choice;
	do
	{
		cout<<"***************MENU***************"<<endl;
		cout<<"1.CREATE BOOK\n2.DISPLAY BOOK\n3.EXIT"<<endl;
		cout<<"ENTER YOUR CHOICE: "<<endl;
		cin>>choice;
		switch(choice)
		{
			case 1:
				t.add_book();
				break;
			case 2:
				t.display(root);
				break;
			case 3:
				cout<<"EXITING THE PROGRAM................:)"<<endl;
				break;
			default:
				cout<<"INVALID INPUT!!!"<<endl;
		}
	}while(choice!=3);
	return 0;
}
