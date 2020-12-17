### c++输入输出上

- 为什么学习c++?

    c++跟c对比？
    开发效率更快

   2. c++版本 
    
    https://isocpp.org  查看编辑器的兼容性

    https://zh.cppreference.com  语法标准


<!-- 34分钟开始 -->

- c++对c的提升

    类型敏感

    ```c++
    
        int n3 = {5.6} // 类型严格匹配



    ```

    类型占位符

    1. 注意跟js中的var的区别
    2. 可以根据复制推断类型
    3. decltype

    
    ```c++
        
        <!-- 类型推导 -->

        auto n0 = 3;  //3分配为int 类型

    
    ```


    空指针

        NULL
        nullptr


    范围迭代

        ```c++

            for(int val:ary){
                printf("%d", val);
            }
        
        ```



### c++输入输出下

<< 作用域运算符    自动识别类型；

using namespace


设置进制的两种写法：


    ```c++


    
    ```

- 浮点



    ```c++

        std::fixed<<13.6958<<endl; //定点
        std::scientific<<13.6958<<endl; //科学计数法


        // 精度

        cout.percision(3); //精度  对于定点，显示的是所有的位

    
    
    ```

- 对齐

    ```c++

        cout.width(40);

        cout<< std::right << "world" << endl;
    
    ```


- 输入

    不读取空格
    ```c++
        char szBuff[255] = { 0 };
	    int n = 0;

        cin >> szBuff ;
        int nCntAvil = cin.rdbuf()->in_avail();
	    cin.ignore(nCntAvil);
    
    ```

    读取部分空格
    ```c++
        char ary[255] = { 0 };

        cin.getline(ary, sizeof(ary));

        
	 
    
    ```






### 布尔/const

1. c语言使用布尔类型的方法

```c

typedef int BOOL;
#define TRUE 1
#define FALSE 0

int main(){
    BOOL bVal = TRUE;
    bVal = FALSE;
}



```

2. const

    - 作用：定义一个常量；

    - 为什么会出现：对c语言中的**无参宏**进行了改进

      

    - 场景： const 修饰指针 （34分钟）

        const type *p;    p指针本身可以修改；指向的内容不能修改
        
        type  const *p;    p指针本身可以修改；指向的内容不能修改

        type * const p; p指向内容可以修改，p本身不可以修改

    
        限制少的可以往限制多的转换，反之不行；

    -   无参宏与const的对比
        

        相同点：
        

        不同点：

        1. 无参宏没有类型检查
            ```c++
                #define i  10.0 
                #define i  10

                int j = 10;  
                std::cout << i / 3 << std::endl;  
                std::cout << j * 10 << std::endl;  


                int j = 10;  
                std::cout << i / 3 << std::endl;  
                std::cout << j * 10 << std::endl; 

                
                // const的用法
                const int i = 10;  
                int j = 10;  
                std::cout << i / 3 << std::endl;  
                std::cout << j * 10 << std::endl;  



            ```
        2. const在编译阶段被翻译；宏会在预编译阶段执行

        3. 宏在代码段中，const在数据段中

        4. 宏可以重复定义
        
            ```c++
                int main()    
                {    
                    #define MODI 10    
                    cout << MODI << endl;    
                    #undef MODI    
                    cout << MODI + 1 << endl;    
                    return 0;    
                }
            ```


### 引用/默认参

1. 引用  

    

    题外话：vs重命名的功能，右键有提示

    基本使用

    ```c++
        
        int n1 = 2;
        int & n1Ref = n1;



    ```

    替代c语言中的指针，解决指针的危害：空指针和野指针

    - 引用必须初始化，所以可以避免空指针和野指针

    - 引用没有多级引用

    -   
        ```c++
        
        int n1 = 2;
        int & n1Ref = n1;

        int n2 = 3;

        n1Ref = n2;  // n1改为3；

        ```
    -  不要返回局部变量的引用

        ```c++
            int& func(){
                int n=1;
                return n;
            }

            int& nRef1 = func(); //不要返回局部变量的引用


        ```

    - 引用可以引用所有的数据类型，着重介绍了对指针的应用；

    - 引用的本质：限制更多的指针；

    - 引用与指针的区别


2. 默认参

    - 没有提供实参的话，会使用默认参

    ```c++

        void Say(const char * szUser,  const char * szCon = "你好"){

        }
    
    ```

    - 题外话：函数的压栈顺序

    - 声明文件如何 使用默认参： 默认参放到声明里面（59分钟处）




