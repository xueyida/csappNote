## 存储技术

 ### 随机访问存储器

- 静态RAM
    用途： 高速缓存
    组成： 一位由6个晶体管组成
    特点：
    1. 只要有电，数据就不会改变（持续）
    2. 不会受外界干扰（敏感） 

- 动态RAM芯片      

    用途：内存
    组成：由一个电容和一个访问晶体管组成；
    
    DRAM的行内存缓冲区

    RAM的原理：p401
        
        根据i，把第i行复制到行缓冲区，使用一个，剩余的丢弃


    作业： c语言实现动态RAM的原理


- 内存模块

    1. 内存控制器： 
        
        作用： 
        1. 通过管理**内存模块**，读取和写入DRAM
        2. 通过控制**内存模块**，每隔一段时间刷新DRAM,如果不刷新DRAM中的数据会消失
        
        位置：
        大多数内存控制器现在都集成在了**处理器**中

        原理：

    2. 内存模块（内存条）：
        DRAM芯片封装在内存模块中，内存模块可以查到主板的扩展槽，也就是我们平时使用的内存条

    3. 主存：由多个内存模块组成，也就是多个内存条

        内存模块的工作原理：p403


    4. 32位系统与64位系统使用（4个DRAM组成的芯片或者8个DRAM组成的芯片）的区别，？
        1. 如果是由8个DRAM芯片组成， 由**内存控制器**控制 ，32位在每个DRAM芯片上每次存4位或者取四位；64位在每个DRAM芯片上每次存或取8位；（猜测，但是好像每次取一个超单元，也就是一个字节）

        2. 内存控制会把**内存模块**分开或者合并，比如32位系统使用的**内存模块**是由8个DRAM组成，内存控制器会把内存模块分成两半，相当于有两个内存模块

        内存控制器将地址A转换成一个超单元地址（i,j）,发送到内存模块-> 内存模块讲（i,j）地址发送到每个芯片

    5. 作业：c语言实现内存模块的原理（这一块感觉还是挺复杂的....）

- 增强的DRAM

    FPM (快叶)：传统的DRAM读到数据后，把缓冲区的数据丢掉，fpm根据需要不丢弃FPM

    EDO DRAM: FPM的扩展版

    SDRAM: 同步DRAM (同步的)，具体的细节不讨论

    DDR DRAM: 比SDRAM多用一个时钟信号

    VRAM：图形系统的帧缓存区

- ROM

    作用：
     - 固件——存储在ROM设备中的程序叫做固件

     - 闪存——闪存基于EEPROM,ssd是基于闪存的
    
    种类： 

    - PROM  可编程ROM 只能被编程一次

    - EPROM   可擦写可编程ROM  1000

    - EEPROM 电子可擦除可编写 10^5


      

- 访问主存
    
    1. 从cpu往内存写叫写事务，从内存往cpu传从叫读事务

    路径： 
    
        cpu将地址通过总线接口发送到系统总线->系统总线->i/o桥->内存总线->主存感觉到内存总线上有信号，然后去内存取数据,然
        
        后发到内存总线->内存总线->i/o桥->系统总线->cpu感觉到系统总线上的数据


    作业：c语言模拟访问主存



### 磁盘存储

1. 磁盘组成：

1. 一个磁盘由多个盘片组成
2. 一个盘面由2个表面组成
3. 一个面是由多个磁道组成的
4. 一个磁道是由多个扇区组成的
5. 一个扇区通常是512字节

2. 磁盘容量=盘片数*（表面数/每片）*磁道数*扇区数*每个扇区的字节数

    对于磁盘来说，1k=10^3而不是2^10方，其他的类似；

3. 磁盘读写：

    1. 磁盘以扇区大小来进行读写数据，跟内存是以一个字节进行读写类似

4. 访问时间由：寻道时间 旋转时间 传送时间组成



5. 访问磁盘：
    
    途径： **磁盘控制器**

        位置：磁盘控制器封装在硬盘中，维护逻辑块号与磁盘之间的关系;
        
        作用：磁盘控制器根据逻辑块号，翻译成物理磁盘；


    原理（内存映射I/O）：
        当一个设备连接到总线时，该设备就在内存空间中有了一个地址（每个这样的地址称为I/O端口），通过该地址可以给I/O发送指令；


    过程（直接内存访问）：
        
        发起磁盘读：
            
            访问的路线：
            系统总线 -> i/o桥接器 -> i/o总线->主机总线适配器->磁盘控制器-> 磁盘

            直接访问内存需要发三个指令：
            1. cpu给磁盘发指令，告诉磁盘发起读
            2. 第二条指令指明逻辑快
            3. 第三条指令是存到内存中的地址
        
        数据传送到内存：
            磁盘控制器先讲逻辑块翻译成扇区地址，读取扇区内容（读取的内容保存到哪里？）
            访问的路线：
            磁盘-> 磁盘控制器->主机总线适配器->i/o总线->i/o桥接器->内存总线->内存
        结束发送：
            磁盘控制器给cpu发送中断，来通知cpu(这里涉及到第八章的内容);

    作业：c语言模拟该流程

### 固态硬盘

- 组成：
    ssd由多个闪存芯片+闪存翻译层（相当于磁盘控制器）

- 特点：
    - 读比写快；
    - 一个闪存芯片由多个块组成，块由32-128页组成；页的大小位512字节-4KB
    - 数据是以页进行读取的

- ssd与hd对比：
    ssd访问更快
    ssd闪存容易磨损




## 局部性

### 什么是局部性

使用最近引用引用过的数据周围的数据，或者最近引用过的数据本身

时间局部性：

    引用过一次的内存位置，在短时间内还被多次引用

空间局部性：

    引用过一次的内存位置，在短时间内，该内存周围的数据可能被引用


量化局部性的一些原则：

1. 重复引用相同的变量，时间局部性比较优秀；
2. 具有步长位k（每隔k个元素进行访问，就称k为步长）的引用模式，有比较好的空间局部性；
3. 内存中步长越大，程序的跳转幅度比较大，所以局部性就差一些；
4. for循环体里的指令是按照顺序存放的，对于取指令来说有比较好的时间空间局部性





## 存储器层次结构

层次结构：p421

    存储器层次结构：

    寄存器->高速缓存L1 -> 高速缓存L2 -> 高速缓存L3 -> 主存  -> 磁盘 -> 网路

缓存：

    缓存思想能够实现的一个重要原因就是，程序的局部性；一个数据被引用，周围的数据也会被引用到；所以取一个数据的时候，把周围的数据都取到内存中去；

    主存缓存是由操作系统跟cpu上的地址翻译硬件共同管理的

    缓存的工作原理：p423
    

各个阶段缓存的大小：p425






## 高速缓存存储器

