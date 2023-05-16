#ifndef _BINARY_NODE_TREE
#define _BINARY_NODE_TREE
#include<iostream>
#include<string>
using namespace::std;
#include "BinaryTreeInterface.h"
#include "BinaryNode.h"
#include "PrecondViolatedExcep.h"
typedef void(*FunctionType) (int anItem);
template < class ItemType>
class BinaryNodeTree : public BinaryTreeInterface< ItemType >
{
    private:
        BinaryNode<ItemType>*rootPtr;
    protected:
    //------------------------------------------------------------
    // Protected Utility Methods Section:
    // Recursive helper methods for the public methods.
    //------------------------------------------------------------
        int max(int a, int b) const;
        int getHeightHelper(BinaryNode<ItemType>* subTreePtr) const;
        int getNumberOfNodesHelper(BinaryNode<ItemType>* subTreePtr) const;
        // Recursively deletes all nodes from the tree.
        void destroyTree(BinaryNode<ItemType>* subTreePtr);
        // Recursively adds a new node to the tree in a left/right fashion to
        // keep the tree balanced.
        BinaryNode<ItemType>*balancedAdd(BinaryNode<ItemType>*subTreePtr,BinaryNode<ItemType>* newNodePtr);
        // Removes the target value from the tree by calling moveValuesUpTree
        // to overwrite value with value from child.
        BinaryNode<ItemType>*removeValue(BinaryNode<ItemType>*subTreePtr, const ItemType target, bool &success);
        // Copies values up the tree to overwrite value in current node until
        // a leaf is reached; the leaf is then removed, since its value is
        // stored in the parent.
        BinaryNode<ItemType>*moveValuesUpTree(BinaryNode<ItemType>*subTreePtr);
        //BinaryNode<ItemType>* BinaryNodeTree<ItemType>::removeLeftmostNode(BinaryNode<ItemType>*nodePtr, const ItemType& inorderSuccesssor);
        // Recursively searches for target value in the tree by using a
        // preorder traversal.
        BinaryNode<ItemType>* find(BinaryNode<ItemType> *aTree, const ItemType &findItem, bool &success) const;
        // Copies the tree rooted at treePtr and returns a pointer to
        // the copy.
        BinaryNode<ItemType>*copyTree(const BinaryNode<ItemType>* treePtr) const;
        // Recursive traversal helper methods:
        void preorder(void visit(ItemType&), BinaryNode<ItemType>* treePtr) const;
        void inorder(void visit(ItemType&), BinaryNode<ItemType>* treePtr) const;
        void postorder(void visit(ItemType&), BinaryNode<ItemType>* treePtr) const;
    public:
    //------------------------------------------------------------
    // Constructor and Destructor Section.
    //------------------------------------------------------------
        BinaryNodeTree();
        BinaryNodeTree(const ItemType& rootItem);
        BinaryNodeTree(const ItemType& rootItem, const BinaryNodeTree<ItemType>*leftTreePtr, const BinaryNodeTree<ItemType> *rightTreePtr);
        BinaryNodeTree(const BinaryNodeTree<ItemType>* tree);
        BinaryNodeTree(const BinaryNode<ItemType>* tree);
        ~BinaryNodeTree();
    //------------------------------------------------------------
    // Public BinaryTreeInterface Methods Section.
    //------------------------------------------------------------
        bool isEmpty() const;
        int getHeight() const;
        int getNumberOfNodes() const;
        ItemType getRootData() const;
        void setRootData(const ItemType& newData);
        bool add(const ItemType& newData); // Adds a node
        bool remove(const ItemType& data); // Removes a node
        void clear();
        ItemType getEntry(const ItemType& anEntry) const;
        bool contains(const ItemType& anEntry) const;
        //------------------------------------------------------------------------
        void attachLeft(const ItemType& anEntry) const;
        void attachRight(const ItemType& anEntry) const;
        void attachLeftSubtree(BinaryNodeTree<ItemType>* lefTreePtr) const;
        void attachRightSubtree(BinaryNodeTree<ItemType>* rightTreePtr) const;
        BinaryNodeTree<ItemType> detachLeftSubtree() const;
        BinaryNodeTree<ItemType> detachRightSubtree() const;
        BinaryNodeTree<ItemType> getLeftSubtree() const;
        BinaryNodeTree<ItemType> getRightSubtree() const;
    //------------------------------------------------------------
    // Public Traversals Section.
    //------------------------------------------------------------
        void preorderTraverse(void visit(ItemType&)) const;
        void inorderTraverse(void visit(ItemType&)) const;
        void postorderTraverse(void visit(ItemType&)) const;
    //------------------------------------------------------------
    // Overloaded Operator Section.
    //------------------------------------------------------------
        BinaryNodeTree<ItemType>& operator=(const BinaryNodeTree<ItemType>&rightHandSide);
}; // end BinaryNodeTree
template < class ItemType>
int BinaryNodeTree<ItemType>::max(int a, int b) const
{
    int heightest;
    if (a > b)
        heightest = a;
    else
        heightest = b;
    return heightest;
}
template < class ItemType>
int BinaryNodeTree<ItemType>::getHeightHelper(BinaryNode<ItemType>* subTreePtr) const
{
    if (subTreePtr == nullptr)
        return 0;
    else
        return 1 + max(getHeightHelper(subTreePtr->getLeftChildPtr()),
    getHeightHelper(subTreePtr->getRightChildPtr()));
} // end getHeightHelper
template < class ItemType>
int BinaryNodeTree<ItemType>::getNumberOfNodesHelper(BinaryNode<ItemType>* subTreePtr) const
{
    { if (subTreePtr == nullptr)
        return 0;
    else
        return 1 + getNumberOfNodesHelper(subTreePtr->getLeftChildPtr()) + getNumberOfNodesHelper(subTreePtr->getRightChildPtr());
    } // end numNodes
}
// Recursively deletes all nodes from the tree.
template < class ItemType>
void BinaryNodeTree<ItemType>::destroyTree(BinaryNode<ItemType>* subTreePtr)
{
    if (subTreePtr != nullptr)
    {
        destroyTree(subTreePtr->getLeftChildPtr());
        destroyTree(subTreePtr->getRightChildPtr());
        delete subTreePtr;
        subTreePtr = nullptr;
    } // end if
} // end destroyTree
// Recursively adds a new node to the tree in a left/right fashion to
// keep the tree balanced.
template < class ItemType>
BinaryNode<ItemType>* BinaryNodeTree<ItemType>::balancedAdd(BinaryNode<ItemType>* subTreePtr, BinaryNode<ItemType>* newNodePtr)
{
    if (subTreePtr == nullptr)
        return newNodePtr;
    else
    {
        BinaryNode<ItemType>* leftPtr = subTreePtr->getLeftChildPtr();
        BinaryNode<ItemType>* rightPtr = subTreePtr->getRightChildPtr();
        if (getHeightHelper(leftPtr) > getHeightHelper(rightPtr))
        {
            rightPtr = balancedAdd(rightPtr, newNodePtr);
            subTreePtr->setRightChildPtr(rightPtr);
        }
        else
        {
            leftPtr = balancedAdd(leftPtr, newNodePtr);
            subTreePtr->setLeftChildPtr(leftPtr);
        } // end if
    return subTreePtr;
    } // end if
} // end balancedAdd
/** Depth-first search of tree for item.
@param subTreePtr tree to search.
@param target target item to find.
@param success communicate to client we found it.
@returns A pointer to node containing the item. */
template<class ItemType>
BinaryNode<ItemType>*
BinaryNodeTree<ItemType>::removeValue(BinaryNode<ItemType>*subTreePtr, const ItemType target, bool& success)
{
    if (subTreePtr == nullptr) // not found here
        return subTreePtr;
    if (subTreePtr->getItem() == target) // found it
    {
        subTreePtr = moveValuesUpTree(subTreePtr);
        success = true;
        return subTreePtr;
    }
    else
    {
        auto targetNodePtr = removeValue(subTreePtr->getLeftChildPtr(), target, success);
        subTreePtr->setLeftChildPtr(targetNodePtr);
        if (!success) // no need to search right subTree
        {
            targetNodePtr = removeValue(subTreePtr->getRightChildPtr(), target,
            success);
            subTreePtr->setRightChildPtr(targetNodePtr);
        } // end if
    return subTreePtr;
    } // end if
} // end removeValue
// Copies values up the tree to overwrite value in current node until
// a leaf is reached; the leaf is then removed, since its value is
// stored in the parent.
template<class ItemType>
BinaryNode<ItemType>* BinaryNodeTree<ItemType>::moveValuesUpTree(BinaryNode<ItemType> *nodePtr)
{
    BinaryNode<ItemType> *leftPtr = nodePtr->getLeftChildPtr();
    BinaryNode<ItemType> *rightPtr = nodePtr->getRightChildPtr();
    int leftHeight = getHeightHelper(leftPtr);
    int rightHeight = getHeightHelper(rightPtr);
    if (leftHeight > rightHeight)
    {
        nodePtr->setItem(leftPtr->getItem());
        leftPtr = moveValuesUpTree(leftPtr);
        nodePtr->setLeftChildPtr(leftPtr);
        return nodePtr;
    }
    else
    {
        if (rightPtr != nullptr)
        {
            nodePtr->setItem(rightPtr->getItem());
            rightPtr = moveValuesUpTree(rightPtr);
            nodePtr->setRightChildPtr(rightPtr);
            return nodePtr;
        }
        else
        {
    //this was a leaf!
    // value not important
            return nullptr;
        } // end if
    } // end if
} // end moveValuesUpTree

