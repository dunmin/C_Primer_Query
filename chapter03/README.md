# Chapter 3

## 练习 3.7
将```auto&```修改为```char&```则没有区别，修改成```char```则字符串不会变化

## 练习 3.9
不合法，使用下标访问空字符串

## 练习 3.11
如果省略部分修改了```c```则不合法，若没有修改则合法

## 练习 3.13
``` cpp
(a) vector<int> v1;                 // size:0
(b) vector<int> v2(10);             // size:10, value:0
(c) vector<int> v3(10, 42);         // size:10, value:42
(d) vector<int> v4{ 10 };           // size:1,  value:10
(e) vector<int> v5{ 10, 42 };       // size:2,  value:10, 42
(f) vector<string> v6{ 10 };        // size:10, value:""
(g) vector<string> v7{ 10, "hi" };  // size:10, value:"hi"
```

## [练习3.17](exercise_3.17.cpp)
