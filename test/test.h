#include <stdio.h>
#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <stdint.h>
#include <cmocka.h>
#include "../src/sinclair.h"

void null_test_success(void **state);
void test_ibuff_create(void **state);
void test_ibuff_push(void **state);
void test_ibuff_pop(void **state);
