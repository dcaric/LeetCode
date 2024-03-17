//
//  main.swift
//  JumpGame
//
//  Created by Dario Caric on 11.03.2024..
//

import Foundation


func canJump(_ nums: [Int]) -> Bool {
    var maxReach = 0
    for i in 0..<nums.count {
        if i > maxReach { return false } // If current index is beyond max reach, cannot proceed
        maxReach = max(maxReach, i + nums[i]) // Update max reach
        if maxReach >= nums.count - 1 { return true } // If max reach is at or beyond last index, can finish
    }
    return true // If loop completes without returning false, can reach last index
}

var nums: [Int] = [8,2,4,4,4,9,5,2,5,8,8,0,8,6,9,1,1,6,3,5,1,2,6,6,0,4,8,6,0,3,2,8,7,6,5,1,7,0,3,4,8,3,5,9,0,4,0,1,0,5,9,2,0,7,0,2,1,0,8,2,5,1,2,3,9,7,4,7,0,0,1,8,5,6,7,5,1,9,9,3,5,0,7,5]

print("can jump: \(canJump(nums))")



