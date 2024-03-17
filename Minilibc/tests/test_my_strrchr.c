/*
** EPITECH PROJECT, 2024
** MiniLibC
** File description:
** test_my_strrchr
*/

#include "tests.h"

char *(*test_my_strrchr)(const char *, int);

bool init_my_strrchr(void)
{
    void *call_shared_lib = dlopen("./libasm.so", RTLD_LAZY);

    if (call_shared_lib == NULL) {
        return false;
    }
    test_my_strrchr = dlsym(call_shared_lib, "strrchr");
    return true;
}

Test(strrchr, empty_string)
{
    const char *str = "";
    char c = 'W';
    char *expected_result = strrchr(str, c);
    char *my_result = "";

    if (init_my_strrchr() == false) {
        return;
    }
    my_result = test_my_strrchr(str, c);
    cr_assert(my_result == expected_result);
}

Test(strrchr, not_found)
{
    const char *str = "Hello, World";
    char c = 'a';
    char *expected_result = strrchr(str, c);
    char *my_result = "";

    if (init_my_strrchr() == false) {
        return;
    }
    my_result = test_my_strrchr(str, c);
    cr_assert(my_result == expected_result);
}

Test(strrchr, simple)
{
    const char str[] = "Hello, World";
    char c = 'o';
    char *expected_result = strrchr(str, c);
    char *my_result = "";

    if (init_my_strrchr() == false) {
        return;
    }
    my_result = test_my_strrchr(str, c);
    cr_assert(my_result == expected_result);
}

Test(strrchr, empty_char)
{
    const char *str = "Hello";
    char c = '\0';
    char *expected_result = strrchr(str, c);
    char *my_result = "";

    if (init_my_strrchr() == false) {
        return;
    }
    my_result = test_my_strrchr(str, c);
    cr_assert(my_result == expected_result);
}

Test(strrchr, all_empty)
{
    const char *str = "";
    char c = '\0';
    char *expected_result = strrchr(str, c);
    char *my_result = "";

    if (init_my_strrchr() == false) {
        return;
    }
    my_result = test_my_strrchr(str, c);
    cr_assert(my_result == expected_result);
}
