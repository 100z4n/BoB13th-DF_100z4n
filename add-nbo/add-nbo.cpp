#include <iostream>
#include <cstdint>
#include <cstdio>
#include <arpa/inet.h>

uint32_t read_file(FILE *fp) {
	uint32_t num;
	fread(&num, sizeof(uint32_t), 1, fp);
	return ntohl(num);
}

int main(int argc, char *argv[]){
	if(argc!=3) {
		fprintf(stderr, "%s <file1> <file2>\n", argv[0]);
		return 1;
	}

	//file1 read
	FILE *file1=fopen(argv[1], "rb");
	if(file1==nullptr){
		perror("file1 read error");
		return 1;
	}

	//file2 read
	FILE *file2=fopen(argv[2], "rb");
	if(file2==nullptr){
		perror("file2 read error");
		return 1;
	}

	uint32_t num1=read_file(file1);
	uint32_t num2=read_file(file2);

	fclose(file1);
	fclose(file2);

	uint32_t sum=num1+num2;

	printf("%u(0x%x) + %u(0x%x) = %u(0x%x) \n", num1, num1, num2, num2, sum, sum);

	return 0;
}
