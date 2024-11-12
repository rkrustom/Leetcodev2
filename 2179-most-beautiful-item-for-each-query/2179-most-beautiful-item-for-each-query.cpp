class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
            // Step 1: Sort items by price, if same price, beauty doesn't matter in sorting
    sort(items.begin(), items.end());

    // Step 2: Prepare a price-beauty map with cumulative max beauty
   map<int, int> priceToBeauty;
    int maxBeauty = 0;
    for (const auto& item : items) {
        maxBeauty = max(maxBeauty, item[1]); // Get the max beauty up to this price
        priceToBeauty[item[0]] = maxBeauty;       // Map price to current max beauty
    }

    // Step 3: Sort queries while keeping track of original indices
   vector<pair<int, int>> sortedQueries;
    int qSize = queries.size();
    for (int i = 0; i < qSize; ++i) {
        sortedQueries.push_back({queries[i], i});
    }
    sort(sortedQueries.begin(), sortedQueries.end());

    // Step 4: Answer each query using the priceToBeauty map
    vector<int> answer(qSize);
    auto it = priceToBeauty.begin();
    for (const auto& query : sortedQueries) {
        int maxAffordableBeauty = 0;
        // Find the largest price <= query.first
        it = priceToBeauty.upper_bound(query.first);
        if (it != priceToBeauty.begin()) {
            --it; // move to the last valid price <= query.first
            maxAffordableBeauty = it->second;
        }
        answer[query.second] = maxAffordableBeauty;
    }

    return answer;

    }
};