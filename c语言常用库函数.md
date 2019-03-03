# string.h

* 字符串拷贝

  ```c
  //用 法: char *strcpy(char *destin, char *source);
  //拷贝所有字符
  #include <stdio.h>
  #include <string.h>
  int main(void)
  {
  	char string[10];
  	char *str1 = "abcdefghi";
  	strcpy(string, str1);
  	printf("%s\n", string);
  	return 0;
  }
  
  
  //拷贝n个字符,将字符串src中最多n个字符复制到字符数组dest中(它并不像strcpy一样遇到NULL才停止复制，而是等凑够n个字符才开始复制），返回指向dest的指针。
  //用法：char *strncpy(char * destin, char *source , int n_size)
  #include <stdio.h>
  #include <string.h>
  int main(void)
  {
  	char string[4] ;
  	char *str1 = "abcdefghi";
  	strncpy(string, str1,3);
      string[3] = '\0';  //必须加结束符
  	printf("%s\n", string);
  	return 0;
  }
  
  ```


* 