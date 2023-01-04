# HTML 5 介绍

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

## meta

- **声明网页解析编码格式**

```html
<meta charset="utf-8">
```

- **网页自适应**

```html
<meta name="viewport" content="width=device-width, initial-scale=1.0"
```

- **搜索优化**

```html
<mata name="keywords" content="Web开发,HTML5,CSS3">
<meta name="description" content="实例演示，描述内容。">
<meta name="author" content = "Jacob-xyb">
```

- **网页自动跳转**

```html
<meta http-equiv="refresh" content="5"; https://space.bilibili.com/12502993>
```

# HTML 基础

##  语法特性

1. HTML 对换行不敏感，对 tab 不敏感，只在乎标签的嵌套结构。
2. 空白折叠现象：HTML中的所有文字之间，如果有空格，换行，tab 都将被折叠为一个空格显示。

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

## HTML 注释

可以将注释插入 HTML 代码中，这样可以提高其可读性，使代码更易被人理解。浏览器会忽略注释，也不会显示它们。

注释写法如下:

```html
<!-- 这是一个注释 -->
```

# HTML基础标签 \*\*\*\*\*\*\*\*\*\*

##  h1-h6 标题

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

## p 段落

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

## br 换行

> `<br>`标签用于插入一个简单的换行符。

## hr 水平线分隔线

> `<hr>` 标签用于在 HTML 页面中创建一条水平分隔线。

属性有：color、width、align（对齐的意思）、noshade

- width: 默认 100%，

- align: 默认 center 

```html
<hr color="pink" width="300px" align="left" noshade>
```

# 格式化文本标签

## 加粗

- **strong**

  > `<strong>` 标签用于定义表示重要的文本。

  提示：如果只是为了达到某种视觉效果而使用这个标签的话，强烈建议使用 CSS 代替。

- **b 标签**

  全拼：bold
  
  > `<b>` 标签用于定义表示粗体的文本。

  b 元素仅表示粗体的文本，并**没有**附带任何表示重要的语义。
  
  根据 HTML5 的规范，如果你只是想实现加粗效果，强烈建议使用 CSS 代替。
  
- **css**

  `font-weight: bolder;`

## 倾斜

- **em**

  全拼：emphasize

  > `<em>` 标签用于定义表示强调的文本。

  提示：如果只是为了达到某种视觉效果而使用这个标签的话，强烈建议使用 CSS 代替。

- **i**

  全拼：italic

  > `<i>` 标签用于定义表示斜体的文本。

  i 元素仅表示斜体的文本，并**没有**附带任何表示强调的语义。

  根据 HTML5 的规范，如果你只是想实现斜体效果，强烈建议使用 CSS 代替。

- **css**

  `font-style: italic;`

## 删除线

