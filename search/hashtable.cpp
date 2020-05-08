#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;
const int n = 10000000;
const int bucket = 401;

class symboltable;

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
        table = new ListNode *[size];           // allocate the first demension of table
        for (int i = 0; i < size; i++) {    // initialization
            table[i] = 0;                   // ensure every slot points to NULL
        }
    }
    ~Hashtable();

    void Insert(ListNode data);
    string Search(string key);
    void DisplayTable();
private:
    int size,count;          // size: size of table, count: number of data            
    ListNode **table;             // pointer to pointer, hash table     
};

int h(string x)
{	
	int nbuck = 0;
	for (int i = 0; i < 6; i++)
		nbuck += static_cast<int>(x[i]);
		
	return nbuck % bucket;
}


void Hashtable::Insert(ListNode data){

    int index = h(data.value);   // get index of slot
    ListNode *newNode = new ListNode(data);       // create new node to store data

    if (table[index] == NULL) {           // eg: list: (empty), add4
        table[index] = newNode;           // eg: list: 4->NULL
    }
    else {                                // eg: list: 5->9->NULL  , add 4
        ListNode *next = table[index]->next;  //     list: 5->4->9->NULL
        table[index]->next = newNode;
        newNode->next = next;
    }
}

string Hashtable::Search(string key){

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

    for (int i = 0; i < bucket; i++) {    // visit every node in table 
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
		int i;
		srand(time(0));
		string *str=new string[n];
		clock_t start,end;
		
		Hashtable hash(n);

		for(i=0;i<n;i++)
		str[i]=getnumber();
		
		string key = str[rand()%n];
		
		start = clock();
		for(i=0;i<n;i++)
		hash.Insert(ListNode(str[i]));
		end = clock();
		
		cout<<"產生時間 : "<< end - start;
		
		start = clock();		
		hash.Search(key);
		end = clock();
		
		cout<<"搜尋時間 : "<<end - start;
return 0;	
}


