#include <fcntl.h>
#include <unistd.h>

int main(int argc, const char *argv[])
{
	int	fd;
	const char *ter = "/dev/ttys001";
	fd = open(ter, O_RDWR | O_NOCTTY | O_NDELAY);
	if (fd == -1)
		return (2);
	write(fd, "testing\n", 8);
	close(fd);
	return 0;
}
