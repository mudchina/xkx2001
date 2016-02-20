//Cracked by Roath
// 华山小径２
// qfy 25/7/1996

inherit ROOM;

void create()
{
	set("short", "小木屋前");
	set("long", @LONG
一间简陋的小木屋前。西北另有一条小径。
LONG
	);

	set("outdoors", "huashan");

	set("exits", ([ /* sizeof() == 1 */
	"enter":__DIR__"xiaofang",
	"northwest":__DIR__"shaluo",
	"southwest":__DIR__"taogu",
]));

	set("cost", 1);
	setup();
	replace_program(ROOM);
}
 
