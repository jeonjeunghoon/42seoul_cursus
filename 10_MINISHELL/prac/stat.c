#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h> // struct stat
#include <stdio.h>
#include <stdlib.h>
#include <pwd.h> // struct passwd
#include <grp.h> // struct group

int		main(int argc, char **argv)
{
	int		return_stat;
	char	*file_name;
	struct	stat file_info;
	struct	passwd	*my_passwd; // password
	struct	group	*my_group; // group
	mode_t	file_mode; // file mode

	if (argc != 2)
	{
		printf("Usage : ./file_info [file_name]\n");
		exit(0);
	}
	file_name = argv[1]; // file name
	if ((return_stat = stat(file_name, &file_info)) == -1)
	{
		perror("Error: ");
		exit(0);
	}
	file_mode = file_info.st_mode; // file mode;
	printf("파일 이름: %s\n", file_name);
	printf("==============================\n");
	printf("파일 타입: ");
	if (S_ISREG(file_mode))
		printf("정규 파일\n");
	else if (S_ISLNK(file_mode))
		printf("심볼릭 링크\n");
	else if (S_ISDIR(file_mode))
		printf("디렉토리\n");
	else if (S_ISCHR(file_mode))
		printf("문자 디바이스\n");
	else if (S_ISBLK(file_mode))
		printf("블럭 디바이스\n");
	else if (S_ISFIFO(file_mode))
		printf("FIFO\n");
	else if (S_ISSOCK(file_mode))
		printf("소켓\n");
	my_passwd = getpwuid(file_info.st_uid);
	my_group = getgrgid(file_info.st_gid);
	printf("OWNER: %s\n", my_passwd->pw_name);
	printf("GROUP: %s\n", my_group->gr_name);
	printf("FILE SIZE IS: %lld\n", file_info.st_size);
	printf("마지막 읽은 시간: %ld\n", file_info.st_atime);
	printf("마지막 수정 시간: %ld\n", file_info.st_mtime);
	printf("하드 링크된 파일 수: %d\n", file_info.st_nlink);
	return 0;
}