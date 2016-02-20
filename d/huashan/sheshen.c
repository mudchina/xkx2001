//Cracked by Roath
// sheshen.c

inherit ROOM;

void create()
{
	set("short", "舍身崖");
	set("long", @LONG
这是一段极窄极险的山崖，四周云雾飞绕，下面渊深无底。如不小心
，一失足掉下去，只怕连骨头都找不到。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
	  "eastdown" : __DIR__"canglong",
	]));
	
	set("objects",([
//              __DIR__"npc/referee" : 1,
	]));

	set("no_clean_up", 0);
	set("outdoors", "xx" );

	set("cost", 4);
	setup();
//	replace_program(ROOM);
}

void init()
{
	object me = this_player();

   	if ( interactive(me) && me->query("huashan/job_pending") ) {
		me->set_temp("hz_job/sheshen", 1);
   	}
}