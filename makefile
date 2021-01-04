champion-debug: champion.c
	gcc --debug champion.c -o champion-debug

champion: champion.c
	gcc -O3 champion.c -o champion

challenger-debug: challenger.c
	gcc --debug challenger.c -o challenger-debug

challenger: challenger.c
	gcc -O3 challenger.c -o challenger

compete: champion challenger
	