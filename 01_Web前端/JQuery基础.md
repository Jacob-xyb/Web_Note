# jQuery

# 体验jQuery

## 引入jQuery

```html
<script src="./jQuery/jQuery.js"></script>
```

引入 jQuery 文件后，会在全局暴露两个变量名：`$`，`jQuery`

这两个变量是一模一样的。

# jQuery 的选择器

语法：`$('选择器')`

注意：获取到的均是**元素集合**。

# jQuery 的筛选器

语法：`$('选择器').筛选器名称()`

```js
console.log($('li').first());
console.log($('li').last());
console.log($('li').eq(3));     // 索引
console.log($('span').next());  // span 元素的下一个元素
console.log($('span').nextAll());
console.log($('span').prev());  // span 元素的上一个元素
console.log($('span').prevAll());
console.log($('span').parent());
console.log($('span').parents());   // 获取到的是该元素的所有父级元素，直到 html 为止
console.log($('span').siblings());   // 获取该元素的所有兄弟元素
console.log($('ul').find());   // 获取该元素的所有后代元素
```

# jQuery 操作文本内容

`html()` : 获取元素所有内容，等价于原生 JS 中的 `innerHTML()`

`html('需要设置的内容')`: 可以解析 html 标签

`text()`: 获取元素的文本

`text('需要设置的文本')` : 文本不解析 html 标签

`val()` : 获取表单元素的值

`val('需要设置的值')`

# jQuery 操作类名

`addClass()`

`removeClass()`

`toggleClass()`

