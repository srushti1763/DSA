#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct tree
{
    int data;
    struct tree *left;
    struct tree *right;
} TREE;

void random(FILE *fp,int n)
{
    for(int i=0;i<n;i++)
    {
        fprintf(fp,"%d ",rand()%100);
    }
}
TREE *insert_into_bst(TREE *root, int data)
{
    TREE *newnode;
    newnode = (TREE *)malloc(sizeof(TREE));
    if (newnode == NULL)
    {
        printf("Heap is running out of memory\n");
        return root;
    }

    newnode->data = data;
    newnode->left = newnode->right = NULL;

    if (root == NULL)
    {
        printf("Root created\n");
        root = newnode;
        return root;
    }

    TREE *cur = root, *parent = NULL;

    while (cur != NULL)
    {
        parent = cur;

        if (newnode->data < cur->data)
            cur = cur->left;
        else
            cur = cur->right;
    }

    if (newnode->data < parent->data)
        parent->left = newnode;
    else
        parent->right = newnode;

    return root;
}

void inorder(TREE *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d\t", root->data);
        inorder(root->right);
    }
}

void preorder(TREE *root)
{
    if (root != NULL)
    {
        printf("%d\t", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(TREE *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d\t", root->data);
    }
}

TREE *delete_from_bst(TREE *root, int data)
{
    if (root == NULL)
    {
        printf("Tree is empty\n");
        return root;
    }

    TREE *cur, *parent, *successor, *p;
    cur = root;
    parent = NULL;

    while (cur != NULL && cur->data != data)
    {
        parent = cur;
        if (data < cur->data)
            cur = cur->left;
        else
            cur = cur->right;
    }

    if (cur == NULL)
    {
        printf("Data not found in the tree\n");
        return root;
    }

    if (cur->left == NULL)
        p = cur->right;
    else if (cur->right == NULL)
        p = cur->left;
    else
    {
        successor = cur->right;
        while (successor->left != NULL)
            successor = successor->left;
        successor->left = cur->left;
        p = cur->right;
    }

    if (parent == NULL)
    {
        free(cur);
        return p;
    }

    if (cur == parent->left)
        parent->left = p;
    else
        parent->right = p;
    free(cur);
    return root;
}

void in_degree_of_root_node(TREE *root)
{
    if (root == NULL)
        printf("Root does not exist\n");
    else
        printf("In degree of the root node is 0\n");
}

void out_degree_of_root_node(TREE *root)
{
    if (root == NULL)
        printf("Root does not exist\n");
    else
    {
        if (root->right == NULL && root->left == NULL)
            printf("Out degree of root is 0\n");
        else if ((root->left == NULL && root->right != NULL) || (root->left != NULL && root->right == NULL))
            printf("Out degree of root is 1\n");
        else
            printf("Out degree of root is 2\n");
    }
}

int count_edges(TREE *root)
{
    static int count = 0;
    if (root != NULL)
    {
        count++;
        count_edges(root->left);
        count_edges(root->right);
    }
    return count;
}

void no_of_edges(TREE *root)
{
    if (root == NULL)
    {
        printf("Root does not exist\n");
    }

    else
    {
        if (root->right == NULL && root->left == NULL)
            printf("There is only root node and no edges in the tree\n");
        else
        {
            int count;
            count = count_edges(root);
            printf("There are %d edges in the tree\n", count - 1);
        }
    }
}

void minumum_value_element(TREE *root)
{
    if (root == NULL)
        printf("Root does not exist\n");
    else
    {
        if (root->left == NULL && root->right == NULL)
            printf("%d is the smallest value element in the tree\n", root->data);
        else if (root->left == NULL && root->right != NULL)
            printf("%d is the smallest value element in the tree\n", root->data);
        else
        {
            TREE *cur = root;
            while (cur->left != NULL)
            {
                cur = cur->left;
            }
            printf("%d is the smallest value element in the tree\n", cur->data);
        }
    }
}

void maximum_value_element(TREE *root)
{
    if (root == NULL)
        printf("Root does not exist\n");
    else
    {
        if (root->left == NULL && root->right == NULL)
            printf("%d is the largest value element in the tree\n", root->data);
        else if (root->left != NULL && root->right == NULL)
            printf("%d is the largest value element in the tree\n", root->data);
        else
        {
            TREE *cur = root;
            while (cur->right != NULL)
                cur = cur->right;
            printf("%d is the largest value element in the tree\n", cur->data);
        }
    }
}

void address_of_the_root_node(TREE *root)
{
    if (root == NULL)
        printf("Root does not exist\n");
    else
        printf("Address of root node is %d\n", root);
}

void memory_occupied_by_the_tree(TREE *root)
{
    if (root == NULL)
        printf("Root does not exist\n");
    else
    {
        int count = count_edges(root);
        printf("Tree has occupied %d bytes of memory\n", (count * sizeof(TREE)) / 2);
    }
}

int count_leaf_nodes(TREE *root)
{
    static int leaf;

    if (root != NULL)
    {
        if (root->left == NULL && root->right == NULL)
            leaf++;
        count_leaf_nodes(root->left);
        count_leaf_nodes(root->right);
    }

    return leaf;
}

void no_of_leaf_nodes(TREE *root)
{
    if (root == NULL)
        printf("Root does not exist\n");
    else
    {
        if (root != NULL && root->left == NULL && root->right == NULL)
            printf("There is only one leaf node, which is the root node\n");
        else
        {
            int count = count_leaf_nodes(root);
            printf("There are %d leaf nodes in the tree\n", count);
        }
    }
}

void out_degree_of_leaf_nodes(TREE *root)
{
    if (root == NULL)
        printf("Root does not exist\n");
    else
        printf("Out degree of all the leaf nodes in 0\n");
}

void edges_between_root_and_largest_element(TREE *root)
{
    if(root==NULL)
    printf("Root does not exist\n");
    else
    {
        if(root->right==NULL)
        printf("There are 0 edges between the root and largest value element\n");
        else
        {
            int count=0;
            TREE *cur=root;
            while(cur->right!=NULL)
            {
                cur=cur->right;
                count++;
            }
            printf("There are %d edges between the root and the largest value element\n",count);
        }
    }
}
void disp(TREE *root,int space)
{
    if(root==NULL)
        return;
    space+=10;
    disp(root->right,space);
    printf("\n");
    for(int i=10;i<=space;i++)
        printf(" ");
    printf("%d\n",root->data);
    disp(root->left,space);
}

int main()
{

    int num, i;
    TREE *root = NULL;
    printf(" Enter a number to set the limit for a random number \n");
    scanf (" %d", &num);

    FILE *fp=fopen("random.txt","w+");
    random(fp,num);
    rewind(fp);
    printf("1-Insert into BST\n2-Inorder\n3-Preorder\n4-Postorder\n5-Delete from BST\nAny other number-Exit program\n");

    while (1)
    {
        int choice, data;
        printf("Enter choice\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            fscanf(fp,"%d",&data);
            root = insert_into_bst(root, data);
            break;
        case 2:
            if (root == NULL)
                printf("Tree is empty\n");
            else
                inorder(root);
            break;
        case 3:
            if (root == NULL)
                printf("Tree is empty\n");
            else
                preorder(root);
            break;
        case 4:
            if (root == NULL)
                printf("Tree is empty\n");
            else
                postorder(root);
            break;
        case 5:
            printf("Enter the data to be deleted\n");
            scanf("%d", &data);
            root = delete_from_bst(root, data);
            break;
        default:
            printf("Program terminated successfully\n");
            break;
        }

        if (choice == 6)
            break;
    }
    disp(root,0);
    in_degree_of_root_node(root);
    out_degree_of_root_node(root);
    no_of_edges(root);
    minumum_value_element(root);
    maximum_value_element(root);
    address_of_the_root_node(root);
    memory_occupied_by_the_tree(root);
    no_of_leaf_nodes(root);
    out_degree_of_leaf_nodes(root);
    edges_between_root_and_largest_element(root);
   fclose(fp);
    return 0;
}
