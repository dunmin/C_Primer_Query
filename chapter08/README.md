# Chapter 8

## [练习 8.1](exercise_8.1.cpp)
> 编写函数，接受一个istream&参数，返回值类型也是istream&。此函数须从给定流中读取数据，直至遇到文件结束标识时停止。它将读取的数据打印在标准输出上。完成这些操作后，在返回流之前，对流进行复位，使其处于有效状态

## 练习 8.2
> 测试函数，调用参数为cin

``` cpp
Ref. 练习 8.1
```

## 练习 8.3 -important
什么情况下，下面的while循环会终止？
```
while (cin >> i) /*  ...    */
```

``` cpp
如果 badbit、failbit、eofbit 的任一个被置位，那么检测流状态的条件会失败
```

## 练习 8.4 
> 编写函数，以读模式打开一个文件，将其内容读入到一个string的vector中，将每一行作为一个独立的元素存于vector中。

``` cpp
void readfunc(string infile)
{
    ifstream input(infile);
    if(input){
        vector<string> read_in;
        string x;
        while(getline(input, x)){
            read_in.push_back(x);
        }
        for(auto x:read_in){
            cout<<x<<endl;
        }
    }
}
```

## 练习 8.5
> 重写上面的程序，将每个单词作为一个独立的元素进行存储。

``` cpp
getline(input, x) 换成 input>>x
```


## [练习 8.9](exercise_8.9.cpp)
> 使用你为8.1.2节第一个练习所编写的函数打印一个istringstream对象的内容。

## [练习 8.10](exercise_8.10.cpp)
> 编写程序，将来自一个文件中的行保存在一个vector中。然后使用一个istringstream从vector读取数据元素，每次读取一个单词。

## 练习 8.11
> 本节的程序在外层while循环中定义了istringstream 对象。如果record 对象定义在循环之外，你需要对程序进行怎样的修改？重写程序，将record的定义移到while 循环之外，验证你设想的修改方法是否正确。

``` cpp
string line, word;
vector<PersonInfo> people;
istringstream record;
while (getline(cin, line))
{
	PersonInfo info;
	record.clear();
	record.str(line);           // 增加这一句
	record >> info.name;
	while (record >> word)
		info.phones.push_back(word);
	people.push_back(info);
}
```

## 练习 8.12
> 我们为什么没有在PersonInfo中使用类内初始化？

``` cpp
因为这里只需要聚合类就够了，所以没有必要在 PersionInfo 中使用类内初始化。
```

## 练习 8.14 -important
> 我们为什么将entry和nums定义为```const auto& ？```

```
1. 避免拷贝，节省开销，所以用引用
2. 在程序中不会改变值所以用const
```