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

## [练习 3.17](exercise_3.17.cpp)

## [练习 3.22](exercise_3.22.cpp)

## [练习 3.24](exercise_3.24.cpp)

## 练习 3.26
> important

因为迭代器之间只支持相减运算而不支持相加，将```beg```加上相减后得到的距离的一半，表示将```beg```移到中间位置

## [练习 3.43](exercise_3.43.cpp)

## [练习 3.44](exercise_3.44.cpp)

## [练习 3.45](exercise_3.45.cpp)


