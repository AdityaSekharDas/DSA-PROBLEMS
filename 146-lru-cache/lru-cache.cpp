class LRUCache {
public:

    class Node {
        public:
        int key , val;
        Node* next;
        Node* prev;

        Node(int k , int v) {
            key = k;
            val = v;
            next = prev = nullptr;
        }
    };

    Node* head;
    Node* tail;
    int cap;
    unordered_map<int,Node*> mp;

    LRUCache(int capacity) {
        cap = capacity;

        head = new Node(-1,-1);
        tail = new Node(-1,-1);

        head->next = tail;
        tail->prev = head;
    }

    void addnode(Node* newnode) {
        Node* temp = head->next;
        newnode->next = temp;
        temp->prev = newnode;
        head->next = newnode;
        newnode->prev = head;
    }

    void delnode(Node* node) {
        Node* prevnode = node->prev;
        Node* afternode = node->next;
        prevnode->next = afternode;
        afternode->prev = prevnode;
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end()) return -1;
        Node* node = mp[key];
        int ans = node->val;
        delnode(node);
        addnode(node);
        mp[key] = head->next;
        return ans;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()) {
            Node* exi = mp[key];
            delnode(exi);
            mp.erase(key);
        }

        if(mp.size() == cap) {
            Node* lru = tail->prev;
            mp.erase(lru->key);
            delnode(lru);
        }

        Node* newnode = new Node(key,value);
        addnode(newnode);
        mp[key] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */