#ifndef __NOTE_HASH_MAP_H__
#define __NOTE_HASH_MAP_H__

#include <map>

namespace Note {

class MyHashMap {
    public:
        static int generateBucket(int key) {
            return key % 1000;
        }
        /** Initialize your data structure here. */
        MyHashMap() {
            m_hashMap.clear();
        }

        /** value will always be positive. */
        void put(int key, int value) {
            int bucket = generateBucket(key);
            auto& kv = m_hashMap[bucket];
            kv[key] = value;
        }

        /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
        int get(int key) {
            int bucket = generateBucket(key);
            auto it = m_hashMap.find(bucket);
            if (it == m_hashMap.end()) {
                return -1;
            }
            auto itFind = it->second.find(key);
            if (itFind == it->second.end()) {
                return -1;
            }
            return itFind->second;
        }

        /** Removes the mapping of the specified value key if this map contains a mapping for the key */
        void remove(int key) {
            int bucket = generateBucket(key);
            auto it = m_hashMap.find(bucket);
            if (it == m_hashMap.end()) {
                return;
            }
            auto itFind = it->second.find(key);
            if (itFind == it->second.end()) {
                return;
            }
            it->second.erase(itFind);
            return;
        }
    private:
        std::map<int, std::map<int, int> > m_hashMap;
};

}

#endif
