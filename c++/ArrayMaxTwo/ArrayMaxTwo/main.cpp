//
//  main.cpp
//  ArrayMaxTwo
//
//  Created by Dario Caric on 14/01/2024.
//

#include <iostream>
#include <vector>

using namespace std;


int removeDuplicates(vector<int>& nums) {
 
    vector<int>numLocal;
    
    int oneNumCounter = 1;
    numLocal.push_back(nums[0]);
    int current = nums[0];
    for (int i = 1; i < nums.size(); i++) {
        if (current != nums[i]) {
            current = nums[i];
            oneNumCounter = 1;
            numLocal.push_back(nums[i]);
        } else if (current == nums[i] && oneNumCounter < 2) {
            oneNumCounter ++;
            numLocal.push_back(nums[i]);
        }
    }
    nums = numLocal;
    
    /*
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
    */
    
    return int(nums.size());
}

int main(int argc, const char * argv[]) {
    
    vector<int> list = {0,0,1,1,1,1,2,3,3};
    int result = removeDuplicates(list);
    cout << "result:" << result << endl;
    
    return 0;
}
