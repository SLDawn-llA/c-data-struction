#pragma once
//Sequence list 
///��ͷ�ļ��� �����������ͻ�ṹ
//ͬʱ ��������
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
//����˳���Ľṹ
//��̬˳�������������С �޷��ж� ��ɿռ��˷ѻ��߿ռ䲻����
//#define N 100
//struct SeqList
//{
//	int arr[N];
//	int size;//ʵ����Ч���ݸ���
//};
//��̬˳��� int *arr; ָ��һ����̬�ڴ濪�ٵĵ�ַ ��ȷ����С����ȥ��̬����
typedef int sldatatype;
typedef struct SeqList //����
{
	sldatatype* arr;//��̬�ڴ濪�ٵ�ַ
	int size;//��Ч���ݸ���
	int capacity;//�ռ��С
}sl;
////////////struct sqelist//���������������typedef ֱ�Ӷ���   
////////////{///Ҳ����struct ���������typedef����
////////////	int a;
////////////	int y;
////////////};
////////////typedef struct sqelist sl;// ����һ����sqelist �Ľṹ������
////////////sl a;����������sl=====struct sqelist    ��struct sqelist ���൱��int����������
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