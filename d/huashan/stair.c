//Cracked by Roath
// xiaolu1.c 华山密室石阶
// qfy 10/8/1997

inherit ROOM;

void create()
{
	set("short", "石阶");
	set("long", @LONG
石阶蜿然向下伸延，尽头可见扇紧壁着的石门。两侧石壁上挂着点燃
的火把，把通道照得十分明亮。
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
		"down" : __DIR__"door",
	]));


	set("cost", 0);
	setup();
}


