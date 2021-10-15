#include <dirent.h>
#include <stdio.h>

int main(void)
{
	DIR *dir_info;
	struct dirent *dir_entry;

	dir_info = opendir(".");
	if (dir_info != NULL)
	{
		dir_entry = readdir(dir_info);
		while (dir_entry != NULL)
		{
			printf("%s\n", dir_entry->d_name);
			dir_entry = readdir(dir_info);
		}
		closedir(dir_info);
	}
	return (0);
}