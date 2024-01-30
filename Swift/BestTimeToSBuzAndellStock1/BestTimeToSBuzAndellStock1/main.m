//
//  main.m
//  BestTimeToSBuzAndellStock1
//
//  Created by Dario Caric on 23.01.2024..
//

#import <Foundation/Foundation.h>

// CLASS BEGIN
@interface StockAnalyzer : NSObject
- (NSInteger)maxProfit:(NSArray *)prices;
@end

@implementation StockAnalyzer

- (NSInteger)maxProfit:(NSArray *)prices {
    if (prices.count == 0) return 0;

    NSInteger minPrice = [prices[0] integerValue];
    NSInteger maxProfit = 0;

    for (NSNumber *price in prices) {
        NSInteger priceValue = [price integerValue];
        if (priceValue < minPrice) {
            minPrice = priceValue;
        } else if (priceValue - minPrice > maxProfit) {
            maxProfit = priceValue - minPrice;
        }
    }

    return maxProfit;
}

@end
// CLASS END

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        StockAnalyzer *analyzer = [[StockAnalyzer alloc] init];
        NSArray *prices = @[@7, @1, @5, @3, @6, @4];
        NSInteger profit = [analyzer maxProfit:prices];
        NSLog(@"Maximum Profit: %ld", (long)profit);
    }
    return 0;
}
