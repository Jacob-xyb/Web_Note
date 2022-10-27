# 代码质量

## 书写风格

![](https://static.sitestack.cn/projects/zh.javascript.info/1c70bb4fa97449266b488163bc47cad9.svg)

# Chrome 中调试

## Debugger 命令

我们也可以使用 `debugger` 命令来暂停代码，像这样

```js
function hello(name) {
  let phrase = `Hello, ${name}!`;
  debugger;  // <-- 调试器会在这停止
  say(phrase);
}
```

# 基础数据类型进阶

## 基础数据类型包装器

像 Java 这样的一些语言允许我们使用 `new Number(1)` 或 `new Boolean(false)` 等语法，明确地为原始类型创建“对象包装器”。

在 JavaScript 中，由于历史原因，这也是可以的，但极其 **不推荐**。因为这样会出问题。

**例如：**

```js
alert(typeof 0); // "number"
alert(typeof new Number(0)); // "object"!

let zero = new Number(0);
if (zero) { // zero 为 true，因为它是一个对象
  alert( "zero is truthy?!?" );
}
```

另一方面，调用不带 `new`（关键字）的 `String/Number/Boolean` 函数是完全理智和有用的。它们将一个值转换为相应的类型：转成字符串、数字或布尔值（原始类型）。

例如，下面完全是有效的：

```js
let num = Number("123"); // 将字符串转成数字
```

**基础数据类型不能存储额外的数据，但是new出来的可以。**

```js
let num1 = 0;    // "number"
let num2 = new Number(0);   // "object"

num1.test = "hello1";
num2.test = "hello2";

console.log(num1.test);     // undefined || 严格模式下会报错
console.log(num2.test);     // "hello2"
```

- **null/undefined 没有任何方法**

特殊的原始类型 `null` 和 `undefined` 是例外。它们没有对应的“对象包装器”，也没有提供任何方法。从某种意义上说，它们是“最原始的”。

尝试访问这种值的属性会导致错误：

## Number

### 特殊数值

除了常规的数字，还包括所谓的 **“特殊数值（“special numeric values”）”** 也属于这种类型：`Infinity`、`-Infinity` 和 `NaN`。

- `Infinity` 代表数学概念中的 [无穷大](https://en.wikipedia.org/wiki/Infinity) ∞。是一个比任何数字都大的特殊值。

  ```js
  // 我们可以通过除以 0 来得到它：
  alert( 1 / 0 ); // Infinity
  
  // 或者在代码中直接使用它：
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

### 安全的数学运算

在 JavaScript 中做数学运算是安全的。我们可以做任何事：除以 0，将非数字字符串视为数字，等等。

脚本永远不会因为一个致命的错误（“死亡”）而停止。最坏的情况下，我们会得到 `NaN` 的结果。

特殊的数值属于 “number” 类型。当然，对“特殊的数值”这个词的一般认识是，它们并不是数字。

# 数组进阶

## 内部

数组是一种特殊的对象。使用方括号来访问属性 `arr[0]` 实际上是来自于对象的语法。它其实与 `obj[key]` 相同，其中 `arr` 是对象，而`数字` (index) 用作`键`（key）。

它们扩展了对象，提供了特殊的方法来处理有序的数据集合以及 `length` 属性。但从本质上讲，它仍然是一个对象。

记住，在 JavaScript 中只有 7 种基本类型。数组是一个对象，因此其行为也像一个对象。

例如，它是通过引用来复制的：

```js
let fruits = ["Banana"]
let arr = fruits; // 通过引用复制 (两个变量引用的是相同的数组)
alert( arr === fruits ); // true
arr.push("Pear"); // 通过引用修改数组
alert( fruits ); // Banana, Pear — 现在有 2 项了
```

……但是数组真正特殊的是它们的内部实现。JavaScript 引擎尝试把这些元素一个接一个地存储在连续的内存区域，就像本章的插图显示的一样，而且还有一些其它的优化，以使数组运行得非常快。

但是，如果我们不像“有序集合”那样使用数组，而是像常规对象那样使用数组，这些就都不生效了。

例如，从技术上讲，我们可以这样做:

```js
let fruits = []; // 创建一个数组
fruits[99999] = 5; // 分配索引远大于数组长度的属性
fruits.age = 25; // 创建一个具有任意名称的属性
```

这是可以的，因为数组是基于对象的。我们可以给它们添加任何属性。

但是 Javascript 引擎会发现，我们在像使用常规对象一样使用数组，那么针对数组的优化就不再适用了，然后对应的优化就会被关闭，这些优化所带来的优势也就荡然无存了。

数组误用的几种方式:

- 添加一个非数字的属性，比如 `arr.test = 5`。
- 制造空洞，比如：添加 `arr[0]`，然后添加 `arr[1000]` (它们中间什么都没有)。
- 以倒序填充数组，比如 `arr[1000]`，`arr[999]` 等等。

请将数组视为作用于 **有序数据** 的特殊结构。它们为此提供了特殊的方法。数组在 JavaScript 引擎内部是经过特殊调整的，使得更好地作用于连续的有序数据，所以请以正确的方式使用数组。如果你需要任意键值，那很有可能实际上你需要的是常规对象 `{}`。

## 数组的 delete

数组的 delete 只会删除 index 对应的值，而不会改变数组的长度。

## concat 进阶

通常，`arr.concat()` 只复制数组中的元素。其他对象，即使它们看起来像数组一样，但仍然会被作为一个整体添加：

```js
let arr = [1, 2];
let arrayLike = {
  0: "something",
  length: 1
};
alert( arr.concat(arrayLike) ); // 1,2,[object Object]
```

……但是，如果类似数组的对象具有 `Symbol.isConcatSpreadable` 属性，那么它就会被 `concat` 当作一个数组来处理：此对象中的元素将被添加：

```js
let arr = [1, 2];
let arrayLike = {
  0: "something",
  1: "else",
  [Symbol.isConcatSpreadable]: true,
  length: 2
};
alert( arr.concat(arrayLike) ); // 1,2,something,else
```

## 数组的清空

```js
let arr;
arr = [[1, 2, 3], [2, 3, 4]];

arr = [[]];
console.log(arr);   // [[]]
arr = [];
console.log(arr);   // []
console.log([] === [[]]);   // false
// ++ 在 JavaScript 中，[] 和 [[]] 是真实存在且不一样的

// arr[0].push([1, 2, 3]);     // error
arr.push([1, 2, 3]);
console.log(arr);   // [[1, 2, 3]]
arr[0].push(1, 2);  // 真实存在的属性才可以调用方法
console.log(arr);   // [[1, 2, 3, 1, 2]]
```

# JavaScript中的深拷贝

## 数组的深拷贝

```js
// slice()	|| 一维
arr2 = arr1.slice();
// concat() || 一维
arr2 = arr1.concat();
```

[后续](https://blog.csdn.net/liming1016/article/details/126967475)

