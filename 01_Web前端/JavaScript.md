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

换言之，字符串是按字符（母）逐个进行比较的：

字符串的比较算法非常简单：

1. 首先比较两个字符串的首位字符大小。
2. 如果一方字符较大（或较小），则该字符串大于（或小于）另一个字符串。算法结束。
3. 否则，如果两个字符串的首位字符相等，则继续取出两个字符串各自的后一位字符进行比较。
4. 重复上述步骤进行比较，直到比较完成某字符串的所有字符为止。
5. 如果两个字符串的字符同时用完，那么则判定它们相等，否则未结束（还有未比较的字符）的字符串更大。

```js
document.write(`'Z' > 'A': ${'Z' > 'A'}`); // true
document.write(`<br>`);
document.write(`'a' > 'A': ${'Z' > 'A'}`); // true
document.write(`<br>`);
document.write(`'Glow' > 'Glee': ${'Glow' > 'Glee'}`); // true
document.write(`<br>`);
document.write(`'Bee' > 'Be': ${'Bee' > 'Be'}`); // true
document.write(`<br>`);
```

### 不同类型间的比较

当对不同类型的值进行比较时，JavaScript 会首先将其转化为数字（number）再判定大小。

```js
document.write(`'2' > 1: ${'2' > 1}`); // true
document.write(`<br>`);
document.write(`'01' == '1': ${'01' == 1}`); // true
document.write(`<br>`);
```

对于布尔类型值，`true` 会被转化为 `1`、`false` 转化为 `0`。

### 严格相等

普通的相等性检查 `==` 存在一个问题，它不能区分出 `0` 和 `false`：

```js
alert( 0 == false ); // true
```

也同样无法区分空字符串和 `false`：

```js
alert( '' == false ); // true
```

这是因为在比较不同类型的值时，处于相等判断符号 `==` 两侧的值会先被转化为数字。空字符串和 `false` 也是如此，转化后它们都为数字 0。

如果我们需要区分 `0` 和 `false`，该怎么办？

**严格相等运算符 `===` 在进行比较时不会做任何的类型转换。**

换句话说，如果 `a` 和 `b` 属于不同的数据类型，那么 `a === b` 不会做任何的类型转换而立刻返回 `false`。

```js
alert( 0 === false ); // false，因为被比较值的数据类型不同
```

同样的，与“不相等”符号 `!=` 类似，“严格不相等”表示为 `!==`。

严格相等的运算符虽然写起来稍微长一些，但是它能够很清楚地显示代码意图，降低你犯错的可能性。

### 对 null 和 undefined 进行比较

当使用 `null` 或 `undefined` 与其他值进行比较时，其返回结果常常出乎你的意料。

当使用严格相等 `===` 比较二者时

它们不相等，因为它们属于不同的类型。

```js
alert( null === undefined ); // false
```

当使用非严格相等 `==` 比较二者时

JavaScript 存在一个特殊的规则，会判定它们相等。他们俩就像“一对恋人”，仅仅等于对方而不等于其他任何的值（只在非严格相等下成立）。

```js
alert( null == undefined ); // true
```

当使用数学式或其他比较方法 `< > <= >=` 时：

`null/undefined` 会被转化为数字：`null` 被转化为 `0`，`undefined` 被转化为 `NaN`。

下面让我们看看，这些规则会带来什么有趣的现象。同时更重要的是，我们需要从中学会如何远离这些特性带来的“陷阱”。

#### 奇怪的结果：null vs 0

通过比较 `null` 和 0 可得：

```js
alert( null > 0 );  // (1) 
falsealert( null == 0 ); // (2) 
falsealert( null >= 0 ); // (3) true
```

是的，上面的结果完全打破了你对数学的认识。在最后一行代码显示“`null` 大于等于 0”的情况下，前两行代码中一定会有一个是正确的，然而事实表明它们的结果都是 false。

为什么会出现这种反常结果，这是因为相等性检查 `==` 和普通比较符 `> < >= <=` 的代码逻辑是相互独立的。进行值的比较时，`null` 会被转化为数字，因此它被转化为了 `0`。这就是为什么（3）中 `null >= 0` 返回值是 true，（1）中 `null > 0` 返回值是 false。

另一方面，`undefined` 和 `null` 在相等性检查 `==` 中不会进行任何的类型转换，它们有自己独立的比较规则，所以除了它们之间互等外，不会等于任何其他的值。这就解释了为什么（2）中 `null == 0` 会返回 false。

