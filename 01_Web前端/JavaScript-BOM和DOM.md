# JavaScript BOM 操作

## BOM 

**BOM（Browser Object Model）**： 浏览器对象模型

一整套操作浏览器相关内容的属性和方法：

- 操作浏览器历史记录
- 操作浏览器滚动条
- 操作浏览器页面跳转
- 操作浏览器标签页的开启和关闭
- ···

## 可视化窗口尺寸

获取可视窗口宽度：`console.log(window.innerWidth)`

获取可视窗口高度：`console.log(window.innerHeight)`

**注意：** 窗口宽高是包含滚动条的宽高。

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

`window.history.go()`: 

```js
window.history.go(1)	// 前进一个页面
window.history.go(-1)	// 后退一个页面
```

## 浏览器滚动

### 浏览器卷去的尺寸

卷去的高度: `document.documentElement.scrollTop || document.body.scrollTop`

卷去的宽度: `document.documentElement.scrollLeft || document.body.scrollLeft`

### 浏览器滚动到

设置浏览器滚动条的位置

滚动到：`window.scrollTo()`

参数方式 1： `window.scrollTo( left, top )`

- 此方式只能瞬间定位，不能平滑滚动

参数方式 2：`window.scrollTo( {left:xx, top:yy, behavior: 'smooth' })`

- behavior: 'smooth' 代表平滑滚动

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

### 停止定时器

```html
<body>
    <button id="btn1">清除定时器 1</button>
    <button id="btn2">清除定时器 2</button>
    <script>
        let time1 = setInterval(function () {
            console.log(Date.now());
        }, 1000);

        let time2 = setInterval(function () {
            console.log('Jacob-xyb');
        }, 1000);

        btn1.onclick = function(){
            clearInterval(time1);
        };

        btn2.onclick = function(){
            clearInterval(time2);
        };
    </script>
</body>
```

## 浏览器相关信息

- **window.location.herf** : 获取浏览器 url 

```js
// 获取的 url 是编码后的字符串
console.log(location.href);
```

## 浏览器本地存储

### localStorage

```html
<button id="btn1">存</button>
<button id="btn2">取</button>
<button id="btn3">删</button>
<button id="btn4">清空</button>
<script>
    btn1.onclick = function () {
        localStorage.setItem("name", "Jacob-xyb");
        localStorage.setItem("obj", JSON.stringify({ name: "Jacob-xyb" }));
    }
    btn2.onclick = function () {
        console.log(localStorage.getItem("name"));
        console.log(JSON.parse(localStorage.getItem("obj")));
    }
    btn3.onclick = function () {
        localStorage.removeItem("name");
    }
    btn4.onclick = function () {
        localStorage.clear();
    }
</script>
```

**注意：** 存储的时候只能存储字符串，如果是对象，需要先转成 JSON 字符串。

### sessionStorage

操作和 localStorage 一样，他们的区别在于：

- **localStorage**： 永久存储，关闭页面不会丢失
- **sessionStorage**： 会话存储，关闭页面会丢失

# JavaScript DOM 操作

## DOM 结构

HTML 文档的主干是标签（tag）。

根据文档对象模型（DOM），每个 HTML 标签都是一个对象。嵌套的标签是闭合标签的“子标签（children）”。标签内的文本也是一个对象。

所有这些对象都可以通过 JavaScript 来访问，我们可以使用它们来修改页面。

例如，`document.body` 是表示 `<body>` 标签的对象。

运行这段代码会使 `<body>` 保持 3 秒红色状态:

```js
document.body.style.background = 'red'; // 将背景设置为红色
setTimeout(() => document.body.style.background = '', 3000); // 恢复回去
```

### DOM 的例子

以下是一个简单的文档（document）：

```html
<!DOCTYPE HTML>
<html>
<head>
  <title>About elk</title>
</head>
<body>
  The truth about elk.
</body>
</html>
```

DOM 将 HTML 表示为标签的树形结构。它看起来如下所示：

在上面的图片中，你可以点击元素（element）节点，它们的子节点会打开/折叠。

**每个树的节点都是一个对象。**

标签被称为 **元素节点**（或者仅仅是元素），并形成了树状结构：`<html>` 在根节点，`<head>` 和 `<body>` 是其子项，等。

元素内的文本形成 **文本节点**，被标记为 `＃text`。一个文本节点只包含一个字符串。它没有子项，并且总是树的叶子。

