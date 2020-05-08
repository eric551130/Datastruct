#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#define n 10

using namespace std;

template<class T>
void MaxHeap(vector<T> &array, int root, int length){

    int left = (2*root),right = (2*root + 1);
    int largest;

    if (left <= length && array[left] > array[root])
        largest = left;
    else
        largest = root;

    if (right <= length && array[right] > array[largest])
        largest = right;

    if (largest != root) {                         // �p�G�ثeroot��Key���O�T�̤����̤j
        swap(array[largest], array[root]);         // �N�մ�root�P�T�̤�Key�̤j��node����m
        MaxHeap(array, largest, length);        // �վ�s��subtree��Max Heap
    }
}
template<class T>
void BuildMaxHeap(vector<T> &array){

    for (int i = array.size()/2; i >= 1 ; i--) {
        MaxHeap(array, i, array.size() - 1);     // length�n��@, �]��heap�q1�}�l�s����
    }
}
template<class T>
void HeapSort(vector<T> &array){

    array.insert(array.begin(), "");                     // �Nindex(0)���m

    for (int i = array.size()/2; i >= 1 ; i--) {
        MaxHeap(array, i, array.size() - 1);     // length�n��@, �]��heap�q1�}�l�s����
    }                               // �Narray�վ㦨Max Heap

    int size = array.size() -1;                    // size�ΨӰO���u�ثe�n�B�z���x�}�v������
    for (int i = array.size() -1; i >= 2; i--) {
        swap(array[1], array[i]);                       // �N�̤j�ȩ��array���̫�@�Ӧ�m
        size--;
        MaxHeap(array, 1, size);                     // �վ�u�����̫�@�Ӧ�m�v���x�}
    }

    array.erase(array.begin());                         // �Nindex(0)�R��
}

template<class T>
void PrintArray(vector<T> &array){
    for (int i = 0; i < array.size(); i++) {
        cout << array[i] << " ";
    }
    cout <<endl;
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

int main() {
	clock_t start,end;
    cout<<"Heapsort"<<endl;
   
   string (*hsarr) = new string[n];
    for(int i=0;i<n;i++) hsarr[i]=getnumber();
    
    vector<string> hsarray(hsarr,hsarr+n);	//arr 0 ~ n �ivector array 
    
    hsarray.push_back("scdcds");
    hsarray.push_back("acdcds");
    hsarray.push_back("ssacds");
    
    PrintArray(hsarray); 
   	start=clock();
    HeapSort(hsarray);
	end=clock();
	PrintArray(hsarray); 
	
	double Hstime = (end-start)/1000.000;
    cout<<"string time is : " <<Hstime<< endl;

    int (*hiarr) = new int[n];
    for(int i=0;i<n;i++) hiarr[i]=rand()%100000;
/*    
    vector<int> hiarray(hiarr,hiarr+n);	//arr 0 ~ n �ivector array 
    
   	start=clock();
    HeapSort(hiarray);
	end=clock();
	
	double Hitime = (end-start)/1000.000;
    cout<<"int time is : " <<Hitime<< endl;   
*/
    return 0;
}
