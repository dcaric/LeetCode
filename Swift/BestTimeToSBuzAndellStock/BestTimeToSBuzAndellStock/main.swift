//
//  main.swift
//  BestTimeToSBuzAndellStock
//
//  Created by Dario Caric on 23.01.2024..
//

import Foundation


func maxProfit(_ prices: [Int]) -> Int {
    
    guard !prices.isEmpty else { return 0 }

    var minPrice = prices[0]
    var maxProfit = 0

    for price in prices {
        if price < minPrice {
            minPrice = price
        } else if price - minPrice > maxProfit {
            maxProfit = price - minPrice
        }
    }

    return maxProfit
}

let prices = [7,1,5,3,6,4]
print("Maximum Profit:\(maxProfit(prices))")
