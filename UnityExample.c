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

void test_input_parsing()
{
	int argc = 2;
	char **argv = NULL;
	TEST_ASSERT_EQUAL(false, input_parsing(argc, argv));

	int argc1 = 1;
	TEST_ASSERT_EQUAL(false, input_parsing(argc1, argv));

	int argc2 = 3;
	char *argv1[3];
	argv1[0] = "test";
	argv1[1] = "mandelbrot";
	argv1[2] = "1";
	TEST_ASSERT_EQUAL(true, input_parsing(argc2, argv1));

	char *argv2[3];
	argv2[0] = "test";
	argv2[1] = "julia";
	argv2[2] = "1";
	TEST_ASSERT_EQUAL(true, input_parsing(argc2, argv2));

	char *argv3[3];
	argv3[0] = "test";
	argv3[1] = "juliajan";
	argv3[2] = "5";
	TEST_ASSERT_EQUAL(false, input_parsing(argc2, argv3));

	char *argv4[3];
	argv4[0] = "test";
	argv4[1] = "julia";
	argv4[2] = "2147483648";
	TEST_ASSERT_EQUAL(false, input_parsing(argc2, argv4));

	char *argv5[3];
	argv5[0] = "test";
	argv5[1] = "julia";
	argv5[2] = "-2147483648234534524524254534525452";
	TEST_ASSERT_EQUAL(false, input_parsing(argc2, argv5));
}

int main(void) {
	UNITY_BEGIN();
	RUN_TEST(test_ft_atoi_with_overflow);
	RUN_TEST(test_zoom);
	RUN_TEST(test_input_parsing);
	return UNITY_END();
}