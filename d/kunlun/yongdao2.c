//Cracked by Roath
// Room: /d/mingjiao/yongdao2.c
// Zhangchi 3/00

inherit ROOM;

void create()
{
	set("short", "甬道");
	set("long", @LONG
这是一条又深又长的甬道。每隔三丈处，便点着一个火把，将甬道照
得亮如白昼。两边的墙壁上刻着些不知名的图案，似鬼似魔，似神似兽。
当年明教流转中土时，其教徒为开凿此甬道，不知历经了多少岁月。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"yongdao",
  "south" : __DIR__"shijie2",
  "northup" : __DIR__"shanlu19",
  "northwest" : __DIR__"moluo",
]));
	set("no_clean_up", 0);
	set("cost", 1);

	setup();
	replace_program(ROOM);
}
