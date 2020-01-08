# Chapter 11

## 练习 11.1
> 描述map 和 vector 的不同

``` cpp
map 是关联容器， vector 是顺序容器
```

## 练习 11.2
> 分别给出最适合使用 list、vector、deque、map以及set的例子

``` cpp
list：双向链表，适合频繁插入删除元素的场景
vector：适合频繁访问元素的场景
deque：双端队列，适合频繁在头尾插入删除元素的场景
map：字典
set：适合有序不重复的元素的场景
```

## [练习 11.4](exercise_11.3.cpp) 
> 编写你自己的单词计数程序

## [练习 11.4](exercise_11.4.cpp) 
> 扩展你的程序，忽略大小写和标点。例如，"example."、"example,"和"Example"应该递增相同的计数器

## 练习 11.5
> 解释map和set的区别。你如何选择使用哪个？

``` cpp
map是键值对，set只有值是一个集合
```

## 练习 11.6 - important
> 解释set和list 的区别。你如何选择使用哪个？

``` cpp
set 是有序不重复集合，底层实现是红黑树，而 list 是无序可重复集合，底层实现是链表
```

##  练习 11.7
> 定义一个map，关键字是家庭的姓，值是一个vector，保存家中孩子（们）的名。编写代码，实现添加新的家庭以及向已有家庭中添加新的孩子

``` cpp
map<string, vector<int>> houses;
string house = "ling";
string name = "name"
houses[newhouse].push_back(name);
```

## 练习 11.8
> 编写一个程序，在一个vector而不是一个set中保存不重复的单词。使用set的优点是什么

``` cpp
vector每添加一个元素就要循环判断是否存在， 而set的优点是集合本身的元素就是不重复
```

## 练习 11.9
> 定义一个map，将单词与一个行号的list关联，list中保存的是单词所出现的行号。

``` cpp
map<string, list<int>> mapper;
```

## 练习 11.10 - imporatnt
> 可以定义一个vector::iterator 到 int 的map吗？list::iterator 到 int 的map呢？对于两种情况，如果不能，解释为什么

``` cpp
可以定义 vector<int>::iterator 到 int 的map，但是不能定义 list<int>::iterator 到 int 的map。因为map的键必须实现 < 操作，list 的迭代器不支持比较运算。
```

## 练习 11.11
> 不使用decltype 重新定义 bookstore

``` cpp
multiset<Sales_data, bool (*)(const Sales_data &lhs, const Sales_data &rhs)> map_list(compareIsbn);
```

## [练习 11.12](exercise_11.12.cpp)
> 编写程序，读入string和int的序列，将每个string和int存入一个pair 中，pair保存在一个vector中

## 练习 11.13
> 在上一题的程序中，至少有三种创建pair的方法。编写此程序的三个版本，分别采用不同的方法创建pair。解释你认为哪种形式最易于编写和理解，为什么？

``` cpp
pair_vec.push_back({name, score});
pair_vec.push_back(make_pair(name, score));
pair_vec.push_back(pair<string, int>(name, score));
```

## 练习 11.15
> 对一个int到vector<int>的map，其mapped_type、key_type和 value_type分别是什么？

``` cpp
mapped_type: vector<int>
key_type:int
value_type:pair<const int, vector<int>>
```

## 练习 11.16
> 使用一个map迭代器编写一个表达式，将一个值赋予一个元素。

``` cpp
std::map<int, string>::iterator it = m.begin();
it->second = "hello";
```

## 练习 11.17 -important
> 假定 c 是一个string的multiset，v 是一个string 的vector，解释**下面**的调用。指出每个调用是否合法：

``` cpp
copy(v.begin(), v.end(), inserter(c, c.end()));
copy(v.begin(), v.end(), back_inserter(c));
copy(c.begin(), c.end(), inserter(v, v.end()));
copy(c.begin(), c.end(), back_inserter(v));
第二个调用不合法，因为 multiset 没有 push_back 方法。其他调用都合法。
```

