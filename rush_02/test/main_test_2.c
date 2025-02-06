#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>


int	open_dict(int *dict_id);
int	read_dict(int dict_id, char *dict_ptr);

struct s_entry
{
    char *key;
    char *value;
};

int	main(void)
{
	int *dict_id;
	char *dict_ptr;
    int i;

	//check_args
    dict_id = &i;
	if (open_dict(dict_id) == 0)
		return (0);
    dict_ptr = (char *)malloc(4001 * sizeof(char));
	if (read_dict(*dict_id, dict_ptr) == 0)
		return (0);
    i = 0;
    while (dict_ptr[i] != '\0')
    {
        write(1, (dict_ptr + i), 1);
        i++;
    }
	if (close(*dict_id) < 0)
	{
		write(1, "Error", 5);
		exit(1);
	}
	free(dict_ptr);
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

int	read_dict(int dict_id, char *dict_ptr)
{
	int	end;

	if (dict_ptr == NULL)
	{
		write(1, "Error", 5);
		exit(1);
		return (0);
	}
	end = read(dict_id, dict_ptr, 4000);
	dict_ptr[end] = '\0';
	return (1);
}

char* find_entry(char* key, struct s_entry *dict)

void read_three_digits(char* nb, int digits, struct s_entry *dict) {
    int i;
    char digit;
    char* num;
    char* word;

    i = 3 - digits;
    while (i < 3) {
        digit = nb[i];
        if (digit == '0') {
            i++;
            continue;
        }
        if (i == 0) {
            // convert digit to char*
            *num = find_entry(digit, dict);
            *word = find_entry("100", dict);
            // write num + word
        } else if (i == 1) {
            if (digit >= 2) {
                *num = digit + '0'; // create str
                *word = find_entry(num, dict);
                // write word
            } else {
                *num = '1' + nb[i+1]; // create str
                *word = find_entry(num, dict);
                // write word
                break; //do not go to single digit
            }
        } else {
            *num = digit; // create str
                *word = find_entry(num, dict);
                // write word
        }
    }
}