#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>


int	open_dict(int *dict_id);

struct s_entry
{
    char *key;
    char *value;
};

int	main(void)
{
	int *dict_id;
    	int i;

    	dict_id = &i;
	if (open_dict(dict_id) == 0)
		return (0);

	if (close(*dict_id) < 0)
	{
		write(1, "Error", 5);
		exit(1);
	}
	return (0);
}

int	open_dict(int *dict_id)
{
	*dict_id = open("numbers.dict", O_RDONLY);
	if (*dict_id < 0)
	{
		write(1, "Error", 5);
		exit(1);
		return (0);
	}
	return (1);
}
