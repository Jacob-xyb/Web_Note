# HTML 5

超文本标记语言（英语：**HyperText Markup Language**，简称：HTML）是一种用于创建网页的标准标记语言。

您可以使用 HTML 来建立自己的 WEB 站点，HTML 运行在浏览器上，由浏览器来解析。

**注意：**对于中文网页需要使用 **<meta charset="utf-8">** 声明编码，否则会出现乱码。有些浏览器(如 360 浏览器)会设置 GBK 为默认编码，则你需要设置为 **<meta charset="gbk">。**

## HTML文档的后缀名

- .html
- .htm

以上两种后缀名没有区别，都可以使用。

## 第一个实例

```html
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>菜鸟教程(runoob.com)</title>
</head>
<body>
 
<h1>我的第一个标题</h1>
 
<p>我的第一个段落。</p>
 
</body>
</html>
```

实例解析：

![](https://www.runoob.com/wp-content/uploads/2013/06/02A7DD95-22B4-4FB9-B994-DDB5393F7F03.jpg)

- **<!DOCTYPE html>** 声明为 HTML5 文档
- **<html>** 元素是 HTML 页面的根元素
- **<head>** 元素包含了文档的元（meta）数据，如 **<meta charset="utf-8">** 定义网页编码格式为 **utf-8**。
- **<title>** 元素描述了文档的标题
- **<body>** 元素包含了可见的页面内容
- **<h1>** 元素定义一个大标题
- **<p>** 元素定义一个段落

**注：**在浏览器的页面上使用键盘上的 F12 按键开启调试模式，就可以看到组成标签。

## 什么是HTML?

HTML 是用来描述网页的一种语言。

- HTML 指的是超文本标记语言: **H**yper**T**ext **M**arkup **L**anguage
- HTML 不是一种编程语言，而是一种**标记**语言
- 标记语言是一套**标记标签** (markup tag)
- HTML 使用标记标签来**描述**网页
- HTML 文档包含了HTML **标签**及**文本**内容
- HTML文档也叫做 **web 页面**

## HTML 标签

HTML 标记标签通常被称为 HTML 标签 (HTML tag)。

- HTML 标签是由 *尖括号* 包围的关键词，比如 <html>
- HTML 标签通常是 *成对出现* 的，比如  `<b>` 和 `</b>`
- 标签对中的第一个标签是 *开始标签*，第二个标签是 *结束标签*
- 开始和结束标签也被称为 *开放标签* 和 *闭合标签*

`<标签>内容</标签>`

## HTML 网页结构

下面是一个可视化的HTML页面结构：

![image-20220809163853558](https://s2.loli.net/2022/08/09/tQkXIyfFT3cNmlj.png)

**Tips：**  只有 <body> 区域 (白色部分) 才会在浏览器中显示。

## HTTP

超文本传输协议：HyperText Transfer Protocol

## HTML版本

从初期的网络诞生后，已经出现了许多HTML版本:

| 版本      | 发布时间 |
| :-------- | :------- |
| HTML      | 1991     |
| HTML+     | 1993     |
| HTML 2.0  | 1995     |
| HTML 3.2  | 1997     |
| HTML 4.01 | 1999     |
| XHTML 1.0 | 2000     |
| HTML5     | 2012     |
| XHTML5    | 2013     |

## <!DOCTYPE> 声明

<!DOCTYPE>声明有助于浏览器中正确显示网页。

网络上有很多不同的文件，如果能够正确声明HTML的版本，浏览器就能正确显示网页内容。

doctype 声明是不区分大小写的，以下方式均可：

```html
<!DOCTYPE html>

<!DOCTYPE HTML>

<!doctype html>

<!Doctype Html>
```

## 通用声明

```html
HTML5

<!DOCTYPE html>

HTML 4.01

<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN"
"http://www.w3.org/TR/html4/loose.dtd">

XHTML 1.0

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN"
"http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
```

查看完整网页声明类型 [DOCTYPE 参考手册](https://www.runoob.com/tags/tag-doctype.html)。

## 字符集

<meta charset="utf-8">

字符集用 `meta` 标签定义，meta 表示”元“。”元“配置就是表示基本的配置项目。

`meta` 还可以设置关键字和页面描述

```html
<meta name="description"
    content="腾讯网从2003年创立至今，已经成为集新闻信息，区域垂直生活服务、社会化媒体资讯和产品为一体的互联网媒体平台。腾讯网下设新闻、科技、财经、娱乐、体育、汽车、时尚等多个频道，充分满足用户对不同类型资讯的需求。同时专注不同领域内容，打造精品栏目，并顺应技术发展趋势，推出网络直播等创新形式，改变了用户获取资讯的方式和习惯。" />
```

```html
<meta name="" content="" />
```

## head

`<head>` 标签用于定义文档的头部，它是所有头部元素的容器。

`<head>` 中的元素可以引用脚本、指示浏览器在哪里找到样式表，提供元素等等。

以下标签可以用在 head 部分：<basc> , <link> , <meta> , <script> , <style> , <title> 

其中 `<title>` 是 head 部分唯一必须的部分。

# HTML 基础

## HTML 语法特性

1. HTML 对换行不敏感，对 tab 不敏感，只在乎标签的嵌套结构。
2. 空白折叠现象：HTML中的所有文字之间，如果有空格，换行，tab 都将被折叠为一个空格显示。

## HTML h1-h6

HTML 标题（Heading）是通过<h1> - <h6> 标签来定义的。

```html
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>Jacob-xyb</title>
</head>
<body>

<h1>这是标题 1</h1>
<h2>这是标题 2</h2>
<h3>这是标题 3</h3>
<h4>这是标题 4</h4>
<h5>这是标题 5</h5>
<h6>这是标题 6</h6>

</body>
</html>
```

### HTML 水平线

`<hr>` 标签在 HTML 页面中创建水平线。

hr 元素可用于分隔内容。

### HTML 注释

可以将注释插入 HTML 代码中，这样可以提高其可读性，使代码更易被人理解。浏览器会忽略注释，也不会显示它们。

注释写法如下:

```html
<!-- 这是一个注释 -->
```

### HTML 标题大小与字体大小的关系

```html
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html;charset=UTF-8">
        <title>Document</title>
    </head>
    <h1>这是1号标题</h1>
    <font size="6">这是6号字体文本</font>

    <h2>这是2号标题</h2>
    <font size="5">这是5号字体文本</font>

    <h3>这是3号标题</h3>
    <font size="4">这是4号字体文本</font>

    <h4>这是4号标题</h4>
    <font size="3">这是3号字体文本</font>

    <h5>这是5号标题</h5>
    <font size="2">这是2号字体文本</font>

    <h6>这是6号标题</h6>
    <font size="1">这是1号字体文本</font>
</html>
```

![image-20220811231933054](https://s2.loli.net/2022/08/11/eioMubz6rUOQBfJ.png)

## HTML 段落

HTML 段落是通过标签 <p> 来定义的。

**p** 是指：段落 **paragraph**

HTML 标签是分等级的，HTML 将所有的标签分为两种：容器级和文本级。

容器级标签：可以放置任何内容；

文本级标签：只能放置**文字**、**图片**、**表单**元素。

```html
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>Jacob-xyb</title>
</head>
<body>

<p>这是一个段落。</p>
<p>这是一个段落。</p>
<p>这是一个段落。</p>

</body>
</html>
```

### 段落是不能嵌套的

如果将代码写成这样：

```html
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>Jacob-xyb</title>
</head>
<body>

<p>这是一个段落。</p>
<p>段落是不能嵌套的
    <h1>这是一个h1标题</h1>
</p>
<p>这是一个段落。</p>
<p>这是一个段落。</p>

</body>
</html>
```

在浏览器中会自动改变源码：

![image-20220811200630224](https://s2.loli.net/2022/08/11/glAbCLDqpOEm64x.png)

上述案例是遇到 `<h>` 会自动帮助补全 `<p>`

但是如果 `</h>` 后直接接文字就会出现无法意料的情况：

```html
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>Jacob-xyb</title>
</head>
<body>

<p>这是一个段落。</p>
<p>段落是不能嵌套的
    <h1>这是一个h1标题</h1>
</p>
<p><h2>这是一个h2标题</h2>
检查是否能正常显示</p>
<p>这是一个段落。</p>

</body>
</html>
```

![image-20220811201742953](https://s2.loli.net/2022/08/11/RxwP5eqMo4DrJzZ.png)

虽然能正常显示网页，但是浏览器处理的源码格式已经乱了：

![image-20220811201837030](https://s2.loli.net/2022/08/11/Iku1CplfUOnGENY.png)

## HTML 链接

HTML 链接是通过标签 <a> 来定义的。

```html
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>Jacob-xyb</title>
</head>
<body>

<a href="https://github.com/Jacob-xyb">这是一个链接使用了 href 属性</a>

</body>
</html>
```

**提示:**在 href 属性中指定链接的地址。

## HTML 图像

HTML 图像是通过标签 <img> 来定义的.

页面上能够插入的图片类型：jpg(jpeg)、gif、png、bmp

不能插入的图片类型：psd、ai

**q1:为什么 img 是单标签而不是标签对？**

因为如果是标签对，里面就包含内容，标签对就是对内容增加语义，而图片就是一个图片。

```html
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>Jacob-xyb</title>
</head>
<body>

<img src="./images/github_logo.png" alt="github logo"/>

</body>
</html>
```

**注意：** 图像的名称和尺寸是以属性的形式提供的。

### HTML 图像属性

**src**: 就是图像的来源；

**alt**: [alternate 替代] 当这个图片无法被显示时，出现的替代文字（有的浏览器不支持）

## HTML 元素

HTML 文档由 HTML 元素定义。

| 开始标签 *               | 元素内容     | 结束标签 * |
| :----------------------- | :----------- | :--------- |
| `<p>`                    | 这是一个段落 | `</p>`     |
| `<a href="default.htm">` | 这是一个链接 | `</a>`     |
| `<br>`  [blank row]      | 换行         |            |

**Tips:** 开始标签常被称为**起始标签（opening tag）**，结束标签常称为**闭合标签（closing tag）**。

### HTML 元素语法

- HTML 元素以**开始标签**起始
- HTML 元素以**结束标签**终止
- **元素的内容**是开始标签与结束标签之间的内容
- 某些 HTML 元素具有**空内容（empty content）**
- 空元素**在开始标签中进行关闭**（以开始标签的结束而结束）
- 大多数 HTML 元素可拥有**属性**

### 嵌套的 HTML 元素

大多数 HTML 元素可以嵌套（HTML 元素可以包含其他 HTML 元素）。

HTML 文档由相互嵌套的 HTML 元素构成。

### HTML 文档实例解析

```html
<!DOCTYPE html>
<html>

<body>
<p>这是第一个段落。</p>
</body>

</html>
```

以上实例包含了三个 HTML 元素。

- `<p>` 元素:

```html
<p>这是第一个段落。</p>
```

这个 <p> 元素定义了 HTML 文档中的一个段落。
这个元素拥有一个开始标签 <p> 以及一个结束标签 </p>.
元素内容是: 这是第一个段落。

- `<body>` 元素:

```html
<body>
<p>这是第一个段落。</p>
</body>
```

<body> 元素定义了 HTML 文档的主体。
这个元素拥有一个开始标签 <body> 以及一个结束标签 </body>。
元素内容是另一个 HTML 元素（p 元素）。

- `<html>`  元素：

```html
<html>

<body>
<p>这是第一个段落。</p>
</body>

</html>
```

<html> 元素定义了整个 HTML 文档。
这个元素拥有一个开始标签 <html> ，以及一个结束标签 </html>.
元素内容是另一个 HTML 元素（body 元素）。

### 不要忘记结束标签

即使您忘记了使用结束标签，大多数浏览器也会正确地显示 HTML：

<p>这是一个段落<p>这是一个段落

以上实例在浏览器中也能正常显示，因为关闭标签是可选的。

但不要依赖这种做法。忘记使用结束标签会产生不可预料的结果或错误。

## HTML 超级链接

一个网站，是由很多HTML网页组成的。 HTML 网页之间能够相互跳转，点击超链接，形成“网”。

`<a href="default.htm"> </a>`

**a**: [anchor 锚]

**href**: [hypertext reference 超文本地址] 

**title**: 悬停文本

**target**:  "_blank" 新弹窗；

```html
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>Jacob-xyb</title>
</head>
<body>

<a href="005_HTML图像.html">这是一个超链接</a>
<br>
<a href="005_HTML图像.html" title="这也是个超链接" target="_blank"><img src="images/github_logo.png" alt=""></a>


</body>
</html>
```

## HTML 页面锚点

```html
<!DOCTYPE html>
<html>
<head>
	<meta http-equiv="Content-Type" content="text/html;charset=UTF-8">
	<title>Document</title>
</head>
<body>
	<a href="#工作经验">点击我就查看工作经验</a>
	<a href="#wdzp">点击我就查看我的作品</a>

	<h1>个人简介</h1>
	<h2>基本信息</h2>
	<p>基本信息基本信息... 基本信息基本信息</p>

	<h2><a id="工作经验">工作经验</a></h2>
	<p>工作经验工作经验...工作经验工作经验</p>

	<h2><a name="wdzp">我的作品</a></h2>
	<p>我的作品我的作品...我的作品我的作品</p>
</body>
</html>
```

## HTML 样式

style 元素可以出现在 HTML 文档中的各个部分，一个文档可以包含多个 style 元素

### HTML 的 style 属性

style 属性的作用：

**提供了一种改变所有 HTML 元素的样式的通用方法。**

样式是 HTML 4 引入的，它是一种新的首选的改变 HTML 元素样式的方式。通过 HTML 样式，能够通过使用 style 属性直接将样式添加到  HTML 元素，或者间接地在独立的样式表中（CSS 文件）进行定义。

**不赞成使用的标签和属性**

在 HTML 4 中，有若干的标签和属性是被废弃的。被废弃（Deprecated）的意思是在未来版本的 HTML 和 XHTML  中将不支持这些标签和属性。

这里传达的信息很明确：请避免使用这些被废弃的标签和属性！

**应该避免使用下面这些标签和属性：**

| 标签                 | 描述               |
| -------------------- | ------------------ |
| <center>             | 定义居中的内容。   |
| <font> 和 <basefont> | 定义 HTML 字体。   |
| <s> 和 <strike>      | 定义删除线文本     |
| <u>                  | 定义下划线文本     |
| **属性**             | **描述**           |
| align                | 定义文本的对齐方式 |
| bgcolor              | 定义背景颜色       |
| color                | 定义文本颜色       |

对于以上这些标签和属性：请使用样式代替！

```html
<!DOCTYPE html>
<html>
    <head>
        <meta charset="utf-8">
    </head>
    <!-- <body bgcolor="red"> -->
    <body>
        <h1>标题不赞成使用的标签和属性</h1>
        <center> 居中的文本 </center>
        <font color="red">文本加颜色(暂时不知道如何加背景色)</font>
        <h5><font face="verdana">设置字体</font></h5>
        <p><font face="arial" color="red" size="5">设置字体大小</font></p>
        <h1>标题对应的样式写法</h1>
        <p style="text-align:center">居中的文本</p>
        <p style="background-color:red;color:yellow">文本加颜色和背景色</p>
        <h5 style="font-family:verdana">设置字体</h5>
        <p style="font-family:arial;color:red;font-size:20px;">设置字体大小</p>
    </body>
</html>
```

![image-20220813172238083](https://s2.loli.net/2022/08/13/ZA6jGepTPLB4wfC.png)

### HTML5 的 style 属性

| 属性   | 值                                                           | 描述                                                         |
| ------ | ------------------------------------------------------------ | ------------------------------------------------------------ |
| media  | screen、tty、tv、projection、handheld、print、braille、aural、all | 指定样式适用的，媒体                                         |
| scoped | scoped                                                       | 指定样式的作用范围(如果使用该属性，则样式仅仅应用到 style 元素的父元素及其子元素) |
| type   | text/css                                                     | 指定样式的类型                                               |

## HTML 列表

### 无序列表

无序列表是一个项目的列表，此列项目使用粗体圆点（典型的小黑圆圈）进行标记。

无序列表始于 <ul> 标签。每个列表项始于 <li>。

**ul**: [unordered list 无序列表]

**li**: [list item 列表项]

```html
<ul>
<li>Coffee</li>
<li>Milk</li>
</ul>
```

实例：

```html
<!DOCTYPE html>
<html>
<head>
    <meta charset="utf-8">
	<title>Document</title>
</head>
<body>
	<h3>习大大专著</h3>
	<ul>
		<li>
			<h4>习近平谈治国理政</h4>
			<p>¥49.00</p>
			<p>《习近平谈治国理政》谈中国、论世界，为各国读者开启了一扇观察和感知中国的窗口。阅读这本书，可以了解以习近平同志为总书记的党中央治国理念和执政方略，品味悠长醇厚的中国历史文化，感受当</p>
		</li>
		<li>
			<h4>习近平用典</h4>
			<p>¥23.60</p>
			<p>人民日报社社长杨振武主持编写并作序，人民日报社副总编辑卢新宁组织撰写解读文字，旨在对习近平总书记重要讲话（文章）引用典故的现实意义进行解读，对典故的背景义</p>
		</li>
		<li>
			<h4>摆脱贫困</h4>
			<p>26.00</p>
			<p>追本溯源 融会贯通	深入学习贯彻习近平总书记系列重要讲话精神	推动学习贯彻向广度深度拓展	习近平总书记**部个人专著	时隔22年后重印发行</p>
		</li>
	</ul>
</body>
</html>
```

![image-20220813222246961](https://s2.loli.net/2022/08/13/7aRVnPTHOuvJhbt.png)

### 有序列表

同样，有序列表也是一列项目，列表项目使用数字进行标记。

有序列表始于 <ol> 标签。每个列表项始于 <li> 标签。

**ol**: [ordered list 有序列表]

**li**: [list item 列表项]

```html
<ol>
<li>Coffee</li>
<li>Milk</li>
</ol>
```

### 定义列表

自定义列表不仅仅是一列项目，而是项目及其注释的组合。

自定义列表以 <dl> 标签开始。每个自定义列表项以 <dt> 开始。每个自定义列表项的定义以 <dd>  开始。

**dl**: [definition list 定义列表] 

**dt**: [definition title 定义标题]

**dd**: [definition description 定义表述词]

```html
<dl>
<dt>Coffee</dt>
<dd>Black hot drink</dd>
<dt>Milk</dt>
<dd>White cold drink</dd>
</dl>
```

**注意：** 定义列表的列表项内部可以使用段落、换行符、图片、链接以及其他列表等等。

## HTML 块 和 内联

**可以通过 <div> 和 <span> 将 HTML 元素组合起来。**

### HTML 块元素

大多数 HTML 元素被定义为块级元素或内联元素。

编者注：“块级元素”译为 block level element，“内联元素”译为 inline element。

块级元素在浏览器显示时，通常会以新行来开始（和结束）。

例子：<h1>, <p>, <ul>, <table>

### HTML 内联元素

内联元素在显示时通常不会以新行开始。

例子：<b>, <td>, <a>, <img>

## HTML div 和 span

**HTML <div> 元素是块级元素，它是可用于组合其他 HTML 元素的容器。**

<div> 元素没有特定的含义。除此之外，由于它属于块级元素，浏览器会在其前后显示折行。

如果与 CSS 一同使用，<div> 元素可用于对大的内容块设置样式属性。

`<div>` 元素的另一个常见的用途是文档布局。它取代了使用表格定义布局的老式方法。使用 <table>  元素进行文档布局不是表格的正确用法。<table> 元素的作用是显示表格化的数据。

**HTML <span> 元素是内联元素，可用作文本的容器。**

<span> 元素也没有特定的含义。

当与 CSS 一同使用时，<span> 元素可用于为部分文本设置样式属性。

## HTML 类

对 HTML 进行分类（设置类），使我们能够为元素的类定义 CSS 样式。

为相同的类设置相同的样式，或者为不同的类设置不同的样式。

```html
<!DOCTYPE html>
<html>

<head>
    <style>
        .cities {
            background-color: black;
            color: white;
            margin: 20px;
            padding: 20px;
        }
    </style>
</head>

<body>
    <div class="cities">
        <h2>London</h2>
        <p>
            London is the capital city of England.<br>
            It is the most populous city in the United Kingdom,
            with a metropolitan area of over 13 million inhabitants.
        </p>
    </div>
</body>

</html>
```

## HTML 布局

### 使用 <div> + css 元素的 HTML 布局

注释：<div> 元素常用作布局工具，因为能够轻松地通过 CSS 对其进行定位。

这个例子使用了四个 <div> 元素来创建多列布局：

```html
<!DOCTYPE html>
<html>

<head>
    <meta charset="utf-8">
</head>
<style>
    #header {
        background-color: black;
        color: white;
        text-align: center;
        padding: 5px;
    }

    #nav {
        line-height: 30px;
        background-color: #eeeeee;
        height: 300px;
        width: 100px;
        float: left;
        padding: 5px;
    }

    #section {
        width: 350px;
        float: left;
        padding: 10px;
    }

    #footer {
        background-color: black;
        color: white;
        clear: both;
        text-align: center;
        padding: 5px;
    }
</style>

<body>
    <div id="header">
        <h1>City Gallery</h1>
    </div>
    <div id="nav">
        London<br>
        Paris<br>
        Tokyo<br>
    </div>
    <div id="section">
        <h1>London</h1>
        <p>
            London is the capital city of England. It is the most populous city in the United Kingdom,
            with a metropolitan area of over 13 million inhabitants.
        </p>
        <p>
            Standing on the River Thames, London has been a major settlement for two millennia,
            its history going back to its founding by the Romans, who named it Londinium.
        </p>
    </div>
    <div id="footer">
        Copyright W3School.com.cn
    </div>
</body>
```

![image-20220814151619258](https://s2.loli.net/2022/08/14/meS5vGkc6fJRZpW.png)

### 使用 HTML5 的网站布局

HTML5 提供的新语义元素定义了网页的不同部分：

**HTML5 语义元素**

| 标签    | 语义                           |
| ------- | ------------------------------ |
| header  | 定义文档或节的页眉             |
| nav     | 定义导航链接的容器             |
| section | 定义文档中的节                 |
| article | 定义独立的自包含文章           |
| aside   | 定义内容之外的内容（比如侧栏） |
| footer  | 定义文档或节的页脚             |
| details | 定义额外的细节                 |
| summary | 定义 details 元素的标题        |

这个例子使用 <header>, <nav>, <section>, 以及 <footer>  来创建多列布局：

```html
<style>
    header {
        background-color: black;
        color: white;
        text-align: center;
        padding: 5px;
    }

    nav {
        line-height: 30px;
        background-color: #eeeeee;
        height: 300px;
        width: 100px;
        float: left;
        padding: 5px;
    }

    section {
        width: 350px;
        float: left;
        padding: 10px;
    }

    footer {
        background-color: black;
        color: white;
        clear: both;
        text-align: center;
        padding: 5px;
    }
</style>

<body>

    <header>
        <h1>City Gallery</h1>
    </header>

    <nav>
        London<br>
        Paris<br>
        Tokyo<br>
    </nav>

    <section>
        <h1>London</h1>
        <p>
            London is the capital city of England. It is the most populous city in the United Kingdom,
            with a metropolitan area of over 13 million inhabitants.
        </p>
        <p>
            Standing on the River Thames, London has been a major settlement for two millennia,
            its history going back to its founding by the Romans, who named it Londinium.
        </p>
    </section>

    <footer>
        Copyright W3School.com.cn
    </footer>

</body>
```

实现效果与上述一模一样

### 使用表格的 HTML 布局

注释：<table> 元素不是作为布局工具而设计的。

<table> 元素的作用是显示表格化的数据。

使用 <table> 元素能够取得布局效果，因为能够通过 CSS 设置表格元素的样式：

```html
<style>
    table.lamp {
        width: 100%;
        border: 1px solid #d4d4d4;
    }

    table.lamp th,
    td {
        padding: 10px;
    }

    table.lamp td {
        width: 40px;
    }
</style>

<body>
    <table class="lamp">
        <tr>
            <th>
                <img src="./images/github_logo.png" alt="Note">
            </th>
            <td>
                The table element was not designed to be a layout tool.
            </td>
        </tr>
    </table>
</body>
```

![image-20220814152614911](https://s2.loli.net/2022/08/14/abtUiV7WBJjdNS9.png)

## HTML label标签

label 可以起到一个绑定的作用

```html
<!DOCTYPE html>
<html>

<head>
    <meta charset="utf-8">
    <title>Document</title>
</head>

<body>
    <p>
        请选择你的性别：
        <input type="radio" name="sex" id="nan" /> <label for="nan">男</label>
        <input type="radio" name="sex" id="nv" /> <label for="nv">女</label>
    </p>
    <p>
        <input type="checkbox" id="kk" />
        <label for="kk">10天内免登陆</label>
    </p>
    <p>
        <label for="xingming">姓名：</label>
        <input type="text" id="xingming" />
    </p>
</body>

</html>
```

## HTML字符实体

用常用字符表示这些符号的方式。

# HTML 表单

## HTML 表单

**HTML 表单用于搜集不同类型的用户输入。**

### form 元素

HTML 表单用于收集用户输入。

<form> 元素定义 HTML 表单：

实例：

```html
<form>
 .
form elements
 .
</form>
```

---

**HTML 表单包含表单元素。**

表单元素指的是不同类型的 input 元素、复选框、单选按钮、提交按钮等等。

### input 元素

*<input>* 元素是最重要的*表单元素*。

<input> 元素有很多形态，根据不同的 *type* 属性。

主要使用的类型：

| 类型   | 描述                                 |
| ------ | ------------------------------------ |
| text   | 定义常规文本输入。                   |
| radio  | 定义单选按钮输入（选择多个选择之一） |
| submit | 定义提交按钮（提交表单）             |

- **文本输入**

`<input type="text">` 定义用于**文本输入**的单行输入字段：

```html
<form>
 First name:<br>
<input type="text" name="firstname">
<br>
 Last name:<br>
<input type="text" name="lastname">
</form> 
```

![image-20220814153029858](https://s2.loli.net/2022/08/14/IKfxNkFpa5QRAMH.png)

**注释**：表单本身并不可见。还要注意文本字段的默认宽度是 20 个字符。

- **单选按钮输入**

`<input type="radio">`  定义**单选按钮**。

单选按钮允许用户在有限数量的选项中选择其中之一：

```html
<form>
<input type="radio" name="sex" value="male" checked>Male
<br>
<input type="radio" name="sex" value="female">Female
</form> 
```

![image-20220814153152130](https://s2.loli.net/2022/08/14/c4XWonEa6RCtTU2.png)

- **提交按钮**

`<input type="submit">`  定义用于向 **表单处理程序**（form-handler）提交表单的按钮。

表单处理程序通常是包含用来处理输入数据的脚本的服务器页面。

表单处理程序在表单的 **action** 属性中指定：

```html
<form action="action_page.php">
First name:<br>
<input type="text" name="firstname" value="Mickey">
<br>
Last name:<br>
<input type="text" name="lastname" value="Mouse">
<br><br>
<input type="submit" value="Submit">
</form> 
```

![image-20220814153259098](https://s2.loli.net/2022/08/14/wu9d3hT7xV21fPk.png)

- **Action 属性**

**action 属性** 定义在提交表单时执行的动作。

向服务器提交表单的通常做法是使用提交按钮。

通常，表单会被提交到 web 服务器上的网页。

在上面的例子中，指定了某个服务器脚本来处理被提交表单：

```html
<form action="action_page.php">
```

如果省略 action 属性，则 action 会被设置为当前页面。

- **Method 属性**

**method 属性** 规定在提交表单时所用的 HTTP 方法（**GET** 或 **POST**）：

```html
<form action="action_page.php" method="GET">
```

或：

```html
<form action="action_page.php" method="POST">
```

**何时使用 GET？**

如果表单提交是被动的（比如搜索引擎查询），并且没有敏感信息。

当您使用 GET 时，表单数据在页面地址栏中是可见的：

```html
action_page.php?firstname=Mickey&lastname=Mouse
```

注释：GET 最适合少量数据的提交。浏览器会设定容量限制。

**何时使用 POST？**

如果表单正在更新数据，或者包含敏感信息（例如密码）。

POST 的安全性更加，因为在页面地址栏中被提交的数据是不可见的。

- **Name 属性**

如果要正确地被提交，每个输入字段必须设置一个 name 属性。

本例只会提交 "Last name" 输入字段：

```html
<form action="action_page.php">
First name:<br>
<input type="text" value="Mickey">
<br>
Last name:<br>
<input type="text" name="lastname" value="Mouse">
<br><br>
<input type="submit" value="Submit">
</form> 
```

- **fieldset** 

*<fieldset>* 元素组合表单中的相关数据

*<legend>* 元素为 <fieldset> 元素定义标题。

```html
<form action="action_page.php">
<fieldset>
<legend>Personal information:</legend>
First name:<br>
<input type="text" name="firstname" value="Mickey">
<br>
Last name:<br>
<input type="text" name="lastname" value="Mouse">
<br><br>
<input type="submit" value="Submit"></fieldset>
</form> 
```

![image-20220814155201539](https://s2.loli.net/2022/08/14/P8RW2vB4wyS9ZEz.png)

### form 属性

HTML <form> 元素，已设置所有可能的属性，是这样的：

```html
<form action="action_page.php" method="GET" target="_blank" accept-charset="UTF-8"
ectype="application/x-www-form-urlencoded" autocomplete="off" novalidate>
.
form elements
 .
</form> 
```

下面是 <form> 属性的列表：

| 属性           | 描述                                                       |
| -------------- | ---------------------------------------------------------- |
| accept-charset | 规定在被提交表单中使用的字符集（默认：页面字符集）。       |
| action         | 规定向何处提交表单的地址（URL）（提交页面）。              |
| autocomplete   | 规定浏览器应该自动完成表单（默认：开启）。                 |
| enctype        | 规定被提交数据的编码（默认：url-encoded）。                |
| method         | 规定在提交表单时所用的 HTTP 方法（默认：GET）。            |
| name           | 规定识别表单的名称（对于 DOM 使用：document.forms.name）。 |
| novalidate     | 规定浏览器不验证表单。                                     |
| target         | 规定 action 属性中地址的目标（默认：_self）。              |

## HTML表单元素

### \<input> 元素

最重要的表单元素是 `<input>`  元素。

<input> 元素根据不同的  **type**  属性，可以变化为多种形态。

### \<select> 元素（下拉列表）

`<select>` 元素定义*下拉列表*：

```html
<select name="cars">
    <option value="volvo">Volvo</option>
    <option value="saab">Saab</option>
    <option value="fiat">Fiat</option>
    <option value="audi">Audi</option>
</select>
```

`<option>` 元素定义待选择的选项。

列表通常会把首个选项显示为被选选项。

您能够通过添加 selected 属性来定义预定义选项。

```html
<option value="fiat" selected>Fiat</option>
```

### \<textarea> 元素

`<textarea>` 元素定义多行输入字段（**文本域**）：

```html
<textarea name="message" rows="10" cols="30">
The cat was playing in the garden.
</textarea>
```

![image-20220814160957790](https://s2.loli.net/2022/08/14/IbmJNGH1wj5VcZg.png)

### \<button> 元素

`<button>` 元素定义可点击的*按钮*：

```html
<button type="button" onclick="alert('Hello World!')">Click Me!</button>
```

![image-20220814161055407](https://s2.loli.net/2022/08/14/MsZ4J6HIEruo18B.png)

### HTML5 表单元素

HTML5 增加了如下表单元素：

- <datalist> 
- <keygen> 
- <output> 

**注释**：默认地，浏览器不会显示未知元素。新元素不会破坏您的页面。

### HTML5 \<datalist> 元素

`<datalist>` 元素为 `<input>` 元素规定预定义选项列表。

用户会在他们输入数据时看到预定义选项的下拉列表。

<input> 元素的 **list** 属性必须引用 <datalist> 元素的 **id**  属性。

通过 <datalist> 设置预定义值的 <input> 元素：

```html
<form action="action_page.php">
<input list="browsers">
<datalist id="browsers">
   <option value="Internet Explorer">
   <option value="Firefox">
   <option value="Chrome">
   <option value="Opera">
   <option value="Safari">
</datalist> 
</form>
```

## HTML 输入类型

### 输入类型：text

`<input type="text">` 定义供 **文本输入** 的单行输入字段：

```html
<form>
     First name:<br>
    <input type="text" name="firstname">
    <br>
     Last name:<br>
    <input type="text" name="lastname">
</form> 
```

 ![image-20220814153029858](https://s2.loli.net/2022/08/14/IKfxNkFpa5QRAMH.png)

### 输入类型：password

`<input type="password">` 定义 **密码字段**：

```html
<form>
     User name:<br>
    <input type="text" name="username">
    <br>
     User password:<br>
    <input type="password" name="psw">
</form> 
```

![image-20220814181022021](https://s2.loli.net/2022/08/14/k5OJZibolhCdLn3.png)

注释：password 字段中的字符会被做掩码处理（显示为星号或实心圆）。

### 输入类型：submit

`<input type="submit">`  定义 **提交** 表单数据至 **表单处理程序** 的按钮。

表单处理程序（form-handler）通常是包含处理输入数据的脚本的服务器页面。

在表单的 action 属性中规定表单处理程序（form-handler）：

```html
<form action="action_page.php">
    First name:<br>
    <input type="text" name="firstname" value="Mickey">
    <br>
    Last name:<br>
    <input type="text" name="lastname" value="Mouse">
    <br><br>
    <input type="submit" value="Submit">
</form> 
```

![image-20220814155201539](https://s2.loli.net/2022/08/14/P8RW2vB4wyS9ZEz.png)

如果您省略了提交按钮的 value 属性，那么该按钮将获得默认文本：

### Input Type: radio

`<input type="radio">`  定义单选按钮。

Radio buttons let a user select ONLY ONE of a limited number of choices:

```html
<form>
    <input type="radio" name="sex" value="male" checked>Male
    <br>
    <input type="radio" name="sex" value="female">Female
</form> 
```

![image-20220814181358280](https://s2.loli.net/2022/08/14/ROPxfKkULsQlnTw.png)

**注意：** 如果 radion 中的 name 不一致时，就会出现可以多选的情况。

### Input Type: checkbox

`<input type="checkbox">`  定义复选框。

复选框允许用户在有限数量的选项中选择零个或多个选项。

```html
<form>
    <input type="checkbox" name="vehicle" value="Bike">I have a bike
    <br>
    <input type="checkbox" name="vehicle" value="Car">I have a car 
</form> 
```

![image-20220814182358177](https://s2.loli.net/2022/08/14/mQyx2F531MuNrPe.png)

### Input Type: button

`<input type="button>` 定义*按钮*。

```html
<form>
    <input type="button" onclick="alert('Hello World!')" value="Click Me!">
</form> 
```

### Input Type: reset

```html
<form>
	<input type="reset" />
</form> 
```

## HTML5 输入类型

HTML5 增加了多个新的输入类型：

- color 
- date 
- datetime 
- datetime-local 
- email 
- month 
- number 
- range 
- search 
- tel 
- time 
- url 
- week 

注释：老式 web 浏览器不支持的输入类型，会被视为输入类型 text。

### 输入类型：number

`<input type="number">`  用于应该包含数字值的输入字段。

您能够对数字做出限制。

根据浏览器支持，限制可应用到输入字段。

```html
<form>
  Quantity (between 1 and 5):
  <input type="number" name="quantity" min="1" max="5">
</form>
```

**输入限制**

这里列出了一些常用的输入限制（其中一些是 HTML5 中新增的）：

| 属性      | 描述                               |
| --------- | ---------------------------------- |
| disabled  | 规定输入字段应该被禁用。           |
| max       | 规定输入字段的最大值。             |
| maxlength | 规定输入字段的最大字符数。         |
| min       | 规定输入字段的最小值。             |
| pattern   | 规定通过其检查输入值的正则表达式。 |
| readonly  | 规定输入字段为只读（无法修改）。   |
| required  | 规定输入字段是必需的（必需填写）。 |
| size      | 规定输入字段的宽度（以字符计）。   |
| step      | 规定输入字段的合法数字间隔。       |
| value     | 规定输入字段的默认值。             |

```html
<form>
  Quantity:
  <input type="number" name="points" min="0" max="100" step="10" value="30">
</form>
```

### 输入类型：date

`<input type="date">` 用于应该包含日期的输入字段。

根据浏览器支持，日期选择器会出现输入字段中。

```html
<form>
  Birthday:
  <input type="date" name="bday">
</form>
```

**输入限制**

```html
<form>
  Enter a date before 1980-01-01:
  <input type="date" name="bday" max="1979-12-31"><br>
  Enter a date after 2000-01-01:
  <input type="date" name="bday" min="2000-01-02"><br>
</form>
```

### 输入类型：color

`<input type="color">` 用于应该包含颜色的输入字段。

根据浏览器支持，颜色选择器会出现输入字段中。

```html
<form>
  Select your favorite color:
  <input type="color" name="favcolor">
</form>
```

### 输入类型：range

`<input type="range">`  用于应该包含一定范围内的值的输入字段。

根据浏览器支持，输入字段能够显示为滑块控件。

```html
<form>
  <input type="range" name="points" min="0" max="10">
</form>
```

您能够使用如下属性来规定限制：min、max、step、value。

### 输入类型：month

`<input type="month">` 允许用户选择月份和年份。

根据浏览器支持，日期选择器会出现输入字段中。

```html
<form>
  Birthday (month and year):
  <input type="month" name="bdaymonth">
</form>
```

### 输入类型：week

`<input type="week">` 允许用户选择周和年。

根据浏览器支持，日期选择器会出现输入字段中。

```html
<form>
  Select a week:
  <input type="week" name="week_year">
</form>
```

### 输入类型：time

`<input type="time">` 允许用户选择时间（无时区）。

根据浏览器支持，时间选择器会出现输入字段中。

```html
<form>
  Select a time:
  <input type="time" name="usr_time">
</form>
```

### 输入类型：datetime

`<input type="datetime">` 允许用户选择日期和时间（有时区）。

根据浏览器支持，日期选择器会出现输入字段中。

```html
<form>
  Birthday (date and time):
  <input type="datetime" name="bdaytime">
</form>
```

### 输入类型：datetime-local

`<input type="datetime-local">` 允许用户选择日期和时间（无时区）。

 根据浏览器支持，日期选择器会出现输入字段中。

```html
<form>
  Birthday (date and time):
  <input type="datetime-local" name="bdaytime">
</form>
```

### 输入类型：email

`<input type="email">` 用于应该包含电子邮件地址的输入字段。

根据浏览器支持，能够在被提交时自动对电子邮件地址进行验证。

某些智能手机会识别 email 类型，并在键盘增加 ".com" 以匹配电子邮件输入。

```html
<form>
  E-mail:
  <input type="email" name="email">
</form>
```

### 输入类型：search

`<input type="search">` 用于搜索字段（搜索字段的表现类似常规文本字段）。

```html
<form>
  Search Google:
  <input type="search" name="googlesearch">
</form>
```

### 输入类型：tel

`<input type="tel">` 用于应该包含电话号码的输入字段。

目前只有 Safari 8 支持 tel 类型。

```html
<form>
  Telephone:
  <input type="tel" name="usrtel">
</form>
```

### 输入类型：url

`<input type="url">` 用于应该包含 URL 地址的输入字段。

根据浏览器支持，在提交时能够自动验证 url 字段。

某些智能手机识别 url 类型，并向键盘添加 ".com" 以匹配 url 输入。

```html
<form>
  Add your homepage:
  <input type="url" name="homepage">
</form>
```

## HTML 输入属性

TODO
