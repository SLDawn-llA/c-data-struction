#include"SeqList.h"/////��ʼ��----β�壨�ڴ����Ƿ��㹻�ڴ����롪�������ڴ��free����Ȼ�����β�壩
//��ʼ����������
void slinit(sl* a)
{
	a->arr = NULL;
	a->size = 0;
	a->capacity=0;
}
//β�� ---�����Ƿ�ռ��㹻 ������Ҫ����ռ� ����֮��ʹ�������Ҫ����
void slcheckcapacity(sl* a)
{
	if (a->capacity == a->size)//���������ʵ�����ݸ�����ȵĻ������ڴ治��
	{
		//������ռ�   ���ĸ���������ռ���
		// һ��ռ����� ��������������  (��Ƶ������ ��ʹ��������Ч�ʴ�󽵵���������������)
		//����һ������ ��ʼ��sl��˳������͵�a�ĸ�������������Ϊ0ɶ�� ����������զ���
		// ��������Ŀ�����  �ж��Ƿ�Ϊ0  Ϊ��͸�ֵΪ������   ��Ϊ��ͷ���
		int newcapacity = a->capacity == 0 ? 4 : 2 * a->capacity;
		//��ʾ������������ ����ʵ���ڴ�ռ���Ҫ�ö�̬�ڴ溯������
		// ԭ�����д�С�� �����Ǹı��С ��realloc ���п�������ʧ�ܾͻḳֵΪNULL 
		//������֮ǰ������  �������ص�����  Ҫ����  ���Ծ�Ҫ�Ƚ�����Ŀռ���´����ı��� 
		//�����ΪNULL �Ÿ�ֵ��arr
		sldatatype* tmp = (sldatatype*)realloc(a->arr, newcapacity * sizeof(sldatatype));
		if (tmp == NULL)
		{
			perror("realloc failed");
			exit(1);
		}
		//�ռ�����ɹ�
		a->arr = tmp;
		a->capacity = newcapacity;//����ֻ���ж��ڴ��Ƿ�  �����ͼ� ���Ͳ���
		//����12�е�if û�з�֧else         �����ж��ڴ�   ���ڻ�û��ʵ�����ݵ�����ɾ�� ����a->size����
	}

}
//���ڴ����������ڴ������  ��free
void destroy(sl* a)
{//a->arr ��Ϊ�վ�free  Ϊ��free�ᱨ��   ��Ϊ��NULL��������
	if (a->arr)
	{
		free(a->arr);
		a->arr = NULL;
		a->capacity = a->size = 0;
	}
}

//������β��
void pushback(sl* a, sldatatype x)
{
	//a = NULL;///����õ�
	//if (a == NULL)//Ϊɶ   �˷�������� ֻ�᷵�ش���Ϊ0 ���ᱨ��
	//return;//���֮��  assert ��Ȼ�������Ǹ���ֱ��չ�ֳ���������
	assert(a);//Assertion failed: a, file E:\Visual studio 2022\code\˳���\˳���\SeqList.c, line 53
	//��Ϊ�� ��Ҫ����ڴ��Ƿ��㹻 �����ܲ��ǰ�
	slcheckcapacity(a);
	a->arr[a->size] = x;//Ϊɶ�����±�Ϊsize  ����Ϊsize�Ǵ�0��ʼ�� ����ʾʵ�����ݸ�����size�ӵ�һ�����ݿ�ʼ����1��
	//����ΪsizeΪ1 ʱ ʵ���������������±�Ϊ0��   �±�Ϊsize ��1�ǾͿ�����
	a->size++;////Ҳ����ֱ��a->arr[a->size++] = x;
}
//ͷ��    ��������β�岻ͬ  ͷ����������Ҫ��������ƶ�һλ
void pushfront(sl* a, sldatatype x)
{
	assert(a);
	slcheckcapacity(a);
	//Ҫ�������ƶ�λ�ò���ͷ��
	int i;////Ϊɶ����ѭ���Ǵ��±�Ϊsize  ��ʼ�� ����Ϊsize�Ǵ�0��ʼ�� ����ʾʵ�����ݸ�����size�ӵ�һ�����ݿ�ʼ����1��
	//����ΪsizeΪ1 ʱ ʵ���������������±�Ϊ0��   �±�Ϊsize ��1�ǾͿ�����
	for (i = a->size; i>=1; i--)//�����ȷ��������ֹ�Ļ� ����i = a->size; i; i--����  
		//ͨ��ѭ�������	���ж�����
	{
		a->arr[i] = a->arr[i - 1];///ѭ�������վ���a->arr[1]=a->arr[0]  ����i-1>=0
	}
	a->arr[0] = x;
	a->size++;
}

//��ӡ  ������Ը�ֱ��
void print(sl* a)
{
	int i;
	for (i = 0; i < a->size; i++)
	{
		printf("%d", a->arr[i]);
		
	}printf("\n");
	
}
/// βɾ
void popback(sl* a)
{
	assert(a);
	assert(a->size);//˳���Ϊ�ղ���ִ��ɾ������  û������size--���ǲ��ʹ�-1��ʼ��
	//���п���//a->arr[a->size-1] = 0;///a->arr[a->size] = 0;���д��������Ϊsize��ʱΪ4 �����������ֵΪ0
	//���ڴ�ռ�����ֻΪ4Խ����� ������ֹ
	a->size--;
}
	//������˵һ��βɾ�ǽ�Ҫɾ��������  ��ֵΪĬ��ֵ0��Ȼ������size--
	//�������ֻ��size-- ͨ����ӡ��ӡ��size��֮ǰ�����ݸ�����ΪĬ��ֵ������ν
	//���Ҷ� �������� ɾ������ �޸����� �������ݶ�û��Ӱ��  ��Ϊʵ����Щ����������size���ڵķ�Χ 
	//size--��ԭʼ���ݲ�����size��Χ�� ���԰�������һ��д����ΪĬ��ֵ �ǿ��п��޵�
//ͷɾ    ����������βɾ�ֲ�ͬ  ͷɾ��֮������ݶ�Ҫ��ǰ�ƶ�һλ
void popfront(sl* a)
{
	assert(a);
	assert(a->size);//û�����ݲ���ɾ
	int i;
	for (i =0; i <a->size-1; i++)
	{
		a->arr[i ] = a->arr[i+1];//a->arr[size-2] = a->arr[size-1];
		
	}
	a->size--;
}
///��ָ��λ��֮ǰ��������
void insert(sl* a, int pos, sldatatype x)//����x
{
	assert(a);
	assert(pos >= 0&&pos<=a->size);
	 slcheckcapacity(a);
	int i;////��pos��������������ƶ�һλ �Ҵ����һλ��ʼ��Ϊ��pos��ʼ�Ḳ�ǵ�
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
	assert(pos >= 0 && pos <=a->size);//���ܵ��� ��Ϊ�±�Ϊsizeλ�� ���ڷ�Χ��
	slcheckcapacity(a);
	int i;//��ɾ������λ��ʼ ��������ݶ�Ҫ��ǰ�ƶ�һλ
	for (i = pos; i <=a->size-1; i++)
	{
		a->arr[i] = a->arr[i + 1];//arr[size-1]=arr[size]
	}//����Ǵ�pos��ʼ�ƶ���ֹ�����ǵ�
	a->size--;
}
int find(sl* a, sldatatype x)///������Ѱ��x��������±�ֵ
{
	assert(a);
	int i;
	for (i = 0; i < a->size; i++)
	{
		if (a->arr[i] == x)
			return i;
		
	} return -1;//ѭ�����˶�û���ҵ� �ͷ���-1 ��Ȼ�±겻����Ϊ������
}