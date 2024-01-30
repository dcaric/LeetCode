//
//  main.cpp
//  BestTimeToSBuzAndellStock
//
//  Created by Dario Caric on 23.01.2024..
//

#include <iostream>
#include <vector>

using namespace std;

int maxProfit(vector<int>& prices) {
    if (prices.size() == 0) return 0;
    
    int min = prices[0];
    int maxProfit = 0;
    
    
    for (int i = 1; i<prices.size(); i++) {
        if (prices[i] < min) min = prices[i];
        else if (prices[i] - min > maxProfit) {
            maxProfit = prices[i] - min;
        }
    }
    
    
    return maxProfit;
}


int main(int argc, const char * argv[]) {
    
    vector<int> prices = {7,1,5,3,6,4};
    cout << "Maximum Profit: " << maxProfit(prices) << endl;

    return 0;
}
