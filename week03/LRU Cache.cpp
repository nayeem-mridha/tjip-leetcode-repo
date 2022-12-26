class LRUCache {
    public:
    list<int> lru;
    int max_cap;
    unordered_map<int, int> kv;
    unordered_map<int, list<int>::iterator> mp;

    LRUCache(int capacity) {
        max_cap = capacity;
    }

    int get(int key) {
        if (kv.count(key) == 0) return -1;
        updateLRU(key);
        return kv[key];
    }

    void put(int key, int value) {
        if (kv.size() == max_cap && kv.count(key) == 0) {
            evict();
        }
        updateLRU(key);
        kv[key] = value;
        return;
    }

    void updateLRU(int key) {
        if (kv.count(key)) {
            lru.erase(mp[key]);
        }
        lru.push_front(key);
        mp[key] = lru.begin();
    }

    void evict() {
        int last_key = lru.back();
        mp.erase(last_key);
        kv.erase(last_key);
        lru.pop_back();
    }
};
