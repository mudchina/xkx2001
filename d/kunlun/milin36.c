//Cracked by Roath
// Room: /d/mingjiao/milin36.c
// Zhangchi 3/00

inherit ROOM;

void create()
{
	set("short", "密松林");
	set("long", @LONG
此处古松参天，千奇百怪。耳旁似隐隐听到阵阵山风，林中却没有一
丝动静。松枝上不时有几只松鼠蹿来蹿去，相戏成趣。巨木旗的教众们经
常在这里砍伐树木。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"xiaolu37",
  "east" : __DIR__"shanlu76",
]));
	set("objects", ([
		__DIR__"obj/pine" : 2,
	]));

	set("cost", 2);

	setup();
//	replace_program(ROOM);
}

