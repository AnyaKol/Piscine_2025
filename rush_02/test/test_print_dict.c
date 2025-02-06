#include <stdio.h>

struct s_entry
{
    char *key;
    char *value;
};

int nb_len(char *nb);
void write_hundred(char *nb, struct s_entry *dict, int digits);

void print_dict_nb(char *nb, struct s_entry *dict, int size)
{
    int len;
    int entry_len;
    int i;

    len = nb_len(nb);
    i = size;
    while (i > 0)
    {
        entry_len = nb_len(dict[i].key);
        if (len >= entry_len)
        {
            write_hundred(nb, dict, len - entry_len + 1);
        }
        i--;
    }
}

int nb_len(char *nb)
{
    int i;

    while (nb[i] != 0)
    {
        i++;
    }
    return (i);
}

void write_hundred(char *nb, struct s_entry *dict, int digits)
{
    int i;

    i = 1;
    if (digits == 3)
    {
        while (i <= 10)
        {
            if (nb[0] == dict[i].key)
            {
                printf("%s", dict[i].value);
                printf("%s", dict[29].value);
            }
            i++;
        }
    }

}

int main(void)
{
    int dict_size;

    struct s_entry dict[] =
    {
        {"0", "zero"},
        {"1", "one"},
        {"2", "two"},
        {"3", "three"},
        {"4", "four"},
        {"5", "five"},
        {"6", "six"},
        {"7", "seven"},
        {"8", "eight"},
        {"9", "nine"},
        {"10", "ten"},
        {"11", "eleven"},
        {"12", "twelve"},
        {"13", "thirteen"},
        {"14", "fourteen"},
        {"15", "fifteen"},
        {"16", "sixteen"},
        {"17", "seventeen"},
        {"18", "eighteen"},
        {"19", "nineteen"},
        {"20", "twenty"},
        {"30", "thirty"},
        {"40", "forty"},
        {"50", "fifty"},
        {"60", "sixty"},
        {"70", "seventy"},
        {"80", "eighty"},
        {"90", "ninety"},
        {"100", "hundred"},
        {"1000", "thousand"},
        {"1000000", "million"},
    };
    char nb[] = "123456";
    print_dict_nb(nb, dict, 31);
    return (0);
}