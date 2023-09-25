#!/usr/bin/python3
def safe_print_list(my_list=[], x=0):
    list_length = 0
    for i in range(x):
        try:
            print("{}".format(my_list[i]), end='')
            list_length += 1
        except IndexError:
            pass
    print()
    return list_length
