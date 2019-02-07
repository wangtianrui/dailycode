## 复杂度

空间复杂度O(1) ： 所需辅助空间是常量

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

    >循环次数为：length1 + length2
    >
    >每次比较两个数组index1与index2的大小，小的加入新数组，index+1
    >
    >若index>length，则另一个数组的index+1并将另一个数组的index数加入新数组

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



## 链表