#### 特立独行的 undefined

`undefined` 不应该被与其他值进行比较：

```js
alert( undefined > 0 ); // false (1)
alert( undefined < 0 ); // false (2)
alert( undefined == 0 ); // false (3)
```

为何它看起来如此厌恶 0？返回值都是 false！

原因如下：

- `(1)` 和 `(2)` 都返回 `false` 是因为 `undefined` 在比较中被转换为了 `NaN`，而 `NaN` 是一个特殊的数值型值，它与任何值进行比较都会返回 `false`。
- `(3)` 返回 `false` 是因为这是一个相等性检查，而 `undefined` 只与 `null` 相等，不会与其他值相等。

#### 规避错误

我们为何要研究上述示例？我们需要时刻记得这些古怪的规则吗？不，其实不需要。虽然随着代码写得越来越多，我们对这些规则也都会烂熟于胸，但是我们需要更为可靠的方法来避免潜在的问题：

除了严格相等 `===` 外，其他凡是有 `undefined/null` 参与的比较，我们都需要额外小心。

除非你非常清楚自己在做什么，否则永远不要使用 `>= > < <=` 去比较一个可能为 `null/undefined` 的变量。对于取值可能是 `null/undefined` 的变量，请按需要分别检查它的取值情况。

## 交互

### alert

语法：

```js
alert(message);
```

运行这行代码，浏览器会弹出一个信息弹窗并暂停脚本，直到用户点击了“确定”。

举个例子：

```js
alert("Hello");
```

弹出的这个带有信息的小窗口被称为 **模态窗**。“modal” 意味着用户不能与页面的其他部分（例如点击其他按钮等）进行交互，直到他们处理完窗口。在上面示例这种情况下 —— 直到用户点击“确定”按钮。

### prompt

`prompt` 函数接收两个参数：

```js
result = prompt(title, [default]);
```

浏览器会显示一个带有文本消息的模态窗口，还有 input 框和确定/取消按钮。

`title`: 显示给用户的文本

`default`: 可选的第二个参数，指定 input 框的初始值。

用户可以在 prompt 对话框的 input 框内输入一些内容，然后点击确定。或者他们可以通过按“取消”按钮或按下键盘的 Esc 键，以取消输入。

`prompt` 将返回用户在 `input` 框内输入的文本，如果用户取消了输入，则返回 `null`。

举个例子：

```js
let age = prompt('How old are you?', 100);
alert(`You are ${age} years old!`); // You are 100 years old!
```

IE 浏览器会提供默认值

第二个参数是可选的。但是如果我们不提供的话，Internet Explorer 会把 `"undefined"` 插入到 prompt。

我们可以在 Internet Explorer 中运行下面这行代码来看看效果：

```js
let test = prompt("Test");
```

所以，为了 prompt 在 IE 中有好的效果，我们建议始终提供第二个参数：

```js
let test = prompt("Test", ''); // <-- for IE
```

### confirm

语法：

```js
result = confirm(question);
```

`confirm` 函数显示一个带有 `question` 以及确定和取消两个按钮的模态窗口。

点击确定返回 `true`，点击取消返回 `false`。

例如：

```js
let isBoss = confirm("Are you the boss?");
alert( isBoss ); // 如果“确定”按钮被按下，则显示 true
```

## 条件运算符

有时我们需要根据不同条件执行不同的操作。

我们可以使用 `if` 语句和条件运算符 `?`（也称为“问号”运算符）来实现。

### if 语句

`if(...)` 语句计算括号里的条件表达式，如果计算结果是 `true`，就会执行对应的代码块。

例如：

```js
let year = prompt('In which year was ECMAScript-2015 specification published?', '');
if (year == 2015) alert( 'You are right!' );
```

如果有多个语句要执行，我们必须将要执行的代码块封装在大括号内：

```js
if (year == 2015) {
  alert( "That's correct!" );
  alert( "You're so smart!" );
}
```

建议每次使用 if 语句都用大括号 `{}` 来包装代码块，即使只有一条语句。这样可以提高代码可读性。

### 布尔转换

`if (…)` 语句会计算圆括号内的表达式，并将计算结果转换为布尔型。

回顾一下转换规则：

