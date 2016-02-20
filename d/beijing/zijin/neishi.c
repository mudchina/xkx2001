//Cracked by Roath
// Room: /d/beijing/zijincheng/neishi.c

inherit ROOM;

void create()
{
	set("short", "内室");
	set("long", @LONG
房中放着一张大床，一张小床。墙角放着几只箱子。东首放着
一只大水缸，显得十分突兀。地上湿了一大片。窗子关得甚严，
每一道窗缝都用棉纸糊住。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"zhuchu",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
