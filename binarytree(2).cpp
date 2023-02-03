#include <iostream>
using namespace std;

class node
{
public:
    int info;
    node *leftnode;
    node *rightnode;
    node(int num)
    {
        info = num;
        rightnode = NULL;
        leftnode = NULL;
    }
};

int flag = 0;
static node *createTree()
{
    node *root = NULL;

    int data;

    cout << "Enter data:" << endl;
    cin >> data;

    if (data == -1)
    {
        return NULL;
    }
    root = (node *)malloc(sizeof(node));

    root = new node(data);
    cout << "Enter left child of " << data << " :" << endl;
    root->leftnode = createTree();

    cout << "Enter right child of " << data << " :" << endl;
    root->rightnode = createTree();

    return root;
}

void inOrder(node *root)
{
    if (root == NULL)
    {
        return;
    }

    inOrder(root->leftnode);
    cout << root->info << " ";
    inOrder(root->rightnode);
    return;
}

void preOrder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->info << " ";
    preOrder(root->leftnode);

    preOrder(root->rightnode);

    return;
}

void postOrder(node *root)
{
    if (root == NULL)
    {
        return;
    }

    postOrder(root->leftnode);

    postOrder(root->rightnode);
    cout << root->info << " ";
    return;
}

int searching(node *temp, int data, node *&addNode, node *&prevNode)
{

    if (flag == 1)
    {
        return flag;
    }

    if (temp == NULL)
    {
        return flag;
    }

    if (temp->info == data)
    {
        flag = 1;
        cout << endl
             << data << " is present in tree." << endl
             << endl;
        return flag;
    }

    if (flag == 0)
    {
        prevNode = temp;
        addNode = prevNode->leftnode;
        flag = searching(temp->leftnode, data, addNode, prevNode);
        if (flag == 0)
        {
            prevNode = temp;
            addNode = prevNode->rightnode;
            flag = searching(temp->rightnode, data, addNode, prevNode);
        }
        return flag;
    }
    return flag;
}
void insertionAtnode(node *&addNode, int data)
{
    int choice;
    node *n = (node *)malloc(sizeof(node));

    n = new node(data);

NEXT:
    cout << "1 for insert at left node" << endl;
    cout << "2 for insert at right node" << endl;
    cout << "Enter your choice:" << endl;
    cin >> choice;

    switch (choice)
    {
    case 1:
        if (addNode->leftnode == NULL)
        {
            addNode->leftnode = n;
            break;
        }
        n->leftnode = addNode->leftnode;
        addNode->leftnode = n;
        break;
    case 2:
        if (addNode->rightnode == NULL)
        {
            addNode->rightnode = n;
            break;
        }
        n->rightnode = addNode->rightnode;

        addNode->rightnode = n;
        break;
    default:
        cout << "Invalid choice only 1 and 2 is allowed" << endl;
        goto NEXT;
    }
    return;
}

void insertAtroot(node *&root, int data)
{
    node *n = (node *)malloc(sizeof(node));
    n = new node(data);
    if (root == NULL)
    {
        root = (node *)malloc(sizeof(node));
        root = n;
        return;
    }
    node *temp = (node *)malloc(sizeof(node));
    temp = root;
    n->leftnode = temp;
    n->rightnode = temp->rightnode;
    temp->rightnode = NULL;
    root = n;

    return;
}

