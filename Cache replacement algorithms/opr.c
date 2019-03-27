#include<stdio.h>
#include<stdlib.h>

int n;
int page[10];
int mem_size;
int mem[10];
int hit = 0, miss = 0;
int page_exists = 0;
int cold_miss = 0;
int req_index = 0;

void init()
{
    int i;
    for(i=0;i<mem_size;i++)
        mem[i] = -1;
}

int find_index(int start)
{
    int matched = 0,i,j;
    int index[10] = {0};

    //checking if values in mem exist in upcoming pages
    for(i=0;i<n;i++)
    {
        for(j=0;j<mem_size;j++)
        {
            if(mem[j] == page[i])
            {
                index[j] = 1;
                matched++;
            }
        }
        if(matched == mem_size-1)
            break;
    }

    //selecting index
    for(i=mem_size-1;i>=0;i--)
        if(index[i] == 0)
            return index[i];
}

void func()
{
    int i,j;
    for(i=0;i<n;i++)
    {
        //checking if the page exists in memory
        page_exists = 0;
        for(j=0;j<mem_size;j++)
        {
            if(page[i] == mem[j])
            {
                hit++;
                page_exists = 1;
            }
        }

        //page fault
        if(!page_exists)
        {
            miss++;

            //cold miss
            if(cold_miss<mem_size)
            {
                mem[cold_miss] = page[i];
                cold_miss++;
            }

            //memory is full
            else
            {
                req_index = find_index(i);
                mem[req_index] = page[i];
            }
            
        }
    printf("\n");
	for(j=0;j<mem_size;j++)
	{
		printf("%d ",mem[j]);
	}
    }
    printf("\nHits = %d\nMisses = %d",hit,miss);
}

int main()
{
    printf("\nEnter number of pages");
    scanf("%d",&n);
    int i;
    for(i=0;i<n;i++)
    {
        printf("\nEnter page value");
        scanf("%d",&page[i]);
    }
    printf("\nEnter memory size");
    scanf("%d",&mem_size);
    init();
    func();
    return 0;
}