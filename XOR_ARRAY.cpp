#include <bits/stdc++.h>
using namespace std;


vector<int> generateArray(int n, int L, int R) {
    // 1. Create the Prefix XOR array (P)
    // We strictly use distinct consecutive integers to start.
    // This ensures no accidental zero-sum ranges appear elsewhere.
    vector<int> P(n);
    int start_val = 500000; // Large enough buffer to be safe
    for(int i = 0; i < n; i++) {
        P[i] = start_val + i;
    }

    // 2. Enforce the Zero-Sum Condition for Range [L, R]
    // The rule: RangeXOR(L, R) = P[R] ^ P[L-1]
    
    if (L == 0) {
        // Special Case: If the range starts at 0, P[R] must be 0
        // because RangeXOR(0, R) is just P[R].
        P[R] = 0;
    } else {
        // Standard Case: We need P[R] ^ P[L-1] == 0
        // So we force P[R] to be a duplicate of P[L-1].
        P[R] = P[L - 1];
    }

    // 3. Construct the actual array A from P
    // Formula: A[i] = P[i] ^ P[i-1]
    vector<int> A(n);
    A[0] = P[0]; // Base case
    for(int i = 1; i < n; i++) {
        A[i] = P[i] ^ P[i - 1];
    }

    return A;
}


int main() {
    int T;
    cin>>T;
    while(T--)
    {
        int n,L,R;
        cin>>n;
        cin>>L;
        cin>>R;
        vector<int> ans = generateArray(n,L-1,R-1);
        for(int i=0;i<n;i++)
        {
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
    
}