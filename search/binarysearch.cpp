#include<iostream>
#include <cstdlib>
#include <ctime>
#include<string>
#define n 1000000

using namespace std;

template<class T>
void merge(T array[],int p,int q,int r,T max);  

template<class T>
void mergesort(T array[],int p,int r,T max);

string getnumber(); 

int RecursiveBS(string *arr, int start, int end, string khey);

int IteratorBS(string *arr, int start, int end, string khey);
 
int main(){
	string *sArray = new string[n];
	string key1,key2;
	int count;
	string max = "zzzzzz";
	clock_t start,end;	int time1,time2;
	for(int i=0;i<n;i++)
		sArray[i] = getnumber();		
		
	key1 = sArray[rand()%n];
	key2 = sArray[rand()%n];
	
	mergesort(sArray,0,n-1,max);
	
//	count = RecursiveBS(sArray,0,(n-1),key1);

	cout<<"RecursiveBS"<<endl;
	start = clock();
	RecursiveBS(sArray,0,(n-1),key1);
	end = clock();
	
	time2 = end - start;
	cout<<"產生時間 : "<<time1<<" ms , 搜尋時間 : "<<time2<<" ms\n"; 
	
	cout<<"search key1 = "<<key1<<endl;
	if(count==0) cout<<"search fail"<<endl;
	else {
	cout<<"success "<<endl;
	cout<<"number = "<<count<<" , key1 = "<<sArray[count];
	}

	count = IteratorBS(sArray,0,(n-1),key2);

	cout<<"\nsearch key2 = "<<key2<<endl;
	if(count==0) cout<<"search fail"<<endl;
	else {
	cout<<"success "<<endl;
	cout<<"number = "<<count<<" , key2 = "<<sArray[count];
	}
	
return 0;	
}

int RecursiveBS(string *arr, int start, int end, string khey) {
	if (start > end)
		return -1;

	int mid = start + (end - start) / 2;  
	if (arr[mid] > khey)
		return RecursiveBS(arr, start, mid - 1, khey);
	else if (arr[mid] < khey)
		return RecursiveBS(arr, mid + 1, end, khey);
	else
	    return mid;  
}

int IteratorBS(string *arr, int start, int end, string khey) {
    int ret = -1;    
    
	int mid;
	while (start <= end) {
		mid = start + (end - start) / 2; 
		if (arr[mid] < khey)
			start = mid + 1;
		else if (arr[mid] > khey)
			end = mid - 1;
		else {           
			ret = mid;  
            break;
        }
	}
	
	return ret;   
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
