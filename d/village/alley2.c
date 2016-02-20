//Cracked by Roath
// Room: /d/village/alley2.c

inherit ROOM;

void create()
{
	set("short", "小巷尽头");
	set("long", @LONG
这里是小巷的尽头，一只破木箱上摆着几样粗制的赌具，地上乱扔着些鸡骨
头，空气中有一股鸡香、酒香和汗臭混杂在一起的味道。看来这里是村内地痞、
流氓聚集的地方。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "southeast" : __DIR__"alley1",
]));
	set("no_clean_up", 0);
	set("outdoors", "xxx");
	set("objects", ([
		__DIR__"npc/punk": 1,
		__DIR__"npc/dipi": 1,  ]) );

	set("cost", 1);
	setup();
//	replace_program(ROOM);
}

void init()
{
	object me = this_player();

   	if ( interactive(me) && me->query("huashan/job_pending") ) {
		me->set_temp("hz_job/alley", 1);
   	}
}

