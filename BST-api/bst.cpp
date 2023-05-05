#include <iostream>
#include <algorithm>
using namespace std;
template <class var>
class Node
{
public:
    Node<var> *left, *right;
    var value;
    Node()
    {
        left = right = NULL;
        // value = 0;
    }
    Node(var value)
    {
        left = right = NULL;
        this->value = value;
    }
};
template <class var>
class BST
{
    Node<var> *root;
    int count;
    // var *temp;

public:
    BST()
    {
        root = NULL;
        count = 0;
    }
    BST(int x)
    {
        root = new Node<var>(x);
        count = 1;
    }
    BST(const BST<var> &bst)
    {
        int count1 = bst.countNode(bst.root);
        var *temp;
        int i = 0;
        temp = bst.preorder1(bst.root, i, temp);
        root=NULL; //new Node<var>(temp[0]);
        for (int j = 0; j < count1; j++)
        {
            insert(root, temp[j]);
        }
        delete[] temp;
    }
    ~BST()
    {

        count = countNode(root);
        Node<var> **temp;
        int i = 0;
        temp = allNode(root, i, temp);
        for (int j = 0; j < count; j++)
        {
            delete temp[j];
        }
        delete[] temp;
    }
    Node<var>** allNode(Node<var> *s,int &i, Node<var> **temp) const
    {
        if (s == root)
        {
            temp = new Node<var>*[countNode(root)];
        }
        if (s == NULL)
            return temp;
        temp[i] = s;
        i++;
        allNode(s->left, i, temp);
        allNode(s->right, i, temp);
        return temp;
    }
    Node<var> *getStart() const
    {
        return root;
    }
    Node<var> *insertUtil(Node<var> *root, var value)
    {
        if(root==nullptr) return new Node<var>(value);
        if(value>=root->value)
            root->right = insertUtil(root->right, value);
        else
            root->left = insertUtil(root->left, value);
        return root;
    }
    BST<var> &insert(Node<var> *s, var x)
    {
        root = insertUtil(root,x);
        return *this;
    }
    void inorder(Node<var> *s)
    {
        if (s == NULL)
            return;
        inorder(s->left);
        cout << s->value << " ";
        inorder(s->right);
    }
    void preorder(Node<var> *s)
    {
        if (s == NULL)
            return;
        cout << s->value << " ";
        preorder(s->left);
        preorder(s->right);
    }
    void postorder(Node<var> *s)
    {
        if (s == NULL)
            return;

        postorder(s->left);
        postorder(s->right);
        cout << s->value << " ";
    }

    Node<var> *findPtr(Node<var> *s, var x)
    {
        if (s == NULL)
            return NULL;
        if (s->value == x)
            return s;
        else if (x < s->value)
            return findPtr(s->left, x);
        else
            return findPtr(s->right, x);
    }
    bool find(Node<var> *s, var x)
    {
        if (s == NULL)
            return false;
        if (s->value == x)
            return true;
        else if (x < s->value)
            return find(s->left, x);
        else
            return find(s->right, x);
    }
    void show(Node<var> *s)
    {
        if (s == NULL)
            return;
        if (s->left == NULL && s->right == NULL)
        {
            cout << s->value;
            return;
        }
        if (s->left != NULL && s->right == NULL)
        {
            cout << s->value << "(";
            show(s->left);
            cout << ")()";
        }
        else if (s->right != NULL && s->left == NULL)
        {
            cout << s->value << "()(";
            show(s->right);
            cout << ")";
        }
        else
        {
            cout << s->value;
            cout << "(";
            show(s->left);
            cout << ")(";
            show(s->right);
            cout << ")";
        }
    }
    Node<var> *DeleteUtil(Node<var> *root, var item)
    {
        if(root==nullptr) return root;
        if(item>root->value) root->right = DeleteUtil(root->right,item);
        else if(item<root->value) root->left = DeleteUtil(root->left,item);
        else
        {
            if(root->left==nullptr)
                return root->right;
            else if(root->right==nullptr)
                return root->left;
            else
            {
                cout<<"Here\n";
                Node<var> *temp = findMin(root->right);
                cout<<temp->value<<endl;
                root->value = temp->value;
                root->right = DeleteUtil(root->right,temp->value);
            }
        }
        return root;
    }
    Node<var> *findMin(Node<var> *root)
    {
        if(root->left==nullptr) return root;
        return findMin(root->left);
    }
    Node<var> *findMax(Node<var> *root)
    {
        if(root->right==nullptr) return root;
        return findMax(root->right);
    }
    BST<var> &Delete(Node<var> *s, var item)
    {
        root = DeleteUtil(root,item);

        return *this;
    }
    var *preorder1(Node<var> *s, int &i, var *temp) const
    {
        if (s == root)
        {
            temp = new var[countNode(root)];
        }
        if (s == NULL)
            return temp;
        temp[i] = s->value;
        i++;
        preorder1(s->left, i, temp);
        preorder1(s->right, i, temp);
        return temp;
    }
    int countNode(Node<var> *s) const
    {
        if (s == NULL)
            return 0;
        return 1 + countNode(s->left) + countNode(s->right);
    }
    template <class var1>
    friend ostream &operator<<(ostream &out, BST<var1> &bst);
};
template <class var>
ostream &operator<<(ostream &out, BST<var> &bst)
{
    if (bst.count != bst.countNode(bst.root) && bst.countNode(bst.root) >= 0)
    {
        bst.show(bst.getStart());
        bst.count = bst.countNode(bst.root);
        out << endl;
    }
    return out;
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    string s1, s2;
    int x;
    BST<int> list;
    while (true && !feof(stdin))
    {
        cin >> s1;
        if (s1 == "I")
        {
            cin >> x;
            list = list.insert(list.getStart(), x);
            cout << list;
        }
        else if (s1 == "D")
        {
            cin >> x;
            list = list.Delete(list.getStart(), x);
            cout <<"After Deletion: "<<list;
        }
        else if (s1 == "F")
        {
            cin >> x;
            cout << ((list.find(list.getStart(), x)) ? "True" : "False");
            cout << endl;
        }
        else if (s1 == "T")
        {
            cin >> s2;
            transform(s2.begin(),s2.end(),s2.begin(), ::toupper);
            if (s2 == "IN")
            {
                list.inorder(list.getStart());
            }
            else if (s2 == "PRE")
            {
                list.preorder(list.getStart());
            }
            else if (s2 == "POST")
            {
                list.postorder(list.getStart());
            }
            cout << endl;
        }
        else
        {
            cout<<"Invalid\n";
        }
    }
}
