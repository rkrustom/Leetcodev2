class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
                int t_b = numBottles;

        while (numBottles >= numExchange) {
            t_b += numBottles / numExchange;
            numBottles = (numBottles / numExchange) + (numBottles % numExchange);
        }

        return t_b;

    }
};