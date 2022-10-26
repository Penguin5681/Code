/*
Problem: Given an array nums of distinct integers, return
all the possible permutations. You can return
the answer in any order.
*/

#include <bits/stdc++.h>
#include <stdlib.h>
#include <vector>
using std::vector;

vector<vector<int>> ans;
void permute(vector<int> &a, int idx) {
    if (idx == a.size()) {
        ans.push_back(a);
        return;
    }
    for (int i = idx; i < a.size(); i++) {
        std::swap(a[i], a[idx]);
        permute(a, idx + 1);
        std::swap(a[i], a[idx]);
    }
    return;
}

signed main(void) {
    int n;
    std::cin >> n;

    vector<int> A(n);
    for (auto &i : A) {
        std::cin >> i;
    }
    permute(A, 0);
    for (auto v : ans) {
        for (auto i : v) {
            std::cout << i << " ";
        }
        std::cout << std::endl;
    }
}