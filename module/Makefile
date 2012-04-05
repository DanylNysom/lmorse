MODULE_NAME=myleds
obj-m := ${MODULE_NAME}.o
MAJOR_NUMBER=3333

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

install: all
	insmod ${MODULE_NAME}.ko
	mknod /dev/${MODULE_NAME} c ${MAJOR_NUMBER} 0
	chmod a+w /dev/${MODULE_NAME}

clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
