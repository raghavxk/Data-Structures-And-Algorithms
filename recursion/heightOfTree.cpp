int heightOfTree(int *root) {
    if (root == null)
        return 0;
    int lh = heightOfTree(root->left);
    int rh = heightOfTree(root->right);
    return max(lh, rh) + 1;
}
