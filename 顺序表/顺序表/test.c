//test.c 是用来测试的(main函数在其中) 用来测试SeqList.c中的函数对不对
//  SeqList.c使用来封装函数的 （实现顺序表的方法） 
// 而对应的.h是用来充当目录 声明函数的 顺序表结构 声明顺序表的方法即目录
#include"SeqList.h"////test.c--->SeqList.h(由函数申明指向函数调用)--》SeqList.c(调用函数)
void test01()
{
	sl a;
	slinit(&a);//如果是a 就是值传递 即值拷贝  但是a 没有初始化 拷贝啥呢 所以就会报错//所以用址传递
	pushback(&a, 1);///为啥这行代码插入前不用checkcapacity呢 因为pushback函数中已经提前调用了
	pushback(&a, 2);
	pushback(&a, 3);
	pushback(&a, 4);
	print(&a);
	//popback(&a);
	insert(&a, 2, 0);
	print(&a);
	erase(&a, 5);//print 中i<size 不包含size
	print(&a);
	printf("%d\n",find(&a, 2));
	print(&a);
	popfront(&a);
	print(&a);

	destroy(&a);///其实这行也可以像checkcapacity一样不写只需在打印之后自动free
	//但是这样的话  只能打印一次 就释放了free了（ 已经试过了没问题）

}
int main()
{
	test01();//第一次测试
	return 0;
}