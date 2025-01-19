#include<iostream>
#include<string.h>
using namespace std;

struct node{
    char data;
    node *left;
    node *right;
};
class stack{
    public:
    node* data[50];
    int top;
    stack()
    {
        top=-1;
    }

    int is_empty(){
        return top==-1;
    }

    int push(node *p)
    {
        data[++top]=p;
    }

    node *pop()
    {
        return (data[top--]);
    }
};

class tree{
    char prefix[50];
    public:
    node *top;
    void create_tree(char prefix[]){
        char c;
        stack s;
        node *t1,*t2;
        int len=strlen(prefix);
        for (int i=len-1;i>=0;i--){
            top=new node;
            top->left=NULL;
            top->right=NULL;

            if(isalpha(prefix[i])){
                top->data=prefix[i];
                s.push(top);
            }
            else if(prefix[i]=='+'||prefix[i]=='-'||prefix[i]=='*'||prefix[i]=='/'){
                t2=s.pop();
                t1=s.pop();
                top->data=prefix[i];
                top->left=t2;
                top->right=t1;
                s.push(top);
            }
        }
        top=s.pop();
    }
    void display(node* top)
    {
        stack s1,s2;
        node *tr=top;
        s1.push(tr);
        while(!s1.is_empty()){
            tr=s1.pop();
            s2.push(tr);

            if(tr->left!=NULL){
                s1.push(tr->left);
            }
            if(tr->right!=NULL){
                s1.push(tr->right);
            }
        }

        while(!s2.is_empty()){
            top=s2.pop();
            cout<<top->data;
        }
        cout<<endl;
    }
    void deletion(node* t){
        if(t==NULL)
        {
            return;
        }
        deletion(t->left);
        deletion(t->right);
        cout<<"DELETING: "<<t->data<<endl;
        free(t);
    }
};



int main(){
    tree t;
    char expression[20];
    int choice;

    do
    {
        cout<<"1. Enter prefix expression"<<endl;
        cout<<"2. Display postfix Expression"<<endl;
        cout<<"3. Deletion"<<endl;
        cout<<"4. Exit"<<endl;
        cout<<"Enter your choice: \t";
        cin>>choice;

        switch(choice){
            case 1:
                cout<<"\nEnter the Expression: \n";
                cin>>expression;
                t.create_tree(expression);
                break;
            case 2:
                t.display(t.top);
                break;
            case 3:
                t.deletion(t.top);
                break;
            case 4:
                cout<<"EXITING .............:)";
                break;
            default:
                cout<<"Invalid Choice!"<<endl;
                break;
        }
    } while (choice!=4);
    return 0;
}