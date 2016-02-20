//Cracked by Roath
// author: chu@xkx
// name: queue.c
// date: 5/8/98

#include <ansi.h>
#define INIT_CAP 320
#define CAP_INC 320

int capacity, head, tail;
mixed data;

void create()
{
    capacity = INIT_CAP;
    data = allocate(capacity);
    head = 0;
    tail = 0;
}

int size()
{
    if (tail>=head) return tail-head;
    return capacity+tail-head;
}

int full()
{
    if (head-1 == tail) return 1;
    if ((head == 0) && (tail == capacity-1)) return 1;
    return 0;
}

int empty()
{
    return (tail==head);
}

int info()
{
    printf("queue: capacity=%d, head=%d, tail=%d\n", capacity,
		head, tail);
    return capacity;
}

void enque(object ob)
{
    int i, j, new_cap;
    mixed new_data;

    // printf("debug queue: before enque, size=%d, head=%d, tail=%d", size(), head, tail);
    if (full()){
 	new_cap = capacity+CAP_INC;
	new_data = allocate(new_cap);
	j=head;
	for (i=0; i<capacity; i++){
	    new_data[i] = data[j];
	    j++;
	    if (j==capacity) j=0;
 	}
	data = new_data;
	head = 0;
	tail = capacity-1;
	capacity = new_cap;
    }

    data[tail] = ob;
    tail++;
    if (tail >= capacity) tail=0;
    // printf(", after enque, size=%d, head=%d, tail=%d\n", size(), head, tail);
}

object deque()
{
    object ob;

    //printf("debug queue: before deque, size=%d, head=%d, tail=%d, ", size(), head, tail);
    if (empty())  return 0;
    
    ob = data[head];
    head ++;
    if (head >= capacity) head = 0;
    //printf("after deque, size=%d, head=%d, tail=%d\n", size(), head, tail);
    return ob;
}

int contains(object ob)
{
    int i;

    /** debug
    printf("calling contains, capacity=%d, head=%d, tail=%d\n",
		  capacity, head, tail);
    */
    for (i=head; i!=tail;) {
	if (data[i] == ob) return 1;
  	i++;
        if (i==capacity) i=0;
    }
    return 0;
}

