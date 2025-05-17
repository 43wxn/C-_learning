# const
	const起到保护变量不被修改的作用，增加程序的健壮性

```
cpp
const int *p//指向const属性的int类型的指针
int const *p//同上
int const *p//int类型的const指针，表示指针的属性是const，即指针的指向地址不可被改变，指针只能一只指向一个目标变量
conts int const *p//指向具有const属性的int对象的const指针 
```
```
cpp
必须使用const void*类型去保存const属性的对象
const int *a=10;
const void *p=&a;
//但是 指向const属性对象的指针是可以指向非const对象的
int *a=10;
const int *p=&a;
但是还是不能通过p指针去修改a的值，即使a是非const属性的对象
```
---
---
```
cpp
const int p=10;//cont属性的对象一定要初始化赋初值，因为const属性的对象不能被修改。
```
---
---
```
cpp
void functionn(const char *ptr){
	ptr是输入的参数 但被const修饰 也就是说ptr是指向const属性的对象，这个对象无法被修改，即函数体内无法修改函数体外的变量的值
}
```
```
cpp
对于非内部数据类型的参数而言,void function(A a)声明的函数效率会很低。因为函数体内部将产生A类型的临时对象用于复制参数a，临时对象的构造，复制，析构过程都会耗费时间。
因此，为了提高效率，可以将函数的声明改为             void function(A &a)的引用的形式，但是引用的形式又会有函数外部变量被修改的可能 故用const修饰即可 void function(const A &a)
```
---
----
```
cpp
使用const进行说明的成员函数 称为常成员函数。只有常成员函数才能操作常量或常对象
对于类中的const成员变量必须通过初始化列表进行初始化
class Apple{
	private:
	int people[100];
	public:
	Apple(int i);
	const int apple_number;
};
Apple::Apple(int i):apple_number(i){}//这是用参数列表进行初始化
我们还可以用其他的方法进行初始化
static conts int apple_number;//将常量的定义与static结合
const int Apple::apple_number=10;//在类的外面进行初始化

```
```
cpp
同时const对象只能访问const的成员函数，而非const对象可以访问任意的成员函数，包括const成员函数
```
---
---
```
cpp
static静态成员变量不能在类的内部进行初始化 只能在类的内部进行声明 定义在类的定义体外部。通常在类的实现文件中类的外部进行初始化
```