//SDIZO IS1 221B LAB04
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
    char znaki[100];
    struct node_rec *left, *right;
};
typedef struct node_rec *tree_type;

int insertuj(node_rec *& root, int key)
{
    node_rec *new_node = new node_rec();
    new_node->left = NULL;
    new_node->right = NULL;
    new_node->key = key;
    for(int i=0;i<100;i++)
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
    for(int i=0; i<=x; i++)
    {
        int wylosowana = 11 + rand() %( 19000 - 11 );
        if(insertuj(root, wylosowana)==-1)i--;
    }
}

int wysokosc(node_rec *& root)
{
    if (root == NULL)
    {
        return (-1);
    }
    int leftwys = wysokosc(root->left);
    int rightwys = wysokosc(root->right);
    if (leftwys > rightwys)
    {
        return (leftwys + 1);
    }
    else
    {
        return (rightwys + 1);
    }
}

void rotate_right(node_rec *& grandfather, node_rec *&parent, node_rec *& child, node_rec *& root)
{
    if (grandfather != NULL)
    {
        if (grandfather->right == parent)
        grandfather->right = child;
        else grandfather->left = child;
    }
    else
    root = child;
    node_rec *tmp = child->right;
    child->right = parent;
    parent->left = tmp;
    return;
}

void rotate_left(node_rec *& grandfather, node_rec *&parent, node_rec *& child, node_rec *& root)
{
    if (grandfather != NULL)
    {
        if (grandfather->left == parent)
        grandfather->left = child;
        else grandfather->right = child;
    }
    else
    root = child;
    node_rec *tmp = child->left;
    child->left = parent;
    parent->right = tmp;
    return;
}

void rotation(int granica, node_rec *& root)
{
    node_rec *grandParent = NULL;
    node_rec *parent = root;
    node_rec *child = root->right;
    for (; granica > 0; granica--)
    {
        if (child != NULL)
        {
            rotate_left(grandParent, parent, child, root);
            grandParent = child;
            parent = grandParent->right;
            child = parent->right;
        }
        else break;
    }
}

void make_intermediate_list(node_rec *& root)
{
    node_rec *grandfather = NULL;
    node_rec *tmp = root;
    while (tmp != NULL)
    {
        if ((tmp->left) != NULL)
        {
            node_rec *tmp2 = tmp->left;
            rotate_right(grandfather, tmp, tmp->left, root);
            tmp = tmp2;
        }
        else
        {
            grandfather = tmp;
            tmp = tmp->right;
        }
    }
}

int najwiekszapotega(int n)
{
    int ndx = 0;
    while (1 < n)
    {
        n = (n >> 1);
        ndx++;
    }
    return (1 << ndx);
}

void make_perfect_tree(node_rec *& root)
{
    int n = 0;
    for (node_rec * tmp = root; tmp != NULL; tmp = tmp->right, n++);
    int m = najwiekszapotega(n + 1) - 1;
    rotation(n - m, root);
    while (m > 1)
    {
        rotation(m /= 2, root);
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

void usunwszystko (node_rec *& root)
{
  if (root != NULL)
    {
        usunwszystko (root->left);
        usunwszystko (root->right);
        delete root;
    }
}

int main()
{
    clock_t begin, end;
    begin = clock();
    fstream plik;
    plik.open("inlab04.txt");
    int x1,x2;
    plik >> x1 >> x2;
    node_rec * root;
    root = NULL;
    losuj(root,x1);
    cout << "Wysokosc drzewa wynosi: " << wysokosc(root) << endl;
    make_intermediate_list(root);
    make_perfect_tree(root);
    cout << "Wysokosc drzewa wynosi: " << wysokosc(root) << endl;
    usunwszystko(root);
    losuj(root,x2);
    cout << "Wysokosc drzewa wynosi: " << wysokosc(root) << endl;
    make_intermediate_list(root);
    make_perfect_tree(root);
    cout << "Wysokosc drzewa wynosi: " << wysokosc(root) << endl;
    plik.close();
    end = clock();
    cout << "Czas: " << (double)(end - begin) / CLOCKS_PER_SEC << "s" << endl;
    return 0;
}
