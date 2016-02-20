//Cracked by Roath
// xiakedao/yongdao.c
// modified by aln 5 / 98

inherit __DIR__"no_pk_room";

void create()
{
        set("short", "石壁");
        set("long", @LONG
这是在山坡上突出来的一块石壁，四周杂草丛生。左边好象有个
小洞(hole)，似乎可以钻(zuan)进去。从这跳(jump)下去就是山脚了。
LONG );
        set("objects", ([ 
			 __DIR__ + "npc/monkey" : 1, 
      ]));

	set("outdoors", "xiakedao" );
	set("cost", 0);
	setup();
}

void init()
{
        ::init();

	add_action("do_zuan", "zuan");
	add_action("do_jump", "jump");
}

int do_zuan(string arg)
{	object me = this_player();
	if ( !arg )
		return notify_fail( "你想钻什麽?\n");
	if ( arg != "hole" )
		return notify_fail( "老老实实 zuan hole 吧。\n");
	message_vision("$N一弯腰，往那洞口钻了进去。\n", me);
	write("你在洞里爬了一会儿，突然眼前一亮。\n");
	me->move(__DIR__"yongdao2");
	message("vision", me->name() + "从洞里钻了出来。\n",environment(me), ({me}) );

	return 1;
}
int do_jump(string arg)
{	object me = this_player();
	if ( !arg )
	{	write("你要往哪跳？\n");
		return 1;
	}
	if ( arg != "down" )
		return 0;
	message_vision("$N从山坡上跳了下去。\n", me);
	me->move(__DIR__"shanxia");
	if (me->query_skill("dodge") > 20) 
		message("vision", me->name() + "山坡上跳了下来。\n",environment(me), me );
	else
		message("vision", me->name() + "山坡上滚了下来。\n",environment(me), me );
	return 1;
}
