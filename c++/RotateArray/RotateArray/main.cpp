//
//  main.cpp
//  RotateArray
//
//  Created by Dario Caric on 18.01.2024..
//

#include <iostream>
#include <vector>

using namespace std;

void rotate(vector<int>& nums, int k) {
    if (k > nums.size()) k = k % nums.size();
    cout << "k:" << k << endl;
    
    if ( k > 0 && nums.size() > 1 && nums.size() != k){

        vector<int> numsLocal;
        
        for (int i = nums.size()-k; i <=nums.size()-1; i++) {
            numsLocal.push_back(nums[i]);
        }
        
        for (int i = 0; i<=nums.size()-k-1; i++) {
            numsLocal.push_back(nums[i]);
        }
        
        nums = numsLocal;
    }
}

int main(int argc, const char * argv[]) {
    
    vector<int>nums = {1,2};
    int k = 3;
    
    rotate(nums, k);
    for (int i = 0; i<nums.size(); i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
    return 0;
}
