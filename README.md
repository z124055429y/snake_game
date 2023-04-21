# Snake Game

## 系统要求

- macos
- 类Unix系统需要手动调整终端窗口大小，并调整`run.sh`

## 功能:

- 欢迎界面
- 障碍物&随机生成食物
- 蛇的移动
- 碰撞&吃食物
- 积分功能

## 总结

- 信号机制 && 定时器
- curses库使用
- cmake管理项目
- googleUnit测试
- 封装(分离了游戏元素GameElement，游戏控制Controller，以及游戏渲染Render，并统一由Game对象制定规则&管理交互)
