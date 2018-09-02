# CSP-Practice
### This preject is used for practicing programming skills and pass the CSP in this autumn.
* 201803-1-jump.cpp 跳一跳
* 201803-2-ball.cpp 碰撞小球
   * 逻辑上的要点：1.碰撞，边界改变运动方向 2.变量记录每个小球的位置，方向 3.通过轨道状态判断是否发生碰撞
   * 碰到的坑：1.小球移动后没有更新轨道状态 2.多个循环使用相同的临时变量，造成变量值被错误更改
   
* 201712-1-min-diff.cpp 最小差值
   * 算法思路很简单，先排序，然后相邻的元素求差的最小值
   * 启示在于，可以用标准库中的vector，sort等减少代码量