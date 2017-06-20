
#include <stdlib.h>
#if TIME_WITH_SYS_TIME
# include <sys/time.h>
# include <time.h>
#else
# if HAVE_SYS_TIME_H
#  include <sys/time.h>
# else
#  include <time.h>
# endif
#endif
#include <string.h>
#include <math.h>
#include <ibase.h>
#include "example.h"

#define BADVAL -9999L
#define MYBUF_LEN 15		/* number of chars to get for */

typedef struct blob {
	short	(*blob_get_segment) ();
	void	*blob_handle;
	int	blob_number_segments;
	int	blob_max_segment;
	int	blob_total_length;
	void	(*blob_put_segment) ();
} *BLOB;

time_t	time();
char	*ctime();

/* variable to return values in.  Needs to be static so it doesn't go 
   away as soon as the function invocation is finished */

char	buffer[256];
char	buffer2[512];	/* for string concatenation */
char	datebuf[12];	/* for date string */

int	r_long;
double	r_double;
float	r_float;
short	r_short;

struct	tm *tbuf;
int	time_sec;

ISC_QUAD newdate;


/*===============================================================
 fn_lower_c() - Puts its argument longo lower case, for C programs
 Input is of VARCHAR, output is of CSTRING.
 Not international or non-ascii friendly.
================================================================= */
char* EXPORT fn_lower_c(char* s) /* VARCHAR input */
{
	char *buf;
	short length = 0;

	char *buffer = (char *)malloc(256);

	length = (short)*s;
	s += 2;
	buf = buffer;
	while (*s)
		if (*s >= 'A' && *s <= 'Z')
			*buf++ = *s++ - 'A' + 'a';
		else
			*buf++ = *s++;

	*buf = '\0';
	buffer [length] = '\0';

	return buffer;
}
