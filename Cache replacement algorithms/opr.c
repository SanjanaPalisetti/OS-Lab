#include<stdio.h>
#include<stdlib.h>


int pages[100] = {0};
int freq[100] = {0};
int memory[100] = {0};
int mem_size;
int n;
int hit_count = 0;
int miss_count = 0;
int count=0;
int page_exists = 0;
int index = 0;



int find_frequency(int start)
{
	int i,min=0,j;
	for(i=0;i<mem_size;i++)
	{
		for(j=start;j<n;j++)
		{
			if(pages[j] == memory[i])
			freq[i]++;
		}
	}
	for(i=0;i<mem_size;i++)
	{
		if(freq[i]<freq[min])
			min = i;
	}
	return min;
}


int func()
{
	int i,j;
	for(i=0;i<n;i++)
	{
		page_exists = 0;

		// checking if page exists
		for(j=0;j<mem_size;j++)
		{
			if(pages[i]==memory[j])
			{
				page_exists = 1;
				index = j;
			}
		}

		// page fault 
		if(!page_exists)
		{
			miss_count++;

			// memory isnt full yet
			if(count<mem_size)
			{
				memory[count] = pages[i];
				count++;
			}

			// memory is full
			else
			{
				index = find_frequency(i);
				memory[index] = pages[i];
			}
		}

		// page exists
		else
		{
			hit_count++;
		}

		// showing memory
		printf("\n");
		for(j=0;j<mem_size;j++)
		{
			printf("%d ",memory[j]);
		}
	}

	// printing values
	printf("\nHits = %d\nMisses = %d",hit_count,miss_count);
}


int main()
{
	// inputting values
	printf("\nEnter number of pages : ");
	scanf("%d",&n);

	int i;
	for(i=0;i<n;i++)
	{
		printf("\nEnter page value : ");
		scanf("%d",&pages[i]);
	}

	printf("\nEnter memory size : ");
	scanf("%d",&mem_size);

	// calling func and printing results
	func();
}