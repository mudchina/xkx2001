//Cracked by Roath
// Room: /city/zhulin2.c

inherit	ROOM;

void create()
{
		set("short", "竹林小道");
		set("long",	@LONG
这是一条竹林小道，两旁尽是遮天蔽日的茂密的竹林。
LONG
		);

		set("exits", ([
				"east" : __DIR__"gbxiaowu",
				"west" : __DIR__"zhulin1",
				"south"	: __DIR__"ml1",
				"north"	: __DIR__"zhulin3",
		]));

		set("objects", ([
				"clone/weapon/zhubang":	1,
				"d/gaibang/obj/yellowbang":	1,
		]));

		set("cost",	2);
		set("bang_count", 2);
		setup();
//		replace_program(ROOM);
}

void init()
{
		add_action("do_make", "make");
		add_action("do_make", "zuo");
}

int	do_make(string arg)
{
		object me =	this_player();
		object ob =	new("clone/weapon/zhubang");

		if ( !arg || arg ==	"")	return 0;

		if ( arg ==	"zhu bang" ){
				if (query("bang_count")	< 1) {
						tell_object(me,	"能做竹棒的竹子都截光了。\n", me);
						return 1;
				}
				else if	( me->query_str() <	20)	{
						tell_object(me,	"你的力气不够截竹子做竹棒。\n",	me);
						return 1;
				}
				else {
						message_vision("$N折下一杆竹子，做了一只竹棒。\n", me);
						ob->move(me);
						add("bang_count", -1);
						return 1;
				}
		}
		return 0;
}

