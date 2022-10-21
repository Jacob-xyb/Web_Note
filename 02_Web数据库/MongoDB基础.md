# MongoDB 简介

## 什么是 MongoDB？

MongoDB 是由C++语言编写的，是一个基于分布式文件存储的开源数据库系统。

在高负载的情况下，添加更多的节点，可以保证服务器性能。

MongoDB 旨在为WEB应用提供可扩展的高性能数据存储解决方案。

MongoDB 将数据存储为一个文档，数据结构由键值(key=>value)对组成。MongoDB 文档类似于 JSON 对象。字段值可以包含其他文档，数组及文档数组。

![](https://www.runoob.com/wp-content/uploads/2013/10/crud-annotated-document.png)

## 主要特点

- MongoDB 是一个面向文档存储的数据库，操作起来比较简单和容易。
- 你可以在MongoDB记录中设置任何属性的索引 (如：FirstName="Sameer",Address="8 Gandhi Road")来实现更快的排序。
- 你可以通过本地或者网络创建数据镜像，这使得MongoDB有更强的扩展性。
- 如果负载的增加（需要更多的存储空间和更强的处理能力） ，它可以分布在计算机网络中的其他节点上这就是所谓的分片。
- Mongo支持丰富的查询表达式。查询指令使用JSON形式的标记，可轻易查询文档中内嵌的对象及数组。
- MongoDb 使用update()命令可以实现替换完成的文档（数据）或者一些指定的数据字段 。
- Mongodb中的Map/reduce主要是用来对数据进行批量处理和聚合操作。
- Map和Reduce。Map函数调用emit(key,value)遍历集合中所有的记录，将key与value传给Reduce函数进行处理。
- Map函数和Reduce函数是使用Javascript编写的，并可以通过db.runCommand或mapreduce命令来执行MapReduce操作。
- GridFS是MongoDB中的一个内置功能，可以用于存放大量小文件。
- MongoDB允许在服务端执行脚本，可以用Javascript编写某个函数，直接在服务端执行，也可以把函数的定义存储在服务端，下次直接调用即可。
- MongoDB支持各种编程语言:RUBY，PYTHON，JAVA，C++，PHP，C#等多种语言。
- MongoDB安装简单。

## 历史

- 2007年10月，MongoDB由10gen团队所发展。2009年2月首度推出。
- 2012年05月23日，MongoDB2.1 开发分支发布了! 该版本采用全新架构，包含诸多增强。
- 2012年06月06日，MongoDB 2.0.6 发布，分布式文档数据库。
- 2013年04月23日，MongoDB 2.4.3 发布，此版本包括了一些性能优化，功能增强以及bug修复。
- 2013年08月20日，MongoDB 2.4.6 发布。
- 2013年11月01日，MongoDB 2.4.8 发布。
- ……

## MongoDB 下载

你可以在mongodb官网下载该安装包，地址为：https://www.mongodb.com/download-center#community。MonggoDB支持以下平台:

- OS X 32-bit
- OS X 64-bit
- Linux 32-bit
- Linux 64-bit
- Windows 32-bit
- Windows 64-bit
- Solaris i86pc
- Solaris 64

## 语言支持

MongoDB有官方的驱动如下：

- [C](http://github.com/mongodb/mongo-c-driver)
- [C++](http://github.com/mongodb/mongo)
- [C# / .NET](http://www.mongodb.org/display/DOCS/CSharp+Language+Center)
- [Erlang](https://github.com/TonyGen/mongodb-erlang)
- [Haskell](http://hackage.haskell.org/package/mongoDB)
- [Java](http://github.com/mongodb/mongo-java-driver)
- [JavaScript](http://www.mongodb.org/display/DOCS/Javascript+Language+Center)
- [Lisp](https://github.com/fons/cl-mongo)
- [node.JS](http://github.com/mongodb/node-mongodb-native)
- [Perl](http://github.com/mongodb/mongo-perl-driver)
- [PHP](http://github.com/mongodb/mongo-php-driver)
- [Python](http://github.com/mongodb/mongo-python-driver)
- [Ruby](http://github.com/mongodb/mongo-ruby-driver)
- [Scala](https://github.com/mongodb/casbah)
- [Go](https://github.com/mongodb/mongo-go-driver)

## MongoDB 工具

有几种可用于MongoDB的管理工具。

### 监控

MongoDB提供了网络和系统监控工具Munin，它作为一个插件应用于MongoDB中。

Gangila是MongoDB高性能的系统监视的工具，它作为一个插件应用于MongoDB中。

基于图形界面的开源工具 Cacti, 用于查看CPU负载, 网络带宽利用率,它也提供了一个应用于监控 MongoDB 的插件。

### GUI

- Fang of Mongo – 网页式,由Django和jQuery所构成。
- Futon4Mongo – 一个CouchDB Futon web的mongodb山寨版。
- Mongo3 – Ruby写成。
- MongoHub – 适用于OSX的应用程序。
- Opricot – 一个基于浏览器的MongoDB控制台, 由PHP撰写而成。
- Database Master — Windows的mongodb管理工具
- RockMongo — 最好的PHP语言的MongoDB管理工具，轻量级, 支持多国语言.

## MongoDB 应用案例

下面列举一些公司MongoDB的实际应用：

- Craiglist上使用MongoDB的存档数十亿条记录。
- FourSquare，基于位置的社交网站，在Amazon EC2的服务器上使用MongoDB分享数据。
- Shutterfly，以互联网为基础的社会和个人出版服务，使用MongoDB的各种持久性数据存储的要求。
- bit.ly, 一个基于Web的网址缩短服务，使用MongoDB的存储自己的数据。
- spike.com，一个MTV网络的联营公司， spike.com使用MongoDB的。
- Intuit公司，一个为小企业和个人的软件和服务提供商，为小型企业使用MongoDB的跟踪用户的数据。
- sourceforge.net，资源网站查找，创建和发布开源软件免费，使用MongoDB的后端存储。
- etsy.com ，一个购买和出售手工制作物品网站，使用MongoDB。
- 纽约时报，领先的在线新闻门户网站之一，使用MongoDB。
- CERN，著名的粒子物理研究所，欧洲核子研究中心大型强子对撞机的数据使用MongoDB。

# Windows MongoDB

## 下载

MongoDB 提供了可用于 32 位和 64 位系统的预编译二进制包，你可以从MongoDB官网下载安装，MongoDB 预编译二进制包下载地址：https://www.mongodb.com/download-center/community

下载 .msi 文件，下载后双击该文件，按操作提示安装即可。

安装过程中，你可以通过点击 "Custom(自定义)" 按钮来设置你的安装目录。

![](https://www.runoob.com/wp-content/uploads/2013/10/win-install1.jpg)

下一步安装 **"install mongoDB compass"** 不勾选（当然你也可以选择安装它，可能需要更久的安装时间），MongoDB Compass 是一个图形界面管理工具，我们可以在后面自己到官网下载安装，下载地址：https://www.mongodb.com/download-center/compass。

---

- **创建数据目录：**

安装好后原本是没有data文件和log文件夹的，这里我们需要自己手动创建这两个文件夹，并且要在data文件夹中再创建一个db文件夹。

- **运行 MongoDB 服务：**

假设安装目录是在 E 盘根目录。

进入 E:\MongoDB\bin 在 cmd 中运行以下指令 运行 MongoDB 服务器。

```powershell
mongod --dbpath E:\MongoDB\data\db

# 多参数启动方法
mongod --dbpath E:\MongoDb\data\db --logpath E:\MongoDb\log\mongo.log --port 27017
```

然后再打开一个 cmd 进入 E:\MongoDB\bin 执行命令 连接 MongoDB

```powershell
mongo
```

如果安装是6.0版本或者某些版本，就会不带MongoDB shell需要自行下载：https://www.mongodb.com/try/download/shell

原来使用mongo.exe的启动方式是使用mongo命令，现在则改为mongosh命令。

此时访问： [http://127.0.0.1:27017](http://127.0.0.1:27017/) 或者 [http://localhost:27017](http://localhost:27017/)  出现 **It looks like you are trying to access MongoDB over HTTP on the native driver port.** 说明启动成功了。

## 配置环境变量

在设置中搜索变量 -> 环境变量 -> 系统变量 -> Path -> 添加 mongodb的bin目录。

# MongoDB 概念解析

不管我们学习什么数据库都应该学习其中的基础概念，在mongodb中基本的概念是文档、集合、数据库。

| SQL术语/概念 | MongoDB术语/概念 | 解释/说明                           |
| :----------- | :--------------- | :---------------------------------- |
| database     | database         | 数据库                              |
| table        | collection       | 数据库表/集合                       |
| row          | document         | 数据记录行/文档                     |
| column       | field            | 数据字段/域                         |
| index        | index            | 索引                                |
| table joins  |                  | 表连接,MongoDB不支持                |
| primary key  | primary key      | 主键,MongoDB自动将_id字段设置为主键 |

![](https://www.runoob.com/wp-content/uploads/2013/10/Figure-1-Mapping-Table-to-Collection-1.png)

## 数据库(database)

**MongoDB 中的库就类似于传统关系数据库中库的概念，用来通过不同库隔离不同应用数据。**

一个mongodb中可以建立多个数据库。

MongoDB的默认数据库为"db"，该数据库存储在data目录中。

MongoDB的单个实例可以容纳多个独立的数据库，每一个都有自己的集合和权限，不同的数据库也放置在不同的文件中。

默认的数据库为 "test"， 数据库存储在启动指定的data目录中。

---

数据库也通过名字来标识。数据库名可以是满足以下条件的任意UTF-8字符串。

- 不能是空字符串（"")。
- 不得含有' '（空格)、.、$、/、\和\0 (空字符)。
- 应全部小写。
- 最多64字节。

**有一些数据库名是保留的，可以直接访问这些有特殊作用的数据库。**

- **admin**： 从权限的角度来看，这是"root"数据库。要是将一个用户添加到这个数据库，这个用户自动继承所有数据库的权限。一些特定的服务器端命令也只能从这个数据库运行，比如列出所有的数据库或者关闭服务器。
- **local:** 这个数据永远不会被复制，可以用来存储限于本地单台服务器的任意集合
- **config**: 当Mongo用于分片设置时，config数据库在内部使用，用于保存分片的相关信息。

## 集合

**集合就是 MongoDB 文档组，类似于 RDBMS （关系数据库管理系统：Relational Database Management System)中的表格。**

集合存在于数据库中，集合没有固定的结构，这意味着你在对集合可以插入不同格式和类型的数据，但通常情况下我们插入集合的数据都会有一定的关联性。

比如，我们可以将以下不同数据结构的文档插入到集合中：

```json
{"site":"www.baidu.com"}
{"site":"www.google.com","name":"Google"}
{"site":"https://jacob-xyb.github.io","name":"Jx-TBox","num":5}
```

当第一个文档插入时，集合就会被创建。

## 文档(Document)

**集合中一条条文档记录，是一组键值(key-value)对(即 BSON)。MongoDB 的文档不需要设置相同的字段，并且相同的字段不需要相同的数据类型，这与关系型数据库有很大的区别，也是 MongoDB 非常突出的特点。**

一个简单的文档例子如下：

```json
{"site":"https://jacob-xyb.github.io","name":"Jx-TBox"}
```

需要注意的是：

1. 文档中的键/值对是有序的。
2. 文档中的值不仅可以是在双引号里面的字符串，还可以是其他几种数据类型（甚至可以是整个嵌入的文档)。
3. MongoDB区分类型和大小写。
4. MongoDB的文档不能有重复的键。
5. 文档的键是字符串。除了少数例外情况，键可以使用任意UTF-8字符。

文档键命名规范：

- 键不能含有\0 (空字符)。这个字符用来表示键的结尾。
- .和$有特别的意义，只有在特定环境下才能使用。
- 以下划线"_"开头的键是保留的(不是严格要求的)。

## MongoDB 数据类型

下表为MongoDB中常用的几种数据类型。

| 数据类型           | 描述                                                         |
| :----------------- | :----------------------------------------------------------- |
| String             | 字符串。存储数据常用的数据类型。在 MongoDB 中，UTF-8 编码的字符串才是合法的。 |
| Integer            | 整型数值。用于存储数值。根据你所采用的服务器，可分为 32 位或 64 位。 |
| Boolean            | 布尔值。用于存储布尔值（真/假）。                            |
| Double             | 双精度浮点值。用于存储浮点值。                               |
| Min/Max keys       | 将一个值与 BSON（二进制的 JSON）元素的最低值和最高值相对比。 |
| Array              | 用于将数组或列表或多个值存储为一个键。                       |
| Timestamp          | 时间戳。记录文档修改或添加的具体时间。                       |
| Object             | 用于内嵌文档。                                               |
| Null               | 用于创建空值。                                               |
| Symbol             | 符号。该数据类型基本上等同于字符串类型，但不同的是，它一般用于采用特殊符号类型的语言。 |
| Date               | 日期时间。用 UNIX 时间格式来存储当前日期或时间。你可以指定自己的日期时间：创建 Date 对象，传入年月日信息。 |
| Object ID          | 对象 ID。用于创建文档的 ID。                                 |
| Binary Data        | 二进制数据。用于存储二进制数据。                             |
| Code               | 代码类型。用于在文档中存储 JavaScript 代码。                 |
| Regular expression | 正则表达式类型。用于存储正则表达式。                         |

下面说明下几种重要的数据类型。

### ObjectId

ObjectId 类似唯一主键，可以很快的去生成和排序，包含 12 bytes，含义是：

- 前 4 个字节表示创建 **unix** 时间戳,格林尼治时间 **UTC** 时间，比北京时间晚了 8 个小时
- 接下来的 3 个字节是机器标识码
- 紧接的两个字节由进程 id 组成 PID
- 最后三个字节是随机数

![](https://www.runoob.com/wp-content/uploads/2013/10/2875754375-5a19268f0fd9b_articlex.jpeg)

MongoDB 中存储的文档必须有一个 _id 键。这个键的值可以是**任何类型**的，默认是个 ObjectId 对象

由于 ObjectId 中保存了创建的时间戳，所以你不需要为你的文档保存时间戳字段，你可以通过 getTimestamp 函数来获取文档的创建时间.

# MongoDB 基本操作

## shell

```shell
cls		# 清屏
```

## 库

- **查找所有库**

  `show databases` | `show dbs`

  ```shell
  > show dbs
  admin   40.00 KiB
  config  72.00 KiB
  local   72.00 KiB
  > 
  ```

- **创建库**

  `use [dbname]`

  创建并使用，MongoDB 如果创建的库是空的，则默认不显示（但是已经创建成功了）。

- **删除库**

  `db.dropDatabase()` 默认删除当前选中的库，但是并不会退出当前已删除的库。

- **查看当前所在库**

  `db`
  
## 集合

- **查看集合**

  `show collections` | `show tables`

- **创建集合**

  `db.createCollection('集合名称', [options])`

  options 可以是如下参数：

  | 字段        | 类型 | 描述                                                         |
  | :---------- | :--- | :----------------------------------------------------------- |
  | capped      | 布尔 | （可选）如果为 true，则创建固定集合。固定集合是指有着固定大小的集合，当达到最大值时，它会自动覆盖最早的文档。 **当该值为 true 时，必须指定 size 参数。** |
  | autoIndexId | 布尔 | 3.2 之后不再支持该参数。（可选）如为 true，自动在 _id 字段创建索引。默认为 false。 |
  | size        | 数值 | （可选）为固定集合指定一个最大值，即字节数。 **如果 capped 为 true，也需要指定该字段。** |
  | max         | 数值 | （可选）指定固定集合中包含文档的最大数量。                   |

  在插入文档时，MongoDB 首先检查固定集合的 size 字段，然后检查 max 字段。

  **一般不限制大小，不常用**

  **隐式创建：** 向不存在的集合插入文档时，此集合会被自动创建。

- **删除集合**

  `db.[collection].drop()` : 如果成功删除选定集合，则 drop() 方法返回 true，否则返回 false。

## 文档

### 插入文档

文档的数据结构和 JSON 基本一样。

所有存储在集合中的数据都是 BSON 格式。

BSON 是一种类似 JSON 的二进制形式的存储格式，是 Binary JSON 的简称。

MongoDB 使用 **insert()** 或 ~~save()~~ 方法向集合中插入文档，语法如下：

```sql
db.COLLECTION_NAME.insert(document)
或
db.COLLECTION_NAME.save(document) # 弃用
```

- ~~save()：如果 _id 主键存在则更新数据，如果不存在就插入数据。该方法新版本中已废弃，可以使用 **db.collection.insertOne()** 或 **db.collection.replaceOne()** 来代替。~~
- insert(): 若插入的数据主键已经存在，则会抛 **org.springframework.dao.DuplicateKeyException** 异常，提示主键重复，不保存当前数据。

**6.0 已经抛弃 insert() 方法**

**3.2 版本之后新增了 db.collection.insertOne() 和 db.collection.insertMany()。**

---

- `db.collection.insertOne()` 用于向集合插入一个新文档，语法格式如下：

```sql
db.collection.insertOne(
   <document>,
   {
      writeConcern: <document>
   }
)
```

- `db.collection.insertMany()` 用于向集合插入一个多个文档，语法格式如下：

```sql
db.collection.insertMany(
   [ <document 1> , <document 2>, ... ],
   {
      writeConcern: <document>,
      ordered: <boolean>
   }
)
```

参数说明：

- document：要写入的文档。
- writeConcern：写入策略，默认为 1，即要求确认写操作，0 是不要求。
- ordered：指定是否按顺序写入，默认 true，按顺序写入。

脚本方式插入：

```js
for(let i=0;i<100;i++){
    db.users.insert({"_id":i, "name":"xyb_"+i, "age": 27});
}
```

**注意：** 在 MongoDB 中每个文档都会有一个 `_id` 作为唯一标识， `_id` 默认会自动生成，如果手动指定，将使用手动指定的值。

#### 实例

- **单个插入：**

  ```sql
  db.col.insertOne({title: 'MongoDB 教程', 
      description: 'MongoDB 是一个 Nosql 数据库',
      by: '菜鸟教程',
      url: 'http://www.runoob.com',
      tags: ['mongodb', 'database', 'NoSQL'],
      likes: 100,
  })
  ```

- **多个插入：**

  ```sql
  db.collection.insertMany([{"b": 3}, {'c': 4}])
  ```

### 查询所有文档

MongoDB 查询文档使用 find() 方法。

find() 方法以非结构化的方式来显示所有文档。

`db.[collection].find()`

### 删除文档

**语法：**

```sql
db.collection.deleteOne()	# 删除一条
db.collection.deleteMany()	# 删除全部
```

#### 实例

```sql
db.col.insertOne({title: 'MongoDB 教程', 
    description: 'MongoDB 是一个 Nosql 数据库',
})
db.col.remove({title:'MongoDB 教程'})
```

### 更新文档

**语法：**

```sql
db.collection.updateOne(filter, update, options)
db.collection.updateMany(filter, update, options)
```

[db.collection.updateOne()](https://www.mongodb.com/docs/manual/reference/method/db.collection.updateOne/#db.collection.updateone--)

[db.collection.updateMany()](https://www.mongodb.com/docs/manual/reference/method/db.collection.updateMany/#db.collection.updatemany--)

#### 实例

```sql
db.col.insertOne({title: 'MongoDB 教程', 
    description: 'MongoDB 是一个 Nosql 数据库',
})
db.col.updateOne({title:'MongoDB 教程'}, {$set:{title:'MongoDB'}})
# $set: 保留原始数据更新
db.col.updateOne({title:'MongoDB 教程'}, {title:'MongoDB'})
# 先删除文档 再更新文档，更新后的只保留 'title'属性。
```

# MongoDB 查询进阶

## 语法

`db.集合名称.find(query, proection)`

- **query**: 可选，使用查询操作符指定查询条件
- **projection**：可选，使用投影操作符指定返回的键。

如果需要以易读的方式来读取数据，可以使用 `pretty()` 方法：`db.集合名称.find().pretty()` ，以格式化的方式来显示所有文档。

除了 find() 方法之外，还有一个 findOne() 方法，它只返回一个文档。

## MongoDB 与 RDBMS Where 语句比较

如果你熟悉常规的 SQL 数据，通过下表可以更好的理解 MongoDB 的条件语句查询：

| 操作       | 格式                     | 范例                                        | RDBMS中的类似语句       |
| :--------- | :----------------------- | :------------------------------------------ | :---------------------- |
| 等于       | `{<key>:<value>}`        | `db.col.find({"by":"菜鸟教程"}).pretty()`   | `where by = '菜鸟教程'` |
| 小于       | `{<key>:{$lt:<value>}}`  | `db.col.find({"likes":{$lt:50}}).pretty()`  | `where likes < 50`      |
| 小于或等于 | `{<key>:{$lte:<value>}}` | `db.col.find({"likes":{$lte:50}}).pretty()` | `where likes <= 50`     |
| 大于       | `{<key>:{$gt:<value>}}`  | `db.col.find({"likes":{$gt:50}}).pretty()`  | `where likes > 50`      |
| 大于或等于 | `{<key>:{$gte:<value>}}` | `db.col.find({"likes":{$gte:50}}).pretty()` | `where likes >= 50`     |
| 不等于     | `{<key>:{$ne:<value>}}`  | `db.col.find({"likes":{$ne:50}}).pretty()`  | `where likes != 50`     |

## AND

MongoDB 的 find() 方法可以传入多个键(key)，每个键(key)以逗号隔开，即常规 SQL 的 AND 条件。

语法格式如下：

```sql
db.col.find({key1:value1, key2:value2}).pretty()
```

以上实例中类似于 WHERE 语句：**WHERE key1=value1 AND key2=value2**

**注意：** 一个 key 出现多次的情况下，后面的 key 会覆盖前面的。

## OR

MongoDB OR 条件语句使用了关键字 **$or**,语法格式如下：

```sql
db.col.find({$or: [{key1: value1}, {key2:value2}]}).pretty()
```

以上实例中类似于 WHERE 语句：**WHERE key1=value1 OR key2=value2**

## 模糊查询

采用正则表达式查询

```sql
db.集合名称.find({like:/movie/})
```

## 数组长度查询

```sql
db.集合名称.find({like:{$size:3}})	# 查找数组长度为3的文档。
```

## 查询排序

```sql
db.集合名称.find().sort({key1:1, key2:1})
```

- 1 代表升序，-1 代表降序。

# MongoDB 远程连接

## 流程

1. 修改配置信息

   `bin\mongod.cfg`

   ```yaml
   # mongodb的配置文件中的bind_ip 默认为127.0.0.1，默认只有本机可以连接。 需要将bind_ip配置为0.0.0.0，表示接受任何IP的连接
   bind_ip: 0.0.0.0
   
   # 如果需要用户验证的话（开启远程的同时建议开启用户验证）
   security:
     authorization: enabled
   ```

   然后执行

   ```py
   $ mongod --config mongodb.conf --install
   ```

2. 添加用户

   ```py
   mongo
   use admin
   db.createUser({user:“root”,pwd:“123456”,roles:[“userAdminAnyDatabase”]})
   db.auth(“root”, “123456”)
   db.grantRolesToUser( "admin" , [ { role: "root", db: "admin" } ])	// 增加 root 权限，不然还是无法执行命令
   ```

3. 启动MongoDB服务即可。

   ```py
   $ mongod --config=D:\MongoDB\bin\mongod.cfg  --dbpath=D:\MongoDB\data --logpath=D:\MongoDB\log\mongod.log --service
   ```

   **情况1：** 修改配置后，本地启动就无法开启 service 服务了，就很奇怪，进管理器手动开启才行。

   >mongo 局域网ip 测试时:
   >
   >若还不行.则关闭防火墙或增加防火墙入站规则开放mongodb 27017端口
   >
   >`iptables -A INPUT -p tcp -m state --state NEW -m tcp --dport 27017 -j ACCEPT`

   

## 开启权限验证

找到`MongoDB`安装目录下的`bin`目录中的`mongod.cfg`文件，开启权限验证功能：

```py
security:
  authorization: enabled
```

## 有无密码连接方式

```py
# 1.启动MongoDB：

方法1：若本地配置好了MongoDB为windows服务，在服务里启动MongoDB

方法2：开启一个cmd，执行mongod --dbpath MongoDB的data数据存放地址

如mongod --dbpath D:MongoDBdata

# 2.连接本地MongoDB

无密码：再开启一个cmd，执行 mongo

有密码：再开启一个cmd，执行 mongo -u user -p password

# 3.连接远程服务器MongoDB

无密码：开启一个cmd，执行 mongo 42.114.29.206:27017/log

有密码：开启一个cmd，执行 mongo 42.114.29.206:27017/log  -u user -p password
```

## 常用命令

```py
show users  // 查看当前库下的用户

db.dropUser('username')  // 删除用户
db.removeUser('username') // 删除用户

db.updateUser('admin', {pwd: '654321'})  // 修改用户密码

db.addUser('user','pwd')	// 某个数据库添加访问权限
db.auth('admin', '654321')  // 密码认证
```

## 角色权限

| 角色描述       | 角色标识                                                     |
| -------------- | ------------------------------------------------------------ |
| 数据库用户角色 | read、readWrite                                              |
| 数据库管理角色 | dbAdmin、dbOwner、userAdmin                                  |
| 集群管理角色   | clusterAdmin、clusterManager、clusterMonitor、hostManager    |
| 备份恢复角色   | backup、restore                                              |
| 所有数据库角色 | readAnyDatabase、readWriteAnyDatabase、userAdminAnyDatabase、 dbAdminAnyDatabase |
| 超级用户角色   | root                                                         |