- 数字 `0`、空字符串 `""`、`null`、`undefined` 和 `NaN` 都会被转换成 `false`。因为他们被称为 “falsy” 值。
- 其他值被转换为 `true`，所以它们被称为 “truthy”。

### else 语句

`if` 语句有时会包含一个可选的 “else” 块。如果判断条件不成立，就会执行它内部的代码。

```js
let year = prompt('In which year was ECMAScript-2015 specification published?', '');
if (year == 2015) {
  alert( 'You guessed it right!' );
} else {
  alert( 'How can you be so wrong?' ); // 2015 以外的任何值
}
```

### else if 语句

有时我们需要测试一个条件的几个变体。我们可以通过使用 `else if` 子句实现。

```js
let year = prompt('In which year was ECMAScript-2015 specification published?', '');
if (year < 2015) {
  alert( 'Too early...' );
} else if (year > 2015) {
  alert( 'Too late' );
} else {
  alert( 'Exactly!' );
}
```

### ? 条件运算符 

有时我们需要根据一个条件去赋值一个变量。

```js
let accessAllowed;
let age = prompt('How old are you?', '');
if (age > 18) {
  accessAllowed = true;
} else {
  accessAllowed = false;
}
alert(accessAllowed);
```

所谓的“条件”或“问号”运算符让我们可以更简短地达到目的。

这个运算符通过问号 `?` 表示。有时它被称为三元运算符，被称为“三元”是因为该运算符中有三个操作数。实际上它是 JavaScript 中唯一一个有这么多操作数的运算符。

语法：

```js
let result = condition ? value1 : value2;
```

计算条件结果，如果结果为真，则返回 `value1`，否则返回 `value2`。

例如：

```js
let accessAllowed = (age > 18) ? true : false;
```

技术上讲，我们可以省略 `age > 18` 外面的括号。问号运算符的优先级较低，所以它会在比较运算符 `>` 后执行。

**但括号可以使代码可读性更强，所以我们建议使用它们。**

请注意：

在上面的例子中，你可以不使用问号运算符，因为比较本身就返回 `true/false`：

```js
// 下面代码同样可以实现
let accessAllowed = age > 18;
```

### 多个 ?

使用一系列问号 `?` 运算符可以返回一个取决于多个条件的值。

```js
let age = prompt('age?', 18);
let message = (age < 3) ? 'Hi, baby!' :
  (age < 18) ? 'Hello!' :
  (age < 100) ? 'Greetings!' :
  'What an unusual age!';
alert( message );
```

可能很难一下子看出发生了什么。但经过仔细观察，我们可以看到它只是一个普通的检查序列。

1. 第一个问号检查 `age < 3`。
2. 如果为真 — 返回 `'Hi, baby!'`。否则，会继续执行冒号 `":"` 后的表达式，检查 `age < 18`。
3. 如果为真 — 返回 `'Hello!'`。否则，会继续执行下一个冒号 `":"` 后的表达式，检查 `age < 100`。
4. 如果为真 — 返回 `'Greetings!'`。否则，会继续执行最后一个冒号 `":"` 后面的表达式，返回 `'What an unusual age!'`。

**不推荐使用**

### ‘?’ 的非常规使用

有时可以使用问号 `?` 来代替 `if` 语句

```js
let company = prompt('Which company created JavaScript?', '');
(company == 'Netscape') ?
   alert('Right!') : alert('Wrong.');
```

根据条件 `company =='Netscape'`，要么执行 `?` 后面的第一个表达式并显示对应内容，要么执行第二个表达式并显示对应内容。

在这里我们不是把结果赋值给变量。而是根据条件执行不同的代码。

**不建议这样使用问号运算符。**

这种写法比 `if` 语句更短，对一些程序员很有吸引力。但它的可读性差。

## 逻辑运算符

JavaScript 里有三个逻辑运算符：`&&`（与），`||`（或），`!`（非）

虽然他们被称为“逻辑”运算符，但这些运算符却可以被应用于任意类型的值，而不仅仅是布尔值。他们的结果也同样可以是任意类型。

### &&（与）

两个 & 符号表示 `&&` 与操作：

```js
result = a && b;
```

传统的编程中，当两个操作数都是真值，与操作返回 `true`，否则返回 `false`：

```js
alert( true && true );   // true
alert( false && true );  // false
alert( true && false );  // false
alert( false && false ); // false
```

使用 if 语句：

