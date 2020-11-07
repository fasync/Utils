#include <X11/Xlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int
main()
{
	Display *dp;
	Window win;
	XEvent event;

	dp = XOpenDisplay(NULL);

	if (!dp) {
		fprintf(stderr, "Could not open display.\n");
		exit(1);
	}

	int screen = DefaultScreen(dp);
	win = RootWindow(dp, screen);

	XSelectInput(dp, win, KeyPressMask | KeyReleaseMask);

	while (event.xkey.keycode != 0x09) {
		XNextEvent(dp, &event);

		switch (event.type) {

		case KeyPress: {
			printf("Key 0x%02x was pressed.\n", event.xkey.keycode);
			break;
		}
		case KeyRelease: {
			printf(
			    "Key 0x%02x was released.\n", event.xkey.keycode);
			break;
		}
		}
	}

	XCloseDisplay(dp);

	return 0;
}
