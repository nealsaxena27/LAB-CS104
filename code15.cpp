# include <bits/stdc++.h>
using namespace std;

# define MAX_SIZE 10000

struct sparse_matrix
{
    int row;
    int col;
    int val;
};

typedef struct sparse_matrix sparse_matrix;

void read_sparse_matrix(sparse_matrix mat[]){
    int m, n;
    cin>>m>>n;
    mat[0].row = m; mat[0].col = n;
    int k = 1;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int x;
            cin>>x;
            if(x!=0){
                mat[k].row = i;
                mat[k].col = j;
                mat[k].val = x;
                k++;
            }
        }
    }
    mat[0].val = k - 1;
}

void print_sparse_matrix(sparse_matrix mat[]){
    int rows = mat[0].row;
    int cols = mat[0].col;
    int size = mat[0].val;
    int k = 1;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if(k <= size && i==mat[k].row && j==mat[k].col){
                printf("%6d ",mat[k++].val);
            }
            else{
                printf("%6d",0);
            }
        }
        cout<<endl;
    }
}

void add_sparse_matrix(sparse_matrix mat1[], sparse_matrix mat2[], sparse_matrix mat3[]){
    int size1 = mat1[0].val, size2 = mat2[0].val;
    int l = 1, r = 1, k = 1;
    while(l <= size1 && r <= size2){
        if(mat1[l].row==mat2[r].row && mat1[l].col==mat2[r].col){
            if(mat1[l].val + mat2[r].val != 0){
                mat3[k].row = mat1[l].row;
                mat3[k].col = mat1[l].col;
                mat3[k].val = mat1[l].val + mat2[r].val;
                k++;
            }
            l++; r++;
        }
        else if((mat1[l].row < mat2[r].row) || (mat1[l].row==mat2[r].row && mat1[l].col < mat2[r].col)){
            mat3[k].row = mat1[l].row;
            mat3[k].col = mat1[l].col;
            mat3[k].val = mat1[l].val;
            k++; l++;
        }
        else{
            mat3[k].row = mat2[r].row;
            mat3[k].col = mat2[r].col;
            mat3[k].val = mat2[r].val;
            k++; r++;
        }
    }
    while(l <= size1){
        mat3[k].row = mat1[l].row;
        mat3[k].col = mat1[l].col;
        mat3[k].val = mat1[l].val;
        k++; l++;
    }
    while(l <= size2){
        mat3[k].row = mat2[r].row;
        mat3[k].col = mat2[r].col;
        mat3[k].val = mat2[r].val;
        k++; r++;
    }
    mat3[0].row = mat1[0].row;
    mat3[0].col = mat1[0].col;
    mat3[0].val = k - 1;
}


int main(){
    sparse_matrix mat1[MAX_SIZE];
    sparse_matrix mat2[MAX_SIZE];
    read_sparse_matrix(mat1);
    read_sparse_matrix(mat2);
    print_sparse_matrix(mat1);
    print_sparse_matrix(mat2);
    sparse_matrix mat3[MAX_SIZE];
    add_sparse_matrix(mat1,mat2,mat3);
    print_sparse_matrix(mat3);
}