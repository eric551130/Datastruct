#include <iostream>
#include <cstdlib>
#include <ctime>
#define n 30000000
#define datanum 30000000
#define bucket 3000000 
using namespace std;

//BinarySearch
template<class T>
void merge(T array[],int p,int q,int r,T max);  

template<class T>
void mergesort(T array[],int p,int r,T max);

string getnumber(); 

int RecursiveBS(string *arr, int start, int end, string khey);

int IteratorBS(string *arr, int start, int end, string khey);

//BinarySearchTree
class BST;
class TreeNode{
public:
    friend class BST; 	
    TreeNode():leftchild(0),rightchild(0),parent(0),key(""){};
    TreeNode(string x):leftchild(0),rightchild(0),parent(0),key(x){};
    string GetKey(){return key;}        
private:
    TreeNode *leftchild;
    TreeNode *rightchild;
    TreeNode *parent;
    string key;
};

class BST{
public:
    BST():root(0){};
    TreeNode* Search(string key);
    void InsertBST(string key);
    void InorderPrint();        	
private:
    TreeNode* root;
    TreeNode* Leftmost(TreeNode *current);
    TreeNode* Successor(TreeNode *current);
};

TreeNode* BST::Search(string KEY){

    TreeNode *current = root;
         
    while (current != NULL && KEY != current->key) { 
    	                                           
        if (KEY < current->key){                      
            current = current->leftchild; 
        }
        else {
            current = current->rightchild;
        }
    }
    return current;
}

void BST::InsertBST(string key){

    TreeNode *y = 0;     
    TreeNode *x = 0;    
    TreeNode *insert_node = new TreeNode(key); 

    x = root;
    while (x != NULL) {             
        y = x;                                
        if (insert_node->key < x->key){
            x = x->leftchild;
        }
        else{
            x = x->rightchild;
        }
    }                                
                                      
    insert_node->parent = y;         

    if (y == NULL){                
        this->root = insert_node;
    }
    else if (insert_node->key < y->key){
        y->leftchild = insert_node;
    }
    else{
        y->rightchild = insert_node;
    }
}

TreeNode* BST::Leftmost(TreeNode *current){
    
    while (current->leftchild != NULL){
        current = current->leftchild;
    }
    return current;
}
TreeNode* BST::Successor(TreeNode *current){
    
    if (current->rightchild != NULL){
        return Leftmost(current->rightchild);
    }
    
    TreeNode *new_node = current->parent;
    
    while (new_node != NULL && current == new_node->rightchild) {
        current = new_node;
        new_node = new_node->parent;
    }
    
    return new_node;
}
void BST::InorderPrint(){
    TreeNode *current = new TreeNode;
    current = Leftmost(root);
    while(current){
        cout << "(" << current->key << ")" << " ";
        current = Successor(current);
    }
}

//HashTablewithChain
class Hashtable;

class ListNode{
	friend class Hashtable;
	public:            
 	   string value;      
 	   ListNode *next;     	
 	   ListNode():value(""),next(0){};
 	   ListNode(string Value):value(Value),next(0){};
	   ListNode(ListNode const &data):value(data.value),next(data.next){};
};

class Hashtable
{
public:
    Hashtable(){};
    Hashtable(int m){
		size=m;
		count=0;
        table = new ListNode *[size];       
        for (int i = 0; i < size; i++) {   
            table[i] = 0;                
        }
    }
    ~Hashtable();

    void Insert(ListNode data);
    string hSearch(string key);
    void DisplayTable();
private:
    int size,count;       
    ListNode **table;     
};

long long int h(string x)
{	
	long long int nbuck = 1;
	for (int i = 0; i < 6; i++){
		if(i%2==0)
		nbuck *= static_cast<int>(x[i]);
		else
		nbuck += static_cast<int>(x[i]);
	}
		long long int temp = ( nbuck )% bucket;
		
	return temp;
}


