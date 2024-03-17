/*
** EPITECH PROJECT, 2024
** MiniLibC
** File description:
** test_my_strncmp
*/

#include "tests.h"

int (*test_my_strncmp)(const char *, const char *, size_t);

bool init_my_strncmp(void)
{
    void *call_shared_lib = dlopen("./libasm.so", RTLD_LAZY);

    if (call_shared_lib == NULL) {
        return false;
    }
    test_my_strncmp = dlsym(call_shared_lib, "strncmp");
    return true;
}

Test(strncmp, negative)
{
    const char *str = "Bonjour";
    const char *str2 = "Bonnour";
    size_t go_to = 5;
    int expected_result = strncmp(str, str2, go_to);
    int my_result = 0;

    if (init_my_strncmp() == false) {
        return;
    }
    my_result = test_my_strncmp(str, str2, go_to);
    cr_assert(my_result == expected_result);
}

Test(strncmp, positive)
{
    const char *str = "Bonnour";
    const char *str2 = "Bonjour";
    size_t go_to = 5;
    int expected_result = strncmp(str, str2, go_to);
    int my_result = 0;

    if (init_my_strncmp() == false) {
        return;
    }
    my_result = test_my_strncmp(str, str2, go_to);
    cr_assert(my_result == expected_result);
}

Test(strncmp, equal)
{
    const char *str = "Bonjour";
    const char *str2 = "Bonjour";
    size_t go_to = 3;
    int expected_result = strncmp(str, str2, go_to);
    int my_result = 0;

    if (init_my_strncmp() == false) {
        return;
    }
    my_result = test_my_strncmp(str, str2, go_to);
    cr_assert(my_result == expected_result);
}

Test(strncmp, equal_2)
{
    const char *str = "Bonjour";
    const char *str2 = "Bonjoure";
    size_t go_to = 6;
    int expected_result = strncmp(str, str2, go_to);
    int my_result = 0;

    if (init_my_strncmp() == false) {
        return;
    }
    my_result = test_my_strncmp(str, str2, go_to);
    cr_assert(my_result == expected_result);
}

Test(strncmp, almost_equal)
{
    const char *str = "Bonjour";
    const char *str2 = "Bonjoure";
    size_t go_to = 10;
    int expected_result = strncmp(str, str2, go_to);
    int my_result = 0;

    if (init_my_strncmp() == false) {
        return;
    }
    my_result = test_my_strncmp(str, str2, go_to);
    cr_assert(my_result == expected_result);
}

Test(strncmp, no_incrementator)
{
    const char *str = "Bonjour";
    const char *str2 = "bonjour";
    size_t go_to = 0;
    int expected_result = strncmp(str, str2, go_to);
    int my_result = 0;

    if (init_my_strncmp() == false) {
        return;
    }
    my_result = test_my_strncmp(str, str2, go_to);
    cr_assert(my_result == expected_result);
}

Test(strncmp, no_first_string)
{
    const char *str = "";
    const char *str2 = "bonjour";
    size_t go_to = 4;
    int expected_result = strncmp(str, str2, go_to);
    int my_result = 0;

    if (init_my_strncmp() == false) {
        return;
    }
    my_result = test_my_strncmp(str, str2, go_to);
    cr_assert(my_result == expected_result);
}

Test(strncmp, no_second_string)
{
    const char *str = "bonjour";
    const char *str2 = "";
    size_t go_to = 4;
    int expected_result = strncmp(str, str2, go_to);
    int my_result = 0;

    if (init_my_strncmp() == false) {
        return;
    }
    my_result = test_my_strncmp(str, str2, go_to);
    cr_assert(my_result == expected_result);
}

Test(strncmp, no_string)
{
    const char *str = "";
    const char *str2 = "";
    size_t go_to = 4;
    int expected_result = strncmp(str, str2, go_to);
    int my_result = 0;

    if (init_my_strncmp() == false) {
        return;
    }
    my_result = test_my_strncmp(str, str2, go_to);
    cr_assert(my_result == expected_result);
}

Test(strncmp, all_zero)
{
    const char *str = "";
    const char *str2 = "";
    size_t go_to = 0;
    int expected_result = strncmp(str, str2, go_to);
    int my_result = 0;

    if (init_my_strncmp() == false) {
        return;
    }
    my_result = test_my_strncmp(str, str2, go_to);
    cr_assert(my_result == expected_result);
}

Test(strncmp, same_string)
{
    const char *str = "Hello Mate !!";
    const char *str2 = "Hello Mate !!";
    size_t go_to = 8;
    int expected_result = strncmp(str, str2, go_to);
    int my_result = 0;

    if (init_my_strncmp() == false) {
        return;
    }
    my_result = test_my_strncmp(str, str2, go_to);
    cr_assert(my_result == expected_result);
}

Test(strncmp, big_incrementator)
{
    const char *str = "Hello Mate !!";
    const char *str2 = "Hello Mate !!";
    size_t go_to = 90;
    int expected_result = strncmp(str, str2, go_to);
    int my_result = 0;

    if (init_my_strncmp() == false) {
        return;
    }
    my_result = test_my_strncmp(str, str2, go_to);
    cr_assert(my_result == expected_result);
}
