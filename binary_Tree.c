#include<stdio.h>
#include<stdlib.h>

struct tree {
    int data;
    struct tree *left,*right;
};
struct tree *root;

struct tree *creat(){
    struct tree *newnode;
    int x;
    newnode = (struct tree *)malloc(sizeof(struct tree));
    printf("Enter the data:");
    scanf("%d", &x);
    if (x == -1)
    {
        return 0;
    }
    newnode->data = x;
    printf("Enter th left child of %d: ", x);
    newnode->left = creat();
    printf("Enter th right child of %d: ", x);
    newnode->right=creat();
}

void preprint(struct tree * root){
    if(root==NULL){
        return;
    }
    printf("\n %d ",root->data),
    preprint(root->left);
    preprint(root->right);
}

int main(){
    struct tree *root;
    root=NULL;
    root=creat();
    printf("preorder is: ");
    preprint(root);

}