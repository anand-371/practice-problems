/*
Swappable Trees
Given two trees root0 and root1, return whether you can transform root0 into root1 by swapping any node's left and right subtrees any number of times.

Example 1
Input
Visualize
root0 = [1, [3, null, null], [4, [0, null, [2, null, null]], null]]
root1 = [1, [3, null, null], [4, [0, null, [2, null, null]], null]]
Output
true
*/
bool solve(Tree* X, Tree* Y) {
 if (X == Y) {
        return true;
    }
 
    return (X && Y) && (X->val == Y->val) &&
        ((solve(X->left, Y->left) && solve(X->right, Y->right)) ||
        (solve(X->right, Y->left) && solve(X->left, Y->right)));
}
