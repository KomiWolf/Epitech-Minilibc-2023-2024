/*
** EPITECH PROJECT, 2024
** MiniLibC
** File description:
** test_my_strpbrk
*/

#include "tests.h"

char *(*test_my_strpbrk)(const char *, const char *);

bool init_my_strpbrk(void)
{
    void *call_shared_lib = dlopen("./libasm.so", RTLD_LAZY);

    if (call_shared_lib == NULL) {
        return false;
    }
    test_my_strpbrk = dlsym(call_shared_lib, "strpbrk");
    return true;
}

Test(strpbrk, empty_string)
{
    const char *str = "";
    const char *accept = "dkl";
    char *expected_result = strpbrk(str, accept);
    char *my_result = "";

    if (init_my_strpbrk() == false) {
        return;
    }
    my_result = test_my_strpbrk(str, accept);
    cr_assert(my_result == expected_result);
}

Test(strpbrk, no_accept)
{
    const char *str = "Hello, World!";
    const char *accept = "";
    char *expected_result = strpbrk(str, accept);
    char *my_result = "";

    if (init_my_strpbrk() == false) {
        return;
    }
    my_result = test_my_strpbrk(str, accept);
    cr_assert(my_result == expected_result);
}

Test(strpbrk, found)
{
    const char *str = "Hello, World!";
    const char *accept = "JsWAsm";
    char *expected_result = strpbrk(str, accept);
    char *my_result = "";

    if (init_my_strpbrk() == false) {
        return;
    }
    my_result = test_my_strpbrk(str, accept);
    cr_assert(my_result == expected_result);
}