例如，`<title>` 标签里面有文本 `"About elk"`。

请注意文本节点中的特殊字符：

- 换行符：`↵`（在 JavaScript 中为 `\n`）
- 空格：`␣`

空格和换行符都是完全有效的字符，就像字母和数字。它们形成文本节点并成为 DOM 的一部分。所以，例如，在上面的示例中，`<head>` 标签中的 `<title>` 标签前面包含了一些空格，并且该文本变成了一个 `#text` 节点（它只包含一个换行符和一些空格）。

只有两个顶级排除项：

1. 由于历史原因，`<head>` 之前的空格和换行符均被忽略。
2. 如果我们在 `</body>` 之后放置一些东西，那么它会被自动移动到 `body` 内，并处于 `body` 中的最下方，因为 HTML 规范要求所有内容必须位于 `<body>` 内。所以 `</body>` 之后不能有空格。

在其他情况下，一切都很简单 — 如果文档中有空格（就像任何字符一样），那么它们将成为 DOM 中的文本节点，而如果我们删除它们，则不会有任何空格。

这是没有空格的文本节点：

## 获取元素

- **特殊元素节点**

  html, head, body

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
  ```

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

## 操作元素类名

- 元素.className

获取：`元素.className`

设置：`元素.className = '新类名'`

- 元素.classList

获取：`元素.classList`

增加：`元素.classList.add(类名)`  // 会自动去重

删除：`元素.classList.remove(类名)`

切换：`元素.classList.toggle(类名)`  // 有则删除，无则添加。

##  节点操作

### 创建节点

语法：`document.creatElement('标签名称')`

作用：创建一个指定标签元素

返回值：一个创建好的元素节点

### 插入节点

- `父节点.appendChild(子节点)`

  把 子节点 放在 父节点 的内部，并且放在最后位置。

- `父节点.insertBefore(要插入的子节点, 哪一个子节点的前面)`

  把 子节点 放在 父节点 的内部，并且放在指定某一个子节点的前面。

### 删除节点

- `父节点.removeChild(子节点)`
- `节点.remove()`

### 替换节点

`父节点.replaceChild(换上节点, 换下节点)`

### 克隆节点

`节点.cloneNode(是否克隆后代节点)`

## 获取元素尺寸

`元素.offsetHeight` 和 `元素.offsetWidth`: 获取元素 content + padding + border 区域的尺寸

`元素.clientHeight` 和 `元素.clientWidth`: 获取元素 content + padding 区域的尺寸

## 事件

### 事件绑定

事件绑定三要素：

1. 事件源：和 **谁** 最好约定
2. 事件类型：约定一个什么 **行为**
3. 事件处理函数： 当用户触发该行为的时候，执行什么代码

语法：`事件源.on事件类型 = 事件处理函数`

### 事件类型

![image.png](https://s2.loli.net/2022/09/26/nkFdT1Cywr7OWBl.png)

### 事件对象

```js
// 直接在事件处理函数接受形参
div.onclick = function (e) {
    console.log(e);
}
```

#### 鼠标事件相关信息

**坐标信息**

1. `offsetX` 和 `offsetY`: 相对于元素的坐标
2. `clientX` 和 `clientY`: 相对于浏览器可视窗口的坐标
3. `pageX` 和 `pageY`： 相对于页面文档流

#### 键盘事件相关信息

**键盘编码**：`事件对象.keyCode`

### 事件传播

- **浏览器响应事件的机制**

  浏览器窗口最先知道事件的发生

  **捕获阶段**：从 window 按照结构子级的顺序传递到目标

  **目标阶段**：准确触发事件的元素接收到行为

  **冒泡阶段**：从 目标 按照结构父级的顺序传递到 window

- **阻止事件传播**

  语法：`事件对象.stopPropagation()`

- **事件委托**

  利用冒泡的机制，把自己的事件委托给结构父级中的某一层

  `e.target.tagName === 'LI'` 注意标签名是全部大写

# window

```js
window.location.href	# 获取本地url地址
```

# Ajax

## 初识

1. 创建 ajax 对象

   ```js
   var xhr = new XMLHttpRequest();
   ```

2. 配置本次请求

   ```js
   xhr.open(请求方法, 请求地址, 是否异步);
   ```

3. 注册请求完成事件

   ```js
   xhr.onload = function () {};
   ```

4. 发送请求

   ```js
   xhr.send();
   ```

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