# CSS

## CSS 概述

- CSS 指层叠样式表 (**C**ascading **S**tyle **S**heets) 
- 样式定义**如何显示** HTML 元素 
- 样式通常存储在**样式表**中 
- 把样式添加到 HTML 4.0 中，是为了*解决内容与表现分离的问题* 
- **外部样式表**可以极大提高工作效率 
- 外部样式表通常存储在 **CSS 文件**中 
- 多个样式定义可*层叠*为一 

## 样式解决了一个普遍的问题

HTML 标签原本被设计为用于定义文档内容。通过使用 <h1>、<p>、<table> 这样的标签，HTML 的初衷是表达“这是标题”、“这是段落”、“这是表格”之类的信息。同时文档布局由浏览器来完成，而不使用任何的格式化标签。

由于两种主要的浏览器（Netscape 和 Internet Explorer）不断地将新的 HTML 标签和属性（比如字体标签和颜色属性）添加到 HTML 规范中，创建文档内容清晰地独立于文档表现层的站点变得越来越困难。

为了解决这个问题，万维网联盟（W3C），这个非营利的标准化联盟，肩负起了 HTML 标准化的使命，并在 HTML 4.0 之外创造出样式（Style）。

所有的主流浏览器均支持层叠样式表。

## 样式表极大地提高了工作效率

样式表定义如何显示 HTML 元素，就像 HTML 3.2 的字体标签和颜色属性所起的作用那样。样式通常保存在外部的 .css 文件中。通过仅仅编辑一个简单的 CSS 文档，外部样式表使你有能力同时改变站点中所有页面的布局和外观。

由于允许同时控制多重页面的样式和布局，CSS 可以称得上 WEB 设计领域的一个突破。作为网站开发者，你能够为每个 HTML 元素定义样式，并将之应用于你希望的任意多的页面中。如需进行全局的更新，只需简单地改变样式，然后网站中的所有元素均会自动地更新。

## 多重样式将层叠为一个

样式表允许以多种方式规定样式信息。样式可以规定在单个的 HTML 元素中，在 HTML 页的头元素中，或在一个外部的 CSS 文件中。甚至可以在同一个 HTML 文档内部引用多个外部样式表。

层叠次序
当同一个 HTML 元素被不止一个样式定义时，会使用哪个样式呢？

一般而言，所有的样式会根据下面的规则层叠于一个新的虚拟样式表中，其中**数字 4 拥有最高的优先权**。

1. 浏览器缺省设置 
2. 外部样式表 
3. 内部样式表（位于 <head> 标签内部） 
4. 内联样式（在 HTML 元素内部） 

因此，内联样式（在 HTML 元素内部）拥有最高的优先权，这意味着它将优先于以下的样式声明：<head> 标签中的样式声明，外部样式表中的样式声明，或者浏览器中的样式声明（缺省值）。

## CSS 显示方式

1. **内联样式（Inline Style）**

   `<div style="width:200px; height:200px;"></div>`

2. **内部样式表（Internal Style Sheet）**

3. **外部样式表（External Style Sheet）**：HTML5 推荐用法

   `<link rel="stylesheet" type="text/css" href="" >` 

## CSS 优先级

外部 < 内部 < 内联；

但是 `!important` 加在样式后可以提高优先级：

语法：`color: red !important;`

# CSS 基础语法

## CSS 语法

CSS 规则由两个主要的部分构成：选择器，以及一条或多条声明。

```css
selector {declaration1; declaration2; ... declarationN }
```

选择器通常是您需要改变样式的 HTML 元素。

每条声明由一个属性和一个值组成。

属性（property）是您希望设置的样式属性（style attribute）。每个属性有一个值。属性和值被冒号分开。

```css
selector {property: value}
```

下面这行代码的作用是将 h1 元素内的文字颜色定义为红色，同时将字体大小设置为 14 像素。

在这个例子中，h1 是选择器，color 和 font-size 是属性，red 和 14px 是值。

```css
h1 {
	color:red; 
	font-size:14px;
	}
```

## 值的不同写法和单位

除了英文单词 red，我们还可以使用十六进制的颜色值 #ff0000：

为了节约字节，我们可以使用 CSS 的缩写形式：

```css
p { color: #f00; }
```

我们还可以通过两种方法使用 RGB 值：

```css
p { color: rgb(255,0,0); }
p { color: rgb(100%,0%,0%); }
```

请注意，当使用 RGB 百分比时，即使当值为 0 时也要写百分比符号。但是在其他的情况下就不需要这么做了。比如说，当尺寸为 0 像素时，0 之后不需要使用  px 单位，因为 0 就是 0，无论单位是什么。

## 记得写引号

提示：如果值为若干单词，则要给值加引号：

```html
p {font-family: "sans serif";}
```

# 基础选择器

## 元素选择器

element选择器可以设定某元素的样式。

```css
element
{    
    CSS 样式
}
```

## id选择器

id 选择器是唯一的，在一个页面，id不能重复，`#id` 表述

```css
#id
{
    CSS 样式
}
```

## 类选择器

类选择器允许以一种独立于文档元素的方式来指定样式。

- **class属性可以在HTML文档中出现多次。只有适当地标记文档后，才能使用这些选择器，该选择器可以单独使用，也可以与其他元素结合使用，`.class` 表述**

- **同一个标签可以同时属于多个类: `<class='class1 class2'>`**

* `<class='class1' class='class2'>` 是错误的！同一个标签不能同时拥有重复的属性

```css
.class
{
    CSS 样式
}
```

不要用一个类表示过多的属性，合理的做法是用提供 ”公共类“ ，比如 绿、线等。

**class上样式，id上行为**

## 通配符*

`*` 表示所有元素

```css
* {}	/*代表所有元素，不建议使用*/
```

常用场景：

```css
body * {}	/*元素的所有后代*/
```

# 复合选择器

复合选择器是由两个或多个基础选择器通过不同的方式进行组合

## 交集选择器

```css
element.class || element#id
{
    CSS 样式;
}
```

交集选择器没有空格

例如：

```css
div.red	/*代表是div 又是.red*/
div .red /*表达 div 后代中所有 .red */
```

## 并集选择器

```css
h3,li	/*代表并集选择器*/
```

## 后代选择器

**后代选择器（descendant selector）又称为包含选择器。**

```css
选择器1 选择器2 ...{
    CSS 样式;
}
```

从左往右的所有匹配的后代元素

**但是底层原理是从右向左查找元素**

## 子元素选择器

子元素选择器，选择 选择器1 元素中符合直接子元素的 选择器2 元素

```css
选择器1 > 选择器2 {
    CSS 样式;
}
```

- **如果元素不是父元素的直接子元素，则不会被选择。**

## 相邻元素选择器

选择具有相同父元素且同级的element1相邻的element2

```css
element1 + element2 {
    CSS 样式;
}
```

## 通用兄弟选择器

通用兄弟选择器，选择具有相同父元素且同级的element1之后的element2

- **两种元素必须拥有相同的父元素，但是 element2 不必直接紧随 element1。**

```css
element1 ~ element2 {
    CSS 样式;
}
```

# 伪类选择器

## 动态伪类选择器

动态选择器的设置是有前后顺序的：link -> visited -> hover -> active

爱恨法则：`l`o`v`e ` ha`te

### :link

:link 选择器用于选取未被访问的链接。

