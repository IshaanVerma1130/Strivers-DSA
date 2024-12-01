#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class StockSpanner {
    stack<pair<int, int>> span;
    int index = -1;

   public:
    StockSpanner() {
        index = -1;
        span = stack<pair<int, int>>();
    }

    int next(int val) {
        index++;
        while (!span.empty() && val >= span.top().first) {
            span.pop();
        }
        int ans = index - (span.empty() ? -1 : span.top().second);
        span.push({val, index});
        return ans;
    }
};