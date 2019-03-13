#include<stdio.h>
#include<stdlib.h>

int length = 3;
int pages[100] = {0};
int memory[3] = {-1,-1,-1};
int used[3] = {0};
int n;
int count=0;
int miss_count = 0;
int hit_count = 0;
int page_exists = 0;
int index = 0;



int least_used_index()
{
	int j,max=0;
	for(j=0;j<length;j++)
	{
		if(used[max]<used[j])
			max = j;
	}
	return max;
}


int func()
{
	int i,j;
	for(i=0;i<n;i++)
	{
		page_exists = 0;

		// checking if page exists
		for(j=0;j<length;j++)
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
			if(count<length)
			{
				memory[count] = pages[i];
				count++;

				// increasing time since usage of all other pages
				for(j=0;j<length;j++)
				{
					if(j==count)
						used[j] = 0;
					else
						used[j]++;
				}
			}

			// memory is full
			else
			{
				index = least_used_index();
				memory[index] = pages[i];

				// increasing time since usage of all other pages
				for(j=0;j<length;j++)
				{
					if(j==index)
						used[j] = 0;
					else
						used[j]++;
				}
			}
		}

		else
		{
			hit_count++;
			// increasing time since usage of all other pages
			for(j=0;j<length;j++)
			{
				if(j==index)
					used[j] = 0;
				else
					used[j]++;
			}
		}

		// showing memory
		printf("\n");
		for(j=0;j<length;j++)
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

	// calling func and printing results
	func();
}