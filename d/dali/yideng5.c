//Cracked by Roath
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "山顶");
	set("long", @LONG
这是山峰的顶上，一大块平地，开垦成二十来亩山田，种着禾稻，一柄锄头
抛在田边，半坡上斜出一块岩石(rock)，一头黄牛仰卧其上，四蹄乱蹬，却翻不
过身来。下面一人摆起丁字步，双手牢牢的托住了岩石。
LONG);
	set("objects", ([
		"/kungfu/class/dali/farmer" : 1,
        ]));
	set("item_desc", ([
		"rock" : "　　这头牛少说也有三百斤上下，岩石的份量瞧来也不在那牛之下，虽有一\n半靠着山坡，但那人稳稳托住，也算得是神力惊人。\n",
        ]));
	set("exits", ([
		"down" : __DIR__"yideng4",
        ]));
	set("cost", 2);
	set("no_fight", 1);
	set("no_clean_up", 0);
	set("outdoor","dali");
    set("no_sleep_room",1);
	set("invalid_startroom", 1);
	setup();
	replace_program(ROOM);
}
