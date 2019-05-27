#include<stdio.h>
int ch, n, m, queue[50], pages[50], lru[100], k=99, l=99, in=0;
int queueIsEmpty()
{
	for(int i=0; i<m; i++)
		if(queue[i] == -1)
			return (i+1);
	return 0;
}
int pageHit(int page)
{
	for(int i=0; i<m; i++)
		if(queue[i] == page)
			return 1;
	return 0;
}
void display()
{
	for(int i=0; i<m; i++)
		printf("%d ", queue[i]);
	printf("\n");
}
void solve(int ch)
{
	int i, j;
	for(i=0; i<n; i++)
	{
		if(pageHit(pages[i]))
		{
			lru[k--] = pages[i];
			l--;
		}
		else if(queueIsEmpty()>0 || ch == 1)
		{
			queue[in] = pages[i];
			in = (in+1)%m;
			lru[k--] = pages[i];
		}
		else
		{
			for(j=0; j<m; j++)
				if(queue[j] == lru[l])
					break;
			queue[j] = lru[k--] = pages[i];
			l--;
		}
		display();
	}

}
int main()
{
	printf("Enter no. of pages: ");
	scanf("%d", &n);
	printf("Enter table size: ");
	scanf("%d", &m);
	for(int i=0; i<m; i++)
		queue[i] = -1;
	printf("Enter pages numbers : ");
	for(int i=0; i<n; i++)
		scanf("%d", &pages[i]);
	printf("1. FIFO\n2. LRU\n");
	scanf("%d", &ch);
	solve(ch);
}