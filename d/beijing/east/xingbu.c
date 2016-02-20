//Cracked by Roath
// Room: /d/beijing/east/xingbu.c

inherit ROOM;

void create()
{
	set("short", "刑部");
	set("long", @LONG
刑部于六部中专门持掌刑法罪案，与太常寺、都察院合称“
三司”，此处肃杀之气极重，路人走到这里无不侧目而视，急行
而过，片刻也不愿停留。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
	"south" : __DIR__"zhaoyangdajie2",
	]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
