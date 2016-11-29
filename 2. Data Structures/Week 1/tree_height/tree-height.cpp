#include <iostream>
#include <vector>
#include <algorithm>

class TreeHeight {
    int n;
    std::vector<int> parent;

public:
    void read() {
        std::cin >> n;
        parent.resize(n);
        for (int i = 0; i < n; i++)
            std::cin >> parent[i];
    }

    // This function fills depth of i'th element in parent[].  The depth is
    // filled in depth[i].
    // http://www.geeksforgeeks.org/find-height-binary-tree-represented-parent-array/
    void fillDepth(int parent[], int i, int depth[]) {
        // If depth[i] is already filled
        if (depth[i])
            return;

        // If node at index i is root
        if (parent[i] == -1) {
            depth[i] = 1;
            return;
        }

        // If depth of parent is not evaluated before, then evaluate
        // depth of parent first
        if (depth[parent[i]] == 0)
            fillDepth(parent, parent[i], depth);

        // Depth of this node is depth of parent plus 1
        depth[i] = depth[parent[i]] + 1;
    }

    int compute_height() {
        // Replace this code with a faster implementation
//    int maxHeight = 0;
//    for (int vertex = 0; vertex < n; vertex++) {
//      int height = 0;
//      for (int i = vertex; i != -1; i = parent[i])
//        height++;
//      maxHeight = std::max(maxHeight, height);
//    }
//    return maxHeight;

        int depth[n];
        for (int i = 0; i < n; i++)
            depth[i] = 0;

        // fill depth of all nodes
        for (int i = 0; i < n; i++)
            fillDepth(&parent[0], i, depth);

        // The height of binary tree is maximum of all depths.
        // Find the maximum value in depth[] and assign it to ht.
        int ht = depth[0];
        for (int i = 1; i < n; i++)
            if (ht < depth[i])
                ht = depth[i];
        return ht;
    }
};

int main() {
    std::ios_base::sync_with_stdio(0);
    TreeHeight tree;
    tree.read();
    std::cout << tree.compute_height() << std::endl;
}