```js
let hour = 12;
let minute = 30;
if (hour == 12 && minute == 30) {
  alert( 'Time is 12:30' );
}
```

#### 与运算的原理

```js
// 与运算会返回第一个假值，否则返回最后一个真值。
let result;
result = 1 && 0 && 2;
document.write(result);     // 0
document.write(`<br>`);
result = 1 && 10 && 2;
document.write(result);     // 2
document.write(`<br>`);        
```

与运算 `&&` 做了如下的事：

- 从左到右依次计算操作数。
- 将处理每一个操作数时，都将其转化为布尔值。如果结果是 `false`，就停止计算，并返回这个操作数的初始值。
- 如果所有的操作数都被计算过（也就是，转换结果都是 `true`），则返回最后一个操作数。

---

与运算 `&&` 在或运算符 `||` 之前执行

与运算 `&&` 的优先级比或运算 `||` 要高。

所以代码 `a && b || c && d` 完全跟 `&&` 表达式加了括号一样：`(a && b) || (c && d)`。

就像或运算一样，与运算 `&&` 有时候能够代替 `if`。

```js
let x = 1;
(x > 0) && alert( 'Greater than zero!' );
```

`&&` 右边的代码只有运算抵达到那里才能被执行。也就是，当且仅当 `(x > 0)` 返回了真值。

**带 `&&` 的代码变体看上去更短。但是 `if` 的含义更明显，可读性也更高。**

**所以建议是根据目的选择代码的结构。需要条件判断就用 `if`，需要与运算就用 `&&`。**

### ||（或）

两个竖线符号表示了“或”运算：

```js
result = a || b;
```

在传统的编程中，逻辑或仅能够操作布尔值。如果参与运算的任意一个参数为 `true`，返回的结果就为 `true`，否则返回 `false`。

在 JavaScript 中，逻辑运算符更加灵活强大。但是首先我们看一下操作数是布尔值的时候发生了什么。

大多数情况，逻辑或 `||` 会被用在 `if` 语句中，用来测试是否有 **任何** 给定的条件为 `true`。

```js
let hour = 9;
if (hour < 10 || hour > 18) {
  alert( 'The office is closed.' );
}
```

可以传入更多条件：

```js
let hour = 12;
let isWeekend = true;
if (hour < 10 || hour > 18 || isWeekend) {
  alert( 'The office is closed.' ); // 是周末
}
```

### !（非）

感叹符号 `!` 表示布尔非运算。

语法相当简单：

```js
result = !value;
```

运算符接受一个参数，并按如下运作：

1. 将操作数转化为布尔类型：`true/false`。
2. 返回相反的值。

例如：

```js
alert( !true ); // false
alert( !0 ); // true
```

两个非运算 `!!` 有时候用来将某个值转化为布尔类型：

```js
alert( !!"non-empty string" ); // true
alert( !!null ); // false
```

也就是，第一个非运算将该值转化为布尔类型并取反，第二个非运算再次取反。最后我们就得到了一个任意值到布尔值的转化。

有更多详细的方法可以完成同样的事 —— 一个内置的 `Boolean` 函数：

```
alert( Boolean("non-empty string") ); // truealert( Boolean(null) ); // false
```

非运算符 `!` 的优先级在所有逻辑运算符里面最高，所以它总是在 `&&` 和 `||` 前执行。

## 循环

### while 循环

`while` 循环的语法如下：

```js
while (condition) {
  // 代码
  // 所谓的“循环体”
}
```

当 `condition` 为 `true` 时，执行循环体的 `code`。

例如，以下将循环输出当 `i < 3` 时的 `i` 值：

```js
let i = 3;
while (i) { // 当 i 变成 0 时，条件为 false，循环终止
  alert( i );
  i--;
}
```

循环体的单次执行叫作 **一次迭代**。上面示例中的循环进行了三次迭代。

如果上述示例中没有 `i++`，那么循环（理论上）会永远重复执行下去。实际上，浏览器提供了阻止这种循环的方法，我们可以通过终止进程，来停掉服务器端的 JavaScript。

任何表达式或变量都可以是循环条件，而不仅仅是比较。在 `while` 中的循环条件会被计算，计算结果会被转化为布尔值。

例如，`while (i != 0)` 可简写为 `while (i)`：

