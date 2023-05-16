#pragma once

#include "BinaryTreeInterface.h"
#include "BinaryNode.h"
#include "BinaryNodeTree.h"
#include "PrecondViolatedExcep.h"
template < class ItemType>
class BinarySearchTree : public BinaryNodeTree<ItemType>
{
    private:
    BinaryNode<ItemType>* rootPtr; 
    protected:
    //------------------------------------------------------------
    // Protected Utility Methods Section:
    // Recursive helper methods for the public methods.
    //------------------------------------------------------------
    // Recursively finds where the given node should be placed and
    // inserts it in a leaf at that point.
    BinaryNode<ItemType>* insertInorder(BinaryNode<ItemType>* subTreePtr, BinaryNode<ItemType>* newNode);
    // Removes the given target value from the tree while maintaining a
    // binary search tree.
    BinaryNode<ItemType>* removeValue(BinaryNode<ItemType>* subTreePtr, const ItemType target, bool& success);
    // Removes a given node from a tree while maintaining a
    // binary search tree.
    BinaryNode<ItemType>* removeNode(BinaryNode<ItemType>* nodePtr);
    // Removes the leftmost node in the left subtree of the node
    // pointed to by nodePtr.
    // Sets inorderSuccessor to the value in this node.
    // Returns a pointer to the revised subtree.
    BinaryNode<ItemType>* removeLeftmostNode(BinaryNode<ItemType>* subTreePtr, ItemType& inorderSuccessor);
    // Returns a pointer to the node containing the given value,
    // or nullptr if not found.
    BinaryNode<ItemType>* findNode(BinaryNode<ItemType>* treePtr, const ItemType& target, bool &success) const;
    public:
    //------------------------------------------------------------
    // Constructor and Destructor Section.
    //------------------------------------------------------------
    BinarySearchTree();
    BinarySearchTree(const ItemType& rootItem);
    BinarySearchTree(const BinarySearchTree<ItemType>& tree);
    virtual ~BinarySearchTree();
    //------------------------------------------------------------
    // Public Methods Section.
    //------------------------------------------------------------
    bool isEmpty() const;
    int getHeight() const;
    int getNumberOfNodes() const;
    ItemType getRootData() const;
    void setRootData(const ItemType& newData) const;
    bool add(const ItemType& newEntry);
    bool remove(const ItemType& anEntry);
    void clear();
    ItemType getEntry(const ItemType& anEntry) const;
    bool contains(const ItemType& anEntry) const;
    //------------------------------------------------------------
    // Public Traversals Section.
    //------------------------------------------------------------
    void preorderTraverse(void visit(ItemType&)) const;
    void inorderTraverse(void visit(ItemType&)) const;
    void postorderTraverse(void visit(ItemType&)) const;
    //------------------------------------------------------------
    // Overloaded Operator Section.
    //------------------------------------------------------------
    BinarySearchTree<ItemType>&operator=(const BinarySearchTree<ItemType>& rightHandSide);
}; // end BinarySearchTree
// Inserts a new item into the binary search tree to which subTreePtr points.
template < class ItemType>
BinaryNode<ItemType>* BinarySearchTree<ItemType>::insertInorder(BinaryNode<ItemType>* subTreePtr, BinaryNode<ItemType>* newNodePtr)
{
    BinaryNode<ItemType>*tempPtr;
    if (subTreePtr == nullptr)
        return newNodePtr;
    else if (subTreePtr->getItem() > newNodePtr->getItem())
    {
        tempPtr = insertInorder(subTreePtr->getLeftChildPtr(), newNodePtr);
        subTreePtr->setLeftChildPtr(tempPtr);
    }
    else
    {
        tempPtr = insertInorder(subTreePtr->getRightChildPtr(), newNodePtr);
        subTreePtr->setRightChildPtr(tempPtr);
    }
    return subTreePtr;
}
// Removes the target value from the tree by calling moveValuesUpTree
// to overwrite value with value from child.
// Codigo para BST
template < class ItemType>
BinaryNode<ItemType>*BinarySearchTree<ItemType>::removeValue(BinaryNode<ItemType>*subTreePtr, const ItemType target, bool& success)
{
    BinaryNode<ItemType> *tempPtr;
    if (subTreePtr == nullptr)
    {
        success = false; return nullptr;
    }
    else 
        if (subTreePtr->getItem() == target)
        {
        // Item is in the root of some subtree
            subTreePtr = removeNode(subTreePtr);
            // Remove the item
            success = true;
            return subTreePtr;
        }
        else
        if (subTreePtr->getItem() > target)
        {
        // Search the left subtree
            tempPtr = removeValue(subTreePtr->getLeftChildPtr(), target, success);
            subTreePtr->setLeftChildPtr(tempPtr);
            return subTreePtr;
        }
        else
        {
            // Search the right subtree
            tempPtr = removeValue(subTreePtr->getRightChildPtr(), target, success);
            subTreePtr->setRightChildPtr(tempPtr);
            return subTreePtr;
    }   
}

