#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector> 
#define n 2500000

using namespace std;

//Bst
template<class T>
class BST;

template<class T>
class TreeNode{
public:
    TreeNode():left(0),right(0),parent(0){};
    TreeNode(T x):left(0),right(0),parent(0),key(x){};
    T GetKey(){return key;}       
	friend class BST<T>; 
private:
    TreeNode *left,*right;
    TreeNode *parent;
    T key;
};

template<class T>
class BST{
public:
    BST():root(0){};
    void InsertBST(T key);
    void InorderPrint();        	
private:
    TreeNode<T>* root;
    TreeNode<T>* theLeft(TreeNode<T> *current); //找最左邊 
    TreeNode<T>* Successor(TreeNode<T> *current);
};

template<class T>
void BST<T>::InsertBST(T key){

    TreeNode<T> *y = 0;     
    TreeNode<T> *x = 0;   
    TreeNode<T> *insert_node = new TreeNode<T>(key); 

    x = root;
    while (x != NULL) {  
        y = x;                                
        if (insert_node->key < x->key){
            x = x->left;
        }
        else{
            x = x->right;
        }
    }                      
                      
    insert_node->parent = y;        

    if (y == NULL){           
        this->root = insert_node;
    }
    else if (insert_node->key < y->key){
        y->left = insert_node;
    }
    else{
        y->right = insert_node;
    }
}

template<class T>
TreeNode<T>* BST<T>::theLeft(TreeNode<T> *current){
    
    while (current->left != NULL){
        current = current->left;
    }
    return current;
}

template<class T>
TreeNode<T>* BST<T>::Successor(TreeNode<T> *current){
    
    if (current->right != NULL){
        return theLeft(current->right);
    }
    
    TreeNode<T> *new_node = current->parent;
    
    while (new_node != NULL && current == new_node->right) {
        current = new_node;
        new_node = new_node->parent;
    }
    
    return new_node;
}

template<class T>
void BST<T>::InorderPrint(){
    TreeNode<T> *current = new TreeNode<T>;
    current = theLeft(root);
    while(current){
       // cout << "(" << current->key << ")" << " ";
        current = Successor(current);
    }
}

//heapsort
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

    if (largest != root) {                       
        swap(array[largest], array[root]);       
        MaxHeap(array, largest, length);       
    }
}
template<class T>
void HeapSort(vector<T> &array,T zero){

    array.insert(array.begin(), zero);               

    for (int i = array.size()/2; i >= 1 ; i--) {
        MaxHeap(array, i, array.size() - 1);  
    }                          

    int size = array.size()-1;                  
    for (int i = array.size() -1; i >= 2; i--) {
        swap(array[1], array[i]);                     
        size--;
        MaxHeap(array, 1, size);                 
    }

    array.erase(array.begin());                   
}
//quicksort 
template<class T>
void qswap(T* a,T* b){
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
int main() {
	srand(time(0));
	clock_t start,end;
	
	cout<<"BinarySearchTree "<<endl;
    string *sArray = new string[n];
    BST<string> stringT;
    
    for(int i=0;i<n;i++){
    sArray[i]=getnumber();	
	}
	
    for(int i=0;i<n;i++){
    stringT.InsertBST(sArray[i]);	
	}
	start = clock();
    stringT.InorderPrint();
    end = clock();
    double stime = (end-start);
    cout<<"string time is : " <<stime<< " ms"<<endl;
    //============================================
    int *intArray = new int[n];
    BST<int> intT;
    
    for(int i=0;i<n;i++){
    intArray[i]=rand()%1000;	
	}
	
    for(int i=0;i<n;i++){
    intT.InsertBST(intArray[i]);	
	}
	
	start = clock();
    intT.InorderPrint();
    end = clock();
    double itime = (end-start);
    cout<<"int time is : " <<itime<< " ms"<< endl;  
    //============================================
    double *dArray = new double[n];
    BST<double> doubleT;
    for(int i=0;i<n;i++){
    dArray[i]=(rand()%10000);	
	}
	
    for(int i=0;i<n;i++){
    doubleT.InsertBST(dArray[i]);	
	}
	
    start = clock();
    doubleT.InorderPrint();
    end = clock();
    double dtime = (end-start);
    cout<<"double time is : " <<dtime<< " ms"<< endl;      
    //============================================
    cout<<"Heapsort"<<endl;
    
    string (*hsarr) = new string[n];
    for(int i=0;i<n;i++) hsarr[i]=getnumber();
    
    vector<string> hsarray(hsarr,hsarr+n);	//arr 0 ~ n 進vector array 
    string zero=("");
    
   	start=clock();
    HeapSort(hsarray,zero);
	end=clock();
	
	double Hstime = (end-start);
    cout<<"string time is : " <<Hstime<< " ms"<< endl;
    //============================================
    int (*hiarr) = new int[n];
    for(int i=0;i<n;i++) hiarr[i]=rand()%100000;
    
    vector<int> hiarray(hiarr,hiarr+n);	//arr 0 ~ n 進vector array 
    
   	start=clock();
    HeapSort(hiarray,0);
	end=clock();
	
	double Hitime = (end-start);
    cout<<"int time is : " <<Hitime<< " ms"<< endl;   
    //============================================
    double (*hdarr) = new double[n];
    for(int i=0;i<n;i++) hdarr[i]=(rand()%1000000)/10.000;
    
    vector<double> hdarray(hdarr,hdarr+n);	//arr 0 ~ n 進vector array 
    
   	start=clock();
    HeapSort(hdarray,0.000);
	end=clock();
	
	double Hdtime = (end-start);
    cout<<"double time is : " <<Hitime<< " ms"<< endl;      
    //============================================
    cout<<"quicksort"<<endl;
    
    string (*sA) = new string[n];
	
	for(int i=0;i<n;i++)
	sA[i] = getnumber();
	
	start = clock();
	QuickSort(sA,0,n-1);
	end = clock();
	double qstime = (end-start);	
	cout<<"string time is : " <<qstime<< " ms"<< endl;	  
	//============================================
    int *iA = new int[n];
	
	for(int i=0;i<=n;i++)
	iA[i] = rand()%1000000;
	
	start = clock();
	QuickSort(iA,0,n-1);
	end = clock();
	double qitime = (end-start);	
	cout<<"int time is : " <<qitime<< " ms"<< endl;	 	
	//============================================
    double *dA = new double[n];
	
	for(int i=0;i<=n;i++)
	dA[i] = (rand()%1000000)/1.000;
	
	start = clock();
	QuickSort(dA,0,n-1);
	end = clock();
	double qdtime = (end-start);	
	cout<<"double time is : " <<qdtime<< " ms"<< endl;	 	
		   
    return 0;
}



