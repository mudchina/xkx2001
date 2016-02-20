//Cracked by Roath
// yideng quest room 7

inherit ROOM;

void create()
{
	set("short", "缺口");
	set("long", @LONG
山路中间突然中断，前面的山中间裂开，出现了一个缺口(gap)。石壁直上
直下，下面黑黝黝地深不见底，看来可能是地震造成的。山路在对面的山上继续
蜿蜒向前。
LONG);
	set("item_desc",([
		"gap" : "　　这缺口看起来倒是不宽，可以跳过去，但是对面有个书生挡着，如果他\n在你跳到半空的时候出手攻击，那你是必死无疑。\n",
		]));
	set("objects", ([
		"/kungfu/class/dali/zhu.c" : 1,
		]) );
	set("exits", ([
		"down":__DIR__"yideng5",
		]));
	set("cost", 2);
	set("no_clean_up", 0);
	set("outdoor","dali");
	set("no_sleep_room",1);
	set("invalid_startroom", 1);
	setup();
}

void init()
{
	add_action("do_kill", "kill");
	add_action("do_kill", "fight");
	add_action("do_steal", "steal");
	add_action("do_steal", "throw");
}

int do_kill(string arg)
{
	if (arg=="zhu" || arg=="ziliu" || arg=="zhu ziliu")
	{
		tell_object(this_object(), "隔着这个缺口，你怎么攻击他啊？\n");
		return 1;
	}
	return 0;
}

int do_steal(string arg)
{
	tell_object(this_object(), "山顶之上，决无遮掩，你没有办法偷袭。\n");
	return 1;
}

