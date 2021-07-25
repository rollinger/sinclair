#include "test.h"

/* A test case that does nothing and succeeds. */
void null_test_success(void **state)
{
	(void) state; /* unused */
	return ;
}

/* ibuff_create Test Case
SIG:	t_ibuff	*ibuff_create(void)
TESTS if returns a t_ibuff type and if bsize is set to BUFFER_BLOCK_LEN
*/
void test_ibuff_create(void **state)
{
	t_ibuff	*new = ibuff_create();
	assert_non_null(new);
	assert_non_null(new->buff);
	assert_non_null(new->bptr);
	assert_int_equal(new->bmax, BUFFER_BLOCK_LEN);
	(void) state; /* unused */
	return ;
}

/* ibuff_push Test Case
SIG:	void ibuff_push(t_ibuff *b, int i)
TESTS if the int is written and the ptr is moved forward and the statistics are ok.
*/
void test_ibuff_push(void **state)
{
	size_t	n = 6, i = 0;
	int		arr[6] = {88,2,8,99,4,8};
	t_ibuff	*new = ibuff_create();
	while (i < n)
	{
		ibuff_push(new, arr[i]);
		assert_int_equal(*(new->bptr - 1), arr[i]);
		assert_int_equal(new->bptr - new->buff, i + 1);
		assert_int_equal(new->bptr - new->buff, new->n);
		++i;
	}
	assert_int_equal(new->bptr - new->buff, n);
	(void) state; /* unused */
	return ;
}

/* ibuff_pop Test Case
SIG:	void ibuff_pop(t_ibuff *b, int i)
TESTS if the int is written and the ptr is moved bacwards
*/
void test_ibuff_pop(void **state)
{
	(void) state; /* unused */
	return ;
}

/* ibuff_pop Test Case
SIG:	size_t	ibuff_len(t_ibuff *b)
TESTS if the length is returned correctly
*/
void test_ibuff_len(void **state)
{
	(void) state; /* unused */
	return ;
}
