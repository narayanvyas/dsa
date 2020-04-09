#include <iostream>
#include <conio.h>
#include <queue>
using namespace std;

struct node
{
    int data;
    struct node *left, *right;
};

// Creation of Binary Tree
node *create()
{
    node *newNode;
    int x;
    newNode = (node *)malloc(sizeof(node));
    cout << "Enter Value (Enter -1 for NULL)\t";
    cin >> x;
    if (x == -1)
        return NULL;
    newNode->data = x;
    cout << "Enter Left Child of " << x << endl;
    newNode->left = create();
    cout << "Enter Right Child of " << x << endl;
    newNode->right = create();
    return newNode;
}

// Traversal of Binary Tree

void preOrder(node *root)
{
    if (root == NULL)
        return;
    cout << root->data << "\t";
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(struct node *root)
{
    if (root == NULL)
        return;
    inOrder(root->left);
    cout << root->data << "\t";
    inOrder(root->right);
}
void postOrder(struct node *root)
{
    if (root == NULL)
        return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << "\t";
}

void levelOrder(node *root)
{
    if (root == NULL)
        return;
    queue<node *> Q;
    Q.push(root);
    while (!Q.empty())
    {
        node *currentNode = Q.front();
        cout << currentNode->data << "\t";
        if (currentNode->left != NULL)
            Q.push(currentNode->left);
        if (currentNode->right != NULL)
            Q.push(currentNode->right);
        Q.pop();
    }
}
void treeTraversal(node *root)
{
    if (root == NULL)
        cout << endl
             << "Tree Is Empty\n";
    else
    {
        cout << "\nIn Order\t";
        inOrder(root);
        cout << "\nPre Order\t";
        preOrder(root);
        cout << "\nPost Order\t";
        postOrder(root);
        cout << "\nLevel Order\t";
        levelOrder(root);
        cout << "\n\n";
    }
}

// Search Value in Binary Tree
void searchValue(node *root)
{
    int searchValue;
    cout << "\n\nEnter Value To Search\t";
    cin >> searchValue;
    if (root == NULL)
    {
        cout << "Tree is empty";
        return;
    }
    else
    {
        queue<node *> Q;
        Q.push(root);
        while (!Q.empty())
        {
            node *currentNode = Q.front();
            if (searchValue == currentNode->data)
            {
                cout << endl
                     << searchValue << " Found";
                return;
            }
            if (currentNode->left != NULL)
                Q.push(currentNode->left);
            if (currentNode->right != NULL)
                Q.push(currentNode->right);
            Q.pop();
        }
        cout << endl
             << searchValue << " Not Found";
    }
}

// Insert Node in Binary Tre
node *insertNode(node *root)
{
    int x;
    cout << "Enter Value To Insert:\t";
    cin >> x;
    if (root == NULL)
    {
        node *tmpNode = (node *)malloc(sizeof(node));
        tmpNode->data = x;
        tmpNode->left = NULL;
        tmpNode->right = NULL;
        return tmpNode;
    }
    queue<node *> Q;
    Q.push(root);
    while (!Q.empty())
    {
        node *currentNode = Q.front();
        cout << currentNode->data << "\t";
        if (currentNode->left == NULL)
        {
            node *tmpNode = (node *)malloc(sizeof(node));
            tmpNode->data = x;
            tmpNode->left = NULL;
            tmpNode->right = NULL;
            currentNode->left = tmpNode;
            break;
        }
        else if (currentNode->right == NULL)
        {
            node *tmpNode;
            tmpNode = (node *)malloc(sizeof(node));
            tmpNode->data = x;
            tmpNode->left = NULL;
            tmpNode->right = NULL;
            currentNode->right = tmpNode;
            break;
        }
        else
        {
            Q.push(currentNode->left);
            Q.push(currentNode->right);
        }
        Q.pop();
    }
    cout << endl;
    return root;
}
// Delete Node
void deleteDeepestNode(node *root, node *nodeToDelete)
{
    queue<node *> Q;
    Q.push(root);
    node *temp;
    while (!Q.empty())
    {
        temp = Q.front();
        Q.pop();
        if (temp == nodeToDelete)
        {
            temp = NULL;
            delete (nodeToDelete);
            return;
        }
        if (temp->right)
        {
            if (temp->right == nodeToDelete)
            {
                temp->right = NULL;
                delete (nodeToDelete);
                return;
            }
            else
                Q.push(temp->right);
        }

        if (temp->left)
        {
            if (temp->left == nodeToDelete)
            {
                temp->left = NULL;
                delete (nodeToDelete);
                return;
            }
            else
                Q.push(temp->left);
        }
    }
}
node *deleteNode(node *root)
{
    if (root == NULL)
    {
        cout << "Tree is Already Empty";
        return NULL;
    }
    int value;
    cout << "\nEnter Value to Delete:\t";
    cin >> value;
    if (root->left == NULL && root->right == NULL)
    {
        if (root->data == value)
            return NULL;
        else
        {
            cout << "\nValue Not Found In Tree";
            return root;
        }
    }
    queue<node *> Q;
    Q.push(root);
    node *temp;
    node *keyNode = NULL;

    while (!Q.empty())
    {
        temp = Q.front();
        if (temp->data == value)
            keyNode = temp;
        if (temp->left != NULL)
            Q.push(temp->left);
        if (temp->right != NULL)
            Q.push(temp->right);
        Q.pop();
    }
    if (keyNode == NULL)
    {
        cout << "Value Not Found";
        return root;
    }
    else
    {
        keyNode->data = temp->data;
        deleteDeepestNode(root, temp);
        return root;
    }
}

// Delete Complete Tree
node *deleteCompleteTree(node *root)
{
    if (root == NULL)
        cout << "\nTree is already empty\n";
    else
    {
        cout << "\nTree Deleted Successfully\n";
    }
    return NULL;
}

int main()
{
    int choice;
    node *root = NULL;

    while (true)
    {
        cout << "***************** Menu *****************\n\n";
        cout << "Press 1 to Create Tree\nPress 2 to Traverse Tree\nPress 3 to Search in tree\n";
        cout << "Press 4 to Insert Item\nPress 5 to Delete Node\nPress 6 to Delete Complete Tree\nPress 7 to Exit\n\n";
        cout << "***************** Menu *****************\n\nEnter Your Choice: ";
        cin >> choice;
        cout << endl;
        switch (choice)
        {
        case 1:
            root = create();
            cout << "\n\n";
            break;
        case 2:
            treeTraversal(root);
            break;
        case 3:
            searchValue(root);
            cout << "\n\n";
            break;
        case 4:
            root = insertNode(root);
            break;
        case 5:
            root = deleteNode(root);
            break;
        case 6:
            root = deleteCompleteTree(root);
            break;
        case 7:
            exit(0);
            break;
        default:
            cout << "You Entered A Wrong Choice";
        }
    }
    return 0;
}