# Chapter 9

## 练习 9.1
> 对于下面的程序任务，vector、deque和list哪种容器最为适合？解释你的选择的理由。如果没有哪一种容器优于其他容器，也请解释理由

```
(a) 读取固定数量的单词，将它们按字典序插入到容器中。我们将在下一章中看到，关联容器更适合这个问题。
(b) 读取未知数量的单词，总是将单词插入到末尾。删除操作在头部进行。
(c) 从一个文件读取未知数量的整数。将这些数排序，然后将它们打印到标准输出。
```

``` cpp
(a) list因为进行频繁的插入操作，或者用vector之后再排序也行
(b) deque因为操作都是在首尾
(c) vector，尾部插入，之后排序
```

## 练习 9.2
> 定义一个list对象，其元素类型是int的deque

``` cpp
list<deque<int> > de_list;
```

## 练习 9.3
> 构成迭代器范围的迭代器有何限制？

``` cpp
(1) 它们指向同一个容器中的元素，或者是容器最后一个元素之后的位置。
(2) 我们可以通过反复递增 begin 来到达 end。换句话说，end 不在 begin 之前。
```

## 练习 9.4
> 编写函数，接受一对指向```vector```的迭代器和一个```int```值。在两个迭代器指定的范围中查找给定的值，返回一个布尔值来指出是否找到。

```cpp
bool search_int(vector<int>::const_iterator start, vector<int>::const_iterator endd, int num)
{
    for(vector<int>::const_iterator iter = start;iter!=endd;iter++){
        if((*iter)==num){
            return true;
        }
    }
    return false;
}
```

## 练习 9.5
> 重写上一题的函数，返回一个迭代器指向找到的元素。注意，程序必须处理未找到给定值的情况。

``` cpp
vector<int>::const_iterator search_int(vector<int>::const_iterator start, vector<int>::const_iterator endd, int num)
{
    for(vector<int>::const_iterator iter = start;iter!=endd;iter++){
        if((*iter)==num){
            return iter;
        }
    }
    return endd;
}
```

## 练习 9.6
> 下面的程序有何错误？你应该如何修改它？
```
list<int> lst1;
list<int>::iterator iter1 = lst1.begin(),
					iter2 = lst1.end();
while (iter1 < iter2) /* ... */
```

``` cpp
改为iter1!=iter2, 因为list中没有实现<，因为list存放元素的地址不是连续的
通常情况下所有容器的迭代器我们都使用!=,因为这才是所有容器都实现了的通用操作
```

## 练习 9.7
> 为了索引int 的 vector中的元素，应该使用什么类型？

``` cpp
vector<int>::size_type
```

## 练习 9.8
> 为了读取string的list中的元素，应该使用什么类型？如果写入list，又应该使用什么类型？

``` cpp
(1) list<string>::const_iterator
(2) list<string>::iterator
```

## 练习 9.9
> begin 和 cbegin 两个函数有什么不同？
``` cpp
begin 返回的是普通迭代器，cbegin 返回的是常量迭代器
```

## 练习 9.10
> 下面4个对象分别是什么类型？

``` cpp
vector<int> v1;
const vector<int> v2; 
auto it1 = v1.begin(), it2 = v2.begin();       //error, auto应该是相同类型而it1, it2类型不同
auto it3 = v1.cbegin(), it4 = v2.cbegin();
// it1是vector<int>::iterator
// it2, it3, it4是vector<int>::const_iterator
```

## 练习 9.11
> 对6种创建和初始化 vector 对象的方法，每一种都给出一个实例。解释每个vector包含什么值。\

``` cpp
vector<int> vec;    // 0
vector<int> vec(10);    // 10 * 0
vector<int> vec(10, 1);  // 10 * 1
vector<int> vec{ 1, 2, 3, 4, 5 }; // 1, 2, 3, 4, 5
vector<int> vec(other_vec); // 拷贝 other_vec 的元素
vector<int> vec(other_vec.begin(), other_vec.end()); // 拷贝 other_vec 的元素
```

## 练习 9.12
> 对于接受一个容器创建其拷贝的构造函数，和接受两个迭代器创建拷贝的构造函数，解释它们的不同。

``` cpp
(1) 接受一个容器创建其拷贝的构造函数，必须容器类型和元素类型都相同。
(2) 接受两个迭代器创建拷贝的构造函数，不要求容器类型相同，要求元素类型相同或者能转换成要初始化的容器的元素类型
```

