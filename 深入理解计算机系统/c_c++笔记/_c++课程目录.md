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






### 命名空间

解决的问题- 名字冲突

使用方式：

```c++

   
    namespace Test{
        int  a=1;
    }

     // 第一种方式
    int main(){
        {
            using namespace Test;
            a=2;
        }
        return 0;
    }


    // 第二张方式
    Test::a = 2;

    // 第三种方式
    using Test::a;
    a=2


```

知识点：

1. namespace可以拆分

2. 取别名

```c++

    // 1
    namespace Test {
        int a=2;
    }

    namespace Test {
        int b=3;
    }

    // 2

    namespace Test1=Test;

```

### 函数重载

- 构成重载的条件：

0. 作用域需要相同
1. 参数（参数类型，参数数量，参数顺序）不同
2. 函数名相同
3. 调用约定不考虑
4. 返回值类型不考虑

```c++

    int Add(int n1, int n2){
        return n1+n1;
    }

    float Add(float n1, float n2){
        return n1+n2;
    }

    float Add(float n1, float n2, float n3){
        return n1+n2+n3;
    }

    // 调用约定

    int __stdcall Add(int n)
    {
        return 0;
    }

    int __cdecl Add(int n){
        return 0;
    }

```


- 函数重载原理：名称粉碎


    1. extern "C" // 告诉函数名称粉碎规则使用c，而不是c++

    2. 使用extern "C" 无法使用函数重载


- 重载使用过程中，需要注意参数的完美匹配

- 默认参对函数的调用也是有影响


### 内联

短函数： 体积小  效率低  方便调试 

宏：    体积大   效率高  不方便调试（在每个地方使用的地方都会展开）



提出内联：

    内联的作用： 



    既可以像函数一样调试，也可以在调用点像宏一样展开

    debug版任何函数都不会展开；

    内联相关的编译选项：
        ob0:所有的函数都不内联
        ob1：有依赖的内联
        ob2：所有都尝试内联
    

    建议编译器内联，但是能不能内联成功，看编译器

    内联函数声明与实现不能拆开，建议内联函数定义与实现都放在头文件中

    内联函数被编译器变成文件作用域；包含内联函数的头文件， 被多个cpp调用，然后实现，不会出现重定义的问题



### 类


1. 面向对象编程（提高代码的复用）

    封装，继承，多态

2. class与struct的区别

    - class默认属性是公有的，struct是私有的

    - struct没有public,private等

3. 内存结构
    - class 与 struct的内存布局是一样的

    - class访问权限控制是语法限制

    - cTest没有成员变量，使用一个字节占位

4. 成员函数指针

    ```c++

        typedef void(* PFN_SETX)(int nX);

        PFN_SETX pfnSetX = &CPlayer::Setx;  // 不能给到pfnSetX
        
        void *p = &CPlayer::Setx;  // 报错




        typedef void(CPlayer::* PFN_SETX)(int nX);

        PFN_SETX pfnSetX = &CPlayer::Setx;  // 正确


        player.*pfnSetX(9)  //成员函数变量指针调用，使用类对象

        CPlayer* p = &player;

        (p->*pfnSetX)(99);



    
    ```



5. 声明和定义分开

    声明写到头文件
    实现写到cpp文件

    属性写在声明的部分，函数写在声明的下部分；先公有，再私有

    public: 函数


    private： 函数

    public: 属性


    private： 




6. __thiscall
    调用传参约定

    类成员函数通过ecx传入this指针的调用约定叫做__thiscall

    调用约定可以改；




7. 类对象的共享问题

    类对象的成员属性是单独的

    类对象的成员函数是同一份，通过this确定哪个对象调用






### 构造和析构

解决问题：class的初始化

构造：函数名和类名形同；无返回值；可以重载；
析构：函数名和类名形同，前面加~；无返回值；不可以重载；没有参数


javascript也有构造函数，没有析构

构造和析构的调用世纪：
    在对象的生命周期开始时，调用构造，在对象的生命周期结束时，调用析构

### new delete

new 申请堆内存，并调用构造
delete 调用析构，并释放堆

解决问题：

    堆上分配的数据,不能自动调用构造 

使用方式：

    数组：
        CFoo *paryF = new CFoo[5]{{},{},{},{},{}} 
        delete[] paryF;

29分钟开始不常用：

    ```c++

        class CFoo2
        {
            CFoo2(){

            }
            int m_n;
        }

        int *pInt = new CFoo2[6];

    ```

    没有析构函数，对内存不会分配内存数的位置




### 拷贝构造

解决问题：参数传对象，会有重复释放的问题

struct传参时，会把内存复制过去

拷贝构造的使用场景：

1. 对象传参

```c++

    class CDataBuff{

    }

    void Foo(CDataBuff buf)
    {
        cout <<buf.GetData()<<endl;
    }

    int main(){
        CDataBuff buf0((char*)"hello", 6);
        Foo(buf0);
        return 0;
    }

```


### 构造自己的string





