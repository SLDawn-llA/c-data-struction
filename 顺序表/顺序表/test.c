//test.c ���������Ե�(main����������) ��������SeqList.c�еĺ����Բ���
//  SeqList.cʹ������װ������ ��ʵ��˳���ķ����� 
// ����Ӧ��.h�������䵱Ŀ¼ ���������� ˳���ṹ ����˳���ķ�����Ŀ¼
#include"SeqList.h"////test.c--->SeqList.h(�ɺ�������ָ��������)--��SeqList.c(���ú���)
void test01()
{
	sl a;
	slinit(&a);//�����a ����ֵ���� ��ֵ����  ����a û�г�ʼ�� ����ɶ�� ���Ծͻᱨ��//������ַ����
	pushback(&a, 1);///Ϊɶ���д������ǰ����checkcapacity�� ��Ϊpushback�������Ѿ���ǰ������
	pushback(&a, 2);
	pushback(&a, 3);
	pushback(&a, 4);
	print(&a);
	//popback(&a);
	insert(&a, 2, 0);
	print(&a);
	erase(&a, 5);//print ��i<size ������size
	print(&a);
	printf("%d\n",find(&a, 2));
	print(&a);
	popfront(&a);
	print(&a);

	destroy(&a);///��ʵ����Ҳ������checkcapacityһ����дֻ���ڴ�ӡ֮���Զ�free
	//���������Ļ�  ֻ�ܴ�ӡһ�� ���ͷ���free�ˣ� �Ѿ��Թ���û���⣩

}
int main()
{
	test01();//��һ�β���
	return 0;
}