//Cracked by Roath
// huyang road
// maco

inherit ROOM;

void create()
{
    int i;
	set("short", "胡杨林");
	set("long", @LONG
塔里木河岸及沙漠边缘地带，生长着大片茂密的胡杨木(tree)
，巍巍然顶天立地，构成一幅美景。一条渺无人烟的道路笔直通往
东西两侧。
LONG
	);

	set("exits", ([
		"east" : __DIR__"huyang1",
		"west" : __DIR__"huyang3",
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

