#include <stdio.h>


//判断机器的字节序
int check_sys()
{
    int a = 1;

    //指针类型 
    //1.决定了访问几个字节 char* 访问1个字节
    //2.决定了+1或者-1跳过几个字节
    char *p = (char *)&a;  
    //1：小端 0：大端
    return *p;
}
int main()
{
    int ret;
    ret = check_sys();
    if(ret == 1)
    {
        printf("小端");
    }
    else
    {
        printf("大端");
    }
    return 0;
}