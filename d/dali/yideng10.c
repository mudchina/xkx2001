//Cracked by Roath
// yideng10.c

inherit ROOM;
void create()
{
	set("short", "禅房");
	set("long", @LONG
这里是一间内室禅房，一般是打坐入定的地方。偶尔也用来接待佛门高僧，
探讨佛理。
LONG);
	set("exits", ([
		"out" : __DIR__"yideng12.c",
        ]));
	set("cost", 2);
	set("no_clean_up", 0);
	set("no_sleep_room",1);
	set("invalid_startroom", 1);
	setup();
}

int valid_leave(object me, string dir)
{
	object yd;
	if (objectp(yd=present("yideng dashi", environment(me))))
	{
		message_vision("一灯大师对$N微微笑了笑：“你改变主意不需要我的治疗了？好吧。”\n说罢转身离开了禅房。\n", me);
		me->delete_temp("yideng_waitreward");
		yd->move("/d/dali/yideng9.c");
	}
    return ::valid_leave(me, dir);
}