## 练习 11.18
> 写出第382页循环中map_it 的类型，不要使用auto 或 decltype

``` cpp
map<string, size_t>::const_iterator = word_count.cbegin();
```

## 练习 11.20
> 重写11.1节练习的单词计数程序，使用insert代替下标操作。你认为哪个程序更容易编写和阅读？解释原因

``` cpp
使用 insert 更容易阅读和编写。insert 有返回值，可以明确的体现出插入操作的结果。
```

## 练习 11.21
> 假定word_count 是一个 string 到 size_t 的map，word 是一个string，解释下面循环的作用：

``` cpp
单词不在容器中则添加单词，value值为0，在的话就递增计数器统计单词出现的次数
```

## 练习 11.22
> 给定一个```map<string, vector<int>>```，对此容器的插入一个元素的insert版本，写出其参数类型和返回类型

``` cpp
参数类型：pair<string, vector<int>>
返回类型：pair<map<string, vector<int>>::iterator, bool>
```

## 练习 11.24
> 下面的程序完成什么功能？
```
map<int, int> m;
m[0] = 1;
```

``` cpp
添加一个元素到 map 中，如果该键存在，则重新赋值
```

## 练习 11.25
> 对比下面的程序与上一题程序
```
vector<int> v;
v[0] = 1;
```

``` cpp
未定义行为，vector 的下标越界访问。
```

## 练习 11.26
> 可以用什么类型来对一个map进行下标操作？下标运算符返回的类型是什么？请给出一个具体例子——即，定义一个map，然后写出一个可以用来对map进行下标操作的类型以及下标运算符将会返会的类型。

``` cpp
map<int, std::string> m;
关键字类型：key_type
返回类型：mapped_type
```

## 练习 11.27
> 对于什么问题你会使用count来解决？什么时候你又会选择find呢？

``` cpp
对于允许重复关键字的容器，应该用 count ; 对于不允许重复关键字的容器，应该用 find
```

## 练习 11.28
> 对一个string到int的vector的map，定义并初始化一个变量来保存在其上调用find所返回的结果。

``` cpp
map<string, vector<int>> m;
map<string, vector<int>>::iterator it = m.find("key");
```

## 练习 11.29
> 如果给定的关键字不在容器中，upper_bound、lower_bound 和 equal_range 分别会返回什么？

``` cpp
如果给定的关键字不在容器中，则 lower_bound和 upper_bound 会返回相等的迭代器，指向一个不影响排序的关键字插入位置。而equal_range 会返回一个 pair，pair 中的两个迭代器都指向关键字可以插入的位置
```

## 练习 11.30
> 对于本节最后一个程序中的输出表达式，解释运算对象pos.first->second的含义

``` cpp
pos 是一个 pair，pos.first 是一个迭代器，指向匹配关键字的元素，该元素是一个 pair，访问该元素的第二个成员
```

## [练习 11.31](exercise_11.31.cpp)
> 编写程序，定义一个作者及其作品的multimap。使用find在multimap中查找一个元素并用erase删除它。确保你的程序在元素不在map 中时也能正常运行。

## 练习 11.34
> 如果你将transform 函数中的find替换为下标运算符，会发生什么情况？

``` cpp
如果使用下标运算符，当关键字未在容器中时，会往容器中添加一个新元素
```

## 练习 11.35 -important
> 在buildMap中，如果进行如下改写，会有什么效果？
```
trans_map[key] = value.substr(1);
//改为
trans_map.insert({key, value.substr(1)});
```

``` cpp
当一个转换规则的关键字多次出现的时候，使用下标运算符会保留最后一次添加的规则，而用insert则保留第一次添加的规则。
```

## 练习11.37
> 一个无序容器与其有序版本相比有何优势？有序版本有何优势？

``` cpp
无序容器拥有更好的性能，有序容器使得元素始终有序。
```