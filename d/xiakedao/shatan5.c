//Cracked by Roath
// Dong 1/9/98
// modifiedy by aln 5 / 98


void create()
{
    	set("short", "沙滩");
    	set("long", @LONG
沙滩不是很大，白白的细沙间藏着许多贝壳，海浪冲过，阳光下
闪闪发光十分好看。沙滩的尽头是一堵大石壁。有几个女孩正踏浪玩
耍着。
LONG
    	);

    	set("exits", ([
    		"west" : __DIR__"shatan4",
    	]));
    	set("outdoors", "xiakedao");
	set("objects", ([ 
                "/d/city/npc/girl" : 3, 
      ]));

    	setup();
}


