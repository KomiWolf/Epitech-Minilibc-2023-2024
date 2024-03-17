/*
** EPITECH PROJECT, 2024
** MiniLibC
** File description:
** test_my_strlen
*/

#include "tests.h"

size_t (*test_my_strlen)(const char *);

bool init_my_strlen(void)
{
    void *call_shared_lib = dlopen("./libasm.so", RTLD_LAZY);

    if (call_shared_lib == NULL) {
        return false;
    }
    test_my_strlen = dlsym(call_shared_lib, "strlen");
    return true;
}

Test(strlen, simple_string)
{
    const char *str = "Hello, World";
    size_t expected_result = strlen(str);
    size_t my_result = 0;

    if (init_my_strlen() == false) {
        return;
    }
    my_result = test_my_strlen(str);
    cr_assert(my_result == expected_result);
}

Test(strlen, special_string)
{
    const char *str = "a\nb\tc,\nd\r";
    size_t expected_result = strlen(str);
    size_t my_result = 0;

    if (init_my_strlen() == false) {
        return;
    }
    my_result = test_my_strlen(str);
    cr_assert(my_result == expected_result);
}

Test(strlen, empty_string)
{
    const char *str = "";
    size_t expected_result = strlen(str);
    size_t my_result = 0;

    if (init_my_strlen() == false) {
        return;
    }
    my_result = test_my_strlen(str);
    cr_assert(my_result == expected_result);
}