void deletion(int delNode, node *prevNode, node *&addNode)
{
    int choice_replace, data;

    cout << endl
         << "1 for insert another element at deleted node" << endl;
    cout << "Otherwise any key except 1" << endl;
    cin >> choice_replace;
    switch (choice_replace)
    {
    case 1:
        cout << "Enter element:" << endl;
        cin >> data;
        addNode->info = data;
        break;
    default:
        node *temp = (node *)malloc(sizeof(node));
        cout << "parent node " << prevNode->info << endl;
        if (temp->info == delNode)
        {
            cout << "temp data = " << temp->info << endl;
            if (addNode->leftnode == NULL && addNode->rightnode == NULL)
            {
                if(prevNode->leftnode == addNode){
                    prevNode->leftnode = NULL;
                    return;
                }
                prevNode->rightnode=NULL;
                return;
            }
            else if (addNode->leftnode == NULL)
            {
                prevNode->leftnode = addNode->rightnode;
                return;
            }
            else if (addNode->rightnode == NULL)
            {
                prevNode->leftnode = addNode->leftnode;
                return;
            }
        }
        temp = prevNode->rightnode;
        if (temp->info == delNode)
        {
            cout << "temp data = " << temp->info << endl;
            if (addNode->leftnode == NULL && addNode->rightnode == NULL)
            {
                prevNode->rightnode = NULL;
                return;
            }
            else if (addNode->leftnode == NULL)
            {
                prevNode->rightnode = addNode->rightnode;
                return;
            }
            else if (addNode->rightnode == NULL)
            {
                prevNode->rightnode = addNode->leftnode;
                return;
            }
            else
            {
                while (temp->leftnode != NULL && temp->rightnode != NULL)
                {
                    temp = temp->leftnode;
                }
            }
        }

        break;
    }
}

int main()
{
    int choice, data, insertion_choice;
    node *head = NULL;
    node *addNode, *prevNode;

    while (1)
    {
        cout << "1 Create tree" << endl;
        cout << "2 Display in Inorder" << endl;
        cout << "3 Display in Preorder" << endl;
        cout << "4 Display in Postorder" << endl;
        cout << "5 Searching" << endl;
        cout << "6 Insertion" << endl;
        cout << "7 Deletion" << endl;
        cout << "0 Exit" << endl
             << endl;
        cout << "Enter your choice:" << endl;
        cin >> choice;
        switch (choice)
        {
        case 0:
            return 0;
        case 1:
            head = createTree();
            break;
        case 2:
            if (head == NULL)
            {
                cout << "Tree is empty" << endl;
                break;
            }
            cout << "Tree in Inorder:" << endl;
            inOrder(head);
            cout << endl;
            break;

        case 3:
            if (head == NULL)
            {
                cout << "Tree is empty" << endl;
                break;
            }
            cout << "Tree in Preorder:" << endl;
            preOrder(head);
            cout << endl;
            break;

        case 4:
            if (head == NULL)
            {
                cout << "Tree is empty" << endl;
                break;
            }
            cout << "Tree in Postorder:" << endl;
            postOrder(head);
            cout << endl;
            break;

        case 5:
            if (head == NULL)
            {
                cout << "Tree is empty" << endl;
                break;
            }
            flag = 0;
            cout << "Enter element you want to search:" << endl;
            cin >> data;
            flag = searching(head, data, addNode, prevNode);
            if (flag == 0)
            {
                cout << endl
                     << data << " is not present in tree." << endl
                     << endl;
                break;
            }
            break;
        case 7:
            flag = 0;
            if (head == NULL)
            {
                cout << "Tree is empty" << endl;
                break;
            }
            int delNode;
            cout << "Enter node you want to delete:" << endl;
            cin >> delNode;
            flag = searching(head, delNode, addNode, prevNode);
            if (flag == 0)
            {
                cout << endl
                     << delNode << " is not present in tree." << endl
                     << endl;
                break;
            }
            deletion(delNode, prevNode, addNode);
            break;

        case 6:
            cout << "Enter data for insertion:" << endl;
            cin >> data;

        next2:
            cout << endl
                 << "1 for insertion at root" << endl;
            cout << "2 for insertion at node other than root" << endl;
            cout << endl
                 << "Enter your choice for insertion:" << endl;
            cin >> insertion_choice;

            switch (insertion_choice)
            {
            case 1:
                insertAtroot(head, data);
                break;
            case 2:
                flag = 0;

                int ref;
                cout << "Enter node at which you want the insertion:" << endl;
                cin >> ref;
                flag = searching(head, ref, addNode, prevNode);
                if (flag == 0)
                {
                    cout << endl
                         << ref << " is not present in tree." << endl
                         << endl;
                    break;
                }
                insertionAtnode(addNode, data);
                break;
            default:
                cout << "Invalid choice" << endl;
                goto next2;
                break;
            }
            break;

        default:
            cout << "Invalid choice" << endl;
            break;
        }
    }
}