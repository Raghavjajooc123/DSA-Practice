/*************************************************************

    Following is the Binary Tree node structure

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode < T > *left;
        BinaryTreeNode < T > *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/
void changeTree(BinaryTreeNode < int > * root) {
    if(root == NULL || (root->left==NULL && root->right==NULL)) return;
    int sum = 0;
    if(root->left!=NULL) sum+=root->left->data;
    if(root->right!=NULL) sum+=root->right->data;
    if(root->data <= sum) root->data = sum;
    else{
        if(root->left!=NULL) root->left->data = root->data;
        if(root->right!=NULL) root->right->data = root->data;
    }
    changeTree(root->left);
    changeTree(root->right);
    
    sum = 0;
    if(root->left!=NULL) sum+=root->left->data;
    if(root->right!=NULL) sum+=root->right->data;
    root->data = sum;
}  
