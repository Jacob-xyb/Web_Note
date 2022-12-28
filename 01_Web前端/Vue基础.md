# Vue 简介

1. JavaScript框架
2. 简化 DOM 操作
3. 响应式数据驱动

# Vue2 与 Vue3 的区别

- 最大的区别就是初始化的不同

  ```js
  // Vue 2x
  let vm = new Vue({
      el: "#box",
      data: {
      }
  })
  
  // Vue 3x
  let obj = {
      data() {
          return {
              myname: "Jacob",
          }
      },
      methods: {
      }
  }
  Vue.createApp(obj).mount("#box");
  ```

  

# class与style

## Vue 2x

后续添加属性拦截： `Vue.set(对象, 属性, true)`

```js
let vm = new Vue({
    el: "#box",
    data: {
        classobj: {
            aa: true,
            bb: true,
            cc: false,
        }
    }
})

Vue.set(vm.classobj, "dd", true)
```

# 条件渲染

## 映射显示

```html
<div id="box">
    <div v-if="isCreated">1111</div>
    <div v-if="!isCreated">2222</div>
    <ul>
        <li v-for="item in datalist">
            {{item.title}} --
            <span v-if="item.state===0">未付款</span>
            <span v-else-if="item.state===1">已发货</span>
            <span v-else-if="item.state===2">已完成</span>
        </li>
    </ul>
</div>
<script>
    let obj = {
        data() {
            return {
                isCreated: true,
                datalist: [
                    {
                        title: "111",
                        state: 0,
                    },
                    {
                        title: "222",
                        state: 1,
                    },
                    {
                        title: "333",
                        state: 2,
                    }
                ],
            }
        },
    }
    Vue.createApp(obj).mount("#box");
</script>
```

