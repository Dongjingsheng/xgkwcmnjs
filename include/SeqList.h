
#include <stdio.h>
#include <malloc.h>
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

#define list_init_size 100   //线性表存储空间的初始分配量
#define LISTINCREMENT 10     //线性表存储空间的分配增量

typedef int Status;
typedef int ElemType;

typedef struct{
	ElemType *elem;          //存储空间基址
	int length;              //当前长度
	int listsize;            //当前分配的存储容量（以sizeof(ElemType)为单位）
}SqList;

Status InitList_Sq(SqList &L){
	//构造一个空的线性表L
	L.elem =(ElemType * )malloc(list_init_size*sizeof(ElemType));
	if(!L.elem )exit(OVERFLOW);//存储分配失败
	L.length =0;               //空表长度为0
	L.listsize =list_init_size;//初始存储容量
	return OK;
}//Initlist_Sq

Status ListInsert_Sq(SqList &L,int i,ElemType e){
	//在顺序线性表L中第i个位置之前插入新的元素e，
	//i的合法值为1<=i<=ListLength_Sq(L)+1
	ElemType *p,*q,*newbase;        //定义指针
	if(i<1||i>L.length +1)
		return ERROR;               //i值不合法
	if(L.length >=L.listsize ){     //当前存储空间已满，增加分配
		newbase=(ElemType * )realloc(L.elem ,(L.listsize +LISTINCREMENT)*sizeof(ElemType));
		if(!newbase)exit(OVERFLOW); //存储分配失败
		L.elem =newbase;            //新基址
		L.listsize +=LISTINCREMENT; //增加存储容量
	}
	q=&(L.elem [i-1]);              //q为插入位置
	for(p=&(L.elem [L.length -1]);p>=q;--p)
		*(p+1)=*p;                  //插入位置及之后的元素右移
	*q=e;                           //插入e
	++L.length ;                    //表长增1
	return OK;
}//ListInsert_Sq

Status ListDelete_Sq(SqList &L,int i,ElemType &e){
	//在顺序线性表L中删除第i个元素，并用e返回其值
	//i的合法值为1<=i<=ListLength_Sq(L)
	ElemType *p,*q;                  //定义指针
	if((i<1) || (i>L.length ))
		return ERROR;                //i值不合法
	p=&(L.elem [i-1]);               //p为被删除元素的位置
	e=*p;                            //被删除元素的值赋给e
	q=L.elem +L.length -1;           //表尾元素的位置
	for(++p;p<=q;++p)
		*(p-1)=*p;                   //被删除元素之后的元素左移
	--L.length ;                     //表长减1
	return OK;
}//ListDelete_sq

int LocateElem_Sq(SqList L,ElemType e)
{
	//在顺序线性表L中查找第1个值与e满足compare()的元素的位序
	//若找到，则返回其在L中的位序，否则返回0
	ElemType *p;
	int i=1;                //i的初值为第一个元素的位序
	p=L.elem ;             //p的初值为第一个元素的存储位置
	while(i<=L.length && *p++!=e) ++i;
	if(i<=L.length) return i;
	else return 0;
}//LocateElem_Sq

void MergeList_Sq(SqList La,SqList Lb,SqList &Lc ){
	//已知顺序线性表La和Lb的元素按值非递减排列
	//归并La和Lb得到新的顺序线性表Lc，Lc的元素也按非递减排列
	ElemType *pa,*pb,*pc,*pa_last,*pb_last;
	pa=La.elem ;
	pb=Lb.elem ;
	Lc.listsize =Lc.length =La.length +Lb.length ;
	pc=Lc.elem =(ElemType *)malloc(Lc.listsize *sizeof(ElemType));
	if(!Lc.elem )exit(OVERFLOW);  //存储分配失败
	pa_last=La.elem +La.length -1;
	pb_last=Lb.elem +Lb.length -1;
	while(pa<=pa_last && pb<=pb_last)
	{
		//归并
		if(*pa<=*pb)
			*pc++=*pa++;
		else
			*pc++=*pb++;
	}
	while(pa<=pa_last) *pc++=*pa++;        //插入La的剩余元素
	while(pb<=pb_last) *pc++=*pb++;        //插入Lb的剩余元素
}//MergeList_Sq

void display(SqList L)
{   //输出
	int i;
	for(i=0;i<=L.length -1;i++)
		printf("%d\t",L.elem [i]);
}
