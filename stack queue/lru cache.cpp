Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and put.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
put(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.

The cache is initialized with a positive capacity.


LRUCache cache = new LRUCache( 2 /* capacity */ );

cache.put(1, 1);
cache.put(2, 2);
cache.get(1);       // returns 1
cache.put(3, 3);    // evicts key 2
cache.get(2);       // returns -1 (not found)
cache.put(4, 4);    // evicts key 1
cache.get(1);       // returns -1 (not found)
cache.get(3);       // returns 3
cache.get(4);       // returns 4


class LRUCache {
public:
    
      list<pair<int,int>> cache;
        unordered_map<int,list<pair<int,int>>::iterator> mymap;  //Key, address in dequeue PAIR
        
        void refreshPosition(int key,int value)
        {
            cache.erase(mymap[key]);
            cache.push_front(make_pair(key,value));
            mymap[key] = cache.begin();     //Addr of new position stored in map
        }
    int capacity;
    LRUCache(int capacity) {
        this->capacity=capacity;
    }
    
    int get(int key) {
         if(mymap.find(key)!=mymap.end())
        {
            refreshPosition(key,(*mymap[key]).second);
            return (*mymap[key]).second;
        }
        return -1;
    }
    
    void put(int key, int value) {
               if(mymap.find(key)!=mymap.end())
            refreshPosition(key,value);
        else
        {
            //Add to cache
            cache.push_front(make_pair(key,value));
            mymap[key] = cache.begin();
            if(mymap.size()>capacity)
            {
                mymap.erase(cache.back().first);
                cache.pop_back();
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
