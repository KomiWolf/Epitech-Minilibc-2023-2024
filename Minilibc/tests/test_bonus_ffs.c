/*
** EPITECH PROJECT, 2024
** MiniLibC
** File description:
** test_bonus_ffs
*/

#include <strings.h>

#include "tests.h"

int (*test_my_ffs)(int);

bool init_my_ffs(void)
{
    void *call_shared_lib = dlopen("./libasm.so", RTLD_LAZY);

    if (call_shared_lib == NULL) {
        return false;
    }
    test_my_ffs = dlsym(call_shared_lib, "ffs");
    return true;
}

Test(ffs, test_ffs_1)
{
    int expected_result = ffs(0);
    int my_result = 0;

    if (init_my_ffs() == false) {
        return;
    }
    my_result = test_my_ffs(0);
    cr_assert(my_result == expected_result);
}

Test(ffs, test_ffs_2)
{
    int expected_result = ffs(1);
    int my_result = 0;

    if (init_my_ffs() == false) {
        return;
    }
    my_result = test_my_ffs(1);
    cr_assert(my_result == expected_result);
}

Test(ffs, test_ffs_3)
{
    int expected_result = ffs(2);
    int my_result = 0;

    if (init_my_ffs() == false) {
        return;
    }
    my_result = test_my_ffs(2);
    cr_assert(my_result == expected_result);
}

Test(ffs, test_ffs_4)
{
    int expected_result = ffs(5);
    int my_result = 0;

    if (init_my_ffs() == false) {
        return;
    }
    my_result = test_my_ffs(5);
    cr_assert(my_result == expected_result);
}

Test(ffs, test_ffs_5)
{
    int expected_result = ffs(10);
    int my_result = 0;

    if (init_my_ffs() == false) {
        return;
    }
    my_result = test_my_ffs(10);
    cr_assert(my_result == expected_result);
}

Test(ffs, test_ffs_6)
{
    int expected_result = ffs(80);
    int my_result = 0;

    if (init_my_ffs() == false) {
        return;
    }
    my_result = test_my_ffs(80);
    cr_assert(my_result == expected_result);
}

Test(ffs, test_ffs_7)
{
    int expected_result = ffs(-20);
    int my_result = 0;

    if (init_my_ffs() == false) {
        return;
    }
    my_result = test_my_ffs(-20);
    cr_assert(my_result == expected_result);
}

Test(ffs, test_ffs_8)
{
    int expected_result = ffs(-237);
    int my_result = 0;

    if (init_my_ffs() == false) {
        return;
    }
    my_result = test_my_ffs(-237);
    cr_assert(my_result == expected_result);
}

Test(ffs, test_ffs_9)
{
    int expected_result = ffs(956);
    int my_result = 0;

    if (init_my_ffs() == false) {
        return;
    }
    my_result = test_my_ffs(956);
    cr_assert(my_result == expected_result);
}
