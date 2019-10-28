#include<stdio.h>
#include<string.h>
#define LEN 100005

typedef struct pp{
	char name[100];
	int t;
}P;

P Q[LEN];
int head,tail,n;

void enqueue(P x){
	Q[tail] = x;
	tail = (tail + 1) % LEN;
} 

P dequeue(){
	P x = Q[head];
	head = (head + 1) % LEN;
	return x;
}

int min(int a,int b)
{
	return a < b ? a : b;  //返回最小值
}

int main()
{
	int elaps = 0,c;
	int i,q;
	P u;
	scanf("%d %d",&n,&q);
	
	for(i = 1;i <= n;i++){  //按顺序将所有任务添加至队列
		scanf("%s",Q[i].name);
		scanf("%d",&Q[i].t);
	}
	head = 1;
	tail = n + 1;
	
	while(head != tail){  //模拟
		u = dequeue();
		c = min(q,u.t);  //ִ执行时间片q或所需时间u.t的处理
		u.t -= c;  //计算剩余的所需时间
		elaps += c;  //累计已经过的时间
		if(u.t > 0)  //如果处理尚未结束则重新添加至队列
			enqueue(u);
		else
			printf("%s %d\n",u.name,elaps);
	}
	
	return 0;
}
