//顺序栈的定义
#define STACK_INIT_SIZE 100;
#define STACKINCREMENT 10;
typedef struct
{
	SElemtype * base;
	SElemtype * top;
	int stacksize;
}SqStack;

void conversion(SqStack &S){
	//输入一个任意非负十进制整数，打印输出与其等值的八进制
	InitStack(S);
	scanf("%d",N);
	while(N){
		Push(S,N%8);
		N = N/8;
	}
	while(!StackEmpty(S)){
		Pop(S,e);
		printf("%d", e);
	}
}

void LineEdit(SqStack &S){
	//利用字符栈S，从终端接收一行并传送至调用过程的数据区
	InitStack(S);
	ch = getchar();
	while(ch != EOF){//EOF为全文结束符
		while(ch != EOF && ch != '\n'){
			switch(ch){
				case '#': Pop(S,c); break; //栈非空时退栈
				case '@': ClearStack(S); break; //重置S为空
				default: Push(S,ch); //有效字符进栈，未考虑栈满情形
			}
			ch = getchar();
		}
		ClearStack(S);
		if (ch != EOF) ch = getchar();
	}
	DestroyStack(S);
}

typedef struct
{
	int ord;		//通道块在路径上的“序号”
	PosType seat;	//通道块在迷宫中的“坐标”
	int di;			//从此通道块走向下一块的方向
}SElemtype;

Stuaus MazePath(MazeType maze, PosType start, PosType end){
	//若迷宫中存在从入口start到出口end的通道
	//求一条通道存放在栈中，通道为栈底到栈顶
	InitStack(S);
	currentPos = start;
	currentStep = 1;
	do{
		if (Pass(currentPos)) //当前位置可以通过，未走通道块
		{
			FootPrint(currentPos); //留下足迹
			e = (currentStep,currentPos,1);
			Push(S,e); //加入到路径中
			if(currentPos == end)  return TRUE;
			currentPos = NextPos(currentPos,1); //下一位置是当前位置的东（1）
			currentStep ++;
		}
		else //当前位置不能通过
		{
			if( ! StackEmpty(S)){
				Pop(S,e);
				while(e.di == 4 && !StackEmpty(S)){
					MarkPrint(e.seat); 
					Pop(S,e); //留下不能通过标记，并回退
				}
				if(e.di < 4){
					e.di++; 
					Push(S,e);	//换方向
					currentPos = NextPos(e.seat, e.di); //设定当前位置是新方向上的相邻块
				}
			}
		}
	}while( !StackEmpty(S));
	return FALSE;
}

void hanoi(int n, char x, char y, char z)
//将塔座x上按直径由小到大自上而下编号为1至n的n个圆盘
//按规则搬到z上，y为辅助塔座
//搬动操作move(x,n,z)可定义为（C是初值为0的全局变量，对搬动计数）
//printf("%i move disk %i from %c to %c\n", ++c, n ,x, z);
{
	if(n == 1) move(x, 1, z);
	else{
		hanoi(n-1, x, z, y);
		move(x, n, z);
		hanoi(n-1, y, x, z);
	}
}

//单链队列链式存储结构
typedef struct QNode
{
	QElemType		data;
	struct QNode*  	next;
}QNode,*QueuePtr;

typedef struct 
{	
	QueuePtr	front;
	QueuePtr	rear;
}LinkQueue;

Status InitQueue(LinkQueue &Q){
	Q.front = Q.rear = (QueuePtr)malloc(sizeof(QNode));
	if(!Q.front) exit(OVERFLOW);
	Q.front->next = NULL;
	return OK;
}

Status DestroyQueue(LinkQueue &Q){
	while(Q.front){
		Q.rear = Q.front->next;
		free(Q.front);
		Q.front = Q.rear;
	}
	return OK;
}

Status EnQueue(LinkQueue &Q,QElemType e){
	p = (QueuePtr)malloc(sizeof(QNode));
	if(!p) exit(OVERFLOW);
	p->data = e;
	p->next = NULL;
	Q.rear->next = p;
	Q.rear = p;
	return OK;
}







