//Cracked by Roath
// 华山小径
// qfy 22/7/1996

inherit ROOM;

void create()
{
        set("short", "后山小径");
	set("long", @LONG
这是华山后山的一条小径，人迹鲜至。两旁野草生得密密麻麻，要不
是有人带领，谁也想不到这里竟然有条小径。
LONG
        );

	set("outdoors", "huashan");

        set("exits", ([ /* sizeof() == 1 */
  	"north":__DIR__"taogu",
]));

	set("cost", 2);
        setup();
        replace_program(ROOM);
}
 
