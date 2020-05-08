#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

class point{
	public:
		int x;
		int y;
		int dir;		
};
class Node {
	public:
		point data;
		Node *link;
};
class Stack{
	public:                 
 		Stack(){
 			size = 0;
 			top = NULL; 
 		};
  		void Push(point data);
  		void Pop();
  		bool IsEmpty();
  		Node* Top();
  		int getSize();
    private:
    	Node *top;
    	int size;
};

void Stack::Push(point dat){

    Node *newnode; 
    newnode = new Node;
	newnode -> data = dat;
    newnode->link = top;                    
    top = newnode;
    size++;
}

void Stack::Pop(){

    if (IsEmpty()) {
        cout << "Stack is empty.\n";
        return;
    }

    Node *deletenode = top;
    top = top->link;
    delete deletenode;
    deletenode = 0;
    size--;
}

Node* Stack::Top(){

    if (IsEmpty()) {
        cout << "Stack is empty.\n";
    }

return top;
}

bool Stack::IsEmpty(){

    return (size == 0);     // if size==0, return true
}

int Stack::getSize(){
	
    return size;
}

int path(int g,int h,int n,int p);

int move[4][2]={{0,1},{1,0},{0,-1},{-1,0}};

int main(){
	int g,h,n,p,k;	
	srand(time(0));
	k=100;
	int success,nopath;
	clock_t start,end;
	n=500;p=20;
/*	for(int p=20;p<=80;p+=20){
	success=0;nopath=0;
	start=clock();
	for(int i=0;i<k;i++){
	if(path(n,n,n,p))
		success++;
	else
		nopath++;				
	}
	end=clock();
	cout<<"迷宮大小 = "<<n<<" ,每個點通過率 = "<<p<<"%"<<endl;	
	cout<<"success : "<<success<<" ,no path : "<<nopath<<endl;
	cout<<"Success rate : "<<success<<"%"<<" ,time : "<<(end-start)<<"ms"<<endl;
	cout<<"====================================="<<endl;		
	}*/ 
	p=90;
	success=0;nopath=0;
	start=clock();
	for(int i=0;i<k;i++){
	if(path(n,n,n,p))
		success++;
	else
		nopath++;				
	}
	end=clock();
	cout<<"迷宮大小 = "<<n<<"每個點通過率 = "<<p<<"%"<<endl;	
	cout<<"success : "<<success<<" ,no path : "<<nopath<<endl;
	cout<<"Success rate : "<<success<<"%"<<" ,time : "<<(end-start)<<"ms"<<endl;
	cout<<"====================================="<<endl;
		
return 0;	
}


int path(int g,int h,int num,int p){
	int n=num+2;
	int maze[n][n];	
	int i,j;

	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			maze[i][j]=0;
			
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
		if(i==0||j==0||i==n-1||j==n-1)
			maze[i][j]=1;
		else if((i==1&&j==1)||(i==num&&j==num))	
			maze[i][j]=0;
		else{
			int count = (rand()%100)+1;			
			if(count<=p)	
			maze[i][j]=0;
			else
			maze[i][j]=1;
			}			
		}
	}

//==============================================
		
	Stack stack;
	point temp;
	temp.x=1;
	temp.y=1;
	temp.dir=0;	
	stack.Push(temp);
	int count = 0;
//	cout<<stack.Top()->data.x<<" "<<stack.Top()->data.y<<" "<<stack.Top()->data.dir<<endl;
//	cout<<stack.getSize()<<endl;
	maze[1][1]=2;
		
	while(!stack.IsEmpty()){
		temp = stack.Top()->data;
		stack.Pop();
		
		int i=temp.x;int j=temp.y;int d = temp.dir;
		while(d<4){
			int m = i+move[d][0];int n = j+move[d][1];
			if((m==g)&&(n==h)) count = 1;
			if(!maze[m][n]){
				maze[m][n]=2;
				temp.x=i;temp.y=j;temp.dir=d+1;
				stack.Push(temp);
				i=m;j=n;d=0;
			}
			else d++;
		}	
	}

return count;
}
