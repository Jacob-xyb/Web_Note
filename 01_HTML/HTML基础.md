# HTML 5

超文本标记语言（英语：HyperText Markup Language，简称：HTML）是一种用于创建网页的标准标记语言。

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

# HTML 基础

## HTML 标题

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

## HTML 段落

HTML 段落是通过标签 <p> 来定义的。

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

```html
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>Jacob-xyb</title>
</head>
<body>

<img src="./images/github_logo.png"/>

</body>
</html>
```

**注意：** 图像的名称和尺寸是以属性的形式提供的。

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