class FenwickTree {
    vector<int> tree;
    int n;
public:
    FenwickTree(int size) : n(size), tree(size + 1, 0) {}

    void update(int index, int delta) {
        index++;
        while (index <= n) {
            tree[index] += delta;
            index += index & -index;
        }
    }

    int query(int index) {
        index++;
        int result = 0;
        while (index > 0) {
            result += tree[index];
            index -= index & -index;
        }
        return result;
    }

    int queryRange(int left, int right) {
        return query(right) - query(left - 1);
    }
};

class Solution {
public:
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int> pos2(n);
        for (int i = 0; i < n; ++i)
            pos2[nums2[i]] = i;

        vector<int> pos(n);
        for (int i = 0; i < n; ++i)
            pos[i] = pos2[nums1[i]];

        FenwickTree bitLeft(n), bitRight(n);
        vector<int> leftCount(n, 0), rightCount(n, 0);

        for (int i = 0; i < n; ++i) {
            leftCount[i] = bitLeft.query(pos[i] - 1);
            bitLeft.update(pos[i], 1);
        }

        bitRight = FenwickTree(n);
        for (int i = n - 1; i >= 0; --i) {
            rightCount[i] = bitRight.query(n - 1) - bitRight.query(pos[i]);
            bitRight.update(pos[i], 1);
        }

        long long result = 0;
        for (int i = 0; i < n; ++i)
            result += (long long)leftCount[i] * rightCount[i];

        return result;
    }
};
