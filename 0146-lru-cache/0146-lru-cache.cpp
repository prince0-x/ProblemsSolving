/*
class LRUCache {
private:
    vector<pair<int, int>>cache;
    int capacity;
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        for(int i=0;i<cache.size();i++){
            if(cache[i].first==key)
            {
                pair<int,int>temp=cache[i];
                cache.erase(cache.begin() + i);
                cache.push_back(temp);
                return temp.second;
            }
        }
        return -1;
    }
    
    void put(int key, int value) {
        for (int i = 0; i < cache.size(); i++) {
            if (cache[i].first == key) {
                cache.erase(cache.begin() + i);
                cache.push_back({key, value});
                return;
            }
        }

        if (cache.size() == capacity) {
            cache.erase(cache.begin());
        }

        cache.push_back({key, value});
    }
};
*/

// using dll

class Node {
public:
    int key;
    int val;
    Node* prev;
    Node* next;

    Node(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr) {}
};

class LRUCache {
private:
    int capacity;
    unordered_map<int, Node*>cache;
    Node*left;
    Node*right;
    void remove(Node*head){
        Node *pre = head->prev;
        Node *nextt = head->next;
        pre->next = nextt;
        nextt->prev= pre;

    }
    void insert(Node *head){
        Node* pre = right->prev;
        pre->next = head;
        head->prev = pre;
        head->next = right;
        right->prev = head;
    }
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        
        cache.clear();
        left = new Node(0, 0);
        right = new Node(0, 0);
        left->next = right;
        right->prev = left;
    }
    
    int get(int key) {
        if (cache.find(key) != cache.end()) {
            Node* node = cache[key];
            remove(node);
            insert(node);
            return node->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            remove(cache[key]);
        }
        Node* newNode = new Node(key, value);
        cache[key] = newNode;
        insert(newNode);

        if (cache.size() > capacity) {
            Node* lru = left->next;
            remove(lru);
            cache.erase(lru->key);
            delete lru;
        }
    }
};

