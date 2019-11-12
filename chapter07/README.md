# Chapter 7

## 练习 7.4
> 编写一个名为Person的类，使其表示人员的姓名和地址。使用string对象存放这些元素，接下来的练习将不断充实这个类的其他特征。

``` cpp
// Person.h
#ifndef PERSON_H
#define PERSON_H
#include <string>

class Person
{
    public:
        Person();
        virtual ~Person();
        std::string name;
        std::string address;
    protected:
    private:
};

#endif // PERSON_H
```


## 练习 7.5
> 在你的Person类中提供一些操作使其能够返回姓名和地址。这些函数是否应该是const的呢？解释原因。

``` cpp
应该是const,因为要返回函数中并不修改成员同时常量也要使用这个函数
```

## 练习 7.6
> 对于函数add、read和print，定义你自己的版本。


``` cpp
Sales_data& Sales_data::combine(Sales_data &rhs){
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

std::istream &read(std::istream& is, Sales_data& rhs)
{
    double price  = 0;
    is>>rhs.bookNo>>rhs.units_sold>>price;
    rhs.revenue = price * rhs.units_sold;
    return is;
}
std::ostream &print(std::ostream& os, Sales_data& rhs)
{
    os<<rhs.isbn()<<" "<<rhs.units_sold<<" "<<rhs.revenue;
    return os;
}
```

## 练习 7.8
> 为什么read函数将其Sales_data参数定义成普通的引用，而print函数将其参数定义成常量引用

``` cpp
因为read函数修改其引用对象的值而print不修改
```

## 练习 7.9
> 对于7.1.2节练习中代码，添加读取和打印Person对象的操作。

``` cpp
std::istream &read(std::istream& is, Person& rhs)
{
    is>>rhs.name>>rhs.address;
    return is;
}
std::ostream &print(std::ostream& os, Person& rhs)
{
    os<<rhs.address<<" "<<rhs.name;
    return os;
}
```

## 练习 7.10
> 在下面这条if语句中，条件部分的作用是什么？
```
if (read(read(cin, data1), data2))
```

``` cpp
从输入中读取两个值给data1和data2对象
```

## 练习 7.11
> 在你的Sales_data类中添加构造函数，然后编写一段程序令其用到每个构造函数。

[Sales_data.h](exercise_7.xh.cpp) | [Sales_data.cpp](exercise_7.xc.cpp) | [main.cpp](exercise_7.7.cpp)


## 练习 7.12
> 把只接受一个istream 作为参数的构造函数移到类的内部。

``` cpp
Sales_data(std::istream is)
{
    read(is, *this);
}
```

## 练习 7.14
> 编写一个构造函数，令其用我们提供的类内初始值显式地初始化成员

```cpp
Sales_data() : units_sold(0) , revenue(0) { }
```

## 练习 7.15
> 为你的 Person 类添加正确的构造函数。

``` cpp
Person() = default;
Person(const string &sname,const string &saddress):
                name(sname),address(saddress)
```


## 练习 7.16
> 在类的定义中对于访问说明符出现的位置和次数有限定吗？如果有，是什么？什么样的成员应该定义在public 说明符之后？什么样的成员应该定义在private 说明符之后？

``` cpp
(1) 没有限定
(2) 如果某个成员能够在整个程序内都被访问，那么它应该定义为 public; 如果某个成员只能在类内部访问，那么它应该定义为 private
```

## 练习 7.17
> 使用class 和 struct 时有区别吗？如果有，是什么？

``` cpp
使用class和struct定义类唯一的区别就是默认的访问权限
```

## 练习 7.18 - important
> 封装是何含义？它有什么用处？

``` cpp
将类内部分成员设置为外部不可见，而提供部分接口给外面，这样的行为叫做封装。封装隐藏了具体的实现，当我们使用某个抽象数据类型时，只需要考虑它提供什么接口操作，而不用去考虑它的具体实现。
```

