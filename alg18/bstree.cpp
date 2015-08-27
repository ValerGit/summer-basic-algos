#include <bstree.h>

void BSTree::deleting(NodeBST* root)
{
    if(root == 0) return;
    deleting(root->left);
    deleting(root->right);
    delete root->left;
    delete root->right;
}

NodeBST* BSTree::addElement(NodeBST* root, int toAdd)
{
    if(head == 0)
    {
        NodeBST* temp = new NodeBST(toAdd);
        temp->subNodes = 0;
        head = temp;
        return 0;
    }
    if(root == 0)
    {
        NodeBST* temp = new NodeBST(toAdd);
        temp->subNodes = 0;
        return temp;
    }
    if(root->value <= toAdd) root->right = addElement(root->right, toAdd);
    else root->left = addElement (root->left, toAdd);
    root->subNodes +=1;
    return root;
}

void BSTree::calcHeight(NodeBST* root)
{
    if(root == 0) return;
    calcHeight(root->left);
    calcHeight(root->right);
    if(root->left && root->right)
        root->height = 1 + max(root->left->height, root->right->height);
    else{
        if(root->left) root->height = 1 + root->left->height;
        else if(root->right) root->height = 1 + root->right->height;
        else root->height = 1;
    }
    height = root->height;
}