// Recursively searches for target value in the tree by using a
// preorder traversal.
/// Locates the node in the binary search tree to which subTreePtr points that contains
// the value target. Returns either a pointer to the located node or nullptr if such a
// node is not found.
template<class ItemType>
bool BinaryNodeTree<ItemType>::remove(const ItemType& target)
{
    bool isSuccessful = false;
    rootPtr = removeValue(rootPtr, target, isSuccessful);
    return isSuccessful;
} // end remove
template < class ItemType>
BinaryNode<ItemType>* BinaryNodeTree<ItemType>::copyTree(const BinaryNode<ItemType>* treePtr) const
{
    BinaryNode<ItemType>* newTreePtr = nullptr;
    // Copy tree nodes during a preorder traversal
    if (treePtr != nullptr)
    {
    // Copy node
        newTreePtr = new BinaryNode<ItemType>(treePtr->getItem(), nullptr, nullptr);
        newTreePtr->setLeftChildPtr(copyTree(treePtr->getLeftChildPtr()));
        newTreePtr->setRightChildPtr(copyTree(treePtr->getRightChildPtr()));
    } // end if
    // Else tree is empty (newTreePtr is nullptr)
    return newTreePtr;
} // end copyTree
// Recursive traversal helper methods:
template < class ItemType>
void BinaryNodeTree<ItemType>::preorder(void visit(ItemType&), BinaryNode<ItemType>* treePtr) const
{
    if (treePtr != nullptr)
    {
        ItemType theItem = treePtr->getItem();
        visit(theItem);
        preorder(visit, treePtr->getLeftChildPtr());
        preorder(visit, treePtr->getRightChildPtr());
    } // end if
}
template < class ItemType>
void BinaryNodeTree<ItemType>::inorder(void visit(ItemType&), BinaryNode<ItemType>* treePtr) const
{
    if (treePtr != nullptr)
    {
        inorder(visit, treePtr->getLeftChildPtr());
        ItemType theItem = treePtr->getItem();
        visit(theItem);
        inorder(visit, treePtr->getRightChildPtr());
    } // end if
} // end inorder
template < class ItemType>
void BinaryNodeTree<ItemType>::postorder(void visit(ItemType&), BinaryNode<ItemType>* treePtr) const
{
    if (treePtr != nullptr)
    {
        postorder(visit, treePtr->getLeftChildPtr());
        postorder(visit, treePtr->getRightChildPtr());
        ItemType theItem = treePtr->getItem();
        visit(theItem);
    } // end if
}
template < class ItemType>
BinaryNodeTree<ItemType>::BinaryNodeTree() : rootPtr(nullptr)
{
} // end default constructor
template < class ItemType>
BinaryNodeTree<ItemType>::BinaryNodeTree(const ItemType& rootItem)
{
    rootPtr = new BinaryNode<ItemType>(rootItem, nullptr, nullptr);
} // end constructor
template < class ItemType>
BinaryNodeTree<ItemType>::BinaryNodeTree(const ItemType& rootItem, const BinaryNodeTree<ItemType>* leftTreePtr, const BinaryNodeTree<ItemType>* rightTreePtr)
{
    rootPtr = new BinaryNode<ItemType>(rootItem, copyTree(leftTreePtr->rootPtr),
    copyTree(rightTreePtr->rootPtr));
} // end constructor
template < class ItemType>
BinaryNodeTree<ItemType>::BinaryNodeTree(const BinaryNodeTree<ItemType>* treePtr)
{
    rootPtr = copyTree(treePtr->rootPtr);
} // end copy constructor
template < class ItemType>
BinaryNodeTree<ItemType>::BinaryNodeTree(const BinaryNode<ItemType>* tree){
    rootPtr = new BinaryNode<ItemType>(tree->getItem(), nullptr, nullptr);
    rootPtr->setLeftChildPtr(tree->getLeftChildPtr());
    rootPtr->setRightChildPtr(tree->getRightChildPtr());
}
template < class ItemType>
BinaryNodeTree<ItemType>::~BinaryNodeTree()
{
    destroyTree(rootPtr);
}
//------------------------------------------------------------
// Public BinaryTreeInterface Methods Section.
//------------------------------------------------------------
template < class ItemType>
bool BinaryNodeTree<ItemType>::isEmpty() const
{
    return(rootPtr == nullptr);
}
template < class ItemType>
int BinaryNodeTree<ItemType>::getHeight() const
{
    return (getHeightHelper(rootPtr));
}
template < class ItemType>
int BinaryNodeTree<ItemType>::getNumberOfNodes() const
{
    if (!isEmpty())
        return(getNumberOfNodesHelper(rootPtr));
    else return 0;
}
template < class ItemType>
ItemType BinaryNodeTree<ItemType>::getRootData() const 
{
    if (isEmpty())
        throw PrecondViolatedExcep("TreeException:EmptyTree");
    return rootPtr->getItem();
} //end getRootData
template < class ItemType>
void BinaryNodeTree<ItemType>::setRootData(const ItemType& newData)
{
    if (!isEmpty())
        rootPtr->setItem(newData);
    else
        rootPtr = new BinaryNode<ItemType>(newData, nullptr, nullptr);
}//end setRootData
template < class ItemType>
bool BinaryNodeTree<ItemType>::add(const ItemType& newData)
{
    BinaryNode<ItemType>* newNodePtr = new BinaryNode<ItemType>(newData);
    rootPtr = balancedAdd(rootPtr, newNodePtr);
    //rootPtr = insertInorder(rootPtr, newNodePtr); //BST
    return true;
} // end add
template < class ItemType>
void BinaryNodeTree<ItemType>::clear()
{
    destroyTree(rootPtr);
    rootPtr = nullptr;
}
template < class ItemType>
ItemType BinaryNodeTree<ItemType>::getEntry(const ItemType& anEntry) const 
{
    BinaryNode<ItemType> *tempTree=nullptr;
    bool isSuccessful = false;
    tempTree = find(rootPtr, anEntry, isSuccessful);
    if (!isSuccessful){
        throw PrecondViolatedExcep("TreeException: Entry not found in tree!");
    }
    return (tempTree->getItem());
} //end getEntry
//Busca un elemento dentro de arbol Binario
template < class ItemType>
BinaryNode<ItemType>* BinaryNodeTree<ItemType>::find(BinaryNode<ItemType> *aTree,const ItemType &findItem, bool &success) const 
{
    BinaryNode<ItemType> *tempTree;
    if (aTree==nullptr)
    {
        tempTree = aTree;
        success = false; //No found
        return tempTree;
    }
    else if (aTree->getItem() == findItem){
        success = true; //foud
        return aTree;
    }//end if
    else
    {
        tempTree = find(aTree->getLeftChildPtr(), findItem,success);
        if (tempTree==nullptr)
            return (find(aTree->getRightChildPtr(), findItem,success));
        else
            return tempTree;
    }//end else
} // end find
template < class ItemType>
bool BinaryNodeTree<ItemType>::contains(const ItemType& anEntry) const
{
    BinaryNode<ItemType> *tempTree=nullptr;
    bool isSuccessful = false;
    tempTree = find(rootPtr, anEntry, isSuccessful);
    return isSuccessful;
}
//Funciona se corrigio
template < class ItemType>
void BinaryNodeTree<ItemType>::attachLeft(const ItemType& anEntry) const
{
    BinaryNode<ItemType> *leftTreePtr;
    if (isEmpty())
        throw PrecondViolatedExcep("TreeException: Empty tree");
    else
        if (rootPtr->getLeftChildPtr() != nullptr)
            throw PrecondViolatedExcep("TreeException: Can not overwrite left tree");
            else{
            leftTreePtr = new BinaryNode<ItemType>(anEntry, nullptr,
            nullptr);
            rootPtr->setLeftChildPtr(leftTreePtr);
        if (rootPtr->getLeftChildPtr() == nullptr)
            throw PrecondViolatedExcep("TreeException: Can not allocate memory");
        } //end if
    }// end attachLeft
    //Funciona se corrigio
