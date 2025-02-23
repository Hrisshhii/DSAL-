#include<iostream>
using namespace std;
#define size 10

class stack{
    private:
    int top;
    int s[size];
    
    public:
    stack(){
        top=-1;
    }
    
    int isEmpty(){
        return top==-1;
    }
    
    int isFull(){
        return top==(size-1);
    }
    
    void push(int x){
        if(!isFull()){
            s[++top]=x;
        }
    }
    
    int pop(){
        if(!isEmpty()){
            int t=s[top];
            top--;
            return t;
        }
        return -1;
    }
    
    int peek(){
        if(!isEmpty()){
            return s[top];
        }
    }
};

class DFS{
    public:
    int visit[size];
    int g[size][size];
    int n;
    
    void create(){
        cout<<"ENTER NUMBER OF VERTICES: "<<endl;
        cin>>n;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<"Enter value 0 or 1 for a vertix:("<<i<<","<<j<<")";
                cin>>g[i][j];
            }
        }
        
        cout<<"\nAdjacency Matrix: "<<endl;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<g[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    
    void dfs(){
        stack s;
        for(int i=0;i<n;i++){
            visit[i]=0;
        }
        
        int v1;
        cout<<"Enter starting Node: "<<endl;
        cin>>v1;
        s.push(v1);
        
        cout << "DFS Traversal: ";
        
        while(!s.isEmpty()){
            int v=s.pop();
            if(visit[v]==0){
                cout<<v<<" ";
                visit[v]=1; 
            
                for(int i=n-1;i>=0;i--){
                    if(g[v][i]==1 && visit[i]==0){
                        s.push(i);
                    }
                }
            }
        }
        cout<<endl;
    }
};

int main(){
    DFS d;
    d.create();
    d.dfs();
    return 0;
}
