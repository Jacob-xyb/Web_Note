# 请问 \<!DOCTYPE html> 标签是干啥用的呢？

## Question

请问 <!DOCTYPE html> 标签是干啥用的呢？

## My Answer

声明这是一个 html 文件。

## Official Answer

`<!DOCTYPE html>` 标签可以告诉浏览器你的 HTML 文档是基于哪一个标准进行开发的（在这里，<!DOCTYPE html> 表示该文档是基于 HTML5 的标准进行开发）。通过使用 DOCTYPE，浏览器就能够更准确地选择用什么方式来解释和展现你的网页。另外要记住，DOCTYPE 定义需要放在 HTML 文档的最开头位置！

# head 元素中必须要有的元素是？

## Question

head 元素中必须要有的元素是？

## My Answer

<meta charset="utf-8">

## Official Answer

head 元素中必须要有一个 title 元素。

# 通常，在网页中可见的内容是包含于哪个标签中？

## Question

通常，在网页中可见的内容是包含于哪个标签中？

## My Answer

<body> </body>

## Official Answer

<body> 标签

# 请写出下图中 A、B、C、D 的名称。

## Question

请写出下图中 A、B、C、D 的名称。

![](https://xxx.ilovefishc.com/forum/201803/26/175826shu2iihtrb2fbr3i.png)

## My Answer

A: 属性：链接地址

B：URL地址

C：悬停在链接上显示的文字

D： a 标签主体

## Official Answer

A -> href 属性；B -> href 的属性值；C -> a 元素的内容；D -> a 元素

# 请问下面代码存在什么问题？

## Question

请问下面代码存在什么问题？（共有 6 处错误）

```
<DOCTYPE html5>
<html>
<head>
    <title>第一个程序</title>
</head>
<body>
    <h1>Hello</h1>
    <img src='img/FishC.png"alt="鱼C-Logo" width="256px" height="256px">
    <a href="http://bbs.fishc.com" target="blank">学习中遇到不会的问题，可以在鱼C论坛提问哦~</a>
    <p>I <h3>love</h3> FishC.com!</p>
</body>
</html>
```

## My Answer

1. Line 1: `<!DOCTYPE html>`
2. head 标签缺少 `<meta charset="utf-8">`
3. Line 8: `src='img/FishC.png"` 引号不匹配
4. Line 10: p 包含了 h3，h3 应该用 span

## Official Answer

1. Line1: `<!DOCTYPE html>`

   - 这回 W3C 是动真格的了，他们下定决心要将 HTML5 的标准一统天下。换句话说，doctype 以后不会再变了，无论是发展到 HTML6，还是 HTML18，永远只需要在文档的开头写上 <!DOCTYPE html> 就可以了。
   -  还有，DOCTYPE 前面的感叹号不要忘了~
2. Line8: `<img src="img/FishC.png" alt="鱼C-Logo" width="256px" height="256px">`
   - 多个属性间应该使用至少一个空格分隔。
   - 可以使用成对的单引号或双引号将属性值包裹起来，但绝对不能混用。
3. Line9: `<a href="http://bbs.fishc.com" target="_blank">学习中遇到不会的问题，可以在鱼C论坛提问哦~</a>`
   - 注意 _blank 前面是有下划线的。
4. Line10: `<p>I love FishC.com!</p>`
   - 这属于标题标签的滥用，<h1>~<h6> 标签永远只用于表示标题的层级关系。

# Title

## Question

## My Answer

## Official Answer