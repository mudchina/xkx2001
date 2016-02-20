//Cracked by Roath
// /d/emei/yunu.c 
// xbc, xuy: 96/07/09

inherit ROOM;

#include <ansi.h>

void create()
{
        set("short", "玉女峰");
        set("long", @LONG
这是归云阁边的玉女峰，峰顶有一个四尺见方的小池，深亦四尺，四季不枯，
传为天女沐浴之器。古时州刺史冯楫，曾在此结茅而居，发奋诵读《华严经》，
不食人间烟火，于是玉女下凡，为他馈赠食物。
LONG
        );
        set("exits", ([
		"northdown" : __DIR__"guiyun",
        ]));

	set("outdoors", "emei");

        set("objects", ([
                CLASS_D("emei") + "/fang" :1,
        ]));


	set("cost", 4);
        setup();
//	replace_program(ROOM);
}

void init()
{
	add_action("do_wash", "wash");
}

int do_wash(string arg)
{
	object me = this_player();
	if ( !arg || arg != "face" ) return 0;

	message_vision(CYN"$N轻轻地捧起一些天池之水洗了洗脸。\n"NOR, me);

	if ( me->query("gender") == "女性" && 
	     me->query_skill("beauty", 1) > 30 &&
	     me->query_skill("beauty", 1) < 120) {
		tell_object(me, CYN"你觉得发现了一些新的驻颜窍门。\n"NOR);
		me->improve_skill("beauty", me->query_per()*2);
		me->receive_damage("jing", 10, "把脸洗破，羞死了");
	}
	
	return 1;
}
