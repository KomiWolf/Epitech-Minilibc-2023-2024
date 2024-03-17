/*
** EPITECH PROJECT, 2024
** MiniLibC
** File description:
** test_my_strcmp
*/

#include "tests.h"

int (*test_my_strcmp)(const char *, const char *);

bool init_my_strcmp(void)
{
    void *call_shared_lib = dlopen("./libasm.so", RTLD_LAZY);

    if (call_shared_lib == NULL) {
        return false;
    }
    test_my_strcmp = dlsym(call_shared_lib, "strcmp");
    return true;
}

Test(strcmp, negative)
{
    const char *str = "Bonjour";
    const char *str2 = "Hello";
    int expected_result = strcmp(str, str2);
    int my_result = 0;

    if (init_my_strcmp() == false) {
        return;
    }
    my_result = test_my_strcmp(str, str2);
    cr_assert(my_result == expected_result);
}

Test(strcmp, positive)
{
    const char *str = "Hello";
    const char *str2 = "Bonjour";
    int expected_result = strcmp(str, str2);
    int my_result = 0;

    if (init_my_strcmp() == false) {
        return;
    }
    my_result = test_my_strcmp(str, str2);
    cr_assert(my_result == expected_result);
}

Test(strcmp, equal)
{
    const char *str = "Bonjour";
    const char *str2 = "Bonjour";
    int expected_result = strcmp(str, str2);
    int my_result = 0;

    if (init_my_strcmp() == false) {
        return;
    }
    my_result = test_my_strcmp(str, str2);
    cr_assert(my_result == expected_result);
}

Test(strcmp, almost_equal_1)
{
    const char *str = "Bonjour";
    const char *str2 = "Bonjoure";
    int expected_result = strcmp(str, str2);
    int my_result = 0;

    if (init_my_strcmp() == false) {
        return;
    }
    my_result = test_my_strcmp(str, str2);
    cr_assert(my_result == expected_result);
}

Test(strcmp, almost_equal_2)
{
    const char *str = "Bonjour";
    const char *str2 = "BoNjour";
    int expected_result = strcmp(str, str2);
    int my_result = 0;

    if (init_my_strcmp() == false) {
        return;
    }
    my_result = test_my_strcmp(str, str2);
    cr_assert(my_result == expected_result);
}
