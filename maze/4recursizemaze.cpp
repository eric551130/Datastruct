#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 100
#define size (N+2)

int success=0;
int visit(long int maze[][size],int i, int j)
{
    maze[i][j] = 2;
	
	
    if(i == N && j == N)
    success = 1;

    if(success != 1 && maze[i][j+1] == 0) visit(maze,i, j+1); //�k 
    if(success != 1 && maze[i+1][j] == 0) visit(maze,i+1, j); //�U 
    if(success != 1 && maze[i][j-1] == 0) visit(maze,i, j-1); //�� 
    if(success != 1 && maze[i-1][j] == 0) visit(maze,i-1, j); //�W 
 
  //  if(success != 1)
   //     maze[i][j] = 0;
   
    return success;
}
void getmaze(long int maze[][size],int mazesize,int p){
	int i,j;
	int n=mazesize+2;
	
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			int count = rand()%100;
			if(i==0||j==0||i==(n-1)||j==(n-1)) maze[i][j]=1;
			else{
				if(count<=p) maze[i][j]=0;
				else maze[i][j]=1;
			}			
		}
	}
	maze[1][1]==0; maze[mazesize][mazesize]==0;
}
int main() {
   int i,j;
   long int maze[size][size];
   srand(time(0));
   int ok=0,nopath=0,p;
   clock_t start,end;
   	printf("�|���j�M\n");
    for(p=20;p<=80;p+=20){
    	ok = 0; nopath=0;
    	start = clock();
    for(int k=0;k<100;k++){
  		getmaze(maze,N,p);
 		if(visit(maze,1, 1) == 0) nopath++;
   		else ok++;  	  
	}
		end = clock();
	  printf("�g�c�j�p : %d ,�C���I�q�L�v : %d%%\n",N,p);	
 	  printf("success = %d ,no path =  %d \n",ok,nopath);
 	  printf("Success rate : %d%% ,time : %dms\n",ok,(end-start));
	  printf("=====================================\n");         	
	}
    p = 90;ok = 0; nopath=0;
    start = clock();
    for(int k=0;k<100;k++){
  		getmaze(maze,N,p);
 		if(visit(maze,1, 1) == 0) nopath++;
   		else ok++;  	  
	}
	end = clock();
	  printf("�g�c�j�p : %d ,�C���I�q�L�v : %d%%\n",N,p);	
 	  printf("success = %d ,no path =  %d \n",ok,nopath); 	
	  printf("Success rate : %d%% ,time : %dms\n",ok,(end-start));

   return 0; 
}
