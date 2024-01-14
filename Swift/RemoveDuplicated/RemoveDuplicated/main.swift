//
//  main.swift
//  RemoveDuplicated
//
//  Created by Dario Caric on 13/01/2024.
//

import Foundation

var list: [Int] = [0,0,1,1,1,2,2,3,3,4]

func removeDuplicates(_ nums: inout [Int]) -> Int {

    var numsLocal = [Int]()
    
    numsLocal.append(nums[0])

    for item in nums {
        if (!numsLocal.contains(item)) {
            numsLocal.append(item)
        }
    }
    nums = numsLocal
        
    return nums.count
    
}

let result = removeDuplicates(&list)
print("result:\(result)")
