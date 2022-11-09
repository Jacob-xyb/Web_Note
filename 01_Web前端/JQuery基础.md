# jQuery

# 体验jQuery

## 引入jQuery

```html
// 本地引入
<script src="./jQuery/jQuery.js"></script>

// 网络引入
<script src="https://apps.bdimg.com/libs/jquery/2.1.4/jquery.min.js"></script>
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
//等效于
var divDom = div[0];

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

## 层次选择器

```js
$("#parent div");		// 选择id为parent的元素下的所有div元素
$("#parent > div");		// 选择id为parent的直接div子元素
$("#parent + div");		// 选择id为parent的下一个div同级元素
$("#parent ~ div");		// 选择id为parent之后的div同级元素
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
console.log($('span').siblings());   // 获取该元素的所有兄弟元素,不包含自身
console.log($('ul').find());   // 获取该元素的所有后代元素

console.log($('ul').find(selector));	// 获取该元素满足筛选条件的所有元素（不包括本身）
console.log($('ul').filter(selector));	// 获取该元素满足筛选条件的所有元素（包括本身）
```

# jQuery 遍历方法

| 方法                                                         | 描述                                                         |
| :----------------------------------------------------------- | :----------------------------------------------------------- |
| [add()](https://www.runoob.com/jquery/traversing-add.html)   | 把元素添加到匹配元素的集合中                                 |
| addBack()                                                    | 把之前的元素集添加到当前集合中                               |
| andSelf()                                                    | 在版本 1.8 中被废弃。addBack() 的别名                        |
| [children()](https://www.runoob.com/jquery/traversing-children.html) | 返回被选元素的所有直接子元素                                 |
| [closest()](https://www.runoob.com/jquery/traversing-closest.html) | 返回被选元素的第一个祖先元素                                 |
| [contents()](https://www.runoob.com/jquery/traversing-contents.html) | 返回被选元素的所有直接子元素（包含文本和注释节点）           |
| [each()](https://www.runoob.com/jquery/traversing-each.html) | 为每个匹配元素执行函数                                       |
| end()                                                        | 结束当前链中最近的一次筛选操作，并把匹配元素集合返回到前一次的状态 |
| [eq()](https://www.runoob.com/jquery/traversing-eq.html)     | 返回带有被选元素的指定索引号的元素                           |
| [filter()](https://www.runoob.com/jquery/traversing-filter.html) | 把匹配元素集合缩减为匹配选择器或匹配函数返回值的新元素       |
| [find()](https://www.runoob.com/jquery/traversing-find.html) | 返回被选元素的后代元素                                       |
| [first()](https://www.runoob.com/jquery/traversing-first.html) | 返回被选元素的第一个元素                                     |
| [has()](https://www.runoob.com/jquery/traversing-has.html)   | 返回拥有一个或多个元素在其内的所有元素                       |
| [is()](https://www.runoob.com/jquery/traversing-is.html)     | 根据选择器/元素/jQuery 对象检查匹配元素集合，如果存在至少一个匹配元素，则返回 true |
| [last()](https://www.runoob.com/jquery/traversing-last.html) | 返回被选元素的最后一个元素                                   |
| map()                                                        | 把当前匹配集合中的每个元素传递给函数，产生包含返回值的新 jQuery 对象 |
| [next()](https://www.runoob.com/jquery/traversing-next.html) | 返回被选元素的后一个同级元素                                 |
| [nextAll()](https://www.runoob.com/jquery/traversing-nextall.html) | 返回被选元素之后的所有同级元素                               |
| [nextUntil()](https://www.runoob.com/jquery/traversing-nextuntil.html) | 返回介于两个给定参数之间的每个元素之后的所有同级元素         |
| [not()](https://www.runoob.com/jquery/traversing-not.html)   | 从匹配元素集合中移除元素                                     |
| [offsetParent()](https://www.runoob.com/jquery/traversing-offsetparent.html) | 返回第一个定位的父元素                                       |
| [parent()](https://www.runoob.com/jquery/traversing-parent.html) | 返回被选元素的直接父元素                                     |
| [parents()](https://www.runoob.com/jquery/traversing-parents.html) | 返回被选元素的所有祖先元素                                   |
| [parentsUntil()](https://www.runoob.com/jquery/traversing-parentsuntil.html) | 返回介于两个给定参数之间的所有祖先元素                       |
| [prev()](https://www.runoob.com/jquery/traversing-prev.html) | 返回被选元素的前一个同级元素                                 |
| [prevAll()](https://www.runoob.com/jquery/traversing-prevall.html) | 返回被选元素之前的所有同级元素                               |
| [prevUntil()](https://www.runoob.com/jquery/traversing-prevuntil.html) | 返回介于两个给定参数之间的每个元素之前的所有同级元素         |
| [siblings()](https://www.runoob.com/jquery/traversing-siblings.html) | 返回被选元素的所有同级元素，不包含自身                       |
| [slice()](https://www.runoob.com/jquery/traversing-slice.html) | 把匹配元素集合缩减为指定范围的子集                           |

# jQuery 操作文本内容

`html()` : 获取元素所有内容，等价于原生 JS 中的 `innerHTML()`

`html('需要设置的内容')`: 可以解析 html 标签

`text()`: 获取元素的文本

`text('需要设置的文本')` : 文本不解析 html 标签

`val()` : 获取表单元素的值

`val('需要设置的值')`

# jQuery 操作属性

## 属性的分类

1. 固有属性：元素本身就有的属性（id, name, class, style 等）
2. 返回值是boolean的属性：checked、selected、disabled
3. 自定义属性: 用户自定义的属性

## 获取属性

`attr('属性名')` | `prop('属性名')`

1. 固有属性，两种方法均可获取

2. prop() 读取不了自定义属性。

3. 返回值是boolean类型的属性，

   设置了属性时：attr() 返回具体的值，prop() 返回 true；

   未设置属性时：attr() 返回 undefined，prop() 返回 false。

## 设置属性

`attr('属性名', '属性值')` | `prop('属性名', '属性值')`

1. prop() 设置不了自定义属性。

**案例：**

```html
<input type="checkbox" name="ch" checked id="aa" abc="aabbcc">aa
<input type="checkbox" name="ch" id="bb">bb
<script>
    // 1.设置固有属性
    $("#aa").attr("value", 1);
    $("#bb").prop("value", 2);

    // 2.返回值是 boolean 的属性
    $("#aa").attr("checked", false);
    $("#bb").prop("checked", true);

    // 3.自定义属性
    $('#aa').attr("uname", "jx");
    $("#bb").prop("uname", "jx");   // 不生效
