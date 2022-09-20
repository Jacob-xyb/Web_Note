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
2. **内部样式表（Internal Style Sheet）**
3. **外部样式表（External Style Sheet）**：HTML5 推荐用法

# CSS 基础语法

## CSS 语法

CSS 规则由两个主要的部分构成：选择器，以及一条或多条声明。

```
selector {declaration1; declaration2; ... declarationN }
```

选择器通常是您需要改变样式的 HTML 元素。

每条声明由一个属性和一个值组成。

属性（property）是您希望设置的样式属性（style attribute）。每个属性有一个值。属性和值被冒号分开。

```html
selector {property: value}
```

下面这行代码的作用是将 h1 元素内的文字颜色定义为红色，同时将字体大小设置为 14 像素。

在这个例子中，h1 是选择器，color 和 font-size 是属性，red 和 14px 是值。

```html
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

# 颜色

## 前景色

[标准颜色名称查询](https://man.ilovefishc.com/color/index.html)

CSS支持 RGB、 HEX、 HSL、 RGBA、 HSLA 五种方式表示颜色。

### HSL

其中 HSL，分别是 色相（Hue ）、饱和度（Saturation ）、亮度（Lightness）。

## 背景色

### 背景图

浏览器会使用背景图像去覆盖背景颜色

`background-imag:url();`	背景图片自动填充

**多张图片时，左边的会覆盖右边的图像**

`background-repeat: no-repeat;` 不重复填充

`background-repeat: repeat-x;` 只横向重复 （space 也是垂直重复）

`background-repeat: repeat-x;` 只纵向重复

`background-position:` 控制背景图像的绝对位置 

### background-attachment

background-attachment设置背景图像是否固定或者随着页面的其余部分滚动。

`background-attachment:scroll || fixed || inherit || local;`

| 值      | 说明                                            |
| ------- | ----------------------------------------------- |
| scroll  | 背景图片随页面的其余部分滚动。这是默认          |
| fixed   | 背景图像是固定的；此时 size 就无效了            |
| inherit | 指定background-attachment的设置应该从父元素继承 |
| local   | 背景图片随滚动元素滚动                          |

### background-origin

background-origin 属性规定 background-position 属性相对于什么位置来定位。

- **如果背景图像的 background-attachment 属性为 “fixed”，则该属性没有效果。**

`background-origin: padding-box|border-box|content-box;`

| 值          | 说明                                   |
| ----------- | -------------------------------------- |
| padding-box | 默认值。背景图像相对于内边距框来定位。 |
| border-box  | 背景图像相对于边框盒来定位。           |
| content-box | 背景图像相对于内容框来定位。           |

### background-clip

background-clip属性指定背景绘制区域。

`background-clip: border-box|padding-box|content-box;`

| 值          | 说明                                             |
| ----------- | ------------------------------------------------ |
| border-box  | 默认值。背景绘制在边框方框内（剪切成边框方框）。 |
| padding-box | 背景绘制在衬距方框内（剪切成衬距方框）。         |
| content-box | 背景绘制在内容方框内（剪切成内容方框）。         |

# 边框

`border:border-width|border-style|border-color;`

边框有样式的前提下才会显示 颜色 和 宽度。

## border-style

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

## border-width

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

## border-color

border-color 属性设置四条边框的颜色。

## border-radius

border-radius 属性是一个简写属性，用于设置四个 border-*-radius 属性。

迷幻行为： `apx bpx` 时， 显示为 左上和右下为 apx apx 的圆角， 右上和左下为 bpx bpx 的圆角。

只有设置为 `apx / bpx` 时，才会四个角都是 apx bpx。

形如：`a1px b1px c1px d1px / a2px b2px c2px d2px` 时 表示左上、右上、右下、左下 为 (a1px a2px) ... (d1px d2px)

## border-image

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

# 边距

## 内边距

## 外边距

`margin: auto` 生效必须是 块级元素，且有宽度。

`margin: 0 auto;` auto 代表尽其所能的增加。

只有标准流的盒子，才能使用；浮动，绝对定位，固定定位均不可以使用；

`margin: 0 auto;` 是在居中盒子，而不是文本，文本居中需要使用 `text-align:center;`

### margin 塌陷

左右边距取和，上下边距取最大。

**注意：**假如需要并排放置两个带边框的框，可通过将 box-sizing 设置为 “border-box”。这可令浏览器呈现出带有指定宽度和高度的框，并把边框和内边距放入框中。

| 属性        | 说明                                                         |
| ----------- | ------------------------------------------------------------ |
| content-box | 这是CSS2.1指定的宽度和高度的行为。指定元素的宽度和高度（最小/最大属性）适用于box的宽度和高度。元素的填充和边框布局和绘制指定宽度和高度除外 |
| border-box  | 指定宽度和高度（最小/最大属性）确定元素边框box。也就是说，对元素指定宽度和高度包括padding和border的指定。内容的宽度和高度减去各自双方该边框和填充的宽度从指定的”宽度”和”高度”属性计算 |
| inherit     | 指定box-sizing属性的值，应该从父元素继承                     |

# 尺寸

## box-sizing

box-sizing 属性允许以某种方式定义某些元素，以适应指定区域。

## 最小最大尺寸

## 溢出

overflow 属性规定当内容溢出元素框时发生的事情。

**注意：**这个属性定义溢出元素内容区的内容会如何处理。如果值为 scroll，不论是否需要，用户代理都会提供一种滚动机制。因此，有可能即使元素框中可以放下所有内容也会出现滚动条。

| 值      | 说明                                                         |
| ------- | ------------------------------------------------------------ |
| visible | 默认值。内容不会被修剪，会呈现在元素框之外。                 |
| hidden  | 内容会被修剪，并且其余内容是不可见的。                       |
| scroll  | 内容会被修剪，但是浏览器会显示滚动条以便查看其余的内容。     |
| auto    | 如果内容被修剪，则浏览器会显示滚动条以便查看其余的内容。推荐。 |
| inherit | 规定应该从父元素继承 overflow 属性的值。                     |

同时提供：`overflow-x`、`overflow-y`

## resize

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

# 阴影

# 显示类型



# CSS 继承性

能继承的属性：`color`, `text- 开头的`, `line- 开头的`, `font- 开头的` 

# CSS 盒子模型

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

## border

三个属性：线宽，线型，颜色。

颜色默认为黑色。

# 标准文档流

## 块级元素和行内元素

**块级元素:**

- 霸占一行，不能与其他元素并列
- 能接受宽、高
- 如果不设置宽度，那么宽度默认为父亲的100%

**行内元素：**

- 与其他行内元素并排
- 不能设置宽高，默认宽度为文字的宽度

# 浮动

## 浮动的性质

1. 浮动的元素 **脱离标准版文档流**

2. 一旦一个元素浮动了，那么就能设置宽高，不区分块级元素和行内元素了

3. 浮动的元素互相贴靠

   如果有足够空间，那么就会靠着2哥；如果没有足够空间，那么就会靠着1号大哥。

   如果没有足够的空间靠着1号大哥，就会自己贴左墙。

   ![image-20220821213505903.png](https://s2.loli.net/2022/08/21/29WkdrLUfjvtzGB.png)

   4.浮动元素有自围绕效果

## 浮动清除

清除方法1：给浮动元素的祖先元素加高度

清除方法2：增加属性：`clear: both;` ，如果父元素没有设置高时，margin 会失效

清除方法3：用 `<div>` 建一堵墙

清除方法4：内墙法

清除方法5：`overflow: hidden;`

# 定位

## position

position 属性规定元素的定位类型。

| 值       | 说明                                                         |
| -------- | ------------------------------------------------------------ |
| static   | 默认值。没有定位，元素出现在正常的流中（忽略 top, bottom, left, right 或者 z-index 声明）。 |
| absolute | 生成绝对定位的元素，相对于 static 定位以外的第一个父元素进行定位。元素的位置通过 “left”, “top”, “right” 以及 “bottom” 属性进行规定。 |
| fixed    | 生成绝对定位的元素，相对于浏览器窗口进行定位。元素的位置通过 “left”, “top”, “right” 以及 “bottom” 属性进行规定。 |
| relative | 生成相对定位的元素，相对于其正常位置进行定位。因此，”left:20” 会向元素的 LEFT 位置添加 20 像素。 |
| inherit  | 规定应该从父元素继承 position 属性的值。                     |

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

