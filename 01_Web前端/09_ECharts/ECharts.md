# 如何快速上手ECharts

## 特性介绍

ECharts，一个纯 Javascript 的图表库，可以流畅的运行在 PC 和移动设备上，兼容当前绝大部分浏览器（IE8/9/10/11，Chrome，Firefox，Safari等），底层依赖轻量级的 Canvas 类库 ZRender，提供直观，生动，可交互，可高度个性化定制的数据可视化图表。

## 从哪里获取 ECharts ？

获取 ECharts 的路径有以下几种，请根据您的情况进行选择：

1. 最直接的方法是在 ECharts 的[官方网站](http://echarts.baidu.com/download.html)中挑选适合您的版本进行下载，不同的打包下载应用于不同的开发者功能与体积的需求，或者您也可以直接下载[完整版本](http://echarts.baidu.com/dist/echarts.min.js)；开发环境建议下载[源代码版本](http://echarts.baidu.com/dist/echarts.js)，包含了常见的错误提示和警告。
2. 也可以在 ECharts 的 [GitHub](https://github.com/echarts) 上下载最新的 release 版本，解压出来的文件夹里的 dist 目录里可以找到最新版本的 echarts 库。
3. 或者通过 npm 获取 echarts，npm install echarts --save，详见“[在 webpack 中使用 echarts](http://echarts.baidu.com/tutorial.html#在 webpack 中使用 ECharts)”
4. 由 cdn 引入，你可以在 [cdnjs](https://cdnjs.com/libraries/echarts)，[npmcdn](https://npmcdn.com/echarts@latest/dist/) 或者国内的 [bootcdn](http://www.bootcdn.cn/echarts/) 上找到 ECharts 的最新版本。

## 如何引入 ECharts？

ECharts 的引入方式变简单了，因为从 ECharts 3 开始就不用使用 AMD 的方式引入，代码也不再内置 AMD 加载器，所以 ECharts 的引入方式就可以像 JavaScript 库一样用 script 标签引入即可。

下面是 Echarts 引入的代码：

```html
<!DOCTYPE html>
<html>
<head>
    <meta charset="utf-8">
    <!-- 引入 ECharts 文件 -->
    <script src="echarts.min.js"></script>
</head>
</html>
```

## 准备容器

使用 Echarts 绘制图表前需要先有一个有宽高的 DOM 容器，代码如下：

```html
<body>
    <!-- 为 ECharts 准备一个具备大小（宽高）的 DOM -->
    <div id="main" style="width: 600px;height:400px;"></div>
</body>
```

## 使用 Echarts 绘制一个简单的图表

接着通过使用 [echarts.init](https://www.w3cschool.cn/echarts_tutorial/echarts_tutorial-id7w2c65.html#echarts.init) 方法来初始化一个 echarts 实例和使用  [setOption](https://www.w3cschool.cn/echarts_tutorial/echarts_tutorial-9m4j2c67.html) 方法生成一个简单的柱状图，完整的代码如下：

```html
<!DOCTYPE html>
<html>
<head>
    <meta charset="utf-8">
    <title>w3cschool (www.w3cschool.cn) </title>
    <!-- 引入 echarts.js -->
    <script src="https://cdn.bootcdn.net/ajax/libs/echarts/4.8.0/echarts-en.common.js" rel="external nofollow" ></script>
</head>
<body>
    <!-- 为ECharts准备一个具备大小（宽高）的Dom -->
    <div id="main" style="width: 600px;height:400px;"></div>
    <script type="text/javascript">
        // 基于准备好的dom，初始化echarts实例
        var myChart = echarts.init(document.getElementById('main'));
        // 指定图表的配置项和数据
        var option = {
            title: {
                text: 'ECharts 入门示例'
            },
            tooltip: {},
            legend: {
                data:['销量']
            },
            xAxis: {
                data: ["衬衫","羊毛衫","雪纺衫","裤子","高跟鞋","袜子"]
            },
            yAxis: {},
            series: [{
                name: '销量',
                type: 'bar',
                data: [5, 20, 36, 10, 10, 20]
            }]
        };
        // 使用刚指定的配置项和数据显示图表。
        myChart.setOption(option);
    </script>
</body>
</html>
```

# 配置项 \*\*\*\*\*\*\*\*\*\*

# [title](https://echarts.apache.org/zh/option.html#title) 标题

## 基础属性一览

| 属性                                                         | 值类型  | 说明                                             |
| ------------------------------------------------------------ | ------- | ------------------------------------------------ |
| [show](https://echarts.apache.org/zh/option.html#title.show) = true | boolean | 是否显示标题组件                                 |
| [text](https://echarts.apache.org/zh/option.html#title.text) = '' | string  | 主标题文本，支持使用 `\n` 换行。<br />默认靠左。 |

## [textAlign](https://echarts.apache.org/zh/option.html#title.textAlign) = 'auto'

string

整体（包括 text 和 subtext）的水平对齐。

可选值：`'auto'`、`'left'`、`'right'`、`'center'`。

基于基准线对齐，所以要居中对齐则要这样设置：

```css
left: "50%",
textAlign: "center",
```

##   [textStyle](https://echarts.apache.org/zh/option.html#title.textStyle) 文字样式

嵌套于 `title` 、`legend`

> 注意：如果不定义 `rich`，不能指定文字块的 `width` 和 `height`。

### 基础属性一览

| 属性                                                         | 值类型            | 说明                                                         |
| ------------------------------------------------------------ | ----------------- | ------------------------------------------------------------ |
| [color](https://echarts.apache.org/zh/option.html#title.subtextStyle.color) = '#333' | Color             | 主标题文字的颜色。                                           |
| [fontStyle](https://echarts.apache.org/zh/option.html#title.textStyle.fontStyle) = 'normal' | string            | 主标题文字字体的风格。<br />`'normal'`、`'italic'`、`'oblique'` |
| [fontWeight](https://echarts.apache.org/zh/option.html#title.textStyle.fontWeight) = 'bolder' | string  \| number | 主标题文字字体的粗细。<br />`'normal'` 、`'bold'`、`'bolder'`、`'lighter'`<br />100 \| 200 \| 300 \| 400 ... |
| [fontFamily](https://echarts.apache.org/zh/option.html#title.textStyle.fontFamily) = 'sans-serif' | string            | 主标题文字的字体系列。<br />'serif' , 'monospace', 'Arial', 'Courier New', 'Microsoft YaHei', ... |
| [fontSize](https://echarts.apache.org/zh/option.html#title.textStyle.fontSize) = 18 | number            | 主标题文字的字体大小。                                       |

## 副标题

title就是图表标题，可以控制它的属性，如颜色、位置等，**当有副标题的时候title有两种写法**，可以写为数组或对象

- **对象写法**

  ```js
  title: {
    show: true,    // 是否显示标题组件,（true/false）
    text: '',   // 主标题文本，支持使用\n换行
    textStyle: {    // 标题样式
    },
    subtext: '',    // 副标题
    subtextStyle: {    // 副标题样式
      }
  }
  ```

- **数组写法**

  ```js
  title: {
      { // 标题
      	text: '',   // 主标题文本，支持使用\n换行
    		textStyle: {    // 标题样式
    			},
      },
      { // 负标题
      	text: '',   // 主标题文本，支持使用\n换行
    		textStyle: {    // 标题样式
    			},
      },
  }
  ```

# legend 图例

## 基础属性一览

| 属性 | 值类型 | 说明 |
| ---- | ------ | ---- |
|      |        |      |

##  [type](https://echarts.apache.org/zh/option.html#legend.type)

string

图例的类型。可选值：

- `'plain'`：普通图例。缺省就是普通图例。
- `'scroll'`：可滚动翻页的图例。当图例数量较多时可以使用。

参见 [滚动图例（垂直）](https://echarts.apache.org/examples/zh/editor.html?c=pie-legend&edit=1&reset=1) 或 [滚动图例（水平）](https://echarts.apache.org/examples/zh/editor.html?c=radar2&edit=1&reset=1)。

当使用 `'scroll'` 时，可以进行细节配置。

## [icon](https://echarts.apache.org/zh/option.html#legend.icon)

string

图例项的 icon。

ECharts 提供的标记类型包括

`'circle'` , `'rect'`, `'roundRect'`, `'triangle'`, `'diamond'`, `'pin'`, `'arrow'`, `'none'`

可以通过 `'image://url'` 设置为图片，其中 URL 为图片的链接，或者 `dataURI`。

URL 为图片链接例如：

`'image://http://example.website/a/b.png'`

URL 为 `dataURI` 例如：

```css
'image://data:image/gif;base64,R0lGODlhEAAQAMQAAORHHOVSKudfOulrSOp3WOyDZu6QdvCchPGolfO0o/XBs/fNwfjZ0frl3/zy7////wAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAACH5BAkAABAALAAAAAAQABAAAAVVICSOZGlCQAosJ6mu7fiyZeKqNKToQGDsM8hBADgUXoGAiqhSvp5QAnQKGIgUhwFUYLCVDFCrKUE1lBavAViFIDlTImbKC5Gm2hB0SlBCBMQiB0UjIQA7'
```

可以通过 `'path://'` 将图标设置为任意的矢量路径。这种方式相比于使用图片的方式，不用担心因为缩放而产生锯齿或模糊，而且可以设置为任意颜色。路径图形会自适应调整为合适的大小。路径的格式参见 [SVG PathData](http://www.w3.org/TR/SVG/paths.html#PathData)。可以从 Adobe Illustrator 等工具编辑导出。

例如：

```css
'path://M30.9,53.2C16.8,53.2,5.3,41.7,5.3,27.6S16.8,2,30.9,2C45,2,56.4,13.5,56.4,27.6S45,53.2,30.9,53.2z M30.9,3.5C17.6,3.5,6.8,14.4,6.8,27.6c0,13.3,10.8,24.1,24.101,24.1C44.2,51.7,55,40.9,55,27.6C54.9,14.4,44.1,3.5,30.9,3.5z M36.9,35.8c0,0.601-0.4,1-0.9,1h-1.3c-0.5,0-0.9-0.399-0.9-1V19.5c0-0.6,0.4-1,0.9-1H36c0.5,0,0.9,0.4,0.9,1V35.8z M27.8,35.8 c0,0.601-0.4,1-0.9,1h-1.3c-0.5,0-0.9-0.399-0.9-1V19.5c0-0.6,0.4-1,0.9-1H27c0.5,0,0.9,0.4,0.9,1L27.8,35.8L27.8,35.8z'
```

##  [data](https://echarts.apache.org/zh/option.html#legend.data)

Array

图例的数据数组。数组项通常为一个字符串，每一项代表一个系列的 `name`（如果是[饼图](https://echarts.apache.org/zh/option.html#series-pie)，也可以是饼图单个数据的 `name`）。图例组件会自动根据对应系列的图形标记（symbol）来绘制自己的颜色和标记，特殊字符串 `''`（空字符串）或者 `'\n'`（换行字符串）用于图例的换行。

如果 `data` 没有被指定，会自动从当前系列中获取。多数系列会取自 [series.name](https://echarts.apache.org/zh/option.html#series.name) 或者 [series.encode](https://echarts.apache.org/zh/option.html#series.encode) 的 `seriesName` 所指定的维度。如 [饼图](https://echarts.apache.org/zh/option.html#series-pie) and [漏斗图](https://echarts.apache.org/zh/option.html#series-funnel) 等会取自 series.data 中的 name。

如果要设置单独一项的样式，也可以把该项写成配置项对象。此时必须使用 `name` 属性对应表示系列的 `name`。

示例

```css
data: [{
    name: '系列1',
    // 强制设置图形为圆。
    icon: 'circle',
    // 设置文本为红色
    textStyle: {
        color: 'red'
    }
}]
```

> **name 必须与 数据中的一致，否则不显示；切图例默认居中靠上**

## [lineStyle](https://echarts.apache.org/zh/option.html#legend.lineStyle)

图例图形中线的样式，用于诸如折线图图例横线的样式设置。其属性的取值为 `'inherit'` 时，表示继承系列中的属性值。

### 基础属性一览

| 属性                                                         | 值类型 | 说明       |
| ------------------------------------------------------------ | ------ | ---------- |
| [color](https://echarts.apache.org/zh/option.html#legend.lineStyle.color) = 'inherit' | Color  | 线的颜色。 |
| [width](https://echarts.apache.org/zh/option.html#legend.lineStyle.width) = auto | number | 线宽       |

###  [type](https://echarts.apache.org/zh/option.html#legend.lineStyle.type) = inherit

string number Array

线的类型。

可选：

- `'solid'`
- `'dashed'`
- `'dotted'`

自 `v5.0.0` 开始，也可以是 `number` 或者 `number` 数组，用以指定线条的 [dash array](https://developer.mozilla.org/zh-CN/docs/Web/SVG/Attribute/stroke-dasharray)，配合 `dashOffset` 可实现更灵活的虚线效果。

例如：

```css
{

type: [5, 10],

dashOffset: 5
}
```

## 图例图标文字对齐

猜测 图例文字的基准线为 图例图标的中线 位置，因此总是会呈现一种对不齐的感觉：

![image.png](https://s2.loli.net/2022/11/03/fi2WT6vVJ1dE3lb.png)

因为 `legend.textStyle` 没有 `verticalAlign` 属性，只有 `legend.textStyle.rich.<style_name>` 有，太复杂了，所以采用 `height` 调节居中方式，然后设置 `rich` 让 `height` 生效。 

```css
legend: {
    name: '系列1',
        textStyle: {
            height: "8",
                rich: {},
    },
    right: "30",
},
```

`height: "8"` 目前来说就是个经验值，基本覆盖全部情况。