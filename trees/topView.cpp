class Solution {
public:
    vector<int> topView(Node *root) {
        vector<int> result;
        if (!root) return result;

        // HD -> node value
        map<int, int> mp;

        // queue: node + horizontal distance
        queue<pair<Node*, int>> q;
        q.push({root, 0});

        while (!q.empty()) {
            auto it = q.front();
            q.pop();

            Node* node = it.first;
            int hd = it.second;

            // store only first node at each HD
            if (mp.find(hd) == mp.end()) {
                mp[hd] = node->data;
            }

            if (node->left) {
                q.push({node->left, hd - 1});
            }

            if (node->right) {
                q.push({node->right, hd + 1});
            }
        }

        // extract values in order
        for (auto it : mp) {
            result.push_back(it.second);
        }

        return result;
    }
};