```js
let i = 3;
while (i) { // 当 i 变成 0 时，条件为 false，循环终止
  alert( i );
  i--;
}
```

单行循环体不需要大括号

如果循环体只有一条语句，则可以省略大括号 `{…}`：

```js
let i = 3;
while (i) alert(i--);
```

### do…while 循环

使用 `do..while` 语法可以将条件检查移至循环体 **下面**：

```js
do {
  // 循环体
} while (condition);
```

循环首先执行循环体，然后检查条件，当条件为真时，重复执行循环体。

### for 循环

`for` 循环更加复杂，但它是最常使用的循环形式。

`for` 循环看起来就像这样：

```js
for (begin; condition; step) {
  // ……循环体……
}
```

我们逐个部分分析 `for` 循环：

| 语句段         |            |                                                  |
| :------------- | :--------- | :----------------------------------------------- |
| begin          | `i = 0`    | 进入循环时执行一次。                             |
| condition      | `i < 3`    | 在每次循环迭代之前检查，如果为 false，停止循环。 |
| body（循环体） | `alert(i)` | 条件为真时，重复运行。                           |
| step           | `i++`      | 在每次循环体迭代后执行。                         |

**内联变量声明**

这里“计数”变量 `i` 是在循环中声明的。这叫做“内联”变量声明。这样的变量只在循环中可见。

```js
for (let i = 0; i < 3; i++) {
  alert(i); // 0, 1, 2
}
alert(i); // 错误，没有这个变量。
```

除了定义一个变量，我们也可以使用现有的变量：

```js
let i = 0;
for (i = 0; i < 3; i++) { // 使用现有的变量
  alert(i); // 0, 1, 2
}
alert(i); //3，可见，因为是在循环之外声明的
```

**省略语句段**

`for` 循环的任何语句段都可以被省略。

例如，如果我们在循环开始时不需要做任何事，我们就可以省略 `begin` 语句段。

就像这样：

```js
let i = 0; // 我们已经声明了 i 并对它进行了赋值
for (; i < 3; i++) { // 不再需要 "begin" 语句段
  alert( i ); // 0, 1, 2
}
```

我们也可以移除 `step` 语句段：

```js
let i = 0;
for (; i < 3;) {
  alert( i++ );
}
```

该循环与 `while (i < 3)` 等价。

实际上我们可以删除所有内容，从而创建一个无限循环：

```js
for (;;) {
  // 无限循环
}
```

请注意 `for` 的两个 `;` 必须存在，否则会出现语法错误。

### break 跳出循环

通常条件为假时，循环会终止。

但我们随时都可以使用 `break` 指令强制退出。

例如，下面这个循环要求用户输入一系列数字，在输入的内容不是数字时“终止”循环。

```js
let sum = 0;
while (true) {
  let value = +prompt("Enter a number", '');
  if (!value) break; // (*)
  sum += value;
}
alert( 'Sum: ' + sum );
```

如果用户输入空行或取消输入，在 `(*)` 行的 `break` 指令会被激活。它立刻终止循环，将控制权传递给循环后的第一行，即，`alert`。

根据需要，”无限循环 + `break`“ 的组合非常适用于不必在循环开始/结束时检查条件，但需要在中间甚至是主体的多个位置进行条件检查的情况。

### continue 继续下一次迭代

`continue` 指令是 `break` 的“轻量版”。它不会停掉整个循环。而是停止当前这一次迭代，并强制启动新一轮循环（如果条件允许的话）。

如果我们完成了当前的迭代，并且希望继续执行下一次迭代，我们就可以使用它。

下面这个循环使用 `continue` 来只输出奇数：

```js
for (let i = 0; i < 10; i++) {
  //如果为真，跳过循环体的剩余部分。
  if (i % 2 == 0) continue;
  alert(i); // 1，然后 3，5，7，9
}
```

对于偶数的 `i` 值，`continue` 指令会停止本次循环的继续执行，将控制权传递给下一次 `for` 循环的迭代（使用下一个数字）。因此 `alert` 仅被奇数值调用。

`continue` 指令利于减少嵌套

显示奇数的循环可以像下面这样：

```js
for (let i = 0; i < 10; i++) {
  if (i % 2) {
    alert( i );
  }
}
```

从技术角度看，它与上一个示例完全相同。当然，我们可以将代码包装在 `if` 块而不使用 `continue`。

