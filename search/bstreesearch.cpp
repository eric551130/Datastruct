#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#define n 10000000

using namespace std;

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
    TreeNode *x = 0;        // 哨兵
    TreeNode *insert_node = new TreeNode(key); 

    x = root;
    while (x != NULL) {                // 在while中, 以如同Search()的方式尋找適當的位置       
        y = x;                                
        if (insert_node->key < x->key){
            x = x->leftchild;
        }
        else{
            x = x->rightchild;
        }
    }                                  // 跳出迴圈後, x即為NULL
                                       // y即為insert_node的parent
    insert_node->parent = y;           // 將insert_node的parent pointer指向y

    if (y == NULL){                    // 下面一組if-else, 把insert_node接上BST
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
    string *sArray = new string[n];
    string ssearch;
    BST T;
    
    for(int i=0;i<n;i++){
    sArray[i]=getnumber();	
	}
	ssearch = sArray[rand()%n];
	
    for(int i=0;i<n;i++){
    T.InsertBST(sArray[i]);	
	}
	
   // cout << "Inorder Traversal:\n";
  //  T.InorderPrint();
   // cout << endl;
    
    cout<<"\nssearch is :"<<ssearch<<endl;
    TreeNode *node = T.Search(ssearch);
    if(node != NULL){
    	cout << "\nThere is " << "(" << node->GetKey() << ")" << endl;
    }
    else {
    	cout << "no element with Key :"<< ssearch << endl;
    }
    
    node = T.Search("AAACCC");
    if(node != NULL){
    	cout << "\nThere is " << "(" << node->GetKey() << ")" << endl;
    }
    else {
    	cout << "no element with Key(AAACCC)" << endl;
    }

    return 0;
}



