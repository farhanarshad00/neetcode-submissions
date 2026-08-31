class LRUCache {
private:
  struct Node{
        int key;
        int value;
        Node* prev;
        Node* next;
    };

    unordered_map<int,Node*> cache;
    Node* dummyHead;
    Node* dummyTail;
    int capacity;
    
  
    void removal(Node* node){
        node->prev->next=node->next;
        node->next->prev=node->prev;
    }
    void insertAtHead(Node* node){
        Node* oldFirst=dummyHead->next;
        dummyHead->next=node;
        node->prev=dummyHead;
        node->next=oldFirst;
        oldFirst->prev=node;
    }
public:
    LRUCache(int capacity) {
        this->capacity=capacity;
        dummyHead=new Node();
        dummyTail=new Node();
        dummyHead->next=dummyTail;
        dummyTail->prev=dummyHead;
        
        
    }
    
    int get(int key) {
        if(cache.find(key)==cache.end()){
            return -1;
        }else{
            Node* node = cache[key];
            removal(node);
            insertAtHead(node);
            return node->value;
        }

        
    }
    
    void put(int key, int value) {
        if(cache.find(key)!=cache.end()){
            Node* node = cache[key];
            node->value=value;
            removal(node);
            insertAtHead(node);
            
        }else if(cache.size()<capacity){
            Node* nu_node = new Node();
            nu_node->key=key;
            nu_node->value=value;
            insertAtHead(nu_node);
            cache.insert({key,nu_node});
        }else{
            Node* lru_node = dummyTail->prev;
            int old_key=lru_node->key;
            removal(lru_node);
            cache.erase(old_key);
            delete lru_node;
            Node* nu_node = new Node();
            nu_node->key=key;
            nu_node->value=value;
            insertAtHead(nu_node);
            cache.insert({key,nu_node});
            

        }
        
    }
};
