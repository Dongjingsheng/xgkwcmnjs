#include"SeqList.h"
#include<iostream>
using namespace std;
int main()
{
    int i,j; ElemType e,x;
    int k;
    SqList La;
   while(1)
    {   cout<<"\n\t\t              —顺序表—\n\n";
        cout<<"\t\t\t          菜单     \n";
        cout<<"\t\t\t ——— ————— ——\n";
        cout<<"\t\t\t   1. 建立顺序表              \n";
        cout<<"\t\t\t   2. 在i位置插入元素e \n";
        cout<<"\t\t\t   3. 删除第i个元素        \n";
        cout<<"\t\t\t   4. 查找值为 e 的元素\n";
        cout<<"\t\t\t   0. 退出                            \n";
        cout<<"\t\t\t ———————————\n";
        cout<<"\t\t\t    请选择(0-4):";
        cin>>k;
        switch(k)
        {
            case 1:InitList_Sq(La);  cout<<"创建了一个空的顺序表！"<<endl;break;
	        case 2:cout<<"\n请输入插入的位置和值：";
	                     cin>>i>>x;
	                     ListInsert_Sq(La,i,x);
	                     cout<<"\n插入成功后的顺序表为：";
	                     display(La);
                         break;
             case 3:cout<<"\n请输入删除的位置：";
	                     cin>>i;
	                     ListDelete_Sq(La,i,e);
	                     cout<<"\n删除成功后的顺序表为：";
	                     display(La);
                         break;
	        case 4:cout<<"\n请要找的元素值：";
	                     cin>>x;
	                     j=LocateElem_Sq( La, x);
	                     if(j!=0)cout<<"\n找到了，元素"<<x<<"的位置为："<<j;
	                     else  cout<<"\n没找到！";
                         break;
           case 0: cout<<"\n\t\t\t------ 谢谢使用！-------\n";
                         cout<<"\n\t\t\t按任意键退出......\n";
                         return 0;


	   } // switch
     }//while
  } // main
