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
闪闪发光十分好看。沙滩的尽头是一堵大石壁。有几个女孩正踏浪玩
耍着。偶尔可见大大小小的海龟爬来爬去。
LONG
    	);

    	set("exits", ([
		       "northeast" : __DIR__"jiaoshi3",
		       "west" : __DIR__"shatans2",
		       ]));
    	set("outdoors", "xiakedao");
	set("objects", ([ 
			 __DIR__"npc/haigui" : 1, 
			 ]));

    	setup();
}


