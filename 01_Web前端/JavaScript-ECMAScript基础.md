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

# 注释

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

# 现代模式

## “use strict”

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

# 变量

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

## var 与 let

在较旧的脚本中，你也可能发现另一个关键字 `var`，而不是 `let`：

```js
var message = 'Hello';
```

`var` 关键字与 `let` **大体** 相同，也用来声明变量，但稍微有些不同，也有点“老派”。

## 变量命名

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

## 保留字

有一张 [保留字列表](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Lexical_grammar#Keywords)，这张表中的保留字无法用作变量命名，因为它们被用于编程语言本身了。

比如，`let`、`class`、`return`、`function` 都被保留了。

## 常量

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

# 基础数据类型

## 动态类型语言

JavaScript 中的变量可以保存任何数据。变量在前一刻可以是个字符串，下一刻就可以变成 number 类型：

```js
// 没有错误
let message = "hello";
message = 123456;
```

允许这种操作的编程语言称为“动态类型”（dynamically typed）的编程语言，意思是虽然编程语言中有不同的数据类型，但是你定义的变量并不会在定义后，被限制为某一数据类型。

在 JavaScript 中有 7 种原始类型：`number`，`bigint`，`string`，`boolean`，`symbol`，`null` 和 `undefined`。

## number 类型

JavaScript 中的常规数字以 64 位的格式 [IEEE-754](https://en.wikipedia.org/wiki/IEEE_754-2008_revision) 存储，也被称为“双精度浮点数”

```js
let n1 = 123;
document.write(typeof(n1), `<br>`); // number
let n2 = 12.345;
document.write(typeof(n2), `<br>`); // number
```

*number* 类型代表 **整数** 和 **浮点数**。

- **数值的其他表示方法**

  ```js
  // 科学计数法
  document.write(2e5, `<br>`); // 200000
  document.write(2E5, `<br>`); // 200000
  // 十六进制，大小写不敏感
  document.write(0x100, `<br>`); // 256
  // 八进制， 加不加 o 均生效
  document.write(0o100, `<br>`); // 64
  document.write(0100, `<br>`); // 64
  // 二进制
  document.write(0b100, `<br>`); // 4
  ```

除了常规的数字，还包括所谓的“特殊数值（“special numeric values”）”也属于这种类型：`Infinity`、`-Infinity` 和 `NaN`。

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

## bigint 类型

```js
// 尾部的 "n" 表示这是一个 BigInt 类型
const bigInt = 1234567890123456789012345678901234567890n;
document.write(typeof(bigInt));  // bigint
alert(bigInt);
// 尾部不写 "n" 就会转换为 浮点数
const Float = 1234567890123456789012345678901234567890;
alert(Float);
```

## string 类型

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

## boolean 类型

boolean 类型仅包含两个值：`true` 和 `false`。

布尔值也可作为比较的结果：

```js
let isGreater = 4 > 1;
alert( isGreater ); // true（比较的结果是 "yes"）
```

## null 值

它构成了一个独立的类型，只包含 `null` 值：

```js
let age = null;
document.write(typeof(age), `<br>`);    // object // 这是 JavaScript 语言的一个错误
document.write(age, `<br>`);    // null
```

相比较于其他编程语言，JavaScript 中的 `null` 不是一个“对不存在的 `object` 的引用”或者 “null 指针”。

JavaScript 中的 `null` 仅仅是一个代表“无”、“空”或“值未知”的特殊值。

上面的代码表示，由于某些原因，`age` 是未知或空的。

## undefined 值

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

但是不建议这样做。通常，使用使用 `null` 将一个“空”或者“未知”的值写入变量中，`undefined` 仅仅用于检验，例如查看变量是否被赋值或者其他类似的操作。

## symbol 

`symbol` 类型用于创建对象的唯一标识符。

# typeof 运算符

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

# constructor 属性

```js
"John".constructor                 // 返回函数 String()  { [native code] }
(3.14).constructor                 // 返回函数 Number()  { [native code] }
false.constructor                  // 返回函数 Boolean() { [native code] }
[1,2,3,4].constructor              // 返回函数 Array()   { [native code] }
{name:'John', age:34}.constructor  // 返回函数 Object()  { [native code] }
new Date().constructor             // 返回函数 Date()    { [native code] }
function () {}.constructor         // 返回函数 Function(){ [native code] }
```

# 类型转换

大多数情况下，运算符和函数会自动将赋予他们的值转换为正确的类型。

比如，`alert` 会自动将任何值都转换为字符串以进行显示。算术运算符会将值转换为数字。

在某些情况下，我们需要将值显式地转换为我们期望的类型。

## 转为 字符串

### String(value)

`String(value)` 显示转换

```js
let value1 = true;
document.write(String(value1));
document.write(`<br>`);
value1 = null;
document.write(String(value1));
document.write(`<br>`);
```

### value.toString()

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

## 转为 数字

### Number()

我们也可以使用 `Number(value)` 显式地将这个 `value` 转换为 number 类型。

**number 类型转换规则：**

| 值              | 变成……                                                       |
| :-------------- | :----------------------------------------------------------- |
| `undefined`     | `NaN`                                                        |
| `null`          | `0`                                                          |
| `true 和 false` | `1` and `0`                                                  |
| `string`        | 去掉首尾空格后的纯数字字符串中含有的数字。如果剩余字符串为空，则转换结果为 `0`。否则，将会从剩余字符串中“读取”数字。当类型转换出现 error 时返回 `NaN`。 |
| 其他对象        | NaN                                                          |

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

特殊的：

```js
// 进制数
Number('0b11'); 	// 3
Number('0x11'); 	// 17
// 但是
Number('011');		// 11 而不是 9
// 更推荐的写法
Number('0o11');		// 9
```

### parseInt()

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

### parseFloat()

parseFloat() 规则和 parseInt() 类似，只是会解析小数点

### 自动进行 Number 转换

在算术函数和表达式中，会自动进行 number 类型转换。

比如，当把除法 `/` 用于非 number 类型：

```js
alert( "6" / "2" ); // 3, string 类型的值被自动转换成 number 类型后进行计算
```

## 转为 布尔

布尔（boolean）类型转换是最简单的一个。

它发生在逻辑运算中（稍后我们将进行条件判断和其他类似的东西），但是也可以通过调用 `Boolean(value)`显式地进行转换。

转换规则如下：

- 直观上为“空”的值（如 `0`、空字符串、`null`、`undefined` 和 `NaN`）将变为 `false`。
- 其他值变成 `true`。

| 值                                    | 变成……  |
| :------------------------------------ | :------ |
| `0`, `null`, `undefined`, `NaN`, `""` | `false` |
| 其他值                                | `true`  |

# 运算符

## 运算符相关术语

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

##  + 运算符

### + 一元运算符

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

### + 二元运算符

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

## 其他数学运算符

`-` 、`*` 、`/` 、`%` 只能进行数学运算

## 运算符优先级

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

## = 赋值运算符

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

## ** 幂运算符

幂运算符 `**` 是最近被加入到 JavaScript 中的。

对于自然数 `b`，`a ** b` 的结果是 `a` 与自己相乘 `b` 次，整数非整数均适用。

```js
document.write(`2 ** 2 = ${2 ** 2}`);  // 4
document.write(`<br>`);
document.write(`2 ** 0.5 = ${2 ** 0.5}`);  // 1.4142135623730951
document.write(`<br>`);
```

## 自增/自减

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

## 位运算符

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

## ，逗号运算符

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

# 值的比较

**比较结果为 Boolean 类型**、

在数学中有很多用于比较大小的运算符：

- 大于 / 小于：`a > b`，`a < b`。
- 大于等于 / 小于等于：`a >= b`，`a <= b`。
- 检查两个值的相等：`a == b`（注意表达式中是两个等号 `=`，若写为单个等号 `a = b` 则表示赋值）。
- 检查两个值不相等，在数学中使用 `≠` 符号，而在 JavaScript 中则通过在赋值符号前加叹号表示：`a != b`。

## 字符串比较

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

## 不同类型间的比较

**当对不同类型的值进行比较时，JavaScript 会首先将其转化为数字（number）再判定大小。**

```js
document.write(`'2' > 1: ${'2' > 1}`); // true
document.write(`<br>`);
document.write(`'01' == '1': ${'01' == 1}`); // true
document.write(`<br>`);
```

对于布尔类型值，`true` 会被转化为 `1`、`false` 转化为 `0`。

特殊的：

```js
// 虽然 Number(null) = 0, 但是 null == 0 结果为 false
document.write(`'null' == 0: ${null == 0}`); // false
document.write(`<br>`);
```

## 严格相等

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

## 对 null 和 undefined 进行比较

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

### 奇怪的结果：null vs 0

通过比较 `null` 和 0 可得：

```js
alert( null > 0 );  // (1) false
alert( null == 0 ); // (2) false
alert( null >= 0 ); // (3) true
```

是的，上面的结果完全打破了你对数学的认识。在最后一行代码显示“`null` 大于等于 0”的情况下，前两行代码中一定会有一个是正确的，然而事实表明它们的结果都是 false。

为什么会出现这种反常结果，这是因为相等性检查 `==` 和普通比较符 `> < >= <=` 的代码逻辑是相互独立的。进行值的比较时，`null` 会被转化为数字，因此它被转化为了 `0`。这就是为什么（3）中 `null >= 0` 返回值是 true，（1）中 `null > 0` 返回值是 false。

另一方面，`undefined` 和 `null` 在相等性检查 `==` 中不会进行任何的类型转换，它们有自己独立的比较规则，所以除了它们之间互等外，不会等于任何其他的值。这就解释了为什么（2）中 `null == 0` 会返回 false。

### 特立独行的 undefined

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

### 规避错误

我们为何要研究上述示例？我们需要时刻记得这些古怪的规则吗？不，其实不需要。虽然随着代码写得越来越多，我们对这些规则也都会烂熟于胸，但是我们需要更为可靠的方法来避免潜在的问题：

除了严格相等 `===` 外，其他凡是有 `undefined/null` 参与的比较，我们都需要额外小心。

除非你非常清楚自己在做什么，否则永远不要使用 `>= > < <=` 去比较一个可能为 `null/undefined` 的变量。对于取值可能是 `null/undefined` 的变量，请按需要分别检查它的取值情况。

# 交互

## alert

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

## prompt

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

## confirm

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

# 条件运算符

有时我们需要根据不同条件执行不同的操作。

我们可以使用 `if` 语句和条件运算符 `?`（也称为“问号”运算符）来实现。

## if 语句

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

## 布尔转换

`if (…)` 语句会计算圆括号内的表达式，并将计算结果转换为布尔型。

回顾一下转换规则：

- 数字 `0`、空字符串 `""`、`null`、`undefined` 和 `NaN` 都会被转换成 `false`。因为他们被称为 “falsy” 值。
- 其他值被转换为 `true`，所以它们被称为 “truthy”。

## else 语句

`if` 语句有时会包含一个可选的 “else” 块。如果判断条件不成立，就会执行它内部的代码。

```js
let year = prompt('In which year was ECMAScript-2015 specification published?', '');
if (year == 2015) {
  alert( 'You guessed it right!' );
} else {
  alert( 'How can you be so wrong?' ); // 2015 以外的任何值
}
```

## else if 语句

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

## ? 条件运算符 *

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

## 多个 ?

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

## ‘?’ 的非常规使用

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

# 逻辑运算符

JavaScript 里有三个逻辑运算符：`&&`（与），`||`（或），`!`（非）

虽然他们被称为“逻辑”运算符，但这些运算符却可以被应用于任意类型的值，而不仅仅是布尔值。他们的结果也同样可以是任意类型。

## &&（与）

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

### 与运算的原理

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

## ||（或）

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

## !（非）

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

# 循环

## while 循环

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

## do…while 循环

使用 `do..while` 语法可以将条件检查移至循环体 **下面**：

```js
do {
  // 循环体
} while (condition);
```

循环首先执行循环体，然后检查条件，当条件为真时，重复执行循环体。

## for 循环

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

## break 跳出循环

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

## continue 继续下一次迭代

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

## break/continue 标签

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

# switch 语句

`switch` 语句可以替代多个 `if` 判断。

`switch` 语句为多分支选择的情况提供了一个更具描述性的方式。

## 语法

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

## case 分组

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

## 注意事项

**强调一下，这里的相等是严格相等。被比较的值必须是相同的类型才能进行匹配。**

# 函数基础

## 函数声明

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

## 局部变量

在函数中声明的变量只在该函数内部可见。

```js
function showMessage() {
  let message = "Hello, I'm JavaScript!"; // 局部变量
  alert( message );
}
showMessage(); // Hello, I'm JavaScript!
alert( message ); // <-- 错误！变量是函数的局部变量
```

## 外部变量

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

## 函数的全局变量

任何函数之外声明的变量，例如上述代码中的外部变量 `userName`，都被称为 **全局** 变量。

全局变量在任意函数中都是可见的（除非被局部变量遮蔽）。

减少全局变量的使用是一种很好的做法。现代的代码有很少甚至没有全局变量。大多数变量存在于它们的函数中。但是有时候，全局变量能够用于存储项目级别的数据。

## 参数

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

## 默认值

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

## 返回值

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

## 函数命名

函数就是行为（action）。所以它们的名字通常是动词。它应该简短且尽可能准确地描述函数的作用。这样读代码的人就能清楚地知道这个函数的功能。

一种普遍的做法是用动词前缀来开始一个函数，这个前缀模糊地描述了这个行为。团队内部必须就前缀的含义达成一致。

例如，以 `"show"` 开头的函数通常会显示某些内容。

函数以 XX 开始……

- `"get…"` —— 返回一个值，
- `"calc…"` —— 计算某些内容，
- `"create…"` —— 创建某些内容，
- `"check…"` —— 检查某些内容并返回 boolean 值，等。

## 函数 == 注释

函数应该简短且只有一个功能。如果这个函数功能复杂，那么把该函数拆分成几个小的函数是值得的。有时候遵循这个规则并不是那么容易，但这绝对是件好事。

一个单独的函数不仅更容易测试和调试 —— 它的存在本身就是一个很好的注释！

# 函数表达式

在 JavaScript 中，函数不是“神奇的语言结构”，而是一种特殊的值。

我们在前面章节使用的语法称为 **函数声明**：

```js
function sayHi() {
  alert( "Hello" );
}
```

另一种创建函数的语法称为 **函数表达式**。

通常会写成这样：

```js
let sayHi = function() {
  alert( "Hello" );
};
```

在这里，函数被创建并像其他赋值一样，被明确地分配给了一个变量。不管函数是被怎样定义的，都只是一个存储在变量 `sayHi` 中的值。

上面这两段示例代码的意思是一样的：“创建一个函数，并把它存进变量 `sayHi`”。

我们还可以用 `alert` 打印这个变量值：

```js
function sayHi() {
  alert( "Hello" );
}
alert( sayHi ); // 显示函数代码
```

注意，最后一行代码并不会运行函数，因为 `sayHi` 后没有括号。在其他编程语言中，只要提到函数的名称都会导致函数的调用执行，但 JavaScript 可不是这样。

在 JavaScript 中，函数是一个值，所以我们可以把它当成值对待。上面代码显示了一段字符串值，即函数的源码。

的确，在某种意义上说一个函数是一个特殊值，我们可以像 `sayHi()` 这样调用它。

但它依然是一个值，所以我们可以像使用其他类型的值一样使用它。

---

你可能想知道，为什么函数表达式结尾有一个分号 `;`，而函数声明没有：

```js
function sayHi() {
  // ...
}
let sayHi = function() {
  // ...
};
```

答案很简单：

- 在代码块的结尾不需要加分号 `;`，像 `if { ... }`，`for { }`，`function f { }` 等语法结构后面都不用加。
- 函数表达式是在语句内部的：`let sayHi = ...;`，作为一个值。它不是代码块而是一个赋值语句。不管值是什么，都建议在语句末尾添加分号 `;`。所以这里的分号与函数表达式本身没有任何关系，它只是用于终止语句。'

## 回调函数

让我们多举几个例子，看看如何将函数作为值来传递以及如何使用函数表达式。

我们写一个包含三个参数的函数 `ask(question, yes, no)`：

`question`: 关于问题的文本

`yes`: 当回答为 “Yes” 时，要运行的脚本

`no`: 当回答为 “No” 时，要运行的脚本

函数需要提出 `question`（问题），并根据用户的回答，调用 `yes()` 或 `no()`：

```js
function ask(question, yes, no) {
  if (confirm(question)) yes()
  else no();
}
function showOk() {
  alert( "You agreed." );
}
function showCancel() {
  alert( "You canceled the execution." );
}
// 用法：函数 showOk 和 showCancel 被作为参数传入到 ask
ask("Do you agree?", showOk, showCancel);
```

在实际开发中，这样的的函数是非常有用的。实际开发与上述示例最大的区别是，实际开发中的函数会通过更加复杂的方式与用户进行交互，而不是通过简单的 `confirm`。在浏览器中，这样的函数通常会绘制一个漂亮的提问窗口。但这是另外一件事了。

`ask` 的两个参数值 `showOk` 和 `showCancel` 可以被称为 **回调函数** 或简称 **回调**。

主要思想是我们传递一个函数，并期望在稍后必要时将其“回调”。在我们的例子中，`showOk` 是回答 “yes” 的回调，`showCancel` 是回答 “no” 的回调。

---

我们可以用函数表达式对同样的函数进行大幅简写：

```js
function ask(question, yes, no) {
  if (confirm(question)) yes()
  else no();
}
ask(
  "Do you agree?",
  function() { alert("You agreed."); },
  function() { alert("You canceled the execution."); }
);
```

这里直接在 `ask(...)` 调用内进行函数声明。这两个函数没有名字，所以叫 **匿名函数**。这样的函数在 `ask` 外无法访问（因为没有对它们分配变量），不过这正是我们想要的。

这样的代码在我们的脚本中非常常见，这正符合 JavaScript 语言的思想。

一个函数是表示一个“行为”的值

字符串或数字等常规值代表 **数据**。

函数可以被视为一个 **行为（action）**。

我们可以在变量之间传递它们，并在需要时运行。

## 函数表达式 vs 函数声明

函数声明和函数表达式之间的主要区别:

首先是语法：如何通过代码对它们进行区分。

- **函数声明**：在主代码流中声明为单独的语句的函数。

  ```js
  // 函数声明
  function sum(a, b) {
    return a + b;
  }
  ```

- **函数表达式**：在一个表达式中或另一个语法结构中创建的函数。下面这个函数是在赋值表达式 `=` 右侧创建的：

  ```js
  // 函数表达式
  let sum = function(a, b) {
    return a + b;
  };
  ```

更细微的差别是，JavaScript 引擎会在 **什么时候** 创建函数

**函数表达式是在代码执行到达时被创建，并且仅从那一刻起可用。**

一旦代码执行到赋值表达式 `let sum = function…` 的右侧，此时就会开始创建该函数，并且可以从现在开始使用（分配，调用等）。

函数声明则不同。

**在函数声明被定义之前，它就可以被调用。**

例如，一个全局函数声明对整个脚本来说都是可见的，无论它被写在这个脚本的哪个位置。

这是内部算法的原故。当 JavaScript **准备** 运行脚本时，首先会在脚本中寻找全局函数声明，并创建这些函数。我们可以将其视为“初始化阶段”。

在处理完所有函数声明后，代码才被执行。所以运行时能够使用这些函数。

---

函数声明的另外一个特殊的功能是它们的块级作用域。

**严格模式下，当一个函数声明在一个代码块内时，它在该代码块内的任何位置都是可见的。但在代码块外不可见。**

---

什么时候选择函数声明与函数表达式？

根据经验，当我们需要声明一个函数时，首先考虑函数声明语法。它能够为组织代码提供更多的灵活性。因为我们可以在声明这些函数之前调用这些函数。

这对代码可读性也更好，因为在代码中查找 `function f(…) {…}` 比 `let f = function(…) {…}` 更容易。函数声明更“醒目”。

# 箭头函数

创建函数还有另外一种非常简单的语法，并且这种方法通常比函数表达式更好。

它被称为“箭头函数”，因为它看起来像这样：

```js
let func = (arg1, arg2, ...argN) => expression
```

……这里创建了一个函数 `func`，它接受参数 `arg1..argN`，然后使用参数对右侧的 `expression` 求值并返回其结果。

换句话说，它是下面这段代码的更短的版本：

```js
let func = function(arg1, arg2, ...argN) {  return expression;};
```

让我们来看一个具体的例子：

```js
let sum = (a, b) => a + b;
/* 这个箭头函数是下面这个函数的更短的版本：
let sum = function(a, b) {
  return a + b;
};
*/
alert( sum(1, 2) ); // 3
```

- 如果我们只有一个参数，还可以省略掉参数外的圆括号，使代码更短。

  例如：

  ```js
  let double = n => n * 2;
  // 差不多等同于：let double = function(n) { return n * 2 }
  alert( double(3) ); // 6
  ```

- 如果没有参数，括号将是空的（但括号应该保留）：

  ```js
  let sayHi = () => alert("Hello!");
  sayHi();
  ```

箭头函数可以像函数表达式一样使用。

```js
let age = prompt("What is your age?", 18);
let welcome = (age < 18) ?
  () => alert('Hello') :
  () => alert("Greetings!");
welcome();
```

---

**多行的箭头函数**

上面的例子从 `=>` 的左侧获取参数，然后使用参数计算右侧表达式的值。

但有时我们需要更复杂一点的东西，比如多行的表达式或语句。这也是可以做到的，但是我们应该用花括号括起来。然后使用一个普通的 `return` 将需要返回的值进行返回。

就像这样：

```js
let sum = (a, b) => {  // 花括号表示开始一个多行函数
  let result = a + b;
  return result; // 如果我们使用了花括号，那么我们需要一个显式的 “return”
};
alert( sum(1, 2) ); // 3
```

在这里，我们赞扬了箭头功能的简洁性。但还不止这些！

箭头函数还有其他有趣的特性。

为了更深入地学习它们，我们首先需要了解一些 JavaScript 其他方面的知识，因此我们将在后面的 [深入理解箭头函数](https://www.bookstack.cn/read/zh.javascript.info/36343a6258490160.md) 一章中再继续研究箭头函数。

现在，我们已经可以用箭头函数进行单行行为和回调了。

---

**普通函数有 arguments，但箭头函数没有**

**箭头函数没有 this, 也就是说会去外部作用域去寻找 this (通常是 Window)**


# 对象

我们可以通过使用带有可选 **属性列表** 的花括号 `{…}` 来创建对象。一个属性就是一个键值对（“key: value”），其中键（`key`）是一个字符串（也叫做属性名），值（`value`）可以是任何值。

我们可以用下面两种语法中的任一种来创建一个空的对象（“空柜子”）：

```js
let user = new Object(); // “构造函数” 的语法
let user = {};  // “字面量” 的语法
```

## 文本和属性

我们可以在创建对象的时候，立即将一些属性以键值对的形式放到 `{...}` 中。

```js
let user = {     // 一个对象
  name: "John",  // 键 "name"，值 "John"
  age: 30        // 键 "age"，值 30
};
```

属性有键（或者也可以叫做“名字”或“标识符”），位于冒号 `":"` 的前面，值在冒号的右边。

在 `user` 对象中，有两个属性：

1. 第一个的键是 `"name"`，值是 `"John"`。
2. 第二个的键是 `"age"`，值是 `30`。

生成的 `user` 对象可以被想象为一个放置着两个标记有 “name” 和 “age” 的文件的柜子。

我们可以随时添加、删除和读取文件。

可以使用点符号访问属性值：

```js
// 读取文件的属性：
alert( user.name ); // John
alert( user.age ); // 30
```

属性的值可以是任意类型。

我们可以用 `delete` 操作符移除属性：

```js
delete user.age;
```

我们也可以用多字词语来作为属性名，但必须给它们加上引号：

```js
let user = {
  name: "John",
  age: 30,
  "likes birds": true  // 多词属性名必须加引号
};
```

列表中的最后一个属性应以逗号结尾：

```js
let user = {
  name: "John",
  age: 30,
}
```

这叫做尾随（trailing）或悬挂（hanging）逗号。这样便于我们添加、删除和移动属性，因为所有的行都是相似的。

## 方括号

对于多词属性，点操作就不能用了：

```js
// 这将提示有语法错误
user.likes birds = true
```

JavaScript 理解不了。它认为我们在处理 `user.likes`，然后在遇到意外的 `birds` 时给出了语法错误。

点符号要求 `key` 是有效的变量标识符。这意味着：不包含空格，不以数字开头，也不包含特殊字符（允许使用 `$` 和 `_`）。

有另一种方法，就是使用方括号，可用于任何字符串：

```js
let user = {};
// 设置
user["likes birds"] = true;
// 读取
alert(user["likes birds"]); // true
// 删除
delete user["likes birds"];
```

## 计算属性

我们可以在对象字面量中使用方括号。这叫做 **计算属性**。

例如：

```js
let fruit = prompt("Which fruit to buy?", "apple");
let bag = {
  [fruit]: 5, // 属性名是从 fruit 变量中得到的
};
alert( bag.apple ); // 5 如果 fruit="apple"
```

计算属性的含义很简单：`[fruit]` 含义是属性名应该从 `fruit` 变量中获取。

所以，如果一个用户输入 `"apple"`，`bag` 将变为 `{apple: 5}`。

本质上，这跟下面的语法效果相同：

```js
let fruit = prompt("Which fruit to buy?", "apple");
let bag = {};
// 从 fruit 变量中获取值
bag[fruit] = 5;
```

……但是看起来更好。

我们可以在方括号中使用更复杂的表达式：

```js
let fruit = 'apple';
let bag = {
  [fruit + 'Computers']: 5 // bag.appleComputers = 5
};
```

方括号比点符号更强大。它允许任何属性名和变量，但写起来也更加麻烦。

**所以大部分时间里，当属性名是已知且简单的时候，就是用点符号。如果我们需要一些更复杂的内容，那么就用方括号。**

## **属性值简写**

在实际开发中，我们通常用已存在的变量当做属性名。

例如：

```js
function makeUser(name, age) {
  return {
    name: name,
    age: age,
    // ……其他的属性
  };
}
let user = makeUser("John", 30);
alert(user.name); // John
```

在上面的例子中，属性名跟变量名一样。这种通过变量生成属性的应用场景很常见，在这有一种特殊的 **属性值缩写** 方法，使属性名变得更短。

可以用 `name` 来代替 `name:name` 像下面那样：

```js
function makeUser(name, age) {
  return {
    name, // 与 name: name 相同
    age,  // 与 age: age 相同
    // ...
  };
}
```

我们可以把属性名简写方式和正常方式混用：

```js
let user = {
  name,  // 与 name:name 相同
  age: 30
};
```

## 方法简写

在对象字面量中，有一种更短的（声明）方法的语法：

```js
// 这些对象作用一样
user = {
  sayHi: function() {
    alert("Hello");
  }
};
// 方法简写看起来更好，对吧？
let user = {
  sayHi() { // 与 "sayHi: function()" 一样
    alert("Hello");
  }
};
```

如上所示，我们可以省略 `"function"`，只写 `sayHi()`。

说实话，这种表示法还是有些不同。在对象继承方面有一些细微的差别（稍后将会介绍），但目前它们并不重要。在几乎所有的情况下，较短的语法是首选的。

## 属性名称限制

**属性名（key）必须是字符串或 Symbol（标识符的一种特殊类型，稍后将介绍）。**

**其它类型将被自动地转化为字符串。**

例如当我们使用数字 `0` 作为属性 `key` 时，它将被转化为字符串 `"0"`：

```js
let obj = {
  0: "test" // 和 "0": "test" 相同
};
// 两个 alert 访问的是同一个属性（数字 `0` 被转化为了字符串 "0"）
alert( obj["0"] ); // test
alert( obj[0] ); // test（同一个属性）
```

**保留字段可以被用作属性名。**

正如我们所知道的，像 “for”、“let” 和 “return” 等保留字段不能用作变量名。

但是对于对象的属性，没有这些限制。任何名字都可以：

```js
let obj = {
  for: 1,
  let: 2,
  return: 3
}
alert( obj.for + obj.let + obj.return );  // 6
```

我们可以将任意字符串作为属性键（key），只有一个特殊的：`__proto__` 因为历史原因要特别对待。

比如，我们不能把它设置为非对象的值：

```js
let obj = {};
obj.__proto__ = 5; // 分配一个数字
alert(obj.__proto__); // [object Object] — 值为对象，与预期结果不同
```

## 属性存在性测试，“in” 操作符

对象的一个显著的特点就是其所有的属性都是可访问的。如果某个属性不存在也不会报错！访问一个不存在的属性只是会返回 `undefined`。这提供了一种普遍的用于检查属性是否存在的方法 —— 获取值来与 undefined 比较：

```js
let user = {};
alert( user.noSuchProperty === undefined ); // true 意思是没有这个属性
```

这里同样也有一个特别的操作符 `"in"` 来检查属性是否存在。

语法是：

```js
"key" in object
```

请注意，`in` 的左边必须是 **属性名**。通常是一个**带引号的字符串**。

如果我们省略引号，则意味着将测试包含实际名称的变量。例如：

```js
let user = { age: 30 };
let age = "key";
document.write(age in user); // false，从 age 获取属性名并检查这个属性
document.write(`<br>`);
document.write('age' in user); // true
document.write(`<br>`);
```

对存储值为 `undefined` 的属性使用 “in”

通常，检查属性是否存在时，使用严格比较 `"=== undefined"` 就够了。但在一种特殊情况下，这种方式会失败，而 `"in"` 却可以正常工作。

那就是属性存在，但是存储值为 `undefined`：

```js
let obj = {
  test: undefined
};
alert( obj.test ); // 显示 undefined，所以属性不存在？
alert( "test" in obj ); // true，属性存在！
```

在上面的代码中，属性 `obj.test` 事实上是存在的，所以 `in` 操作符检查通过。

这种情况很少发生，因为通常情况下是不会给对象赋值 undefined 的，我们经常会用 `null` 来表示未知的或者空的值。

## “for…in” 循环

为了遍历一个对象的所有键（key），可以使用一个特殊形式的循环：`for..in`。这跟我们在前面学到的 `for(;;)` 循环是完全不一样的东西。

语法：

```js
for (key in object) {
  // 对此对象属性中的每个键执行的代码
}
```

例如，让我们列出 `user` 所有的属性：

```js
let user = {
  name: "John",
  age: 30,
  isAdmin: true
};
for (let key in user) {
  // keys
  alert( key );  // name, age, isAdmin
  // 属性键的值
  alert( user[key] ); // John, 30, true
}
```

## 对象中键的排序

对象有顺序吗？换句话说，如果我们遍历一个对象，我们获取属性的顺序是和属性添加时的顺序相同吗？

简短的回答是：“有特别的顺序”：整数属性会被进行排序，其他属性则按照创建的顺序显示。

```js
let codes = {
    "49": "Germany",
    "41": "Switzerland",
    "44": "Great Britain",
    // ..,
    "1": "USA"
};
for (let key in codes) {
    document.write(key + ' ');  // 1, 41, 44, 49
}
```

因为这些电话号码是整数，所以它们以升序排列。所以我们看到的是 `1, 41, 44, 49`。

整数属性？那是什么？

这里的“整数属性”指的是一个可以在不作任何更改的情况下转换为整数的字符串（包括整数到整数）。

所以，“49” 是一个整数属性名，因为我们把它转换成整数，再转换回来，它还是一样。但是 “+49” 和 “1.2” 就不行了：

```js
// Math.trunc 是内置的去除小数部分的方法。
alert( String(Math.trunc(Number("49"))) ); // "49"，相同，整数属性
alert( String(Math.trunc(Number("+49"))) ); // "49"，不同于 "+49" ⇒ 不是整数属性
alert( String(Math.trunc(Number("1.2"))) ); // "1"，不同于 "1.2" ⇒ 不是整数属性
```

……此外，如果属性名不是整数，那它们就按照创建时候的顺序来排序。

如果想强行按照创建顺序来，可以 **欺骗** 程序：

```js
let codes = {
  "+49": "Germany",
  "+41": "Switzerland",
  "+44": "Great Britain",
  // ..,
  "+1": "USA"
};
for (let code in codes) {
  alert( +code ); // 49, 41, 44, 1
}
```

- **整数和其他属性混用时的顺序**

  整数优先级别最高

  ```js
  let user = {
      name: "jx",
      age: "27",
      1: "bb",
      0: "aa",
  }
  document.write(`<br>`);
  for (let key in user) {
      document.write(key + ' ');  // 0 1 name age
  }
  ```

## 复制和合并，Object.assign

复制一个对象变量会创建指向此对象的另一个引用。

那如果我们需要复制一个对象呢？创建一份独立的拷贝，一份克隆？

这也是可行的，但是有一点麻烦，因为 JavaScript 中没有支持这种操作的内置函数。实际上，我们很少这么做。在大多数时候，复制引用都很好用。

但如果我们真想这么做，就需要创建一个新的对象，然后遍历现有对象的属性，在原始级别的状态下复制给新的对象。

```js
let user = {
  name: "John",
  age: 30
};
let clone = {}; // 新的空对象
// 复制所有的属性值
for (let key in user) {
  clone[key] = user[key];
}
// 现在的复制是独立的了
clone.name = "Pete"; // 改变它的值
alert( user.name ); // 原对象属性值不变
```

也可以用 [Object.assign](https://developer.mozilla.org/zh/docs/Web/JavaScript/Reference/Global_Objects/Object/assign) 来实现。

```js
Object.assign(dest,[ src1, src2, src3...])
```

- 参数 `dest` 和 `src1, ..., srcN`（你需要多少就可以设置多少，没有限制）是对象。
- 这个方法将 `src1, ..., srcN` 这些所有的对象复制到 `dest`。换句话说，从第二个参数开始，所有对象的属性都复制给了第一个参数对象，然后返回 `dest`。

例如，我们可以用这个方法来把几个对象合并成一个：

```js
let user = { name: "John" };
let permissions1 = { canView: true };
let permissions2 = { canEdit: true };
// 把 permissions1 和 permissions2 的所有属性都拷贝给 user
Object.assign(user, permissions1, permissions2);
// 现在 user = { name: "John", canView: true, canEdit: true }
```

我们可以用 `Object.assign` 来替代循环赋值进行简单的克隆操作：

```js
let user = {
  name: "John",
  age: 30
};
let clone = Object.assign({}, user);
```

它将对象 `user` 的所有的属性复制给了一个空对象并返回。实际上和循环赋值没什么区别，只是更短了。

---

直到现在，我们都是假设 `user` 的所有属性都是原始值。但是属性也可以是其他对象的引用。这种我们应该怎么操作呢？

```js
let user = {
  name: "John",
  sizes: {
    height: 182,
    width: 50
  }
};
alert( user.sizes.height ); // 182
```

现在，仅仅进行 `clone.sizes = user.sizes` 复制是不够的，因为 `user.sizes` 是一个对象，这个操作只能复制这个对象的引用。所以 `clone` 和 `user` 共享了一个对象。

```js
let user = {
  name: "John",
  sizes: {
    height: 182,
    width: 50
  }
};
let clone = Object.assign({}, user);
alert( user.sizes === clone.sizes ); // true，同一个对象
// user 和 clone 共享 sizes 对象
user.sizes.width++;       // 在这里改变一个属性的值
alert(clone.sizes.width); // 51，在这里查看属性的值
```

为了解决这个问题，我们在复制的时候应该检查 `user[key]` 的每一个值，如果它是一个对象，那么把它也复制一遍，这叫做深拷贝（deep cloning）。

有一个标准的深拷贝算法，用于解决上面这种和一些更复杂的情况，叫做 [结构化克隆算法（Structured cloning algorithm）](https://html.spec.whatwg.org/multipage/structured-data.html#safe-passing-of-structured-data)。为了不重复造轮子，我们可以使用它的一个 JavaScript 实现的库 [lodash](https://lodash.com/)，方法名叫做 [_.cloneDeep(obj)](https://lodash.com/docs#cloneDeep)。

## Symbol

“Symbol” 值表示唯一的标识符。

可以使用 `Symbol()` 来创建这种类型的值：

```js
// id 是 symbol 的一个实例化对象
let id = Symbol();
```

创建时，我们可以给 Symbol 一个描述（也称为 Symbol 名），这在代码调试时非常有用：

```js
// id 是描述为 "id" 的 Symbol
let id = Symbol("id");
```

Symbol 保证是唯一的。即使我们创建了许多具有相同描述的 Symbol，它们的值也是不同。描述只是一个标签，不影响任何东西。

例如，这里有两个描述相同的 Symbol —— 它们不相等：

```js
let id1 = Symbol("id");
let id2 = Symbol("id");
alert(id1 == id2); // false
```

JavaScript 中的大多数值都支持字符串的隐式转换。例如，我们可以 `alert` 任何值，都可以生效。Symbol 比较特殊，它不会被自动转换。

例如，这个 `alert` 将会提示出错：

```js
let id = Symbol("id");
alert(id); // 类型错误：无法将 Symbol 值转换为字符串。
```

这是一种防止混乱的“语言保护”，因为字符串和 Symbol 有本质上的不同，不应该意外地将它们转换成另一个。

如果我们真的想显示一个 Symbol，我们需要在它上面调用 `.toString()`，如下所示：

```js
let id = Symbol("id");
alert(id.toString()); // Symbol(id)，现在它有效了
```

或者获取 `symbol.description` 属性，只显示描述（description）：

```js
let id = Symbol("id");
alert(id.description); // id
```

### “隐藏”属性

Symbol 允许我们创建对象的“隐藏”属性，代码的任何其他部分都不能意外访问或重写这些属性。

例如，如果我们使用的是属于第三方代码的 `user` 对象，我们想要给它们添加一些标识符。

我们可以给它们使用 Symbol 键：

```js
let user = { // 属于另一个代码
  name: "John"
};
let id = Symbol("id");
user[id] = 1;
alert( user[id] ); // 我们可以使用 Symbol 作为键来访问数据
```

在字符串 `"id"` 上使用 `Symbol("id")` 有什么好处？

因为 `user` 属于另一个代码，另一个代码也使用它执行一些操作，所以我们不应该在它上面加任何字段，这样很不安全。但是 Symbol 不会被意外访问到，所以第三方代码看不到它，所以使用 Symbol 也许不会有什么问题。

另外，假设另一个脚本希望在 `user` 中有自己的标识符，以实现自己的目的。这可能是另一个 JavaScript 库，因此脚本之间完全不了解彼此。

然后该脚本可以创建自己的 `Symbol("id")`，像这样：

```js
// ...
let id = Symbol("id");
user[id] = "Their id value";
```

我们的标识符和他们的标识符之间不会有冲突，因为 Symbol 总是不同的，即使它们有相同的名字。

……但如果我们处于同样的目的，使用字符串 `"id"` 而不是用 symbol，那么 **就会** 出现冲突：

```js
let user = { name: "John" };
// 我们的脚本使用了 "id" 属性。
user.id = "Our id value";
// ……另一个脚本也想将 "id" 用于它的目的……
user.id = "Their id value"
// 砰！无意中被另一个脚本重写了 id！
```

## 对象方法，”this”

# 数组

一个特殊的数据结构，能存储有序的集合。

## 声明

- **创建一个空数组**

  ```js
  let arr = new Array();
  let arr = [];
  ```

  > 绝大多数情况下使用的都是第二种语法

- **初始化一个数组**

  ```js
  let fruits = ["Apple", "Orange", "Plum"];
  ```

## 基本操作

```js
arr[index]		// 索引获取数据
arr.length		// 获取长度


arr.length = num	// 设置长度
// ++ 小结：arr.length = num 时
// ++ 1.num 小于 原有长度，数组将被裁剪，只保留 num 个数据；
// ++ 2.num 大于 原有长度，数据将被扩充，被扩充的数据为 undefined.

arr[index] = value	// 设置数组中的数据
// ++ 小结：当 index 大于 length 时，会在后面新增数据
// ++  如果中间有间隙，则以 undefined 填充

// 负索引
console.log("负索引 =======");
console.log(fruits[-1], fruits[-2], fruits[-3]);    // 全是 undefined
console.log(fruits[1], fruits[2], fruits[3]);
// ++ 小结：数组中的负索引是不被允许的，但是在函数参数中普遍可以使用。
```

## 常用方法

![image.png](https://s2.loli.net/2022/10/26/SnLoT5UVEYXC7e6.png)

左侧的方法改变自身， 右侧的方法不改变自身。

### 队列方法

**pop/push, shift/unshift 方法**

```js
let fruits = ["Apple", "Orange", "Plum"];
let tmp;
let res;
```

- **push**

  `arr.push(value)`
  作用：将数据 **追加** 到数组的 **末尾**
  返回值：追加数据后数组 **最新的长度**

  ```js
  // push
  console.log("push =======");
  tmp = fruits.concat();
  res = tmp.push("Peach");    //  4
  console.log(tmp, res);
  // >> push 多个？ >> 可
  tmp = fruits.concat();
  res = tmp.push("Watermelon", "Banana");    // 5
  console.log(tmp, res);
  // >> push 嵌套？ >> 可
  tmp = fruits.concat();
  res = tmp.push(["Watermelon", "Banana"]);    // 4
  console.log(tmp, res);
  ```

- **pop**

  `arr.pop()`

  作用：删除数组 **最后一个** 数据

  返回值：被删除的数据

  ```js
  // pop
  console.log("pop =======");
  tmp = fruits.concat();
  res = tmp.pop();   //  "Plum"
  console.log(tmp, res);
  ```

- **unshift**

  语法类似于 push，向前添加

  ```js
  // unshift: 语法类似于 push，向前添加
  console.log("unshift =======");
  tmp = fruits.concat();
  res = tmp.unshift("Peach");    //  4
  console.log(tmp, res);
  ```

- **shift** 

  语法类似于 pop, 删除第一个数据

  ```js
  // shift: 语法类似于 pop, 删除第一个数据
  console.log("shift =======");
  tmp = fruits.concat();
  res = tmp.shift();   //  "Apple"
  console.log(tmp, res);
  ```

### 排序方法

```js
let arr = [9, 2, 3, 1, 4];
let tmp;
let res;
```

- **reverse()**

  ```js
  // reverse
  // ++ arr.reverse()
  // ++ 作用：反转数组
  // ++ 返回值：反转后的数组
  console.log("reverse =======");
  tmp = arr.concat();
  res = tmp.reverse();
  console.log(tmp, res);  // tmp 也被反转了
  res[0] = "xx";
  console.log(tmp, res);  // tmp 也被改变了
  // ++ 小结：arr.reverse() 直接改变 arr，返回是arr的引用
  ```

- **sort()**

  ```js
  // sort
  // ** 1. arr.sort()
  // ++++ 这些元素默认情况下被按字符串进行排序。
  let sort_arr = [1, 2, 15];
  console.log("sort() =======");
  sort_arr.sort();
  console.log(sort_arr);  //  [1, 15, 2]
  // ** 2. arr.sort(fn)
  // ++++ 使用 排序函数 来确认如何比较这些元素
  // +++++ 比较函数可以返回任何数字
  // +++++ 实际上，比较函数只需要返回一个正数表示“大于”，一个负数表示“小于”。
  console.log("sort(fn) =======");
  // ++++ 升序 arr.sort( (a, b) => a - b );
  sort_arr.sort((a, b) => a - b);
  console.log(sort_arr);  //  [1, 2, 15]
  // ++++ 降序 arr.sort( (a, b) => b - a );
  sort_arr.sort((a, b) => b - a);
  console.log(sort_arr);  //  [15, 2, 1]
  // 对于特殊字符串，应该使用特殊的函数来返回
  let countries = ['Österreich', 'Andorra', 'Vietnam'];   // 德语
  console.log(countries.sort((a, b) => a > b ? 1 : -1)); // Andorra, Vietnam, Österreich（错的）
  console.log(countries.sort((a, b) => a.localeCompare(b))); // Andorra,Österreich,Vietnam（对的！）
  ```

### 切片方法

```js
let arr = [9, 2, 3, 1, 4, 6, 7, 5, 8];
let tmp;
let res;
```

- **splice**

  ```js
  // splice
  // ++ arr.splice(start_index=0, num=0, (value||arr)=null)
  // ++ 作用：删除 数组中若干数据，并选择是否 插入 新的数据
  // ++ 返回值：以新数组的形式返回被删除的数据
  console.log("splice =======");
  // >> 用法1.删除数据
  tmp = arr.concat();
  res = tmp.splice(0, 1); 
  console.log(tmp, res);  // res: [9]
  // >> 用法2.插入数据
  tmp = arr.concat();
  res = tmp.splice(0, 0, "xx", "xx");
  console.log(tmp, res);  // res: [], 因为没有删除数据
  // ++ 小结：arr.splice() 用法多样
  ```

- **slice**

  ```js
  // slice
  // ++ arr.slice([start=0], [end=arr.length])
  // ++ 作用：切片，[start, end)
  // ++ 返回值：返回数组的深拷贝，仅限一维上的
  console.log("slice =======");
  tmp = arr.concat();
  res = tmp.slice(1, 4);
  console.log(tmp, res);  // [2, 3, 1]
  ```

- **concat**

  ```js
  // concat
  // ++ arr.concat(arg1, arg2...)
  // ++ 作用：创建一个新数组，其中包含来自于其他数组和其他项的值
  // ++ 参数：接受任意数量的参数 — 数组或值都可以。
  // ++ 返回值：结果是一个包含来自于 arr，然后是 arg1，arg2 ... 的元素的新数组。
  // +++ 如果参数 argN 是一个数组，那么其中的所有元素都会被复制。否则，将复制参数本身。
  // +++ 返回的数组仅限一维上的深拷贝
  console.log("concat =======");
  tmp = arr.concat();
  res = tmp.concat("aa", "bb");
  console.log(tmp, res);
  tmp = arr.concat();
  res = tmp.concat(["aa", "bb"], ["xx", "yy"]);
  console.log(tmp, res);
  ```

### 转换方法

- **join()**

  ```js
  // join()
  // ++ arr.join(连接符)
  // ++ 作用：将数组的内容以 连接符 拼接成一个 字符串
  // ++ 返回值：拼接好的 字符串
  console.log("join() =======");
  let arr = ['Bilbo', 'Gandalf', 'Nazgul'];
  let str = arr.join(';'); // 使用分号 ; 将数组粘合成字符串
  console.log(str); // "Bilbo;Gandalf;Nazgul"
  ```

- **map()**

  ```js
  // map()
  // ++ arr.map(function(item, index, array) {});
  // ++ 作用: 它对数组的每个元素都调用函数
  // ++ 返回值：返回一个新的数组
  console.log("map() =======");
  let map_arr = ['Bilbo', 'Gandalf', 'Nazgul'].map(item => item.length);
  console.log(map_arr);    // [5, 7, 6]
  let map_arr1 = [1, 2, 3].map(item => item ** 2);
  console.log(map_arr1);   // [1, 4, 9]
  ```

### 查找方法

```js
let arr = [1, 0, false];
let res;
```

- **indexOf()**

  ```js
  let arr = [1, 0, false];
  let res;
  // indexOf()
  // ++ arr.indexOf(item)
  // ++ 作用：查找 item 在 arr 中的 索引
  // ++ 返回值：返回 第一次 的 索引，没找到则返回 -1。
  // >> 注意：查找时，内部使用的判断为 严格相等 "==="
  console.log("indexOf() =======");
  res = arr.indexOf(false); // 使用分号 ; 将数组粘合成字符串
  console.log(res); // 2
  ```

- **filter()**

  ```js
  // filter()
  // ++ arr.filter(function(item, index, array){});
  // ++ 作用：过滤 数组
  // ++ 返回值：所有匹配元素组成的 数组
  console.log("filter() =======");
  let users = [
      { id: 1, name: "John" },
      { id: 2, name: "Pete" },
      { id: 3, name: "Mary" }
  ];
  let someUsers = users.filter(item => item.id < 3);
  console.log(someUsers, someUsers.length); // 2
  ```

### 遍历方法

- **forEach()**

  ```js
  let arr = ["Bilbo", "Gandalf", "Nazgul"];
  
  // forEach()
  // ++ arr.forEach(function(item, index, array){});
  // ++ 作用：查找 item 在 arr 中的 索引
  // ++ 返回值：返回 第一次 的 索引，没找到则返回 -1。
  // >> 注意：查找时，内部使用的判断为 严格相等 "==="
  console.log("forEach() =======");
  arr.forEach(function (item, index, array) {
      console.log(`${item} is at index ${index} in ${array}`);
  });
  ```

### 判断方法

```js
let arr = [1, 2, 3, 4, 5, "xx"];
let res;
```

- **every()**

  ```js
  // every()
  // ++ arr.every(function(item, index, array){});
  // ++ 作用：判断数组是不是 每一项 都满足条件
  // ++ 返回值：一个 布尔值
  console.log("every() =======");
  res = arr.every(item => ["number", "string"].indexOf(typeof item) !== -1); 
  console.log(res);   // true
  res = arr.every(item => item < 6); 
  console.log(res);   // false
  ```

- **some()**

  ```js
  // some()
  // ++ arr.some(function(item, index, array){});
  // ++ 作用：判断数组是不是有 某一项 满足条件
  // ++ 返回值：一个 布尔值
  console.log("some() =======");
  res = arr.some(item => typeof item === "string"); 
  console.log(res);   // true
  res = arr.some(item => item === 6); 
  console.log(res);   // false
  ```

# 基础数据类型常用方法

## 数字类型

### toString(base)

方法 `num.toString(base)` 返回在给定 `base` 进制数字系统中 `num` 的字符串表示形式。

```js
let num = 255;
document.write(num.toString(16));  // ff
document.write(`<br>`);
document.write(num.toString(2));   // 11111111
document.write(`<br>`);
```

`base` 的范围可以从 `2` 到 `36`。默认情况下是 `10`。

常见的用例如下：

- **base=16** 用于十六进制颜色，字符编码等，数字可以是 `0..9` 或 `A..F`。

- **base=2** 主要用于调试按位操作，数字可以是 `0` 或 `1`。

- **base=36** 是最大进制，数字可以是 `0..9` 或 `A..Z`。所有拉丁字母都被用于了表示数字。对于 `36` 进制来说，一个有趣且有用的例子是，当我们需要将一个较长的数字标识符转换成较短的时候，例如做一个短的 URL。可以简单地使用基数为 `36` 的数字系统表示：

  ```js
  alert( 123456..toString(36) ); // 2n9c
  ```

使用两个点来调用一个方法

请注意 `123456..toString(36)` 中的两个点不是打错了。如果我们想直接在一个数字上调用一个方法，比如上面例子中的 `toString`，那么我们需要在它后面放置两个点 `..`。

如果我们放置一个点：`123456.toString(36)`，那么就会出现一个 error，因为 JavaScript 语法隐含了第一个点之后的部分为小数部分。如果我们再放一个点，那么 JavaScript 就知道小数部分为空，现在使用该方法。

也可以写成 `(123456).toString(36)`。

### 舍入

舍入（rounding）是使用数字时最常用的操作之一。

这里有几个对数字进行舍入的内建函数：

`Math.floor()`: 向下舍入：`3.1` 变成 `3`，`-1.1` 变成 `-2`。

`Math.ceil()`: 向上舍入：`3.1` 变成 `4`，`-1.1` 变成 `-1`。

`Math.round()`: 向最近的整数舍入：`3.1` 变成 `3`，`3.6` 变成 `4`，`-1.1` 变成 `-1`。（3.5 -> 4）

`Math.trunc()`:移除小数点后的所有内容：`3.1` 变成 `3`，`-1.1` 变成 `-1`。（IE 浏览器不支持这个方法）

这个是总结它们之间差异的表格：

|        | `Math.floor` | `Math.ceil` | `Math.round` | `Math.trunc` |
| :----- | :----------- | :---------- | :----------- | :----------- |
| `3.1`  | `3`          | `4`         | `3`          | `3`          |
| `3.6`  | `3`          | `4`         | `4`          | `3`          |
| `-1.1` | `-2`         | `-1`        | `-1`         | `-1`         |
| `-1.6` | `-2`         | `-1`        | `-2`         | `-1`         |

```js
// 数字的表示方法
document.write(0xff + ' ' + 0xFF + ' ' + 0xFf); // 255
document.write(`<br>`);
document.write(0b111 + ' ' + 0o111);    // 7 73
document.write(`<br>`);

// toString(base)
let num = 255;
document.write(num.toString(16));  // ff
document.write(`<br>`);
document.write(num.toString(2));   // 11111111
document.write(`<br>`);

// 舍入
document.write(Math.floor(3.1), " ", Math.floor(-1.1));  // 3 -2
document.write(`<br>`);
document.write(Math.ceil(3.1), " ", Math.ceil(-1.1));  // 4 -1
document.write(`<br>`);
document.write(Math.round(3.1), " ", Math.round(-1.1), " ", Math.round(3.5));  // 3 -1 4
document.write(`<br>`);
```

---

这些函数涵盖了处理数字小数部分的所有可能方法。但是，如果我们想将数字舍入到小数点后 `n` 位，该怎么办？

有两种方式可以实现这个需求：

1. 乘除法

   例如，要将数字舍入到小数点后两位，我们可以将数字乘以 `100`，调用舍入函数，然后再将其除回。

   ```js
   let num = 1.23456;
   alert( Math.floor(num * 100) / 100 ); // 1.23456 -> 123.456 -> 123 -> 1.23
   ```

2. 函数 [toFixed(n)](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Number/toFixed) 将数字舍入到小数点后 `n` 位，并以字符串形式返回结果。

   ```js
   let num = 12.34;
   alert( num.toFixed(1) ); // "12.3"
   ```

   这会向上或向下舍入到最接近的值，类似于 `Math.round`：

   ```js
   let num = 12.34;
   alert( num.toFixed(5) ); // "12.34000"，在结尾添加了 0，以达到小数点后五位
   ```

   请注意 `toFixed` 的结果是一个字符串。如果小数部分比所需要的短，则在结尾添加零：

   ```
   let num = 12.34;alert( num.toFixed(5) ); // "12.34000"，在结尾添加了 0，以达到小数点后五位
   ```

   我们可以使用一元加号或 `Number()` 调用，将其转换为数字：`+ num.toFixed(5)`。

### 不精确的计算

```js
alert( 0.1 + 0.2 == 0.3 ); // false
```

解决方法：

```js
let sum = 0.1 + 0.2;
alert( +sum.toFixed(2) ); // 0.3
```

### isFinite 和 isNaN

还记得这两个特殊的数值吗？

- `Infinity`（和 `-Infinity`）是一个特殊的数值，比任何数值都大（小）。
- `NaN` 代表一个 error。

它们属于 `number` 类型，但不是“普通”数字，因此，这里有用于检查它们的特殊函数：

- `isNaN(value)` 将其参数转换为数字，然后测试它是否为 `NaN`：

  ```js
  alert( isNaN(NaN) ); // true
  alert( isNaN("str") ); // true
  ```

  但是我们需要这个函数吗？我们不能只使用 `=== NaN` 比较吗？不好意思，这不行。值 “NaN” 是独一无二的，它不等于任何东西，包括它自身：

  ```js
  alert( NaN === NaN ); // false
  ```

- `isFinite(value)` 将其参数转换为数字，如果是常规数字，则返回 `true`，而不是 `NaN/Infinity/-Infinity`：

  ```js
  alert( isFinite("15") ); // true
  alert( isFinite("str") ); // false，因为是一个特殊的值：NaN
  alert( isFinite(Infinity) ); // false，因为是一个特殊的值：Infinity
  ```

有时 `isFinite` 被用于验证字符串值是否为常规数字：

```js
let num = +prompt("Enter a number", '');
// 结果会是 true，除非你输入的是 Infinity、-Infinity 或不是数字
alert( isFinite(num) );
```

请注意，在所有数字函数中，包括 `isFinite`，空字符串或仅有空格的字符串均被视为 `0`。

与 `Object.is` 进行比较

有一个特殊的内建方法 [`Object.is`](https://developer.mozilla.org/zh/docs/Web/JavaScript/Reference/Global_Objects/Object/is)，它类似于 `===` 一样对值进行比较，但它对于两种边缘情况更可靠：

1. 它适用于 `NaN`：`Object.is（NaN，NaN）=== true`，这是件好事。
2. 值 `0` 和 `-0` 是不同的：`Object.is（0，-0）=== false`，从技术上讲这是对的，因为在内部，数字的符号位可能会不同，即使其他所有位均为零。

在所有其他情况下，`Object.is(a，b)` 与 `a === b` 相同。

这种比较方式经常被用在 JavaScript 规范中。当内部算法需要比较两个值是否完全相同时，它使用 `Object.is`（内部称为 [SameValue](https://tc39.github.io/ecma262/#sec-samevalue)）。

### parseInt 和 parseFloat

使用加号 `+` 或 `Number()` 的数字转换是严格的。如果一个值不完全是一个数字，就会失败：

```js
alert( +"100px" ); // NaN
```

唯一的例外是字符串开头或结尾的空格，因为它们会被忽略。

但在现实生活中，我们经常会有带有单位的值，例如 CSS 中的 `"100px"` 或 `"12pt"`。并且，在很多国家，货币符号是紧随金额之后的，所以我们有 `"19€"`，并希望从中提取出一个数值。

这就是 `parseInt` 和 `parseFloat` 的作用。

它们可以从字符串中“读取”数字，直到无法读取为止。如果发生 error，则返回收集到的数字。函数 `parseInt` 返回一个整数，而 `parseFloat` 返回一个浮点数：

```js
alert( parseInt('100px') ); // 100
alert( parseFloat('12.5em') ); // 12.5
alert( parseInt('12.3') ); // 12，只有整数部分被返回了
alert( parseFloat('12.3.4') ); // 12.3，在第二个点出停止了读取
```

某些情况下，`parseInt/parseFloat` 会返回 `NaN`。当没有数字可读时会发生这种情况：

```js
alert( parseInt('a123') ); // NaN，第一个符号停止了读取
```

parseInt(str, radix)` 的第二个参数

`parseInt()` 函数具有可选的第二个参数。它指定了数字系统的基数，因此 `parseInt` 还可以解析十六进制数字、二进制数字等的字符串：

```js
alert( parseInt('0xff', 16) ); // 255
alert( parseInt('ff', 16) ); // 255，没有 0x 仍然有效
alert( parseInt('2n9c', 36) ); // 123456
```

### 其他数学函数

JavaScript 有一个内建的 [Math](https://developer.mozilla.org/en/docs/Web/JavaScript/Reference/Global_Objects/Math) 对象，它包含了一个小型的数学函数和常量库。

几个例子：

- `Math.random()`

  返回一个从 0 到 1 的随机数（不包括 1）

- `Math.max(a, b, c...)/ Math.min(a, b, c...)`

  从任意数量的参数中返回最大/最小值。

- `Math.pow(n, power)`

  返回 `n` 的给定（power）次幂

## 字符串

在 JavaScript 中，文本数据被以字符串形式存储，单个字符没有单独的类型。

字符串的内部格式始终是 [UTF-16](https://en.wikipedia.org/wiki/UTF-16)，它不依赖于页面编码。

### 引号（Quotes）

**字符串可以包含在单引号、双引号或反引号中**

单引号和双引号基本相同。但是，反引号允许我们通过 `${…}` 将任何表达式嵌入到字符串中：

```js
function sum(a, b) {
  return a + b;
}
alert(`1 + 2 = ${sum(1, 2)}.`); // 1 + 2 = 3.
```

使用反引号的另一个优点是它们允许字符串跨行，但是使用单引号或双引号来实现字符串跨行的话，则会出现错误。

反引号还允许我们在第一个反引号之前指定一个“模版函数”。语法是：`func`string` `。函数 `func` 被自动调用，接收字符串和嵌入式表达式，并处理它们。你可以在 [docs](https://developer.mozilla.org/zh/docs/Web/JavaScript/Reference/Template_literals#Tagged_template_literals) 中阅读更多关于它们的信息。这叫做 “tagged templates”。此功能可以更轻松地将字符串包装到自定义模版或其他函数中，但这很少使用。

### 特殊字符

我们仍然可以通过使用“换行符（newline character）”，以支持使用单引号和双引号来创建跨行字符串。换行符写作 `\n`，用来表示换行：

```js
let guestList = "Guests:\n * John\n * Pete\n * Mary";
alert(guestList); // 一个多行的客人列表
```

还有其他不常见的“特殊”字符。

| 字符                                    | 描述                                                         |
| :-------------------------------------- | :----------------------------------------------------------- |
| `\n`                                    | 换行                                                         |
| `\r`                                    | 回车：不单独使用。Windows 文本文件使用两个字符 `\r\n` 的组合来表示换行。 |
| `\’`, `\”`                              | 引号                                                         |
| `\`                                     | 反斜线                                                       |
| `\t`                                    | 制表符                                                       |
| `\b`, `\f`, `\v`                        | 退格，换页，垂直标签 —— 为了兼容性，现在已经不使用了。       |
| `\xXX`                                  | 具有给定十六进制 Unicode `XX` 的 Unicode 字符，例如：`‘\x7A’` 和 `‘z’` 相同。 |
| `\uXXXX`                                | 以 UTF-16 编码的十六进制代码 `XXXX` 的 unicode 字符，例如 `\u00A9` —— 是版权符号 `©` 的 unicode。它必须正好是 4 个十六进制数字。 |
| `\u{X…XXXXXX}`（1 到 6 个十六进制字符） | 具有给定 UTF-32 编码的 unicode 符号。一些罕见的字符用两个 unicode 符号编码，占用 4 个字节。这样我们就可以插入长代码了。 |

所有的特殊字符都以反斜杠字符 `\` 开始。它也被称为“转义字符”。

### 字符串长度

`length` 属性表示字符串长度

```js
document.write( `My\n`.length );    // 3
```

注意 `\n` 是一个单独的“特殊”字符，所以长度确实是 `3`。

`length` 是一个属性

掌握其他编程语言的人，有时会错误地调用 `str.length()` 而不是 `str.length`。这是行不通的。

请注意 `str.length` 是一个数字属性，而不是函数。后面不需要添加括号。

### 访问字符

要获取在 `pos` 位置的一个字符，可以使用方括号 `[pos]` 或者调用 [str.charAt(pos)](https://developer.mozilla.org/zh/docs/Web/JavaScript/Reference/Global_Objects/String/charAt) 方法。第一个字符从零位置开始：

```js
let str = `Hello`;
// 第一个字符
alert( str[0] ); // H
alert( str.charAt(0) ); // H
// 最后一个字符
alert( str[str.length - 1] ); // o
```

方括号是获取字符的一种现代化方法，而 `charAt` 是历史原因才存在的。

它们之间的唯一区别是，如果没有找到字符，`[]` 返回 `undefined`，而 `charAt` 返回一个空字符串：

我们也可以使用 `for..of` 遍历字符：

```js
for (let char of "Hello") {
  alert(char); // H,e,l,l,o（char 变为 "H"，然后是 "e"，然后是 "l" 等）
}
```

### 字符串是不可变的

在 JavaScript 中，字符串不可更改。改变字符是不可能的。

```js
let str = 'Hi';
str[0] = 'h'; // error
alert( str[0] ); // 无法运行
```

### 常用函数

- [toLowerCase()](https://developer.mozilla.org/zh/docs/Web/JavaScript/Reference/Global_Objects/String/toLowerCase) 和 [toUpperCase()](https://developer.mozilla.org/zh/docs/Web/JavaScript/Reference/Global_Objects/String/toUpperCase)

  ```js
  alert( 'Interface'.toUpperCase() ); // INTERFACE
  alert( 'Interface'.toLowerCase() ); // interface
  ```
  
- **查找字符串**

  在字符串中查找子字符串有很多种方法。

  `str.indexOf()` :  [str.indexOf(substr, pos)](https://developer.mozilla.org/zh/docs/Web/JavaScript/Reference/Global_Objects/String/indexOf)

  它从给定位置 `pos` 开始，在 `str` 中查找 `substr`，如果没有找到，则返回 `-1`，否则返回匹配成功的位置。

  可选的第二个参数允许我们从给定的起始位置开始检索。

  `str.lastIndexOf(substr, pos)`: 它从字符串的末尾开始搜索到开头。

  ---

  更现代的方法: `includes`，`startsWith`，`endsWith`

- **获取子字符串**

  JavaScript 中有三种获取字符串的方法：`substring`、`substr` 和 `slice`。

  `str.slice(start [, end])` : 返回字符串从 `start` 到（但不包括）`end` 的部分。如果没有第二个参数，`slice` 会一直运行到字符串末尾：`start/end` 也有可能是负值。它们的意思是起始位置从字符串结尾计算。

  `str.substring(start [, end])` : 返回字符串在 `start` 和 `end` **之间** 的部分。这与 `slice` 几乎相同，但它允许 `start` 大于 `end`。不支持负参数（不像 slice），它们被视为 `0`。

   已弃用 ~~`str.substr(start [, length])` : 返回字符串从 `start` 开始的给定 `length` 的部分。~~

  与以前的方法相比，这个允许我们指定 `length` 而不是结束位置：

  ---

  相较于其他两个变体，`slice` 稍微灵活一些，它允许以负值作为参数并且写法更简短。因此仅仅记住这三种方法中的 `slice` 就足够了。

### 包含字符串

`str.includes(substr)` 

```js
console.log('hello'.includes('ll'));  // true
```

### 字符串替换

`str.replace(str1, str2)`

```js
let s1 = "aabbcc";
console.log(s1.replace("b", "x"));      // aaxbcc
console.log(s1.replace(/b/g, "x"));     // aaxxcc
```

# Iterable object 可迭代对象

```js
let range = {
  from: 1,
  to: 5
};
// 1. for..of 调用首先会调用这个：
range[Symbol.iterator] = function() {
  // ……它返回迭代器对象（iterator object）：
  // 2. 接下来，for..of 仅与此迭代器一起工作，要求它提供下一个值
  return {
    current: this.from,
    last: this.to,
    // 3. next() 在 for..of 的每一轮循环迭代中被调用
    next() {
      // 4. 它将会返回 {done:.., value :...} 格式的对象
      if (this.current <= this.last) {
        return { done: false, value: this.current++ };
      } else {
        return { done: true };
      }
    }
  };
};
// 现在它可以运行了！
for (let num of range) {
  alert(num); // 1, 然后是 2, 3, 4, 5
}
```

# Map 映射对象

[Map](https://developer.mozilla.org/zh/docs/Web/JavaScript/Reference/Global_Objects/Map) 是一个带键的数据项的集合，就像一个 `Object` 一样。 但是它们最大的差别是 `Map` 允许任何类型的键（key）。

它的方法和属性如下：

- `new Map()` —— 创建 map。
- `map.set(key, value)` —— 根据键存储值。
- `map.get(key)` —— 根据键来返回值，如果 `map` 中不存在对应的 `key`，则返回 `undefined`。
- `map.has(key)` —— 如果 `key` 存在则返回 `true`，否则返回 `false`。
- `map.delete(key)` —— 删除指定键的值。
- `map.clear()` —— 清空 map。
- `map.size` —— 返回当前元素个数。

## 链式调用

每一次 `map.set` 调用都会返回 map 本身，所以我们可以进行“链式”调用：

```js
map.set('1', 'str1').set(1, 'num1').set(true, 'bool1');
```

## Object.entries：从对象创建 Map

当创建一个 `Map` 后，我们可以传入一个带有键值对的数组（或其它可迭代对象）来进行初始化，如下所示：

```js
// 键值对 [key, value] 数组
let map = new Map([
  ['1',  'str1'],
  [1,    'num1'],
  [true, 'bool1']
]);
alert( map.get('1') ); // str1
```

如果我们想从一个已有的普通对象（plain object）来创建一个 `Map`，那么我们可以使用内建方法 [Object.entries(obj)](https://developer.mozilla.org/zh/docs/Web/JavaScript/Reference/Global_Objects/Object/entries)，该返回对象的键/值对数组，该数组格式完全按照 `Map` 所需的格式。

所以可以像下面这样从一个对象创建一个 Map：

```js
let obj = {
  name: "John",
  age: 30
};
let map = new Map(Object.entries(obj));
alert( map.get('name') ); // John
```

这里，`Object.entries` 返回键/值对数组：`[ ["name","John"], ["age", 30] ]`。这就是 `Map` 所需要的格式。

# Set

# WeakMap

# WeakSet

# 解构赋值

# 日期和时间

# JSON 方法

JavaScript 提供了如下方法：

- `JSON.stringify` 将对象转换为 JSON。
- `JSON.parse` 将 JSON 转换回对象。

## JSON.stringify

## JSON.parse

`json` 字符串是一个被称为 **JSON 编码（JSON-encoded）** 或 **序列化（serialized）** 或 **字符串化（stringified）** 或 **编组化（marshalled）** 的对象。

请注意，JSON 编码的对象与对象字面量有几个重要的区别：

- 字符串使用双引号。JSON 中没有单引号或反引号。所以 `'John'` 被转换为 `"John"`。
- 对象属性名称也是双引号的。这是强制性的。所以 `age:30` 被转换成 `"age":30`。

错误写法列举：

```js
let json = `{
  name: "John",                     // 错误：属性名没有双引号
  "surname": 'Smith',               // 错误：值使用的是单引号（必须使用双引号）
  'isAdmin': false,                 // 错误：键使用的是单引号（必须使用双引号）
  "birthday": new Date(2000, 2, 3), // 错误：不允许使用 "new"，只能是裸值
  "friends": [0,1,2,3],             // 这个没问题
}`;
```

# 函数进阶

## 递归

## Rest 参数与 Spread 语法

在 JavaScript 中，无论函数是如何定义的，你都可以使用任意数量的参数调用函数。

```js
function sum(a, b) {
  return a + b;
}
alert( sum(1, 2, 3, 4, 5) );
```

虽然这里不会因为传入“过多”的参数而报错。但是当然，在结果中只有前两个参数被计算进去了。

Rest 参数可以通过使用三个点 `...` 并在后面跟着包含剩余参数的数组名称，来将它们包含在函数定义中。这些点的字面意思是“将剩余参数收集到一个数组中”。

例如，我们需要把所有的参数都放到数组 `args` 中：

```js
function sumAll(...args) { // 数字名为 args
  let sum = 0;
  for (let arg of args) sum += arg;
  return sum;
}
alert( sumAll(1) ); // 1
alert( sumAll(1, 2) ); // 3
alert( sumAll(1, 2, 3) ); // 6
```

**Rest 参数必须放到参数列表的末尾**

## 闭包

比较难理解

## 函数对象，NFE

### 函数自定义属性

函数属性用来替代闭包：

```js
function makeCounter() {
  // 不需要这个了
  // let count = 0
  function counter() {
    return counter.count++;
  };
  counter.count = 0;
  return counter;
}
let counter = makeCounter();
alert( counter() ); // 0
alert( counter() ); // 1
```

## “new Function” 语法

# 对象进阶

# 原型，继承

在编程中，我们经常会想获取并扩展一些东西。

例如，我们有一个 `user` 对象及其属性和方法，并希望将 `admin` 和 `guest` 作为基于 `user` 稍加修改的变体。我们想重用 `user` 中的内容，而不是复制/重新实现它的方法，而只是在其至上构建一个新的对象。

**原型继承（Prototypal inheritance）** 这个语言特性能够帮助我们实现这一需求。

## 原型链

<img src="https://s2.loli.net/2022/09/28/WqDK49RXCgvoh6I.png" alt="image.png"  />

## [[Prototype]]

在 JavaScript 中，对象有一个特殊的隐藏属性 `[[Prototype]]`（如规范中所命名的），它要么为 `null`，要么就是对另一个对象的引用。该对象被称为“原型”：

```js
function Person() {}
console.log(Person.prototype)   // {constructor: ƒ}
```

原型有点“神奇”。当我们想要从 `object` 中读取一个缺失的属性时，JavaScript 会自动从原型中获取该属性。在编程中，这种行为被称为“原型继承”。许多炫酷的语言特性和编程技巧都基于此。

属性 `[[Prototype]]` 是内部的而且是隐藏的，但是这儿有很多设置它的方式。

- 构造函数

```js
function Person() {}
console.log(Person.prototype)   // {constructor: ƒ}

Person.prototype.sayHi = function () {console.log('hello world')};
new Person().sayHi();
```

- 字面量对象

```js
let animal = {
  eats: true
};
let rabbit = {
  jumps: true
};
rabbit.__proto__ = animal; // (*)
// 现在这两个属性我们都能在 rabbit 中找到：
alert( rabbit.eats ); // true (**)
alert( rabbit.jumps ); // true
```

`__proto__` 是 `[[Prototype]]` 的因历史原因而留下来的 getter/setter

请注意，`__proto__` 与 `[[Prototype]]` **不一样**。`__proto__` 是 `[[Prototype]]` 的 getter/setter。

`__proto__` 的存在是历史的原因。在现代编程语言中，将其替换为函数 `Object.getPrototypeOf/Object.setPrototypeOf` 也能 get/set 原型。我们稍后将学习造成这种情况的原因以及这些函数。

根据规范，`__proto__` 必须仅在浏览器环境下才能得到支持，但实际上，包括服务端在内的所有环境都支持它。目前，由于 `__proto__` 标记在观感上更加明显，所以我们在后面的示例中将使用它。

这里只有两个限制：

1. 引用不能形成闭环。如果我们试图在一个闭环中分配 `__proto__`，JavaScript 会抛出错误。
2. `__proto__` 的值可以是对象，也可以是 `null`。而其他的类型都会被忽略。

当然，这可能很显而易见，但是仍然要强调：只能有一个 `[[Prototype]]`。一个对象不能从其他两个对象获得继承。

## 面向对象中的原型

在构造函数中使用原型创建的对象，每个对象的实例所有用的原型对象空间是共享的

```js
// 原型对象共享空间
function Person() { }
Person.prototype.sayHi = function () { console.log('hello world') };

let p1 = new Person();
let p2 = new Person();

console.log(p1.sayHi === p2.sayHi);  // true
```

**属性 写在构造函数体内，方法 写在构造函数的原型上**





















