// gcc -o shm_server shm_server.c

#include <fcntl.h>     // O_RDWR
#include <stdio.h>     // printf(), perror()
#include <stdlib.h>    // exit()
#include <string.h>    // 문자열 처리 (지금은 strcpy는 안 쓰지만 포함됨)
#include <sys/mman.h>  // shm_open(), mmap(), munmap()
#include <unistd.h>    // close()


int main()
{
    int shm_fd = shm_open("/myshm", O_CREAT | O_RDWR, 0666);    // /myshm 이름의 공유 메모리 객체를 읽고 쓰기 권한(O_RDWR) 으로 연다.
    if (shm_fd == -1)
    {
        perror("shm_open");
        exit(1);
    }
    ftruncate(shm_fd, 4096);
    char *shm = mmap(0, 4096, PROT_WRITE | PROT_READ, MAP_SHARED, shm_fd, 0);
    if (shm == MAP_FAILED)
    {
        perror("mmap");
        exit(1);
    }

    strcpy(shm, "Hello shared memory FROM process 1!");
    char temp[10];
    scanf("%s", temp);
    munmap(shm, 4096);
    shm_unlink("/myshm");
    return 0;
}