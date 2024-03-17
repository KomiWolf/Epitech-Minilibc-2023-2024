/*
** EPITECH PROJECT, 2024
** MiniLibC
** File description:
** test_my_memset
*/

#include "tests.h"

void *(*test_my_memset)(void *, int, size_t);

bool init_my_memset(void)
{
    void *call_shared_lib = dlopen("./libasm.so", RTLD_LAZY);

    if (call_shared_lib == NULL) {
        return false;
    }
    test_my_memset = dlsym(call_shared_lib, "memset");
    return true;
}

Test(memset, fill_int_array)
{
    int int_array[6];
    int set = 0;
    size_t len = 5;
    void *expected_result = memset(int_array, set, len);
    void *my_result = NULL;

    if (init_my_memset() == false) {
        return;
    }
    my_result = test_my_memset(int_array, set, len);
    cr_assert(my_result == expected_result);
}

Test(memset, fill_string)
{
    char string[20];
    char set = 'a';
    size_t len = 19;
    void *expected_result = memset(string, set, len);
    void *my_result = NULL;

    if (init_my_memset() == false) {
        return;
    }
    my_result = test_my_memset(string, set, len);
    cr_assert(my_result == expected_result);
}
