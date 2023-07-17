#include <iostream>
#include <string>
using namespace std;

template <class K>
class BSTNode
{
    K key;
    BSTNode<K> *left;
    BSTNode<K> *right;

public:
    BSTNode()
    {
    }

    BSTNode(BSTNode<K> *left, BSTNode<K> *right, K key)
    {
        this->left = left;
        this->right = right;
        this->key = key;
    }

    // getter functions
    K getKey()
    {
        return key;
    }

    BSTNode<K> *getLeft()
    {
        return left;
    }

    BSTNode<K> *getRight()
    {
        return right;
    }

    // setter functions
    void setKey(K key)
    {
        this->key = key;
    }

    void setLeft(BSTNode<K> *left)
    {
        this->left = left;
    }

    void setRight(BSTNode<K> *right)
    {
        this->right = right;
    }
};

template <class K>
class BST
{
private:
    BSTNode<K> *root;

    // helper functions
    K getMin(BSTNode<K> *cur)
    {
        if (cur->getLeft() == NULL)
            return cur->getKey();
        getMin(cur->getLeft());
    }

    BSTNode<K> *removeMin(BSTNode<K> *cur)
    {
        BSTNode<K> *temp = NULL;
        if (cur->getLeft() == NULL)
        {
            temp = cur->getRight();
            delete cur;
            return temp;
        }

        cur->setLeft(removeMin(cur->getLeft()));
    }

    BSTNode<K> *insertHelp(BSTNode<K> *cur, K key)
    {
        if (cur == NULL)
        {
            BSTNode<K> *temp = new BSTNode<K>(NULL, NULL, key);
            return temp;
        }
        if (key >= cur->getKey())
            cur->setRight(insertHelp(cur->getRight(), key));

        else
            cur->setLeft(insertHelp(cur->getLeft(), key));
    }

    BSTNode<K> *removeHelp(BSTNode<K> *cur, K key)
    {
        if (cur == NULL)
            return cur;

        if (cur->getKey() == key)
        {
            BSTNode<K> *temp = NULL;

            if (cur->getLeft() && cur->getRight())
            {
                cur->setKey(getMin(cur->getRight()));
                cur->setRight(removeMin(cur->getRight()));
            }

            else
            {
                if (cur->getLeft())
                    temp = cur->getLeft();
                else
                    temp = cur->getRight();

                delete cur;
                return temp;
            }
        }

        else if (key > cur->getKey())
            cur->setRight(removeHelp(cur->getRight(), key));

        else
            cur->setLeft(removeHelp(cur->getLeft(), key));

        return cur;
    }

    bool findHelp(BSTNode<K> *cur, K key)
    {
        if (cur == NULL)
            return false;

        if (cur->getKey() == key)
            return true;

        if (key > cur->getKey() && cur->getRight())
            return findHelp(cur->getRight(), key);

        else if (key < cur->getKey() && cur->getLeft())
            return findHelp(cur->getLeft(), key);

        else
            return false;
    }

    void printHelp(BSTNode<K> *root)
    {
        if (root == NULL)
            return;

        cout << root->getKey();

        if (root->getLeft() || root->getRight())
        {
            cout << "(";
            if (root->getLeft())
                printHelp(root->getLeft());
            cout << ",";

            if (root->getRight())
                printHelp(root->getRight());
            cout << ")";
        }
    }

    void inOrderPrint(BSTNode<K> *cur)
    {
        if (cur == NULL)
            return;
        inOrderPrint(cur->getLeft());
        cout << cur->getKey() << " ";
        inOrderPrint(cur->getRight());
    }
    void preOrderPrint(BSTNode<K> *cur)
    {
        if (cur == NULL)
            return;
        cout << cur->getKey() << " ";
        preOrderPrint(cur->getLeft());
        preOrderPrint(cur->getRight());
    }
    void postOrderPrint(BSTNode<K> *cur)
    {
        if (cur == NULL)
            return;
        postOrderPrint(cur->getLeft());
        postOrderPrint(cur->getRight());
        cout << cur->getKey() << " ";
    }

public:
    BST()
    {
        root = NULL;
    }

    void insert(K key)
    {
        root = insertHelp(root, key);
    }

    void remove(K key)
    {
        root = removeHelp(root, key);
    }

    bool find(K key)
    {
        return findHelp(root, key);
    }

    void print()
    {
        cout << "(";
        printHelp(root);
        cout << ")";
        cout << endl;
    }

    void traverse(string type)
    {
        if (type == "In")
            inOrderPrint(root);

        else if (type == "Pre")
            preOrderPrint(root);

        else
            postOrderPrint(root);

        cout << endl;
    }
};