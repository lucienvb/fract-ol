//
// Created by Lucien Van Bussel on 1/18/23.
//

#include "./unity/src/unity.h"
#include "fractol.h"
#include "MLX42/include/MLX42/MLX42.h"

void setUp(void) {
	// set stuff up here
}

void tearDown(void) {
	// clean stuff up here
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

void	test_zoom()
{
	t_fract	test;
	test.zoom = 1.0;

	TEST_ASSERT_EQUAL(test.zoom, 1);
	zoom(&test, 0.005);
	TEST_ASSERT_EQUAL(test.zoom, 1.005);
	TEST_ASSERT_NOT_EQUAL(test.zoom, 0.0);
	zoom(&test, 0.0);
	TEST_ASSERT_EQUAL(test.zoom, 1.005);
}

//void test_input_parsing()
//{
//	int argc = 2;
//	char **argv = NULL;
//
//	TEST_ASSERT_EQUAL(false, input_parsing(argc, argv));
//	argc = 1;
//	TEST_ASSERT_EQUAL(false, input_parsing(argc, argv));
//	argc = 3;
//	argv[0] = "test";
//	argv[1] = "mandelbrot";
//	argv[2] = NULL;
//	TEST_ASSERT_EQUAL(true, input_parsing(argc, argv));
//}

// not needed when using generate_test_runner.rb
int main(void) {
	UNITY_BEGIN();
	RUN_TEST(test_ft_atoi_with_overflow);
	RUN_TEST(test_zoom);
//	RUN_TEST(test_input_parsing);
	return UNITY_END();
}