</script>
```

## 移除属性

`removeAttr('属性名')`: 规定从指定元素中移除的属性。 **removeAttr('id');**

# jQuery 操作样式

| 方法                                                         | 说明                                                         |
| :----------------------------------------------------------- | :----------------------------------------------------------- |
| attr("class")                                                | 获取class属性的值，即样式名称                                |
| attr("class", "样式名")                                      | 修改class属性的值，修改样式                                  |
| addClass("样式名")                                           | 添加样式名称                                                 |
| css()                                                        | 添加具体的样式                                               |
| removeClass("样式名")                                        | 从被选元素移除一个或多个类。<br />如果没有规定参数，则该方法将从被选元素中删除所有类。 |
| toggleClass(*classname,*function*(index,currentclass),switch*) | 对添加和移除被选元素的一个或多个类进行切换。                 |

## css()

1. 单个样式：`css("样式名", "样式值")`
2. 多个样式：`css({"样式名": “样式值", "样式名2": "样式值2"})`

# 创建元素

只有 jQuery 对象才能使用jQuery方法，因此要经常创建jQuery元素。

```js
$("元素内容");
$("<p>this is a paragraph!!!</p>");
```

# 添加元素

| 方法                | 说明                                                         |
| ------------------- | ------------------------------------------------------------ |
| prepend(content)    | 在被选元素内部的**开头**插入元素或内容，被追加的content参数，可以是字符、HTML 元素标记、jQuery对象等等 |
| prependTo(selector) | 将被选元素或内容插入到 selector 元素开头                     |
| append(content)     | 在被选元素内部的**结尾**插入元素或内容，被追加的content参数，可以是字符、HTML 元素标记、jQuery对象等等 |
| appendTo(selector)  | 将被选元素或内容插入到 selector 元素结尾                     |
| before(content)     | 在被选元素前插入content                                      |
| after(content)      | 在被选元素后插入content                                      |

**注意：** 在添加已存在的元素时，相当于剪切。

# 删除元素

| 方法     | 说明                                                     |
| -------- | -------------------------------------------------------- |
| remove() | 删除所选元素或指定的子元素，包括整个标签和内容一起删除。 |
| empty()  | 清空所选元素的内容                                       |

# 遍历元素

```js
$(selector).each(function(index, element){});
```

**参数：**

- function： 遍历时的回调函数
- index：遍历元素的序列号，0开始
- element：当前的元素，为 dom 元素

> 遍历相当于取下标，$(selector)[index] 就是一个 dom 元素

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


## ready 加载事件

两种写法：

```js
$(document).ready(function() {
    alert('hello world')
});
$(function() {
    alert('hello world')
});
```

## bind 绑定事件

```js
$(selector).bind(eventType [, eventData], hander(eventObject));
```

**参数**:

- eventType: 一个字符串类型的事件类型
- [, eventData]：传递的参数，格式： {key1: value1, key2: value2}
- hander(eventObject)：该事件触发执行的函数

## 绑定单个事件

- **bind绑定**

  `$("元素").bind("事件类型", function(){});`

- **直接绑定**

  `$("元素").事件名(function(){});`

## 绑定多个事件

- **bind绑定**

1. 同时为多个事件绑定同一个函数

   `$("元素").bind("事件类型1, 事件类型2, ...", function(){});`

2. 为元素绑定多个事件并设置对应的函数（链接函数形式）

   `$("元素").bind("事件类型1", function(){}).bind("事件类型2", function(){});`

3. 为元素绑定多个事件并设置对应的函数 （参数列表形式）

   `$("元素").bind({"事件类型1": function(){}, "事件类型2": function(){}});`

- **直接绑定**

  `$("元素").事件名(function(){}).事件名(function(){});`

## on 动态绑定事件

on() 方法在被选元素及子元素上添加一个或多个事件处理程序。

自从jQuery 1.7 版本之后，on() 方法是bind() 、live()、和 delegate() 方法的新的替代品。

on可以绑定没有页面渲染时不存在的dom，bind不可以。

on是jquery推荐使用的，bind是从某个版本开始就不推荐使用的。

```js
$(document).on(type, selector, function () {
});
```

- 示例

```js
ProfileList.on('dblclick', ".Profile_right li", function () {
    let Profile_btnOK = $("#Profile_btnOK");
    Profile_btnOK.click();
});
```

# jQuery Ajax

## $.ajax

调用方法：`$.ajax({});`

**参数：**

- type：请求方式 GET/POST
- url: 请求地址 url
- async: 是否异步，默认 true 表示异步
- data: 发送到服务器的数据
- dataType: 预期服务器返回的数据类型
- contentType: 设置请求头
- success: 请求成功时调用此函数
- error: 请求失败时调用此函数

### $.ajax - get 请求

```js
$.ajax({
    type: "get",    // 请求方式 大小写均可
    url: "data.txt",    // 请求地址
    data: {// 如果没有可以不写
        username: "张三"
    },
    dataType: "json",   // 预期返回的数据类型，在返回时会自动转换数据类型
    success: function(data) { // data 是形参，代表返回的数据，但是是字符串
        // let json_data = JSON.parse(data);  // 设置 dataType 后就可以不用转换了
    }
});
```

## \$.get、\&.post、\$.getJSON

```js
// 1.请求一个 json 文件，忽略返回值
$.get("js/data.json");

// 2.请求json文件，传递参数，忽略返回值
$.get('js/data.json', {name:"jx", age:27});

// 3.请求json文件，拿到返回值，请求成功后可拿到返回值
$.get("js/data.json", function(data){});

// 4.请求json文件，传递参数，拿到返回值
$.get("js/data.json", {name:"jx", age:27}, function(data){});
```

三个的语法都是类似的。

> getJson() 要求返回的数据格式满足 json 格式 (json字符串)



