//Cracked by Roath
// minority or tribe village and suburban
// Room: /d/dali/minov1.c

inherit ROOM;

void create()
{
	set("short", "大叠水瀑布");
	set("long", @LONG
延山间小路越丘陵，过村庄，穿田野，约二，三里后，隐隐听见水流的轰鸣，
续前进，在一片坡地的前端，呈现倒丫字形深箐，那巨大的轰鸣声，就是从这箐
沟里传出的。延坡上的之字形小路攀藤扶石蜿蜒而下，约五百丈，至箐底，一片
雄奇壮观的瀑布，便呈现在你的眼前。
LONG);
	set("objects", ([
		__DIR__"npc/youke1.c" : 2,
		]));
	set("exits", ([
		"northwest" : __DIR__"minov3",
		"southdown" : __DIR__"minov6",
		"eastup" : __DIR__"minov2",
		]));
	set("area", "大叠水瀑布");
	set("cost", 2);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	setup();
	replace_program(ROOM);
}