## 练习 7.19
> 在你的Person 类中，你将把哪些成员声明成public 的？哪些声明成private 的？解释你这样做的原因。

``` cpp
构造函数等其他对外接口getAddress()、getName()是public,类的成员定义为private
```

## 练习 7.20
> 友元在什么时候有用？请分别举出使用友元的利弊。

``` cpp
当其他类或者函数想要访问当前类的私有变量时，这个时候应该用友元。很方便但是牺牲了封装性与可维护性。
```

## 练习 7.21
> 修改你的Sales_data 类使其隐藏实现的细节。你之前编写的关于Sales_data操作的程序应该继续使用，借助类的新定义重新编译该程序，确保其正常工作。

[Sales_data.h](exercise_7.21.h) | [Sales_data.cpp](exercise_7.21.cpp)

## 练习 7.25 -important
> Screen 能安全地依赖于拷贝和赋值操作的默认版本吗？如果能，为什么？如果不能？为什么？

``` cpp
能。Screen 的成员只有内置类型和 string，因此能安全地依赖于拷贝和赋值操作的默认版本。管理动态内存的类则不能依赖于拷贝和赋值操作的默认版本，而且也应该尽量使用string 和 vector 来避免动态管理内存的复杂性。
```

## 练习 7.27
> 给你自己的Screen 类添加move、set 和display 函数，通过执行下面的代码检验你的类是否正确。
```
Screen myScreen(5, 5, 'X');
myScreen.move(4, 0).set('#').display(cout);
cout << "\n";
myScreen.display(cout);
cout << "\n";
```

[Screen.h](exersise7.27_Screen.h) | [Screen.h](exersise7.27_Screen.cpp) |[Screen.h](exersise_7.27.cpp)

## 练习 7.28
> 如果move、set和display函数的返回类型不是Screen& 而是Screen，则在上一个练习中将会发生什么情况？

``` cpp
move,set,display改变的不是同一个对象
```

## 练习 7.30 -important
> 通过this指针使用成员的做法虽然合法，但是有点多余。讨论显示使用指针访问成员的优缺点。

``` cpp
优点:
(1) 程序的意图更明确
(2) 函数的参数可以与成员同名，如
void setAddr(const std::string &addr) { this->addr = addr; }

缺点:
有时候显得有点多余
```

## 练习 7.31
> 定义一对类X 和Y，其中X 包含一个指向 Y 的指针，而Y 包含一个类型为 X 的对象。

``` cpp
class Y;

class X{
	Y* y = nullptr;	
};

class Y{
	X x;
};
```

## 练习 7.33
> 如果我们给Screen 添加一个如下所示的size成员将发生什么情况？如果出现了问题，请尝试修改它。

```cpp
// pos在类作用域之外，出现错误
Screen::pos Screen::size() const {
    return height * width;
}
```

## 练习 7.34 -important
> 如果我们把第256页Screen类的pos的typedef放在类的最后一行会发生什么情况？

``` cpp
除了在成员函数体内之外，其他地方都用不了pos,包括dummy_fcn处形参的height的类型pos
```

## 练习 7.35 -important
> 解释下面代码的含义，说明其中的Type和initVal分别使用了哪个定义。如果代码存在错误，尝试修改它。
 
``` cpp
typedef string Type;
Type initVal();                                 // Type是string 
class Exercise {
public:
    typedef double Type;                        // 覆盖为double
    Type setVal(Type);                          // 返回类型与形参都是double
    Type initVal();                             // double
private:
    int val;
};
Type Exercise::setVal(Type parm) {         // 返回类型应该是Exercise::Type,不修改则返回类型是string
    val = parm + initVal();                     // 使用的是类成员函数initVal
    return val;
}
```

## 练习 7.36
> 下面的初始值是错误的，请找出问题所在并尝试修改它。

```
struct X {
	X (int i, int j): base(i), rem(base % j) {}
	int rem, base;
};
```

``` cpp
// 根据定义顺序，rem会被先初始化，而此时base&j得不到想要的效果
struct X {
	X (int i, int j): base(i), rem(base % j) {}
	int base,rem;
};
```

