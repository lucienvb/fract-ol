//
// Created by Lucien Van Bussel on 1/18/23.
//

#include "./unity/src/unity.h"
#include "fractol.h"

void setUp(void) {
	// set stuff up here
}

void tearDown(void) {
	// clean stuff up here
}

void test_error_double_check(void)
{
	// !! error_double_check start at the second string in the array (because of the executable) !!

	// test with doubles, output should be 0
	char *arr1[4];
	arr1[0] = "0";
	arr1[1] = "1";
	arr1[2] = "1";
	arr1[3] = NULL;
	TEST_ASSERT_EQUAL(0, error_double_check(arr1));

	// test without doubles, output should be 1
	char *arr2[4];
	arr2[0] = "1";
	arr2[1] = "2";
	arr2[2] = "3";
	arr2[3] = NULL;
	TEST_ASSERT_EQUAL(1, error_double_check(arr2));
}

void test_ft_atoi_with_overflow()
{
	int		num;

	// test with string, output should be 1
	char	*str1 = "hello";
	TEST_ASSERT_EQUAL(1, ft_atoi_with_overflow(str1, &num));

	// test with 0 (int), output should be 1
	char	*str2 = "0";
	TEST_ASSERT_EQUAL(1, ft_atoi_with_overflow(str2, &num));

	// test with integer, output should be 1
	char	*str3 = "-99";
	TEST_ASSERT_EQUAL(1, ft_atoi_with_overflow(str3, &num));

	// test with an empty array, output should be 1
	//TEST_ASSERT_EQUAL(1, ft_atoi_with_overflow(NULL, &num));

	// test with negative overflowing number, output should be 0
	char	*str5 = "-9123452346245666";
	TEST_ASSERT_EQUAL(0, ft_atoi_with_overflow(str5, &num));

	// test with positive overflowing number, output should be 0
	char	*str6 = "9123452346245666";
	TEST_ASSERT_EQUAL(0, ft_atoi_with_overflow(str6, &num));
}

void test_already_sorted()
{
	t_node *stack_1;
	t_node *stack_2;

	stack_1 = (t_node *) malloc(sizeof(t_node));
	stack_2 = (t_node *) malloc(sizeof(t_node));
	stack_2->content = 2;
	stack_2->next = NULL;
	stack_1->content = 1;
	stack_1->next = stack_2;

	t_node *stack_3;
	t_node *stack_4;

	stack_3 = (t_node *) malloc(sizeof(t_node));
	stack_4 = (t_node *) malloc(sizeof(t_node));
	stack_4->content = 1;
	stack_4->next = NULL;
	stack_3->content = 2;
	stack_3->next = stack_4;

	TEST_ASSERT_EQUAL(0, list_reversed_sorted(stack_1));
	TEST_ASSERT_EQUAL(1, list_reversed_sorted(stack_3));

}

// not needed when using generate_test_runner.rb
int main(void) {
	UNITY_BEGIN();
	RUN_TEST(test_error_double_check);
	RUN_TEST(test_ft_atoi_with_overflow);
	RUN_TEST(test_already_sorted);
	return UNITY_END();
}