但在副作用方面，它多创建了一层嵌套（大括号内的 `alert` 调用）。如果 `if` 中代码有多行，则可能会降低代码整体的可读性。

禁止 `break/continue` 在 ‘?’ 的右边

请注意非表达式的语法结构不能与三元运算符 `?` 一起使用。特别是 `break/continue` 这样的指令是不允许这样使用的。

例如，我们使用如下代码：

```js
if (i > 5) {
  alert(i);
} else {
  continue;
}
```

……用问号重写：

```js
(i > 5) ? alert(i) : continue; // continue 不允许在这个位置
```

……代码会停止运行，并显示有语法错误。

这是不（建议）使用问号 `?` 运算符替代 `if` 语句的另一个原因。

### break/continue 标签

有时候我们需要从一次从多层嵌套的循环中跳出来。

例如，下述代码中我们的循环使用了 `i` 和 `j`，从 `(0,0)` 到 `(3,3)` 提示坐标 `(i, j)`：

```js
for (let i = 0; i < 3; i++) {
  for (let j = 0; j < 3; j++) {
    let input = prompt(`Value at coords (${i},${j})`, '');
    // 如果我想从这里退出并直接执行 alert('Done!')
  }
}
alert('Done!');
```

我们需要提供一种方法，以在用户取消输入时来停止这个过程。

在 `input` 之后的普通 `break` 只会打破内部循环。这还不够 —— 标签可以实现这一功能！

**标签** 是在循环之前带有冒号的标识符：

```js
labelName: for (...) {
  ...
}
```

`break <labelName>` 语句跳出循环至标签处：

```js
outer: for (let i = 0; i < 3; i++) {
  for (let j = 0; j < 3; j++) {
    let input = prompt(`Value at coords (${i},${j})`, '');
    // 如果是空字符串或被取消，则中断并跳出这两个循环。
    if (!input) break outer; // (*)
    // 用得到的值做些事……
  }
}
alert('Done!');
```

上述代码中，`break outer` 向上寻找名为 `outer` 的标签并跳出当前循环。

因此，控制权直接从 `(*)` 转至 `alert('Done!')`。

我们还可以将标签移至单独一行：

```js
outer:
for (let i = 0; i < 3; i++) { ... }
```

`continue` 指令也可以与标签一起使用。在这种情况下，执行跳转到标记循环的下一次迭代。

标签并不允许“跳到”所有位置

标签不允许我们跳到代码的任意位置。

例如，这样做是不可能的：

```js
break label;  // 无法跳转到这个标签
label: for (...)
```

只有在循环内部才能调用 `break/continue`，并且标签必须位于指令上方的某个位置。

## switch 语句

`switch` 语句可以替代多个 `if` 判断。

`switch` 语句为多分支选择的情况提供了一个更具描述性的方式。

### 语法

`switch` 语句有至少一个 `case` 代码块和一个可选的 `default` 代码块。

就像这样：

```js
switch(x) {
  case 'value1':  // if (x === 'value1')
    ...
    [break]
  case 'value2':  // if (x === 'value2')
    ...
    [break]
  default:
    ...
    [break]
}
```

- 比较 `x` 值与第一个 `case`（也就是 `value1`）是否严格相等，然后比较第二个 `case`（`value2`）以此类推。
- 如果相等，`switch` 语句就执行相应 `case` 下的代码块，直到遇到最靠近的 `break` 语句（或者直到 `switch` 语句末尾）。
- 如果没有符合的 case，则执行 `default` 代码块（如果 `default` 存在）。

**举例**：

`switch` 的例子（高亮的部分是执行的 `case` 部分）：

```js
let a = 2 + 2;
switch (a) {
  case 3:
    alert( 'Too small' );
    break;
  case 4:
    alert( 'Exactly!' );
    break;
  case 5:
    alert( 'Too large' );
    break;
  default:
    alert( "I don't know such values" );
}
```

这里的 `switch` 从第一个 `case` 分支开始将 `a` 的值与 `case` 后的值进行比较，第一个 `case` 后的值为 `3` 匹配失败。

然后比较 `4`。匹配，所以从 `case 4` 开始执行直到遇到最近的 `break`。

**如果没有 `break`，程序将不经过任何检查就会继续执行下一个 `case`。**

无 `break` 的例子：

