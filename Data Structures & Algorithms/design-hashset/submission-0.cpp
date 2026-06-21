class MyHashSet {
private:
    // Node for linked list chaining
    struct ListNode {
        int key;
        ListNode* next;
        ListNode(int k) : key(k), next(nullptr) {}
    };
    
    vector<ListNode*> buckets;
    int size = 10000;  // Number of buckets (can be tuned)
    
    // Hash function
    int getHash(int key) {
        return key % size;
    }
    
    // Find the node and its previous node for a given key in a bucket
    ListNode* findNode(ListNode* head, int key) {
        ListNode* curr = head;
        while (curr != nullptr) {
            if (curr->key == key) {
                return curr;
            }
            curr = curr->next;
        }
        return nullptr;
    }
    
public:
    MyHashSet() {
        buckets.resize(size, nullptr);
    }
    
    void add(int key) {
        int hash = getHash(key);
        ListNode* curr = buckets[hash];
        
        // Check if key already exists
        if (findNode(curr, key) != nullptr) {
            return;  // Already exists, do nothing
        }
        
        // Add to front of linked list
        ListNode* newNode = new ListNode(key);
        newNode->next = buckets[hash];
        buckets[hash] = newNode;
    }
    
    void remove(int key) {
        int hash = getHash(key);
        ListNode* curr = buckets[hash];
        
        if (curr == nullptr) return;
        
        // If head node contains the key
        if (curr->key == key) {
            buckets[hash] = curr->next;
            delete curr;
            return;
        }
        
        // Search in rest of the list
        while (curr->next != nullptr) {
            if (curr->next->key == key) {
                ListNode* toDelete = curr->next;
                curr->next = curr->next->next;
                delete toDelete;
                return;
            }
            curr = curr->next;
        }
    }
    
    bool contains(int key) {
        int hash = getHash(key);
        return findNode(buckets[hash], key) != nullptr;
    }
    
    // Destructor to free memory (optional but good practice)
    ~MyHashSet() {
        for (ListNode* head : buckets) {
            while (head != nullptr) {
                ListNode* temp = head;
                head = head->next;
                delete temp;
            }
        }
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */