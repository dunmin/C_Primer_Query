# Chapter 5

## 练习 6.1
> 实参和形参的区别的什么？

``` cpp
实参是函数调用的实际值，是形参的初始值。
```

## 练习 6.2
> 请指出下列函数哪个有错误，为什么？应该如何修改这些错误呢？

``` cpp
(a) int f() {
          string s;
          // ...
          return s;                             // 返回类型错误
    }
(b) f2(int i) { /* ... */ }                     // 无返回类型
(c) int calc(int v1, int v1)  /* ... */ }       // 缺少{
(d) double square (double x)  return x * x;     // 函数必须有花括号
```

## 练习 6.8
> 编写一个名为Chapter6.h 的头文件，令其包含6.1节练习中的函数声明。

``` cpp
// chapter6.h
#ifndef CHAPTER6_H_INCLUDED
#define CHAPTER6_H_INCLUDED
int func(int,int);
#endif // CHAPTER6_H_INCLUDED
```

``` cpp
// main
#include <iostream>
#include <stdexcept>
#include "chapter6.h"

using namespace std;

int func(int a,int b){
    cout<<a+b<<endl;
}

int main()
{
    func(1,2);
    return 0;
}

```

## [练习 6.10](exercise_6.10.cpp)

## [练习 6.11](exercise_6.11.cpp)

## [练习 6.12](exercise_6.12.cpp)

## 练习6.13
> 假设 T 是某种类型的名字，说明以下两个函数声明的区别：一个是void f(T), 另一个是 void f(&T)。

``` cpp
void f(T) 是值传递
void f(&T) 是引用传递
```

## 练习 6.14
> 举一个形参应该是引用类型的例子，再举一个形参不能是引用类型的例子。

``` cpp
(a) 当交换两个string类型的函数时，应该用引用类型传递，否则复制拷贝比较低效
(b) 当形参只想在函数内改变，但是不想影响到函数外的时候不能用引用类型
```

## 练习 6.15
> 说明find_char 函数中的三个形参为什么是现在的类型，特别说明为什么s是常量引用而occurs是普通引用？为什么s和occurs是引用类型而c不是？如果令s是普通引用会发生什么情况？如果令occurs是常量引用会发生什么情况？

``` cpp
(a) s是string,为了减少拷贝的开销所以使用引用，但是在函数中又不对其进行修改，所以使用const, occurs的改变需要影响到函数外，所以用引用，c两者都不是所以就是普通引用
(b) s在函数中不修改所以用const,occurs在函数中会变化所以不用const
(c) c是char，拷贝开销无需考虑，外部也无需修改，所以不需要作为引用类型，
(d) c非引用类型即便修改也不会影响外部，因此也不需要const
(e) 如果s是普通引用对程序没有影响，但是如果无意中修改了s的值不会报错，难以发现
(f) 如果occurs是常量引用那么在函数中修改occurs会产生错误
```