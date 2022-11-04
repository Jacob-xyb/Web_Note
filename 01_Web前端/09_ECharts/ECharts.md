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

| 属性                                                         | 值类型 | 说明                 |
| ------------------------------------------------------------ | ------ | -------------------- |
| [itemWidth](https://echarts.apache.org/zh/option.html#legend.itemWidth) = 25 | number | 图例标记的图形宽度。 |

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

## [itemStyle](https://echarts.apache.org/zh/option.html#legend.itemStyle)

Object

图例的图形样式。其属性的取值为 `'inherit'` 时，表示继承系列中的属性值。

### 基础属性一览

| 属性                                                         | 值类型 | 说明                                                    |
| ------------------------------------------------------------ | ------ | ------------------------------------------------------- |
| [opacity](https://echarts.apache.org/zh/option.html#legend.itemStyle.opacity) = inherit | number | 图形透明度。支持从 0 到 1 的数字，为 0 时不绘制该图形。 |

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

# grid 网格

直角坐标系内绘图网格，单个 grid 内最多可以放置上下两个 X 轴，左右两个 Y 轴。

## 基础属性一览

| 属性                                                         | 值类型          | 说明                                                         |
| ------------------------------------------------------------ | --------------- | ------------------------------------------------------------ |
| [id](https://echarts.apache.org/zh/option.html#grid.id)      | string          | 图形组件 ID。默认不指定。指定则可用于在 option 或者 API 中引用组件 |
| [show](https://echarts.apache.org/zh/option.html#grid.show) = false | boolean         | 是否显示直角坐标系网格。                                     |
| [borderColor](https://echarts.apache.org/zh/option.html#grid.borderColor) = '#ccc' | Color           | 网格的边框颜色。**注意**：此配置项生效的前提是，设置了 `show: true`。 |
| [borderWidth](https://echarts.apache.org/zh/option.html#legend.borderWidth) = 0 | number          | 图例的边框线宽。                                             |
| [padding](https://echarts.apache.org/zh/option.html#legend.padding) = 5 | number \| Array | 图例内边距，单位px，默认各方向内边距为5，接受数组分别设定上右下左边距。 |
| [itemGap](https://echarts.apache.org/zh/option.html#legend.itemGap) = 10 | number          | 图例每项之间的间隔。横向布局时为水平间隔，纵向布局时为纵向间隔。 |
| [itemWidth](https://echarts.apache.org/zh/option.html#legend.itemWidth) = 25 | number          | 图例标记的图形宽度。                                         |
| [itemHeight](https://echarts.apache.org/zh/option.html#legend.itemHeight) = 14 | number          | 图例标记的图形高度。                                         |

## 距离属性

| 属性                                                         | 值类型           | 说明                                                         |
| ------------------------------------------------------------ | ---------------- | ------------------------------------------------------------ |
| [left](https://echarts.apache.org/zh/option.html#grid.left) = '10%' | string \| number | grid 组件离容器左侧的距离。<br /> `20` 这样的具体像素值，可以是 `'20%'` 这样相对于容器高宽的百分比，<br />也可以是 `'left'`, `'center'`, `'right'`。<br />如果 `left` 的值为`'left'`, `'center'`, `'right'`，组件会根据相应的位置自动对齐。 |
| [top](https://echarts.apache.org/zh/option.html#grid.top) = 60 | string \| number | grid 组件离容器上侧的距离。<br /> `20` 这样的具体像素值，可以是 `'20%'` 这样相对于容器高宽的百分比，<br />也可以是 `'left'`, `'middle'`, `'right'`。<br />如果 `left` 的值为`'left'`, `'middle'`, `'right'`，组件会根据相应的位置自动对齐。 |
| [right](https://echarts.apache.org/zh/option.html#grid.right) = '10%' | string \|number  | grid 组件离容器右侧的距离。<br />`20` 这样的具体像素值，可以是 `'20%'` 这样相对于容器高宽的百分比。 |
| [bottom](https://echarts.apache.org/zh/option.html#grid.bottom) = 60 | string \| number | grid 组件离容器下侧的距离。<br />`20` 这样的具体像素值，可以是 `'20%'` 这样相对于容器高宽的百分比。 |

## [containLabel](https://echarts.apache.org/zh/option.html#grid.containLabel)

`boolean`

grid 区域是否包含坐标轴的[刻度标签](https://echarts.apache.org/zh/option.html#yAxis.axisLabel)。

- containLabel 为 `false` 的时候：
  - `grid.left` `grid.right` `grid.top` `grid.bottom` `grid.width` `grid.height` 决定的是由坐标轴形成的矩形的尺寸和位置。
  - 这比较适用于多个 `grid` 进行对齐的场景，因为往往多个 `grid` 对齐的时候，是依据坐标轴来对齐的。
- containLabel 为 `true` 的时候：
  - `grid.left` `grid.right` `grid.top` `grid.bottom` `grid.width` `grid.height` 决定的是包括了坐标轴标签在内的所有内容所形成的矩形的位置。
  - 这常用于『防止标签溢出』的场景，标签溢出指的是，标签长度动态变化时，可能会溢出容器或者覆盖其他组件

# xAxis

直角坐标系 grid 中的 x 轴，一般情况下单个 grid 组件最多只能放上下两个 x 轴，多于两个 x 轴需要通过配置 [offset](https://echarts.apache.org/zh/option.html#xAxis.offset) 属性防止同个位置多个 x 轴的重叠。

## 基础属性一览

| 属性                                                         | 值类型  | 说明                                                         |
| ------------------------------------------------------------ | ------- | ------------------------------------------------------------ |
| [name](https://echarts.apache.org/zh/option.html#xAxis.name) | string  | 坐标轴名称                                                   |
| [nameLocation](https://echarts.apache.org/zh/option.html#xAxis.nameLocation) = 'end' | string  | 坐标轴名称显示位置。<br />`'start'`、`middle | center`、`end` |
| [offset](https://echarts.apache.org/zh/option.html#xAxis.offset) | number  | X 轴相对于默认位置的偏移。<br />注：若未将 `xAxis.axisLine.onZero` 设为 `false` , 则该项无法生效<br />这一项并不会拉开坐标轴的值和坐标轴名称的距离。 |
| [nameGap](https://echarts.apache.org/zh/option.html#xAxis.nameGap) = 15 | number  | 坐标轴名称与轴线之间的距离。                                 |
| [nameRotate](https://echarts.apache.org/zh/option.html#xAxis.nameRotate) | number  | 坐标轴名字旋转，角度值。**逆时针**                           |
| [scale](https://echarts.apache.org/zh/option.html#xAxis.scale) | boolean | 只在数值轴中（[type](https://echarts.apache.org/zh/option.html#xAxis.type): 'value'）有效。<br />是否是脱离 0 值比例。设置成 `true` 后坐标刻度不会强制包含零刻度。<br />在双数值轴的散点图中比较有用。<br />在设置 [min](https://echarts.apache.org/zh/option.html#xAxis.min) 和 [max](https://echarts.apache.org/zh/option.html#xAxis.max) 之后该配置项无效。 |

## [type](https://echarts.apache.org/zh/option.html#xAxis.type) = 'category'

`string`

坐标轴类型。

可选：

- `'value'` 数值轴，适用于连续数据。

  如果type设置成value，那么，xAxis.data里面设置的数据无效，因为xAxis.data是为category服务的。

  通常来说，数据用一个二维数组表示。如下，每一列被称为一个『维度』 特别地，当只有一个轴为类目轴（axis.type 为 'category'）的时候，数据可以简化用一个一维数组表示:

  ![](https://img-blog.csdnimg.cn/20210310154706695.png)

- `'category'` 类目轴，适用于离散的类目数据。为该类型时类目数据可自动从 [series.data](https://echarts.apache.org/zh/option.html#series.data) 或 [dataset.source](https://echarts.apache.org/zh/option.html#dataset.source) 中取，或者可通过 [xAxis.data](https://echarts.apache.org/zh/option.html#xAxis.data) 设置类目数据。
- `'time'` 时间轴，适用于连续的时序数据，与数值轴相比时间轴带有时间的格式化，在刻度计算上也有所不同，例如会根据跨度的范围来决定使用月，星期，日还是小时范围的刻度。
- `'log'` 对数轴。适用于对数数据。

##  [min](https://echarts.apache.org/zh/option.html#xAxis.min) 和 [max](https://echarts.apache.org/zh/option.html#xAxis.max)

`number` `string` `Function`

坐标轴刻度最小值。

可以设置成特殊值 `'dataMin'`，此时取数据在该轴上的最小值作为最小刻度。

不设置时会自动计算最小值保证坐标轴刻度的均匀分布。

在类目轴中，也可以设置为类目的序数（如类目轴 `data: ['类A', '类B', '类C']` 中，序数 `2` 表示 `'类C'`。也可以设置为负数，如 `-3`）。

当设置成 `function` 形式时，可以根据计算得出的数据最大最小值设定坐标轴的最小值。如：

```css
min: function (value) {
    return value.min - 20;
}
```

## [boundaryGap](https://echarts.apache.org/zh/option.html#xAxis.boundaryGap)

`boolean` `Array`

坐标轴两边留白策略，类目轴和非类目轴的设置和表现不一样。

类目轴中 `boundaryGap` 可以配置为 `true` 和 `false`。默认为 `true`，这时候[刻度](https://echarts.apache.org/zh/option.html#xAxis.axisTick)只是作为分隔线，标签和数据点都会在两个[刻度](https://echarts.apache.org/zh/option.html#xAxis.axisTick)之间的带(band)中间。

非类目轴，包括时间，数值，对数轴，`boundaryGap`是一个两个值的数组，分别表示数据最小值和最大值的延伸范围，可以直接设置数值或者相对的百分比，在设置 [min](https://echarts.apache.org/zh/option.html#xAxis.min) 和 [max](https://echarts.apache.org/zh/option.html#xAxis.max) 后无效。 **示例：**

```css
boundaryGap: ['20%', '20%'],		// 测试不会小于 ["10%", "10%"]，且搭配 scale: true, 比较好
```

## [nameTextStyle](https://echarts.apache.org/zh/option.html#xAxis.nameTextStyle)

### 基础属性一览

| 属性                                                         | 值类型           | 说明                                                         |
| ------------------------------------------------------------ | ---------------- | ------------------------------------------------------------ |
| [lineHeight](https://echarts.apache.org/zh/option.html#xAxis.nameTextStyle.lineHeight) | number           | 行高                                                         |
| [fontWeight](https://echarts.apache.org/zh/option.html#xAxis.nameTextStyle.fontWeight) = 'normal' | string \| number | 坐标轴名称文字字体的粗细。                                   |
| [fontSize](https://echarts.apache.org/zh/option.html#xAxis.nameTextStyle.fontSize) = 12 | number           | 坐标轴名称文字的字体大小。                                   |
| [fontStyle](https://echarts.apache.org/zh/option.html#xAxis.nameTextStyle.fontStyle) = 'normal' | string           | 坐标轴名称文字字体的风格。<br />`'normal'`、`italic`、`oblique` |
| [color](https://echarts.apache.org/zh/option.html#xAxis.nameTextStyle.color) | Color            | 坐标轴名称的颜色，默认取 [axisLine.lineStyle.color](https://echarts.apache.org/zh/option.html#xAxis.axisLine.lineStyle.color) |
| [padding](https://echarts.apache.org/zh/option.html#xAxis.nameTextStyle.padding) | number \| Array  | 文字块的内边距。<br />注意，文字块的 `width` 和 `height` 指定的是内容高宽，不包含 `padding`。 |

## [axisTick](https://echarts.apache.org/zh/option.html#xAxis.axisTick)

坐标轴刻度相关设置。

### 基础属性一览

| 属性                                                         | 值类型  | 说明                           |
| ------------------------------------------------------------ | ------- | ------------------------------ |
| [inside](https://echarts.apache.org/zh/option.html#xAxis.axisTick.inside) = false | boolean | 坐标轴刻度是否朝内，默认朝外。 |
| [length](https://echarts.apache.org/zh/option.html#xAxis.axisTick.length) = 5 | number  | 坐标轴刻度的长度。             |

# echart折线图小圆点去除方式

```css
series: [{symbol: "none"}]
```

设置series下的symbol为none可以直接去除小圆点，图例会变成实心圆

```css
series: [{showSymbol: false}]
```

设置series下的showSymbol为false是不显示小圆点，图例并不会改变





