class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
    int n = prices.size();
    vector<int> answer(n, 0);
    stack<int> st; 
    for(int i = 0; i < n; ++i){
        while(!st.empty() && prices[i] <= prices[st.top()]){
            int idx = st.top();
            st.pop();
            answer[idx] = prices[idx] - prices[i];
        }
        st.push(i);
    }
    while(!st.empty()){
        int idx = st.top();
        st.pop();
        answer[idx] = prices[idx];
    }
    return answer;   
    }
};