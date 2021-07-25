#include "test.h"

/*
* Entry point for the test program.
*/
int main(void)
{
	const struct CMUnitTest tests[] = {
		//cmocka_unit_test(null_test_success),
		cmocka_unit_test(test_ibuff_create),
		//cmocka_unit_test(test_ibuff_push),
		//cmocka_unit_test(test_ibuff_pop),
	};

	printf("::: UNIT TESTS for ___sinclair___ :::\n");
	return cmocka_run_group_tests(tests, NULL, NULL);
}
