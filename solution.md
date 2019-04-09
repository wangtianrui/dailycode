## 复杂度

空间复杂度O(1) ： 所需辅助空间是常量

用两次循环的时间复杂度比嵌套循环小得多！

## 数组

* 删除元素

  **注意判空！！！！！**

  * 删除值为x的元素

    > 删除！=干掉然后后面的前摞
    >
    > 方法一：可以直接覆盖，count从0开始，如果不为x则a[count]=a[i] ; count++    （次方法count是记非x的数量）
    >
    > 方法二：a[i-count]=a[i]   （count是等于x的数量）
    >
    > 总结：要改只能改已经遍历过的位置，只要不是x就按照原来的顺序覆盖掉原来的数组就行

  * 删除最小值

    > 找到最小值：循环一次，记下最小值的index
    >
    > 删除：从index=0开始覆盖：a[count]=a[i]    if(i==index_min) continue; 

  * 删除有序中重复的元素

    >a[i]!=a[i+1] : a[count++]=a[i]

* 合并两数组

  * 合并两个有序数组成为一个新的有序数组

    >循环次数为：length1 + length2 （分为两部分完成：①min_length长度的比较，选择小的加入到新数组②bigger_length-min_length长度直接添加）
    >
    >每次比较两个数组index1与index2的大小，小的加入新数组，index+1
    >
    >若index>min（length1,length2），则开辟新的循环，将剩下的加到数组后面即可

* **交换顺序**

  * 数组逆置（reserve）

    >循环（length/2）次，只用一个i ，每次交换 a[i] 与 a[length-1-i]

  * [a1 a2 a3 a4 b1 b2] -> [b1 b2 a1 a2 a3 a4]

    >子问题划分：三次“reserve”    
    >
    >①[b2 b1 a4 a3 a2 a1]
    >
    >②[b1 b2 a4 a3 a2 a1]
    >
    >③[b1 b2 a1 a2 a3 a4]

* 查找

  * 二分查找

    >while(star < end)     if(a[mid]>target)    end = mid-1     //注意这里要减一，不然会出现死循环
    >
    >如果没有找到：那么a[end] < target < a[star]  ， 并且end在star的前一位 
    >
    >如果在端点处找到：star == end ，但是跳出时star = end = 0 或者star = end = length-1
    >
    >如果没找到，且target > max 则 star > end 且star = length - 1 + 1反之则end=-1
    >
    >注意如果在找到后要进行什么交换操作，请注意在端点处的情况，会越界！！！！

    * 查找两个有序数组合并起来后的中位数，用二分法时间复杂度更低。但是要注意边界问题和跳出循环的条件

* 插入

  * 在指定位置插入

    >倒着来，从后往前，for (i=length-1,i>target_index,i--) a[i+1]=a[i]

比较好的题：查找主数（数组中出现次数大于length/2的数，只用两次循环：时间复杂度为O(n)）

## 链表

通常第一个节点为空

* 链表的结点声明

  ```c++
  typedef int ElemType;
  typedef struct LNode {
  	ElemType value;
  	struct LNode * next;
  }LNode, *LinkList;    //这里LinkList直接表示
  ```

* 插入

  * 头插

  ```c++
  LinkList insertOnHead(LinkList L)
  {
      //注意第一个为空
      if(L == NULL)
      {
          L = (LinkList)malloc(sizeof(LinkList));
          L->next = NULL;
      }
      int x ;
      scanf("%d",&x);
      while(x!=999)//输入999停止输入
      {
          LinkList p = (LinkList)malloc(sizeof(LinkList));
          p->value = x ;
          p->next = L->next;
          L->next = p;
          scanf("%d",&x);
      }
      return L;
  }
  ```

  * 尾插

  ```c++
  LinkList insertOnTail(LinkList L)
  {
      if(L == NULL)
      {
          L = (LinkList)malloc(sizeof(LinkList));
          L->next = NULL;
      }
      int x = 0 ;
      scanf("%d",&x);
      while(x!=999)
      {
          while()
          LinkList p = (LinkList)malloc(sizeof(LinkList));
          p->value = x ;
      }
      return L;
  }
  ```