template < class ItemType>
void BinaryNodeTree<ItemType>::attachRight(const ItemType& anEntry) const
{
    BinaryNode<ItemType> *rigthtTreePtr;
    if (isEmpty())
        throw PrecondViolatedExcep("TreeException: Empty tree");
    else
        if (rootPtr->getRightChildPtr() != nullptr)
            throw PrecondViolatedExcep("TreeException: Can not overwrite right tree");
        else{
            rigthtTreePtr = new BinaryNode<ItemType>(anEntry, nullptr,
            nullptr);
            rootPtr->setRightChildPtr(rigthtTreePtr);
            if (rootPtr->getRightChildPtr() == nullptr)
                throw PrecondViolatedExcep("TreeException: Can not allocate memory");
    } //end if
}// end attachLeft
//Funciona se corrigio
template < class ItemType>
void BinaryNodeTree<ItemType>::attachLeftSubtree(BinaryNodeTree<ItemType>* leftTreePtr) const 
{
    if (isEmpty())
        throw PrecondViolatedExcep("TreeException: Empty tree");
    else{
        if (rootPtr->getLeftChildPtr() != nullptr)
        throw PrecondViolatedExcep("TreeException: Can not overwriteleft subtree");
        else{
        rootPtr->setLeftChildPtr(leftTreePtr->rootPtr);
        leftTreePtr->rootPtr = nullptr;
    } //end if
}
}// end attachLeftSubTree
//Funciona se corrigio
template < class ItemType>
void BinaryNodeTree<ItemType>::attachRightSubtree(BinaryNodeTree<ItemType>* rightTreePtr) const 
{
    if (isEmpty())
        throw PrecondViolatedExcep("TreeException: Empty tree");
    else{
    if (rootPtr->getRightChildPtr() != nullptr)
        throw PrecondViolatedExcep("TreeException: Can not overwrite right subtree");
    else{
        rootPtr->setRightChildPtr(rightTreePtr->rootPtr);
        rightTreePtr->rootPtr = nullptr;
    } //end if
}
}// end attachRightSubTree
template < class ItemType>
BinaryNodeTree<ItemType> BinaryNodeTree<ItemType>::detachLeftSubtree() const

