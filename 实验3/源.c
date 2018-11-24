#include <stdio.h>
#define MAX 8
typedef struct
{
	int base[MAX];//������洢����Ԫ��
	int front;//�����ͷָ��
	int rear;//�����βָ��
}SqQueue;//�����ӵĽṹ��

void InitQueue(SqQueue *Q)//����һ���ն��к���
{
	Q->rear = 0;//��βָ��Ϊ��
	Q->front = Q->rear;//��ͷָ���β
}

int QueueLength(SqQueue Q)//����һ���������ڷ���QԪ�ظ����������г���
{
	return (Q.rear - Q.front + MAX) % MAX;//������巽��
}

void EnQueue(SqQueue *Q, int e)//������в���Ԫ�غ�����������Ԫ��eΪQ���µĶ�βԪ��
{
	if ((Q->rear + 1) % MAX == Q->front)//�ж϶����Ƿ�����
	{
		printf("��������\n");
	}
	else
	{
		Q->base[Q->rear] = e;//baseΪ���飬��ֵԪ��e����β
		Q->rear = (Q->rear + 1) % MAX;//���ζ�����ӻ�����������βָ���1
	}
}

void traverse(SqQueue Q)//����ѭ������Ԫ��
{
	int I, k;
	if (Q.front <= Q.rear)
	{
		for (I = Q.front; I<Q.rear; I++)
		{
			printf("%d ", Q.base[I]);
		}
	}
}

int DeQueue(SqQueue *Q, int *e)//ɾ������Ԫ��
{
	if (Q->rear == Q->front)
	{
		return -1;
	}//��ӿգ�����-1
	*e = Q->base[Q->front];//����βָ��ָ��Ԫ�ظ�ֵ��e
	Q->front = (Q->front + 1) % MAX;//���ζ��г��ӻ�����������ͷָ���1
	return 1;
}

void main()
{
	SqQueue Q;
	int j, m, x;
	InitQueue(&Q);//���ù����ն��к���
	printf("��Ӳ���");
	for (j = 0; j<7; j++)
	{
		EnQueue(&Q, 2 * j);//����ż��Ԫ��
	}
	traverse(Q);//����Q��Ԫ��
	m = QueueLength(Q);//��¼�ӳ�
	printf("\n�Գ���Ϊ��%d\n", m);
	printf("���Ӳ���\n");
	for (j = 0; j<m; j++)
	{
		DeQueue(&Q, &x);//Ԫ�س���
		printf("%d\n", x);
	}
	system("pause");
}