template < class ItemType>
BinaryNode<ItemType>* BinarySearchTree<ItemType>::removeNode(BinaryNode<ItemType> *nodePtr)
{
    BinaryNode<ItemType>*tempPtr = nullptr, *nodeToConnectPtr = nullptr;
    ItemType newNodeValue;
    //N is a leaf
        if (nodePtr->isLeaf())
        {
            //cout << "Es una hoja" << nodePtr->getItem() << endl;
            // Remove leaf from the tree
            delete nodePtr;
            nodePtr = nullptr;
            return nodePtr;
        }
        else
        if (nodePtr->isChild())
        {
            // C replaces N as the child of N’s parent
            if (nodePtr->getLeftChildPtr())
                nodeToConnectPtr = nodePtr->getLeftChildPtr();
            else
                nodeToConnectPtr = nodePtr->getRightChildPtr();
            delete nodePtr;
            nodePtr = nullptr;
            //cout << "Tiene un hijo" << nodeToConnectPtr->getItem() << endl;
            return nodeToConnectPtr;
        }
        else // N has two children
        {
        // Find the inorder successor of the entry in N: it is in the left subtree rooted
        // at N’s right child
            tempPtr = removeLeftmostNode(nodePtr->getRightChildPtr(), newNodeValue);
            cout << "Retorna el sucesor inorder " << newNodeValue << endl;
            nodePtr->setRightChildPtr(tempPtr);
            nodePtr->setItem(newNodeValue);// Put replacement value in node N
            cout << "Tiene dos hijos " << nodePtr->getItem() << endl;
            return nodePtr;
        }
}
template < class ItemType>
BinaryNode<ItemType>*
BinarySearchTree<ItemType>::removeLeftmostNode(BinaryNode<ItemType>*nodePtr, ItemType&inorderSuccesssor)
{
    if (nodePtr->getLeftChildPtr() == nullptr)
    {
        // This is the node you want; it has no left child, but it might have a right subtree
        inorderSuccesssor = nodePtr->getItem();
        return removeNode(nodePtr);
        }
    else
    {
        nodePtr->setLeftChildPtr(removeLeftmostNode(nodePtr->getLeftChildPtr(),
        inorderSuccesssor));
        return nodePtr;
    }
}

template < class ItemType>
BinaryNode<ItemType>* BinarySearchTree<ItemType>::findNode(BinaryNode<ItemType>*subTreePtr, const ItemType& target, bool& success) const
{
    if (subTreePtr == nullptr)
    {
        success = false;
        return nullptr; //No found
    }
    else
        if (subTreePtr->getItem() == target)
        {
            success = true;
            return subTreePtr;
        }
        else
            if (subTreePtr->getItem() > target)
            // Search left subtree
            return findNode(subTreePtr->getLeftChildPtr(), target, success);
            else
            // Search right subtree
            return findNode(subTreePtr->getRightChildPtr(), target, success);
        // Copies the tree rooted at treePtr and returns a pointer to
    // the copy.
}
template < class ItemType>
BinarySearchTree<ItemType>::BinarySearchTree() : rootPtr(nullptr)
{
}
template < class ItemType>
BinarySearchTree<ItemType>::BinarySearchTree(const ItemType& rootItem) //:BinaryNodeTree<ItemType>(rootItem)
{
    rootPtr = new BinaryNodeTree<ItemType>(rootPtr, nullptr, nullptr);
}
template < class ItemType>
BinarySearchTree<ItemType>::BinarySearchTree(const BinarySearchTree<ItemType>& treePtr)
{
    rootPtr = copyTree(treePtr->rootPtr);
}

