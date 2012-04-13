MODULE_NAME=myleds
obj-m := ${MODULE_NAME}.o
MAJOR=3232

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean

install: all
	insmod ${MODULE_NAME}.ko
	make device

uninstall: clean
	rmmod ${MODULE_NAME}
	rm /dev/${MODULE_NAME}

device:
	mknod /dev/${MODULE_NAME} c $(shell dmesg | awk '$$3~/myleds/ {modnum=$$7} END{print modnum}') 0
	chmod a+w /dev/${MODULE_NAME}

