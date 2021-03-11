/*------------------预编译----------------------*/
//一、条件编译
// 在编译一个程序的时候我们如果要将一条语句（一组语句）编译或者放弃是很方便的。因为我们有条件编译指令。
// 比如说：
// 调试性的代码，删除可惜，保留又碍事，所以我们可以选择性的编译。

// #include <stdio.h>
// #define DEBUG
// int main()
// {
//     int arr[4] = {1, 2, 3, 4};
//     int i = 0;
//     for (i = 0; i < 4; i++)
//     {
//         arr[i] = 0;
//     #ifdef DEBUG  //如果定义了DEBUG时候 下句才编译 这个也是预处理阶段处理的
//         printf("%d ", arr[i]); //此句是为了查看赋值是否成功
//     #endif
//     }
//     return 0;
// }

// 1. 条件编译
//     #if 常量表达式
//     //... 
//     #endif 
// //常量表达式由预处理器求值。
// 如：
//     #define __DEBUG__ 1 
//     #if __DEBUG__ 
//     //.. 
//     #endif 

// 2.多个分支的条件编译
//     #if 常量表达式
//     //... 
//     #elif 常量表达式
//     //... 
//     #else 
//     //... 
//     #endif 

// 3.判断是否被定义
//     #if defined(symbol) 
//     #ifdef symbol 
//     #if !defined(symbol) 
//     #ifndef symbol 

// 4.嵌套指令
//     #if defined(OS_UNIX) 
//         #ifdef OPTION1 
//         unix_version_option1(); 
//         #endif 
//         #ifdef OPTION2 
//         unix_version_option2(); 
//         #endif 
//     #elif defined(OS_MSDOS) 
//         #ifdef OPTION2 
//         msdos_version_option2(); 
//         #endif 
//     #endif

//二、头文件包含

// #include <stdio.h>
// 查找策略:
// 查找头文件直接去标准路径下去查找，如果找不到就提示编译错误。

// #include "add.h"
// 查找策略:
// 先在源文件所在目录下查找，
// 如果该头文件未找到，编译器就像查找库函数头文件一样在标准位置查找头文件。 
// 如果找不到就提示编译错误。

// 条件编译--->可以避免头文件内容的重复编译
// #ifndef __TEST_H__ 
// #define __TEST_H__ 
// //头文件的内容
// #endif //__TEST_H__ 
