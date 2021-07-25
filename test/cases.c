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
	assert_int_equal(new->bmax, BUFFER_BLOCK_LEN);
	(void) state; /* unused */
	return ;
}

/* ibuff_push Test Case
SIG:	void ibuff_push(t_ibuff *b, int i)
TESTS if the int is written and the ptr is moved forward
*/
void test_ibuff_push(void **state)
{
	size_t	n = 6, i = 0;
	int		arr[6] = {1,2,3,4,5,6};
	t_ibuff	*new = ibuff_create();
	while (i < n)
	{
		ibuff_push(new, arr[i]);
		assert_int_equal(*(new->bptr), arr[i]);
		assert_int_equal(new->bptr - new->buff, i);
		++i;
	}
	assert_int_equal(new->bptr - new->buff, n - 1);
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
