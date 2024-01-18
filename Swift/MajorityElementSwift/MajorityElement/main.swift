//
//  main.swift
//  MajorityElement
//
//  Created by Dario Caric on 17.01.2024..
//

import Foundation

func updateDict(element: Int, _ dict: inout [Int:Int]) -> Void {
    
    if let currentValue = dict[element] {
        // If the key exists, increment its value
        print("found key:\(element)  value:\(currentValue)")
        dict[element] = currentValue + 1
    } else {
        // If the key does not exist, add it to the dictionary
        print("first time:\(element)")
        dict[element] = 1
    }
}


func majorityElement(_ nums: [Int]) -> Int {
    var dict: [Int : Int] = [:]
    for item in nums {
        print("find num:\(item)")
        updateDict(element: item, &dict)
    }
    
    var max = 0
    var num = 0
    for (key, value) in dict {
        print("key:\(key)  value\(value)")
        if (value > max) {
            num = key
            max = value
        }
    }
    
    return num
    
    
}


var nums: [Int] = [2,2,1,1,1,2,2,2]
print("max:\(majorityElement(nums))")
