//Cracked by Roath
// dating.c 大厅
// xQin 11/00

inherit ROOM;

void create()
{
	set("short", "大厅" );
	set("long", @LONG
穿过滴水檐来到大厅上，只见眼前豁然一片开阔。大厅地上铺着青石砖
片，十几张桃木椅左右排开。厅内布局虽简雅朴素，却丝毫不失庄严之风。
这里也是武当派接见来客的客厅。
LONG
	);
	set("exits", ([
		"south" : __DIR__"sanqingdian",
		"north" : __DIR__"dishuiyan",
	]));
	
	setup();
	replace_program(ROOM);
}

	
	
		