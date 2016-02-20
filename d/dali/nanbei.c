//Cracked by Roath
// Room: /d/dali/nanbei.c

inherit ROOM;

void create()
{
	set("short", "南诏德化碑");
	set("long", @LONG
南诏阁逻风于大唐天宝年间，同大唐两次交战，歼唐军十六万。过后，阁逻
风有悔意，为一时交恶，“岂顾前非，而忘大礼”。于是，派人收拾唐军阵亡将
士，“祭而葬之，以存恩旧”，同时，令人撰文，详记天宝战争的近因和结果，
表达不得已而叛唐的苦衷，将它刻成巨碑，于天宝十一年立于王都太和城国门外。
LONG);
	set("exits", ([
		"northeast" : __DIR__"guandao.c",
		"south" : __DIR__"taihec.c",
		]));
	set("cost", 2);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	setup();
	replace_program(ROOM);
}
