# JavaScript介绍

## JavaScript 组成

- **BOM**

  Browser Object Model

  JS 操作浏览器发生变化的属性和方法

- **DOM**

  Document Object Model

  JS 操作文档流发生变化的属性和方法

- **ECMAScript**

  JavaScript书写语法和书写规则 

# JavaScript的书写位置

## 行内式

**直接把代码书写在标签上**

- **a** 标签

  书写在 `herf` 属性上

  ```html
  <a href="javascript: alert('hello world') ;">点击</a>
  ```

- 非 **a** 标签

  书写在行为属性上

  ```html
  <div onclick="alert('hello world') ">非a点击</div>
  ```

## 内嵌式

写在 `script` 标签对内

内嵌式 JS 代码，不需要依赖任何行为，打开页面就会执行

## 外链式

把代码书写在一个 .js 文件内

```html
<script src=""></script>
```

如果设置了 `src` 特性，`script` 标签内容将会被忽略。

# ECMAScript

## 注释

- **单行注释以两个正斜杠字符 `//` 开始。**

  这一行的剩余部分是注释。它可能独占一行或者跟随在一条语句的后面。

  ```js
  // 这行注释独占一行
  alert('Hello');
  alert('World'); // 这行注释跟随在语句后面
  ```

- **多行注释以一个正斜杠和星号开始 `“/\*”` 并以一个星号和正斜杆结束 `“\*/”`。**

  ```js
  /* 两个消息的例子。
  这是一个多行注释。
  */
  alert('Hello');
  alert('World');
  ```

- 不支持注释嵌套！

  不要在 `/*...*/` 内嵌套另一个 `/*...*/`。

## 现代模式

### “use strict”

这个指令看上去像一个字符串 `"use strict"` 或者 `'use strict'`。当它处于脚本文件的顶部时，则整个脚本文件都将以“现代”模式进行工作。

没有办法取消 `use strict`。

没有类似于 `"no use strict"` 这样的指令可以使程序返回默认模式。

---

以后，当你使用浏览器控制台去测试功能时，请注意 `use strict` 默认不会被启动。

有时，使用 `use strict` 会产生一些不一样的影响，你会得到错误的结果。

你可以试试按下 Shift+Enter 去输入多行代码，然后将 `use strict` 置顶，就像这样：

```js
'use strict'; <Shift+Enter 换行>
//  ...你的代码
<按下 Enter 以运行>
```

它在大部分浏览器中都有效，像 Firefox 和 Chrome。

如果依然不行，那确保 `use strict` 被开启的最可靠的方法是，像这样将代码输入到控制台：

```js
(function() {
  'use strict';
  // ...你的代码...
})()
```

## 变量

在 JavaScript 中创建一个变量，我们需要用到 `let` 关键字。

下面的语句创建（也可以称为 **声明** 或者 **定义**）了一个名称为 “message” 的变量：

```js
let message;
```

现在，我们可以通过赋值运算符 `=` 为变量添加一些数据：

```js
let message;
message = 'Hello'; // 保存字符串
```

简洁一点，我们可以将变量定义和赋值合并成一行：

```js
let message = 'Hello!'; // 定义变量，并且赋值
alert(message); // Hello!
```

也可以在一行中声明多个变量，但不推荐：

```js
let user = 'John', age = 25, message = 'Hello';
```

### var 与 let

在较旧的脚本中，你也可能发现另一个关键字 `var`，而不是 `let`：

```js
var message = 'Hello';
```

`var` 关键字与 `let` **大体** 相同，也用来声明变量，但稍微有些不同，也有点“老派”。

### 变量命名

JavaScript 的变量命名有两个限制：

1. 变量名称必须仅包含字母，数字，符号 `$` 和 `_`。
2. 首字符必须非数字。

