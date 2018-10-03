#ifndef PAM_SPY_H
#define PAM_SPY_H

#define PIC_FMT "/var/log/%F-%T.jpg"

typedef struct FFArgs {
	char	device[64];
	char	dest_path[64];
} FFArgs;

int		snap(char *dest);
char	*generate_filename();

#endif
