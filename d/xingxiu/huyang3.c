//Cracked by Roath
// huyang road
// maco

inherit ROOM;

void create()
{
    int i;
	set("short", "胡杨林");
	set("long", @LONG
道路两边生长着大片茂密的胡杨木(tree)，巍巍然顶天立地，
构成一幅美景。大道在此分岔，东行逐渐接近沙漠，南边仍是一片
胡杨林，西去隐隐可见两座白沙堆积成的山丘。
LONG
	);

	set("exits", ([
		"east" : __DIR__"huyang2",
		"south" : __DIR__"huyang5",
		"west" : __DIR__"huyang4",
	]));
	set("item_desc", ([
	"tree" : "胡杨是荒漠中最高大的树木，阻挡了大漠风沙，也使沙漠不至继续扩大。\n"
		"人们夸赞胡杨的生命力，说它的寿命是“三个一千年”：\n"
		"能在荒漠上生活一千年不死，死後立在荒漠上一千年不倒，倒後在荒漠上一千年不烂。\n",
	]));
	set("outdoors","xingxiu");
	set("cost", 2);
	setup();
	replace_program(ROOM);
}

