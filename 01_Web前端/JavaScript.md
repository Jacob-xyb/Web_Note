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
document.write(typeof(age), `<br>`);    // object // 这是 JavaScript 语言的一个错误
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
2. `typeof null` 的结果是 `"object"`。这其实是不对的。官方也承认了这是 `typeof` 运算符的问题，现在只是为了兼容性而保留了下来。当然，`null` 不是一个 `object`。`null` 有自己的类型，它是一个特殊值。**再次强调，这是 JavaScript 语言的一个错误。**
3. `typeof alert` 的结果是 `"function"`，因为 `alert` 在 JavaScript 语言中是一个函数。我们会在下一章学习函数，那时我们会了解到，在 JavaScript 语言中没有一个特别的 “function” 类型。函数隶属于 `object` 类型。但是 `typeof` 会对函数区分对待。这不是很正确的做法，但在实际编程中非常方便。

## 类型转换

大多数情况下，运算符和函数会自动将赋予他们的值转换为正确的类型。

比如，`alert` 会自动将任何值都转换为字符串以进行显示。算术运算符会将值转换为数字。

在某些情况下，我们需要将值显式地转换为我们期望的类型。

### 转为 字符串

#### String(value)

`String(value)` 显示转换

```js
let value1 = true;
document.write(String(value1));
document.write(`<br>`);
value1 = null;
document.write(String(value1));
document.write(`<br>`);
```

#### value.toString()

虽然语法类似，但是原理不同

```js
let value1 = true;
document.write(String(value1));
document.write(`<br>`);
document.write(value1.toString());
document.write(`<br>`);
value1 = null;
document.write(String(value1));
document.write(`<br>`);
document.write(value1.toString());  // 报错
document.write(`<br>`);
```

**数字**转字符串加参数的话，可以转为对应的**进制数**：

```js
let value;
value = 100;
document.write(value.toString());  // 100
document.write(`<br>`);
document.write(value.toString(2));  // 1100100
document.write(`<br>`);
document.write(value.toString(8));  // 144
document.write(`<br>`);
document.write(value.toString(16));  // 64
document.write(`<br>`);
```

### 转为 数字

#### Number()

我们也可以使用 `Number(value)` 显式地将这个 `value` 转换为 number 类型。

**number 类型转换规则：**

| 值              | 变成……                                                       |
| :-------------- | :----------------------------------------------------------- |
| `undefined`     | `NaN`                                                        |
| `null`          | `0`                                                          |
| `true 和 false` | `1` and `0`                                                  |
| `string`        | 去掉首尾空格后的纯数字字符串中含有的数字。如果剩余字符串为空，则转换结果为 `0`。否则，将会从剩余字符串中“读取”数字。当类型转换出现 error 时返回 `NaN`。 |

```js
let value1 = '123';
document.write(Number(value1));  // 123
document.write(`<br>`);
value1 = '  123  ';
document.write(Number(value1));  // 123
document.write(`<br>`);
value1 = '123+1';
document.write(Number(value1));  // NaN
document.write(`<br>`);
value1 = true;
document.write(Number(value1));  // 1
document.write(`<br>`);
value1 = false;
document.write(Number(value1));  // 0
document.write(`<br>`);
value1 = 'undefined';
document.write(Number(value1));  // NaN
document.write(`<br>`);
value1 = undefined;
document.write(Number(value1));  // NaN
document.write(`<br>`);
value1 = null;
document.write(Number(value1));  // 0
document.write(`<br>`);
value1 = NaN;
document.write(Number(value1));  // NaN
document.write(`<br>`);
```

#### parseInt()

`parseInt()` 原理是逐字符转换，只有第一位不是数字的时候返回NaN，否则保留前面的数字位置内容。

```js
let value1 = 123.38;
document.write(parseInt(value1));  // 123
document.write(`<br>`);
value1 = '123';
document.write(parseInt(value1));  // 123
document.write(`<br>`);
value1 = '  123  ';
document.write(parseInt(value1));  // 123
document.write(`<br>`);
value1 = '123+1';
document.write(parseInt(value1));  // 123
document.write(`<br>`);
value1 = '123.1';
document.write(parseInt(value1));  // 123
document.write(`<br>`);
value1 = 'x123.1';
document.write(parseInt(value1));  // NaN
document.write(`<br>`);
```

对于科学计数法，猜测是先展开再判断

```js
let value1 = 1e2;
document.write(parseInt(value1));  // 100
document.write(`<br>`);
```

#### parseFloat()

parseFloat() 规则和 parseInt() 类似，只是会解析小数点

#### 自动进行 Number 转换

在算术函数和表达式中，会自动进行 number 类型转换。

比如，当把除法 `/` 用于非 number 类型：

```js
alert( "6" / "2" ); // 3, string 类型的值被自动转换成 number 类型后进行计算
```

### 转为 布尔

布尔（boolean）类型转换是最简单的一个。

它发生在逻辑运算中（稍后我们将进行条件判断和其他类似的东西），但是也可以通过调用 `Boolean(value)`显式地进行转换。

