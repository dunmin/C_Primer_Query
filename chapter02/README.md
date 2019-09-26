# Chapter 2

## 练习 2.29
```
(b) p1 = p3``` 合法  
(e) p2 = p1``` 合法
```


## 练习 2.30
```
const int v2 = 0; 
int v1 = v2;
int *p1 = v1, &r1 = v1;
const int *p2 = &v2, *const p3 = &i, &r2 = v2;
```
v2顶层const,  p2底层const, p3是顶层const+底层const, r2是底层const

## 练习 2.31
```
(a) r1 = v2;    合法：但是是改变值不是改变引用
(b) p1 = p2;    不合法, 底层const不能赋值给非const                 
(c) p2 = p1;    合法，p1是int*可以转成const int*
(d) p1 = p3;    不合法, 底层const不能赋值给非const
(e) p2 = p3;    合法，都有底层const
```

## 练习 2.32
```
int null = 0,*p = null;
```
错误，不能把整形直接赋值给指针，即便刚好等于0也不行
```
int null = 0,*p = 0;
```
