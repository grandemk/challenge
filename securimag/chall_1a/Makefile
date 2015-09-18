all: main
main:
	gcc main.c \
	-m32 \
	-o chall \
	-Wl,--section-start=.check_section=0x08048600 \
	-Wl,--section-start=.text=0x08048800 \
	#-fpic \

main2:
	gcc main2.c \
	-m32 \
	-o chall \
	-Wl,--section-start=.check_section=0x08048600 \
	-Wl,--section-start=.text=0x08048800 \
	#-fpic \


