#include <stdio.h>
#include <string.h>
#include <errno.h>

/*-------------------文件操作2----------------------*/
//4.文件的顺序读写 - 补充
// scanf/fscanf/sscanf
// printf/fprintf/sprintf

//键盘 - 标准输入设备 stdin
//屏幕 - 标准输出设备 stdio

//scanf/printf - 是针对标准输入/输出设备流 的格式化输入/输出
//例如:scanf("%d",&a); printf("%d\n",a);
// %a             十六进制浮点数
// %c             字符
// %d             有符号十进制整数
// %f             浮点数(包括float和double)
// %e             浮点数指数输出[e-(E-)记数法]
// %g             浮点数不显无意义的零"0"
// %i             有符号十进制整数(与%d相同)
// %u             无符号十进制整数
// %o             八进制整数    
// %x             十六进制整数
// %p             指针地址
// %s             字符串
// %%             "%"

//fscanf/fprintf - 是针对所有输入/输出设备流 的格式化输入/输出
//int fprintf( FILE *stream, const char *format, [ argument ]... );
//int fscanf ( FILE *fp,const char * format, [ argument ]... );

//sscanf - 是从字符串中读取格式化数据
//sprintf - 是从格式化数据中输出存储成字符串

// struct S
// {
//     int n;
//     char b;
// };
// int main()
// {
//     struct S s = {1,'b'};
//     struct S a = {0};
//     char buf[1024] = {0};

//     FILE *pf = fopen("text.txt", "w");//读和写 但是没有文件时 出错
//     if (pf == NULL)
//     {
//         return 0;
//     }
//     //第一组
//     // scanf("%d %c", &s.n, &s.b); //读取键盘中的数据
//     // printf("%d %c\n", s.n, s.b); //把数据输出到屏幕
//     //第二组
//     // fscanf(pf, "%d %c", &a.n, &a.b); //从文件中读取数据并且把他赋值给...
//     // fprintf(pf, "%d %c", s.n + 1, s.b);//向文件中输入数据
//     //第三组
//     sprintf(buf, "%d %c", s.n, s.b);//把对应数据转化成字符串形式 并储存到buf数组中
//     // printf("%s\n", buf); 
//     sscanf(buf, "%d %c", &(a.n), &(a.b));//把buf中的字符串转换成对应格式数据 并放到对应地址
//     printf("%d %c\n", a.n, a.b);

//     //关闭文件
//     fclose(pf);
//     pf = NULL;
//     return 0;
// }

