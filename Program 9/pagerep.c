#include<stdio.h>
int n, m, pages[50], table[20], lru[20], k=0, in=0, pageHit[100]={0};
void updateLRU(int page, int s)
{
	if(s != -1)
	{
		for(int j=0; j<k-1; j++)
			lru[j] = lru[j+1];
		lru[k-1] = page;	
		return;
	}
	int i, j;
	for(i=0; i<k; i++)
		if(lru[i] == page)
			break;
	for(j=i; j<k-1; j++)
		lru[j] = lru[j+1];
	lru[k-1] = page;
}
int tableEmpty()
{
	for(int i=0; i<m; i++)
		if(table[i] == -1)
			return 1;
	return 0;
}
void display()
{
	for(int i=0; i<m; i++)
		printf("%d ", table[i]);
	printf("\n");
}
void solve(int ch)
{
	for(int i=0; i<n; i++)
	{
		if(pageHit[pages[i]])
			updateLRU(pages[i], -1);
		else if(ch == 1 || tableEmpty())
		{
			pageHit[table[in]] = 0;
			table[in] = pages[i];
			in = (in+1)%m;
			lru[k++] = pages[i];
			pageHit[pages[i]] = 1;
		}
		else
		{
			for(int j=0; j<m; j++)
				if(table[j] == lru[0])
				{
					pageHit[table[j]] = 0;
					table[j] = pages[i];
					pageHit[table[j]] = 1;
				}
			updateLRU(pages[i], 1);
		}
		display();
	}
}
int main()
{
	printf("Enter the no. of processes: ");
	scanf("%d", &n);
	printf("Enter the size of page table: ");
	scanf("%d", &m);
	for(int i=0; i<m; i++)
		table[i] = -1;
	printf("Enter page numbers: ");
	for(int i=0; i<n; i++)
		scanf("%d", &pages[i]);
	printf("1. FIFO\n2. LRU\n");
	int ch;
	scanf("%d", &ch);
	solve(ch);
}