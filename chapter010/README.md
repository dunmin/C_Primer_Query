# Chapter 10

## 练习 10.1
> 头文件 algorithm 中定义了一个名为 count 的函数，它类似 find， 接受一对迭代器和一个值作为参数。 count 返回给定值在序列中出现的次数。编写程序，读取 int 序列存入vector中，打印有多少个元素的值等于给定值。

``` cpp
int main()
{
    vector<int> x = {1,2,3,5,5,6,6,7,5};
    cout<<count(x.begin(), x.end(), 5)<<endl;
    return 0;
}
```

## 练习 10.2
> 重做上一题，但读取 string 序列存入 list 中。

``` cpp
int main()
{
    list<string> x = {"test","sss","test","ddd","dfsf","ere"};
    cout<<count(x.begin(), x.end(), "test")<<endl;
    return 0;
}
```

## 练习 10.3
> 用 accumulate求一个 vector 中元素之和

``` cpp
int main()
{
    vector<int> vec = {1,2,3,4,5,6};
    int sum = accumulate(vec.begin(),vec.end(),0);
    cout<<sum<<endl;
    return 0;
}
```

## 练习 10.4
> 假定 v 是一个vector，那么调用 accumulate(v.cbegin(),v.cend(),0) 有何错误（如果存在的话）

``` cpp
结果回事int类型
```

## 练习 10.5
> 在本节对名册（roster）调用equal 的例子中，如果两个名册中保存的都是C风格字符串而不是string，会发生什么？

``` cpp
C风格字符串是用指向字符的指针表示的，因此会比较两个指针的值（地址），而不会比较这两个字符串的内容。
```

## 练习 10.6
> 编写程序，使用```fill_n```将一个序列中的```int```值都设置为 0

``` cpp
int main()
{
    vector<int> vec = {1,2,3,4,5,6};
    fill_n(vec.begin(), vec.size(), 0);
    for(auto x:vec){
        cout<<x<<endl;
    }
    return 0;
}
```

## 练习 10.7 -important
> 下面程序是否有错误？如果有，请改正：

``` cpp
(a) vector<int> vec; list<int> lst; int i;
	while (cin >> i)
		lst.push_back(i);
	copy(lst.cbegin(), lst.cend(), vec.begin());
(b) vector<int> vec;
	vec.reserve(10);
	fill_n(vec.begin(), 10, 0);
```

```cpp
(a) 应该加一条语句 vec.resize(lst.size()) 。copy 时必须保证目标目的序列至少要包含与输入序列一样多的元素。
(b) 从语句上来说没错误，这段代码没有任何结果。但是从逻辑上来说，应该将 vec.reserve(10) 改为 vec.resize(10)
```

## 练习 10.8
> 本节提到过，标准库算法不会改变它们所操作的容器的大小。为什么使用 back_inserter 不会使这一断言失效？

``` cpp
back_inserter 是插入迭代器，在 iterator.h 头文件中，不是标准库的算法。
```

## [练习 10.9](exercise_10.9.cpp)
> 实现你自己的```elimDups```。分别在读取输入后、调用```unique```后以及调用```erase```后打印```vector```的内容

## 练习 10.10
> 你认为算法不改变容器大小的原因是什么？

``` cpp
算法的接口是迭代器，而迭代器用来改变容器。这样的设计使得算法具有通用性。
```

## [练习 10.13](exercise_10.13.cpp)
> 标准库定义了名为 partition 的算法，它接受一个谓词，对容器内容进行划分，使得谓词为true 的值会排在容器的前半部分，而使得谓词为 false 的值会排在后半部分。算法返回一个迭代器，指向最后一个使谓词为 true 的元素之后的位置。编写函数，接受一个 string，返回一个 bool 值，指出 string 是否有5个或更多字符。使用此函数划分 words。打印出长度大于等于5的元素。

## 练习 10.14
> 编写一个 lambda ，接受两个int，返回它们的和。

``` cpp
auto f = [](int a, int b) {return a+b;};
```

## 练习 10.15
> 编写一个 lambda ，捕获它所在函数的 int，并接受一个 int参数。lambda 应该返回捕获的 int 和 int 参数的和

