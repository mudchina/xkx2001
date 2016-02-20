//Cracked by Roath
// Summer, 10/3/96. 

inherit ROOM;

void create()
{
	set("short", "杂货铺");
	set("long", @LONG
这是一家小小的杂货铺，大箱小箱堆满了一地，都是一些日常用品。
摊上立着一块招牌(zhaopai)。
LONG
	);

	set("item_desc", ([
		"zhaopai": "请用 \"list\" 列出货物表，\"buy\" 向小贩购物。\n",
	]));
	set("exits", ([
		"north" : __DIR__"weststreet",
	]));
	set("objects", ([
		__DIR__"npc/xiao-fan": 1,
	]));

	set("cost", 0);
	setup();
	replace_program(ROOM);
}

