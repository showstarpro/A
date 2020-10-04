#include "stdio.h"
#include "stdlib.h"
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

typedef int status;
typedef int ElemType; //数据元素类型定义

#define LIST_INIT_SIZE 100
#define LISTINCREMENT  10
typedef int ElemType;
typedef struct{  //顺序表（顺序结构）的定义
	      ElemType * elem;
	      int length;
	      int listsize;
}SqList;
typedef struct{  //线性表的管理表定义
     struct { char name[30];
     		  SqList L;	
      } elem[10];
      int length;
      int listsize;
 }LISTS;

status ListTraverse(SqList L)
// 如果线性表L存在，依次显示线性表中的元素，每个元素间空一格，返回OK；如果线性表L不存在，返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
if(L.elem==NULL)  return INFEASIBLE;
if(L.length!=0)
{
for(int i=0;i<=L.length-2;i++)
{
    printf("%d ",L.elem[i]);
}

printf("%d",L.elem[L.length-1]);
}
return OK;
    /********** End **********/
}

status ListInsert(SqList &L,int i,ElemType e)
// 如果线性表L存在，将元素e插入到线性表L的第i个元素之前，返回OK；当插入位置不正确时，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
if(L.elem==NULL)  return INFEASIBLE;
int j;
if(i<1||i>L.length+1)  
return ERROR;
if(L.length>=L.listsize)
{
    int *newbase;
    newbase=(int *)realloc(L.elem,(L.listsize+LISTINCREMENT)*sizeof(int));
    if(newbase==NULL) return ERROR;
    L.elem=newbase;
    L.listsize+=LISTINCREMENT;
}

for(j=L.length-1;j>=i-1;j--)
{
    L.elem[j+1]=L.elem[j];
}
L.elem[i-1]=e;
L.length++;
return OK;
    /********** End **********/
}

status AddList(LISTS &Lists,char ListName[])
{
// 只需要在Lists中增加一个名称为ListName的空线性表，线性表数据又后台测试程序插入。

    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
  int i = 0; 
    while(ListName[i]!='\0')
    {
        Lists.elem[Lists.length].name[i] = ListName[i];
        i++;
    }
    int *newbase;
    newbase = (int*)malloc(LIST_INIT_SIZE * sizeof(int));
    Lists.elem[Lists.length].L.elem = newbase;
    Lists.elem[Lists.length].L.length = 0;
    Lists.elem[Lists.length].L.listsize = LIST_INIT_SIZE;
    Lists.length++;
    /********** End **********/
}

status RemoveList(LISTS &Lists,char ListName[])
// Lists中删除一个名称为ListName的线性表
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    int i = 0;
    bool coms;
    for (i = 0; i <= Lists.length - 1;i++)
    {
       for (int j = 0; j <= 4;j++)
       {
          if(Lists.elem[i].name[j]==ListName[j])
             coms = TRUE;
             else
             {
                coms = FALSE;
                break;
             }
      }
       if(coms==TRUE)
          break;
    }

    if(coms==FALSE)
       return ERROR;
   else
   {
      for (int k = i; k <= Lists.length - 2;k++)
      {
         Lists.elem[i] = Lists.elem[i + 1];
      }
      Lists.length--;
      return OK;
   }

    /********** End **********/
}

int LocateList(LISTS Lists,char ListName[])
// 在Lists中查找一个名称为ListName的线性表，成功返回逻辑序号，否则返回0
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
   int i = 0;
    bool coms;
    for (i = 0; i <= Lists.length - 1;i++)
    {
       for (int j = 0; j <= 4;j++)
       {
          if(Lists.elem[i].name[j]==ListName[j])
             coms = TRUE;
             else
             {
                coms = FALSE;
                break;
             }
      }
       if(coms==TRUE)
          break;
    }
   if(coms==FALSE)
      return 0;
      else
         return i+1;

    /********** End **********/
}


int main() {
	LISTS Lists;
   int n,e;
   char name[30];
   Lists.length=0;
	scanf("%d", &n);
	while(n--)
   {
    	scanf("%s",name);
   		AddList(Lists,name);
      scanf("%d",&e);
      while (e)
      {
      		ListInsert(Lists.elem[Lists.length-1].L,Lists.elem[Lists.length-1].L.length+1,e);
      		scanf("%d",&e);
      }
   }
   scanf("%s",name);
   if (n=LocateList(Lists,name))
   		{
   			printf("%s ",Lists.elem[n-1].name);
   			ListTraverse(Lists.elem[n-1].L);
         putchar('\n');
   		}
   else printf("查找失败");
   return 1;
}