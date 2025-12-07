#include <iostream>
#include <vector>

using namespace std;

class FenwickTree {
    int size;
    vector<int> tree;

public:
    FenwickTree(int n) : size(n), tree(n + 1, 0) {}
    
    void update(int i, int val) {
        while (i <= size) {
            tree[i] += val;
            i += i & (-i);  // Add LSB to jump to parent
        }
    }
    
    int query(int i) {
        int sum = 0;
        while (i > 0) {
            sum += tree[i];
            i -= i & (-i);  // Subtract LSB to jump to previous range
        }
        return sum;
    }
    
    int query(int L, int R) {
        return query(R) - query(L - 1);
    }
};

int main() {
    vector<int> nums = {1, 2, 3, 4, 5}; 
    int n = nums.size();

    FenwickTree ft(n);

    // Build the tree (Update one by one)
    // Note: Fenwick Tree is 1-indexed, so we use i+1
    for (int i = 0; i < n; i++) {
        ft.update(i + 1, nums[i]);
    }

    // Test 1: Sum of first 5 numbers (1+2+3+4+5 = 15)
    cout << "Sum of [1, 5]: " << ft.query(5) << endl;

    // Test 2: Range Sum of [2, 4] (2+3+4 = 9)
    // Formula: Query(4) - Query(1)
    cout << "Sum of [2, 4]: " << ft.query(2, 4) << endl;

    // Test 3: Update index 3 (Change '3' to '10')
    // Old value was 3, new is 10. Delta is +7.
    ft.update(3, 7); 
    cout << "After update, Sum of [1, 5]: " << ft.query(5) << endl; // Should be 22

    return 0;
}