## 练习 7.37
> 使用本节提供的Sales_data类，确定初始化下面的变量时分别使用了哪个构造函数，然后罗列出每个对象所有的数据成员的值。

``` cpp
Sales_data first_item(cin);           // 使用 Sales_data(std::istream &is)
int main() {
	Sales_data next;                  // 使用 Sales_data(std::string s = "");
    Sales_data last("9-999-99999-9"); // 使用 Sales_data(std::string s = "");
}
```

## 练习 7.38
> 有些情况下我们希望提供cin作为接受istream& 参数的构造函数的默认实参，请声明这样的构造函数。

``` cpp
Sale_data(std::istream &is = std::cin);
```

## 练习 7.39
> 如果接受string 的构造函数和接受 istream& 的构造函数都使用默认实参，这种行为合法吗？如果不，为什么？

``` cpp
不合法，这样默认初始化的时候就不知道调用哪一个了
```

## 练习 7.43
> 假定有一个名为 NoDefault 的类，它有一个接受 int 的构造函数，但是没有默认构造函数。定义类 C，C 有一个 NoDefault 类型的成员，定义C 的默认构造函数。

``` cpp
class C{
    C():x(0){}
    Nodefault x;
}
```

## 练习 7.44
> 下面这条声明合法吗？如果不，为什么？
```
vector<NoDefault> vec(10);
```

``` cpp
该语句会执行NoDefault的默认构造函数，但是NoDefault没有默认构造函数
```

## 练习 7.45
> 如果在上一个练习中定义的vector的元素类型是C，则声明合法吗？为什么？

``` cpp
合法，因为C有默认构造函数
```

## 练习 7.46
> 下面哪些论断是不正确的？为什么？

```
(a) 一个类必须至少提供一个构造函数。
(b) 默认构造函数是参数列表为空的构造函数。
(c) 如果对于类来说不存在有意义的默认值，则类不应该提供默认构造函数。
(d) 如果类没有定义默认构造函数，则编译器将为其生成一个并把每个数据成员初始化成相应类型的默认值。
```

``` cpp
(a) 错误，不提供的话会有合成的默认构造函数
(b) 不完全正确。为每个参数都提供了默认值的构造函数也是默认构造函数。
(c) 错误，哪怕没有意义的值也需要初始化。
(d)  不正确。只有当一个类没有定义任何构造函数的时候，编译器才会生成一个默认构造函数。
```

## 练习 7.47
> 说明接受一个string 参数的Sales_data构造函数是否应该是explicit的，并解释这样做的优缺点。

``` cpp
取决于需要，如果是explicit那么就可抑制隐式，但有时候不是explicit更加方便一点
```

## 练习 7.48
> 假定Sales_data 的构造函数不是explicit的，则下述定义将执行什么样的操作？
```
string null_isbn("9-999-9999-9");
Sales_data item1(null_isbn);
Sales_data item2("9-999-99999-9");
```

``` cpp
调用构造函数和是不是explicit没关系
```

## 练习 7.49 -QUE
> 对于combine 函数的三种不同声明，当我们调用i.combine(s) 时分别发生什么情况？其中i是一个Sales_data，而 s是一个string对象。

``` cpp
(a) Sales_data &combine(Sales_data);            // ok: string转Sale_data
(b) Sales_data &combine(Sales_data&);// error C2664: 无法将参数 1 从“std::string”转换“Sales_data &”
(c) Sales_data &combine(const Sales_data&) const; //该成员函数是const 的，意味着不能改变对象。而combine函数的本意就是要改变对象
```

## 练习 7.51
> vector 将其单参数的构造函数定义成 explicit 的，而string则不是，你觉得原因何在？

``` cpp
func(vector<int>&)传一个整数，然后转换成vector<int>临时量使用没什么意义，而给func(string)传一个c风格字符串，之后转换成string处理，使得很多地方都能用字符串字面值代替string 
```