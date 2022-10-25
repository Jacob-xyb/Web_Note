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





