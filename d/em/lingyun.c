//Cracked by Roath
// lingyun.c 凌云梯
// Shan: 96/06/22

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "凌云梯");
	set("long", @LONG
这是凌云梯，最早是一位叫阿婆多的外国和尚在此缚木架石，以渡行人，
又叫「胡僧梯」。路边有梅子坡，可见满坡青梅如豆，于疏枝密叶中逗引行人，
甚有「望梅止渴」之功用。此梯北通洗象池，南至雷洞坪。
LONG
	);
	set("exits", ([
		"northdown" : __DIR__"xixiang",
		"southup" : __DIR__"leidong",
	]));

        set("no_clean_up", 0);
        set("outdoors", "emei" );

	set("cost", 3);
	setup();
//	replace_program(ROOM);

}

void init()
{
	add_action("do_look", "look");
}

int do_look(string arg)
{
	object me = this_player();
	int t;
	mixed local;
	
	if ( arg != "梅" && arg != "青梅" && arg != "mei") 
		return command("look "+arg);

	local = localtime(time()*60);
        t = local[2]*60 + local[1];

	if ( t >= 660 && t < 840 ) {
		me->set("water", me->max_water_capacity());
		tell_object(me, HIG"虽然烈日当头，你一看到满坡青梅不由得口舌生津，不再觉得干渴。\n"NOR);
		return 1;
	}
	
	tell_object(me, "一颗颗晶莹的青梅，令人口舌生津。\n");

	return 1;
}
