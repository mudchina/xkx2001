//Cracked by Roath
// chaotian.c 朝天宫 
// by Fang 8/19/96

inherit ROOM;

void create()
{
	set("short", "朝天宫");
	set("long", @LONG
这里已近武当绝顶，只见石梯直耸，危蹬高悬，两旁辅以索链、铁拦勾
连。
LONG
	);
        set("outdoors", "wudang");

	set("exits", ([
		"northdown" : __DIR__"hutouyan",
                "south" : __DIR__"huixian",
	]));
        set("objects", ([
                CLASS_D("wudang") + "/qingxu" : 1]));
	set("cost", 3);
	setup();
	replace_program(ROOM);
}