## 练习 9.13
> 如何从一个list初始化一个vector？从一个vector又该如何创建？编写代码验证你的答案。

``` cpp
list<int> ilst(5, 4);
vector<int> ivc(5, 5);

vector<double> dvc(ilst.begin(), ilst.end());
vector<int> dvc2(ivc);
vector<double> dvc3(ivc.begin(), ivc.end());
```

## [练习 9.14](exercise_9.14.cpp)
> 编写程序，将一个list中的char * 指针元素赋值给一个vector中的string。

## 练习 9.15
> 编写程序，判定两个vector是否相等。

``` cpp
vector<int> x = {1,2,3,4};
vector<int> y(4,3);
cout<<(x==y)<<endl;
```

## 练习 9.16
> 重写上一题的程序，比较一个list中的元素和一个vector中的元素。

``` cpp
vector<int> x = {1,2,3,4};
list<int> y = {1,3,2,4};
list<int>::iterator iter = y.begin();
for(int i=0;i<3;i++) iter++;
cout<<(x[3]==(*iter))<<endl;
```

## 练习 9.17
> 假定c1 和 c2 是两个容器，下面的比较操作有何限制？
```
if (c1 < c2)
```

``` cpp
(1) c1,c2必须是相同类型的容器并且保存相同类型的元素
(2) c1,c2中的元素类型要支持关系运算符
```

## [练习 9.18](exercise_9.18.cpp)
> 编写程序，从标准输入读取string序列，存入一个deque中。编写一个循环，用迭代器打印deque中的元素

## [练习 9.19](exercise_9.19.cpp)
> 重写上一题的程序，用list替代deque。列出程序要做出哪些改变

``` cpp
没啥改变，把deque的地方换成list就可以，他们都有push_back()操作
```

## [练习 9.20](exercise_9.20.cpp)
> 编写程序，从一个list拷贝元素到两个deque中。值为偶数的所有元素都拷贝到一个deque中，而奇数值元素都拷贝到另一个deque中。

## 练习 9.21
> 如果我们将第308页中使用 insert 返回值将元素添加到list中的循环程序改写为将元素插入到vector中，分析循环将如何工作。

```
与原来相同，都是反复在最前插元素
```

## 练习 9.22 - Que
> 假定iv是一个int的vector，下面的程序存在什么错误？你将如何修改？
``` 
vector<int>::iterator iter = iv.begin(),
					  mid = iv.begin() + iv.size() / 2;
while (iter != mid)
	if (*iter == some_val)
		iv.insert(iter, 2 * some_val);
```

``` cpp
insert之后，迭代器就会失效，修改为
while (iter != mid)
{
	if (*iter == some_val)
	{
		iter = v.insert(iter, 2 * some_val);
		++iter;
    }
	++iter;
}
```

## 练习 9.23
> 在本节第一个程序中，若 c.size() 为1，则val、val2、val3和val4的值会是什么？

``` cpp
都会是同一个值
```

## [练习 9.24](exercise_9.24.cpp)
> 编写程序，分别使用 at、下标运算符、front 和 begin 提取一个vector中的第一个元素。在一个空vector上测试你的程序。

## 练习 9.25
> 对于第312页中删除一个范围内的元素的程序，如果```elem1```与```elem2```相等会发生什么？如果```elem2```是尾后迭代器，或者```elem1```和```elem2```皆为尾后迭代器，又会发生什么？

``` cpp
(1)如果elem1和elem2相等，那么不会发生任何操作
(2)如果elem2 是尾后迭代器，那么删除从elem1到最后的元素
(3)如果两者皆为尾后迭代器，也什么都不会发生
```

## [练习 9.26](exercise_9.26.cpp)
> 使用下面代码定义的ia，将ia 拷贝到一个vector和一个list中。是用单迭代器版本的erase从list中删除奇数元素，从vector中删除偶数元素。

## [练习 9.27](exercise_9.27.cpp)
> 编写程序，查找并删除forward_list中的奇数元素。

## 练习 9.29
> 假定vec包含25个元素，那么vec.resize(100)会做什么？如果接下来调用vec.resize(10)会做什么？
```
vec.resize(100)：将75个值为0(默认初始化值)的元素添加到vec的末尾
vec.resize(10)：从vec的末尾删除90个元素
```

## 练习 9.30
> 接受单个参数的resize版本对元素类型有什么限制（如果有的话）？

