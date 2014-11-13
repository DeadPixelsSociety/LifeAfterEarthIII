#include <cstdlib>

#include <server/Listener.h>

int main(int argc, char *argv[])
{
	lae3::server::Listener listener;

	listener.start();

	for (;;)
    {
        //
    }

	return EXIT_SUCCESS;
}
