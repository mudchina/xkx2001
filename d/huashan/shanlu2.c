//Cracked by Roath
// 华山玉女峰小径
// qfy 26/6/1996

inherit ROOM;

void create()
{
        set("short", "玉女峰小径");
	set("long", @LONG
走完这条小径，便能到达峰顶的思过崖。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  		"southdown" : __DIR__"shanlu1",
  		"northup":__DIR__"siguoya",
	]));

	set("outdoors", "huashan");

	set("cost", 3);
        setup();
        replace_program(ROOM);
}
 
