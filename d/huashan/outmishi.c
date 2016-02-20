//Cracked by Roath
// 华山小径
// qfy 30/8/1997

inherit ROOM;

void create()
{
	set("short", "荒山小径");
	set("long", @LONG
这是华山后山的一条小径，人迹难至。两旁野草生得密密麻麻，要不
是从密室里出来，谁也不会到这里来。
LONG
	);

	set("outdoors", "huashan");

	set("exits", ([ /* sizeof() == 1 */
	"northup":__DIR__"xiaolu2",
]));

	set("cost", 2);
	setup();
	replace_program(ROOM);
}
 
