# Chapter 5

## 练习 5.4
> 说明下列例子的含义，如果存在问题，试着修改它。
```
(a) while (string::iterator iter != s.end()) { /* . . . */ }
(b) while (bool status = find(word)) { /* . . . */ }
		if (!status) { /* . . . */ }
```

``` cpp
(a) iter每次都被默认初始化，比较是否是s.end(),达不到效果
(b) 在while之外使用status,而status是定义在循环内的，因此报错
```

## [练习 5.11](exercise_5.11.cpp)

## [练习 5.14](exercise_5.14.cpp)

## 练习 5.15
> 说明下列循环的含义并改正其中的错误。

``` cpp
(a) for (int ix = 0; ix != sz; ++ix) { /* ... */ }
    if (ix != sz)                           // ix不在作用与范围内
    	// . . .
(b) int ix;
    for (ix != sz; ++ix) { /* ... */ }      // for少了一个;
(c) for (int ix = 0; ix != sz; ++ix, ++sz) { /*...*/ }      // ix与sz都递增，循环不会停止
```

## [练习 5.17](exercise_5.17.cpp)

## [练习 5.21](exercise_5.21.cpp)

## 练习 5.22
> 本节的最后一个例子跳回到 begin，其实使用循环能更好的完成该任务，重写这段代码，注意不再使用goto语句。
```
// 向后跳过一个带初始化的变量定义是合法的
begin:
    int sz = get_size();
    if (sz <= 0) {
        goto begin;
    }
```

```  cpp
while(true){
    int sz = get_size();
    if(sz<=0){
        continue;
    else {
        break;

    }
}
```

## [练习 5.25](exercise_5.25.cpp)