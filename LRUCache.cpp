
class LRUCache{

struct Node {
    Node *prev, *next;
    int key, val;
    Node(Node* pre, Node* nxt, int k, int v) : prev(pre), next(nxt), key(k), val(v) {}
    Node(int k, int v) : prev(NULL), next(NULL), key(k), val(v) {}
};

public:
    int bucket, size;
    map<int, Node*> table;
    Node *head, *tail;

    LRUCache(int capacity) {
        bucket = capacity;
        size = capacity;
        table.clear();
        head = NULL;
        tail = NULL;
    }
    
    void removeNode(int key) {
        if (table.find(key) == table.end()) { return; }

        Node* cur = table[key];
        table.erase(key);

        if (cur->prev) { 
            cur->prev->next = cur->next; 
        } else {
            head = cur->next; 
            if (head) { head->prev = NULL; }
        }

        if (cur->next) { 
            cur->next->prev = cur->prev; 
        } else { 
            tail = cur->prev; 
            if (tail) { tail->next = NULL; }
        }

        ++bucket;
        delete cur;
    }

    void insertNode(int key, int value) {
        Node* tmp = new Node(key, value);
        
        if (head) {
            tmp->next = head;
            head->prev = tmp;
        }
        head = tmp;
        if (!tail) { tail = tmp; }
        table[key] = tmp;
        if (bucket > 0) { --bucket; }
    }

    void accessNode(int key) {
        int value = table[key]->val;
        removeNode(key);
        insertNode(key, value);
    }

    int get(int key) {
        if (table.find(key) != table.end()) {
            accessNode(key);
            return table[key]->val;
        }
        return -1;
    }
    
    void set(int key, int value) {
        if (size == 0) { return; } // do nothing if size is 0
        
        removeNode(key);
        if (bucket == 0 && tail) {
            removeNode(tail->key);
        }
        
        insertNode(key, value);
    }
};