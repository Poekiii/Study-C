#include <stdio.h>
#include <string.h>
#include <errno.h>
/*-------------------文件操作----------------------*/
// 什么是文件
// 但是在程序设计中，我们一般谈的文件有两种：程序文件、数据文件
// 本章讨论的是数据文件。

// 1.文件类型
// 根据数据的组织形式，数据文件被称为文本文件或者二进制文件。
// 数据在内存中以二进制的形式存储，如果不加转换的输出到外存, 就是二进制文件.
// 如果要求在外存上以ASCII码的形式存储，则需要在存储前转换。以ASCII字符的形式存储的文件就是文本文件。

// 一个数据在内存中是怎么存储的呢？
// 字符一律以ASCII形式存储，数值型数据既可以用ASCII形式存储，也可以使用二进制形式存储。
// 如有整数10000，如果以ASCII码的形式输出到磁盘，则磁盘中占用5个字节（每个字符一个字节），而二进制形式输
// 出，则在磁盘上只占4个字节（VS2013测试）。

// 内存中的存储形式(二进制存储)                  ASCII形式储存
// 00000000 00000000 00100111 00010000  ----> 00110001(代表1) 00110000 00110000 00110000 00110000
// int main()
// {
//     int a = 10000;
//     FILE* pf = fopen("test.txt", "wb");//打开test.txt(若不存在那么创建一个) 并且以binary(二进制)格式write(写入)
//     fwrite(&a, 4, 1, pf);//二进制输入 把a地址处的数据 写一个4字节的数据 到pf地址处 
//     fclose(pf);//文件关闭
//     pf = NULL;
//     return 0;
// }

// 2.文件指针
// 缓冲文件系统中，关键的概念是“文件类型指针”，简称“文件指针”。
// 每个被使用的文件都在内存中开辟了一个相应的文件信息区，用来存放文件的相关信息（如文件的名字，文件状态及文件当前的位置等）。
// 这些信息是保存在一个[结构体变量]中的。该结构体类型是有系统声明的，取名FILE.
// typedef struct _iobuf
// {
//   char	*_ptr;
//   int	 _cnt;
//   char	*_base;
//   int	 _flag;
//   int	 _file;
//   int	 _charbuf;
//   int	 _bufsiz;
//   char	*_tmpfname;
// } FILE;

// FILE* pf;//文件指针变量
// 定义pf是一个指向FILE类型数据的指针变量。可以使pf指向某个文件的文件信息区（是一个结构体变量）。通过该文
// 件信息区中的信息就能够访问该文件。也就是说，通过文件指针变量能够找到与它关联的文件.

// 3.文件的打开和关闭
// 在编写程序的时候，在打开文件的同时，都会返回一个FILE*的指针变量指向该文件，也相当于建立了指针和文件的关系。
// ANSIC 规定使用fopen函数来打开文件，fclose来关闭文件。
// FILE * fopen ( const char * filename, const char * mode );
// int fclose ( FILE * stream );

// 文件使用方式  含义                                    如果指定文件不存在
// “r”（只读）  为了输入数据，打开一个已经存在的文本文件     出错
// “w”（只写）  为了输出数据，打开一个文本文件              建立一个新的文件
// “a”（追加）  向文本文件尾添加数据                       出错
// “rb”（只读） 为了输入数据，打开一个二进制文件            出错
// “wb”（只写） 为了输出数据，打开一个二进制文件            建立一个新的文件
// “ab”（追加） 向一个二进制文件尾添加数据                  出错
// “r+”（读写） 为了读和写，打开一个文本文件                出错
// “w+”（读写） 为了读和写，建议一个新的文件                建立一个新的文件
// “a+”（读写） 打开一个文件，在文件尾进行读写              建立一个新的文件
// “rb+”（读写） 为了读和写打开一个二进制文件               出错
// “wb+”（读写） 为了读和写，新建一个新的二进制文件          建立一个新的文件
// “ab+”（读写） 打开一个二进制文件，在文件尾进行读和写      建立一个新的文件

// int main()
// {
//     //打开文件test.txt
//     //相对路径
//     //.. 表示上一级路径
//     //.  表示当前路径
//     //fopen(".\test.txt", "wb");
//     //fopen("..\..\test.txt","wb"); //当前路径的上一级路径的上一级路径
//     //绝对路径
//     //C:\Users\poeki\... 因'\'会变成转义字符 所以需要两个'\\'
//     //fopen("C:\\Users\\poeki\\Desktop\\VC-Code-C\\Study-C\\3.08 - class eight and ContactByDynamicMem\\test.txt","r");
    
//     FILE* pf = fopen("test.txt", "r");//返回的是test.txt文件信息区的某地址
//     //"w"时 当写时 会重新建立一个文件(空白) 会把老的文件的内容清除掉
//     //"a"(追加)时 不会把老的数据清除
//     //当fopen打开失败会返回NULL
//     if(pf == NULL)
//     {
//         printf("%s\n", strerror(errno));
//         return 0;
//     }
//     //打开文件成功
//     //读文件

//     //文件关闭
//     fclose(pf);
//     pf = NULL;
//     return 0;
// }

// 4.文件的顺序读写
// 功能          函数名      适用于
// 字符输入函数   fgetc     所有输入流
// 字符输出函数   fputc     所有输出流
// 文本行输入函数 fgets     所有输入流
// 文本行输出函数 fputs     所有输出流
// 格式化输入函数 fscanf     所有输入流
// 格式化输出函数 fprintf    所有输出流
// 二进制输入     fread     文件
// 二进制输出     fwrite    文件

//写文件
// int main()
// {
//     FILE* pfw = fopen("test.txt", "w");//打开test.txt(若不存在那么创建一个) 并且以binary(二进制)格式write(写入)
//     if(pfw == NULL)
//     {
//         printf("%s\n", strerror(errno));
//     }
//     //写文件
//     fputc('h', pfw); //以字符形式写一个'b'到文件中
//     fputc('i', pfw);

//     //文件关闭
//     fclose(pfw);
//     pfw = NULL;
//     return 0;
// }

//读文件
// int main()
// {
//     FILE* pfr = fopen("test.txt", "r");//打开test.txt(若不存在那么创建一个) 并且以binary(二进制)格式write(写入)
//     if(pfr == NULL)
//     {
//         printf("%s\n", strerror(errno));
//     }
//     //写文件
//     printf("%c",fgetc(pfr)); //以字符形式读取 每次读取一个字符
//     printf("%c\n",fgetc(pfr)); //第二次使用的时候 指针会指到第二个字符

//     //文件关闭
//     fclose(pfr);
//     pfr = NULL;
//     return 0;
// }

//从键盘输入 输出到屏幕
//键盘和屏幕都是外部设备
//这两个设备使用时 不用程序员打开 一般都是默认打开的
//键盘 - 标准输入设备 stdin
//屏幕 - 标准输出设备 stdio
//是一个程序默认打开的两个流设备
//stdin FILE *类型
//stdout FILE *类型
//stderr FILE *类型
//而 fputc和fgetc 支持所有流的设备 是指不仅支持文件流 也支持标准流等等

//例如
// int main()
// {
//     int ch = fgetc(stdin); //从键盘上获取数据
//     fputc(ch, stdout); //从屏幕输出
//     return 0;
// }

// 5.文件的随机读写
#include <unistd.h>
int main()  
{
    while(1)
    {
        fprintf(stdout,"hello-std-out");
        fprintf(stderr,"hello-std-err");
        sleep(1);
    }
    return 0;
}