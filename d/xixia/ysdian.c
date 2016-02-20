//Cracked by Roath
// Room: /d/xixia/ysdian.c

inherit ROOM;

void create()
{
	set("short", "议事殿");
	set("long", @LONG
这是皇宫里最大的殿堂，也是西夏皇帝李元昊和群臣议事的地方。
地上铺着雪白的玉石板，两边是雪白的帷幄，靠北居中放着龙椅，上方
悬有一块金匾，上书『天下为公』。是时西夏皇帝虚心纳谏，广招天下
贤士，西夏的国力达到了顶峰，南面的大宋和东面的大辽都颇为顾忌。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"square",
  "north" : __DIR__"huilang",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
