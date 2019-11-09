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