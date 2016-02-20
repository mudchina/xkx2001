//Cracked by Roath
//Chaos, Ryu, 3/10/97

inherit ROOM;

void create()
{
	set("short", "刺藤树丛");
	set("long", @LONG
你走了一阵，前面出现一片无法通过的密林，这林子好不古怪，每株树上生满了
长藤钩刺，难以落脚。走不了两步，就被长藤缠住，放眼远望，前面刺藤树密密层层，
不知道能不能走出去。
LONG
	);
	 set("exits", ([
                "west" : __DIR__"shulin2",
                "east" : __DIR__"beach",
                "north" : __DIR__"shanlu1",
        ]));
	set("cost", 5);
	set("outdoors", "taohua");

	setup();
	replace_program(ROOM);
}
