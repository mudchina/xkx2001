//Cracked by Roath
// Jay 8/9/96

inherit ROOM;

void create()
{
        set("short", "书室");
        set("long", @LONG
室中一张桌子上放着文房四宝，墙上挂着一幅临摹颜真卿的「裴
将军帖」(tie)。床脚摆着一张床(bed)。
LONG
        );
        set("exits", ([
		"west" : __DIR__"huilang",
	]));

	set("objects", ([
		__DIR__"npc/tubiweng" : 1,
	]));

	set("item_desc", ([
                "tie" : "帖上写着：
	裴将军！
	大军制六合，
	猛将清九垓。
	战马如龙虎，
	腾陵何壮哉！\n",
		"bed" : "普普通通的一张床。\n",
	]));
        set("no_clean_up", 0);
	set("cost", 0);
	setup();
        replace_program(ROOM);
}
