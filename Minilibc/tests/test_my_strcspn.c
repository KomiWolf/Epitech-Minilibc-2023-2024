/*
** EPITECH PROJECT, 2024
** MiniLibC
** File description:
** test_my_strcspn
*/

#include "tests.h"

size_t (*test_my_strcspn)(const char *, const char *);

bool init_my_strcspn(void)
{
    void *call_shared_lib = dlopen("./libasm.so", RTLD_LAZY);

    if (call_shared_lib == NULL) {
        return false;
    }
    test_my_strcspn = dlsym(call_shared_lib, "strcspn");
    return true;
}

Test(strcspn, zero)
{
    const char *str = "Bonjour";
    const char *reject = "dmB";
    size_t expected_result = strcspn(str, reject);
    size_t my_result = 0;

    if (init_my_strcspn() == false) {
        return;
    }
    my_result = test_my_strcspn(str, reject);
    cr_assert(my_result == expected_result);
}

Test(strcspn, all_string)
{
    const char *str = "Bonjour";
    const char *reject = "khb";
    size_t expected_result = strcspn(str, reject);
    size_t my_result = 0;

    if (init_my_strcspn() == false) {
        return;
    }
    my_result = test_my_strcspn(str, reject);
    cr_assert(my_result == expected_result);
}

Test(strcspn, four)
{
    const char *str = "How are you ?";
    const char *reject = "lxza";
    size_t expected_result = strcspn(str, reject);
    size_t my_result = 0;

    if (init_my_strcspn() == false) {
        return;
    }
    my_result = test_my_strcspn(str, reject);
    cr_assert(my_result == expected_result);
}

Test(strcspn, empty_reject)
{
    const char *str = "How are you ?";
    const char *reject = "";
    size_t expected_result = strcspn(str, reject);
    size_t my_result = 0;

    if (init_my_strcspn() == false) {
        return;
    }
    my_result = test_my_strcspn(str, reject);
    cr_assert(my_result == expected_result);
}