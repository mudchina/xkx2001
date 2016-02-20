//Cracked by Roath
// Room: /d/xiangyang/wofang1.c

inherit ROOM;

void create()
{
	set("short", "卧房");
	set("long", @LONG
这是郭靖和黄蓉的寝室，楠木上摆设著个白瓷花瓶，房中
萦绕著淡淡的檀香味。整个房间虽不华丽，却是幽静雅致，令人神
清气爽。
LONG
	);
	set("no_clean_up", 0);
        set("coordinates", ([ "x" : 6, "y" : -6 ]) );
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"huilang1",
]));

	setup();
	replace_program(ROOM);
}