```js
let a = 2 + 2;
switch (a) {
  case 3:
    alert( 'Too small' );
  case 4:
    alert( 'Exactly!' );
  case 5:
    alert( 'Too big' );
  default:
    alert( "I don't know such values" );
}
```

在上面的例子中我们会看到连续执行的三个 `alert`：

```js
alert( 'Exactly!' );
alert( 'Too big' );
alert( "I don't know such values" );
```

任何表达式都可以成为 `switch/case` 的参数

`switch` 和 `case` 都允许任意表达式。

比如：

```js
let a = "1";
let b = 0;
switch (+a) {
  case b + 1:
    alert("this runs, because +a is 1, exactly equals b+1");
    break;
  default:
    alert("this doesn't run");
}
```

这里 `+a` 返回 `1`，这个值跟 `case` 中 `b + 1` 相比较，然后执行对应的代码。

### case 分组

共享同一段代码的几个 `case` 分支可以被分为一组：

比如，如果我们想让 `case 3` 和 `case 5` 执行同样的代码：

```js
let a = 3;
switch (a) {
  case 4:
    alert('Right!');
    break;
  case 3: // (*) 下面这两个 case 被分在一组
  case 5:
    alert('Wrong!');
    alert("Why don't you take a math class?");
    break;
  default:
    alert('The result is strange. Really.');
}
```

现在 `3` 和 `5` 都显示相同的信息。

`switch/case` 有通过 case 进行“分组”的能力，其实是 switch 语句没有 `break` 时的副作用。因为没有 `break`，`case 3` 会从 `(*)` 行执行到 `case 5`。

### 注意事项

**强调一下，这里的相等是严格相等。被比较的值必须是相同的类型才能进行匹配。**

## 函数

### 函数声明

```js
function showMessage() {
  alert( 'Hello everyone!' );
}
```

`function` 关键字首先出现，然后是 **函数名**，然后是括号之间的 **参数** 列表（用逗号分隔，在上述示例中为空），最后是花括号之间的代码（即“函数体”）。

```js
function name(parameters) {
  ...body...
}
```

我们的新函数可以通过名称调用：`showMessage()`。

### 局部变量

在函数中声明的变量只在该函数内部可见。

```js
function showMessage() {
  let message = "Hello, I'm JavaScript!"; // 局部变量
  alert( message );
}
showMessage(); // Hello, I'm JavaScript!
alert( message ); // <-- 错误！变量是函数的局部变量
```

### 外部变量

函数也可以访问外部变量，例如：

```js
let userName = 'John';
function showMessage() {
  let message = 'Hello, ' + userName;
  alert(message);
}
showMessage(); // Hello, John
```

函数对外部变量拥有全部的访问权限。函数也可以修改外部变量。

只有在没有局部变量的情况下才会使用外部变量。

如果在函数内部声明了同名变量，那么函数会 **遮蔽** 外部变量。例如，在下面的代码中，函数使用局部的 `userName`，而外部变量被忽略：

```js
let userName = 'John';
function showMessage() {
  let userName = "Bob"; // 声明一个局部变量
  let message = 'Hello, ' + userName; // Bob
  alert(message);
}
// 函数会创建并使用它自己的 userName
showMessage();
alert( userName ); // John，未被更改，函数没有访问外部变量。
```

### 函数的全局变量

任何函数之外声明的变量，例如上述代码中的外部变量 `userName`，都被称为 **全局** 变量。

全局变量在任意函数中都是可见的（除非被局部变量遮蔽）。

减少全局变量的使用是一种很好的做法。现代的代码有很少甚至没有全局变量。大多数变量存在于它们的函数中。但是有时候，全局变量能够用于存储项目级别的数据。

### 参数

我们可以使用参数（也称“函数参数”）来将任意数据传递给函数。

在如下示例中，函数有两个参数：`from` 和 `text`。

```js
function showMessage(from, text) { // 参数：from 和 text
  alert(from + ': ' + text);
}
showMessage('Ann', 'Hello!'); // Ann: Hello! (*)
showMessage('Ann', "What's up?"); // Ann: What's up? (**)
```

当函数在 `(*)` 和 `(**)` 行中被调用时，给定值被复制到了局部变量 `from` 和 `text`。然后函数使用它们进行计算。

这里还有一个例子：我们有一个变量 `from`，并将它传递给函数。请注意：函数会修改 `from`，但在函数外部看不到更改，因为函数修改的是复制的变量值副本：

