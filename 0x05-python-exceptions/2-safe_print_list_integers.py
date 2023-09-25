#!/usr/bin/python3
def safe_print_list_integers(my_list=[], x=0):
    list_length = 0
    for i in range(x):
        try:
            print("{:d}".format(my_list[i]), end="")
            list_length += 1
        except (ValueError, TypeError):
            pass
    print()
    return list_length
