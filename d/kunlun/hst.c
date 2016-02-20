//Cracked by Roath
// Room: /d/mingjiao/hst.c
// Zhangchi 3/00

inherit ROOM;

void create()
{
	set("short", "洪山亭");
	set("long", @LONG
“耸耳静听山中趣，睁目细观云下情”。古松半绕，巨柏稍掩，云烟
清漫，花香淡然。后依山脊，抬首望去，山、水、花、木在薄薄的雾帐下，
缓缓地，轻轻地，融进了一体，再也分不出来。只闻得瑶池的仙乐和一丝
丝霏香。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"xiaochang",
  "southeast" : __DIR__"qingyun",
]));
	set("no_clean_up", 0);
	set("cost", 1);

	setup();
	replace_program(ROOM);
}
