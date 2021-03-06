# Chapter 4

## 练习 4.1
> 表达式 5 + 10 * 20 / 2 的求值结果是多少？

``` cpp
105
```

## 练习 4.2
> 根据4.12节中的表，在下述表达式的合理位置添加括号，使得添加括号后运算对象的组合顺序与添加括号前一致。  
```
(a) *vec.begin()       
(b) *vec.begin() + 1
```

``` cpp
(a) *(vec.begin())       
(b) (*(vec.begin())) + 1
```

## 练习 4.3 - impotant
> C++语言没有明确规定大多数二元运算符的求值顺序，给编译器优化留下了余地。这种策略实际上是在代码生成效率和程序潜在缺陷之间进行了权衡，你认为这可以接受吗？请说出你的理由。

[Ref-github.com/huangmingchuan/](https://github.com/huangmingchuan/Cpp_Primer_Answers/tree/master/ch04)
``` cpp
可以接受。
C++的设计思想是尽可能地“相信”程序员，将效率最大化。然而这种思想却有着潜在的危害，就是无法控制程序员自身引发的错误。因此 Java 的诞生也是必然，Java的思想就是尽可能地“不相信”程序员。
```

## 练习 4.4
> 在下面的表达式中添加括号，说明其求值过程及最终结果。编写程序编译该（不加括号的）表达式并输出结果验证之前的推断。  
```
12 / 3 * 4 + 5 * 15 + 24 % 4 / 2
```

```
((((12 / 3) * 4) + (5 * 15)) + ((24 % 4) / 2))
```

## 练习 4.5
> 写出下列表达式的求值结果。  
```
(a) -30 * 3 + 21 / 5
(b) -30 + 3 * 21 / 5
(c) 30 / 3 * 21 % 5
(d) -30 / 3 * 21 % 4
```

``` cpp
(a) 86          (b) -18
(c) 0           (d) -2
```

## 练习 4.6
> 写出一条表达式用于确定一个整数是奇数还是偶数。

``` cpp
if(x % 2 == 0){
    // 偶数
}
else {
    // 奇数
}
```

## 练习 4.7
> 溢出是何含义？写出三条将导致溢出的表达式。

``` cpp
// 当计算的结果超出该类型所能表示的范围时就会产生溢出
short a = 32767;
a + =1;             // 溢出
unsigned int b = 0;
b--;                // 溢出
```

## 练习 4.8
> 说明在逻辑与、逻辑或及相等性运算符中运算对象的求值顺序。

+ 逻辑与, 逻辑或先计算左侧对象值，满足条件再计算右侧
+ 相等性运算符无规定


## 练习 4.9
> 解释在下面的if语句中条件部分的判断过程
```
const char *cp = "Hello World";
if (cp && *cp)
```

``` cpp
先判断cp是指针且非空,接着判断*cp，*cp为'H'也非空，因此为真，执行循环内
```

## 练习 4.10
> 为while 循环写一个条件，使其从标准输入中读取整数，遇到 42 时停止。

``` cpp
int a;
while(cin>>a&&a!=42){
    //..
}
```

## 练习 4.11
> 书写一条表达式用于测试4个值a、b、c、d的关系，确保a大于b、b大于c、c大于d。

``` cpp
if(a>b && b>c && c>d){
    //...
}
```

## 练习 4.12-important
> 假设i、j 和k 是三个整数，说明表达式 i != j < k 的含义。

``` cpp
运算顺序为i!=(j<k)
(1) j<k: j是否小于k，返回bool
(2) bool所转换成的整数(0或1)是否等于i，返回bool
```

## 练习 4.13
> 在下述语句中，当赋值完成后 i 和 d 的值分别是多少？  
``` cpp
int i;   double d;
(a) d = i = 3.5;        // i = 3 d = 3.0
(b) i = d = 3.5;        // i = 3 d = 3.5
```

## 练习 4.14
> 执行下述 if 语句后将发生什么情况？

``` cpp
if (42 = i)   // 编译错误
if (i = 42)   // i的值为42，非0，true，执行循环
```

## 练习 4.15
> 下面的赋值是非法的，为什么？应该如何修改？
```
double dval; int ival; int *pi;
dval = ival = pi = 0;
```

``` cpp
pi(指针)不能赋值给ival(int)
```

## 练习 4.16
> 尽管下面的语句合法，但它们实际执行的行为可能和预期并不一样，为什么？应该如何修改？

``` cpp
if (p = getPtr() != 0)  // 执行顺序(p = (getPtr() != 0))导致p的值是关系运算符得到的bool值转化得到的
if (i = 1024)           // 总是为true, 本意应该是i==1024
```

## 练习 4.17
> 说明前置递增运算符和后置递增运算符的区别

``` cpp
递增递减运算符都必须作用于左值对象，前置版本将对象本身作为左值返回，后置版本将对象原始值的副本作为右值返回
```

## 练习 4.18
> 如果132页那个输出vector对象元素的while循环使用前置递增运算符，将得到什么结果？

``` cpp
从第二个非负数开始输出，输出一个负数后结束，或者到最后解析尾元素的下一位而导致溢出
```

## 练习 4.19 important
> 假设 ptr 的类型是指向 int 的指针、vec 的类型是vector、ival 的类型是int，说明下面的表达式是何含义？如果有表达式不正确，为什么？应该如何修改？

```cpp
(a) ptr != 0 && *ptr++  // ptr非空则解引用ptr后递增指针
(b) ival++ && ival      // 判断ival和ival+1是否都非空，因为&&左侧先计算后计算右侧，因此和c一样出现未定义行为的情况
(c) vec[ival++] <= vec[ival] // 出现错误，因为<=两边的计算顺序不确定，应该修改为vec[ival] <= vec[ival+1]
```

## 练习 4.20
> 假设```iter```的类型是 ```vector<string>::iterator```, 说明下面的表达式是否合法。如果合法，表达式的含义是什么？如果不合法，错在何处？
``` cpp
(a) *iter++;                // 返回iter所指对象的值，之后将iter加1
(b) (*iter)++;              // 将iter所指对象的值加1之后返回(但是不合法,因为string没有++操作)
(c) *iter.empty();          // error: 先执行点运算符，但是由于指针没有成员，出现错误
(d) iter->empty();          // 返回iter所指对象是否为空
(e) ++*iter;                // 将iter所指对象的值加1之后返回(但是不合法,因为string没有++操作)
(f) iter++->empty();        // important: 判断iter是否为空之后将iter加1
```

## [练习 4.21](exercise_4.21.cpp)
> 编写一段程序，使用条件运算符从 vector 中找到哪些元素的值是奇数，然后将这些奇数值翻倍。

## 练习 4.22
> 本节的示例程序将成绩划分为high pass、pass 和 fial 三种，扩展该程序使其进一步将 60 分到 75 分之间的成绩设定为 low pass。要求程序包含两个版本：一个版本只使用条件运算符；另一个版本使用1个或多个if语句。哪个版本的程序更容易理解呢？为什么？

```
使用if-else的比较好理解，因为当条件运算符嵌套多层之后，代码可读性急剧下降，而if-else则比较清晰
```

## 练习 4.23
因为运算符的优先级问题，下面这条表达式无法通过编译。根据4.12节中的表指出它的问题在哪里？应该如何修改？
```
string s = "word";
string pl = s + s[s.size() - 1] == 's' ? "" : "s" ;
```

加法优先级较高，应该改为
``` cpp
string pl = s + (s[s.size() - 1] == 's' ? "" : "s") ;
```

## 练习 4.24
> 本节的示例程序将成绩划分为 high pass、pass、和fail三种，它的依据是条件运算符满足右结合律。假如条件运算符满足的是左结合律，求值的过程将是怎样的？

``` cpp
finalgrade = (grade>90)?"high pass":(grade<60)?"fail":"pass";
如果满足的是左结合律，那么将会先计算(grade>90)，如果成立则返回"high pass"不成立在返回(grade<60)，返回的值作为?"fail":"pass";的条件，从而返回"fail"或者"pass"给finalgrade
即相当于
finalgrade = ((grade > 90) ? "high pass" : (grade < 60)) ? "fail" : "pass";
```

## 练习 4.25
> 如果一台机器上 int 占 32 位、char 占8位，用的是 Latin-1 字符集，其中字符'q' 的二进制形式是 01110001，那么表达式'q' << 6的值是什么？

``` cpp
01110001扩展为int为00000000 00000000 00000000 01110001
左移6位，右边补0左边舍弃
00000000 00000000 00011100 01000000
```

## 练习 4.26
> 在本节关于测验成绩的例子中，如果使用```unsigned int```作为```quiz1```的类型会发生什么情况？

``` cpp
有些机器unsigned int可能只有16位，因此结果未定义 
```

## 练习 4.27
> 下列表达式的结果是什么？

``` cpp
unsigned long ul1 = 3, ul2 = 7;
(a) ul1 & ul2                       // 前24位为0，后8位00000011 & 00000111 = 00000011 = 3 
(b) ul1 | ul2                       // 前24位为0，后8位00000011 | 00000111 = 00000111 = 7
(c) ul1 && ul2                      // 返回true
(d) ul1 || ul2                      // 返回true
```

## [练习 4.28](exercise_4.28.cpp)
> 编写一段程序，输出每一种内置类型所占空间的大小。


## 练习 4.29
> 推断下面代码的输出结果并说明理由。实际运行这段程序，结果和你想象的一样吗？如不一样，为什么？

``` cpp
int x[10];   int *p = x;
cout << sizeof(x)/sizeof(*x) << endl;           // 结果为10
cout << sizeof(p)/sizeof(*p) << endl;           // 结果为4/4 = 1 [impotant]
                                                // 这里的*p指向x,x代表的是头元素，因此也是4字节
```

## 练习 4.30
> 根据4.12节中的表，在下述表达式的适当位置加上括号，使得加上括号之后的表达式的含义与原来的含义相同。
```
(a) sizeof x + y      
(b) sizeof p->mem[i]  
(c) sizeof a < b     
(d) sizeof f()  
```

``` cpp
(a) (sizeof x) + y      
(b) sizeof (p->mem[i])  
(c) (sizeof a) < b     
(d) sizeof (f())  
```

## 练习 4.31
> 本节的程序使用了前置版本的递增运算符和递减运算符，解释为什么要用前置版本而不用后置版本。要想使用后置版本的递增递减运算符需要做哪些改动？使用后置版本重写本节的程序。

```
根据c++ primer page132-Ref, 后置做法需要保存一个递增前的值作为拷贝，加大了开销，因此可以使用前置也可以使用后置的情况下，应使用前置。
后置重写则将全部前置的地方换成后置，无需其他改动
```

## 练习 4.32
> 解释下面这个循环的含义。
```
constexpr int size = 5;
int ia[size] = { 1, 2, 3, 4, 5 };
for (int *ptr = ia, ix = 0;
    ix != size && ptr != ia+size;
    ++ix, ++ptr) { /* ... */ }
```

```cpp
遍历数组ia,同时使用其下标和对应指针
```

## 练习 4.33 - important
> 根据4.12节中的表说明下面这条表达式的含义。

```
someValue ? ++x, ++y : --x, --y
```

``` cpp
,优先级最低，则原式实际组合顺序 (someValue ? ++x, ++y : --x), --y
即someValue为true,则递增x,y,否则递减x。结束之后递减y并返回递减后的值
```

## 练习 4.34
> 根据本节给出的变量定义，说明在下面的表达式中奖发生什么样的类型转换：

``` cpp
(a) if (fval)                       // fval将转换成bool
(b) dval = fval + ival;             // ival将转换成float,与fval相加之后转换成double
(c) dval + ival * cval;             // cval将提升成int，之后和ival相加，再转成double
```

## 练习 4.35
> 假设有如下的定义,请回答在下面的表达式中发生了隐式类型转换吗？如果有，指出来。
```
char cval;
int ival;
unsigned int ui;
float fval;
double dval;
```

``` cpp
(a) cval = 'a' + 3;                             // 'a'提升成int,之后加3后转成char
(b) fval = ui - ival * 1.0;                     // ival转成double,之后ui转成double,之后一起转成float
(c) dval = ui * fval;                           // ui转成float,相乘后转换成double
(d) cval = ival + fval + dval;          // ival转成float,与fval相加后转成double,与dval相加后转成char
```

## 练习 4.36
> 假设 i 是int类型，d 是double类型，书写表达式 i*=d 使其执行整数类型的乘法而非浮点类型的乘法。

``` cpp
i *= static_cast<int>(d);
```

## 练习 4.37 -important
> 用命名的强制类型转换改写下列旧式的转换语句。
```
int i; double d; const string *ps; char *pc; void *pv;
(a) pv = (void*)ps;
(b) i = int(*pc);
(c) pv = &d;
(d) pc = (char*)pv;
```

``` cpp
int i; double d; const string *ps; char *pc; void *pv;
(a) pv = static_cast<void*>(const_cast<string*>(ps));
(b) i = static_cast<int>(*pc);
(c) pv = static_cast<void*>(&d);
(d) pc = static_cast<void*>(pv);
```

## 练习 4.38
> 说明下面这条表达式的含义。

``` cpp
double slope = static_cast<double>(j/i);    // 将j/i的结果值转换为 double，然后赋值给slope
```