
c11 递归

    斐波拉契数列

    例子：走迷宫，使用递归
        


c12 数组
    
    数组在内存中的存储方式；（内存一直且连续）；

    数组寻址方式两种：（第一种是第二种的语法糖）

    1. ary[i]  

    2. int ary + sizeof(type) * i

    延伸：为什么从0开始不是从1开始；
    注意27分钟处的&3[ary]



    举例定位程序的入口点:

        1. 首先定位到0x00400000;
        2. 找到加0x3c个位置（4行-2个位）的值，也就是0x0040003c的值x，然后定位到0x00400000+x的位置（检查是否为pe）;
        3. 在上面的基础上，也就是0x00400000+x的基础上，定位到0x00400000+x+0x28的位置的值y
        4. 0x00400000+y;

    作业：自己写程序，读出自己的入口点地址   








c13(1.5h)

    前40分钟讲解学生（循环）迷宫例子，后50分钟讲解数组算法；

    int ary[2] = {1,2,3}
    ary++ //会报错，ary是个常量

    函数传递数组（如何传递）；


c14(44min)

    二维数组

    寻址方式：


    arr[x][y] 每个元素寻址方式

    (int) ary + sizeof(type[N])*x  + sizeof(type)*y

    举例寻址方式

c15(1.5h)

    字符与字符串

    putchar

    getchar/fflush/rewind

    两种字符串风格



    字符数组与字符串的区别

c16(1h)

内存特性： wres
write read execute share


程序的在内存中的分段概念：
code 可执行代码(re)

data:（全局变量、静态变量，常量）
     inited(已初始化)，一部分只读，一部分可读可写
     uninited（未初始化）

stack(rw，参数变量，局部变量)
heap(rw，)

全局变量作用域 作用域为工程内各个源码文件都能访问    生命周期为模块载入到模块卸载

静态全局变量 定义文件内可以访问 载入到卸载
静态局部变量 定义函数内可以访问 载入到卸载

块作用俞：

```c
    {
        int a = 1;
    }

```

全局变量


初始化字符串时，exe文件会变大


c17

静态变量就是全局变量

静态全局变量与全局变量的区别“



编译器实现静态变量在作用域调用，使用名称粉碎；


45分钟 宏、寄存器变量


C18


1. 数值宏
    所有字母大写

    #define PI 3.1415926

2.  表达式宏

#define AREA(r) r*r*PI

3. 代码段宏

    #define SHOW_INFO(s) printf(s);printf("\r\n")

4. 兼容性宏

    for循环在vc6里是局部作用域， 在vc2019是块作用域；


   1. #define for if(1) for

   2.  一个#，表示转义为字符串
        
        #define STRING(s) #s

        char szBuf[] = STRING(1234);

	    printf("%s", szBuf);

   3. 两个”##“表示链接,还可以连接函数
   
        #define DEF_INT(s) int n##s

        DEf_INT(Test) = 8;

        // int nTest = 8;


c19(70分钟)

5. 编译选项宏

    // cl /D   

    编译预处理

    1. #if #endif
    2. #ifdef #endif
    3. #ifndef #endif
    4. #if defined() #endif

    可以通过ide添加宏；避免在头文件添加


6. 编译器内置宏(非标准)


    （25分钟） 添加编译选项卡： build- configuration - add  预编译z在最后一栏+/p



7. 解决头文件重复包含（写在头文件里）

    #ifndef MYLIB_H（使用全球唯一标识符）
    #define MYLIB_H
    #endif


    GUID全球唯一标识符


8. unicode(43分钟开始)

     ascii: 每个字符站一个编码,中文两个字符(正的取一个，负的取两个)




    解决问题：



    vc6调ascii转utf


应用：用宏实现unicode兼容



c20

    指针
    
    运算法则：

        加减乘除得到的都是常量；

        type *ptr = ...;

        ptr+n = (int)ptr + sizeof(type) * n;

        ptr[n] = *(type *)((int)ptr+ sizeof(type) *  n)


    指针运算：

        指针相减：

        type *p1 = ...;
        type *p2 = ...;

        p1-p2=((int)p1 -(int)p2)/sizeof(type); 得到元素个数；

       
c21:

    *跟变量走；

    float取指针；


    35分钟之前 stdarg.h

    35分钟之后

        char *psz = "hello world";
        char szBuf[] = "hello";

        szBuf[0] = "h";
        puts(szBuf)

        psz[0] = "h";
        puts(szBuf)

        字符串与数组的区别：

        "const char *" 类型的值不能用于初始化 "char *" 类型的实体


c22:

    指针

    1. void * 指针 memoset()参数是这个指针

    2. strcpy返回char*, 使用链式调用 

    27分钟

    函数指针

    bug： 浮点初始化：float f;scanf("%f", &f);    

    编译器检查有没有返回值：检查是否有return;

c23:    
    
    1.指针函数

    函数不能返回局部变量与参数的地址，并不是说不能返回地址；是可以返回指针的

    sizeof("ff"); 字符串字面里值传给函数

    char *st="1111";
    st[0] = "1" 不能修改是因为，字面量值存在内存不可更改的区域；
    
    2. 工程的组织（52分钟开始）

    - 如何建工程

        为什么要用.h?

        编译报错，链接报错；（在文件中测试，编译与链接的文件内容）

        包含.cpp文件；

    - 宏

        只替换一次