void Hashtable::Insert(ListNode data){

    int index = h(data.value); 
    ListNode *newNode = new ListNode(data);    

    if (table[index] == NULL) {         
        table[index] = newNode;       
    }
    else {                              
        ListNode *next = table[index]->next;
        table[index]->next = newNode;
        newNode->next = next;
    }
}

string Hashtable::hSearch(string key){

    int index = h(key);
    ListNode *current = table[index];       

    while (current != NULL) { 
        if ( current->value == key) {
            return current->value;
        }
        current = current->next;
    }
    return " no find ";
}

Hashtable::~Hashtable(){

    for (int i = 0; i < bucket; i++) {    
                                        
        ListNode *current = table[i];    
        while (current != NULL) {  
            ListNode *previous = current;
            current = current->next;
            delete previous;
            previous = 0;
        }
    }
    delete [] table;
}

void Hashtable::DisplayTable(){

    for (int i = 0; i < bucket; i++) {
        cout << "#slot#" << i << ": ";
        ListNode *current = table[i];
        while (current != NULL) {
            cout << "(" << current->value << ") ";
            current = current->next;
        }
        cout << endl;
    }
    cout << endl;
}
 
int main(){
	srand(time(0));
	int count;
	const string max = "zzzzzz";
	clock_t start,end;

//binary search	
	string *sArray = new string[datanum];
	string key1;
	string key2;
	double time1,time2;
	start = clock();
	for(int i=0;i<datanum;i++)
		sArray[i] = getnumber();
				
	mergesort(sArray,0,datanum-1,max);
	end = clock();
	
	time1 = end - start;
//RecursiveBS	
	cout<<"RecursiveBS"<<endl;
	start = clock();
	for(int i=0;i<n;i++){
	key1 = sArray[rand()%datanum];
	RecursiveBS(sArray,0,(datanum-1),key1);		
	}	
	end = clock();
	
	time2 = end - start;
	cout<<"產生時間 : "<<time1/1000.000<<" ms , 搜尋時間 : "<<time2/1000.000<<" ms\n"; 
//IteratorBS	
	cout<<"IteratorBS"<<endl;
	start = clock();
	for(int i=0;i<n;i++){
	key2 = sArray[rand()%datanum];		
	IteratorBS(sArray,0,(datanum-1),key2);
	}	
	end = clock();
	
	time2 = end - start;
	cout<<"產生時間 : "<<time1/1000.000<<" ms , 搜尋時間 : "<<time2/1000.000<<" ms\n"; 
//BinarySearchTree
	double bsttime1,bsttime2;
	string *BstArray = new string[datanum];
    string ssearch;
    BST T;		
	cout<<"BinarySearchTree"<<endl;
	start = clock();
    for(int i=0;i<datanum;i++)
    BstArray[i]=getnumber();	
	
	for(int i=0;i<datanum;i++)
    T.InsertBST(BstArray[i]);	
	end = clock();
	bsttime1 = end-start;
	
	start = clock();
	for(int i=0;i<n;i++){
	ssearch = sArray[rand()%datanum];	
	T.Search(ssearch);					
	}
	end = clock();	
	bsttime2 = end - start;
	cout<<"產生時間 : "<<bsttime1/1000.000<<" ms , 搜尋時間 : "<<bsttime2/1000.000<<" ms\n"; 	
//HashTable	
	double htime1,htime2;
	cout<<"HashTable"<<endl;
	string *str=new string[datanum];
	Hashtable shash(datanum);
	
	start = clock();
	for(int i=0;i<datanum;i++)
	str[i]=getnumber();
				
	for(int i=0;i<datanum;i++)
	shash.Insert(ListNode(str[i]));
		
	end = clock();	
	
	htime1 = end-start;
	
	start = clock();	
	string key;
	for(int i=0;i<datanum;i++){
	key = str[rand()%datanum];		
	shash.hSearch(key);		
	}	
	
	end = clock();	
	htime2 = end - start;
	cout<<"產生時間 : "<<htime1/1000.000<<" ms , 搜尋時間 : "<<htime2/1000.000<<" ms\n"; 		
	
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