``` cpp
void func(){
    int x = 2;
    auto f = [x](int y){return x+y;};
    cout<<f(1)<<endl;
}
```

## [练习 10.20](exercise_10.20.cpp)
> 标准库定义了一个名为 count_if 的算法。类似 find_if，此函数接受一对迭代器，表示一个输入范围，还接受一个谓词，会对输入范围中每个元素执行。count_if返回一个计数值，表示谓词有多少次为真。使用count_if重写我们程序中统计有多少单词长度超过6的部分。

## 练习 10.21 -important
> 编写一个 lambda，捕获一个局部 int 变量，并递减变量值，直至它变为0。一旦变量变为0，再调用lambda应该不再递减变量。lambda应该返回一个bool值，指出捕获的变量是否为0。

``` cpp
void func(){
    int x = 10;
    auto f = [&x]{return x?x--:0;};
    while(f()){
        cout<<x<<endl;
    }
}
```

## 练习 [10.22](exercise_10.22.cpp)
> 重写统计长度小于等于6的单词数量的程序，使用函数代替 lambda

## 练习 10.23
> bind 接受几个参数？

``` cpp
假设被绑定的函数接受 n 个参数，那么bind 接受 n + 1 个参数。
```

## 练习 10.24
> 解释三种迭代器的不同之处

``` cpp
back_inserter 使用 push_back 。
front_inserter 使用 push_front 。
inserter 使用 insert，此函数接受第二个参数，这个参数必须是一个指向给定容器的迭代器。元素将被插入到给定迭代器所表示的元素之前。
```

## [练习 10.27](exercise_10.27.cpp)
> 除了 unique 之外，标准库还定义了名为 unique_copy 的函数，它接受第三个迭代器，表示拷贝不重复元素的目的位置。编写一个程序，使用 unique_copy将一个vector中不重复的元素拷贝到一个初始化为空的list中

## [练习 10.29](exercise_10.29.cpp)
> 编写程序，使用流迭代器读取一个文本文件，存入一个vector中的string里

## [练习 10.33](exercise_10.33.cpp)
> 编写程序，接受三个参数：一个输入文件和两个输出文件的文件名。输入文件保存的应该是整数。使用 istream_iterator 读取输入文件。使用 ostream_iterator 将奇数写入第一个输入文件，每个值后面都跟一个空格。将偶数写入第二个输出文件，每个值都独占一行

## 练习 10.34
> 使用 reverse_iterator 逆序打印一个vector。

``` cpp
vector<int> vec = {1,2,3,4};
for(auto iter = vec.crbegin();iter!=vec.crend();iter++){
    cout<<*iter<<endl;
}
```

## 练习 10.35 - Que
> 使用普通迭代器逆序打印一个vector

``` cpp
vector<int> vec = {1,2,3,4};
for(auto iter = vec.cend()-1;iter!=vec.cbegin()-1;iter--){
    cout<<*iter<<endl;
}
```

## 练习 10.36 
> 使用 find 在一个 int 的list 中查找最后一个值为0的元素

```cpp
list<int> vec = {1,2,3,4,0,1,0,7};
auto iter = find(vec.crbegin(),vec.crend(),0);
cout<<*iter<<endl;
```

## 练习 10.38
> 列出5个迭代器类别，以及每类迭代器所支持的操作。

``` cpp
输入迭代器 : ==,!=,++,*,->
输出迭代器 : ++,*
前向迭代器 : ==,!=,++,*,->
双向迭代器 : ==,!=,++,--,*,->
随机访问迭代器 : ==,!=,<,<=,>,>=,++,--,+,+=,-,-=,*,->,iter[n]==*(iter[n])
```

## 练习 10.39
> list 上的迭代器属于哪类？vector呢？

``` cpp
list: 双向迭代器
vector: 随机访问迭代器
```

## 练习 10.40
> 你认为 copy 要求哪类迭代器？reverse 和 unique 呢？

``` cpp
copy: 需要两个输入迭代器，一个输出迭代器
reverse: 需要双向迭代器
unique: 需要随机访问迭代器
```

## [练习 10.42](exercise_10.42.cpp)
