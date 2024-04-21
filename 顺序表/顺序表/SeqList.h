#pragma once
//Sequence list 
///在头文件中 定义数据类型或结构
//同时 声明函数
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
//定义顺序表的结构
//静态顺序表——数组给大给小 无法判断 造成空间浪费或者空间不够用
//#define N 100
//struct SeqList
//{
//	int arr[N];
//	int size;//实际有效数据个数
//};
//动态顺序表 int *arr; 指向一个动态内存开辟的地址 ，确定大小后再去动态申请
typedef int sldatatype;
typedef struct SeqList //存疑
{
	sldatatype* arr;//动态内存开辟地址
	int size;//有效数据个数
	int capacity;//空间大小
}sl;
////////////struct sqelist//可以像上面的那样typedef 直接定义   
////////////{///也可以struct 定义完后再typedef定义
////////////	int a;
////////////	int y;
////////////};
////////////typedef struct sqelist sl;// 定义一个叫sqelist 的结构体类型
////////////sl a;、、、、、sl=====struct sqelist    而struct sqelist 就相当于int的数据类型
void print(sl* a);
void slinit(sl* a);
void slcheckcapacity(sl* a);
void destroy(sl* a);
void pushback(sl* a, sldatatype x);
void pushfront(sl* a, sldatatype x);
void popback(sl* a);
void popfront(sl* a);
void insert(sl* a,int pos ,sldatatype x);
void erase(sl* a, int pos);
int find(sl* a, sldatatype x);