如果命名包括多个单词，通常采用驼峰式命名法（[camelCase](https://en.wikipedia.org/wiki/CamelCase)）。也就是，单词一个接一个，除了第一个单词，其他的每个单词都以大写字母开头：`myVeryLongName`。

有趣的是，美元符号 `'$'` 和下划线 `'_'` 也可以用于变量命名。它们是正常的符号，就跟字母一样，没有任何特殊的含义。

下面的命名是有效的：

```js
let $ = 1; // 使用 "$" 声明一个变量
let _ = 2; // 现在用 "_" 声明一个变量
alert($ + _); // 3
```

> 未采用 `use strict` 下的赋值
>
> 一般，我们需要在使用一个变量前定义它。但是在早期，我们可以不使用 `let` 进行变量声明，而可以简单地通过赋值来创建一个变量。现在如果我们不在脚本中使用 `use strict` 声明启用严格模式，这仍然可以正常工作，这是为了保持对旧脚本的兼容。
>
> 在现代模式中极其不推荐！

### 保留字

有一张 [保留字列表](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Lexical_grammar#Keywords)，这张表中的保留字无法用作变量命名，因为它们被用于编程语言本身了。

比如，`let`、`class`、`return`、`function` 都被保留了。

### 常量

声明一个常数（不变）变量，可以使用 `const` 而非 `let`：

```js
const aWeekDay = 7;
```

使用 `const` 声明的变量称为“常量”。它们不能被修改，如果你尝试修改就会发现报错。

一个普遍的做法是将常量用作别名，以便记住那些在执行之前就已知的难以记住的值。

使用大写字母和下划线来命名这些常量。

```js
const WEEK_DAY = 7;
```

作为一个“常数”，意味着值永远不变。但是有些常量在执行之前就已知了（比如红色的十六进制值），还有些在执行期间被“计算”出来，但初始赋值之后就不会改变。

例如：

```js
const pageLoadTime = /* 网页加载所需的时间 */;
```

`pageLoadTime` 的值在页面加载之前是未知的，所以采用常规命名。但是它仍然是个常量，因为赋值之后不会改变。

换句话说，大写命名的常量仅用作“硬编码（hard-coded）”值的别名。

## 数据类型

### 动态类型语言

JavaScript 中的变量可以保存任何数据。变量在前一刻可以是个字符串，下一刻就可以变成 number 类型：

```js
// 没有错误
let message = "hello";
message = 123456;
```

允许这种操作的编程语言称为“动态类型”（dynamically typed）的编程语言，意思是虽然编程语言中有不同的数据类型，但是你定义的变量并不会在定义后，被限制为某一数据类型。

在 JavaScript 中有八种基本的数据类型。

### number 类型

```js
let n1 = 123;
document.write(typeof(n1), `<br>`); // number
let n2 = 12.345;
document.write(typeof(n2), `<br>`); // number
```

*number* 类型代表 **整数** 和 **浮点数**。

---

除了常规的数字，还包括所谓的 **“特殊数值（“special numeric values”）”** 也属于这种类型：`Infinity`、`-Infinity` 和 `NaN`。

- `Infinity` 代表数学概念中的 [无穷大](https://en.wikipedia.org/wiki/Infinity) ∞。是一个比任何数字都大的特殊值。

  我们可以通过除以 0 来得到它：

  ```js
  alert( 1 / 0 ); // Infinity
  ```

  或者在代码中直接使用它：

  ```js
  alert( Infinity ); // Infinity
  ```

- `NaN` 代表一个计算错误。它是一个不正确的或者一个未定义的数学操作所得到的结果，比如：

  ```js
  alert( "not a number" / 2 ); // NaN，这样的除法是错误的
  ```

  `NaN` 是粘性的。任何对 `NaN` 的进一步操作都会返回 `NaN`：

  ```js
  alert( "not a number" / 2 + 5 ); // NaN
  ```

  所以，如果在数学表达式中有一个 `NaN`，会被传播到最终结果。

> NaN * Infinity = NaN

---

**数学运算是安全的**

在 JavaScript 中做数学运算是安全的。我们可以做任何事：除以 0，将非数字字符串视为数字，等等。

脚本永远不会因为一个致命的错误（“死亡”）而停止。最坏的情况下，我们会得到 `NaN` 的结果。

特殊的数值属于 “number” 类型。当然，对“特殊的数值”这个词的一般认识是，它们并不是数字。

---

**数值类型的几种写法：**

```js
let n3 = 2e5;
document.write(n3, `<br>`); // 200000
n3 = 2E5;
document.write(n3, `<br>`); // 200000
let n5 = 0x100;  // 十六进制
document.write(n5, `<br>`); // 256
n5 = 0o100;  // 八进制
document.write(n5, `<br>`); // 64
n5 = 0b100;  // 二进制
document.write(n5, `<br>`); // 4
```

### bigint 类型

```js
// 尾部的 "n" 表示这是一个 BigInt 类型
const bigInt = 1234567890123456789012345678901234567890n;
document.write(typeof(bigInt));  // bigint
alert(bigInt);
// 尾部不写 "n" 就会转换为 浮点数
const Float = 1234567890123456789012345678901234567890;
alert(Float);
```

### string 类型

在 JavaScript 中，有三种包含字符串的方式。

1. 双引号：`"Hello"`.
2. 单引号：`'Hello'`.
3. 反引号：``Hello``  (MarkDown中不好显示).

双引号和单引号都是“简单”引用，在 JavaScript 中两者几乎没有什么差别。

反引号是 **功能扩展** 引号。它们允许我们通过将变量和表达式包装在 `${…}` 中，来将它们嵌入到字符串中。例如：

```js
let name = "John";
// 嵌入一个变量
alert( `Hello, ${name}!` ); // Hello, John!
// 嵌入一个表达式
alert( `the result is ${1 + 2}` ); // the result is 3
```

需要注意的是，这仅仅在反引号内有效，其他引号不允许这种嵌入。

在 JavaScript 中没有`char`这种类型。只有一种 `string` 类型，一个字符串可以包含一个或多个字符。

### boolean 类型

boolean 类型仅包含两个值：`true` 和 `false`。

布尔值也可作为比较的结果：

```js
let isGreater = 4 > 1;
alert( isGreater ); // true（比较的结果是 "yes"）
```

### null 值

它构成了一个独立的类型，只包含 `null` 值：

```js
let age = null;
document.write(typeof(age), `<br>`);    // object
document.write(age, `<br>`);    // null
```

相比较于其他编程语言，JavaScript 中的 `null` 不是一个“对不存在的 `object` 的引用”或者 “null 指针”。

JavaScript 中的 `null` 仅仅是一个代表“无”、“空”或“值未知”的特殊值。

上面的代码表示，由于某些原因，`age` 是未知或空的。

### undefined 值

特殊值 `undefined` 和 `null` 一样自成类型。

`undefined` 的含义是 `未被赋值`。

如果一个变量已被声明，但未被赋值，那么它的值就是 `undefined`：

```js
let age;
document.write(typeof(age), `<br>`);    // undefined
document.write(age, `<br>`);    // undefined
```

---

原理上来说，可以为任何变量赋值为 `undefined`：

```js
let x = 123;
x = undefined;
alert(x); // "undefined"
```

但是不建议这样做。通常，使用使用 `null` 将一个“空”或者“未知”的值写入变量中，`undefined` 仅仅用于检验，例如查看变量是否被赋值或者其他类似的操作

### object 类型和 symbol 类型

`object` 类型是一个特殊的类型。

其他所有的数据类型都被称为“原生类型”，因为它们的值只包含一个单独的内容（字符串、数字或者其他）。相反，`object` 则用于储存数据集合和更复杂的实体。

`symbol` 类型用于创建对象的唯一标识符。我们在这里提到 `symbol` 类型是为了学习的完整性，但我们会在学完 `object` 类型后再学习它。

### typeof 运算符

`typeof` 运算符返回参数的类型。当我们想要分别处理不同类型值的时候，或者想快速进行数据类型检验时，非常有用。

它支持两种语法形式：

1. 作为运算符：`typeof x`。
2. 函数形式：`typeof(x)`。

换言之，有括号和没有括号，得到的结果是一样的。

对 `typeof x` 的调用会以字符串的形式返回数据类型：

```js
typeof undefined // "undefined"
typeof 0 // "number"
typeof 10n // "bigint"
typeof true // "boolean"
typeof "foo" // "string"
typeof Symbol("id") // "symbol"
typeof Math // "object"  (1)
typeof null // "object"  (2)
typeof alert // "function"  (3)
```

最后三行可能需要额外的说明：

1. `Math` 是一个提供数学运算的内建 `object`。我们会在 [数字类型](https://www.bookstack.cn/read/zh.javascript.info/d4cff18c0c66067a.md) 一节中学习它。此处仅作为一个 `object` 的示例。
2. `typeof null` 的结果是 `"object"`。这其实是不对的。官方也承认了这是 `typeof` 运算符的问题，现在只是为了兼容性而保留了下来。当然，`null` 不是一个 `object`。`null` 有自己的类型，它是一个特殊值。再次强调，这是 JavaScript 语言的一个错误。
3. `typeof alert` 的结果是 `"function"`，因为 `alert` 在 JavaScript 语言中是一个函数。我们会在下一章学习函数，那时我们会了解到，在 JavaScript 语言中没有一个特别的 “function” 类型。函数隶属于 `object` 类型。但是 `typeof` 会对函数区分对待。这不是很正确的做法，但在实际编程中非常方便。



# JavaScript BOM 操作

一整套操作浏览器相关内容的属性和方法：

- 操作浏览器历史记录
- 操作浏览器滚动条
- 操作浏览器页面跳转
- 操作浏览器标签页的开启和关闭
- ···

## 可视化窗口尺寸

获取可视窗口宽度：`console.log(window.innerWidth)`

获取可视窗口高度：`console.log(window.innerHeight)`

## 浏览器弹出层

```html
<script>
    window.alert('提示框');
    window.confirm('询问框');
    window.prompt('输入框');
</script>
```

### 输入框的返回值

点击取消：返回 `null`；其余均返回字符串

## 开启/关闭 标签页

`window.open(url) ` : 开启新的标签页

`window.close()` : 关闭当前标签页

## 浏览器常见事件

`window.onload = function() {}` : 资源加载完毕

`window.onresize = function() {}` : 可视尺寸改变

`window.onscroll = function() {}` : 滚动条位置改变

## 浏览器的历史操作记录

`window.history.back()` : 回退页面

`window.history.forward()` : 前进页面

## 浏览器卷去的尺寸

卷去的高度: `document.documentElement.scrollTop || document.body.scrollTop`

卷去的宽度: `document.documentElement.scrollLeft || document.body.scrollLeft`

## 浏览器滚动到

设置浏览器滚动条的位置

## 定时器

### 间隔定时器

按照指定周期（毫秒）去执行代码

`setInterval(函数, 时间)`

```javascript
setInterval(function(){
}, 5000);
```

### 延时定时器

在固定的时间（毫秒）后执行一次代码

`setTimeout(函数, 时间)`

```javascript
setTimeout(function(){
}, 5000);
```

# JavaScript DOM 操作

## 获取元素

- **根据 id 名称获取**

  `document.getElementById('id名称');`

  返回值：如果有，就返回这个元素；没有则返回 null。

  ```javascript
  ele = document.getElementById('id名称');
  // ele 为 null 时;
  if (!ele) {  // 判定为真
      ... 
  }
  if (ele==null) { // 判定为真
      ... 
  }
  ```

- **根据元素 类名 获取**

  `document.getElementsByClassName('类名');`

  获取一个伪数组

  ```javascript
  let eles = document.getElementsByClassName('box1');
  // eles 为空的伪数组时
  if (eles.length == 0) { // 判定为真
      ... 
  }

- **根据元素 标签名 获取**

  `document.getElementsByTagName('类名');`

- **根据 选择器 获取一个**

  `documnet.querySelector('选择器');`

  返回值：如果有，只返回第一个匹配的；没有则返回 null。

- **根据 选择器 获取一组**

  `documnet.querySelectorAll('选择器');`

## 操作元素内容

### 操作元素文本内容

获取：`元素.innerText`

设置：`元素.innerText = '新内容'`

案例：

```html
<body>
    <button>操作内容</button>
    <div>
        <p>文本内容</p>
    </div>
    <script>
        // 获取元素
        let ele = document.querySelector('div');
        let btn = document.querySelector('button');
        
        // 获取元素的文本内容
        console.log(ele.innerText);

        // 给按钮绑定点击事件
        btn.onclick = function () {
            // 设置 div 内的文本内容
            ele.innerText = '<span>新内容</span>';
        }
    </script>
</body>
```

点击 button 后，div 内的内容会被完全覆盖，标签会被解析为本文，不会被渲染。

### 操作元素超文本内容

获取：`元素.innerHTML`

设置：`元素.innerHTML = '新内容'`

```html
<body>
    <button>操作内容</button>
    <div>
        <p>文本内容</p>
    </div>
    <script>
        // 获取元素
        let ele = document.querySelector('div');
        let btn = document.querySelector('button');
        
        // 获取元素的超文本内容
        console.log(ele.innerHTML);

        // 给按钮绑定点击事件
        btn.onclick = function () {
            // 设置 div 内的文本内容
            ele.innerHTML = '<span>新内容</span>';
        }
    </script>
</body>
```

这个案例就会将标签渲染出来

## 操作元素属性

以下方法均不用来操作 元素类名 和 样式。

### 原生属性

获取：`元素.属性名`

设置：`元素.属性名 = '属性值'`

### 自定义属性

获取：`元素.getAttribute('属性名')`

设置：`元素.setAttribute('属性名', '属性值')`

删除：`元素.removeAttribute('属性名')`

## 操作元素类名

获取：`元素.className`

设置：`元素.className = '新类名'`

## 操作元素行内样式

获取：`元素.style.样式名`

设置：`元素.style.样式名 = '样式值'`

当遇到带连接符的样式属性时( `background-color`)， JavaScript 中的 样式名 就要更换成 驼峰命名法（`backgroundColor`）。

```html
<body>
    <button>操作样式</button>
    <div style="width:100px; height:100px; background-color:pink;">文本内容</div>
    <script>
        // 获取元素
        let box = document.querySelector('div');
        let btn = document.querySelector('button');

        // 获取样式
        console.log(box.style.width);
        console.log(box.style.height);
        console.log(box.style.backgroundColor);

        // 设置样式
        btn.onclick = function () {
            box.style.width = '200px';
            box.style.height = '200px';
            box.style.backgroundColor = 'skyblue';
        }
    </script>
</body>
```

## 获取元素非行内样式

获取：`window.getComputedStyle(元素).样式名` （行内样式与非行内样式均可获取）

> JavaScript 不能设置元素的非行内样式

# 判断字符串是否包含另一个字符串的方法

- **str1.indexOf(str2)**

```javascript
let str = "123";
console.log(str.indexOf("2") != -1); // true
```

indexOf() 方法可返回某个指定的字符串值在字符串中首次出现的位置。如果要检索的字符串值没有出现，则该方法返回 -1。

- **str1.match(str2)**

- **str1.search(str2)**

search() 方法用于检索字符串中指定的子字符串，或检索与正则表达式相匹配的子字符串。如果没有找到任何匹配的子串，则返回 -1。
