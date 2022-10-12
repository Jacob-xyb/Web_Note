# 入口函数

```js
//1.js原生的入口函数 方法一 等页面内容全部加在完毕,包含dom元素,图片,flash,css等才会执行函数
window.onload = function() {
    alert('hello world')
};
//2.js原生的入口函数 方法二 等dom元素全部加在完毕,就会执行函数,如果要获取图片尺寸,一般用onload
document.addEventListener('DOMContentLoaded', function() {
    alert('hello world')
});
//3.jquery的入口函数 方法一 等dom元素全部加在完毕,就会执行函数
$(function() {
    alert('hello world')
});
//4.jquery的入口函数 方法二 等dom元素全部加在完毕,就会执行函数
$(document).ready(function() {
    alert('hello world')
});
//5.jquery的入口函数 方法三 等页面内容全部加在完毕,包含dom元素,图片,flash,css等才会执行函数
$(window).load(function() {
    alert('hello world')
})
```

一般情况下一个页面响应加载的基本顺序是：**域名解析 -> 加载html -> 加载js和css -> 加载图片等其他信息**。
那么我们在编写JS脚本时什么情况下使用`$(document).ready()`又在什么情况下使用 `$(window).load()` 呢？

- `$(document).ready()`: 从字面的意思上理解，就是文档准备好了。也就是浏览器已经加载并解析完整个html文档，dom树已经建立起来了,然后执行此函数

- `$(window).load()`: 在网页中所有元素(包括页面中图片,css文件等所有关联文件)完全加载到浏览器后才执行。

两者区别在于：

- **执行时间不同**： 

  $(document).ready()是在页面完成HTML的加载并建立了DOM树之后就开始执行，但这并不代表页面的所

  有数据已经全部加载完成，一些大的图片有会在建立DOM树之后很长一段时间才行加载完成，而

  $(window).load()就是整个页面已经加载完毕后才执行，包括图片等一些关联文件。

- **可以被执行的次数不同：**

  \$(document).ready()可以在JavaScript代码中出现多次，并且里面的函数或者代码都可以执行；而\$(window).load()只能在JavaScript代码中出现一次，如果有多个\$(window).load()，那么只有最后一个\$(window).load()里面的函数或者代码才会执行，之前的\$(window).load()都将被覆盖;

- **执行的效率不同**:
  
  如要在dom的元素节点中添加onclick属性节点，这时用$(document).ready()就要比用$(window).load()的效率高；但是在某些时候还必须得用$(window).load()才行.

总结一下就是：**$(window).load()在$(document).ready之后执行，且页面中所有内容全部加载完成后才会执行**，两者的使用时机一目了然，大家可以自行决定。

