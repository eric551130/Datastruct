#include<iostream>
#include<ctime>
#include<cstdlib>
#include<cstring>
#define n 1
using namespace std;
template<class T>
void swap(T* a,T* b){
	T* temp;
	temp = a;
	a = b;
	b = temp;
}
template<class T>
int Partition(T *A,int p,int r){
	T x = A[r];
	int i = p-1;

	for(int j=p;j<r;j++){
		if(A[j]<=x){
		i = i+1;
		swap(A[i],A[j]);	
		}		
	}
	swap(A[i+1],A[r]);
return i+1;
}

template<class T>
void QuickSort(T *A,int p,int r){
	if(p<r){
	int q = Partition(A,p,r);	
	QuickSort(A,p,q-1);
	QuickSort(A,q+1,r);
	}
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

int main(){
    cout<<"quicksort"<<endl;
    clock_t start,end;
    string (*sA) = new string[n];

	for(int i=0;i<n;i++)
	sA[i] = getnumber();
	
	
	
	start = clock();
	QuickSort(sA,0,n-1);
	end = clock();
	double qstime = (end-start)/1000.000;	
	cout<<"string time is : " <<qstime<< endl;	  
return 0;	
}
