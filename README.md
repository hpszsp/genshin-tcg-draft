# Genius Invokation TCG draft pick V3.0

Play Genius Invokation TCG in an interesting mode

For Windows & Linux x86_64 zh_CN.utf8

实现了https://www.bilibili.com/video/BV18B4y1d7Wq
中程序征召模式的大部分功能

此外引入了额外的功能，可以通过character.cfg限定及自定义角色池

目前对应原神七圣召唤4.2版本的角色池

# Changelog

## V3.0

代码完全重构。之前的代码结构过于混乱，难以维护。

新版本的代码具有更好的可拓展性。

新版本将不再使用character.cfg，而是使用use.ini和ban.ini

新版本加入了draft-ini工具用于调整配置文件

#### 从V3.0开始，将不再维护Linux版

#### 从V3.0开始，编译好的exe文件将放在bin目录下

## V2.6

改变了主程序名，现在由zzmode改变为draft

修复了Linux终端中重复输出 -> 的问题

修复了build.sh的错误

删除了部分注释

## V2.5

添加了烟绯，坎蒂丝，万叶，妮露，白术，多莉

修改了一处描述：Fixer由“奥兹”改为“菲谢尔”

修改了部分角色在character.cfg的位置，使其与网站ambr.top一致

删除了关于删除配置文件的错误描述
