/*
** EPITECH PROJECT, 2024
** MiniLibC
** File description:
** test_my_memmove
*/

#include "tests.h"

void *(*test_my_memmove)(void *, const void *, size_t);

bool init_my_memmove(void)
{
    void *call_shared_lib = dlopen("./libasm.so", RTLD_LAZY);

    if (call_shared_lib == NULL) {
        return false;
    }
    test_my_memmove = dlsym(call_shared_lib, "memmove");
    return true;
}

Test(memmove, copy_int_array)
{
    int dest[8];
    const int src[8] = {3, 7, 2, 67, 11, 0, 43, 22};
    size_t n = 8;
    void *expected_result = memmove(dest, src, n);
    void *my_result = NULL;
    if (init_my_memmove() == false) {
        return;
    }
    my_result = test_my_memmove(dest, src, n);
    cr_assert(my_result == expected_result);
}

Test(memmove, copy_string)
{
    char dest[8];
    const char src[8] = "Bonjour";
    size_t n = 8;
    void *expected_result = memmove(dest, src, n);
    void *my_result = NULL;
    if (init_my_memmove() == false) {
        return;
    }
    my_result = test_my_memmove(dest, src, n);
    cr_assert(my_result == expected_result);
}

Test(memmove, copy_string_2)
{
    char *dest = strdup("Hello guys, I'm here !!");
    const char *src = "Bonjour";
    size_t n = 6;
    void *expected_result = memmove(dest, src, n);
    void *my_result = NULL;
    if (init_my_memmove() == false) {
        return;
    }
    my_result = test_my_memmove(dest, src, n);
    cr_assert(my_result == expected_result);
    free(dest);
}


Test(memmove, copy_null)
{
    char dest[8];
    const char src[8];
    size_t n = 8;
    void *expected_result = memmove(dest, src, n);
    void *my_result = NULL;
    if (init_my_memmove() == false) {
        return;
    }
    my_result = test_my_memmove(dest, src, n);
    cr_assert(my_result == expected_result);
}

Test(memmove, copy_null_in_existing_string)
{
    char dest[8] = "Hello";
    const char src[8];
    size_t n = 8;
    void *expected_result = memmove(dest, src, n);
    void *my_result = NULL;
    if (init_my_memmove() == false) {
        return;
    }
    my_result = test_my_memmove(dest, src, n);
    cr_assert(my_result == expected_result);
}

Test(memmove, copy_null_in_existing_string_2)
{
    char dest[8] = "Hello";
    const char src[8];
    size_t n = 5;
    void *expected_result = memmove(dest, src, n);
    void *my_result = NULL;
    if (init_my_memmove() == false) {
        return;
    }
    my_result = test_my_memmove(dest, src, n);
    cr_assert(my_result == expected_result);
}

Test(memmove, copy_null_in_existing_string_3)
{
    char dest[8] = "Hello";
    const char src[8];
    size_t n = 0;
    void *expected_result = memmove(dest, src, n);
    void *my_result = NULL;
    if (init_my_memmove() == false) {
        return;
    }
    my_result = test_my_memmove(dest, src, n);
    cr_assert(my_result == expected_result);
}

Test(memmove, all_zero)
{
    char dest[8];
    const char src[8];
    size_t n = 0;
    void *expected_result = memmove(dest, src, n);
    void *my_result = NULL;
    if (init_my_memmove() == false) {
        return;
    }
    my_result = test_my_memmove(dest, src, n);
    cr_assert(my_result == expected_result);
}

Test(memmove, move_to_null)
{
    char *dest = NULL;
    const char src[] = "aaaaaa";
    size_t n = 0;
    void *expected_result = memmove(dest, src, n);
    void *my_result = NULL;
    if (init_my_memmove() == false) {
        return;
    }
    my_result = test_my_memmove(dest, src, n);
    cr_assert(my_result == expected_result);
}

Test(memmove, move_to_null_2)
{
    char *dest = "aaaaaa";
    const char *src = NULL;
    size_t n = 0;
    void *expected_result = memmove(dest, src, n);
    void *my_result = NULL;
    if (init_my_memmove() == false) {
        return;
    }
    my_result = test_my_memmove(dest, src, n);
    cr_assert(my_result == expected_result);
}
