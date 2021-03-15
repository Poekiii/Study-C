#include <stdio.h>
int main()
{
    char c;
    printf("输入一个字符:>");
	scanf("%c", &c);
    while(c != 'Y')
	{
        printf("当前的字符是:%c",c);
	    scanf("%c", &c);
	}
    return 0;
}

// scanf("%c",&c)  
// 当输入一个字符串时 scanf会读取标志输入设备的第一个字符没错 
// 但是缓存会把后面的回车缓存进去 
// 而scanf读取可一个字符以后 指针会自动移到下一个位置读取  

// 例如:当输入aaaa回车时
// 输入一个字符:>aaaa
// 当前的字符是:a当前的字符是:a当前的字符是:a当前的字符是:a当前的字符是:
// 
