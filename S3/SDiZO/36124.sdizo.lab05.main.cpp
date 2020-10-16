//SDIZO IS1 221B LAB05
//Szymon Mirr
//smirr@wi.zut.edu.pl
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;
struct node_rec
{
    int key;
    char znaki[16];
    struct node_rec *left, *right;
};
typedef struct node_rec *tree_type;

int insertuj(node_rec *& root, int key)
{
    node_rec *new_node = new node_rec();
    new_node->left = NULL;
    new_node->right = NULL;
    new_node->key = key;
    for(int i=0;i<16;i++)
    {
        new_node->znaki[i] = 'A' + rand() %( 'Z' - 'A' );
    }
    node_rec *parent = NULL;
    node_rec *p = root;
    while(p != NULL)
    {
        if(p->key == key) return(-1);
        parent = p;
        if(p->key > key) p = p->left;
        else p = p->right;
    }
    if(root == NULL)
    root = new_node;
    else if(parent->key > key) parent->left = new_node;
    else parent->right = new_node;
    return(0);
}

void losuj(node_rec *& root, int x)
{
    srand( time( 0 ) );
    for(int i=0; i<x; i++)
    {
        int wylosowana = 25 + rand() %( 30000 - 25 );
        if(insertuj(root, wylosowana)==-1)i--;
    }
}

node_rec* rotate_right(node_rec* x)
{
    node_rec* y = x->left;
    x->left = y->right;
    y->right = x;
    return y;
}

node_rec* rotate_left(node_rec* x)
{
    node_rec* y = x->right;
    x->right = y->left;
    y->left = x;
    return y;
}

node_rec *splay(node_rec *root, int key)
{
    if (root->key == key || root == NULL)
    {
        return root;
    }
    if (key < root->key)
    {
        if (root->left == NULL)
        {
            return NULL;
        }
        if (key < root->left->key)
        {
            root->left->left = splay(root->left->left, key);
            root = rotate_right(root);
        }
        else if (key > root->left->key)
        {
            root->left->right = splay(root->left->right, key);
            if (root->left->right != NULL)
            {
                root->left = rotate_left(root->left);
            }
        }
        if(root->left == NULL)
        {
            return root;
        }
        else
        {
            return rotate_right(root);
        }
    }
    else
    {
        if (root->right == NULL)
        {
            return NULL;
        }
        if (root->right->key > key)
        {
            root->right->left = splay(root->right->left, key);
            if (root->right->left != NULL)
            {
                root->right = rotate_right(root->right);
            }
        }
        else if (root->right->key < key)
        {
            root->right->right = splay(root->right->right, key);
            root = rotate_left(root);
        }
        if(root->right == NULL)
        {
            return root;
        }
        else
        {
            return rotate_left(root);
        }
    }
}

void wstaw(node_rec *& root, int key)
{
    while(1)
    {
        if(insertuj(root, key)==-1)
        {
            key=key+1;
        }
        else break;
    }
    root = splay(root,key);
}

void znajdz(node_rec *& root, int x)
{
    int found = 0;
    node_rec *p = root;
    while((p != NULL) & ~found)
    {
        if(p->key == x)
        found = 1;
        else if(p->key < x)
        p = p->right;
        else
        p = p->left;
    }
    if(found==0)
    {
        cout<<"Nie znaleziono elementu "<<x<<endl;
    }
    else
    {
        cout<<"Znaleziono element "<<x<<endl;
        root = splay(root,x);
    }
}

void scan_preorder (node_rec *& root)
{
    if(root != NULL)
    {
        node_rec *P(root);
        cout << P->key << " ";
        scan_preorder(root->left);
        scan_preorder(root->right);
    }
}

void scan_inorder (node_rec *& root)
{
    if(root != NULL)
    {
        scan_inorder(root->left);
        node_rec *P(root);
        cout << P->key << " ";
        scan_inorder(root->right);
    }
}

node_rec* usun(node_rec *& root, int x)
{
    root = splay(root,x);
    node_rec *parent = NULL;
    node_rec *p = root;
    while((p != NULL)&&(x == p->key))
    {
        node_rec *preparent = NULL;
        node_rec *poprzednik = NULL;
        parent = p;
        p = p->left;
        while (p != NULL)
        {
            preparent = parent;
            parent = p;
            p = p->right;
        }
        poprzednik = parent;
        preparent->right = poprzednik->left;
        poprzednik->left = root->left;
        poprzednik->right = root->right;
        root = poprzednik;
        break;
    }
    while((p != NULL)&&(x != p->key))
    {
        parent = p;
        if(p->key < x) p = p->right;
        else p = p->left;
    }
    if (p == NULL) return NULL;
    if ((p->right == NULL) && (p->left == NULL))
    {
        if (p == root)
        {
            root = NULL;
            return root;
        }
        if (parent->right == p) parent->right = NULL;
        else parent->left = NULL;
        return root;
    }
    if (p->right == NULL)
    {
        if (parent->right == p)
        parent->right = p->left;
        else
        parent->left = p->left;
        return root;
    }
    if (p->left == NULL)
    {
        if (parent->right == p)
        parent->right = p->right;
        else
        parent->left = p->right;
        return root;
    }
    node_rec *preparent = p;
    node_rec *child = p->left;
    while(child->right != NULL)
    {
        preparent = child;
        child = child->right;
    }
    if (child == p->left)
    {
        if (parent->right == p) parent->right = child;
        else parent->left = child;
        return root;
    }
    node_rec *grandchild = child->left;
    if (preparent->right == child) preparent->right = grandchild;
    else preparent->left = grandchild;
    child->left = p->left;
    if (parent->right == p)
    parent->right = child;
    else
    parent->left = child;
    return root;
}

int main()
{
    clock_t begin, end;
    begin = clock();
    fstream plik;
    plik.open("inlab05.txt");
    int x1,k1,k2,k3;
    plik >> x1 >> k1 >> k2 >> k3;
    node_rec * root;
    root = NULL;
    losuj(root,x1);
    scan_inorder(root);
    cout << endl << endl;
    scan_preorder(root);
    cout << endl << endl;
    wstaw(root,k1);
    scan_preorder(root);
    cout << endl << endl;
    wstaw(root,k2);
    scan_preorder(root);
    cout << endl << endl;
    znajdz(root,k3);
    cout << endl;
    scan_preorder(root);
    cout << endl << endl;
    usun(root,k2);
    scan_preorder(root);
    cout << endl << endl;
    scan_inorder(root);
    cout << endl << endl;
    plik.close();
    end = clock();
    cout << "Czas: " << (double)(end - begin) / CLOCKS_PER_SEC << "s" << endl;
    return 0;
}
