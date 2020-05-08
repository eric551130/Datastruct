#include <iostream>
#include <string>

using namespace std;

class BST;
class TreeNode{
public:
    TreeNode():leftchild(0),rightchild(0),parent(0),key(""){};
    TreeNode(string x):leftchild(0),rightchild(0),parent(0),key(x){};
    int GetKey(){return key;}        
    string GetElement(){return element;} 
    friend class BST; 	
private:
    TreeNode *leftchild;
    TreeNode *rightchild;
    TreeNode *parent;
    string key;
};

class BST{
public:
    BST():root(0){};
    TreeNode* Search(int key);
    void InsertBST(int key, string element);
    void InorderPrint();        	
private:
    TreeNode* root;
    TreeNode* Leftmost(TreeNode *current);
    TreeNode* Successor(TreeNode *current);
};

TreeNode* BST::Search(int KEY){

    TreeNode *current = root;               // �Ncurent���Vroot�@��traversal�_�I
         
    while (current != NULL && KEY != current->key) {  // ��ر��p���X�j��G
    	                                              // 1.�S��� 2.�����
        if (KEY < current->key){                      
            current = current->leftchild;   // �V����
        }
        else {
            current = current->rightchild;  // �V�k��
        }
    }
    return current;
}

void BST::InsertBST(int key, string element){

    TreeNode *y = 0;        // �Ƿs�⪨��
    TreeNode *x = 0;        // ��L
    TreeNode *insert_node = new TreeNode(key, element); 

    x = root;
    while (x != NULL) {                // �bwhile��, �H�p�PSearch()���覡�M��A����m       
        y = x;                                
        if (insert_node->key < x->key){
            x = x->leftchild;
        }
        else{
            x = x->rightchild;
        }
    }                                  // ���X�j���, x�Y��NULL
                                       // y�Y��insert_node��parent
    insert_node->parent = y;           // �Ninsert_node��parent pointer���Vy

    if (y == NULL){                    // �U���@��if-else, ��insert_node���WBST
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
        cout << current->element << "(" << current->key << ")" << " ";
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
    
    BST T;
    
    T.InsertBST(8,"�t�P�H");
    T.InsertBST(1000,"����");
    T.InsertBST(2,"�J�L");
    T.InsertBST(513,"��J");


    cout << "Inorder Traversal:\n";
    T.InorderPrint();
    cout << endl;
    
    TreeNode *node = T.Search(1000);
    if(node != NULL){
    	cout << "There is " << node->GetElement() << "(" << node->GetKey() << ")" << endl;
    }
    else {
    	cout << "no element with Key(1000)" << endl;
    }
    
    node = T.Search(73);
    if(node != NULL){
    	cout << "There is " << node->GetElement() << "(" << node->GetKey() << ")" << endl;
    }
    else {
    	cout << "no element with Key(73)" << endl;
    }

    return 0;
}



