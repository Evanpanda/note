# JavaWeb

[TOC]

## 一、web应用服务器

`tomcat`、`Jboos`、`Weblogic`、`jetty`

### 1、官网下载tomcat zip

### 2、解压

​	`bin`：存放各个平台下启动和停止`Tomcat`服务的脚本文件

​	`conf`：存放各种`Tomcat`服务器的配置文件

​	`	lib`：第三方`jar`包

​	`		logs`：`Tomcat`服务的日志信息

​	`	temp`：`Tomcat`运行时的临时文件

​	`webapps`：存放允许客户端访问的资源（**java**程序）

​	`work`：存放`Tomcat`将`jsp`转换成的`servlet`文件

### 3、idea新建企业java webapp

## 二、JDBC

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

## 三、Servlet和JSP

### 1、什么是Servlet

- `Servlet`是JavaWeb开发的基石，一种与平台无关的服务器组件
- 它是运行在`Servlet`容器/Web应用服务器，负责与客户端进行通信

### 2、Servlet的功能

- 创建并返回基于客户端请求的动态HTML页面
- 与数据库进行通信

### 3、如何使用Servlet

- `Servlet`本身是一组接口，在`javax.servlet`包里面。
- 自定义一个类，并实现`Sevlet`接口，这个类就具备了接受客户端请求以及做出响应的功能。