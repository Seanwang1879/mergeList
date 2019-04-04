#include <stdio.h>
#include <string.h>

#define MAX_SIZE  100
int *merge(int *array00, int *array01);

void main()
{
	int i;
	int nums00[MAX_SIZE];
	int nums01[MAX_SIZE];
	int *nums;

	printf("please enter array00\n");
	for(i=0; i<MAX_SIZE; i++){
		scanf("%d", &nums00[i]);
	}
	printf("please enter array01\n");
	for(i=0; i<MAX_SIZE; i++){
		scanf("%d", &nums01[i]);
	}

	nums = merge(nums00, nums01);

	return ;
}

int *merge(int *array00, int *array01)
{
	int i=0,j=0,k=0;
	int temp;
	static int array[2*MAX_SIZE];    //1.可以申明成全局变量(静态局部变量也可以，函数退出后变量还在)  2.入参    3.堆(用完函数外要释放掉)  
	
	while(i!=MAX_SIZE || j!=MAX_SIZE){
		if(array00[i]<=array01[j]){
			array[k++] = array00[i++];
		}else{
			array[k++] = array01[j++];
		}
	}
	if(i==MAX_SIZE){
		memcpy(&array[k], &array01[j], MAX_SIZE-j);
	}else if(j == MAX_SIZE){
		memcpy(&array[k], &array00[i], MAX_SIZE-i);
	}

	return array;
}