转换规则如下：

- 直观上为“空”的值（如 `0`、空字符串、`null`、`undefined` 和 `NaN`）将变为 `false`。
- 其他值变成 `true`。

| 值                                    | 变成……  |
| :------------------------------------ | :------ |
| `0`, `null`, `undefined`, `NaN`, `""` | `false` |
| 其他值                                | `true`  |

## 运算符

### 运算符相关术语

- **运算元** —— 运算符应用的对象。比如说乘法运算 `5 * 2`，有两个运算元：左运算元 `5` 和右运算元 `2`。有时候人们也称其为“参数”而不是“运算元”。

- 如果一个运算符对应的只有一个运算元，那么它是 **一元运算符**。比如说一元负号运算符（unary negation）`-`，它的作用是对数字进行正负转换：

  ```js
  let x = 1;
  x = -x;
  alert( x ); // -1，一元负号运算符生效
  ```

- 如果一个运算符拥有两个运算元，那么它是 **二元运算符**。减号还存在二元运算符形式

  ```js
  let x = 1, y = 3;
  alert( y - x ); // 2，二元运算符减号做减运算
  ```

###  + 运算符

#### + 一元运算符

一元运算符加号，或者说，加号 `+` 应用于单个值，对数字没有任何作用。但是如果运算元不是数字，加号 `+` 则会将其转化为数字。

例如：

```js
// 对数字无效
let x = 1;
alert( +x ); // 1
let y = -2;
alert( +y ); // -2
// 转化非数字
alert( +true ); // 1
alert( +"" );   // 0
```

它的效果和 `Number(...)` 相同，但是更加简短。

#### + 二元运算符

进行加法运算：

- 当符号两边都是数字或者布尔的时候，会进行数学运算
- 只有符号任意一边是字符串的时候，就会进行字符串拼接

```js
let value1, value2;
value1 = 10;
value2 = 20
document.write(value1 + value2);  // 30
document.write(`<br>`);
// 当有任意一边是字符串时，就会进行字符串拼接
value2 = '20';
document.write(value1 + value2);  // 1020
document.write(`<br>`);
document.write(value2 + value1);  // 2010
document.write(`<br>`);
```

如果想让两个字符串做数学运算，就都用 +一元运算符进行转换即可：

```js
let apples = "2";
let oranges = "3";
// 在二元运算符加号起作用之前，所有的值都被转化为了数字
alert( +apples + +oranges ); // 5
// 更长的写法
// alert( Number(apples) + Number(oranges) ); // 5
```

### 其他数学运算符

`-` 、`*` 、`/` 、`%` 只能进行数学运算

### 运算符优先级

如果一个表达式拥有超过一个运算符，执行的顺序则由 **优先级** 决定。换句话说，所有的运算符中都隐含着优先级顺序。

圆括号拥有最高优先级，所以如果我们对现有的运算顺序不满意，我们可以使用圆括号来修改运算顺序，就像这样：`(1 + 2) * 2`。

在 JavaScript 中有众多运算符。每个运算符都有对应的优先级数字。数字越大，越先执行。如果优先级相同，则按照由左至右的顺序执行。