```js
function showMessage(from, text) {
  from = '*' + from + '*'; // 让 "from" 看起来更优雅
  alert( from + ': ' + text );
}
let from = "Ann";
showMessage(from, "Hello"); // *Ann*: Hello
// "from" 值相同，函数修改了一个局部的副本。
alert( from ); // Ann
```

### 默认值

如果未提供参数，那么其默认值则是 `undefined`。

例如，之前提到的函数 `showMessage(from, text)` 可以只使用一个参数调用：

```js
showMessage("Ann");
```

那不是错误，这样调用将输出 `"Ann: undefined"`。这里没有参数 `text`，所以程序假定 `text === undefined`。

如果我们想在本示例中设定“默认”的 `text`，那么我们可以在 `=` 之后指定它：

```js
function showMessage(from, text = "no text given") {
  alert( from + ": " + text );
}
showMessage("Ann"); // Ann: no text given
```

现在如果 `text` 参数未被传递，它将会得到值 `"no text given"`。

这里 `"no text given"` 是一个字符串，但它可以是更复杂的表达式，并且只会在缺少参数时才会被计算和分配。所以，这也是可能的：

```js
function showMessage(from, text = anotherFunction()) {
  // anotherFunction() 仅在没有给定 text 时执行
  // 其运行结果将成为 text 的值
}
```

旧式默认参数

旧版本的 JavaScript 不支持默认参数。所以在大多数旧版本的脚本中，你能找到其他设置默认参数的方法。

例如，用于 `undefined` 的显式检查：

```js
function showMessage(from, text) {
  if (text === undefined) {
    text = 'no text given';
  }
  alert( from + ": " + text );
}
```

……或使用 `||` 运算符：

```js
function showMessage(from, text) {
  // 如果 text 能转为 false，那么 text 会得到“默认”值
  text = text || 'no text given';
  ...
}
```

### 返回值

函数可以将一个值返回到调用代码中作为结果。

最简单的例子是将两个值相加的函数：

```js
function sum(a, b) {
  return a + b;
}
let result = sum(1, 2);
alert( result ); // 3
```

只使用 `return` 但没有返回值也是可行的。但这会导致函数立即退出。

空值的 `return` 或没有 `return` 的函数返回值为 `undefined`

```js
function doNothing() { /* 没有代码 */ }
alert( doNothing() === undefined ); // true
```

空值的 `return` 和 `return undefined` 等效：

```js
function doNothing() {
  return;
}
alert( doNothing() === undefined ); // true
```

---

不要在 `return` 与返回值之间添加新行

对于 `return` 的长表达式，可能你会很想将其放在单独一行，如下所示：

```js
return 
(some + long + expression + or + whatever * f(a) + f(b))
```

但这不行，因为 JavaScript 默认会在 `return` 之后加上分号。上面这段代码和下面这段代码运行流程相同：

```js
return; 
(some + long + expression + or + whatever * f(a) + f(b))
```

因此，实际上它的返回值变成了空值。

如果我们想要将返回的表达式写成跨多行的形式，那么应该在 `return` 的同一行开始写此表达式。或者至少按照如下的方式放上左括号：

```js
return (
  some + long + expression
  + or +
  whatever * f(a) + f(b)
  )
```

然后它就能像我们预想的那样正常运行了。

### 函数命名

函数就是行为（action）。所以它们的名字通常是动词。它应该简短且尽可能准确地描述函数的作用。这样读代码的人就能清楚地知道这个函数的功能。

一种普遍的做法是用动词前缀来开始一个函数，这个前缀模糊地描述了这个行为。团队内部必须就前缀的含义达成一致。

例如，以 `"show"` 开头的函数通常会显示某些内容。

函数以 XX 开始……

- `"get…"` —— 返回一个值，
- `"calc…"` —— 计算某些内容，
- `"create…"` —— 创建某些内容，
- `"check…"` —— 检查某些内容并返回 boolean 值，等。

### 函数 == 注释

函数应该简短且只有一个功能。如果这个函数功能复杂，那么把该函数拆分成几个小的函数是值得的。有时候遵循这个规则并不是那么容易，但这绝对是件好事。

一个单独的函数不仅更容易测试和调试 —— 它的存在本身就是一个很好的注释！

## 函数表达式

https://www.bookstack.cn/read/zh.javascript.info/4afb11cc353d302c.md

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
