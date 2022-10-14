# jQuery

# 体验jQuery

## 引入jQuery

```html
<script src="./jQuery/jQuery.js"></script>
```

引入 jQuery 文件后，会在全局暴露两个变量名：`$`，`jQuery`

这两个变量是一模一样的。

## jQuery 对象

jQuery对象类似数组，它的每个元素都是一个引用了DOM节点的对象。

总之jQuery的选择器不会返回`undefined`或者`null`，这样的好处是你不必在下一行判断`if (div === undefined)`。

jQuery对象和DOM对象之间可以互相转化：

```js
var div = $('#abc'); // jQuery对象
var divDom = div.get(0); // 假设存在div，获取第1个DOM元素
var another = $(divDom); // 重新把DOM包装为jQuery对象
```

### jQuery 对象的常用函数

```js
var ps = $('p'); // 返回所有<p>节点
ps.length; // 数一数页面有多少个<p>节点
```



# jQuery 的选择器

语法：`$('选择器')`

注意：获取到的均是**元素集合**。

- **实例：**

| 语法                     | 描述                                                    |
| ------------------------ | ------------------------------------------------------- |
| $("*")                   | 选取所有元素                                            |
| $(this)                  | 选取当前 HTML 元素                                      |
| $("p.intro")             | 选取 class 为 intro 的 <p> 元素                         |
| $("p:first")             | 选取第一个 <p> 元素                                     |
| $("ul li:first")         | 选取第一个 <ul> 元素的第一个 <li> 元素                  |
| $("ul li:first-child")   | 选取每个 <ul> 元素的第一个 <li> 元素                    |
| $("[href]")              | 选取带有 href 属性的元素                                |
| $("a[target='_blank']")  | 选取所有 target 属性值等于 "_blank" 的 <a> 元素         |
| $("a[target!='_blank']") | 选取所有 target 属性值不等于 "_blank" 的 <a> 元素       |
| $(":button")             | 选取所有 type="button" 的 <input> 元素 和 <button> 元素 |
| $("tr:even")             | 选取偶数位置的 <tr> 元素                                |
| $("tr:odd")              | 选取奇数位置的 <tr> 元素                                |

```js
$("#id", ".class")  复合选择器
$("div p span")       层级选择器 //div下的p元素中的span元素
$("div>p")            父子选择器 //div下的所有p元素
$("div+p")            相邻元素选择器 //div后面的p元素(仅一个p)
$("div~p")            兄弟选择器  //div后面的所有p元素(同级别)
$(".p:last")          类选择器 加 过滤选择器  第一个和最后一个（first 或者 last）
$("#mytable td:odd")      层级选择 加 过滤选择器 奇偶（odd 或者 even）
$("div p:eq(2)")    索引选择器 div下的第三个p元素（索引是从0开始）
$("a[href='www.baidu.com']")  属性选择器
$("p:contains(test)")        // 内容过滤选择器，包含text内容的p元素
$(":emtyp")        //内容过滤选择器，所有空标签（不包含子标签和内容的标签）parent 相反
$(":hidden")       //所有隐藏元素 visible 
$("input:enabled") //选取所有启用的表单元素
$(":disabled")     //所有不可用的元素
$("input:checked") //获取所有选中的复选框单选按钮等
$("select option:selected") //获取选中的选项元素
$('[items="A B"]')  //当属性的值包含空格等特殊字符时，需要用双引号括起来。
```

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

`addClass()`: 添加类名

`removeClass()`

`toggleClass()`

# jQuery 操作属性

`removeAttr()`: 规定从指定元素中移除的属性。 **removeAttr('id');**

# jQuery 事件

| 鼠标事件                                                     | 键盘事件                                                     | 表单事件                                                  | 文档/窗口事件                                             |
| :----------------------------------------------------------- | :----------------------------------------------------------- | :-------------------------------------------------------- | :-------------------------------------------------------- |
| [click](https://www.runoob.com/jquery/event-click.html)      | [keypress](https://www.runoob.com/jquery/event-keypress.html) | [submit](https://www.runoob.com/jquery/event-submit.html) | [load](https://www.runoob.com/jquery/event-load.html)     |
| [dblclick](https://www.runoob.com/jquery/event-dblclick.html) | [keydown](https://www.runoob.com/jquery/event-keydown.html)  | [change](https://www.runoob.com/jquery/event-change.html) | [resize](https://www.runoob.com/jquery/event-resize.html) |
| [mouseenter](https://www.runoob.com/jquery/event-mouseenter.html) | [keyup](https://www.runoob.com/jquery/event-keyup.html)      | [focus](https://www.runoob.com/jquery/event-focus.html)   | [scroll](https://www.runoob.com/jquery/event-scroll.html) |
| [mouseleave](https://www.runoob.com/jquery/event-mouseleave.html) |                                                              | [blur](https://www.runoob.com/jquery/event-blur.html)     | [unload](https://www.runoob.com/jquery/event-unload.html) |
| mousedown                                                    |                                                              |                                                           |                                                           |
| mouseup                                                      |                                                              |                                                           |                                                           |
| [hover](https://www.runoob.com/jquery/event-hover.html)      |                                                              |                                                           |                                                           |

**keypress,keydown,keyup的区别:**

- keydown：在键盘上按下某键时发生,一直按着则会不断触发（opera浏览器除外）, 它返回的是键盘代码;

- keypress：在键盘上按下一个按键，并产生一个字符时发生, 返回ASCII码。注意: **shift、alt、ctrl**等键按下并不会产生字符，所以监听无效 ,换句话说, 只有按下能在屏幕上输出字符的按键时keypress事件才会触发。若一直按着某按键则会不断触发。

- keyup：用户松开某一个按键时触发, 与keydown相对, 返回键盘代码.

  ```js
  // 案例1:获取按键代码或字符的ASCII码
  $(window).keydown( function(event){
     // 通过event.which可以拿到按键代码.  如果是keypress事件中,则拿到ASCII码.
  } );
  
  // 案例2:传递数据给事件处理函数
  // 只允许按下的字母键生效, 65~90是所有大写字母的键盘代码范围.
  let validKeys = { start: 65, end: 90  };
  $("#keys").keypress( validKeys, function(event){
      let keys = event.data;  //拿到validKeys对象.
      return event.which >= keys.start && event.which <= keys.end;
  } );
  ```

  