```
元素类型必须提供一个默认构造函数。
```

## 练习 9.31 -important
> 第316页中删除偶数值元素并复制奇数值元素的程序不能用于list或forward_list。为什么？修改程序，使之也能用于这些类型。

```cpp
复合赋值语句只能用于string、vector、deque、array
iter+=2 修改为 iter++
如果是forward_list还需要一个prev
```

## 练习 9.32 -important
> 在第316页的程序中，向下面语句这样调用insert是否合法？如果不合法，为什么？

``` cpp
iter = vi.insert(iter, *iter++);            // 不合法,因为参数的求值顺序是未定的
```

## 练习 9.33
> 在本节最后一个例子中，如果不将insert的结果赋予begin，将会发生什么？编写程序，去掉此赋值语句，验证你的答案。

```cpp
begin会失效，程序死循环
```

## 练习 9.34
> 假定vi是一个保存int的容器，其中有偶数值也有奇数值，分析下面循环的行为，然后编写程序验证你的分析是否正确。
```
iter = vi.begin();
while (iter != vi.end())
	if (*iter % 2)
		iter = vi.insert(iter, *iter);
	++iter;
```

``` cpp
程序对每一个奇数前添加一个这个奇数的副本，之后iter指向新增的副本，这种情况迭代器递增之后还是指向该奇数，因此进入死循环。
```

## 练习 9.35
> 解释一个vector的capacity和size有何区别。

``` cpp
容器的size是指已经保存的元素的数目，
capacity则是在不分配新内存的情况下最多可以保存多少元素
```

## 练习 9.36
> 一个容器的capacity可能小于它的size吗？

``` cpp
不可能
```

## 练习 9.37
> 为什么list或array没有capacity成员函数？

``` cpp
list是链表，不需要存储在连续空间，为新元素单独开一个空间即可
array不允许该变容器大小
```

## 练习 9.39
> 解释下面程序片段做了什么：
```
vector<string> svec;
svec.reserve(1024);
string word;
while (cin >> word)
	svec.push_back(word);
svec.resize(svec.size() + svec.size() / 2);
```

``` cpp
(a) 创建一个空的vector<string>
(b) 将容器的capacity扩大至1024
(c) 输入多个word存储到svec中
(d) 将svec的元素个数调整为原来大概1.5倍，即后面补上一半元素个数的空string
(e) 如果元素个数超出了capacity，则还会自动扩大capacity
```

## 练习 9.40
> 如果上一题的程序读入了256个词，在resize之后容器的capacity可能是多少？如果读入了512个、1000个、或1048个呢？

``` cpp
(a) 256：1024
(b) 512: 1024
(c) 1000: 2048 (假定规模翻倍的话)
(d) 1048: 2048 (假定规模翻倍的话)
```

## 练习 9.41
> 编写程序，从一个vector<char>初始化一个string

``` cpp
vector<char> v{ 'h', 'e', 'l', 'l', 'o' };
string str(v.cbegin(), v.cend());
```

## 练习 9.42 -important
> 假定你希望每次读取一个字符存入一个string中，而且知道最少需要读取100个字符，应该如何提高程序的性能？

``` cpp
使用 reserve(100) 函数预先分配100个元素的空间。
```

## [练习 9.43](exercise_9.43.cpp)
> 编写一个函数，接受三个string参数是s、oldVal 和newVal。使用迭代器及insert和erase函数将s中所有oldVal替换为newVal。测试你的程序，用它替换通用的简写形式，如，将"tho"替换为"though",将"thru"替换为"through"。

## 练习 9.44
> 重写上一题的函数，这次使用一个下标和replace。
``` cpp
// 上一题的s.erase()和s.insert()换成：
s.replace(curr, curr+old_val.size(),new_val.begin(), new_val.end());
```

## [练习 9.47](exercise_9.47.cpp)
> 编写程序，首先查找string"ab2c3d7R4E6"中每个数字字符，然后查找其中每个字母字符。编写两个版本的程序，第一个要使用find_first_of，第二个要使用find_first_not_of。

## 练习 9.48
> 假定```name```和```numbers```的定义如325页所示，```numbers.find(name)```返回什么？

``` cpp
string::npos
```

## [练习 9.50](exercise_9.50.cpp)
> 编写程序处理一个vector，其元素都表示整型值。计算vector中所有元素之和。修改程序，使之计算表示浮点值的string之和