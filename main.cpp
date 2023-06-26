#include <fcntl.h>
#include <iostream>
#include <sys/ioctl.h>
//#include <esdm/esdm_es_irq.h>

#define ESDMIO	0xE0
#define ESDM_IRQ_AVAIL_ENTROPY		_IOR(ESDMIO, 0x00, uint32_t )

int main(int argc, char** argv){
    std::cout << "test\n";
    int esdm_fd = -1;
    char msg[4096];
    esdm_fd = open("/dev/esdm_es", O_RDONLY);
   	if (esdm_fd < 0) {
        std::cout << printf("could not open esdm_es: %i\n", esdm_fd);
		return 0;
	}else{
        std::cout << "opening esdm_es successfull\n";
    }
    int ret;
    uint32_t status[2];
    ret = ioctl(esdm_fd, ESDM_IRQ_AVAIL_ENTROPY,status);

}