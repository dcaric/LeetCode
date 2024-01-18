//
//  main.swift
//  RotateArray
//
//  Created by Dario Caric on 18.01.2024..
//

import Foundation


func rotate(_ nums: inout [Int], _ k: Int) {
    var kk = k
    if (kk > nums.count) {
        kk = kk % nums.count;
    }
    if ( kk <= 0 || nums.count == 1 || k == nums.count){
        return
    }

    for (index, element) in nums.enumerated() {
        print("element:\(element)")
    }
    var numsLocal: [Int] = []
    print("nums.cont:\(nums.count)")

    for i in nums.count-kk...nums.count-1 {
        print("1 i:\(i)")
        numsLocal.append(nums[i])
    }
    
    for i in 0...nums.count - kk-1 {
        print("2 i:\(i)")
        numsLocal.append(nums[i])
    }
}


var nums = [1,2]
let k = 2

rotate(&nums, k)
for item in nums {
    print("\(item)")
}


