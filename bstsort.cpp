#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#define n 50 

using namespace std;

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
    TreeNode<T>* Leftmost(TreeNode<T> *current);
    TreeNode<T>* Successor(TreeNode<T> *current);
};

template<class T>
void BST<T>::InsertBST(T key){

    TreeNode<T> *y = 0;     
    TreeNode<T> *x = 0;        // ��L
    TreeNode<T> *insert_node = new TreeNode<T>(key); 

    x = root;
    while (x != NULL) {                // �bwhile��, �H�p�PSearch()���覡�M��A����m       
        y = x;                                
        if (insert_node->key < x->key){
            x = x->left;
        }
        else{
            x = x->right;
        }
    }                                  // ���X�j���, x�Y��NULL
                                       // y�Y��insert_node��parent
    insert_node->parent = y;           // �Ninsert_node��parent pointer���Vy

    if (y == NULL){                    // �U���@��if-else, ��insert_node���WBST
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
TreeNode<T>* BST<T>::Leftmost(TreeNode<T> *current){
    
    while (current->left != NULL){
        current = current->left;
    }
    return current;
}

template<class T>
TreeNode<T>* BST<T>::Successor(TreeNode<T> *current){
    
    if (current->right != NULL){
        return Leftmost(current->right);
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
    current = Leftmost(root);
    while(current){
        cout << "(" << current->key << ")" << " ";
        current = Successor(current);
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
	
    string *sArray = new string[n];
    BST<string> stringT;
    
    for(int i=0;i<n;i++){
    sArray[i]=getnumber();	
	}
	
    for(int i=0;i<n;i++){
    stringT.InsertBST(sArray[i]);	
	}
	
    cout << "Inorder Traversal:\n";
    stringT.InorderPrint();
    cout << endl;
    //============================================
    int *intArray = new int[n];
    BST<int> intT;
    
    for(int i=0;i<n;i++){
    intArray[i]=rand()%1000;	
	}
	
    for(int i=0;i<n;i++){
    intT.InsertBST(intArray[i]);	
	}
	
    cout << "\nInorder Traversal:\n";
    intT.InorderPrint();
    cout << endl;    
    //============================================
    double *dArray = new double[n];
    BST<double> doubleT;
    for(int i=0;i<n;i++){
    dArray[i]=(rand()%10000)/10.0000;	
	}
	
    for(int i=0;i<n;i++){
    doubleT.InsertBST(dArray[i]);	
	}
	
    cout << "\nInorder Traversal:\n";
    doubleT.InorderPrint();
    cout << endl;       
    //============================================
    
    
    return 0;
}



