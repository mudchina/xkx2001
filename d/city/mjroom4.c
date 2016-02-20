//Cracked by Roath
// Room: mjroom place to play mj 
// Mantian 05/12/2001
#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", GRN"绿竹馆"NOR);
	set("long", @LONG
一间以绿竹布置成的麻将室，是个休闲的好地方。房间里有一张绿竹编制的
桌子，铺着一块绿戎布，上面写着东，南，西，北，桌上摆着一副麻将，四周各
有一张绿竹凳。墙上有一块竹制的计分板(Board)。
LONG);
	set("exits", ([
		"west" : __DIR__"mjroom",
		]));
	set("objects", ([
		__DIR__"npc/mjxiaosi" : 1,
		__DIR__"obj/gtable" : 1,
		]));
	set("item_desc", ([
		"board": GRN"    一块竹制的计分板，上面记满了以往牌局的分数。\n"
					"你可一用mjscore来查询自己的分数，mjscore <ip>来\n"
					"查某人的分数，mjscore -l看全部的资料。\n"NOR,
		]) );
	set("no_fight", 1);
	set("no_sleep_room", 1);
	set("no_clean_up", 0);
	set("cost", 3);
	setup();
}
void init()
{
	add_action("do_practice", "kill");
	add_action("do_practice", "practice");
	add_action("do_practice", "lian");
	add_action("do_practice", "dazuo");
	add_action("do_practice", "exercise");
	add_action("do_practice", "tuna");
	add_action("do_practice", "respirate");
	add_action("do_practice", "quit");
}
int do_practice()
{
	if (query_verb()=="quit") write("你无法在麻将室里离开游戏！！\n");
	if (query_verb()=="kill") write("你来这是来打麻将而不是打架。\n");
    if (query_verb()=="exercise") write("来这是来打麻将而不是打坐。\n");
    if (query_verb()=="dazuo") write("来这是来打麻将而不是打坐。\n");
    if (query_verb()=="lian") write("来这是来打麻将而不是练功。\n");
    if (query_verb()=="practice") write("来这是来打麻将而不是练功。\n");
    if (query_verb()=="respirate") write("来这是来打麻将而不是吐呐。\n");
    if (query_verb()=="tuna") write("来这是来打麻将而不是吐呐。\n");
	return 1;
}
int valid_leave(object me, string dir)
{
	if (me->query_temp("打麻将中"))	return notify_fail("打牌打一半，想跑去哪？\n");
	if (this_object()->query_temp("mjstart") && dir == "west")	return notify_fail("牌局进行中你跑来跑去会影响他人，等这局完了在走吧。\n");
	return ::valid_leave(me, dir);
}
