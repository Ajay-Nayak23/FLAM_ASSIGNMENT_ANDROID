# LRU Cache Implementation and MyHashMap (question-1 and question-2)

## Description

This project implements a Least Recently Used (LRU) Cache using a combination of a doubly linked list and an unordered map (hash map) in C++. The LRU Cache supports constant time operations for both `get` and `put`.

## Features

- **`get(key)`**: Returns the value associated with the key if present in the cache; otherwise, returns `-1`.
- **`put(key, value)`**: Inserts or updates the value for the key. If the cache reaches its capacity, it removes the least recently used item before inserting a new one.

## Implementation Details

- Uses a doubly linked list to maintain the usage order of items.
- Uses a hash map to provide O(1) access to cache entries.
- Dummy head and tail nodes simplify insertion and deletion logic.

## Sample Usage

```cpp
LRUCache lru(2);
lru.put(1, 1);
lru.put(2, 2);
cout << lru.get(1) << endl; // returns 1
lru.put(3, 3);              // evicts key 2
cout << lru.get(2) << endl; // returns -1
lru.put(4, 4);              // evicts key 1
cout << lru.get(1) << endl; // returns -1
cout << lru.get(3) << endl; // returns 3
cout << lru.get(4) << endl; // returns 4

How to Compile and Run
g++ -o lru_cache lru_cache.cpp
./lru_cache

Complexity
Time: O(1) for both get and put

Space: O(capacity)


---

### Question 2: **MyHashMap**

```markdown
# MyHashMap Implementation

## Description

This project implements a simple fixed-size hash map in C++ using an array. It supports basic operations like insertion, retrieval, and deletion.

## Features

- **`put(key, value)`**: Inserts a key-value pair into the map.
- **`get(key)`**: Returns the value for the given key if present; otherwise, returns `-1`.
- **`remove(key)`**: Removes the key-value pair from the map.

## Implementation Details

- Uses a fixed-size array (`int map[1000001]`) to simulate hash behavior.
- All values are initialized to `-1` to signify empty slots.
- Supports keys from 0 to 1e6 (inclusive).

## Sample Usage

```cpp
MyHashMap obj;
obj.put(1, 10);
obj.put(2, 20);
cout << obj.get(1) << endl; // 10
cout << obj.get(3) << endl; // -1
obj.put(2, 30);
cout << obj.get(2) << endl; // 30
obj.remove(2);
cout << obj.get(2) << endl; // -1

How to Compile and Run

g++ -o my_hash_map my_hash_map.cpp
./my_hash_map

Complexity
Time: O(1) for all operations (put, get, remove)

Space: O(1e6)




