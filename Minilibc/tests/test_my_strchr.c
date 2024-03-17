/*
** EPITECH PROJECT, 2024
** assembly
** File description:
** test_my_strchr
*/

#include "tests.h"

char *(*test_my_strchr)(const char *, int);

bool init_my_strchr(void)
{
    void *call_shared_lib = dlopen("./libasm.so", RTLD_LAZY);

    if (call_shared_lib == NULL) {
        return false;
    }
    test_my_strchr = dlsym(call_shared_lib, "strchr");
    return true;
}

Test(strchr, empty_string)
{
    const char *str = "";
    char c = 'W';
    char *expected_result = strchr(str, c);
    char *my_result = "";

    if (init_my_strchr() == false) {
        return;
    }
    my_result = test_my_strchr(str, c);
    cr_assert(my_result == expected_result);
}

Test(strchr, not_found)
{
    const char *str = "Hello, World";
    char c = 'a';
    char *expected_result = strchr(str, c);
    char *my_result = "";

    if (init_my_strchr() == false) {
        return;
    }
    my_result = test_my_strchr(str, c);
    cr_assert(my_result == expected_result);
}

Test(strchr, simple)
{
    const char str[] = "Hello, World";
    char c = 'W';
    char *expected_result = strchr(str, c);
    char *my_result = "";

    if (init_my_strchr() == false) {
        return;
    }
    my_result = test_my_strchr(str, c);
    cr_assert(my_result == expected_result);
}

Test(strchr, no_char)
{
    const char str[] = "Hello, World";
    char c = '\0';
    char *expected_result = strchr(str, c);
    char *my_result = "";

    if (init_my_strchr() == false) {
        return;
    }
    my_result = test_my_strchr(str, c);
    cr_assert(my_result == expected_result);
}

Test(strchr, all_empty)
{
    const char *str = "";
    char c = '\0';
    char *expected_result = strchr(str, c);
    char *my_result = "";

    if (init_my_strchr() == false) {
        return;
    }
    my_result = test_my_strchr(str, c);
    cr_assert(my_result == expected_result);
}
