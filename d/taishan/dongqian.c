//Cracked by Roath
// dongqian.c 独孤求败埋骨山洞洞前平地
// qfy July 10, 1996

inherit ROOM;

void create()
{
        set("short", "洞前平地");
        set("long", @LONG
走过了密径，地势豁然开朗，原来已到了一个深谷之中。前面有个黑
黝黝的大山洞(cave)。洞外赫然有一头大雕，好象在守卫着山洞。洞后树
木苍翠，山气极佳。
LONG
        );

	set("exits", ([
                "enter" : __DIR__"dugudong",
	        "south" : __DIR__"mijing",
        ]));

	set("objects", ([
	    __DIR__"npc/shendiao" : 1,
	]));

	set("item_desc",([
	    "cave" : "一个黑黝黝的大山洞，不知里面有些什么东西。\n"
	]));

	//set("no_fight", 1);

	set("outdoors", "taishan");

	set("cost", 1);
        setup();
}

int valid_leave(object me, string dir)
{
	if ( !me->query_temp("marks/跪") && dir == "enter" 
	&& objectp(present("shen diao", environment(me))))
	   return notify_fail("突然一股劲风扑面，神雕挡在你身前，满含敌意地瞪视着你。\n");

	if ( !(me->query_temp("marks/墓")==1 && me->query_temp("marks/跪")==1 
	&& me->query_temp("marks/墙") ) && dir == "west" )
	   return notify_fail("只听得“呱”的一声雕啼，神雕右翅疾展，力道奇猛地向你一拍，不让你过去。\n"); 

 	return ::valid_leave(me, dir);
}

void init()
{
	object me = this_player();

	if ( me->query_temp("marks/墓") == 1 && me->query_temp("marks/跪") == 1
	&& me->query_temp("marks/墙") == 1 && objectp(present("shen diao", environment(me)))) {
	   if ( !me->query_temp("marks/小") ) {
	      message_vision("神雕向$N满意地点头，伸翅指向西边。原来那里有条隐密之极的小径。\n", me);
	   }
	   set("exits/west",__DIR__"xiaojing");
	   remove_call_out("close_up");
	   call_out("close_up", 5, me);
	} 
	add_action("do_kneel", "kneel");
}

int do_kneel(string arg)
{
	object me = this_player();

	if( !arg || arg != "cave" ) 
	   return notify_fail( "什么？\n" );

	me->set_temp("marks/跪", 1);
	message_vision("$N在洞前跪倒，拜了几拜。\n", me);

	if ( objectp(present("shen diao", environment(me))) ) {
	   message_vision("神雕对着$N点了点头，十分满意$N的表现。\n", me);
	}

	return 1;
}

int close_up(object me)
{
//	message_vision("$N低头沉思犹疑不决了好一会儿，猛然抬头时却忘了小径的方向。\n", me);
	delete("exits/west");
	return 1;
}
