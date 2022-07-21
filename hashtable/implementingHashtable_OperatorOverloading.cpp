#include <iostream>
#include <cstring>
using namespace std;
template <typename T>
class Node{
    public:
    string key;
    T value;
    Node<T>* next;
    Node(string key, T val){
        this->key = key;
        value = val;
        next = NULL;
    }
    ~Node(){
        if(next!=NULL){
            delete next;
        }
    }
};

template<typename T>
class Hashtable{
    Node<T>** table;//pointer to array of pointers
    int current_size;
    int table_size;
    
    int hashfn(string key){
        int idx = 0;
        int p = 1;
        for(int i=0; i<key.length(); i++){
            idx = idx + (key[i]*p)%table_size;
            idx = idx%table_size;
            p = (p*27)%table_size;
        }
        return idx;
    }
    void rehash(){
        Node<T>** oldtable = table;
        int oldtableSize = table_size;
        table_size = 2*table_size;
        table = new Node<T>*[table_size];
        for(int i=0; i<table_size; i++){
            table[i]=NULL;
        }
        current_size = 0;
        
        //shifting all the elements
        for(int i=0; i<oldtableSize; i++){
            Node<T>* head = oldtable[i];
            while(head!=NULL){
                insert(head->key, head->value);
                head = head->next;
            }
            //deleting row from the old table
            if(oldtable[i]!=NULL){
                delete oldtable[i];//this will call a recursive destructor call and delete the complete row
            }
        }
        delete [] oldtable;
    }
    public:
    Hashtable(int ts=7){
        table_size = ts;
        table = new Node<T>*[table_size];
        current_size = 0;
        for(int i=0; i<table_size; i++){
            table[i]=NULL;
        }
    }
    void insert(string key, T value){
        int idx = hashfn(key);
        Node<T>* n = new Node<T>(key, value);
        //insert at the head of the linked list
        n->next = table[idx];
        table[idx]=n;
        current_size++;
        
        //Rehashing 
        float load_factor = current_size/(1.0*table_size);
        if(load_factor>0.7){
            //we have to do rehashing;
            rehash();
        }
    }
    void print(){
        for(int i=0; i<table_size; i++){
            cout<<"Bucket "<<i<<"->";
            Node<T>* head = table[i];
            while(head!=NULL){
                cout<<head->key<<" "<<"->";
                head = head->next;
            }
            cout<<endl;
        }
    }
    T* search(string key){
        int idx = hashfn(key);
        Node<T>* temp = table[idx];
        while(temp!=NULL){
            if(temp->key == key){
                return &temp->value;
            }
            temp = temp->next;
        }
        return NULL;
    }
    T& operator[](string key){
        T* f = search(key);
        if(f==NULL){
            T garbage;
            insert(key, garbage);
            f = search(key);
        }
        return *f;
    }
    void erase(string key){
        int idx = hashfn(key);
        Node<T>* temp = table[idx];
        Node<T>* prev = NULL;
        if(temp == NULL){
            return;
        }
        if(temp->next == NULL){
            if(temp->key == key){
                table[idx] = NULL;
                delete temp;
            }
            else{
                cout<<"Element not present"<<endl;
            }
        }
        else{
            while(temp->key!=key){
                prev = temp;
                temp = temp->next;
            }
            prev->next = temp->next;
            delete temp;
        }
        return;
    }
};

int main() {
	// implementing the hashtable
	Hashtable<int> price_table;
	price_table.insert("Burger", 100);
	price_table.insert("Pizza", 160);
	price_table.insert("Pepsi", 90);
	price_table.insert("Coke", 80);
	price_table.insert("Fries", 120);
	price_table.print();
	
	int* Burger = price_table.search("Burger");
	if(Burger == NULL){
	    cout<<"Not present"<<endl;
	}
	else{
	    cout<<"Burger "<<*Burger<<endl;
	}
	
// 	price_table.erase("Burger");
    price_table["Burger"]+=10;
    cout<<price_table["Burger"]<<endl;
	
	return 0;
}
