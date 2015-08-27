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

int BSTree::calcHeight(NodeBST* root)
{
    if(root == 0) return 0;
    return 1 + max(calcHeight(root->left), calcHeight(root->right));
}
