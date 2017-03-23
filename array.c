/*	试一试指针化数组，比如动态更改数组的长度、添加一些方法
	1. append() 按顺序添加数组成员,多个数据
	2. removelast() 去掉数组最后一个元素
	3. foreach() 遍历所有的数组成员，并输出
	4. insertAtIndex() 按下标插入数据
	5. removeAtIndex() 按下标删除数据
	6. bubbleSort() 从小到大 冒泡排序
	7. max() 找出最大值
	8. min() 找出最小值
	9. contains() 是否包含 返还bool
	10.结构体要包含count 数组的长度，capacity 占用的空间容量
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

//定义一个结构体，包含长度，数组成员。结构体类型还需定义一个指针。在调用函数的时候以便 引用传值。
typedef struct
{
	int *member;
	int count;
	int capacity;
}Array,*pArray;

//1. Why the argument is pointer? Because we have to pass address to make sure the memories can be sucessfully allocated after evoke the init function.
//2. In lnearList,length means the range of the array.MAX_SIZE means the max memories we allocate to the list.We count the members by length not by MAX_SIZE.While adding a member length plus by 1.
//If we equal MAX_SIZE to length,we must realloc memories while adding or removing members.This way costs a lot time and add a lot coding and processing.
void init(pArray array)
{
	array->capacity = 2;
	array->member = (int*)malloc(array->capacity*sizeof(int));
	array->count = 0;
}

void append(pArray array,int count,...)
{
	va_list pointer;
	va_start(pointer,count);

	if (array->capacity == 0)
	{
		array->capacity = count;
		array->member = (int*)malloc(array->capacity*sizeof(int));
	}

	if (array->count + count > array->capacity)
	{
		array->member = (int*)realloc(array->member,(array->capacity + count)*sizeof(int));
		array->capacity += count;
	}

	for (int i = array->count; i < array->count + count; ++i)
	{
		*(array->member + i) = va_arg(pointer,int);
	}
	array->count += count;
}

void removelast(pArray array)
{
	array->count -= 1;
}

void removeAtIndex(pArray array,int index)
{
	int *temp,*ptr;
	//index 是从1开始的,所以减1
	index -= 1;
	temp = array->member + (array->count - 1);
	//ptr指向当前index的数据
	ptr = array->member + index;
	for(;ptr < temp; ++ptr)
	{
		*ptr = *(ptr + 1);
	}
	array->count -= 1;
}

void insertAtIndex(pArray array,int index,int number)
{
	int *temp,*ptrToInsert;
	//temp 是用来前后交换数据的
	// ptrToInsert 是用来插入数据的
	if (index > array->count + 1)
	{
		printf("insert out of range.\n");
	}
	if (array->count > array->capacity)
	{
		array->member = (int*)realloc(array->member,(array->capacity + 2)*sizeof(int));
		array->capacity += 2;
	}
	index -= 1;
	temp = array->member + (array->count - 1);
	ptrToInsert = array->member + index;
	for(; temp >= ptrToInsert; --temp)
	{
		*(temp + 1) = *temp;
	}
	*ptrToInsert = number;
	array->count += 1;
}

void foreach(pArray array)
{
	int *first,*last;
	first = array->member;
	last = array->member + (array->count - 1);
	for (;first <= last; ++first)
	{
		printf("%d ", *first);
	}
	putchar('\n');
}

int *max(pArray array)
{
	int *pMax,*first,*last;
	pMax = first = array->member;
	last = array->member + (array->count - 1);
	for(;first<= last; ++first)
	{
		if (*pMax < *first)
		{
			pMax = first;
		}
	}
	return pMax;
}
void min(pArray array)
{
	int *pMin,*first,*last;
	pMin = first = array->member;
	last = array->member + (array->count - 1);
	for(;first<= last; ++first)
	{
		if (*pMin > *first)
		{
			pMin = first;
		}
	}
	printf("%d\n", *pMin);
}

void swap(int *a,int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
void selectionSort(pArray array)
{
	int *pMax,*last,*first,count;
	count = array->count;
	first = array->member;
	last = array->member + (array->count - 1);
	for(;last > first; --last)
	{
		pMax = max(array);
		if (*pMax > *last)
		{
			swap(last,pMax);
		}
		array->count -= 1;
	}
	array->count = count;
}

void bubbleSort(pArray array)
{
	int *first,*last;
	first = array->member;
	for(int j = 0; j < array->count - 1; ++j)
	{
		for(int i = 0; i < array->count - 1 - j; ++i)
		{
			if (*(first + i) > *(first + i + 1))
			{
				swap(first + i,first + i + 1);
			}
		}
	}
}

_Bool contains(pArray array,int number)
{
	int *first,*last;
	first = array->member;
	last = array->member + (array->count - 1);
	for(;first <= last; ++first)
	{
		if (number == *first)
		{
			printf("True\n");
			return 0;
		}
	}
	printf("False\n");
	return 1;
}

int main(int argc ,char  *const argv[])
{
	Array array;
	init(&array);
	append(&array,6,1,2,3,4,6,5);
	foreach(&array);
	printf("count:%d,capacity:%d\n", array.count,array.capacity);
	append(&array,5,1,2,3,4,5);
	foreach(&array);

	insertAtIndex(&array,4,0);
	foreach(&array);
	printf("count:%d,capacity:%d\n", array.count,array.capacity);
	bubbleSort(&array);
	contains(&array,7);
	printf("%d\n", *max(&array));

	return 0;
}
