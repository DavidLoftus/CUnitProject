#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>

#include <stdlib.h>
// Undefine max because msvc creates a non-standard macro
#undef max

#include "avg_and_max.h"

void avg_test(void)
{
    double arr[] = {1.0, 0.0, -1.0};
    CU_ASSERT_DOUBLE_EQUAL(average(arr, 3), 0.0, 0.0001);
    CU_ASSERT_DOUBLE_EQUAL(average(arr, 2), 0.5, 0.0001);
    CU_ASSERT_DOUBLE_EQUAL(average(arr, 1), 1.0, 0.0001);
}

void avg_test_empty_array(void)
{
    CU_ASSERT_DOUBLE_EQUAL(average(NULL, 0), 0.0, 0.0001);
}

void avg_test_large_array(void)
{
    double* arr = malloc(1000 * sizeof(double));
    CU_ASSERT_PTR_NOT_NULL_FATAL(arr);
    for(int i = 0; i < 1000; ++i)
    {
        arr[i] = i+1;
    }
    CU_ASSERT_DOUBLE_EQUAL(average(arr, 1000), 1001/2.0, 0.0001);
    free(arr);
}

void max_test(void)
{
    double array[] = {4.0, -5.24, 9.252};
    CU_ASSERT_EQUAL(max(array, 3), 9.252);
}

void max_test_empty_array(void)
{
    CU_ASSERT_EQUAL(max(NULL, 0), -INFINITY);
}

void max_test_large_array(void)
{
    double* arr = malloc(1000 * sizeof(double));
    CU_ASSERT_PTR_NOT_NULL_FATAL(arr);
    for(int i = 0; i < 1000; ++i)
    {
        arr[i] = i - i*i * 0.01;
    }
    CU_ASSERT_DOUBLE_EQUAL(max(arr, 1000), 25.0, 0.0001);
    free(arr);
}

int main(void)
{
    CU_initialize_registry();

    CU_pSuite avg_suite = CU_add_suite("avg_suite", NULL, NULL);
    CU_pSuite max_suite = CU_add_suite("max_suite", NULL, NULL);

    CU_ADD_TEST(avg_suite, avg_test);
    CU_ADD_TEST(avg_suite, avg_test_empty_array);
    CU_ADD_TEST(avg_suite, avg_test_large_array);

    CU_ADD_TEST(max_suite, max_test);
    CU_ADD_TEST(max_suite, max_test_empty_array);
    CU_ADD_TEST(max_suite, max_test_large_array);

    CU_basic_set_mode(CU_BRM_VERBOSE);

    CU_basic_run_tests();

    
    CU_cleanup_registry();
}
