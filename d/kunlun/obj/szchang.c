//Cracked by Roath
// Room: /d/mingjiao/szchang.c
// Zhangchi 3/00

inherit ROOM;

void create()
{
	set("short", "铸造场");
	set("long", @LONG
在场子南侧有一座高炉，炉口火孔径不到一尺。一个锐金旗旗下弟子，
身旁放着十余件兵器，目不转睛地望着炉火，每见炉火变色，便将已有些
成型的兵器放入炉中试探火力。旁有两个烈火旗下弟子正卖力地拉扯风箱，
但见炉火直窜上来，火焰高达丈许，蔚为奇观。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"shanlu33",
  "north" : __DIR__"hqku",
]));
	set("objects", ([
		__DIR__"obj/ronglu": 1,
		__DIR__"obj/muzi": 1,
	]));

	set("cost", 1);

	setup();

}

int valid_leave(object me, string dir)
{
        if ((dir == "north" || dir == "west") && this_player()->query_temp("gun_making") )
               return notify_fail("你正在打造火枪，不能离开这里！\n");
        return ::valid_leave(this_player(), dir);
}
