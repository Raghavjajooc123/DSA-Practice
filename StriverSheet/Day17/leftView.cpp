void leftViewHelper(Node* root, int level, int& maxL, vector<int>& ans){
    if(root == NULL) return;
    if(level>maxL){
        ans.push_back(root->data);
        maxL = level;
    }
    leftViewHelper(root->left, level+1, maxL, ans);
    leftViewHelper(root->right, level+1, maxL, ans);
    return;
}
vector<int> leftView(Node *root)
{
   vector<int> ans;
   int maxL = 0;
   leftViewHelper(root, 1, maxL, ans);
   return ans;
}
