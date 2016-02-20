//Cracked by Roath
// guanyin.c 观音堂
// by Shan

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "观音堂");
        set("long", @LONG
观音堂高踞坡岗，近临危崖，环境幽静，四周树木蓊郁，悦目赏心。传说
入山于此，解脱尘凡；出山于此，解脱险阻，又故名解脱庵。进山的人在此焚
香洗心，入山方可化险为夷，步步平安。这里东下可达伏虎寺，西上行约二里
可到归云阁。
LONG
        );
        set("exits", ([
		"westup" : __DIR__"guiyun",
                "east" : __DIR__"jietuo",
        ]));

	set("outdoors", "emei");

	set("cost", 0);
        setup();
//	replace_program(ROOM);
}

void init() 
{
	add_action("do_burn", "burn");
	add_action("do_burn", "fen");
}

int do_burn(string arg)
{
	object me = this_player();

	if ( !arg || (arg != "incense" && arg != "香" && arg != "xiang") )
		return command("burn "+arg);

	this_player()->set_temp("apply/karma", 20+random(20));
	message_vision(YEL"$N虔诚地在观音堂前焚香洗心，以求入山平安。\n"NOR, me);
	return 1;
}

int valid_leave(object me, string dir)
{
	if (dir == "east") me->delete_temp("apply/karma");
	return ::valid_leave(me, dir);
}

