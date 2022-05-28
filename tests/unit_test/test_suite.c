#include <check.h>
#include <stdlib.h>

#include "sign_extend_test.h"
#include "update_flags_test.h"
#include "add_test.h"
#include "memory_test.h"

int main()
{
    int number_failed;
    SRunner *sr;

    sr = srunner_create(make_sign_extend_test_suite());
    srunner_add_suite(sr, make_update_flags_test_suite());
    srunner_add_suite(sr, make_add_test_suite());
    srunner_add_suite(sr, make_memory_test_suite());

    srunner_run_all(sr, CK_NORMAL);

    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);

    return (number_failed==0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