{
    BinaryNode<ItemType> *subTreePtr = new BinaryNode<ItemType>();
    if (isEmpty()){
        throw PrecondViolatedExcep("TreeException: Empty tree");
        return BinaryNodeTree<ItemType>();
    }
    else{
        subTreePtr = copyTree(rootPtr->getLeftChildPtr());
        rootPtr->setLeftChildPtr(nullptr);
        return BinaryNodeTree<ItemType>(subTreePtr);
    }//end if
}
template < class ItemType>
BinaryNodeTree<ItemType> BinaryNodeTree<ItemType>::detachRightSubtree() const
{
    BinaryNode<ItemType> *subTreePtr = new BinaryNode<ItemType>();
    if (isEmpty()){
        throw PrecondViolatedExcep("TreeException: Empty tree");
        return BinaryNodeTree<ItemType>();
    }
    else{
        subTreePtr = copyTree(rootPtr->getRightChildPtr());
        rootPtr->setRightChildPtr(nullptr);
        return BinaryNodeTree<ItemType>(subTreePtr);
    }//end if
}// end detachRightSubtree(
template < class ItemType>
BinaryNodeTree<ItemType> BinaryNodeTree<ItemType>::getLeftSubtree() const
{
    BinaryNode<ItemType> *subTreePtr = new BinaryNode<ItemType>();
    //BinaryNodeTree<ItemType> *temp=nullptr;
    ItemType anItem;
    if (isEmpty())
        return BinaryNodeTree<ItemType>();
    else{
        subTreePtr = copyTree(rootPtr->getLeftChildPtr());
        return BinaryNodeTree<ItemType>(subTreePtr);
    } //end if
}// end getLeftSubtree
template < class ItemType>
BinaryNodeTree<ItemType> BinaryNodeTree<ItemType>::getRightSubtree() const
{
    BinaryNode<ItemType> *subTreePtr = new BinaryNode<ItemType>();
    if (isEmpty())
        return BinaryNodeTree<ItemType>();
    else{
        subTreePtr = copyTree(rootPtr->getRightChildPtr());
        return BinaryNodeTree<ItemType>(subTreePtr);
    } //end if
}// end getRightSubtree
//------------------------------------------------------------
// Public Traversals Section.
//------------------------------------------------------------
template < class ItemType>
void BinaryNodeTree<ItemType>::preorderTraverse(void visit(ItemType&)) const
{
    preorder(visit, rootPtr);
}
template < class ItemType>
void BinaryNodeTree<ItemType>::inorderTraverse(void visit(ItemType&)) const
{
    inorder(visit, rootPtr);
}
template < class ItemType>
void BinaryNodeTree<ItemType>::postorderTraverse(void visit(ItemType&)) const
{
    postorder(visit, rootPtr);
}
//------------------------------------------------------------
// Overloaded Operator Section.
//------------------------------------------------------------
template < class ItemType>
BinaryNodeTree<ItemType> & BinaryNodeTree<ItemType>::operator=(const BinaryNodeTree<ItemType> &rightHandSide)
{
    if (this != &rightHandSide){
        destroyTree(rootPtr);
        rootPtr = copyTree(rightHandSide.rootPtr);
    }//end if
    return *this;
} // end operator=
#endif