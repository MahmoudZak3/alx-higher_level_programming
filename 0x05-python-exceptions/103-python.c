#include <Python.h>
#include <stdio.h>

/**
 * print_python_list - Prints information about a Python list object
 * @p: PyObject pointer to the Python list object
 */
void print_python_list(PyObject *p)
{
    Py_ssize_t size, i;
    PyObject *item;

    printf("[*] Python list info\n");
    printf("[*] Size of the Python List = %ld\n", PyList_Size(p));
    printf("[*] Allocated = %ld\n", ((PyListObject *)p)->allocated);

    size = PyList_Size(p);
    for (i = 0; i < size; i++)
    {
        item = PyList_GetItem(p, i);
        printf("Element %ld: %s\n", i, Py_TYPE(item)->tp_name);
    }
}

/**
 * print_python_bytes - Prints information about a Python bytes object
 * @p: PyObject pointer to the Python bytes object
 */
void print_python_bytes(PyObject *p)
{
    Py_ssize_t size, i;
    char *string;

    printf("[.] bytes object info\n");
    if (!PyBytes_Check(p))
    {
        printf("  [ERROR] Invalid Bytes Object\n");
        return;
    }

    size = PyBytes_Size(p);
    string = PyBytes_AsString(p);

    printf("  size: %ld\n", size);
    printf("  trying string: %s\n", string);

    if (size > 10)
        size = 10;

    printf("  first %ld bytes: ", size);
    for (i = 0; i < size; i++)
    {
        printf("%02hhx", string[i]);
        if (i == size - 1)
            printf("\n");
        else
            printf(" ");
    }
}

/**
 * print_python_float - Prints information about a Python float object
 * @p: PyObject pointer to the Python float object
 */
void print_python_float(PyObject *p)
{
    char *buffer;

    printf("[.] float object info\n");
    if (!PyFloat_Check(p))
    {
        printf("  [ERROR] Invalid Float Object\n");
        return;
    }

    buffer = PyOS_double_to_string(PyFloat_AsDouble(p), 'r', 0, Py_DTSF_ADD_DOT_0, NULL);
    if (buffer == NULL)
        return;

    printf("  value: %s\n", buffer);

    PyMem_Free(buffer);
}
