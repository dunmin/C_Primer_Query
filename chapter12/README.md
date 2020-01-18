# Chapter 12

## 练习 12.1
> 在此代码的结尾，b1 和 b2 各包含多少个元素？
``` 
StrBlob b1;
{
	StrBlob b2 = {"a", "an", "the"};
	b1 = b2;
	b2.push_back("about");
}
```

``` cpp
操作的是同一个vector, 都包含4个元素。在代码的结尾, b2被析构了, b2不存在，b1不影响，还是4个元素
```

## 练习 12.3
> StrBlob 需要const 版本的push_back 和 pop_back吗？如需要，添加进去。否则，解释为什么不需要
``` cpp
不需要。push_back 和 pop_back 会改变对象的内容。而 const 对象是只读的，因此不需要
```

## 练习 12.4
> 在我们的 check 函数中，没有检查 i 是否大于0。为什么可以忽略这个检查

``` cpp
因为 size_type 是一个无符号整型，当传递给 check 的参数小于 0 的时候，参数值会转换成一个正整数
```

## 练习 12.5
> 我们未编写接受一个```initializer_list explicit```参数的构造函数。讨论这个设计策略的优点和缺点

``` cpp
构造函数不是 explicit 的，意味着可以从 initializer_list 隐式转换为 StrBlob。在 StrBlob 对象中，只有一个数据成员 data，而 StrBlob 对象本身的含义，也是一个管理字符串的序列。因此，从 initializer_list 到 StrBlob 的转换，在逻辑上是可行的。而这个设计策略的缺点，可能在某些地方我们确实需要 initializer_list，而编译器仍会将之转换为 StrBlob
```

## [练习 12.6](exercise_12.6.cpp)
> 编写函数，返回一个动态分配的 int 的vector。将此vector 传递给另一个函数，这个函数读取标准输入，将读入的值保存在 vector 元素中。再将vector传递给另一个函数，打印读入的值。记得在恰当的时刻delete vector


## [练习 12.7](exercise_12.7.cpp)
> 重做上一题，这次使用 shared_ptr 而不是内置指针

## 练习 12.8
> 下面的函数是否有错误？如果有，解释错误原因。

```
bool b() {
	int* p = new int;
	// ...
	return p;
}
```

``` cpp
有错误。没有释放指针 p
```

## 练习 12.9
> 解释下面代码执行的结果
```
int *q = new int(42), *r = new int(100);
r = q;
auto q2 = make_shared<int>(42), r2 = make_shared<int>(100);
r2 = q2;
```

``` cpp
(1) 动态分配内存给q, r，初始化为42和100
(2) 将r指向q所指向的内存空间 （找不回q了，内存泄漏了）
(3) 创建一个智能指针q2, r2, 也初始化为42和100
(4) 将q2指向r2所指向的地址(q2所指内存空间被销毁)
```