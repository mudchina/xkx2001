//Cracked by Roath
// Room: /d/beijing/zijincheng/yuchafang.c

inherit ROOM;

void create()
{
	set("short", "御茶房");
	set("long", @LONG
这里是太监的值房,几个太监在这里随时等候皇帝的宣召。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "westup" : __DIR__"qianqinggong",
  "south" : __DIR__"duanningdian",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
