//Cracked by Roath
// square.c

inherit ROOM;

void create()
{
	set("short", "练武场");
	set("long", @LONG
这里是华山派的练武场，有许多华山派弟子在此习武练剑。南边的房
屋门上挂着一块匾，上书「有所不为轩」，是华山掌门及众弟子的居所。
西边有个兵器房。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
	    "north" : __DIR__"yunu",
	    "south" : __DIR__"buwei1",
	    "west" : __DIR__"wuqiku",   
	]));

	set("objects", ([
	    CLASS_D("huashan") + "/laodenuo" : 1,
	]));

	set("no_clean_up", 0);
	set("outdoors", "huashan" );

	set("cost", 1);
	setup();
	//replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
	mapping myfam;
	object obj;

	myfam = (mapping)me->query("family");

	if ( objectp(obj=present("lao denuo", environment(me))) && living(obj) ) {
	   if ( (!myfam || myfam["family_name"] != "华山派") && dir == "west" )
	   	return notify_fail("劳德诺欠身说道：这位"+RANK_D->query_respect(me)+"请止步！那里是本派的兵器房。\n");

	   if ( myfam && myfam["family_name"] != "华山派" && !me->query_temp("marks/帖") && dir == "south" )
		return notify_fail("劳德诺欠身说道：这位"+RANK_D->query_respect(me)+"可有拜帖呈予家师？\n");
	
	   if ( me->query_temp("marks/剑") && dir == "west" )
		return notify_fail("劳德诺怒视着你说道：不是刚取了剑吗？怎么又想再取？\n");

	   if ( present("zixia book", me) )
		return notify_fail("劳德诺攻势凌历，你无法逃脱！\n"); 
	}

	return ::valid_leave(me, dir);
}