//Cracked by Roath
// Dong 1/9/98
// modifiedy by aln 5 / 98
// Ssy

inherit __DIR__"no_pk_room";

void create()
{
    	set("short", "沙滩");
    	set("long", @LONG
沙滩不是很大，白白的细沙间藏着许多贝壳，海浪冲过，阳光下
闪闪发光十分好看。沙滩的边上是一排高高的椰子树，树上还挂着几
只椰子。一阵海风吹过，椰子树随风摇摆着，椰子好像就要掉下来似
的。偶尔可见大大小小的海龟爬来爬去。
LONG
    	);

    	set("exits", ([
		       "east" : __DIR__"shatans3",
		       "west" : __DIR__"shatan",
		       ]));
    	set("outdoors", "xiakedao");
	set("objects", ([ 
			 __DIR__"npc/haigui_s" : 2, 
			 ]));

    	setup();
}


