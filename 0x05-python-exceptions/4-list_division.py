#!/usr/bin/python3
def list_division(my_list_1, my_list_2, list_length):
    i = 0
    div_list = []

    while i < list_length:
        a = 0
        try:
            a = my_list_1[i] / my_list_2[i]
        except ZeroDivisionError:
            print("division by 0")
        except TypeError:
            print("wrong type")
        except IndexError:
            print('out of range')
        finally:
            div_list.append(a)
            i += 1
    return div_list
