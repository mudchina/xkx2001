//Cracked by Roath
// Room: /d/beijing/zijincheng/wuyingdian.c

inherit ROOM;

void create()
{
	set("short", "武英殿");
	set("long", @LONG
是皇帝斋戒及召见大臣的地方，后殿的群房是宫廷画家们作画的
场所。后来这里成为修书处,为皇家刻印了大批书籍,称为殿版.

这是御林军的中军大帐。当中是一张虎皮大雕椅，两边是十张木
椅，供军中将领下坐。门口有刀斧手在伺候。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"guang3",
  "north" : __DIR__"jingsidian",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
