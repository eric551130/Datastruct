#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;


#define n 20000 
template<class T>
void merge(T array[],int p,int q,int r,T max);  

template<class T>
void mergesort(T array[],int p,int r,T max);

template<class T>
void InsertSortedArray(T A[], int size);

template<class T>
void swap(T* a, T* b);

template<class T>
void Bubble(T A[], int size);	

template<class T>
int Max(T A[], int size);

string getnumber(); //6個英文字母識別字 

int main(){
	int i,size,j;
	clock_t start,end; //計算時間 
	double num;
	cout<<"資料量 : "<<n<<" 筆"<<endl;	
	
	cout<<"資料型態 : string =========================="<<endl;
	string (*sArray)[n]= new string[4][n];

	string max = "zzzzzz";
	for(int j=0;j<4;j++)
		for(i=0;i<n;i++)
		sArray[j][i] = getnumber();	
		
	cout<<"Mergesort---------------\nprogram start"<<endl;					
	start = clock();

	mergesort(sArray[0],0,n-1,max);

	end = clock();
	num = (end-start)/1000.000;
	cout<<"time : "<<num<<" s"<<endl;	
    cout<<"finish\n--------------------\n"<<endl;	
	cout<<"InsertSort---------------\nprogram start"<<endl;			

	start = clock();
	
	for(size=1;size<n;size++)
	InsertSortedArray(sArray[1], size);	

	end = clock();
	num = (end-start)/1000.000;
	cout<<"time : "<<num<<" s"<<endl;	
    cout<<"finish\n--------------------\n"<<endl;
   
	cout<<"Selection---------------\nprogram start"<<endl;  


	start = clock();

	for(size = n; size > 1; size--) {
		j = Max(sArray[2], size);
		swap(sArray[2][j], sArray[2][size - 1]);
	}
	end = clock();
	num = (end-start)/1000.000;
	cout<<"time : "<<num<<" s"<<endl;		  
    cout<<"finish\n--------------------\n"<<endl;
    
    
	cout<<"Bubblesort---------------\nprogram start"<<endl;    
			
	start = clock();

	for(size=n;size>0;size--) 
		Bubble(sArray[3], size);
		
	end = clock();
	num = (end-start)/1000.000;
	cout<<"time : "<<num<<" s"<<endl;		
    cout<<"finish\n--------------------\n"<<endl;   
	cout<<"======================================"<<endl;  
	
	
//int
	
	cout<<"\n資料型態 : int =========================="<<endl;
	int (*intArray)[n] = new int[4][n];
	for(int j=0;j<4;j++)
		for(i=0;i<n;i++)
		intArray[j][i] = rand()%1000000;	
		
	cout<<"Mergesort---------------\nprogram start"<<endl;					
	start = clock();

	mergesort(intArray[0],0,n-1,n);

	end = clock();
	num = (end-start)/1000.000;
	cout<<"time : "<<num<<" s"<<endl;	
    cout<<"finish\n--------------------\n"<<endl;	
	cout<<"InsertSort---------------\nprogram start"<<endl;			

	start = clock();
	
	for(size=1;size<n;size++)
	InsertSortedArray(intArray[1], size);	

	end = clock();
	num = (end-start)/1000.000;
	cout<<"time : "<<num<<" s"<<endl;	
    cout<<"finish\n--------------------\n"<<endl;
   
	cout<<"Selection---------------\nprogram start"<<endl;  

		
	start = clock();

	for(size = n; size > 1; size--) {
		j = Max(intArray[2], size);
		swap(intArray[2][j], intArray[2][size - 1]);
	}
	end = clock();
	num = (end-start)/1000.000;
	cout<<"time : "<<num<<" s"<<endl;		  
    cout<<"finish\n--------------------\n"<<endl;
    
    
	cout<<"Bubblesort---------------\nprogram start"<<endl;    
			
	start = clock();

	for(size=n;size>0;size--) 
		Bubble(intArray[3], size);
		
	end = clock();
	num = (end-start)/1000.000;
	cout<<"time : "<<num<<" s"<<endl;		
    cout<<"finish\n--------------------\n"<<endl;   
	cout<<"======================================"<<endl;  
	
//double
	
	cout<<"\n資料型態 : double =========================="<<endl;
	double (*dArray)[n] = new double[4][n];
	double dmax = 1000000.000;
	for(int j=0;j<4;j++)
		for(i=0;i<n;i++)
		dArray[j][i] = (rand()%1000000)/10.000;	
		
	cout<<"Mergesort---------------\nprogram start"<<endl;					
	start = clock();

	mergesort(dArray[0],0,n-1,dmax);

	end = clock();
	num = (end-start)/1000.000;
	cout<<"time : "<<num<<" s"<<endl;	
    cout<<"finish\n--------------------\n"<<endl;	
	cout<<"InsertSort---------------\nprogram start"<<endl;			

	start = clock();
	
	for(size=1;size<n;size++)
	InsertSortedArray(dArray[1], size);	

	end = clock();
	num = (end-start)/1000.000;
	cout<<"time : "<<num<<" s"<<endl;	
    cout<<"finish\n--------------------\n"<<endl;
   
	cout<<"Selection---------------\nprogram start"<<endl;  

		
	start = clock();

	for(size = n; size > 1; size--) {
		j = Max(dArray[2], size);
		swap(dArray[2][j], dArray[2][size - 1]);
	}
	end = clock();
	num = (end-start)/1000.000;
	cout<<"time : "<<num<<" s"<<endl;		  
    cout<<"finish\n--------------------\n"<<endl;
    
    
	cout<<"Bubblesort---------------\nprogram start"<<endl;    
			
	start = clock();

	for(size=n;size>0;size--) 
		Bubble(dArray[3], size);
		
	end = clock();
	num = (end-start)/1000.000;
	cout<<"time : "<<num<<" s"<<endl;		
    cout<<"finish\n--------------------\n"<<endl;   
	cout<<"======================================"<<endl;  
		
//float		
		
	cout<<"\n資料型態 : float =========================="<<endl;
	float (*fArray)[n] = new float[4][n];
	float fmax = 1000000.000;
	for(int j=0;j<4;j++)
		for(i=0;i<n;i++)
		fArray[j][i] = (rand()%1000000)/10.000;	
		
	cout<<"Mergesort---------------\nprogram start"<<endl;					
	start = clock();

	mergesort(fArray[0],0,n-1,fmax);

	end = clock();
	num = (end-start)/1000.000;
	cout<<"time : "<<num<<" s"<<endl;	
    cout<<"finish\n--------------------\n"<<endl;	
	cout<<"InsertSort---------------\nprogram start"<<endl;			

	start = clock();
	
	for(size=1;size<n;size++)
	InsertSortedArray(fArray[1], size);	

	end = clock();
	num = (end-start)/1000.000;
	cout<<"time : "<<num<<" s"<<endl;	
    cout<<"finish\n--------------------\n"<<endl;
   
	cout<<"Selection---------------\nprogram start"<<endl;  

		
	start = clock();

	for(size = n; size > 1; size--) {
		j = Max(fArray[2], size);
		swap(fArray[2][j], fArray[2][size - 1]);
	}
	end = clock();
	num = (end-start)/1000.000;
	cout<<"time : "<<num<<" s"<<endl;		  
    cout<<"finish\n--------------------\n"<<endl;
    
    
	cout<<"Bubblesort---------------\nprogram start"<<endl;    
			
	start = clock();

	for(size=n;size>0;size--) 
		Bubble(fArray[3], size);
		
	end = clock();
	num = (end-start)/1000.000;
	cout<<"time : "<<num<<" s"<<endl;		
    cout<<"finish\n--------------------\n"<<endl;   
	cout<<"======================================"<<endl;  
	
	delete []sArray;  
	delete []intArray;  
	delete []dArray;  
	delete []fArray;  
  return 0; 
}
template<class T>
void InsertSortedArray(T *A, int size) {
	int i;
	T x;
	x = A[size];
	
	for(i = size - 1; i >= 0 && x < A[i]; i--) 
		A[i+1] = A[i];
		
	A[i+1] = x;
		
	return;
}
template<class T>
void swap(T* a,T* b) {
	T* temp;	
	temp=a;
	a=b;
	b=temp;	
	return;
}
template<class T>
void Bubble(T *A, int size) {
	for(int i=0;i<size-1;i++)
		if(A[i]>A[i+1])
		swap(A[i],A[i+1]);
}
template<class T>
int Max(T *A, int size) {
	int pos = 0;

	for(int i = 0; i < size; i++)
		if(A[i] > A[pos]) 
			pos = i;
	
	return pos;
}
string getnumber(){
	char num[6];
	int count;	
	char englishChar[52] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
	char allChar[62] = {'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
	
	count = rand()%1000;
	
	num[0] = englishChar[count%52];
		
	for(int i=1;i<=5;i++){
	count = rand()%1000;	
	num[i] = allChar[count%62];		
	}
	
					
return num;	
}
template<class T>
void merge(T *array,int p,int q,int r,T max){
	int n1,n2;
	
	n1 = q-p+1 ;
	n2 = r-q ;
	
	T (*left) = new T[n1+1];
	T (*right) = new T[n2+1];
		
	for(int i=0;i<n1;i++)
		left[i] = array[p+i];
	
	for(int i=0;i<n2;i++)
		right[i] = array[q+1+i];
	

	left[n1] = max;
	right[n2] = max;		
		
	
	int i=0,j=0;
	
	for(int k=p;k<=r;k++){
		if(left[i]<=right[j]){
			array[k] = left[i];
			i++;
		}
		else{
			array[k] = right[j];
			j++; 
		}		
	}
	delete []left;
	delete []right;	
}
template<class T>
void mergesort(T *array,int p,int r,T max){
	if(p<r){
        int q = (p+r)/2;  
        mergesort(array, p, q, max);    
        mergesort(array, q+1, r, max);   
        merge(array, p, q, r, max); 		
	}
	
}
