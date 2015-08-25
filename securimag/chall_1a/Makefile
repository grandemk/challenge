all:
	gcc main.c \
	-m32 \
	-o chall \
	-Wl,--section-start=.check_section=0x08048600 \
	-Wl,--section-start=.text=0x08048800 \
	#-fpic \



