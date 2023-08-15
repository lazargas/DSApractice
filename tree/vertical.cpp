#include <vector>
#include <queue>
#include <map>
#include <set>
using namespace std;

template<typename T>
struct TreeNode {
    T data;
    TreeNode<T>* left;
    TreeNode<T>* right;
    TreeNode(T val) : data(val), left(nullptr), right(nullptr) {}
};

template<typename T>
vector<vector<T>> verticalOrderTraversal(TreeNode<T> *root) {
    if (root == nullptr)
        return {};

    queue<pair<TreeNode<T>*, pair<int, int>>> q;
    q.push({root, {0, 0}});
    map<int, map<int, multiset<T>>> m;

    while (!q.empty()) {
        auto curr = q.front();
        TreeNode<T>* currNode = curr.first;
        int ylevel = curr.second.first;
        int xlevel = curr.second.second;
        m[ylevel][xlevel].insert(currNode->data);
        q.pop();

        if (currNode->left) {
            q.push({currNode->left, {ylevel + 1, xlevel - 1}});
        }
        if (currNode->right) {
            q.push({currNode->right, {ylevel + 1, xlevel + 1}});
        }
    }

    // Prepare the result from the map
    vector<vector<T>> result;
    for (const auto& ylevelEntry : m) {
        vector<T> column;
        for (const auto& xlevelEntry : ylevelEntry.second) {
            for (const auto& value : xlevelEntry.second) {
                column.push_back(value);
            }
        }
        result.push_back(column);
    }

    return result;
}
