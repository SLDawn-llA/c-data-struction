#include"SeqList.h"/////初始化----尾插（内存检查是否足够内存申请——申请内存的free——然后才是尾插）
//初始化基本数据
void slinit(sl* a)
{
	a->arr = NULL;
	a->size = 0;
	a->capacity=0;
}
//尾插 ---》看是否空间足够 不够就要申请空间 申请之后使用了最后要销毁
void slcheckcapacity(sl* a)
{
	if (a->capacity == a->size)//如果容量与实际数据个数相等的话表明内存不足
	{
		//申请多大空间   用哪个函数申请空间呢
		// 一般空间增容 是两倍或者三倍  (若频繁增容 会使程序运行效率大大降低所以是两到三倍)
		//还有一个问题 初始化sl（顺序表）类型的a的各个基本参数都为0啥的 翻倍后还是零咋解决
		// 答案是用三目运算符  判断是否为0  为零就赋值为非零数   不为零就翻倍
		int newcapacity = a->capacity == 0 ? 4 : 2 * a->capacity;
		//显示的容量增加了 而真实的内存空间需要用动态内存函数申请
		// 原来是有大小的 所以是改变大小 用realloc 而有可能申请失败就会赋值为NULL 
		//会销毁之前的数据  这是严重的问题  要避免  所以就要先将申请的空间给新创建的变量 
		//如果不为NULL 才赋值给arr
		sldatatype* tmp = (sldatatype*)realloc(a->arr, newcapacity * sizeof(sldatatype));
		if (tmp == NULL)
		{
			perror("realloc failed");
			exit(1);
		}
		//空间申请成功
		a->arr = tmp;
		a->capacity = newcapacity;//这里只是判断内存是否够  不够就加 够就不管
		//所以12行的if 没有分支else         而且判断内存   现在还没有实际数据的增加删减 所以a->size不变
	}

}
//有内存的申请就有内存的销毁  即free
void destroy(sl* a)
{//a->arr 不为空就free  为空free会报错   因为对NULL解引用了
	if (a->arr)
	{
		free(a->arr);
		a->arr = NULL;
		a->capacity = a->size = 0;
	}
}

//真正的尾插
void pushback(sl* a, sldatatype x)
{
	//a = NULL;///检测用的
	//if (a == NULL)//为啥   此方法温柔点 只会返回代码为0 不会报错
	//return;//相比之下  assert 虽然暴力但是更能直观展现出问题在哪
	assert(a);//Assertion failed: a, file E:\Visual studio 2022\code\顺序表\顺序表\SeqList.c, line 53
	//不为空 就要检查内存是否足够 够才能插是吧
	slcheckcapacity(a);
	a->arr[a->size] = x;//为啥这里下标为size  是因为size是从0开始的 而表示实际数据个数的size从第一个数据开始就是1了
	//例如为size为1 时 实际数据在哪呢在下标为0那   下标为size 即1那就空着呢
	a->size++;////也可以直接a->arr[a->size++] = x;
}
//头插    。。。与尾插不同  头插后面的数据要逐次往后移动一位
void pushfront(sl* a, sldatatype x)
{
	assert(a);
	slcheckcapacity(a);
	//要先往后移动位置才能头插
	int i;////为啥下面循环是从下标为size  开始呢 是因为size是从0开始的 而表示实际数据个数的size从第一个数据开始就是1了
	//例如为size为1 时 实际数据在哪呢在下标为0那   下标为size 即1那就空着呢
	for (i = a->size; i>=1; i--)//如果不确定到哪终止的话 就先i = a->size; i; i--空着  
		//通过循环到最后	来判断条件
	{
		a->arr[i] = a->arr[i - 1];///循环到最终就是a->arr[1]=a->arr[0]  所以i-1>=0
	}
	a->arr[0] = x;
	a->size++;
}

//打印  检验测试更直观
void print(sl* a)
{
	int i;
	for (i = 0; i < a->size; i++)
	{
		printf("%d", a->arr[i]);
		
	}printf("\n");
	
}
/// 尾删
void popback(sl* a)
{
	assert(a);
	assert(a->size);//顺序表为空不能执行删除功能  没有数据size--了那不就从-1开始了
	//可有可无//a->arr[a->size-1] = 0;///a->arr[a->size] = 0;这行代码错误因为size此时为4 将第五个数赋值为0
	//而内存空间容量只为4越界访问 出现中止
	a->size--;
}
	//正常来说一般尾删是将要删除的数据  赋值为默认值0？然后再让size--
	//但是如果只有size-- 通过打印打印到size那之前的数据赋不赋为默认值都无所谓
	//并且对 增加数据 删减数据 修改数据 查找数据都没有影响  因为实现这些操作都是在size以内的范围 
	//size--后原始数据并不在size范围内 所以按不按照一般写法赋为默认值 是可有可无的
//头删    。。。。与尾删又不同  头删了之后的数据都要往前移动一位
void popfront(sl* a)
{
	assert(a);
	assert(a->size);//没有数据不能删
	int i;
	for (i =0; i <a->size-1; i++)
	{
		a->arr[i ] = a->arr[i+1];//a->arr[size-2] = a->arr[size-1];
		
	}
	a->size--;
}
///在指定位置之前插入数据
void insert(sl* a, int pos, sldatatype x)//插入x
{
	assert(a);
	assert(pos >= 0&&pos<=a->size);
	 slcheckcapacity(a);
	int i;////把pos后面的数都往后移动一位 且从最后一位开始因为从pos开始会覆盖掉
	for (i = a->size; i > pos; i--)
	{
		a->arr[i] = a->arr[i - 1];//a[size]=a[size-1]
	}
	a->arr[pos] = x;
	a->size++;
}
void erase(sl* a, int pos)
{
	assert(a);
	assert(pos >= 0 && pos <=a->size);//不能等于 因为下标为size位置 不在范围内
	slcheckcapacity(a);
	int i;//从删除的那位开始 往后的数据都要往前移动一位
	for (i = pos; i <=a->size-1; i++)
	{
		a->arr[i] = a->arr[i + 1];//arr[size-1]=arr[size]
	}//这次是从pos开始移动防止被覆盖掉
	a->size--;
}
int find(sl* a, sldatatype x)///查找所寻找x这个数的下标值
{
	assert(a);
	int i;
	for (i = 0; i < a->size; i++)
	{
		if (a->arr[i] == x)
			return i;
		
	} return -1;//循环完了都没有找到 就返回-1 当然下标不可能为负数嘛
}