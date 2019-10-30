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

## 练习 6.30
> 编译第200页的str_subrange函数，看看你的编译器是如何处理函数中的错误的。

``` cpp
Gcc中编译不会出错但是运行可能会出现错误
```

## 练习 6.31 -important
> 什么情况下返回的引用无效？什么情况下返回常量的引用无效？

``` cpp
当返回的是对局部变量的引用时无效，当希望修改返回的变量时，返回常量的引用无效
```

## 练习 6.32
> 下面的函数合法吗？如果合法，说明其功能；如果不合法，修改其中的错误并解释原因。
```
int &get(int *array, int index) { return array[index]; }
int main()
{
    int ia[10];
    for (int i = 0; i != 10; ++i)
        get(ia, i) = i;
}
```

``` cpp
合法，引用返回的是左值
```

## [练习 6.33](exercise_6.33.cpp)

## 练习 6.34
> 如果factorial 函数的停止条件如下所示，将发生什么？
```
if (val != 0)
```

``` cpp
结果一样
```

## 练习 6.35
> 在调用factorial 函数时，为什么我们传入的值是 val-1 而非 val--？

```
那么传给下一层函数的就是val而不是val-1了，会陷入无限的递归调用
```

## [练习 6.36](exercise_6.36.cpp)

## [练习 6.37](exercise_6.37.cpp) -important

## 练习 6.38
> 修改arrPtr函数，使其返回数组的引用。

``` cpp
decltype(odd) &arrPtr(int i)
{
    return (i%2)?odd:even;
} 
```

## 练习 6.39
> 说明在下面的每组声明中第二条语句是何含义。如果有非法的声明，请指出来。

``` cpp
(a) int calc(int, int);
	int calc(const int, const int);         // 错误，顶层const不能作为重载依据
(b) int get();
	double get();                           // 错误，返回类型不能作为重载依据
(c) int *reset(int *);
	double *reset(double *);                // 正确
```

## 练习 6.40
> 下面的哪个声明是错误的？为什么？

``` cpp
(a) int ff(int a, int b = 0, int c = 0);                // 正确
(b) char *init(int ht = 24, int wd, char bckgrnd);	    // 错误，有默认实参的形参后面都 应该有默认实参
```

## 练习 6.41
> 下面的哪个调用是非法的？为什么？哪个调用虽然合法但显然与程序员的初衷不符？为什么？

``` cpp
char *init(int ht, int wd = 80, char bckgrnd = ' ');
(a) init();                         // 非法，缺少一个参数值
(b) init(24,10);                    // 合法: init(24,10,' ')
(c) init(14,'*');                   // 合法，但是不是所希望的表达,'*'匹配的是wd,会被转成int,给wd，而不是赋值给bckgrnd
```

## 练习 6.42
> 给make_plural函数的第二个形参赋予默认实参's', 利用新版本的函数输出单词success和failure的单数和复数形式。

``` cpp
string make_plural(size_t ctr, const string &word, const string &ending = "s")
{
    return (ctr>1)? word + ending : word;
}

// 输出successs
make_plural(2,"success")
```

## 练习 6.43
> 你会把下面的哪个声明和定义放在头文件中？哪个放在源文件中？为什么？

``` cpp
(a) inline bool eq(const BigInt&, const BigInt&) {...}  // 内联函数,放到我文件中
(b) void putValues(int *arr, int size);                 // 声明，也放到头文件中
```

## 练习 6.44
> 将6.2.2节(第189页)的isShorter函数改写成内联函数。

``` cpp
inline bool isShorter(const string &s1, const string &s2)
{
    return s1.size() < s2.size();
}
```

## 练习 6.46
> 能把isShorter函数定义成constexpr函数吗？如果能，将它改写成constxpre函数；如果不能，说明原因。

``` cpp
constexpr类型要求返回值和形参都是字面值类型，所以不行
```

## [练习 6.47](exercise_6.47.cpp)

## 练习 6.48
> 说明下面这个循环的含义，它对assert的使用合理吗？
```
string s;
while (cin >> s && s != sought) { } //空函数体
assert(cin);
```

``` cpp
合理，当输入结束但没有输入sought时，cin为false则,assert终止程序,如果有输入等于sought,则cin还没结束循环就结束，那么cin为true,不终止程序，在assert下一句补充cout<<true<<endl;就可以实现输入sought就输出true的功能
```

## 练习 6.49
> 什么是候选函数？什么是可行函数？

``` cpp
候选函数：与被调用函数同名，并且其声明在调用点可见。
可行函数：形参与实参的数量相等，并且每个实参类型与对应的形参类型相同或者能转换成形参的类型。
```

## 练习 6.50
> 已知有第217页对函数 f 的声明，对于下面的每一个调用列出可行函数。其中哪个函数是最佳匹配？如果调用不合法，是因为没有可匹配的函数还是因为调用具有二义性？

``` cpp
(a) f(2.56, 42)                     // 二义性             
(b) f(42)                           // 最佳匹配f(int)
(c) f(42, 0)                        // 最佳匹配f(int,int)
(d) f(2.56, 3.14)                   // 最佳匹配f(double,double)
```

## [练习 6.51](exercise_6.51.cpp)

## 练习6.52
> 已知有如下声明：请指出接下来调用中每个类型转换的等级
```
void manip(int ,int);
double dobj;
```

``` cpp
(a) manip('a', 'z');                // 第三级
(b) manip(55.4, dobj);              // 第四级
```

## 练习 6.53
> 说明下列每组声明中的第二条语句会产生什么影响，并指出哪些不合法（如果有的话）。

``` cpp
(a) int calc(int&, int&); 
	int calc(const int&, const int&);           // ok
(b) int calc(char*, char*);
	int calc(const char*, const char*);         // ok   
(c) int calc(char*, char*);
	int calc(char* const, char* const);         // 上层const造成二义性
```

## 练习 6.54
> 编写函数的声明，令其接受两个int形参并返回类型也是int；然后声明一个vector对象，令其元素是指向该函数的指针。

``` cpp
int func(int,int);
vector<decltype(func)*> q;
```

## 练习 6.55
> 编写4个函数，分别对两个int值执行加、减、乘、除运算；在上一题创建的vector对象中保存指向这些函数的指针。

``` cpp
int add(int a,int b);
int minu(int a,int b);
int multiply(int a,int b);
int division(int a,int b);
q.push_back(add);
q.push_back(minu);
q.push_back(multiply);
q.push_back(division);
```

## [练习 6.56](exercise_6.56.cpp)