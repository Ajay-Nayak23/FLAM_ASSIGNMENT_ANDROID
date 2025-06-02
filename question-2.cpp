#include <bits/stdc++.h>
using namespace std;

class MyHashMap
{
private:
    static const int SIZE = 1e6 + 1;
    int map[SIZE];

public:
    MyHashMap()
    {
        fill(map, map + SIZE, -1);
    }
    void put(int key, int value)
    {
        map[key] = value;
    }

    int get(int key)
    {
        return map[key];
    }

    void remove(int key)
    {
        map[key] = -1;
    }
};

int main()
{
    MyHashMap obj;
    obj.put(1, 10);
    obj.put(2, 20);
    cout << obj.get(1) << endl; // 10
    cout << obj.get(3) << endl; // -1 (not found)
    obj.put(2, 30);             // update key 2
    cout << obj.get(2) << endl; // 30
    obj.remove(2);
    cout << obj.get(2) << endl; // -1 (removed)
    return 0;
}
