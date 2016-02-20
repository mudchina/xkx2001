//Cracked by Roath
// xiakedao/yongdao3.c

inherit ROOM;

void create()
{
        set("short", "甬道");
        set("long", @LONG
不知不绝中已渐渐深入山腹，脚下有些磕磕绊绊。你嗅到一股浓
重的潮气，两侧石壁上有些班驳的青苔。偶尔有青衣或黄衣的弟子走
过，遇到客人均是深施一礼，神色恭谨。
LONG );

      set("exits", ([
		"west" : __DIR__"yongdao1",
		"north" : __DIR__"dadong",
      ]));
      set("no_clean_up", 1);

	set("indoors", "xiakedao" );
	set("cost", 0);
    	set("objects", ([ 
		__DIR__ +"npc/shenlong" : 1, 
    	]));
    	set("no_fight", "1");

	setup();
}
void init()
{	add_action("do_kill", "kill");
}

#include "/d/xiakedao/kill.h"
