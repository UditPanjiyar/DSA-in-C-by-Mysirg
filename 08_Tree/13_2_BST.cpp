#include <iostream>
#include <stdio.h>
using namespace std;
#define EMPTY_TREE 1
#define DATA_NOT_FOUND 2

struct node
{
    int item;
    node *left;
    node *right;
};

class BST
{
private:
    node *root;
    void recPreorder(node *root);
    void recInorder(node *root);
    void recPostorder(node *root);

public:
    BST();
    node *create_node(int value);
    bool isEmpty();
    void insert(int data);
    void preorder();
    void inorder();
    void postorder();
    node *search(int);
    void del(int);
};

BST::BST()
{
    root = NULL;
}

node *BST::create_node(int value)
{
    node *N = new node;
    N->item = value;
    N->left = NULL;
    N->right = NULL;
    return N;
}

bool BST::isEmpty()
{
    if (root == NULL)
        return true;
}
void BST::insert(int data)
{

    if (root == NULL)
    {
        node *n = create_node(data);
        root = n;
    }
    else // (root!=NULL)
    {
        bool flag = true;
        node *ptr = root;
        while (flag == true)
        {
            if (data == ptr->item)
            {
                cout << "insertion not possible because of duplicate element: " << data << endl;
                break;
            }
            else
            {
                if (data < ptr->item) // left subtree
                {
                    if (ptr->left == NULL)
                    {
                        node *n = create_node(data);
                        ptr->left = n;
                        flag = false;
                    }
                    else //(root->left != NULL)
                    {
                        ptr = ptr->left;
                    }
                }
                else // (data> root->item) -- right subtree
                {
                    if (ptr->right == NULL)
                    {
                        node *n = create_node(data);
                        ptr->right = n;
                        flag = false;
                    }
                    else // (root->right != NULL)
                    {
                        ptr = ptr->right;
                    }
                }
            }
        }
    }
}

void BST::recPreorder(node *ptr)
{
    if (ptr != NULL)
    {
        cout << ptr->item << " ";
        recPreorder(ptr->left);
        recPreorder(ptr->right);
    }
}
void BST::preorder()
{
    recPreorder(root);
}

void BST::recInorder(node *ptr)
{
    if (ptr != NULL)
    {
        recInorder(ptr->left);
        cout << ptr->item << " ";
        recInorder(ptr->right);
    }
}

void BST::inorder()
{
    recInorder(root);
}

void BST::recPostorder(node *ptr)
{
    if (ptr != NULL)
    {
        recPostorder(ptr->left);
        recPostorder(ptr->right);
        cout << ptr->item << " ";
    }
}

void BST::postorder()
{
    recPostorder(root);
}

node *BST::search(int data)
{
    node *ptr = root;
    while (ptr != NULL)
    {
        if (data = root->item)
            return root;
        else if (data < root->item)
            root = root->left;
        else
            root = root->right;
    }
    return NULL;
}

void BST::del(int data)
{
    node *ptr, *parptr;

    if (root == NULL)
        throw EMPTY_TREE;

    parptr = NULL;
    ptr = root;
    while (ptr != NULL)
    {
        if (data == ptr->item)
        {
            break;
        }
        if (data < ptr->item)
        {
            parptr = ptr;
            ptr = ptr->left;
        }
        else
        {
            parptr = ptr;
            ptr = ptr->right;
        }
    }

    if (ptr == NULL)
        throw DATA_NOT_FOUND;

    if (parptr == NULL && ptr != NULL) // root node to be deleted
    {
        if (ptr->left == NULL && ptr->right == NULL) // no child
        {
            delete ptr;
            root = NULL;
        }
        else if (ptr->left != NULL && ptr->right != NULL) // two child
        {
            node *suc, *parsuc;
            parsuc = ptr;
            suc = ptr->right;

            while (suc->left != NULL)
            {
                parsuc = suc;
                suc = suc->left;
            }
            ptr->item = suc->item;

            if (suc == parsuc->right)
            {
                parsuc->right = suc->right;
            }
            else
            {
                parsuc->left = suc->right;
            }

            delete suc;
        }
        else // one child  ( ptr->left == NULL || ptr->right == NULL)
        {
            if (ptr->left != NULL)
            {
                ptr->item = ptr->left->item;
                delete ptr->left;
            }
            else // (ptr->right != NULL)
            {
                ptr->item = ptr->right->item;
                delete ptr->right;
            }
        }
    }

    else // node to be deleted is not a root node
    {
        if (ptr->left == NULL && ptr->right == NULL) // no child
        {
            if (ptr == parptr->left)
            {
                parptr->left = NULL;
                delete ptr;
            }
            else // (ptr == parptr->right )
            {
                parptr->right = NULL;
                delete ptr;
            }
        }
        else if (ptr->left != NULL && ptr->right != NULL) // two child
        {
            node *suc, *parsuc;
            parsuc = ptr;
            suc = ptr->right;

            while (suc->left != NULL) // inorder successor
            {
                parsuc = suc;
                suc = suc->left;
            }
            ptr->item = suc->item;

            if (suc == parsuc->left)
            {
                parsuc->left = suc->right;
            }
            else
            {
                parsuc->right = suc->right;
            }

            delete suc;
        }
        else // one child
        {
            if (ptr == parptr->left)
            {
                if (ptr->left != NULL)
                {
                    parptr->left = ptr->left;
                }
                else // (ptr->right != NULL)
                {
                    parptr->left = ptr->right;
                }
                delete ptr;
            }
            else // (ptr == parptr->right )
            {
                if (ptr->right != NULL)
                {
                    if (ptr->left != NULL)
                    {
                        parptr->right = ptr->left;
                    }
                    else ///(ptr->right != NULL)
                    {
                        parptr->right = ptr->right;
                    }
                    delete ptr;
                }
            }
        }
    }
}

int main()
{
    BST obj;
    obj.insert(50);
    obj.insert(30);
    obj.insert(60);

    obj.preorder();
    cout << endl;

    obj.del(30);
    obj.preorder();

    // obj.insert(50);
    // obj.insert(30);
    // obj.insert(70);
    // obj.insert(10);
    // obj.insert(60);
    // obj.insert(90);
    // obj.insert(20);
    // obj.insert(80);
    // obj.insert(15);
    // obj.insert(25);
    // obj.insert(75);
    // obj.insert(85);

    // obj.preorder();
    // cout << endl;

    // obj.del(50);
    // obj.preorder();
    //  cout << endl;

    // obj.del(75);
    // obj.preorder();
    //  cout << endl;

    // obj.del(10);
    // obj.preorder();
    // cout << endl;

    // obj.del(70);
    // obj.preorder();
    // cout << endl;

    return 0;
}