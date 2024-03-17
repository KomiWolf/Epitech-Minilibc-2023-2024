/*
** EPITECH PROJECT, 2024
** MiniLibC
** File description:
** test_my_strstr
*/

#include "tests.h"

char *(*test_my_strstr)(const char *, const char *);

bool init_my_strstr(void)
{
    void *call_shared_lib = dlopen("./libasm.so", RTLD_LAZY);

    if (call_shared_lib == NULL) {
        return false;
    }
    test_my_strstr = dlsym(call_shared_lib, "strstr");
    return true;
}

Test(strstr, empty_haystack)
{
    const char *haystack = "";
    const char *needle = "World";
    char *expected_result = strstr(haystack, needle);
    char *my_result = "";

    if (init_my_strstr() == false) {
        return;
    }
    my_result = test_my_strstr(haystack, needle);
    cr_assert(my_result == expected_result);
}

Test(strstr, empty_needle)
{
    const char *haystack = "Hello, World!";
    const char *needle = "";
    char *expected_result = strstr(haystack, needle);
    char *my_result = "";

    if (init_my_strstr() == false) {
        return;
    }
    my_result = test_my_strstr(haystack, needle);
    cr_assert(my_result == expected_result);
}

Test(strstr, not_found)
{
    const char *haystack = "Hello, World!";
    const char *needle = "Wall";
    char *expected_result = strstr(haystack, needle);
    char *my_result = "";

    if (init_my_strstr() == false) {
        return;
    }
    my_result = test_my_strstr(haystack, needle);
    cr_assert(my_result == expected_result);
}

Test(strstr, found)
{
    const char *haystack = "Hello, World!";
    const char *needle = "World";
    char *expected_result = strstr(haystack, needle);
    char *my_result = "";

    if (init_my_strstr() == false) {
        return;
    }
    my_result = test_my_strstr(haystack, needle);
    cr_assert(my_result == expected_result);
}

Test(strstr, all_empty)
{
    const char *haystack = "";
    const char *needle = "";
    char *expected_result = strstr(haystack, needle);
    char *my_result = "";

    if (init_my_strstr() == false) {
        return;
    }
    my_result = test_my_strstr(haystack, needle);
    cr_assert(my_result == expected_result);
}
