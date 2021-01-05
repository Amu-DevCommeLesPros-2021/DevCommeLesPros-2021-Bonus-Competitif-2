champion-debug: champion.c
	gcc --debug champion.c -o champion-debug

champion: champion.c
	gcc -O3 champion.c -o champion

challenger-debug: challenger.c
	gcc --debug challenger.c -o challenger-debug

challenger: challenger.c
	gcc -O3 challenger.c -o challenger

compete: champion challenger
	@START=$$(date +%s); ./champion; END=$$(date +%s); T1=$$(($$END-$$START)); \
	START=$$(date +%s); ./challenger; END=$$(date +%s); T2=$$(($$END-$$START)); \
	echo Champion time: "$$T1"s; \
	echo Challenger time: "$$T2"s; \
	R=`awk "BEGIN {printf \"%.2f\",$${T2}/$${T1}}"`; \
	echo Ratio: $$R

clean:
	rm -rf challenger challenger-debug champion champion-debug
