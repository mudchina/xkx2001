//Cracked by Roath
// Dong 1/9/98
// modified by aln  5 / 98

inherit __DIR__"no_pk_room";

void create()
{
    	set("short", "沙滩");
    	set("long", @LONG
沙滩的边上是一排高高的椰子树，树上还挂着几个椰子。一阵海
风吹过，椰子树随风摇摆着，椰子好像就要掉下来似的。树下有几个
有几个小孩正想如何摘椰子。
LONG
    	);

    	set("exits", ([
    		"west" : __DIR__"shatan",
    		"east" : __DIR__"shatan5",
    	]));
    	set("outdoors", "xiakedao");
	set("objects", ([ 
                "/d/village/npc/kid" : 3, 
      ]));

    	setup();
}

/*
int do_climb(string arg)
{	object coat, me = this_player();
	int dodge;
	if ( (!arg ) || (arg != "tree") )
		return 0;
	dodge = me->query_skill("dodge", 1);
	if (dodge <= 10)
	{	message_vision("$N双手抱着树杆，想爬上树，可惜没爬了一半就跌了下来。\n", me);
		return 1;
	}
	message_vision("$N双手抱着树杆，慢慢地往树上爬去。\n", me);
	
	return 1;
}
*/
