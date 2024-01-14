//
//  main.swift
//  ArrayMaxTwo
//
//  Created by Dario Caric on 14/01/2024.
//

import Foundation

func removeDuplicates(_ nums: inout [Int]) -> Int {
    var numsLocal = [Int]()
    
    var currentNum : Int?
    var oneNumCounter: Int  = 0
    
    for item in nums {
        if (currentNum != item) {
            currentNum = item
            oneNumCounter = 1
            numsLocal.append(item)
        } else if(currentNum == item && oneNumCounter < 2) {
            oneNumCounter += 1
            numsLocal.append(item)
        }
    }
    
    nums = numsLocal
    
    for item in nums {
        print("\(item)")
    }
    
    return nums.count
}

var list : [Int] = [1]

var result = removeDuplicates(&list)
print("result:\(result)")

