# Nee

## 一个使用C++11标准代码编写的解释器，代码在任何支持C++11编译器上不加修改即可直接编译。
示例代码
```python
b = 6;
a = 2;
c = "hello world";
while a != 100 do
    loop b do
        print(c,a,"\n");
    end;
    if a == 4 then 
        print("a == 4\n");
    elif a == 6 then
        print("print(\"a == 4\");\n");
    else 
        print("haha\n");
    end;

    print(a,"\n");
    a = a + 1;
end;
```
大数相乘
```python
b = 987654321 * 1234567890123456789;
print(b);
```
输出 1219326311248285321112635269

#### todolist
* 增加更多的语法，语言功能
* 尽可能的修复bug
* 和C++交互更加便利
