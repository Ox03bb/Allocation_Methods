#include <iostream>
#include <string.h>

#define DISK_SIZE 100
#define NONE -1
int TABLE_HEAD = 0;



struct file {
	char name[2];
	int start;
	int size;
};

file* Table = (file*)malloc(DISK_SIZE*sizeof(file));


int8_t* CreateDisk(){
	int8_t* disk = (int8_t*)malloc(DISK_SIZE*sizeof(int8_t));
	
	int index = 0;
	for (index; index < DISK_SIZE; index++){
		disk[index] = NONE;
	}
	

	return disk;
}

int MaxContiguous(int8_t* disk){
	int size = 0;
	int temp = 0;

	for (int index = 0; index < DISK_SIZE;index++){
		if (disk[index] == NONE){
			temp ++;
		}else{
			if (temp > size){
				size = temp;
			}
			temp = 0;
		}
	}
	if (size == 0 && temp > 0) return temp;

	return size;
}


int TotalFreeSpace(int8_t* disk){
	int size = 0;

	for (int index = 0; index < DISK_SIZE;index++){
		if (disk[index]==NONE){
			size ++;
		}
	}
	return size;
}



void CreateFile(int8_t* disk){
	char name[2];
	int start,size,back_size=0,temp_size=0, temp_index=0 ;

	printf("Enter file name (2 characters): ");
	scanf("%s", name);

	printf("Enter file size: ");
	scanf("%d", &size);

	if (size > DISK_SIZE || size > MaxContiguous(disk)){
		printf("not enough space");
		return;
	}

	for (int index = 0; index < DISK_SIZE;index++){
		if (disk[index] == NONE){
			temp_size ++;		
		}else{
			if (temp_size > back_size){
				temp_index = index;
				back_size = temp_size;
				
			}else{
				break;
			}
			temp_size = 0;
		}
	}
	 
	for (int index = temp_index; index < temp_index+size ; index++){
		disk[index] = 1;
	}

	file file ;
	file.size = size;
	file.start = temp_index;
	strcpy(file.name,name);

	Table[TABLE_HEAD] = file;
	TABLE_HEAD = TABLE_HEAD + 1;

	printf("File created successfully.\n");

}



int main(){
	int8_t* disk;
	int index = 0;
	disk = CreateDisk();
	
	printf("aaaa");
	while (disk[index])
	{
		printf("%d",disk[index]);
		index ++;
	}
	

	CreateFile(disk);

	printf("done");
}