# JavaWeb

<!-- TOC -->

- [JavaWeb](#javaweb)
  - [一、web应用服务器](#%e4%b8%80web%e5%ba%94%e7%94%a8%e6%9c%8d%e5%8a%a1%e5%99%a8)
    - [1、Tomcat](#1tomcat)
    - [2、使用指南](#2%e4%bd%bf%e7%94%a8%e6%8c%87%e5%8d%97)
      - [1、官网下载tomcat zip](#1%e5%ae%98%e7%bd%91%e4%b8%8b%e8%bd%bdtomcat-zip)
      - [2、解压](#2%e8%a7%a3%e5%8e%8b)
      - [3、idea新建企业java webapp](#3idea%e6%96%b0%e5%bb%ba%e4%bc%81%e4%b8%9ajava-webapp)
  - [二、JDBC](#%e4%ba%8cjdbc)
    - [1、JDBC体系结构](#1jdbc%e4%bd%93%e7%b3%bb%e7%bb%93%e6%9e%84)
    - [2、JDBC的使用](#2jdbc%e7%9a%84%e4%bd%bf%e7%94%a8)
  - [三、Servlet和JSP](#%e4%b8%89servlet%e5%92%8cjsp)
    - [1、什么是Servlet](#1%e4%bb%80%e4%b9%88%e6%98%afservlet)
    - [2、Servlet的功能](#2servlet%e7%9a%84%e5%8a%9f%e8%83%bd)
    - [3、如何使用Servlet](#3%e5%a6%82%e4%bd%95%e4%bd%bf%e7%94%a8servlet)

<!-- /TOC -->

## 一、web应用服务器

`tomcat`、`Jboos`、`Weblogic`、`jetty`

### 1、Tomcat

- Tomcat简单的说就是一个运行JAVA的网络服务器，底层是`Socket`的一个程序，它也是`JSP`和`Serlvet`的一个容器。

### 2、使用指南

#### 	1、官网下载tomcat zip

#### 	2、解压

​		`bin`：存放各个平台下启动和停止`Tomcat`服务的脚本文件

​		`conf`：存放各种`Tomcat`服务器的配置文件

​		`	lib`：第三方`jar`包

​		`		logs`：`Tomcat`服务的日志信息

​		`	temp`：`Tomcat`运行时的临时文件

​		`webapps`：存放允许客户端访问的资源（**java**程序）

​		`work`：存放`Tomcat`将`jsp`转换成的`servlet`文件

#### 	3、idea新建企业java webapp

### 3、url的组成

| http:// |  localhost:  | 8080/ |  web1/  | Hello.html |
| :-----: | :----------: | :---: | :-----: | :--------: |
|  协议   | 主机（域名） | 端口  | web应用 |  资源文件  |

其中，web应用和资源文件统称uri

### 4、虚拟目录

- 如果把所有web站点的目录都放在webapps下，可能导致**磁盘空间不够用**，也**不利于对web站点目录的管理**【如果存在非常多的web站点目录】把**web站点的目录分散到其他磁盘管理就需要配置虚拟目录【默认情况下，只有webapps下的目录才能被Tomcat自动管理成一个web站点】**把web应用所在目录交给web服务器管理，这个过程称之为虚拟目录的映射

- 步骤：

  - 在其他盘符下创建一个web站点目录，并创建WEB-INF目录和一个html文件。

  - 找到Tomcat目录下/conf/server.xml文件

  - 在server.xml中的节点下添加如下代码。**path表示的是访问时输入的web项目名，docBase表示的是站点目录的绝对路径**

    ```xml
    <Context path="/web1" docBase="D:\web1"/>
    ```

- 方法2:

  - 进入到conf\Catalina\localhost文件下，创建一个xml文件，**该文件的名字就是web应用的名字。**

  - xml文件的代码如下，**docBase是你web站点的绝对路径**

  - ```xml
    <?xml version="1.0" encoding="UTF-8"?>
    <Context docBase="D:\web1" reloadable="true"></Context>
    ```

  - 访问web站点下的html资源 

### 5、配置临时域名

- 在hosts文件下配置临时域名

### 6、虚拟主机

- 为什么需要用到虚拟主机？例子：我现在开发了4个网站，有4个域名。如果我不配置虚拟主机，一个Tomcat服务器运行一个网站，我就需要4台电脑才能把4个网站运行起来。

- 步骤：

  - 在tomcat的server.xml文件中添加主机名

  - ```xml
    <Host name="panda" appBase="D:\web1">
    <Context path="/web1" docBase="D:\web1"/>
    </Host>
    ```

  - 访问虚拟主机下的web站: panda:8080/web1



## 二、Servlet和JSP

### 1、什么是Servlet

- `Servlet`是JavaWeb开发的基石，一种与平台无关的服务器组件
- 它是运行在`Servlet`容器/Web应用服务器，负责与客户端进行通信
- 是一个**遵循Servlet开发的java类**。Serlvet是**由服务器调用的**，**运行在服务器端**。

### 2、HTTP协议

- 

### 3、Servlet的功能

- 创建并返回基于客户端请求的动态HTML页面
- 与数据库进行通信

### 4、如何使用Servlet

- `Servlet`本身是一组接口，在`javax.servlet`包里面。
- 自定义一个类，并实现`Sevlet`接口，这个类就具备了接受客户端请求以及做出响应的功能。



## 三、JDBC

`Java DataBase Connectivity`是一个独立与特定数据库的管理系统，通用的SQL数据存取和操作的公共接口，定义了一组标准，未访问不同数据库提供了统一的途径。

### 1、JDBC体系结构

- JDBC的接口包含两个层面：

- - 面向应用的api，供开发者调用；
  - 面向数据库的api，供厂商开发数据库驱动；

- 提供者：java官方；内容：供开发者调用的接口；

- `java.sql`和`javax.sql`：`DriverManager`类、`Connection`接口、`Statement`接口、`ResultSet`接口

- `DriverManager`

- - 提供者：java官方
  - 作用：管理不同的JDBC驱动

- JDBC驱动

- - 提供者：各数据库厂商
  - 作用：负责连接数据库

### 2、JDBC的使用

- 加载数据库驱动，Java程序和数据库之间的桥梁

- 获取`Connection`，Java程序与数据库一次连接

- 创建`Statement`对象，由`Connection`产生，执行SQL语句

- 如果需要接收返回值，创建`Result`对象，保存`Statement`执行之后所查询到的结果

  ```java
  package com.panda.tomcat0314;
  
  import java.sql.*;
  import java.util.Date;
  
  /**
   * @author panda
   * @description
   * @date 2020/3/14
   */
  public class Test {
      public static void main(String[] args) {
          //try catch处理异常
          try {
              //反射加载驱动
              Class.forName("com.mysql.cj.jdbc.Driver");
              //获取连接地址,并处理中文乱码
              String url = "jdbc:mysql://localhost:3306/test?useUnicode=true&characterEncoding=UTF-8";
              //用户信息
              String usr = "root";
              String password = "panyuwen";
              //新建connection连接
              Connection connection = DriverManager.getConnection(url,usr,password);
              //获取statement并执行语句
              Statement statement = connection.createStatement();
              //String sql = "insert into foods(title,owner,price,date,sold,image) values('可乐','panda',2.5,'2020-01-01',0,'n')";
              //statement.executeUpdate(sql);
              String sql = "select * from foods";
              ResultSet resultSet =  statement.executeQuery(sql);
              while (resultSet.next()){
                  int id  = resultSet.getInt("id");
                  String title = resultSet.getString("title");
                  String owner = resultSet.getString("owner");
                  double price = resultSet.getDouble("price");
                  Date date = resultSet.getDate("date");
                  int sold = resultSet.getInt("sold");
                  String image = resultSet.getString("image");
                  System.out.println(title);
  
              }
          } catch (ClassNotFoundException | SQLException e) {
              e.printStackTrace();
          }
      }
  }
  ```