**注意：**:link 选择器不会设置已经访问过的链接的样式。

请使用[`:hover`](https://man.ilovefishc.com/pageCSS3/dothover.html)选择器用于设置鼠标指针浮动到链接上时的样式，[`:visited`](https://man.ilovefishc.com/pageCSS3/dotvisited.html)用于设置指向已访问页面的链接的样式，[`:active `](https://man.ilovefishc.com/pageCSS3/dotActive.html)选择器用于活动链接。

### :visited

### :hover

### :active

判断激活的标准是鼠标点击，p标签也可以被激活

### :focus

:focus 选择器用于选取获得焦点的元素。

## UI伪类选择器

### :enabled

### :disabled

### :checked

### :required

### :optional

### :default

:default选择器用于表示默认状态的按钮（`<input type="button">`），radio(`<input type="radio">`), checkbox (`<input type="checkbox">`) 或select元素中的option HTML元素(“option”)。

```html
<style>
    input:default {
        box-shadow: 0 0 1px 1px green;
    }
</style>
...
<body>
<form action="">
    <input type="radio" value="fake" name="same" /> 小田鱼<br>
    <input type="radio" value="star" checked="checked" name="same" /> 小甲鱼<br>
    <input type="checkbox" checked="checked" value="Bike"/> 我爱C语言<br>
    <input type="checkbox" value="Car"/> 我爱Web
</form>
</body>
```

![image-20220908112329502](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220908112329502.png)

### :valid

### invalid

### :in-range

### :out-of-range

### :read-only

### :read-write

### :indeterminate

## 结构伪类选择器

### :root

### :nth-child

- 定义

> :nth-child(n) 选择器匹配属于其父元素的第 n 个子元素，不论元素的类型。

**注意：**n 可以是数字、关键词或公式。

- 语法

```
:nth-child(number)
{
    CSS 样式
}
```

- 基础n

`:nth-child(n)`：选中某个元素，该元素必须是**某个父元素**下的第n个子元素；

`p:nth-child(n)` ：选中p元素，且该p元素必须是某个父元素下的第n个子元素

**注意：**n是从**1**开始的。

如下代码：

```css
p:nth-child(1)
```

只会选中第二个div中第一个子元素p，例如：

```html
<!DOCTYPE html>
<html>
<head>
    <meta charset="UTF-8">
    <title>鱼C-零基础入门学习Web（Html5+Css3）</title>
    <style>
        p:nth-child(1)
        {
            color:green;
        }
    </style>
</head>
<body>
   <div style="border:1px solid;width: 222px">
       <span>div1 中span</span>
       <p>div1 中第一个段落。</p>
       <p>div1 中的最后一个段落。</p>
   </div><br>
   <div style="border:1px solid;width: 222px">
       <p>div2 中第一个段落。</p>
       <p>div2 中的最后一个段落。</p>
   </div>
</body>
</html>
```

- 正方向范围

  ```css
  li:nth-child(n+6)
  ```

  选中从第6个开始的子元素

- 负方向范围

  ```css
  :nth-child(-n+9)
  ```

  选中从第1个到第9个子元素。使用 :nth-child(-n+9) ，就相当让你选中第9个和其之前的所有子元素

- 前后限制范围

  ```css
  :nth-child(n+4):nth-child(-n+8)
  ```

- 奇数、偶数位

  ```css
  /*奇数*/
  :nth-child(odd)
  
  /*偶数*/
  :nth-child(even)
  ```
  
- 隔选择子元素
  
  ```css
  :nth-child(3n+1)
  ```
  
  选择1,4,7,10
  
- 范围法
  
  ```css
  nth-child(n+2):nth-child(odd):nth-child(-n+9)
  ```
  
  使用 nth-child(n+2):nth-child(odd):nth-child(-n+9) ，将会选中的子元素是从第2位到第9位，并且只包含奇数位。

### :nth-last-child

### :nth-of-type

### :nth-last-of-type

### :first-child

### :last-child

### :first-of-type

### :last-of-type

### :only-child

### only-of-type

### :empty

## 其他伪类选择器

### :target

:target 选择器可用于选取当前活动的目标元素。

**注意：**URL 带有后面跟有锚名称 #，指向文档内某个具体的元素。这个被链接的元素就是目标元素(target element)。

```css
<style>
:target
{
    border: 2px solid #D4D4D4;
    background-color: #e5eecc;
}
</style>
...
<body>
   <h1>这是标题</h1>
   <p><a href="#fishc1">跳转至内容 1</a></p>
   <p><a href="#fishc2">跳转至内容 2</a></p>
   <p><a href="#fishc3">跳转至内容 3</a></p>
   <p>请点击上面的链接，:target 选择器会突出显示当前活动的 HTML 锚。</p>
   <p id="fishc1"><b>内容 1...</b></p>
   <p id="fishc2"><b>内容 2...</b></p>
   <p id="fishc3"><b>内容 3...</b></p>
</body>
```

### :lang

### :not

# 伪元素选择器

## ::first-line

`::first-line` 选择器用于选取指定选择器的首行。

**注意：**以下属性可与 `::first-line` 使用：字体属性、颜色属性、背景属性、word-spacing、letter-spacing、text-decoration、vertical-align、text-transform、line-height、clear

只对块级元素生效，但是例如 a 标签设置为块元素后，就依然生效。

## ::first-letter

::first-letter 选择器用于选取指定选择器的首字母。

**注意：**以下属性可与 `::first-letter` 使用：字体属性、颜色属性、背景属性、外边距属性、内边距属性、边框属性、text-decoration、vertical-align（只有在 float 为 ‘none’ 时）、text-transform、line-height、float、clear

## ::before

::before 选择器在被选元素的内容前面插入内容。

**注意：**请使用 **content** 属性来指定要插入的内容。

```css
p::before
{
    content:"鱼C - ";
}
```

## ::after

::after 选择器在被选元素的内容后面插入内容。

**注意：**请使用 **content** 属性来指定要插入的内容。

```css
p::after
{
    content:"- emm.";
}
```

## ::selection

::selection 选匹配元素中被用户选中或处于高亮状态的部分。

**注意：**只能向 ::selection 选择器应用少量 CSS 属性：color、background、cursor 以及 outline。

# 属性选择器

## [attribute]

[attribute] 选择器用于选取带有指定属性的元素。

```css
<style>
a[target]
{
    background-color:green;
}
</style>
...
<body>
   <p>带有 target 属性的链接会得到绿色背景：</p>
   <a href="http://www.fishc.com" target="_blank">鱼C工作室</a>
   <a href="http://bbs.fishc.com/forum.php">鱼C论坛</a>
</body>
```

## [attribute=value]

[attribute=value]选择器用于选择带有指定值属性的元素

```css
form input[type='text'] {}
```

## [attribute~=value]

[attribute~=value] 选择器用于选取属性值中包含指定词汇的元素。 **`包含不是匹配`**

## [attribute^=value]

[attribute^=value] 选择器匹配属性值中且以value开头的元素

## [attribute$=value]

[attribute$=value] 选择器用于选取属性值中且以value结尾的元素。

## [attribute*=value]

[attribute*=value] 选择器匹配属性值包含指定值的每个元素。

## [attribute|=value]

[attribute|=value] 选择器用于选取带有以指定值开头的属性值的元素。

**注意：**该值必须是整个单词，比如 lang=”en”，或者**后面跟着 `连字符` **，比如 lang=”en-us”。

支持自定义属性

# 选择器权重

`!important > 内联样式 > id > class > element`

其中 `包含选择器` 为包含的权重之和

相同权重的选择符，样式遵循就近原则，哪个选择符最后定义，就采用哪个选择符样式。

# 文本属性

## font-size

font-size 属性可设置字体的尺寸。

**注意：**该属性设置元素的字体大小。注意，实际上它设置的是字体中字符框的高度；实际的字符字形可能比这些框高或矮（通常会矮）。
各关键字对应的字体必须比一个最小关键字相应字体要高，并且要小于下一个最大关键字对应的字体。

语法：` font-size:A|smaller|larger|length|%|inherit`

| 值                                                           | 说明 （索引中有详细介绍）                                    |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| A(xx-small、x-small、small、medium、large、x-large、xx-large) | 把字体的尺寸设置为不同的尺寸，从 xx-small 到 xx-large。默认值：medium。 |
| smaller                                                      | 把 font-size 设置为比父元素更小的尺寸。                      |
| larger                                                       | 把 font-size 设置为比父元素更大的尺寸。                      |
| length                                                       | 把 font-size 设置为一个固定的值。                            |
| %                                                            | 把 font-size 设置为基于父元素的一个百分比值。                |
| inherit                                                      | 定应该从父元素继承字体系列。                                 |

## font-family

> font-family 规定元素的字体系列。

font-family 可以把多个字体名称作为一个“`回退`”系统来保存。如果浏览器不支持第一个字体，则会尝试下一个。
也就是说，font-family 属性的值是用于某个元素的字体族名称或/及类族名称的一个优先表。浏览器会使用它可识别的第一个值。

有两种字体系列名称：

| 类型     | 说明                                           |
| -------- | ---------------------------------------------- |
| 字体系列 | 特定的字体系列（如Times New Roman或Arial）     |
| 通用族   | 一组具有相似外观的字体族（如Serif或Monospace） |

![image.png](https://s2.loli.net/2022/09/21/RwGHmUEQ91xFhDo.png)

常用：

```html
"Arial","Microsoft YaHei","黑体","宋体",sans-serif;
```

## color

## font-weight

> font-weight 属性设置文本的粗细。

**注意：**该属性用于设置显示元素的文本中所用的字体加粗。数字值 400 相当于 关键字 normal，700 等价于 bold，数字只能取100到900间的整百。

| 值                                          | 说明 （索引中有详细介绍）                                   |
| ------------------------------------------- | ----------------------------------------------------------- |
| normal                                      | 默认值。定义标准的字符。                                    |
| bold                                        | 定义粗体字符。                                              |
| bolder                                      | 定义更粗的字符。                                            |
| lighter                                     | 定义更细的字符。                                            |
| 100、200、300、400、500、600、700、800、900 | 定义由粗到细的字符。400 等同于 normal，而 700 等同于 bold。 |
| inherit                                     | 规定应该从父元素继承字体的粗细。                            |

## font-style

> font-style 属性定义字体的风格。

**注意：**该属性设置使用斜体、倾斜或正常字体。斜体字体通常定义为字体系列中的一个单独的字体。理论上讲，用户代理可以根据正常字体计算一个斜体字体。

| 值      | 说明 （索引中有详细介绍）              |
| ------- | -------------------------------------- |
| normal  | 默认值。浏览器显示一个标准的字体样式。 |
| italic  | 浏览器会显示一个斜体的字体样式。       |
| oblique | 浏览器会显示一个倾斜的字体样式。       |
| inherit | 规定应该从父元素继承字体样式。         |

## text-align

> text-align 属性规定元素中的文本的水平对齐方式。

**注意：**该属性通过指定行框与哪个点对齐，从而设置块级元素内文本的水平对齐方式。通过允许用户代理调整行内容中字母和字之间的间隔，可以支持值 justify；不同用户代理可能会得到不同的结果。

| 值      | 描述                                       |
| ------- | ------------------------------------------ |
| left    | 把文本排列到左边。默认值：由浏览器决定。   |
| right   | 把文本排列到右边。                         |
| center  | 把文本排列到中间。                         |
| justify | 实现两端对齐文本效果。                     |
| inherit | 规定应该从父元素继承 text-align 属性的值。 |

## line-height

> line-height 属性设置行间的距离（行高）。

**注意：**该属性会影响行框的布局。在应用到一个块级元素时，它定义了该元素中基线之间的最小距离而不是最大距离。

不允许使用负值。

- 属性值

| 值      | 描述                                                 |
| ------- | ---------------------------------------------------- |
| normal  | 默认。设置合理的行间距。                             |
| number  | 设置数字，此数字会与当前的字体尺寸相乘来设置行间距。 |
| length  | 设置固定的行间距。                                   |
| %       | 基于当前字体尺寸的百分比行间距。                     |
| inherit | 规定应该从父元素继承 line-height 属性的值。          |

## text-indent

> text-indent 属性规定文本块中首行文本的缩进。

**注意：**负值是允许的。如果值是负数，将第一行左缩进。

- 属性值

| 值      | 描述                                        |
| ------- | ------------------------------------------- |
| length  | 定义固定的缩进。默认值：0。                 |
| %       | 定义基于父元素宽度的百分比的缩进。          |
| inherit | 规定应该从父元素继承 text-indent 属性的值。 |

## letter-spacing

> letter-spacing 属性增加或减少字符间的空白（字符间距）。

**注意：**该属性定义了在文本字符框之间插入多少空间。由于字符字形通常比其字符框要窄，指定长度值时，会调整字母之间通常的间隔。因此，normal 就相当于值为 0。

允许使用负值，这会让字母之间挤得更紧。

- 属性值

| 值      | 描述                                           |
| ------- | ---------------------------------------------- |
| normal  | 默认。规定字符间没有额外的空间。               |
| length  | 定义字符间的固定空间（允许使用负值）。         |
| inherit | 规定应该从父元素继承 letter-spacing 属性的值。 |

## word-spacing

> word-spacing属性增加或减少字与字之间的空白。

**注意：**针对这个属性，“字” 定义为由空白符包围的一个字符串。如果指定为长度值，会调整字之间的通常间隔；所以，normal 就等同于设置为 0。允许指定负长度值，这会让字之间挤得更紧。

- 属性值

| 值        | 描述                         |
| --------- | ---------------------------- |
| normal    | 使用浏览器默认的换行规则。   |
| break-all | 允许在单词内换行。           |
| keep-all  | 只能在半角空格或连字符处换行 |

## text-decoration

- 定义

> text-decoration 属性规定添加到文本的修饰。

- 语法

```
text-decoration：none|underline|overline|line-through|blink|inherit;
```

- 属性值

| 值           | 描述                                            |
| ------------ | ----------------------------------------------- |
| none         | 默认。定义标准的文本。                          |
| underline    | 定义文本下的一条线。                            |
| overline     | 定义文本上的一条线。                            |
| line-through | 定义穿过文本下的一条线。                        |
| inherit      | 规定应该从父元素继承 text-decoration 属性的值。 |

## font

> 文字简写

```css
font：font-style font-weight font-size / line-height font-family;
```

**注意：** 顺序不能改变，并且同时指定 font-size 和 font-family 才能同时生效

## text-transform

- 定义

> text-transform 属性控制文本的大小写。

- 语法

```css
text-transform:none|capitalize|uppercase|lowercase|inherit;
```

- 属性值

| 值         | 描述                                           |
| ---------- | ---------------------------------------------- |
| none       | 默认。定义带有小写字母和大写字母的标准的文本。 |
| capitalize | 文本中的每个单词以大写字母开头。               |
| uppercase  | 定义仅有大写字母。                             |
| lowercase  | 定义无大写字母，仅有小写字母。                 |
| inherit    | 规定应该从父元素继承 text-transform 属性的值。 |

# 列表属性

## list-style-type

- 定义

> list-style-type 属性设置或检索对象的列表项所使用的预设标记。

- 语法

```css
list-style-type：A;
```

其中，A 支持 20 余种样式，见下表所示。

- 属性值

| 值              | 描述               |
| --------------- | ------------------ |
| disc            | 实心圆             |
| circle          | 空心圆             |
| square          | 实心方块           |
| decimal         | 阿拉伯数字         |
| lower-roman     | 小写罗马数字       |
| upper-roman     | 大写罗马数字       |
| lower-alpha     | 小写英文字母       |
| upper-alpha     | 大写英文字母       |
| none            | 不使用项目符号     |
| armenian        | 传统的亚美尼亚数字 |
| cjk-ideographic | 浅白的表意数字     |
| georgian        | 传统的乔治数字     |
| lower-greek     | 基本的希腊小写字母 |
| hebrew          | 传统的希伯莱数字   |
| hiragana        | 日文平假名字符     |
| hiragana-iroha  | 日文平假名序号     |
| katakana        | 日文片假名字符     |
| katakana-iroha  | 日文片假名序号     |
| lower-latin     | 小写拉丁字母       |
| upper-latin     | 大写拉丁字母       |

## list-style-image

- 定义

> list-style-image 属性使用图像来替换列表项的标记。

- 语法

```css
list-style-image:URL|none|inherit;
```

- 属性值

| 值      | 描述                                             |
| ------- | ------------------------------------------------ |
| URL     | 图像的路径。                                     |
| none    | 默认。无图形被显示。                             |
| inherit | 规定应该从父元素继承 list-style-image 属性的值。 |

## list-style-position

- 定义

> list-style-position 属性设置在何处放置列表项标记。

非常不好用，并不能有效控制图片位置。

- 语法

```css
list-style-position：inside|outside|inherit;
```

- 属性值

| 值      | 描述                                                         |
| ------- | ------------------------------------------------------------ |
| inside  | 列表项目标记放置在文本以内，且环绕文本根据标记对齐。         |
| outside | 默认值。保持标记位于文本的左侧。列表项目标记放置在文本以外，且环绕文本不根据标记对齐。 |
| inherit | 规定应该从父元素继承 list-style-position 属性的值。          |

## list-style

- 定义

> list-style 简写属性在一个声明中设置所有的列表属性。

**注意：**该属性是一个简写属性，涵盖了所有其他列表样式属性。由于它应用到所有 display 为 list-item 的元素，所以在普通的 HTML 和 XHTML 中只能用于 li 元素，不过实际上它可以应用到任何元素，并由 list-item 元素继承。

可以按顺序设置如下属性，但顺序不影响规则：
-[`list-style-type`](https://man.ilovefishc.com/pageCSS3/list-style-type.html)
-[`list-style-position`](https://man.ilovefishc.com/pageCSS3/list-style-position.html)
-[`list-style-image`](https://man.ilovefishc.com/pageCSS3/list-style-image.html)

可以不设置其中的某个值，比如 “list-style:circle inside;” 也是允许的。未设置的属性会使用其默认值。

**如果想在 li 前面加一个 图片，可以在 li 中添加一个 span 标签，加上背景图片即可**

- 语法

```css
list-style:list-style-type|list-style-position|list-style-image|initial|inherit;
```

- 属性值

| 值                  | 描述                                       |
| ------------------- | ------------------------------------------ |
| list-style-type     | 设置列表项标记的类型。                     |
| list-style-position | 设置在何处放置列表项标记。                 |
| list-style-image    | 使用图像来替换列表项的标记。               |
| initial             | 将这个属性设置为默认值。                   |
| inherit             | 规定应该从父元素继承 list-style 属性的值。 |

# 背景属性

## background-color

- 定义

> background-color属性设置一个元素的背景颜色。

**注意：**元素的背景是元素的总大小，包括填充和边界（但不包括边距）。

- 语法

```css
background-color: color|transparent|inherit;
```

- 属性值

| 值          | 说明                             |
| ----------- | -------------------------------- |
| color       | 指定背景颜色。                   |
| transparent | 指定背景颜色应该是透明的。(默认) |
| inherit     | 指定背景颜色。(从父元素继承)     |

**注意：**color有三种表示法，具体使用情况参看下方代码。

```html
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>鱼C-零基础入门学习Web（Html5+Css3）</title>
    <style>
        body
        {
            /*命名颜色法*/
            background-color:red;
        }
        h1
        {
            /*十六进制颜色法*/
            background-color:#00ff00;
        }
        p
        {
            /*RGB颜色法*/
            background-color:rgb(0,0,255);
        }
    </style>
</head>
<body>
   <h1>鱼C工作室</h1>
   <p>Lorem ipsum dolor sit amet, consectetur adipisicing elit. Dolore eos, explicabo ipsam modi natus quibusdam rem suscipit. Alias architecto ea eius hic illo incidunt iste natus nemo reprehenderit, sint veniam.</p>
</body>
</html>
```

## background-image

- 定义

> background-image 属性为元素设置背景图像。

**注意：**元素的背景占据了元素的全部尺寸，包括内边距和边框，但不包括外边距。
默认地，背景图像位于元素的左上角，并在水平和垂直方向上重复。

- 语法

```css
 background-image: url('URL')|none|inherit;
```

- 属性值

| 值         | 说明                                               |
| ---------- | -------------------------------------------------- |
| url(‘URL’) | 指向图像的路径。                                   |
| none       | 默认值。不显示背景图像。                           |
| inherit    | 规定应该从父元素继承 background-image 属性的设置。 |

**注意：**`‘URL’`表示目标文件的路径，可以是相对路径或者绝对路径。

## background-repeat

- 定义

> background-repeat 属性设置是否及如何重复背景图像。

**注意：**默认地，背景图像在水平和垂直方向上重复，铺满整个屏幕。背景图像的位置是根据 `background-position` 属性设置的。如果未规定 background-position 属性，图像会被放置在元素的左上角。

- 语法

```css
 background-repeat:repeat|repeat-x|repeat-y|no-repeat|inherit;
```

- 属性值

| 值        | 说明                                                |
| --------- | --------------------------------------------------- |
| repeat    | 默认。背景图像将在垂直方向和水平方向重复。          |
| repeat-x  | 背景图像将在水平方向重复。                          |
| repeat-y  | 背景图像将在垂直方向重复。                          |
| no-repeat | 背景图像将仅显示一次。                              |
| inherit   | 规定应该从父元素继承 background-repeat 属性的设置。 |

## background-size

- 定义

> background-size 属性规定背景图像的尺寸。

- 语法

```css
background-size: length|percentage|cover|contain;
```

- 属性值

| 值         | 说明                                                         |
| ---------- | ------------------------------------------------------------ |
| length     | 设置背景图像的高度和宽度。第一个值设置宽度，第二个值设置高度。如果只设置一个值，则第二个值会被设置为 “auto”。 |
| percentage | 以父元素的百分比来设置背景图像的宽度和高度。第一个值设置宽度，第二个值设置高度。如果只设置一个值，则第二个值会被设置为 “auto”。 |
| cover      | 把背景图像扩展至足够大，以使背景图像完全覆盖背景区域。背景图像的某些部分也许无法显示在背景定位区域中。 |
| no-repeat  | 背景图像将仅显示一次。                                       |
| contain    | 把图像图像扩展至最大尺寸，以使其宽度和高度完全适应内容区域。 |

## background-position

- 定义

> background-position 属性设置背景图像的起始位置。

**注意：**这个属性设置背景原图像（由 `background-image` 定义）的位置，背景图像如果要重复，将从这一点开始。需要把 background-attachment 属性设置为 `"fixed"`，才能保证该属性在 Firefox 中正常工作。

- 语法

```css
background-position:A|B|C;
```

- 属性值

| 值                                            | 说明                                                         |
| --------------------------------------------- | ------------------------------------------------------------ |
| A（top、left、right、bottom、center）两两组合 | 如果仅规定了一个关键词，那么第二个值将是”center”。默认值：0% 0%。 |
| B（x% y%）                                    | 第一个值是水平位置，第二个值是垂直位置。左上角是 0% 0%。右下角是 100% 100%。如果仅规定了一个值，另一个值将是 50%。 |
| C(xpos ypos)                                  | 第一个值是水平位置，第二个值是垂直位置。左上角是 0 0。单位是像素 (0px 0px) 或任何其他的 CSS 单位。如果仅规定了一个值，另一个值将是50%。可以混合使用 % 和 position 值。 |

## background-attachment

- 定义

> background-attachment设置背景图像是否固定或者随着页面的其余部分滚动。

fixed 属性会让默认以浏览器窗口左上角作定位，谨慎使用。

- 语法

```css
background-attachment:scroll || fixed || inherit || local;
```

- 属性值

| 值      | 说明                                            |
| ------- | ----------------------------------------------- |
| scroll  | 背景图片随页面的其余部分滚动。这是**默认**      |
| fixed   | 背景图像是固定的                                |
| inherit | 指定background-attachment的设置应该从父元素继承 |
| local   | 背景图片随滚动元素滚动                          |

## background-clip

- 定义

> background-clip属性指定背景绘制区域。

- 语法

```css
background-clip: border-box|padding-box|content-box;
```

- 属性值

| 值          | 说明                                             |
| ----------- | ------------------------------------------------ |
| border-box  | 默认值。背景绘制在边框方框内（剪切成边框方框）。 |
| padding-box | 背景绘制在衬距方框内（剪切成衬距方框）。         |
| content-box | 背景绘制在内容方框内（剪切成内容方框）。         |

## background-origin

- 定义

> background-origin 属性规定 background-position 属性相对于什么位置来定位。

**注意：**如果背景图像的 background-attachment 属性为 “fixed”，则该属性没有效果。

- 语法

```css
background-origin: padding-box|border-box|content-box;
```

- 属性值

| 值          | 说明                           |
| ----------- | ------------------------------ |
| padding-box | 背景图像相对于内边距框来定位。 |
| border-box  | 背景图像相对于边框盒来定位。   |
| content-box | 背景图像相对于内容框来定位。   |

## background 复合属性

```css
background: background-color background-img background-repeat background-position background-attachment;
```

**background-size 只能单独用**



# 浮动属性

## 浮动的性质

1. 浮动的元素 **脱离标准版文档流**

2. 一旦一个元素浮动了，那么就能设置宽高，不区分块级元素和行内元素了

3. 浮动的元素互相贴靠

   如果有足够空间，那么就会靠着2哥；如果没有足够空间，那么就会靠着1号大哥。

   如果没有足够的空间靠着1号大哥，就会自己贴左墙。

   ![image-20220821213505903.png](https://s2.loli.net/2022/08/21/29WkdrLUfjvtzGB.png)

   4.浮动元素有自围绕效果

## 浮动的作用

1. 文本环绕显示
2. 打破 块元素 独占一行的情况

## 浮动清除

```html
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
    <style>
        .box1, .box2 {
            height: 300px;
            width: 300px;
            float: left;
        }

        .box1 {
            background-color: yellow;
        }

        .box2 {
            background-color: blue;
        }

        .box3 {
            width: 400px;
            height: 400px;
            background-color: red;
        }
    </style>
</head>
<body>
	<div class="container">
        <div class="box1"></div>
        <div class="box2"></div>
    </div>
    <div class="box3"></div>
</body>
</html>
```

![image.png](https://s2.loli.net/2022/09/21/BnmGDK9dgZJwCht.png)

### 清除方法1：给浮动元素的祖先元素加高度

```css
.container {
    height: 300px;
}
```

增加高度就不会出现高度塌陷的情况

### 清除方法2：增加属性：`clear: both;`

```css
.box3 {
    clear: both;
    margin-top: 50px;	// 此时 margin 失效
}
```

如果父元素没有设置高时，margin 会失效。

**这里 '失效' 是指 margin 会以父元素的 div 开始计算， 因为浮动并不会给父元素增加高度。**

### 清除方法3：内墙法

```html
<div class="container">
    <div class="box1"></div>
    <div class="box2"></div>
    <div style="clear: both;"></div>
</div>
```

此时父元素 `.container` 就会获得宽高。

### 清除方法4：`overflow: hidden;`

```css
.container {
    overflow:hidden;
}
```

`overflow:hidden;` 触发 `BFC` ，让浮动元素计算高度，从而使父元素获得高度。

# 盒子模型

所有HTML元素可以看作盒子，在CSS中，"box model"这一术语是用来设计和布局时使用。

CSS盒模型本质上是一个盒子，封装周围的HTML元素，它包括：边距，边框，填充，和实际内容。

盒模型允许我们在其它元素和周围元素边框之间的空间放置元素。

下面的图片说明了盒子模型(Box Model)：

![](https://www.runoob.com/images/box-model.gif)

不同部分的说明：

- **Margin(外边距)** - 清除边框外的区域，外边距是透明的。
- **Border(边框)** - 围绕在内边距和内容外的边框。
- **Padding(内边距)** - 清除内容周围的区域，内边距是透明的。
- **Content(内容)** - 盒子的内容，显示文本和图像。

为了正确设置元素在所有浏览器中的宽度和高度，你需要知道的盒模型是如何工作的。

## 元素的宽度和高度

当您指定一个 CSS 元素的宽度和高度属性时，你只是设置内容区域的宽度和高度。要知道，完整大小的元素，你还必须添加内边距，边框和外边距。

## padding

背景色会蔓延到内边距，padding不允许为负值。

## border

三个属性：线宽，线型，颜色。

颜色默认为黑色。

`border:border-width|border-style|border-color;`

边框有样式的前提下才会显示 颜色 和 宽度。

### border-style

border-style 属性用于设置元素所有边框的样式，或者单独地为各边设置边框样式。

**注意：**只有当这个值不是 none 时边框才可能出现。

`border-style:none|hidden|A|inherit;`

| 值      | 说明                                                         |
| ------- | ------------------------------------------------------------ |
| none    | 定义无边框。                                                 |
| hidden  | 与 “none” 相同。不过应用于表时除外，对于表，hidden 用于解决边框冲突。 |
| dotted  | 定义点状边框。在大多数浏览器中呈现为实线。                   |
| dashed  | 定义虚线。在大多数浏览器中呈现为实线。                       |
| solid   | 定义实线。                                                   |
| double  | 定义双线。双线的宽度等于 [border-width](https://man.ilovefishc.com/pageCSS3/border-width.html) 的值。 |
| groove  | 定义 3D 凹槽边框。其效果取决于 [border-color](https://man.ilovefishc.com/page/border-color.html) 的值。 |
| ridge   | 定义 3D 垄状边框。其效果取决于 [border-color](https://man.ilovefishc.com/page/border-color.html) 的值。 |
| inset   | 定义 3D inset 边框。其效果取决于 [border-color](https://man.ilovefishc.com/page/border-color.html) 的值。 |
| outset  | 定义 3D outset 边框。其效果取决于 [border-color](https://man.ilovefishc.com/page/border-color.html) 的值。 |
| inherit | 规定应该从父元素继承边框样式。                               |

### border-width

border-width 简写属性为元素的所有边框设置宽度，或者单独地为各边边框设置宽度。

**注意：**只有当边框样式不是 none 时才起作用。如果边框样式是 none，边框宽度实际上会重置为 0。不允许指定负长度值。

`border-width:medium|thin|thick|length|inherit;`

| 值      | 描述                           |
| ------- | ------------------------------ |
| thin    | 定义细的上边框。               |
| medium  | 默认值。定义中等的上边框。     |
| thick   | 定义粗的上边框。               |
| length  | 允许您自定义上边框的宽度。     |
| inherit | 规定应该从父元素继承边框宽度。 |

### border-color

border-color 属性设置四条边框的颜色。

### border-radius

border-radius 属性是一个简写属性，用于设置四个 border-*-radius 属性。

迷幻行为： `apx bpx` 时， 显示为 左上和右下为 apx apx 的圆角， 右上和左下为 bpx bpx 的圆角。

只有设置为 `apx / bpx` 时，才会四个角都是 apx bpx。

形如：`a1px b1px c1px d1px / a2px b2px c2px d2px` 时 表示左上、右上、右下、左下 为 (a1px a2px) ... (d1px d2px)

### border-image

border-image属性使用图片作为对象的边界。

**注意：**当table设置border-collapse为collapse无效。

| 值                  | 说明                                                         |
| ------------------- | ------------------------------------------------------------ |
| border-image-source | 用在边框的图片的路径。                                       |
| border-image-slice  | 图片边框向内偏移。                                           |
| border-image-width  | 图片边框的宽度。                                             |
| border-image-outset | 边框图像区域超出边框的量。                                   |
| border-image-repeat | 图像边框是否应平铺(repeated)、铺满(rounded)或拉伸(stretched) |

### border-image-source

默认载入，图像只会出现在四个角，可以借助slice来处理

### border-image-slice

border-image-slice属性指定图像的边界向内偏移。

**注意：**此属性指定顶部，右，底部，左边缘的图像向内偏移，分为九个区域：四个角，四边和中间。图像中间部分将被丢弃（完全透明的处理），除非填写关键字。如果省略第四个数字/百分比，它和第二个相同的。如果也省略了第三个，它和第一个是相同的。如果也省略了第二个，它和第一个是相同的。

**注意：这里的单位默认是 px 所以不要写 px，否则造成语法错误**

| 值     | 说明                                                         |
| ------ | ------------------------------------------------------------ |
| number | 数字表示图像的像素（位图图像）或向量的坐标（如果图像是矢量图像） |
| %      | 百分比图像的大小是相对的：水平偏移图像的宽度，垂直偏移图像的高度 |
| fill   | 保留图像的中间部分                                           |

### border-image-repeat

border-image-repeat 属性规定图像边框是否应该被重复（repeated）、拉伸（stretched）或铺满（rounded）。

**注意：**该属性规定如何延展和铺排边框图像的**边缘**和**中间部分**。因此，可以规定两个值。如果省略第二个值，则采取与第一个值相同的值。

| 值      | 说明                                                         |
| ------- | ------------------------------------------------------------ |
| stretch | 拉伸图像来填充区域                                           |
| repeat  | 平铺（重复）图像来填充区域。                                 |
| round   | 类似 repeat 值。如果无法完整平铺所有图像，则对图像进行缩放以适应区域。 |

### border-image-outset

border-image-outset 属性规定边框图像超出边框盒的量。

**注意：**border-image-outset 属性规定边框图像超出边框盒的量。在上、右、下、左侧。如果忽略第四个值，则与第二个值相同。如果省略第三个值，则与第一个值相同。如果省略第二个值，则与第一个值相同。不允许任何负值作为 border-image-outset 值。

| length | 设置边框图像与边框（[border-image](https://man.ilovefishc.com/page/border-image.html)）的距离，默认为0。 |
| ------ | ------------------------------------------------------------ |
| number | 代表相应的 border-width 的倍数                               |

### border-image -width

border-image -width属性指定图像边界的宽度。

| 值     | 说明                                                         |
| ------ | ------------------------------------------------------------ |
| number | 表示相应的border-width 的倍数                                |
| %      | 边界图像区域的大小：横向偏移的宽度的面积，垂直偏移的高度的面积 |
| auto   | 如果指定了，宽度是相应的image slice的内在宽度或高度          |

## margin

### margin 属性

`margin: auto` 生效必须是 块级元素，且有宽度。

**只有块级元素添加margin:0 auto有效果，行内元素和行内块元素添加margin:0 auto均不起效果。**

`margin: 0 auto;` auto 代表尽其所能的增加。

只有标准流的盒子，才能使用；浮动，绝对定位，固定定位均不可以使用；

`margin: 0 auto;` 是在居中盒子，而不是文本，文本居中需要使用 `text-align:center;`

### margin 塌陷

左右边距取和，上下边距取最大。

### margin 父子元素外边距问题

```html
<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
    <style>
        .parent {
            width: 500px;
            height: 500px;
            background-color: yellow;
        }

        .child {
            width: 100px;
            height: 100px;
            background-color: red;
            margin-top: 100px;
        }
    </style>
</head>

<body>
    <div class="parent">
        <div class="child"></div>
    </div>
</body>

</html>
```

此时元素的上边距会作用在父元素上。

- **解决方法1：父元素加 padding**

  这种方式会增加父元素的宽高，所以加 padding 后还需要调整宽高（除非设置了 `box-sizing: border-box;`）

- **解决方法2：父元素加 border**

  还是会调整父元素的宽高。（颜色 transparent 透明可以隐藏边框显示）

- **解决方法3：加浮动**

  父子元素加浮动均可。

- **解决方法4：overflow: hidden**

  产生 BFC 后，父元素就自成空间，不会再对外界产生任何干扰。
  
  overflow: hidden; 后 position: sticky; 就失效了。

# overflow 溢出

overflow 属性规定当内容溢出元素框时发生的事情。

**注意：**这个属性定义溢出元素内容区的内容会如何处理。如果值为 scroll，不论是否需要，用户代理都会提供一种滚动机制。因此，有可能即使元素框中可以放下所有内容也会出现滚动条。

| 值      | 说明                                                         |
| ------- | ------------------------------------------------------------ |
| visible | 默认值。内容不会被修剪，会呈现在元素框之外。                 |
| hidden  | 内容会被修剪，并且其余内容是不可见的。                       |
| scroll  | 内容会被修剪，但是浏览器会显示滚动条以便查看其余的内容。     |
| auto    | 如果内容被修剪，则浏览器会显示滚动条以便查看其余的内容。推荐。 |
| inherit | 规定应该从父元素继承 overflow 属性的值。                     |

同时提供：`overflow-x`、`overflow-y` 分轴设置属性

# white-space

- 定义

> white-space 属性设置如何处理元素内的空白。

- 语法

```css
 white-space:normal|pre|nowrap|pre-wrap|pre-line|inherit;
```

- 属性值

| 值       | 描述                                                         |
| -------- | ------------------------------------------------------------ |
| normal   | 默认。空白会被浏览器忽略。                                   |
| `pre`    | 空白会被浏览器保留。其行为方式类似 HTML 中的 `<pre>` 标签。  |
| `nowrap` | 文本不会换行，文本会在在同一行上继续，直到遇到 `<br>` 标签为止。 |
| pre-wrap | 保留空白符序列，但是正常地进行换行。                         |
| pre-line | 合并空白符序列，但是保留换行符。                             |
| nherit   | 规定应该从父元素继承 white-space 属性的值。                  |

## 溢出省略号

```css
div {
    white-space: nowrap;
    overflow: hidden;
    text-overflow: ellipsis;
}
```

当单行文本溢出显示省略号需要同时设置以下声明：

1. 容器宽度：width: 200px;
2. 强制文本在一行内显示：white-space: nowrap;
3. 溢出内容为隐藏：overflow: hidden;
4. 溢出文本显示省略号：text-overflow: ellipsis;

# 元素显示类型

- **块元素**

  例如：div p ul li ol li dl dt dd h1-h6等

- **行内（内联）元素**

  例如：a b em i span strong等

- **行内块元素**

  例如：img input 等

p 标签内部只能放 文本，不能放块元素，但是可以放行内块元素。

## 行内元素

**行内元素只能实现左右边距和 padding，无法实现上下边距。**

**其中增加 padding 可以蔓延背景，但是上下 padding 的边距距离是不生效的。**

## 元素类型互相转换

`display: block;`

# 定位

## position

position 属性规定元素的定位类型。

| 值       | 文档流 | 说明                                                         |
| -------- | ------ | ------------------------------------------------------------ |
| static   | 默认   | 默认值。没有定位，元素出现在正常的流中（忽略 top, bottom, left, right 或者 z-index 声明）。 |
| absolute | 脱离   | 生成绝对定位的元素，相对于 static 定位以外的第一个父元素进行定位。元素的位置通过 “left”, “top”, “right” 以及 “bottom” 属性进行规定。 |
| fixed    | 脱离   | 生成绝对定位的元素，相对于浏览器窗口进行定位。元素的位置通过 “left”, “top”, “right” 以及 “bottom” 属性进行规定。 |
| relative | 不脱离 | 生成相对定位的元素，相对于其正常位置进行定位。因此，”left:20” 会向元素的 LEFT 位置添加 20 像素。 |
| sticky   | /      | 粘性定位，可以做吸顶效果，css3.0新增                         |
| inherit  | /      | 规定应该从父元素继承 position 属性的值。                     |

要使用绝对定位时，推荐使用 `子绝父相`

absolute 的绝对定位是相对于第一屏， fixed 是相对于浏览器窗口。

## z-index 层级

- 定义

> z-index 属性设置元素的堆叠顺序。

**注意：**拥有更高堆叠顺序的元素总是会处于堆叠顺序较低的元素的前面。

- 语法

```css
z-index:auto|number|inherit;
```

- 属性值

| 值      | 说明                                    |
| ------- | --------------------------------------- |
| auto    | 默认。堆叠顺序与父元素相等。            |
| number  | 设置元素的堆叠顺序。                    |
| inherit | 规定应该从父元素继承 z-index 属性的值。 |

### 父子层级

```html
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
    <style>
        .box {
            width: 200px;
            height: 200px;
            background-color: yellow;
            z-index: 100;
        }

        .child {
            width: 100px;
            height: 100px;
            background-color: red;
            position:absolute;
            top: 20px;
            left: 20px;
            z-index: -1;
        }
    </style>
</head>
<body>
    <div class="box">
        <div class="child"></div>
    </div>
</body>
</html>
```

此时父子定位只有 child 的 z-index 设置为负值时，才能被父元素覆盖；同时 child position 为 static 时， 无论怎么设置，子元素都不会被覆盖。（因为 static 处于标准文档流中）

但是兄弟关系的绝对定位可以随意覆盖。

## 水平垂直居中

```css
.box1 {
    width: 600px;
    height: 600px;
    background-color: red;
    margin: 0 auto;

    position: absolute;
    top: 50%;
    left: 50%;
    margin-top: -300px;
    margin-left: -300px;
}
```

# CSS 精灵图

## CSS Sprites 的原理（图片整合技术）

有许多图像的网页可能需要很长的时间来加载和生成多个服务器的请求。

使用图像拼合会降低服务器的请求数量，并节省带宽。

将图片有规则的合并成一张背景图，即多张图片合为一张整图，然后用 `background-position` 来实现背景图片的定位技术。

# 宽高自适应

## 宽度自适应

块级元素 width 不设置相当于 auto，默认自适应。注意：auto 与 100% 不一样。

## 高度自适应

`min-height` 最常使用。

## 浮动元素的父元素高度自适应

**父元素不写高度时，子元素浮动后，父元素会发生高度塌陷。**

1. 给父元素添加声明: `overflow:hidden;` （缺点：会隐藏溢出的元素）
2. 在浮动元素下方添加空的块元素，并给该元素声明: `clear: both; height: 0; overflow: hidden;` （缺点：在结构里增加了空的标签，不利于代码可读性，且降低了浏览器的性能）
3. 万能清除浮动法: 选择符 `:after{content:" "; clear: both; display: block; height: 0; visibility: hidden;/overflow: hidden;}`

## 窗口自适应

`html, body {height: 100%;}`

# resize

resize属性指定一个元素是否是由用户调整大小的。

**注意：**resize属性适用于计算其他元素的溢出值是不是”visible”。

也就是说，`overflow: visible` 时，resize 不会生效。

| 属性       | 说明                         |
| ---------- | ---------------------------- |
| none       | 用户无法调整元素的尺寸。     |
| both       | 用户可调整元素的高度和宽度。 |
| horizontal | 用户可调整元素的宽度。       |
| vertical   | 用户可调整元素的高度。       |

# 轮廓（outline）

轮廓并不属于元素尺寸的一部分，不会影响到原有的页面布局。

# 表格属性

## border-collapse

- 定义

> border-collapse 属性设置表格的边框是否被合并为一个单一的边框。

**注意：**如果没有指定[!DOCTYPE](http://man.fishc.com/page/!DOCTYPE.html)，可能产生意想不到的效果。

- 语法

```css
border-collapse:collapse|separate|inherit;
```

- 属性值

| 值       | 说明                                                         |
| -------- | ------------------------------------------------------------ |
| collapse | 如果可能，边框会合并为一个单一的边框。会忽略 border-spacing 和 empty-cells 属性 |
| separate | 默认值。边框会被分开。不会忽略 border-spacing 和 empty-cells 属性 |
| inherit  | 规定应该从父元素继承 border-collapse 属性的值                |

# 阴影

# box-sizing

- 定义

> box-sizing 属性允许以某种方式定义某些元素，以适应指定区域。

**注意：**假如需要并排放置两个带边框的框，可通过将 box-sizing 设置为 “border-box”。这可令浏览器呈现出带有指定宽度和高度的框，并把边框和内边距放入框中。

- 语法

```css
box-sizing: content-box|border-box|inherit;
```

- 属性值

| 属性        | 说明                                                         |
| ----------- | ------------------------------------------------------------ |
| content-box | 这是CSS2.1指定的宽度和高度的行为。指定元素的宽度和高度（最小/最大属性）适用于box的宽度和高度。元素的填充和边框布局和绘制指定宽度和高度除外 |
| border-box  | 指定宽度和高度（最小/最大属性）确定元素边框box。也就是说，对元素指定宽度和高度包括padding和border的指定。内容的宽度和高度减去各自双方该边框和填充的宽度从指定的”宽度”和”高度”属性计算 |
| inherit     | 指定box-sizing属性的值，应该从父元素继承                     |

# CSS 继承性

能继承的属性：`color`, `text- 开头的`, `line- 开头的`, `font- 开头的` 

# 标准文档流

## 块级元素和行内元素

**块级元素:**

- 霸占一行，不能与其他元素并列
- 能接受宽、高
- 如果不设置宽度，那么宽度默认为父亲的100%

**行内元素：**

- 与其他行内元素并排
- 不能设置宽高，默认宽度为文字的宽度

# BFC

如果满足下面任意条件，就会自动创建一个新的BFC：

- float 属性的值不为 none
- position 属性的值不为 static 或 relative
- overflow 属性的值不为 visible
- display 属性的值为 flex，inline-flex，inline-block，table-cell 或 table-caption

最常见的是用 `overflow: hidden` ，因为可能产生的副作用是最小的。

# 多列布局

## columns

columns 属性设置列宽和列数。

语法：`columns: column-width column-count;`

| 值                                                           | 说明     |
| ------------------------------------------------------------ | -------- |
| [`column-width`](https://man.ilovefishc.com/pageCSS3/column-width.html) | 列的宽度 |
| [`column-count`](https://man.ilovefishc.com/pageCSS3/column-count.html) | 列数     |

### column-width

column-width 属性指定列的宽度。

语法： `column-width: auto|length;`

其实是指的列最小宽度。

### column-count

column-count 属性指定某个元素应分为的列数。

语法：`column-count: number|auto;`

## column-gap

column-gap 的属性指定的列之间的差距。

语法：`column-gap: length|normal;`

| 值     | 说明                                    |
| ------ | --------------------------------------- |
| length | 一个指定的长度，将设置列之间的差距      |
| normal | 指定一个列之间的普通差距。 W3C建议1EM值 |

## column-rule

column-rule 属性设置列之间的宽度，样式和颜色。

语法：`column-rule: column-rule-width column-rule-style column-rule-color;`

| 值                                                           | 说明                   |
| ------------------------------------------------------------ | ---------------------- |
| [`column-rule-width`](https://man.ilovefishc.com/pageCSS3/column-rule-width.html) | 设置列中之间的宽度规则 |
| [`column-rule-style`](https://man.ilovefishc.com/pageCSS3/column-rule-style.html) | 设置列中之间的样式规则 |
| [`column-rule-color`](https://man.ilovefishc.com/pageCSS3/column-rule-color.html) | 设置列中之间的颜色规则 |

### column-rule-width

column-rule-width 属性指定列之间的宽度大小。

| 值     | 说明                 |
| ------ | -------------------- |
| thin   | 指定一个细边框的规则 |
| medium | 定义一个中等边框规则 |
| thick  | 指定一个粗边框的规则 |
| length | 指定宽度的规则       |

### column-rule-style

column-rule-style 属性指定列之间的样式规则。

| 值     | 说明                                             |
| ------ | ------------------------------------------------ |
| none   | 定义没有规则。                                   |
| hidden | 定义隐藏规则。                                   |
| dotted | 定义点状规则。                                   |
| dashed | 定义虚线规则。                                   |
| solid  | 定义实线规则。                                   |
| double | 定义双线规则。                                   |
| groove | 定义 3D grooved 规则。该效果取决于宽度和颜色值。 |
| ridge  | 定义 3D ridged 规则。该效果取决于宽度和颜色值。  |
| inset  | 定义 3D inset 规则。该效果取决于宽度和颜色值。   |
| outset | 定义 3D outset 规则。该效果取决于宽度和颜色值。  |

### column-rule-color

column-rule-color 属性指定列之间的颜色规则。

## column-span

column-span 属性指定某个元素应该跨越多少列。

语法：`column-span: 1|all;`

## column-fill

`column-fill: balance` 文本的填充是均匀分配的

 `column-fill: auto` 文本的填充是按顺序分配的

# 弹性布局

`display: flex;` : 此元素将显示为弹性盒容器。

`display: inline-flex;` ：此元素将显示为行内弹性盒容器。

## flex-flow

flex-flow 属性是 [flex-direction](https://man.ilovefishc.com/pageCSS3/flexDirection.html) 和 [flex-wrap](https://man.ilovefishc.com/pageCSS3/flexWrap.html) 属性的复合属性。

- **如果元素不是弹性盒对象的元素，则 flex-flow 属性不起作用。**

语法：`flex-flow:flex-direction flex-wrap|initial|inherit;`

### flex-direction

flex-direction 属性规定灵活项目的方向。

- **如果元素不是弹性盒对象的元素，则 flex-direction 属性不起作用。**

语法：`flex-direction: row|row-reverse|column|column-reverse|initial|inherit;`

| 值             | 描述                                         |
| -------------- | -------------------------------------------- |
| `row`          | 默认值，灵活的项目将水平显示，正如一个行一样 |
| column         | 灵活的项目将垂直显示，正如一个列一样。       |
| column-reverse | 与 column 相同，但是以相反的顺序。           |
| initial        | 设置该属性为它的默认值。                     |
| inherit        | 从父元素继承该属性。                         |

### flex-wrap

flex-wrap 属性规定 flex 容器是单行或者多行，同时横轴的方向决定了新行堆叠的方向。

- **如果元素不是弹性盒对象的元素，则 flex-wrap 属性不起作用。**

| 值           | 描述                                                     |
| ------------ | -------------------------------------------------------- |
| nowrap       | 默认值。规定灵活的项目不拆行或不拆列。                   |
| `wrap`       | 规定灵活的项目在必要的时候拆行或拆列。                   |
| wrap-reverse | 规定灵活的项目在必要的时候拆行或拆列，但是以相反的顺序。 |
| initial      | 设置该属性为它的默认值。                                 |
| inherit      | 从父元素继承该属性。                                     |

# 颜色

## 前景色

[标准颜色名称查询](https://man.ilovefishc.com/color/index.html)

CSS支持 RGB、 HEX、 HSL、 RGBA、 HSLA 五种方式表示颜色。

### HSL

其中 HSL，分别是 色相（Hue ）、饱和度（Saturation ）、亮度（Lightness）。
