//Cracked by Roath
// liangongfang.c 练功房
// by Xiang
// xQin 11/00

inherit ROOM;

void create()
{
	set("short", "练功房");
	set("long", @LONG
这里是练功房，地下凌乱地放着几个蒲团，几位武当弟子正盘膝坐在上
面打坐。
LONG
	);
	set("exits", ([
		"south" : __DIR__"donglang1",
	]));
	set("objects", ([
		"/d/village/obj/zhujian" : 3]));

	set("cost", 0);
	setup();
	replace_program(ROOM);
}
