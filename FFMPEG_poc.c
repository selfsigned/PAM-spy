#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>


#define CAPTURE_FRAMES "1"

typedef struct FFArgs {
	char	*device;
	char	*dest_path;
} FFArgs;

int		take_snap(FFArgs args)
{
	return(execlp("ffmpeg",
			"-f=video4linux2",
			"-i", args.device,
			"-vframes", CAPTURE_FRAMES,
			"-y",
			args.dest_path,
			NULL));
	return (1);
}

int		snap(char *dest)
{
	FFArgs args;

	args.device = strdup("/dev/video0");
	args.dest_path = strdup(dest);
	if(take_snap(args) == -1)
		dprintf(2, "Error: %s.\n", strerror(errno));
	free(args.device); free(args.dest_path);
}

int		main() {
	snap("snap0.jpeg");
}
