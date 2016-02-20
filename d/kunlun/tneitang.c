//Cracked by Roath
// Room: /d/mingjiao/tneitang.c
// Zhangchi 3/00

inherit ROOM;

void create()
{
	set("short", "内堂");
	set("long", @LONG
此处为厚土旗内堂，地上铺着波斯地毯，几名厚土旗教众在此守卫。
堂中陈设甚是简单，靠北有一扇半旧的屏风，室内也有几张桌椅，
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"tdating",
]));
	set("no_clean_up", 0);
	set("cost", 1);

	setup();
	replace_program(ROOM);
}
