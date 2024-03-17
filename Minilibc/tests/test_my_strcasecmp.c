/*
** EPITECH PROJECT, 2024
** MiniLibC
** File description:
** test_my_strcasecmp
*/

#include "tests.h"

int (*test_my_strcasecmp)(const char *, const char *);

bool init_my_strcasecmp(void)
{
    void *call_shared_lib = dlopen("./libasm.so", RTLD_LAZY);

    if (call_shared_lib == NULL) {
        return false;
    }
    test_my_strcasecmp = dlsym(call_shared_lib, "strcasecmp");
    return true;
}

Test(strcasecmp, negative)
{
    const char *str = "Bonjour";
    const char *str2 = "Hello";
    int expected_result = strcasecmp(str, str2);
    int my_result = 0;

    if (init_my_strcasecmp() == false) {
        return;
    }
    my_result = test_my_strcasecmp(str, str2);
    cr_assert(my_result == expected_result);
}

Test(strcasecmp, positive)
{
    const char *str = "Hello";
    const char *str2 = "Bonjour";
    int expected_result = strcasecmp(str, str2);
    int my_result = 0;

    if (init_my_strcasecmp() == false) {
        return;
    }
    my_result = test_my_strcasecmp(str, str2);
    cr_assert(my_result == expected_result);
}

Test(strcasecmp, positive_2)
{
    const char *str = "Hello";
    const char *str2 = "HEKlo";
    int expected_result = strcasecmp(str, str2);
    int my_result = 0;

    if (init_my_strcasecmp() == false) {
        return;
    }
    my_result = test_my_strcasecmp(str, str2);
    cr_assert(my_result == expected_result);
}

Test(strcasecmp, equal)
{
    const char *str = "Bonjour";
    const char *str2 = "bOnJoUr";
    int expected_result = strcasecmp(str, str2);
    int my_result = 0;

    if (init_my_strcasecmp() == false) {
        return;
    }
    my_result = test_my_strcasecmp(str, str2);
    cr_assert(my_result == expected_result);
}

Test(strcasecmp, almost_equal)
{
    const char *str = "Bonjour";
    const char *str2 = "bOnJoUrE";
    int expected_result = strcasecmp(str, str2);
    int my_result = 0;

    if (init_my_strcasecmp() == false) {
        return;
    }
    my_result = test_my_strcasecmp(str, str2);
    cr_assert(my_result == expected_result);
}

Test(strcasecmp, almost_equal_2)
{
    const char *str = "Bonjour";
    const char *str2 = "bOnJoUre";
    int expected_result = strcasecmp(str, str2);
    int my_result = 0;

    if (init_my_strcasecmp() == false) {
        return;
    }
    my_result = test_my_strcasecmp(str, str2);
    cr_assert(my_result == expected_result);
}

Test(strcasecmp, almost_equal_3)
{
    const char *str = "Bonjour ";
    const char *str2 = "bOnJoUr";
    int expected_result = strcasecmp(str, str2);
    int my_result = 0;

    if (init_my_strcasecmp() == false) {
        return;
    }
    my_result = test_my_strcasecmp(str, str2);
    cr_assert(my_result == expected_result);
}

Test(strcasecmp, almost_equal_4)
{
    const char *str = "Bonjour";
    const char *str2 = "bOnJoUrU";
    int expected_result = strcasecmp(str, str2);
    int my_result = 0;

    if (init_my_strcasecmp() == false) {
        return;
    }
    my_result = test_my_strcasecmp(str, str2);
    cr_assert(my_result == expected_result);
}
