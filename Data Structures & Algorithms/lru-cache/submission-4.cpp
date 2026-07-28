class LRUCache {
public:

    int capacity;
    list<pair<int, int>> List;
    unordered_map<int, list<pair<int,int>>::iterator> cache_map;

    LRUCache(int capacity) {
        this->capacity = capacity;
        
    }
    
    int get(int key) {
        auto it = cache_map.find(key);
        
        //  not found case
        if(it == cache_map.end()){
            return -1;
        }

        // move the node that was just accessed to the front
        int value = it->second->second;
        List.erase(it->second);
        List.push_front({key, value});
        
        // update the iterator
        cache_map[key] = List.begin();
        return value;

    }
    
    void put(int key, int value) {
        auto it = cache_map.find(key);

        // update case, remove the old node
        if(it != cache_map.end()){
            List.erase(it->second);
            cache_map.erase(it);
        }

        // insert the new node
        List.push_front({key, value});
        cache_map[key] = List.begin();

        // check the capacity
        if(cache_map.size() > capacity){
            auto last_node = List.back().first;
            List.pop_back();
            cache_map.erase(last_node);
        }

        
    }
};
