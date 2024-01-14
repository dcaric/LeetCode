//
//  main.cpp
//  RemoveDuplicates
//
//  Created by Dario Caric on 13/01/2024.
//

#include <iostream>
#include <vector>

using namespace std;

int removeDuplicates(vector<int>& nums) {
 
    vector<int> numslocal;
    
    numslocal.push_back(nums[0]);
    for (int i = 1; i<nums.size(); i++) {
        bool found = false;
        for (int j = 0; j<numslocal.size(); j++) {
            if (nums[i] == numslocal[j]) {
                found = true;
                break;
            }
        }
        if (!found)
            numslocal.push_back(nums[i]);
    }
    nums = numslocal;
    
    return int(numslocal.size());
}

int main() {
    
    vector<int> list = {1, 1, 2};
    int result = removeDuplicates(list);
    cout << "result:" << result << endl;
    
    
    return 0;
}
