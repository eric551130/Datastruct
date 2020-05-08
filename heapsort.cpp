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

    if (largest != root) {                         // 如果目前root的Key不是三者中的最大
        swap(array[largest], array[root]);         // 就調換root與三者中Key最大的node之位置
        MaxHeap(array, largest, length);        // 調整新的subtree成Max Heap
    }
}
template<class T>
void BuildMaxHeap(vector<T> &array){

    for (int i = array.size()/2; i >= 1 ; i--) {
        MaxHeap(array, i, array.size() - 1);     // length要減一, 因為heap從1開始存放資料
    }
}
template<class T>
void HeapSort(vector<T> &array){

    array.insert(array.begin(), "");                     // 將index(0)閒置

    for (int i = array.size()/2; i >= 1 ; i--) {
        MaxHeap(array, i, array.size() - 1);     // length要減一, 因為heap從1開始存放資料
    }                               // 將array調整成Max Heap

    int size = array.size() -1;                    // size用來記錄「目前要處理的矩陣」之長度
    for (int i = array.size() -1; i >= 2; i--) {
        swap(array[1], array[i]);                       // 將最大值放到array的最後一個位置
        size--;
        MaxHeap(array, 1, size);                     // 調整「忽略最後一個位置」的矩陣
    }

    array.erase(array.begin());                         // 將index(0)刪除
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
    
    vector<string> hsarray(hsarr,hsarr+n);	//arr 0 ~ n 進vector array 
    
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
    vector<int> hiarray(hiarr,hiarr+n);	//arr 0 ~ n 進vector array 
    
   	start=clock();
    HeapSort(hiarray);
	end=clock();
	
	double Hitime = (end-start)/1000.000;
    cout<<"int time is : " <<Hitime<< endl;   
*/
    return 0;
}
