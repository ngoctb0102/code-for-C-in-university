#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define ORDER    5

typedef struct tagNODE
{
    int  NumTree;              // số cây con của node hiện hành
    int  Key[ORDER-1];    // mảng lưu trữ các khoá của node
    NODE* Branch[ORDER];  // các con trỏ chỉ đến các node con
} NODE, *NODEPTR, *BTREE; // con trỏ node

NODEPTR Root ;// con trỏ node gốc
 int NodeSearch (NODEPTR p, int k)
{
    int i = 0;
    for (i=0; i< p->NumTree - 1 && p->Key[i] < k; i++);
    return i;
}
NODEPTR Search(int k, int *pPosition, int *pFound)
     {
             int   i = 0;
             NODEPTR   p = Root, q = NULL;;    
             while (p !=NULL)
             {
                     i = NodeSearch (p, k);

                     if (i< p->NumTree - 1 && k == p->Key[i])
                     {
                             *pFound    = 1;
                             *pPosition = i; //Vị trí tìm thấy khóa k

                             return p;           // Node có chứa khóa K
                     }
                     q = p;
                     p = p ->Branch[i];
             }

             /* Không tìm thấy, lúc này p = NULL, và q là node lá có thể thêm khóa k vào node này, pPosition là vị trí có thể chèn khóa k */
             *pFound    = 0;
             *pPosition = i;

             return q; // Trả về node lá
     }
     void Scan(NODEPRT pRoot)
     {
            if (pRoot== NULL)
                     return;
            else
            {
                     /* Vòng lặp duyệt nhánh cây con Branch[i] và khóa Key[i] của node pRoot */
                     for (int i = 0; i < pRoot-> numtress-1; i++)
                     {
                             Scan(pRoot->Branch[i]);
                             printf ("%8d", pRoot-> Key[i]);
                     }

                     /* Duyệt nhánh cây con cuối cùng của node pRoot */
                     Scan (pRoot-> Branch[pRoot-> NumTrees-1]);
            }
     }