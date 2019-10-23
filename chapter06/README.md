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

## 练习 6.16
> 下面的这个函数虽然合法，但是不算特别有用。指出它的局限性并设法改善。
```
bool is_empty(string& s) { return s.empty(); }
```


``` cpp
//s不会再函数中修改，应该定义成const
bool is_empty(const string& s) { return s.empty(); }
```

## 练习 6.17
> 编写一个函数，判断string对象中是否含有大写字母。编写另一个函数，把string对象全部改写成小写形式。在这两个函数中你使用的形参类型相同吗？为什么？

``` cpp
不同，前一个应该用const string&而后一个是string&
```

## 练习 6.18
> 为下面的函数编写函数声明，从给定的名字中推测函数具备的功能。
+ 名为 compare 的函数，返回布尔值，两个参数都是 matrix 类的引用。
+ 名为 change_val 的函数，返回vector的迭代器，有两个参数：一个是int，另一个是vector的迭代器。

``` cpp
(a) bool compare(const matrix&,const matrix&);
(b) vector<int>::iterator change_val(int,vector<int>::iterator);
```

## 练习 6.19
> 假定有如下声明，判断哪个调用合法、哪个调用不合法。对于不合法的函数调用，说明原因。
```
double calc(double);
int count(const string &, char);
int sum(vector<int>::iterator, vector<int>::iterator, int);
vector<int> vec(10);
```

``` cpp
(a) calc(23.4, 55.1);               // error: 参数超过限制
(b) count("abcda",'a');             // ok
(c) calc(66);                       // ok,int可以转double
(d) sum(vec.begin(), vec.end(), 3.8);   // ok, 但是3.8会被截成3
```

## 练习 6.20
> 引用形参什么时候应该是常量引用？如果形参应该是常量引用，而我们将其设为了普通引用，会发生什么情况？

``` cpp
(a) 当在函数中不修改形参的时候
(b) 那么常量实参将无法作用于普通引用形参
```

## [练习 6.21](exercise_6.21.cpp)
> 编写一个函数，令其接受两个参数：一个是int型的数，另一个是int指针。函数比较int的值和指针所指的值，返回较大的那个。在该函数中指针的类型应该是什么？

``` cpp
指针类型应该是const int *,因为函数中没有修改，同时保证传入的参数不受到限制
```

## [练习 6.22](exercise_6.22.cpp) - important

``` cpp
void swap_pointer(int *&var1,int *&var2)                // 改成int *var1,int *var2是没有效果的
{                                                       // 形参必须是指针的引用
    swap(var1,var2);
}
int *p1 = &a,*p2 = &b;                                   // swap_pointer(&a,&b);也不行，因为不能   
swap_pointer(p1,p2);                                     // &a是const不能修改
```


## 练习 6.24
> 描述下面这个函数的行为。如果代码中存在问题，请指出并改正。
```
void print(const int ia[10])
{
	for (size_t i = 0; i != 10; ++i)
		cout << ia[i] << endl;
}
```

``` cpp
// 数组不能作为形参传递
void print(const int （&ia)[10])
{
	for (size_t i = 0; i != 10; ++i)
		cout << ia[i] << endl;
}
```

## [练习 6.25](exercise_6.25.cpp)

## [练习 6.26](exercise_6.26.cpp)
题目要求与**6.25**相同，但是这里的写法更优雅

## [练习 6.27](exercise_6.27.cpp)

## 练习 6.28
> 在error_msg函数的第二个版本中包含ErrCode类型的参数，其中循环内的elem是什么类型

``` cpp
const string &
```

## 练习 6.29 -important
> 在范围for循环中使用initializer_list对象时，应该将循环控制变量声明成引用类型吗？为什么？

``` cpp
应该使用常量引用类型。initializer_list 对象中的元素都是常量，我们无法修改initializer_list 对象中的元素的值。
```