c24: 函数指针

    函数名表示函数第一条指令的地址

    跟数组很相似

    double (__cdecl *pfn)(int, float) = NULL;

    pfn = foo;

    (*pfn)(5, 0.618f) 直接调用
    
    pfn(5,0.618f) 间接调用

    28分钟：应用
    1.例子：斗地主

    2. 还可以实现热更新
    
    3. typedef 与 def的区别

    4. typedef 函数指针

    5. 函数指针数组

        1.  void (*pfnAry[])() = {Func, FunA, Fund}   //好别扭的写法
        2. typedef void (*PFNARY)();
            PFNATY pfnAry[] = {
                Func,FunA,Fund
            }


c25:

    

    1. 指针数组    
    
    使用场景：变长字符串

        char *arr[5] = {
            "test",
            "wwwsddqw3er",
            "wwwkljjer",
            "waawwer",
            "wwwer",
        }

        int ary[3][5] = {
            {1,2,3,4,5},
            {1,2,3,4,5},
            {1,2,3,4,5},
        }

        int (*p)[5] = ary;
        int *p2 = ary[0];   


        char *arr[5] 与 char arr[3][5]对比
    
        1.指针存储比较省空间
        2.指针查找数组稍慢，多了一次指针查找 
    
    2. 数组指针 
    
     int ary[3][5] = {
            {1,2,3,4,5},
            {1,2,3,4,5},
            {1,2,3,4,5},
        }

        int (*p)[5] = ary;   //定义一个int[5]发指针 


    3. 21分钟开始 指针数组的例子

        ```c

            int ary[3][5] = {
                {1,2,3,4,5},
                {1,2,3,4,5},
                {1,2,3,4,5},
            };

            int (* pAry)[5] = ary;

            printf("%p\r\n", pAry);
            printf("%p\r\n", *pAry);

            printf("%d\r\n", sizeof(pAry));
            printf("%\r\n", sizeof(*pAry));

            printf("%p\r\n", pAry+1);   //pAry是一个int *[5]的指针
            printf("%p\r\n", *pAry+1); // *pAry是一个int*指针


            printf("%p\r\n", (pAry + 1)[1]);
            printf("%p\r\n", (*pAry + 1)[1]);


            printf("%p\r\n", (*(pAry + 1))[1]);
            printf("%p\r\n", (*(pAry + 1)+1)[1]);
        
        
        ```

        指针跟整数相加；

    4. 指向指针的指针（53分钟开始）

        二级指针：
            使用场景：参数返回指针值


c26

    结构体

    1. c与c++中的使用区别，cpp使用时，不需要加struct

    2. 结构体指针

    3. .与->的区别；


    原理（15分钟）：

    1. 结构体成员会对齐 


    换位置有什么影响
        ```c

            struct tagPerson
            {

                char szName[5];
                float fHeight;
                double dblWeight;
                char cGender;
                int nID;
                unsigned short int wAge;
            }
        
        ```


    zp:编译对齐值zp
    member type: 结构体成员的类型为

    每个结构体成员的偏移量offset

    公式：

        offset % min(zp, sizeof(member type))  == 0

        步骤：
        
        1. 先给一个默认的offset，默认的为上一个字段的sizeof加上上一个字段的 
        2. 然后使用上面的公式 
    
    结构体整体对齐值：

        公式：  
        
            Aligh = min(zp, max(sizeof(member1 type,...)));  //成员中size最大值与zp比较

            offset % Aligh = 0  //满足条件

    2. 乱七八糟的问题 （52分钟开始分钟）
    
    3. 结构体嵌套 （58分钟开始）

        offset % min(zp, 被嵌套结构体的align)  == 0
        


    4. .与 ->（61分钟开始）

        1. 结构体首地址+偏移量
        2. 



    5. 结构体传参（1h23min开始）

        
    6. #pragma 针对不同方式的对齐
    
    

c27:

    1. 柔性数组
    2. 共用体
    3. 枚举
    4.
    1h08m: malloc and free



c28:

    前6分钟：
        调试版堆的相关格式理论


        地址减32字节的位置，每4个字节

        1st：前一个堆的位置
        2th：后一个堆的位置
        3th：申请堆所在的文件的全路径
        4th:申请堆所在的行
        5th:堆申请的size
        6th:申请堆的类型
        7th: 堆的编号
        8th:堆的上溢标志

        堆正文...

        nth:下溢标志

    7min开始：
        添加堆的文件位置以及例子
    
        1.申请调试信息的堆

            _malloc_dbg(8,_NORMAL_BLOCK,__FILE__,__LINE)  //crtdbg.h

    21分钟：
        调试堆：
            
            数据断点
            内存写入端点调试，监控某一段有没有改变

            跟断点没啥关系： 1.写代码考虑兼容unicode

    33分钟开始：

        动态规范：

            ```c

                //定义指针或资源变量时，初始值必须设定为无效值
                int *pInt = NULL;

                pInt = (int *)malloc(sizeof(int));

                //申请资源后必须检查是否失败

                if(pInt == NULL){
                    
                    // 如果失败，转到异常处理
                    errorProc();

                    // 然后转到出口
                    goto EXIT_PROC;

                }
                
                // 使用资源
                *pInt = 999;

                EXIT_PROC:

                    // 在出口处，检查指针或资源是否失效  why?
                    if(pInt !=NULL) 
                    {   
                        // 如果有效，则释放资源
                        free(pInt);

                        //释放完成后，指针变量设为无效值    
                        pInt = NULL;
                    }   

            
            ```

c29:

    位运算 


c31:

    文件

    位段



















    





    





