这是一个摘抄自 Mozilla 的 [优先级表](https://developer.mozilla.org/en/JavaScript/Reference/operators/operator_precedence)（你没有必要把这全记住，但要记住一元运算符优先级高于二元运算符）：

| 优先级 | 名称     | 符号 |
| :----- | :------- | :--- |
| …      | …        | …    |
| 17     | 一元加号 | `+`  |
| 17     | 一元负号 | `-`  |
| 15     | 乘号     | `*`  |
| 15     | 除号     | `/`  |
| 13     | 加号     | `+`  |
| 13     | 减号     | `-`  |
| …      | …        | …    |
| 3      | 赋值符   | `=`  |
| …      | …        | …    |

### = 赋值运算符

我们知道赋值符号 `=` 也是一个运算符。从优先级表中可以看到它的优先级非常低，只有 `3`。

这也是为什么，当我们赋值时，比如 `x = 2 * 2 + 1`，所有的计算先执行，然后 `=` 才执行，将计算结果存储到 `x`。

```js
let x = 2 * 2 + 1;
alert( x ); // 5
```

链式赋值也是可以的：

```js
let a, b, c;
a = b = c = 2 + 2;
document.write(`${a}, ${b}, ${c}`);  // 4, 4, 4
document.write(`<br>`);
a = 2;
document.write(`${a}, ${b}, ${c}`);  // 2, 4, 4
document.write(`<br>`);  
```

数字肯定不会共享一个值，但是列表或者对象就不确定了，所以链式赋值不推荐使用。

---

**赋值运算符 `"="` 会返回一个值**

每个运算符都有一个返回值。对于以加号 `+` 或者乘号 `*` 为例的大部分运算符而言，这一点很显然。对于赋值运算符而言，这一点同样适用。

语句 `x = value` 把 `value` 的值写入 `x` **然后返回 x**。

下面是一个在复杂语句中使用赋值的例子：

```js
let a = 1;
let b = 2;
let c = 3 - (a = b + 1);
alert( a ); // 3
alert( c ); // 0
```

也不推荐。

### ** 幂运算符

幂运算符 `**` 是最近被加入到 JavaScript 中的。

对于自然数 `b`，`a ** b` 的结果是 `a` 与自己相乘 `b` 次，整数非整数均适用。

```js
document.write(`2 ** 2 = ${2 ** 2}`);  // 4
document.write(`<br>`);
document.write(`2 ** 0.5 = ${2 ** 0.5}`);  // 1.4142135623730951
document.write(`<br>`);
```

### 自增/自减

- **自增** `++` 将变量与 1 相加：

  ```js
  let counter = 2;counter++;      // 和 counter = counter + 1 效果一样，但是更简洁alert( counter ); // 3
  ```

- **自减** `--` 将变量与 1 相减：

  ```js
  let counter = 2;counter--;      // 和 counter = counter - 1 效果一样，但是更简洁alert( counter ); // 1
  ```

重要：

自增/自减只能应用于变量。试一下，将其应用于数值（比如 `5++`）则会报错。

运算符 `++` 和 `--` 可以置于变量前，也可以置于变量后。

- 当运算符置于变量后，被称为“后置形式”：`counter++`。
- 当运算符置于变量前，被称为“前置形式”：`++counter`。

所有的运算符都有返回值。自增/自减也不例外。**前置形式返回一个新的值，但后置返回原来的值（做加法/减法之前的值）。**

```js
let counter, a, b;
counter = 1;
a = counter++;
counter = 1;
b = ++counter;
document.write(`${a},${b}`);  // 1, 2
document.write(`<br>`);
```

---

自增/自减和其它运算符的对比

`++/--` 运算符同样可以在表达式内部使用。它们的优先级比绝大部分的算数运算符要高。

```js
let counter = 1;
alert( 2 * ++counter ); // 4
```

### 位运算符

位运算符把运算元当做 32 位整数，并在它们的二进制表现形式上操作。

这些运算符不是 JavaScript 特有的。大部分的编程语言都支持这些运算符。

下面是位运算符：

- 按位与 ( `&` )
- 按位或 ( `|` )
- 按位异或 ( `^` )
- 按位非 ( `~` )
- 左移 ( `<<` )
- 右移 ( `>>` )
- 无符号右移 ( `>>>` )

这些操作使用得非常少。为了理解它们，我们需要探讨底层的数字表达形式，现在不是做这个的最好时机。尤其是我们现在不会立刻使用它。如果你感兴趣，可以阅读 MDN 中的 [位运算符](https://developer.mozilla.org/en/docs/Web/JavaScript/Reference/Operators/Bitwise_Operators) 相关文章。当有相关实际需求的时候再去阅读是更明智的选择。

### ，逗号运算符

逗号运算符 `,` 是最少见最不常使用的运算符之一。有时候它会被用来写更简短的代码，因此为了能够理解代码，我们需要了解它。

逗号运算符能让我们处理多个语句，使用 `,` 将它们分开。每个语句都运行了，但是只有最后的语句的结果会被返回。

举个例子：

```js
let a = (1 + 2, 3 + 4);alert( a ); // 7（3 + 4 的结果）
```

这里，第一个语句 `1 + 2` 运行了，但是它的结果被丢弃了。随后计算 `3 + 4`，并且该计算结果被返回。

逗号运算符的优先级非常低

请注意逗号运算符的优先级非常低，比 `=` 还要低，因此上面你的例子中圆括号非常重要。

如果没有圆括号：`a = 1 + 2, 3 + 4` 会先执行 `+`，将数值相加得到 `a = 3, 7`，然后赋值运算符 `=` 执行, ‘a = 3’，然后逗号之后的数值 `7` 不会再执行，它被忽略掉了。相当于 `(a = 1 + 2), 3 + 4`。

为什么我们需要这样一个运算符，它只返回最后一个值呢？

有时候，人们会使用它把几个行为放在一行上来进行复杂的运算。

举个例子：

```js
// 一行上有三个运算符for (a = 1, b = 3, c = a * b; a < 10; a++) { ...}
```

这样的技巧在许多 JavaScript 框架中都有使用，这也是为什么我们提到它。但是通常它并不能提升代码的可读性，使用它之前，我们要想清楚。

## 值的比较

**比较结果为 Boolean 类型**、

在数学中有很多用于比较大小的运算符：

- 大于 / 小于：`a > b`，`a < b`。
- 大于等于 / 小于等于：`a >= b`，`a <= b`。
- 检查两个值的相等：`a == b`（注意表达式中是两个等号 `=`，若写为单个等号 `a = b` 则表示赋值）。
- 检查两个值不相等，在数学中使用 `≠` 符号，而在 JavaScript 中则通过在赋值符号前加叹号表示：`a != b`。

### 字符串比较

在比较字符串的大小时，JavaScript 会使用“字典（dictionary）”或“词典（lexicographical）”顺序进行判定。

换言之，字符串是按字符（母）逐个进行比较的

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
