#include <stdio.h>
#define MAX 8
typedef struct
{
	int base[MAX];//用数组存储队列元素
	int front;//定义队头指针
	int rear;//定义队尾指针
}SqQueue;//构建队的结构体

void InitQueue(SqQueue *Q)//构造一个空队列函数
{
	Q->rear = 0;//队尾指针为空
	Q->front = Q->rear;//对头指向队尾
}

int QueueLength(SqQueue Q)//构造一个函数用于返回Q元素个数，即队列长度
{
	return (Q.rear - Q.front + MAX) % MAX;//计算具体方法
}

void EnQueue(SqQueue *Q, int e)//构造队列插入元素函数，即插入元素e为Q的新的队尾元素
{
	if ((Q->rear + 1) % MAX == Q->front)//判断队列是否已满
	{
		printf("队列已满\n");
	}
	else
	{
		Q->base[Q->rear] = e;//base为数组，赋值元素e给队尾
		Q->rear = (Q->rear + 1) % MAX;//环形队列入队基本操作，队尾指针加1
	}
}

void traverse(SqQueue Q)//遍历循环队列元素
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

int DeQueue(SqQueue *Q, int *e)//删除队列元素
{
	if (Q->rear == Q->front)
	{
		return -1;
	}//如队空，返回-1
	*e = Q->base[Q->front];//将队尾指针指向元素赋值给e
	Q->front = (Q->front + 1) % MAX;//环形队列出队基本操作，队头指针加1
	return 1;
}

void main()
{
	SqQueue Q;
	int j, m, x;
	InitQueue(&Q);//调用构建空队列函数
	printf("入队操作");
	for (j = 0; j<7; j++)
	{
		EnQueue(&Q, 2 * j);//插入偶数元素
	}
	traverse(Q);//遍历Q中元素
	m = QueueLength(Q);//记录队长
	printf("\n对长度为：%d\n", m);
	printf("出队操作\n");
	for (j = 0; j<m; j++)
	{
		DeQueue(&Q, &x);//元素出队
		printf("%d\n", x);
	}
	system("pause");
}