#include <iostream>
#include <vector>
#include <string>
#include <sstream>

struct Treenode {
    int val;
    Treenode* left;
    Treenode* right;

    Treenode(int x): val(x), left(nullptr), right(nullptr) {

    }
};

Treenode* buildtree(std::vector<int>& treenums, int index) {
    //终止条件
    if (index >= treenums.size() || treenums[index] == -1) {
        return nullptr;
    }
    //单层遍历
    Treenode* root = new Treenode(treenums[index]);
    root -> left = buildtree(treenums, 2*index + 1);
    root -> right = buildtree(treenums, 2*index + 2);
    return root;
}

int calculatetime(Treenode* root) {
    if (root == nullptr) return 0;

    int lefttime = calculatetime(root -> left);
    int righttime = calculatetime(root -> right);
    int maxtime = std::max(lefttime, righttime);
    int total = root -> val + maxtime;
    return total;
}

int main() {
    std::vector<int> treenums;
    std::string line;
    std::getline(std::cin, line);
    std::stringstream ss(line);
    int num;
    while (ss >> num) {
        treenums.push_back(num);
    }
    //构建二叉树
    Treenode* root = buildtree(treenums , 0);
    //深搜二叉树
    int time = calculatetime(root);
    std::cout << time << std::endl;
    return 0;
}