- **del**

  > `<del>`标签用于定义文已被删除的文本。

  请与 [<ins>](https://man.ilovefishc.com/pageHTML5/ins.html) 标签配合使用，来描述文档中的更新和修正。

- **s**

  全拼：strike

  > `<s>`标签用来定义那些不正确的文本

  `<s>` 对那些不正确、不准确或者没有用的文本进行标识。

  `<s>` 标签不应该用来定义替换的或者删除的文本。

- **css**

  `text-decoration: line-through;`

## 下划线

- **ins**

  > `<ins>` 标签用于定义新插入的文本。

  请与 [<del>](https://man.ilovefishc.com/pageHTML5/del.html) 标签配合使用，来描述文档中的更新和修正。

- **u**

  全拼：underline

  > `<u>`标签定义与常规文本风格不同的文本。

  `<u>` 标签通常可以用于定义像拼写错误的单词或者汉语中的专有名词，但注意要与超链接区分开来。

  根据 HTML5 的规范，如果你只是想为文本添加下划线效果，推荐使用 css 样式来实现。

- **css**

  `text-decoration: underline;`

## 上下标

> `<sub>` 标签用于定义下标文本。全拼：subscript
>
> `<sup>` 标签用于定义上标文本。全拼：superscript

## 预格式化文本

> `<pre>` 标签用于定义预格式化的文本。

pre 元素中的文本通常会保留空格和换行符，而文本自身也会呈现为等宽字体。

# HTML字符实体

在 HTML 中，某些字符是预留的。不能使用包含这些字符的文本。

在 HTML 中**不能**使用小于号`（<）`和大于号`（>）`，这是因为浏览器会误认为它们是标签。

如果希望正确地显示预留字符，我们必须在 HTML 源代码中使用**字符实体（character entities）**。

## HTML 预留字符

| 字符 | 实体编号 | 实体名称     | 描述         |
| ---- | -------- | ------------ | ------------ |
| "    | `&#34;`  | `&quot;`     | quotation    |
| '    | `&#39;`  | `	&apos;` | apostrophe   |
| &    | `&#38;`  | `&amp;`      | ampersand    |
| <    | `&#60;`  | `$lt;`       | less-than    |
| >    | `&#62;`  | `$gt;`       | greater-than |

## ISO 8859-1 符号实体

[查表地址](https://man.ilovefishc.com/pageHTML5/ISO.html)

| 字符 | 实体编号 | 实体名称 | 描述                        |
| ---- | -------- | -------- | --------------------------- |
|      | `&#160;`      | `&nbsp;`      | non-breaking space  |
| 		|  				| `&ensp;` | En Space 半角空格|
| 		|  				| `&emsp;` | Em Space 全角空格|
| ¡    | `&#161;` | `&iexcl;` | inverted exclamation mark   |
| ¢    | `¢`      | `¢`      | cent                        |
| £    | `£`      | `£`      | pound                       |
| ¤    | `¤`      | `¤`      | currency                    |
| ¥    | `¥`      | `¥`      | yen                         |
| ¦    | `¦`      | `¦`      | broken vertical bar         |
| §    | `§`      | `§`      | section                     |
| ¨    | `¨`      | `¨`      | spacing diaeresis           |
| ©    | `&#169;` | `&copy;` | copyright                   |
| ª    | `ª`      | `ª`      | feminine ordinal indicator  |
| «    | `«`      | `«`      | angle quotation mark (left) |
| ¬    | `¬`      | `¬`      | negation                    |
|      | `­`      | `­`      | soft hyphen                 |
| ®    | `&#174;` | `&reg;` | registered trademark        |
| ¯    | `¯`      | `¯`      | spacing macron              |
| °    | `°`      | `°`      | degree                      |
| ±    | `±`      | `±`      | plus-or-minus               |
| ²    | `²`      | `²`      | superscript 2               |
| ³    | `³`      | `³`      | superscript 3               |
| ´    | `´`      | `´`      | spacing acute               |
| µ    | `µ`      | `µ`      | micro                       |
| ¶    | `¶`      | `¶`      | paragraph                   |
| ·    | `·`      | `·`      | middle dot                  |
| ¸    | `¸`      | `¸`      | spacing cedilla             |
| ¹    | `¹`      | `¹`      | superscript 1               |
| º    | `º`      | `º`      | masculine ordinal indicato  |
| »    | `»`      | `»`      | angle quotation mark (righ  |
| ¼    | `¼`      | `¼`      | fraction 1/4                |
| ½    | `½`      | `½`      | fraction 1/2                |
| ¾    | `¾`      | `¾`      | fraction 3/4                |
| ¿    | `¿`      | `¿`      | inverted question mark      |
| ×    | `×`      | `×`      | multiplication              |
| ÷    | `÷`      | `÷`      | division                    |

## ISO 8859-1 字符实体

[查表地址](https://man.ilovefishc.com/pageHTML5/ISO.html#iso-8859-1-%E5%AD%97%E7%AC%A6%E5%AE%9E%E4%BD%93)

| 字符 | 实体编号 | 实体名称 | 描述                         |
| ---- | -------- | -------- | ---------------------------- |
| À    | `À`      | `À`      | capital a, grave accent      |
| Á    | `Á`      | `Á`      | capital a, acute accent      |
| Â    | `Â`      | `Â`      | capital a, circumflex accent |
| Ã    | `Ã`      | `Ã`      | capital a, tilde             |
| Ä    | `Ä`      | `Ä`      | capital a, umlaut mark       |
| Å    | `Å`      | `Å`      | capital a, ring              |
| Æ    | `Æ`      | `Æ`      | capital ae                   |
| Ç    | `Ç`      | `Ç`      | capital c, cedilla           |
| È    | `È`      | `È`      | capital e, grave accent      |
| É    | `É`      | `É`      | capital e, acute accent      |
| Ê    | `Ê`      | `Ê`      | capital e, circumflex accent |
| Ë    | `Ë`      | `Ë`      | capital e, umlaut mark       |
| Ì    | `Ì`      | `Ì`      | capital i, grave accent      |
| Í    | `Í`      | `Í`      | capital i, acute accent      |
| Î    | `Î`      | `Î`      | capital i, circumflex accent |
| Ï    | `Ï`      | `Ï`      | capital i, umlaut mark       |
| Ð    | `Ð`      | `Ð`      | capital eth, Icelandic       |
| Ñ    | `Ñ`      | `Ñ`      | capital n, tilde             |
| Ò    | `Ò`      | `Ò`      | capital o, grave accent      |
| Ó    | `Ó`      | `Ó`      | capital o, acute accent      |
| Ô    | `Ô`      | `Ô`      | capital o, circumflex acc    |
| Õ    | `Õ`      | `Õ`      | capital o, tilde             |
| Ö    | `Ö`      | `Ö`      | capital o, umlaut mark       |
| Ø    | `Ø`      | `Ø`      | capital o, slash             |
| Ù    | `Ù`      | `Ù`      | capital u, grave accent      |
| Ú    | `Ú`      | `Ú`      | capital u, acute accent      |
| Û    | `Û`      | `Û`      | capital u, circumflex accen  |
| Ü    | `Ü`      | `Ü`      | capital u, umlaut mark       |
| Ý    | `Ý`      | `Ý`      | capital y, acute accent      |
| Þ    | `Þ`      | `Þ`      | capital THORN, Icelandic     |
| ß    | `ß`      | `ß`      | small sharp s, German        |
| à    | `à`      | `à`      | small a, grave accent        |
| á    | `á`      | `á`      | small a, acute accent        |
| â    | `â`      | `â`      | small a, circumflex accent   |
| ã    | `ã`      | `ã`      | small a, tilde               |
| ä    | `ä`      | `ä`      | small a, umlaut mark         |
| å    | `å`      | `å`      | small a, ring                |
| æ    | `æ`      | `æ`      | small ae                     |
| ç    | `ç`      | `ç`      | small c, cedilla             |
| è    | `è`      | `è`      | small e, grave accent        |
| é    | `é`      | `é`      | small e, acute accent        |
| ê    | `ê`      | `ê`      | small e, circumflex accent   |
| ë    | `ë`      | `ë`      | small e, umlaut mark         |
| ì    | `ì`      | `ì`      | small i, grave accent        |
| í    | `í`      | `í`      | small i, acute accent        |
| î    | `î`      | `î`      | small i, circumflex accent   |
| ï    | `ï`      | `ï`      | small i, umlaut mark         |
| ð    | `ð`      | `ð`      | small eth, Icelandic         |
| ñ    | `ñ`      | `ñ`      | small n, tilde               |
| ò    | `ò`      | `ò`      | small o, grave accent        |
| ó    | `ó`      | `ó`      | small o, acute accent        |
| ô    | `ô`      | `ô`      | small o, circumflex accent   |
| õ    | `õ`      | `õ`      | small o, tilde               |
| ö    | `ö`      | `ö`      | small o, umlaut mark         |
| ø    | `ø`      | `ø`      | small o, slash               |
| ù    | `ù`      | `ù`      | small u, grave accent        |
| ú    | `ú`      | `ú`      | small u, acute accent        |
| û    | `û`      | `û`      | small u, circumflex acc      |
| ü    | `ü`      | `ü`      | small u, umlaut mark         |
| ý    | `ý`      | `ý`      | small y, acute accent        |
| þ    | `þ`      | `þ`      | small thorn, Icelandic       |
| ÿ    | `ÿ`      | `ÿ`      | small y, umlaut mark         |

# HTML 样式

style 元素可以出现在 HTML 文档中的各个部分，一个文档可以包含多个 style 元素

## HTML 的 style 属性

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

## HTML5 的 style 属性

| 属性   | 值                                                           | 描述                                                         |
| ------ | ------------------------------------------------------------ | ------------------------------------------------------------ |
| media  | screen、tty、tv、projection、handheld、print、braille、aural、all | 指定样式适用的，媒体                                         |
| scoped | scoped                                                       | 指定样式的作用范围(如果使用该属性，则样式仅仅应用到 style 元素的父元素及其子元素) |
| type   | text/css                                                     | 指定样式的类型                                               |

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

## pre

`<pre>` 标签用于定义预格式化的文本。

pre 元素中的文本通常会保留空格和换行符，而文本自身也会呈现为等宽字体。

```html
<!DOCTYPE html>
<html>
<head>
    <meta charset="utf-8">
    <title>鱼C-零基础入门学习Web（Html5+Css3）</title>
</head>
<body>
    <pre>
    pre 元素中的文本通常会保留空格   和

换行符，而文本自身也会呈现为等宽字体。
    </pre>
</body>
</html>
```

## code

## q

`<q>` 标签定义较短的引用。

浏览器通常会在引用内容的两侧添加引号。

**注意:**

`<q>` 标签在本质上与[``](https://man.ilovefishc.com/pageHTML5/blockquote.html) 是一样的。不同之处在于它们的显示和应用。

`<q>` 标签用于简短的行内引用。如果需要引用较长的内容，建议使用 `<blockquote>` 标签。

## cite

`<cite>` 标签定义作品（比如书籍、歌曲、电影、电视节目、绘画、雕塑等）的标题。

## abbr

`<abbr>` 标签定义简称或缩写，比如 “WWW” 或 “NATO”。

通过对缩写进行标记，能够为浏览器、拼写检查和搜索引擎提供有用的信息。

```html
<!DOCTYPE HTML>
<html>
<head>
    <meta charset="UTF-8">
    <title>鱼C-零基础入门学习Web（Html5+Css3）</title>
</head>
<body>
    The <abbr title="鱼C工作室">FishC</abbr> was founded in 2010.
</body>
</html>
```

## dfn

`<dfn>` 标签表现定义中的术语。

术语又称技术名词，是在特定专业领域中一般概念的词语指称，一个术语表示一个概念。

```html
<!DOCTYPE html>
<html>
<head>
    <meta charset="utf-8">
    <title>鱼C-零基础入门学习Web（Html5+Css3）</title>
</head>
<body>
    <dfn>HTML</dfn>是一门用于创建网页的标准标记语言。
</body>
</html>
```

![image-20220903145459187.png](https://s2.loli.net/2022/09/03/ypLwHnokE36tvFq.png)

## address

`<address>` 标签定义文档或文章的作者/拥有者的联系信息。

**注意:**

如果 `<address>` 位于 [``](https://man.ilovefishc.com/pageHTML5/body.html) 标签内，则它表示文档的联系信息。

如果 `<address>` 位于[``](https://man.ilovefishc.com/pageHTML5/article.html) 标签内，则它表示文章的联系信息。

```html
<!DOCTYPE html>
<html>
<head>
    <meta charset="UTF-8">
    <title>鱼C-零基础入门学习Web（Html5+Css3）</title>
</head>
<body>
    <address>
        <strong>联系我们</strong><br>
        邮箱：<a href="mailto:fishc_service@126.com">fishc_service@126.com</a>.<br>
        旺旺：dingdingjiayu<br>
        微信：FishC_Studio（公众号）<br>
    </address>
</body>
</html>
```

![image.png](https://s2.loli.net/2022/09/03/q7HELytckIUfCdj.png)

## ruby、rt、rp

`<ruby>` 标签定义注音符号。

**注意：**

ruby 元素需要与 [rt](https://man.ilovefishc.com/pageHTML5/rt.html) 元素和 [rp](https://man.ilovefishc.com/pageHTML5/rp.html) 元素搭配使用。

其中，[rt](https://man.ilovefishc.com/pageHTML5/rt.html) 元素用来标记注音符号，[rp](https://man.ilovefishc.com/pageHTML5/rp.html) 元素则用来标记当浏览器不支持 ruby 元素时所显示的内容。

```html
<!DOCTYPE html>
<html>
<head>
    <meta charset='utf-8'>
    <title>鱼C-零基础入门学习Web（Html5+Css3）</title>
</head>
<body>
    <ruby>
        小 <rp>(</rp><rt>xiǎo</rt><rp>)</rp>
        甲 <rp>(</rp><rt>jiǎ</rt><rp>)</rp>
        鱼 <rp>(</rp><rt>yú</rt><rp>)</rp>
    </ruby>
</body>
</html>
```

![image.png](https://s2.loli.net/2022/09/03/g3R7XshVUvQBlT1.png)

## bdo

`bdo` 标签修改默认的文本方向。

| 属性 | 值       | 描述                                                         |
| ---- | -------- | ------------------------------------------------------------ |
| dir  | ltr、rtl | 定义文字的方向（ltr -> left to right；rtl -> right to left） |

```html
<!DOCTYPE html>
<html>
<head>
    <meta charset="UTF-8">
    <title>鱼C-零基础入门学习Web（Html5+Css3）</title>
</head>
<body>
    <p>正常：Welcome to FishC.com</p>
    <p>
        如果鱼油的浏览器支持 bi-directional override (bdo)，下一行会从右向左输出 (rtl)；
    </p>
    <bdo dir="rtl">
        Welcome to FishC.com
    </bdo>
</body>
</html>
```

![image.png](https://s2.loli.net/2022/09/03/NwRtiuxHk5TKLIB.png)

## strong 重点

`<strong>` 标签用于定义表示重要的文本。

表现出加粗的样式

提示：如果只是为了达到某种视觉效果而使用这个标签的话，强烈建议使用 CSS 代替，不要用 `b`。

## em 强调

`<em>` 标签用于定义表示强调的文本。

表现出倾斜的样式

提示：如果只是为了达到某种视觉效果而使用这个标签的话，强烈建议使用 CSS 代替，不要用 `i` 。

## del、ins

`<del>`标签用于定义文已被删除的文本。

请与 `ins`  标签配合使用，来描述文档中的更新和修正。

| 属性     | 值                     | 描述                                                   |
| -------- | ---------------------- | ------------------------------------------------------ |
| cite     | URL                    | 指向另外一个文档的 URL，此文档可解释文本被删除的原因。 |
| datetime | YYYY-MM-DDThh:mm:ssTZD | 定义文本被删除的日期和时间。                           |

```html
<!DOCTYPE html>
<html>
<head>
    <meta charset="UTF-8">
    <title>鱼C-零基础入门学习Web（Html5+Css3）</title>
</head>
<body>
    <p>从今天起，鱼C论坛的域名从 <del>bbs.fishc.com</del> 变成 <ins>fishc.com.cn</ins>，官网从 <del>www.fishc.com</del> 变成 <ins>ilovefishc.com</ins></p>
    <p>不过你们要是觉得以前的域名布局比较好，也依旧可以访问旧的域名，它会自动进行跳转。</p>
</body>
</html>
```

![image.png](https://s2.loli.net/2022/09/04/VPm2Sb5OEqFAGI9.png)

## mark 标记文本

`<mark>` 标签用于定义带有标记的文本。

黄底标记

## sub、sup 上下标

上下标文本

```html
<!DOCTYPE html>
<html>
<head>
    <meta charset="utf-8">
    <title>鱼C-零基础入门学习Web（Html5+Css3）</title>
</head>
<body>
    <p>这个文本包含 <sub>sub-下标</sub>文本。</p>
    <p>这个文本包含 <sup>sup-上标</sup> 文本。</p>
</body>
</html>
```

![image.png](https://s2.loli.net/2022/09/04/ta81YJ25PkuwKon.png)

## small

`<small>` 标签用于定义更小字体的文本（比如旁注）。

## \<link>

`<link>` 标签用于指定外部资源。

link 元素最常见的用途是链接样式表。

**注意：**

- link 元素定义了 6 个属性，其中 rel 属性是必选的，它说明了当前文档与被链接资源之间的关系。

| 属性                                                        | 值                                                           | 描述                                     |
| ----------------------------------------------------------- | ------------------------------------------------------------ | ---------------------------------------- |
| href                                                        | URL                                                          | 指定被链接资源的 URL。                   |
| hreflang                                                    | language_code                                                | 指定被链接资源使用的语言。               |
| sizes                                                       | HeightxWidth                                                 | 指定图标的大小（比如 `sizes="16x16"`）。 |
| [`media`](https://man.ilovefishc.com/pageHTML5/media1.html) | media_query                                                  | 指定被链接的资源将被显示到什么设备上。   |
| [`rel`](https://man.ilovefishc.com/pageHTML5/rel.html)      | alternate、author、help、icon、licence、next、pingback、prefetch、prev、search、sidebar、stylesheet、tag | 指定当前文档与被链接资源之间的关系。     |
| [`type`](https://man.ilovefishc.com/pageHTML5/type1.html)   | MIME_type                                                    | 规定被链接文档的 MIME 类型。             |

最常见用例：

```html
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <link rel="stylesheet" type="text/css" href="css/fishc.css" >
</head>
<body>
    <h1>我通过外部样式表进行格式化。</h1>
</body>
</html>
```

### shortcut icon和icon 的区别

过去，为保证favicon出现，网站设计者和开发者采用了多种方法。很难明确地保证favicon可以在所有电脑上显示，即使是用同一版本的一种浏览器。
下列代码另一个局限就是它把favicon关联到了某个特定的HTML或XHTML文档上。为避免这一点，favicon.ico文件应置于根目录下。多数浏览器将自动检测并使用它。
建议包含以下两行HTML代码:

```html
<link rel="shortcut icon" href="http://example.com/favicon.ico" type="image/vnd.microsoft.icon">
<link rel="icon" href="http://example.com/favicon.ico" type="image/vnd.microsoft.icon"> 
```

然而，只有第一行是必须的，因为“shortcut icon”字符串将被多数遵守标准的浏览器识别为列出可能的关键词（“shortcut”将被忽略，而仅适用“icon”）；而Internet Explorer将会把它作为一个单独的名称（“shortcut icon”）。这样做的结果是所有浏览器都可以理解此代码。只有当希望为新浏览器提供另一种备用图像（例如动画GIF）时，才有必要添加第二行。

# 结构化标签

## div

> `<div>` 标签定义 HTML 文档中的一个分隔区块或者一个区域部分。

**HTML <div> 元素是块级元素，它是可用于组合其他 HTML 元素的容器。**

`<div>` 元素没有特定的含义。除此之外，由于它属于块级元素，浏览器会在其前后显示折行。


如果与 CSS 一同使用，<div> 元素可用于对大的内容块设置样式属性。

`<div>` 元素的另一个常见的用途是文档布局。它取代了使用表格定义布局的老式方法。使用 <table>  元素进行文档布局不是表格的正确用法。<table> 元素的作用是显示表格化的数据。

## span

> `<span>` 标签用于组合文档中的行内元素。

**HTML <span> 元素是内联元素，可用作文本的容器。**

<span> 元素也没有特定的含义。

当与 CSS 一同使用时，<span> 元素可用于为部分文本设置样式属性。

# 列表标签

## \<ul> 无序列表

>  `<ul>` 标签用于定义无序列表。

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

### 属性

- type: 列表显示的类型

  - disc: 实心圆 (默认)
  - circle: 空心圆
  - square: 实心方块
  - none: 无样式

  > type 属性对应 css 的 [list-style-type](https://man.ilovefishc.com/pageCSS3/list-style-type.html)

## \<ol> 有序列表

> `<ol>` 标签用于定义有序列表。

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

### 属性

| 属性     | 值            | 描述                             |
| -------- | ------------- | -------------------------------- |
| reversed | reversed      | 规定列表顺序为降序。(9, 8, 7, …) |
| start    | number        | 规定有序列表的起始值。           |
| type     | 1、A、a、I、i | 规定在列表中使用的标记类型。     |

如果 `<ol type="a" start="27">` 那么序列从 `aa` 开始排序。

> 有序列表 css 的  [list-style-type](https://man.ilovefishc.com/pageCSS3/list-style-type.html) 支持更多样式

## \<dl> 自定义列表

> `<dl>` 标签定义了一个包含术语定义以及描述的列表。
>
> `<dt>` 标签用于定义列表中的项目（即术语部分）。
>
> `<dd>` 标签用于定义列表中项目的描述部分。

注意：`dd` 有一个默认的边距。

自定义列表不仅仅是一列项目，而是项目及其注释的组合。

自定义列表以 <dl> 标签开始。每个自定义列表项以 <dt> 开始。每个自定义列表项的定义以 <dd>  开始。

**dl**: [definition list 定义列表] 

**dt**: [definition title 定义标题]

**dd**: [definition description 定义表述词]

> **Tips: 一个 dl 一般设置为一个样式，一个 dl 只包含一个 dt 和 一个 dd**

```html
<!-- dl 一般是一个样式 -->
<dl>
    <dt>我是图片</dt>
    <dd>我是文字</dd>
</dl>
<dl>
    <dt>我是图片</dt>
    <dd>我是文字</dd>
</dl>
```

**注意：** 定义列表的列表项内部可以使用段落、换行符、图片、链接以及其他列表等等。

# 图片标签

## \<img> 标签

> `<img>` 标签用于向网页中嵌入一幅图像。

页面上能够插入的图片类型：jpg(jpeg)、gif、png、bmp

不能插入的图片类型：psd、ai

**注意：** `<img>` 标签有两个必需的属性：src 属性 和 alt 属性。

| 属性     | 值            | 描述                             |
| -------- | ------------- | -------------------------------- |
| `alt`    | text          | 指定图像的替代文本。             |
| `src`    | URL           | 指定显示图像的 URL。             |
| `title`  | text          | 鼠标悬停后的提示信息             |
| width    | px(pixels)、% | 设置图像的宽度（像素或百分比）。 |
| height   | px(pixels)、% | 定义图像的高度（像素或百分比）。 |
| ismap    | URL           | 将图像定义为服务器端图像映射。   |
| longdesc | URL           | 指定包含长的图像描述文档的 URL。 |
| usemap   | URL           | 将图像定义为客户器端图像映射。   |

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

### 图片的宽高

如果单独设置 width 或者 height，图片会按照比例缩放，长宽比并不会改变；

如果同时设置宽高，图片的长宽比就会改变。

# 链接标签

## \<a> 标签

> `<a>` 标签用于定义超链接，超链接可以让用户从一个网页跳转到另一个网页。

**a**: [anchor 锚]

<a> 标签最重要的属性是 href 属性，它指定了链接目标的 URL。

在浏览器中，通常超链接的默认外观是：

![image.png](https://s2.loli.net/2022/11/01/McvRa78gsKSe615.png)

**注意**：

在 HTML 4.01 中，`<a>` 标签可以是超链接或锚。

在 HTML5 中，`<a>` 标签始终是超链接，但是如果未设置 href 属性，则只是超链接的占位符。

HTML5 提供了一些新属性，同时不再支持一些 HTML 4.01 属性。

### 属性

| 属性       | 值                                              | 描述                                                         |
| ---------- | ----------------------------------------------- | ------------------------------------------------------------ |
| download   | filename                                        | 指定被下载的超链接目标。                                     |
| **href**   | URL                                             | 指定链接指向页面的 URL。 [hypertext reference 超文本地址]    |
| hreflang   | language_code                                   | 指定被链接文档的语言。                                       |
| media      | media_query                                     | 指定被链接文档是为何种媒介/设备优化的。                      |
| rel        | text                                            | 规定当前文档与被链接文档之间的关系。                         |
| **target** | **\_blank**、\_parent、\_self、\_top、framename | 指定在何处打开超链接。\_blank：在新窗口中打开 ；\_parent：在当前的父窗口中打开，如果不存在父窗口，此选项的行为方式与 _self 等同 _self：当前窗口打开（默认） _top：在整个窗口中打开 framename：在指定的框架中打开 |
| type       | MIME type                                       | 指定被链接文档的的 MIME 类型。                               |
| title      | description                                     | 鼠标悬停显示的提示文本                                       |

### 超级链接

一个网站，是由很多HTML网页组成的。 HTML 网页之间能够相互跳转，点击超链接，形成“网”。

`<a href="default.htm"> </a>`

```html
<a href="005_HTML图像.html">这是一个超链接</a>
<br>
<a href="005_HTML图像.html" title="这也是个超链接" target="_blank"><img src="images/github_logo.png" alt=""></a>
```

### HTML 页面锚点

```html
<a href="#工作经验">点击我就查看工作经验</a>
<a href="#wdzp">点击我就查看我的作品</a>

<h1>个人简介</h1>
<h2>基本信息</h2>
<p>基本信息基本信息... 基本信息基本信息</p>
<!-- HTML4 -->
<h2><a name="wdzp">我的作品</a></h2>
<p>我的作品我的作品...我的作品我的作品</p>
<div style="height: 800px;"></div>
<!-- HTML 5 -->
<h2 id="工作经验">工作经验</h2>
<p>工作经验工作经验...工作经验工作经验</p>
```

HTML4：是使用 `<a name="锚点"></a>` 进行跳转的。注意：这里的name属性只是针对a标签，其他标签不可随意添加name属性。

HTML5：支持使用 任意属性的 `id` 进行跳转，也就是说，并不需要依赖内嵌 a 标签了。

#  表格标签

## \<table> 标签

> `<table>` 标签用于定义 HTML 表格。

简单的 HTML 表格由 table 元素以及一个或多个 [`tr`](https://man.ilovefishc.com/pageHTML5/tr.html) 、[`th`](https://man.ilovefishc.com/pageHTML5/th.html) 或 [`td`](https://man.ilovefishc.com/pageHTML5/td.html) 标签组成。

tr 元素定义表格中的行，th 元素定义表格中的表头，td 元素定义表格中的单元格。

更复杂的 HTML 表格也可能包括 `<caption>` 、`<col>`  、 [`<colgroup>`](https://man.ilovefishc.com/pageHTML5/colgroup.html) 、[`<thead>`](https://man.ilovefishc.com/pageHTML5/thead.html) 、[`<tfoot>`](https://man.ilovefishc.com/pageHTML5/tfoot.html) 以及 [`<tbody>`](https://man.ilovefishc.com/pageHTML5/tbody.html) 元素。

```html
<body>
    <table>
        <tr>
            <th>ISBN</th>
            <th>Title</th>
        </tr>
        <tr>
            <td>3476896</td>
            <td>零基础入门学习Web（Html5+Css3）</td>
        </tr>
        <tr>
            <td>2489604</td>
            <td>零基础入门学习Web（JavaScript）</td>
        </tr>
    </table>
</body>
```

```css
table, th, td {
    border: 1px solid black;
}

table {
    border-collapse: collapse;
}
```

![image.png](https://s2.loli.net/2022/09/07/LxuqzrsD91dAQbG.png)

### 属性

| 属性                     | 值                  | 描述                                                         |
| ------------------------ | ------------------- | ------------------------------------------------------------ |
| align (不推荐使用)       | left、center、right | 文档中的**表格对齐方式**，应该使用 `margin: 0 auto;` 替代    |
| bgcolor (不推荐使用)     | color               | 表格的背景颜色，应该使用 `background-color` 替代             |
| border (不推荐使用)      | int                 | 表格边框的大小，应该使用 `border` 替代                       |
| bordercolor (不推荐使用) | color               | 表格边框的颜色，应该使用 `border-color` 替代                 |
| cellpadding (不推荐使用) | pixel\| %           | 这个属性定义了表格单元的内容和边框之间的空间。如果它是一个像素长度单位，这个像素将被应用到所有的四个侧边；如果它是一个百分比的长度单位，内容将被作为中心，总的垂直（上和下）长度将代表这个百分比。这同样适用于总的水平（左和右）空间。<br/>应该使用 `table {border-collapse: collapse} td {padding: pixel}` 替代 |
| cellspacing (不推荐使用) | pixel\| %           | 定义了两个单元格之间空间的大小（从水平和垂直方向上），应该使用`border-spacing` 替代 |

## \<tr>

`<tr>` 标签用于定义 HTML 表格中的行。

tr 元素包含一个或多个 [`th`](https://man.ilovefishc.com/pageHTML5/th.html) 或 [`td`](https://man.ilovefishc.com/pageHTML5/td.html) 元素。

### 属性

| 属性                | 值                  | 描述                                                         |
| ------------------- | ------------------- | ------------------------------------------------------------ |
| align (不推荐使用)  | left、center、right | 每个单元格中内容的水平对齐方式，应该使用 `text-align` 替代   |
| valign (不推荐使用) | top、middle、bottom | 每个单元格中内容的垂直对齐方式，应该使用 `vertical-align` 替代 |

## \<th>

`<th>` 标签用于定义表格内的表头单元格。

th 元素内部的文本通常会呈现为居中的粗体文本

### 属性

| 属性    | 值                           | 描述                                                         |
| ------- | ---------------------------- | ------------------------------------------------------------ |
| scope   | col、colgroup、row、rowgroup | 规定表头单元格是否是行、列、行组或列组的头部。               |
| headers | header_id                    | 规定与表头单元格相关联的一个或多个表头单元格。               |
| colspan | number                       | 这个属性包含一个正整数表示了每单元格中**扩展列的数量**。默认值为`1` 。超过 1000 的值被视作 1000。 |
| rowspan | number                       | 这个属性包含一个正整数表示了每单元格中扩展列的数量。默认值为`1.` 如果该值被设置为 `0`, 这个单元格就被扩展为 (thead，tbody 或 tfoot ) 中表格部分的最后一个元素。比 65534 大的值被视作 65534 |

`colspan` 超过单元格后，会往右挤出边界，`rowspan` 同理，也是往右边平移。

![image.png](https://s2.loli.net/2022/09/20/7vabd2Qwtfqskhi.png)

## \<td>

**\<td>** : table data

### 属性

| 属性    | 值                           | 描述                                                         |
| ------- | ---------------------------- | ------------------------------------------------------------ |
| scope   | col、colgroup、row、rowgroup | 规定表头单元格是否是行、列、行组或列组的头部。               |
| headers | header_id                    | 规定与表头单元格相关联的一个或多个表头单元格。               |
| colspan | number                       | 这个属性包含一个正整数表示了每单元格中**扩展列的数量**。默认值为`1` 。超过 1000 的值被视作 1000。 |
| rowspan | number                       | 这个属性包含一个正整数表示了每单元格中扩展列的数量。默认值为`1.` 如果该值被设置为 `0`, 这个单元格就被扩展为 (thead，tbody 或 tfoot ) 中表格部分的最后一个元素。比 65534 大的值被视作 65534 |

## 表格其他封装

- \<tbody> : 定义表格主要内容的组成部分。
- \<thead> : 定义了一组定义表格的列头的行。
- \<tfoot> : 定义了一组表格中各列的汇总行

# 表单标签

## \<form>

> `<form>` 标签用于为用户输入创建 HTML 表单。用于向服务器传输数据。

表单能够包含 input 元素，比如文本字段、复选框、单选框、提交按钮等等。

表单还可以包含 menus、textarea、fieldset、legend 和 label 元素。

| 属性           | 值                                                           | 描述                                                         |
| -------------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| accept-charset | charset_list                                                 | 规定服务器可处理的表单数据字符集。                           |
| `action`       | URL                                                          | 规定当提交表单时向何处发送表单数据。                         |
| autocomplete   | on、off                                                      | 规定是否启用表单的自动完成功能。                             |
| enctype        | application/x-www-form-urlencoded、multipart/form-data、text/plain | 规定在发送表单数据之前如何对其进行编码：application/x-www-form-urlencoded在发送前编码所有字符（默认）（空格被编码为“+”，特殊字符被编码为ASCII十六进制字符）multipart/form-data 不对字符编码。在使用包含文件上传控件的表单时，必须使用该值text/plain 空格转换为 “+” 加号，但不对特殊字符编码 |
| `method`       | get、post                                                    | 规定用于发送 form-data 的 HTTP 方法。                        |
| name           | form_name                                                    | 规定表单的名称。                                             |
| novalidate     | novalidate                                                   | 如果使用该属性，则提交表单时不进行验证。                     |
| `target`       | \_blank、\_self、\_parent、\_top、framename                  | 规定在何处打开 action URL。                                  |

HTML <form> 元素，已设置所有可能的属性，是这样的：

```html
<form action="action_page.php" method="get" target="_blank" accept-charset="UTF-8"
ectype="application/x-www-form-urlencoded" autocomplete="off" novalidate>
.
form elements
 .
</form> 
```

### form 属性

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

## \<input>

*<input>* 元素是最重要的*表单元素*。

### input 属性

| 属性           | 值                                                           | 描述                                                         |
| -------------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| accept         | mime_type                                                    | 指定提交的文件类型（多个类型之间使用英文的逗号隔开，文件类型的几种表述方式请参考 -> [传送门）](https://fishc.com.cn/thread-128222-1-1.html) |
| alt            | text                                                         | 指定图像的说明文字                                           |
| autocomplete   | on、off                                                      | 指定是否启用浏览器预测输入                                   |
| autofocus      | autofocus                                                    | 指定是否自动获得焦点                                         |
| `checked`      | checked                                                      | 指定该属性的复选框，默认显示为勾选状态                       |
| `disabled`     | disabled                                                     | 指定是否禁用该 input 元素                                    |
| form           | formname                                                     | 指定其所属的一个或多个表单 id 值（在 HTML5 中，表单允许你将 input 放在文档中的任意位置，当你这么做的时候，可以通过指定该属性来确定元素所关联的表单） |
| formaction     | URL                                                          | 指定表单提交的位置（只能作用于具有提交性质的按钮，比如 type="submit" 或 type="image"） |
| formenctype    | application/x-www-form-urlencoded、multipart/form-data、text/plain | 指定表单提交的编码方式（只能作用于具有提交性质的按钮，比如 type="submit" 或 type="image"） |
| formmethod     | get、post                                                    | 指定表单提交的方法（只能作用于具有提交性质的按钮，比如 type="submit" 或 type="image"） |
| formnovalidate | formnovalidate                                               | 指定是否重置 form 元素的 novalidate 属性，如果重置，那么当表单提交时 input 元素将不再进行任何验证（只能作用于具有提交性质的按钮，比如 type="submit" 或 type="image"） |
| formtarget     | _blank、_self、_parent、_top、framename                      | 指定表单提交后在何处打开 action URL（只能作用于具有提交性质的按钮，比如 type="submit" 或 type="image"） |
| height         | pixels、%                                                    | 指定图像的高度（像素）                                       |
| list           | datalist-id                                                  | 指定一个数据列表，即 datalist 元素的 id 值                   |
| max            | number、date                                                 | 指定可接受的最大值，以便进行输入验证                         |
| maxlength      | number                                                       | 指定用户可以在文本框输入的最大字符数                         |
| min            | number、date                                                 | 指定可接受的最小值，以便进行输入验证                         |
| multiple       | multiple                                                     | 指定该属性后可以上传多个文件                                 |
| `name`         | field_name                                                   | 指定元素的名称，用于在 JavaScript 中引用元素，或者在表单提交后引用表单数据，只有设置了 name 属性的表单才能在提交表单时传递该值 |
| pattern        | regexp_pattern                                               | 指定一个用于输入验证的正则表达式                             |
| `placeholder`  | text                                                         | 指定一个占位提示文本                                         |
| `readonly`     | readonly                                                     | 将文本框设为只读模式，防止用户编辑其内容                     |
| required       | required                                                     | 表明用户必须输入一个值，否则无法通过输入验证                 |
| size           | number_of_char                                               | 指定文本框的宽度                                             |
| src            | URL                                                          | 指定要显示的图像的 URL                                       |
| step           | number                                                       | 指定上下调节数值的步长                                       |
| `type`         | button、checkbox、color、date、datetime-local、email、file、hidden、image、month、number、password、radio、range、reset、search、submit、tel、text、time、url、week | 规定 input 元素的类型                                        |
| `value`        | text                                                         | 指定输入字段的初始值                                         |
| width          | pixels、%                                                    | 指定图像的宽度（像素）                                       |

###  \<input type="text"> **文本输入**

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

**注释**：文本字段的默认宽度是 20 个字符。

- **常用属性**

```html
<!-- value: 输入字段的初始值 -->
<input type="text" value="默认有的值，(*^__^*) 嘻嘻……" />
<!-- placeholder: 占位提示文本 -->
<input type="text" placeholder="请输入您的姓名"/>
```

### \<input type="password"> 密码输入

`<input type="password">` 定义用于**密码输入**的单行输入字段：

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

- **常用属性**

```html
<!-- placeholder: 占位提示文本 -->
<input type="password" placeholder="请输入密码"/>
```

### \<input type="radio"> **单选按钮输入**

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

**注意：** 要起到单选的作用，同类标签的 name 属性必须保持一致。

### \<input type="checkbox"> 复选框

`<input type="checkbox">`  定义**复选框**。

复选框允许用户在有限数量的选项中选择零个或多个选项。

```html
<form>
    <input type="checkbox" name="vehicle" value="Bike">I have a bike
    <br>
    <input type="checkbox" name="vehicle" value="Car">I have a car 
</form> 
```

![image-20220814182358177](https://s2.loli.net/2022/08/14/mQyx2F531MuNrPe.png)

### \<input type="submit"> **提交按钮**

`<input type="submit">`  定义用于向 **表单处理程序**（form-handler）提交表单的按钮。

`<input type="submit">` 和 `<button type="submit"></button>` 等价。

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

**注意：** 提交按钮显示的字段为标签的value属性。

### \<input type="button> 单纯按钮

`<input type="button>` 定义*按钮*。

```html
<form>
    <input type="button" onclick="alert('Hello World!')" value="Click Me!">
</form> 
```

### \<input type="reset" > 重置按钮

`<input type="reset" />` 定义重置按钮

等价于 `<button type="reset"></button>`

### \<input type="file"> **提交文件**

`<input type="file" name="" id="" />`

### \<input type="image" > **图片按钮**

`<input type="image" src="" alt="" />` 图片代替提交按钮

### \<input type="hidden"> **隐藏按钮**

`<input type="hidden" name="" id="" value="带给后端的个人信息"/>`

## \<select> 元素（下拉列表）

### 属性

- **select 属性**

| 属性       | 值        | 描述                                 |
| ---------- | --------- | ------------------------------------ |
| autofocus  | autofocus | 指定在页面加载后文本区域自动获得焦点 |
| disabled   | disabled  | 指定该下拉列表被禁用                 |
| form       | form_id   | 指定所属表单                         |
| `multiple` | multiple  | 指定该下拉列表支持多个选项           |
| name       | name      | 指定该下拉列表的名称                 |
| required   |           | 指定文本区域是必填的                 |
| `size`     | number    | 指定下拉列表中可见选项的数目         |

```html
<select size="3" multiple name="省份" id=""></select>
```

- **option 属性**

| 属性       | 值       | 描述                           |
| ---------- | -------- | ------------------------------ |
| disabled   | disabled | 指定该选项被禁用               |
| label      | text     | 指定该选项在列表中所显示的标签 |
| `selected` | selected | 指定该选项表现为选中状态       |
| `value`    | text     | 指定发到服务器的选项值         |

### 实例

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

## \<textarea> 元素

### 定义

> `<textarea>` 标签定义多行的文本输入控件。

文本区中可容纳无限数量的字符，其中的文本的默认字体是等宽字体（通常是 Courier）。

可以通过 cols 和 rows 属性来规定 textarea 的尺寸，不过更好的办法是使用 CSS 的 height 和 width 属性。

### 属性

| 属性          | 值               | 描述                                                         |
| ------------- | ---------------- | ------------------------------------------------------------ |
| autofocus     | autofocus        | 指定在页面加载后文本区域自动获得焦点                         |
| cols          | number           | 指定文本区域的可见宽度；值为字符数                           |
| disabled      | disabled         | 禁用该文本区域                                               |
| form          | form_id          | 指定文本区域所属的一个或多个表单                             |
| maxlength     | number           | 指定文本区域的最大字符数                                     |
| name          | name_of_textarea | 指定文本区域的名称                                           |
| `placeholder` | text             | 指定文本区域的占位提示文本                                   |
| readonly      | readonly         | 指定文本区为只读                                             |
| required      | required         | 指定文本区域为必填项                                         |
| rows          | number           | 指定文本区内的可见行数；可以理解为初始高度                   |
| wrap          | hard、soft、off  | 指定在表单提交时，如何处理文本区域的自动换行：soft 表示在页面渲染中对文本进行自动换行，但换行符（CR + LF）不提交hard 表示在页面渲染中对文本进行自动换行，换行符（CR + LF）也会一并提交。如果元素的该属性设置为 hard，则必须同时指定 cols 属性。off 表示在页面渲染中不对文本进行自动换行。 |

CSS 设置属性：`resize: vertiacl | horizontal | both | none;`

### 实例

`<textarea>` 元素定义多行输入字段（**文本域**）：

```html
<textarea name="message" rows="10" cols="30">
The cat was playing in the garden.
</textarea>
```

![image-20220814160957790](https://s2.loli.net/2022/08/14/IbmJNGH1wj5VcZg.png)

## \<fieldset>字段集

`<fieldset>` 标签将表单内容的一部分打包，生成一组相关表单的字段。

当一组表单元素放到 `<fieldset>` 标签内时，浏览器会以特殊方式来显示它们，它们可能有特殊的边界、3D 效果，或者甚至可创建一个子表单来处理这些元素。

`<legend>` 标签用于为 [fieldset](https://man.ilovefishc.com/pageHTML5/fieldset.html) 元素定义说明文字。

注意：legend 元素必须是 [fieldset](https://man.ilovefishc.com/pageHTML5/fieldset.html) 元素的第一个子元素。

### 属性

| 属性     | 值       | 描述                        |
| -------- | -------- | --------------------------- |
| disabled | disabled | 禁用 fieldset               |
| form     | form_id  | 指定 fieldset 所属的表单 ID |
| name     | value    | 指定 fieldset 的名称        |

### 实例

```html
<fieldset>
    <legend>性别</legend>
</fieldset>
```

## \<button>

`<button>` 元素定义可点击的*按钮*：

使用 input 元素也可以设置成按钮的样式，但是在 button 元素的内部，你可以放置文本或图像，而 input 元素则不行。

请始终为 button 元素设置 type 属性，因为不同的浏览器为其指定的默认值可能不同。

| 属性           | 值                                                           | 描述                                                         |
| -------------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| autofocus      | autofocus                                                    | 指定当页面加载的时候，按钮将获得焦点。                       |
| disabled       | disabled                                                     | 禁用按钮。                                                   |
| form           | form_id                                                      | 指定按钮所关联的表单 ID。                                    |
| formaction     | url                                                          | 覆盖 form 元素的 action 属性。注释：该属性与 type="submit" 配合使用。 |
| formenctype    | application/x-www-form-urlencoded、multipart/form-data、text/plain | 覆盖 form 元素的 enctype 属性。注释：该属性与 type="submit" 配合使用。 |
| formmethod     | get、post                                                    | 覆盖 form 元素的 method 属性。注释：该属性与 type="submit" 配合使用。 |
| formnovalidate | formnovalidate                                               | 覆盖 form 元素的 novalidate 属性。注释：该属性与 type="submit" 配合使用。 |
| formtarget     | _blank、_self、_parent、_top、framename                      | 覆盖 form 元素的 target 属性。注释：该属性与 type="submit" 配合使用。 |
| name           | button_name                                                  | 指定按钮的名称。                                             |
| type           | button、reset、submit                                        | 指定按钮的类型。                                             |
| value          | text                                                         | 指定按钮的初始值。注释：可由脚本进行修改。                   |

```html
<button type="button" onclick="alert('Hello World!')">Click Me!</button>
```

![image-20220814161055407](https://s2.loli.net/2022/08/14/MsZ4J6HIEruo18B.png)

# HTML5 标签 \*\*\*\*\*\*\*\*\*\*

# 新增语义化标签

| 标签    | 含义                                                         |
| ------- | ------------------------------------------------------------ |
| article | 定义一篇文章，与页面其它部分无关。                           |
| aside   | 定义侧边栏，通常是网页的说明、提示、引用、附加注释、相关链接、广告等内容。 |
| footer  | 定义文档或节的页脚。                                         |
| header  | 定义文档的页眉（介绍信息）。                                 |
| main    | 定义文档\<body>或应用的主体部分。                            |
| nav     | 定义页面主导航功能。                                         |
| section | 定义定义文档中的节。                                         |

# 新增音频标签

## audio

> `<audio>` 标签定义声音，比如音乐或其他音频流。

| 属性       | 值                   | 说明                                                         |
| ---------- | -------------------- | ------------------------------------------------------------ |
| autoplay   | autoplay             | 如果指定该属性，则音频在就绪后马上播放。(Chrome默认禁止)     |
| `controls` | controls             | 如果指定该属性，则向用户显示播放控件（比如播放/暂停按钮）。  |
| loop       | loop                 | 如果指定该属性，将循环播放音频。                             |
| muted      | muted                | 如果指定该属性，则音频输出为静音。                           |
| preload    | auto、metadata、none | 指定音频在页面加载时，是否进行预加载。注意：如果同时指定了 autoplay 属性，则忽略该属性。 auto：要求浏览器尽快加载整个音频，默认行为 metadata：只加载音频的元数据 none：在用户点击开始播放之前不会加载音频 |
| src        | URL                  | 指定要播放的音频文件的 URL 地址。                            |

## video

> \<video> 标签定义视频，比如电影片段或其他视频流。

| 属性     | 值                   | 说明                                                         |
| -------- | -------------------- | ------------------------------------------------------------ |
| autoplay | autoplay             | 如果指定该属性，则视频在就绪后将自动播放。                   |
| controls | controls             | 如果指定该属性，则向用户显示控件，比如播放/暂停按钮。        |
| height   | pixels               | 指定视频播放器的高度。                                       |
| loop     | loop                 | 如果指定该属性，将循环播放视频。                             |
| muted    | muted                | 如果指定该属性，则将视频的音频输出为静音。                   |
| `poster` | URL                  | 指定视频正在下载时显示的图像。                               |
| preload  | auto、metadata、none | 指定视频在页面加载时，是否进行预加载。注意：如果同时指定了 autoplay 属性，则忽略该属性。 auto：要求浏览器尽快加载整个视频，默认行为 metadata：只加载视频的元数据（宽度、高度、第一帧影像和视频总长度等） none：在用户点击开始播放之前不会加载视频 |
| src      | URL                  | 指定要播放的视频文件的 URL 地址。                            |
| width    | pixels               | 指定视频播放器的宽度。                                       |

# HTML5 增强表单元素

HTML5 增加了如下表单元素：

```html
- <datalist> 

- <keygen> 

- <output> 
```

**注释**：默认地，浏览器不会显示未知元素。新元素不会破坏您的页面。

##  \<datalist> 元素

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

# HTML5 新增表单属性

| 属性      | 说明                              |
| --------- | --------------------------------- |
| autofocus | 自动获得焦点，一个页面只能有一个  |
| required  | 必填项                            |
| multiple  | email，允许填入多个邮箱，逗号隔开 |
| pattern   | 正则表达式                        |

```python
pattern = "[0-9][A-Z]{3}" 
# 代表一个数与三个大写字母
```

# Frames

## \<iframe>

`<iframe>` 标签会创建包含另外一个文档的内联框架（即行内框架）。

| 属性       | 值                                                           | 描述                                                         |
| ---------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| **height** | pixels、%                                                    | 指定 iframe 的高度。                                         |
| name       | text                                                         | 指定 iframe 的名称。                                         |
| sandbox    | allow-forms、allow-pointer-lock、allow-popups、allow-same-origin、allow-scripts、allow-top-navigation | 启用一系列对 `<iframe>`中内容的额外限制。                    |
| seamless   | seamless                                                     | 指示浏览器将 iframe 的内容显示得像主 HTML 文档的一个整体组成部分。 |
| **src**    | URL                                                          | 指定在 iframe 中显示的文档的 URL 地址。                      |
| srcdoc     | HTML_code                                                    | 指定在 `<iframe>` 中显示的页面的 HTML 内容。                 |
| **width**  | pixels、%                                                    | 指定 iframe 的宽度。                                         |

```html
<body>
    <iframe src="https://jacob-xyb.github.io/" width="1600px" height="800px" frameborder="0">不支持iframe</iframe>
</body>
```

# 属性

## HTML 提示：使用小写属性

属性和属性值对大小写不敏感。

不过，万维网联盟在其 HTML 4 推荐标准中推荐小写的属性/属性值。

而新版本的 (X)HTML 要求使用小写属性。

**注意：** 大写属性 在JS使用时会在大写前自动添加 `-` 连接符，所以非常不推荐在属性中出现大写字母，推荐用 `_` 下划线分割。

## HTML 全局属性

| 属性                                                         | 描述                                                       |
| ------------------------------------------------------------ | ---------------------------------------------------------- |
| [accesskey](https://www.runoob.com/tags/att-global-accesskey.html) | 设置访问元素的键盘快捷键。                                 |
| [class](https://www.runoob.com/tags/att-global-class.html)   | 规定元素的类名（classname）                                |
| [contenteditable](https://www.runoob.com/tags/att-global-contenteditable.html)**New** | 规定是否可编辑元素的内容。                                 |
| [contextmenu](https://www.runoob.com/tags/att-global-contextmenu.html)**New** | 指定一个元素的上下文菜单。当用户右击该元素，出现上下文菜单 |
| [data-*](https://www.runoob.com/tags/att-global-data.html) **New** | 用于存储页面的自定义数据                                   |
| [dir](https://www.runoob.com/tags/att-global-dir.html)       | 设置元素中内容的文本方向。                                 |
| [draggable](https://www.runoob.com/tags/att-global-draggable.html)**New** | 指定某个元素是否可以拖动                                   |
| [dropzone](https://www.runoob.com/tags/att-global-dropzone.html)**New** | 指定是否将数据复制，移动，或链接，或删除                   |
| [hidden](https://www.runoob.com/tags/att-global-hidden.html)**New** | hidden 属性规定对元素进行隐藏。                            |
| [id](https://www.runoob.com/tags/att-global-id.html)         | 规定元素的唯一 id                                          |
| [lang](https://www.runoob.com/tags/att-global-lang.html)     | 设置元素中内容的语言代码。                                 |
| [spellcheck](https://www.runoob.com/tags/att-global-spellcheck.html)**New** | 检测元素是否拼写错误                                       |
| [style](https://www.runoob.com/tags/att-global-style.html)   | 规定元素的行内样式（inline style）                         |
| [tabindex](https://www.runoob.com/tags/att-global-tabindex.html) | 设置元素的 Tab 键控制次序。                                |
| [title](https://www.runoob.com/tags/att-global-title.html)   | 规定元素的额外信息（可在工具提示中显示）                   |
| [translate](https://www.runoob.com/tags/att-global-translate.html)**New** | 指定是否一个元素的值在页面载入时是否需要翻译               |
