#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <unistd.h>

/*	利用mmap函数追加写文件
	想法一：改变mmap的传递参数
	：文件映射的长度和偏移地址之和必须小于等于文件大小。
	：通过增加空洞文件，让文件大小扩大2倍，并且映射源文件大小内容。
	：偏移量为偏移原文件大小。
	：失败，违法的参数（报错）
	想法2：
	正常映射文件，在文件虚拟内存映射完毕之后得到addr（映射首地址）
	addr指针增加到len/2处，在此处读写正好可以写到文件末尾。
	可是我正常映射的是文件大小，那么追加的文件内容写到了不该是映射区域的虚拟内存吗？
	：
*/
int main(int argc, char const *argv[])
{
	int fd = open("passwd",O_RDWR|O_APPEND);
	int len = lseek(fd,0,SEEK_END);
/*	ftruncate(fd,len*2);
	void *addr = mmap(NULL,len,PROT_WRITE|PROT_READ,MAP_SHARED,fd,len);
	if(addr == (void *)-1)
	{
		perror("mmap ");
		return 0;
	}*/
	void *addr = mmap(NULL,len,PROT_WRITE|PROT_READ,MAP_SHARED,fd,0);
	if(addr == (void *)-1)
	{
		perror("mmap ");
		return 0;
	}	
	void * NewAddr = addr + len/2;
	close(fd);
	char *ch = (char *)NewAddr;
	gets(ch);
	printf("%s\n",ch);
	munmap(addr,len);
	return 0;
}
