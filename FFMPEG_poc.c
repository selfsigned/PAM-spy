#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define CAPTURE_FRAMES "1"

typedef struct FFArgs {
	char	device[64];
	char	dest_path[64];
} FFArgs;

int		take_snap(FFArgs args) {
	return(execlp("ffmpeg",
			"-f=video4linux2",
			"-i", args.device,
			"-vframes", CAPTURE_FRAMES,
			"-y",
			args.dest_path,
			NULL));
}

int		snap(char *dest) {
	FFArgs args;

	strcpy(args.device, "/dev/video0");
	strcpy(args.dest_path, dest);
	if(take_snap(args) == -1)
		dprintf(2, "Error: %s.\n", strerror(errno));
}

int		main() {
	snap("snap0.jpeg");
}
