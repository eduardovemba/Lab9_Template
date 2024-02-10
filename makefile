stack:
	gcc -Wall -o prog input.c adtstack/main.c adtstack/stackArrayList.c adtstack/stackElem.c
stack_debug:
	gcc -Wall -o prog -g input.c adtstack/main.c adtstack/stackArrayList.c adtstack/stackElem.c
queue:
	gcc -Wall -o prog input.c adtqueue/main.c adtqueue/queueArrayList.c adtqueue/queueElem.c
queue_debug:
	gcc -Wall -o prog -g input.c adtqueue/main.c adtqueue/queueArrayList.c adtqueue/queueElem.c
clean:
	rm -f prog
