#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>

#include <stdlib.h>
// Undefine max because msvc creates a non-standard macro
#undef max

#include "avg_and_max.h"

/**
 * Tests for average function.
 */

void avg_test_basic(void)
{
    double arr[] = {1.0, 0.0, -1.0};
    CU_ASSERT_DOUBLE_EQUAL(average(arr, 3), 0.0, 0.0001);
    CU_ASSERT_DOUBLE_EQUAL(average(arr, 2), 0.5, 0.0001);
    CU_ASSERT_DOUBLE_EQUAL(average(arr, 1), 1.0, 0.0001);

    double arr2[] = {0.325, 0.111, 1.252, -2.997, 0.0};
    CU_ASSERT_DOUBLE_EQUAL(average(arr2, 5), -0.2618, 0.0001);
    CU_ASSERT_DOUBLE_EQUAL(average(arr2, 4), -0.3272, 0.0001);
    CU_ASSERT_DOUBLE_EQUAL(average(arr2, 3),  0.5627, 0.0001);
}

void avg_test_empty_array(void)
{
    CU_ASSERT(isnan(average(NULL, 0)));
}

void avg_test_large_array(void)
{
    double* arr = malloc(1000 * sizeof(double));
    CU_ASSERT_PTR_NOT_NULL_FATAL(arr);
    for(int i = 0; i < 1000; ++i)
    {
        arr[i] = i+1;
    }
    CU_ASSERT_DOUBLE_EQUAL(average(arr, 1000), 500.5, 0.0001);
    free(arr);
}

void avg_test_single_value(void)
{
    double array[1];

    array[0] = 3.14159;
    CU_ASSERT_DOUBLE_EQUAL(average(array, 1), 3.14159, 0.0001);


    array[0] = -2.2252;
    CU_ASSERT_DOUBLE_EQUAL(average(array, 1), -2.2252, 0.0001);


    array[0] = 100.202;
    CU_ASSERT_DOUBLE_EQUAL(average(array, 1), 100.202, 0.0001);
}

void avg_test_same_value(void)
{
    double array[16];

    for(int j = 0; j < 16; ++j)
    {
        array[j] = 3.14159;
    }
    CU_ASSERT_DOUBLE_EQUAL(average(array, 16), 3.14159, 0.0001);


    for(int j = 0; j < 16; ++j)
    {
        array[j] = -100.010;
    }
    CU_ASSERT_DOUBLE_EQUAL(average(array, 16), -100.010, 0.0001);


    for(int j = 0; j < 16; ++j)
    {
        array[j] = 0.0;
    }
    CU_ASSERT_DOUBLE_EQUAL(average(array, 16), 0.0, 0.0001);
}

/**
 * Tests for max function.
 */

void max_test_basic(void)
{
    double array[] = {4.0, -5.24, 9.252};
    CU_ASSERT_EQUAL(max(array, 3), 9.252);

    double array2[] = {0.325, 0.111, 1.252, -2.997, 0.0};
    CU_ASSERT_EQUAL(average(array2, 5), 1.252);
    CU_ASSERT_EQUAL(average(array2, 4), 1.252);
    CU_ASSERT_EQUAL(average(array2, 2),  0.325);
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

void max_test_single_value(void)
{
    double array[1];

    array[0] = 3.14159;
    CU_ASSERT_EQUAL(max(array, 1), 3.14159);


    array[0] = -2.2252;
    CU_ASSERT_EQUAL(max(array, 1), -2.2252);


    array[0] = 100.202;
    CU_ASSERT_EQUAL(max(array, 1), 100.202);
}

void max_test_same_value(void)
{
    double array[16];


    for(int j = 0; j < 16; ++j)
    {
        array[j] = 3.14159;
    }
    CU_ASSERT_EQUAL(max(array, 16), 3.14159);


    for(int j = 0; j < 16; ++j)
    {
        array[j] = -100.010;
    }
    CU_ASSERT_EQUAL(max(array, 16), -100.010);


    for(int j = 0; j < 16; ++j)
    {
        array[j] = 0.0;
    }
    CU_ASSERT_EQUAL(max(array, 16), 0.0);
}

int main(void)
{
    CU_initialize_registry();

    CU_pSuite avg_suite = CU_add_suite("avg_suite", NULL, NULL);
    CU_pSuite max_suite = CU_add_suite("max_suite", NULL, NULL);

    CU_ADD_TEST(avg_suite, avg_test_basic);
    CU_ADD_TEST(avg_suite, avg_test_empty_array);
    CU_ADD_TEST(avg_suite, avg_test_large_array);
    CU_ADD_TEST(avg_suite, avg_test_single_value);
    CU_ADD_TEST(avg_suite, avg_test_same_value);

    CU_ADD_TEST(max_suite, max_test_basic);
    CU_ADD_TEST(max_suite, max_test_empty_array);
    CU_ADD_TEST(max_suite, max_test_large_array);
    CU_ADD_TEST(max_suite, max_test_single_value);
    CU_ADD_TEST(max_suite, max_test_same_value);

    CU_basic_set_mode(CU_BRM_VERBOSE);

    CU_basic_run_tests();

    
    CU_cleanup_registry();
}
