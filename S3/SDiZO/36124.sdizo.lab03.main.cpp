//SDIZO IS1 221B LAB03
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
        cout<<"Znaleziono element "<<x<<endl;
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

int scan_preorder (node_rec *& root, int & liczba)
{
    if(root != NULL)
    {
        node_rec *P(root);
        cout << P->key << " ";
        liczba++;
        scan_preorder(root->left, liczba);
        scan_preorder(root->right, liczba);
    }
    return liczba;
}

int scan_inorder (node_rec *& root, int & liczba)
{
    if(root != NULL)
    {
        scan_inorder(root->left, liczba);
        node_rec *P(root);
        cout << P->key << " ";
        liczba++;
        scan_inorder(root->right, liczba);
    }
    return liczba;
}

int scan_postorder (node_rec *& root, int & liczba)
{
    if(root != NULL)
    {
        scan_postorder(root->left, liczba);
        scan_postorder(root->right, liczba);
        node_rec *P(root);
        cout << P->key << " ";
        liczba++;
    }
    return liczba;
}

void losuj(node_rec *& root, int x)
{
    srand( time( 0 ) );
    for(int i=0; i<x; i++)
    {
        int wylosowana = 11 + rand() %( 19000 - 11 );
        insertuj(root, wylosowana);
    }
}

int main()
{
    clock_t begin, end;
    begin = clock();
    fstream plik;
    plik.open("inlab03.txt");
    int x,k1,k2,k3,k4;
    plik >> x >> k1 >> k2 >> k3 >> k4;
    node_rec * root;
    root = NULL;
    usun(root,k1);
    insertuj(root,k1);
    losuj(root,x);
    int liczba=0;
    cout << endl << "Odwiedzono " << scan_inorder(root, liczba) << " wezlow";
    liczba=0;
    cout << endl << endl;
    cout << endl << "Odwiedzono " << scan_preorder(root, liczba) << " wezlow";
    liczba=0;
    cout << endl << endl;
    insertuj(root,k2);
    cout << endl << "Odwiedzono " << scan_inorder(root, liczba) << " wezlow";
    liczba=0;
    cout << endl << endl;
    insertuj(root,k3);
    insertuj(root,k4);
    usun(root,k1);
    cout << endl << "Odwiedzono " << scan_preorder(root, liczba) << " wezlow";
    liczba=0;
    cout << endl << endl;
    znajdz(root,k1);
    cout << endl;
    usun(root,k2);
    cout << endl << "Odwiedzono " << scan_inorder(root, liczba) << " wezlow";
    liczba=0;
    cout << endl << endl;
    usun(root,k3);
    usun(root,k4);
    plik.close();
    end = clock();
    cout << "Czas: " << (double)(end - begin) / CLOCKS_PER_SEC << "s" << endl;
    return 0;
}
