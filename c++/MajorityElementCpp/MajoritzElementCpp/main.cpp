//
//  main.cpp
//  MajoritzElementCpp
//
//  Created by Dario Caric on 18.01.2024..
//

#include <iostream>
#include <vector>
#include <map>

using namespace std;

void updateDict(int element, map<int, int> *dict) {
    // Check if the key exists in the map
    auto it = dict->find(element);
    
    if (it != dict->end()) {
        // If the key exists, increment its value
        cout << "Found key " << element << " with value: " << it->second << endl;
        it->second += 1;
    } else {
        // If the key does not exist, add it to the map with a value of 1
        cout << "First time for key: " << element << endl;
        (*dict)[element] = 1;
    }
}

int majorityElement(vector<int> nums) {
    
    //decleration of vector iterator
    vector<int>::iterator iter = nums.begin();
    
    map<int, int> dict;
    for(; iter < nums.end(); iter++){
        updateDict(*iter, &dict);
    }
    
    int max = 0;
    int result = 0;
    map<int, int>::iterator it = dict.begin();
    for (; it != dict.end(); ++it) {
        cout << "Key: " << it->first << " Value: " << it->second << endl;
        if (it->second > max) {
            max = it->second;
            result = it->first;
        }
    }
    
    return result;
    
}

int main(int argc, const char * argv[]) {
    
    vector<int> nums = {2,2,1,1,1,2,2,2};
    cout << "Max: " << majorityElement(nums) << endl;
    
    return 0;
}
