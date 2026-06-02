#include <iostream>

using namespace std;

class RandomizedSet {
private:

    unordered_map<int,int>hash;
    vector<int>data;
public:

    RandomizedSet() {

    }
    

    bool insert(int val) {
      
        if(hash.count(val))
            return false;
        data.push_back(val);
        hash[val] = data.size()-1;
        return true;
    }
   
    bool remove(int val) {
    
        if(!hash.count(val))
            return false;

        int index1 = hash[val];
        int val2 = data.back();
        data[index1] = val2;
        hash[val2] = index1;

        data.pop_back();
        hash.erase(val);

        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {

        return data[rand()%data.size()];
    }
};