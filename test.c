#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>

#include "avg_and_max.h"

void avg_test1(void)
{
    double arr[] = {1.0, 0.0, -1.0};
    CU_ASSERT_DOUBLE_EQUAL(average(arr, 3), 0.0, 0.01);
    CU_ASSERT_DOUBLE_EQUAL(average(arr, 2), 0.5, 0.01);
    CU_ASSERT_DOUBLE_EQUAL(average(arr, 1), 0.5, 0.01);
}

void avg_test_empty_array(void)
{
    double arr[] = {0.0};
    CU_ASSERT_DOUBLE_EQUAL(average(arr, 0), 0.0, 0.01);
}

int main(void)
{
    CU_initialize_registry();

    CU_pSuite avg_suite = CU_add_suite("avg_suite", NULL, NULL);
    CU_pSuite max_suite = CU_add_suite("max_suite", NULL, NULL);

    CU_ADD_TEST(avg_suite, avg_test1);
    CU_ADD_TEST(avg_suite, avg_test_empty_array);

    CU_basic_set_mode(CU_BRM_VERBOSE); 

    CU_basic_run_tests();

    
    CU_cleanup_registry();
}
