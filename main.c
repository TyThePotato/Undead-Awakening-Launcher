#include <signal.h>
#include "window.h"
#include "net.h"

static void init();
static void update();
static void close();

Window *window;
Net *net;
volatile int is_running = 1;

int main(int argc, char **argv)
{
	init();
	while (is_running)
	{
		update();
	}
	close();
	return 0;
}

void int_handler(int id)
{
	is_running = 0;
}

void init()
{
	window = window_create();
	net = net_init();
	signal(SIGINT, int_handler);
}

void update()
{
	window_update(window);
}

void close()
{
	net_close(net);
	window_close(window);
}
