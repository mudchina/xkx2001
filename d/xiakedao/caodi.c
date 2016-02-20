//Cracked by Roath
// xiakedao/chaodi.c
// modified by aln 5 / 98
// Ssy

inherit __DIR__"no_pk_room";

void create()
{
        set("short", "草地");
        set("long", @LONG
这里长着齐腰深的杂草 (grass)，脚下的小路几乎无法辨认。忽
而一阵风吹来，那草随风晃动，从你身上拂过。偶尔回头一瞥，发觉
草丛中好象藏着什麽东西。
LONG );

      set("exits", ([
		"east" : __DIR__"shanxia",
		"west" : __DIR__"tulu",
      ]));
	set("item_desc",([
	    "grass" : "这片杂草足有齐腰深。\n",
	]));

	set("outdoors", "xiakedao" );
	set("cost", 2);
	set("begger_count", 1);
	setup();
}
void init()
{
        ::init();

   	add_action("do_push", "push");
}

int do_push(string arg)
{	object begger, me = this_player();
	if ( !arg )
		return notify_fail( "你要推什么？\n");
	if ( arg != "grass" )
		return notify_fail( "什麽？\n");
	if (present("begger", environment(me)) || (int)query("begger_count") == 0)
	{	if (! present("ye tu", environment(me)))
		{	message_vision("$N拨开杂草，一只野兔跳了出来。\n", me);
			begger = new("/d/wudang/npc/yetu.c");
			begger->move(environment(me));
		}
		else
		{	write("你拨开杂草，没发现什麽。\n");	}
		return 1;	
	}	
	message_vision("$N拨开杂草，一个人影跳了出来，吓了你一大跳。\n", me);
	begger = new(__DIR__ + "npc/xuedao");
	begger->move(environment(me));
	set("begger_count", 0);
	return 1;
}
