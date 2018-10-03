#define _POSIX_C_SOURCE 200809L
#include <string.h>
#include <stdio.h>
#include <time.h>

#include "pam_spy.h"

char	*generate_filename()
{
	char	buf[420];
	struct	tm *tmp;
	time_t	t;

	t = time(NULL);
	if (!(tmp = localtime(&t))) {
		perror("Localtime error");
		return (NULL);
	}
	if (!strftime(buf, 420, PIC_FMT, tmp)) {
		perror("Strftime error");
		return (NULL);
	}
	return (strndup(buf, 420));
}