template < class ItemType>
BinarySearchTree<ItemType>:: ~BinarySearchTree()
{
    this->destroyTree(rootPtr);
}
//------------------------------------------------------------
// Public Methods Section.
//------------------------------------------------------------
template < class ItemType>
bool BinarySearchTree<ItemType>::isEmpty() const
{
    return(rootPtr == nullptr);
}
template < class ItemType>
int BinarySearchTree<ItemType>::getHeight() const
{
    return this->getHeightHelper(rootPtr);
}
template < class ItemType>
int BinarySearchTree<ItemType>::getNumberOfNodes() const
{
    if (!isEmpty())
        return this->getNumberOfNodesHelper(rootPtr);
    else
        return 0;
}
template < class ItemType>
ItemType BinarySearchTree<ItemType>::getRootData() const //throw (PrecondViolatedExcep)
{
    if (isEmpty())
        throw PrecondViolatedExcep("TreeException:EmptyTree");
    return rootPtr->getItem();
}
template < class ItemType>
void BinarySearchTree<ItemType>::setRootData(const ItemType& newData) const //throw(PrecondViolatedExcep)
{
    if (!isEmpty())
        rootPtr->setItem(newData);
    else
        rootPtr = new BinaryNode<ItemType>(newData, nullptr, nullptr);
}
template < class ItemType>
bool BinarySearchTree<ItemType>::add(const ItemType& newEntry)
{
    BinaryNode<ItemType>* newNodePtr = new BinaryNode<ItemType>(newEntry);
    rootPtr = insertInorder(rootPtr, newNodePtr); //BST
    return true;
}
template < class ItemType>
bool BinarySearchTree<ItemType>::remove(const ItemType& anEntry)
{
    bool isSuccessful = false;
    rootPtr = removeValue(rootPtr, anEntry, isSuccessful);
    return isSuccessful;
}
template < class ItemType>
void BinarySearchTree<ItemType>::clear()
{
    this->destroyTree(rootPtr);
    rootPtr = nullptr;
}
template < class ItemType>
ItemType BinarySearchTree<ItemType>::getEntry(const ItemType& anEntry) const //throw(PrecondViolatedExcep)
{
    BinaryNode<ItemType> *tempTree = nullptr;
    bool isSuccessful = false;
    tempTree = findNode(rootPtr, anEntry, isSuccessful);
    if (!isSuccessful)
    {
        throw PrecondViolatedExcep("TreeException: Entry not found in tree!");
    }
    return (tempTree->getItem());
}
template < class ItemType>
bool BinarySearchTree<ItemType>::contains(const ItemType& anEntry) const
{
    BinaryNode<ItemType> *tempTree = nullptr;
    bool isSuccessful = false;
    tempTree = findNode(rootPtr, anEntry, isSuccessful);
    return isSuccessful;
}

//------------------------------------------------------------
// Public Traversals Section.
//------------------------------------------------------------
template < class ItemType>
void BinarySearchTree<ItemType>::preorderTraverse(void visit(ItemType&)) const
{
    this->preorder(visit, rootPtr);
}
template < class ItemType>
void BinarySearchTree<ItemType>::inorderTraverse(void visit(ItemType&)) const
{
    this->inorder(visit, rootPtr);
}
template < class ItemType>
void BinarySearchTree<ItemType>::postorderTraverse(void visit(ItemType&)) const
{
    this->postorder(visit, rootPtr);
}
//------------------------------------------------------------
// Overloaded Operator Section.
//------------------------------------------------------------
template <class ItemType>
BinarySearchTree<ItemType>&BinarySearchTree<ItemType>::operator=(const BinarySearchTree<ItemType>& rightHandSide)
{
    if (this != &rightHandSide)
    {
        this->destroyTree(rootPtr);
        rootPtr = this->copyTree(rightHandSide.rootPtr);
    }//end if
    return *this;
}