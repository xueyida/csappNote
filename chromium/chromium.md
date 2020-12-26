### 使用gclient中出现了问题

    应是代理问题，目前好像瞎猫碰上死耗子给解决了；

    文档使用的是参考中的官方文档；

#### 解决代理的方式

1. 代理设置为全局
2. 设置winhttp代理
    
    ```sh

    c:\>netsh
    netsh>winhttp
    netsh winhttp>set proxy localhost:1080
    
    ```

3. 设置http代理

    ```sh

    set http_proxy=http://localhost:1081
    set https_proxy=http://localhost:1081
    set socks5_proxy=socks5://127.0.0.1:1080

    ```

4. git设置代理

    ```sh
                
        git config --global https.proxy  socks5://localhost:1080
        git config --global core.proxy  socks5://localhost:1080
        git config --global http.proxy  socks5://localhost:1080
        git config --global http.sslVerify false
    
    ```

这些代理直接的区别是什么？

#### 使用gclient安装python以及依赖库

    有两个版本的python,依赖存的地方不一样，造成的问题
    
    python 库 安装路径： 
        C:\Users\YIDA\.vpython-root\e68a54\Lib\site-packages

    安装脚本路径: 
        C:\Users\YIDA\.vpython-root\e68a54\Scripts



### 编译中的问题

- You must installWindows 10 SDK version 10.0.19041.0 including the "Debugging Tools for Windows" feature.

    需要安装新的 win10 sdk

### 参考

[官方文档](https://chromium.googlesource.com/chromium/src/+/master/docs/windows_build_instructions.md)