#include<bits/stdc++.h>
using namespace std;
//21BBS0100
#define MAX 20
int adj[MAX][MAX];
int visited[MAX];
int n; 
void create_graph(){
    int i,max_edges,origin,destin;
    printf("Enter number of nodes : ");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        adj[i][i]=1;
    max_edges=n*(n-1);
    for(i=1;i<=max_edges;i++){
        printf("Enter edge %d( 0 0 to quit ) : ",i);
        scanf("%d %d",&origin,&destin);
        if((origin==0) && (destin==0))
            break;
        if( origin > n || destin > n || origin<=0 || destin<=0){
            printf("Invalid edge!\n");
            i--;
            }
        else{
            adj[origin][destin]=1;
            adj[destin][origin]=1;
            }
    }
}

void display(){
    int i,j;
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++)
            printf("%4d",adj[i][j]);
        printf("\n");
    }
}

void dfs(int v){
    int i,stack[MAX],top=-1,pop_v,j,t;
    int ch;
    top++;
    stack[top]=v;
    while (top>=0){
        pop_v=stack[top];
        top--; 
        if( visited[pop_v]==0){
        printf("%d ",pop_v);
        visited[pop_v]=1;
        }

        for(i=1;i<=n;i++)
        {
        if( adj[pop_v][i]==1 && visited[i]==0){
            top++;
            stack[top]=i;
}
        }
    }
}

void bfs(int v){
    int i,front,rear;
    int que[20];
    front=rear= -1;
    printf("%d ",v);
    visited[v]=1;
    rear++;
    que[rear]=v;
    while(front<=rear){
        front++;
        if(front<=rear)
        v=que[front];
        for(i=1;i<=n;i++){
            if( adj[v][i]==1 && visited[i]==0){
                printf("%d ",i);
                visited[i]=1;
                rear++;
                que[rear]=i;
            }
        }
    }
}



int main()
{
    int i,v,choice;
    create_graph();
    while(1){
    cout<<"\n1. Adjacency matrix\n2. Depth First Search using stack\n3. Breadth First Search\n4. Exit\nEnter your choice : ";
    cin>>choice;
    switch(choice){
    case 1:
        cout<<"Adjacency Matrix\n";
        display();
        break;
    case 2:
        cout<<"Enter starting node for Depth First Search : ";
        cin>>v;
        for(i=1;i<=n;i++)
        visited[i]=0;
        dfs(v);
        break;
    case 3:
        cout<<"Enter starting node for Breadth First Search : ";
        cin>>v;
        for(i=1;i<=n;i++)
        visited[i]=0;
        bfs(v);
        break;
    case 4:
        exit(1);
    default:
        cout<<"Invalid Input\n";
        break;
    }
    }
}


