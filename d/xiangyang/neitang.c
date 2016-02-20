//Cracked by Roath
// Room: /d/xiangyang/neitang.c

inherit ROOM;

void create()
{
	set("short", "内堂");
	set("long", @LONG
此处是接待宾客的厅堂，四周布置清雅，几张梨木椅排开，虽
非雕梁画栋，但格局开阔，自有气象。西首照壁上悬挂著几幅字画
，笔致苍劲。南边回廊前湘帘低掩，是往後花园的路径。
LONG
	);
	set("no_clean_up", 0);
	set("coordinates", ([ "x" : 3, "y" : -4 ]) );
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"dating",
  "east" : __DIR__"shanfang",
  "south" : __DIR__"huajing",
]));

	setup();
	replace_program(ROOM);
}
