/*
** EPITECH PROJECT, 2024
** MiniLibC
** File description:
** test_my_memcpy
*/

#include "tests.h"

void *(*test_my_memcpy)(void *, const void *, size_t);

bool init_my_memcpy(void)
{
    void *call_shared_lib = dlopen("./libasm.so", RTLD_LAZY);

    if (call_shared_lib == NULL) {
        return false;
    }
    test_my_memcpy = dlsym(call_shared_lib, "memcpy");
    return true;
}

Test(memcpy, copy_int_array)
{
    int dest[8];
    int src[8] = {3, 7, 2, 67, 11, 0, 43, 22};
    size_t n = 8;
    void *expected_result = memcpy(dest, src, n);
    void *my_result = NULL;

    if (init_my_memcpy() == false) {
        return;
    }
    my_result = test_my_memcpy(dest, src, n);
    cr_assert(my_result == expected_result);
}

Test(memcpy, copy_string)
{
    char dest[8];
    char src[8] = "Bonjour";
    size_t n = 8;
    void *expected_result = memcpy(dest, src, n);
    void *my_result = NULL;

    if (init_my_memcpy() == false) {
        return;
    }
    my_result = test_my_memcpy(dest, src, n);
    cr_assert(my_result == expected_result);
}
