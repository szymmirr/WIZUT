//SDIZO IS1 221B LAB06
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

node_rec* splay(node_rec *& root, int key)
{
    if (!root)return NULL;
    node_rec* header;
    header->left = NULL;
    header->right = NULL;
    node_rec* lewymax = header;
    node_rec* prawymin = header;
    while (1)
    {
        if (key < root->key)
        {
            if (!root->left)break;
            if (key < root->left->key)
            {
                root = rotate_right(root);
                if (!root->left)break;
            }
            prawymin->left = root;
            prawymin = prawymin->left;
            root = root->left;
            prawymin->left = NULL;
        }
        else if (key > root->key)
        {
            if (!root->right)break;
            if (key > root->right->key)
            {
                root = rotate_left(root);
                if (!root->right)break;
            }
            lewymax->right = root;
            lewymax = lewymax->right;
            root = root->right;
            lewymax->right = NULL;
        }
        else break;
    }
    lewymax->right = root->left;
    prawymin->left = root->right;
    root->left = header->right;
    root->right = header->left;
    return root;
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
    splay(root,x);
    scan_preorder(root);
    cout << endl << endl;
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

int minimum(node_rec* node)
{
    node_rec* current = node;
    while (current->left != NULL)
    {
        current = current->left;
    }
    return(current->key);
}

int maksimum(node_rec* node)
{
    node_rec* current = node;
    while (current->right != NULL)
    {
        current = current->right;
    }
    return(current->key);
}

int main()
{
    clock_t begin, end;
    begin = clock();
    fstream plik;
    plik.open("inlab06.txt");
    int x1;
    plik >> x1;
    node_rec * root;
    root = NULL;
    losuj(root,x1);
    scan_preorder(root);
    cout << endl << endl;
    scan_inorder(root);
    cout << endl << endl;
    cout << "min: " << minimum(root);
    cout << " max: " << maksimum(root);
    //usun(root,XX);//najmniejszy
    //usun(root,XX);//najwiekszy
    //usun_wszystko(root,XX);
    plik.close();
    end = clock();
    cout << " Czas: " << (double)(end - begin) / CLOCKS_PER_SEC << "s" << endl;
    return 0;
}
