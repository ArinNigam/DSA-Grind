// mplement the RandomizedSet class:

// RandomizedSet() Initializes the RandomizedSet object.
// bool insert(int val) Inserts an item val into the set if not present. Returns true if the item was not present, false otherwise.
// bool remove(int val) Removes an item val from the set if present. Returns true if the item was present, false otherwise.
// int getRandom() Returns a random element from the current set of elements (it's guaranteed that at least one element exists when this method is called). Each element must have the same probability of being returned.
// You must implement the functions of the class such that each function works in average O(1) time complexity.

#include<bits/stdc++.h>
using namespace std;

class RandomizedSet {
    vector<int> v;
    unordered_map<int,int> mp;
public:
   
    RandomizedSet() {
    }

    bool search(int val){
         if(mp.find(val)!=mp.end())
            return true;
         return false;

    }

    
    bool insert(int val) {
        if(search(val))
            return false;
        v.push_back(val);
        mp[val] = v.size()-1;
        return true;
    }

    
    bool remove(int val) {
        if(!search(val))
            return false;

       
        auto it = mp.find(val);
        v[it->second] = v.back();
        v.pop_back();
        mp[v[it->second]] = it->second;
        mp.erase(val);
        return true;
    }

   
    int getRandom() {

        return v[rand()%v.size()];
    }
};

