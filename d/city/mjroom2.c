//Cracked by Roath
// Room: mjroom place to play mj 
// Mantian 05/12/2001
#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", YEL"黄菊苑"NOR);
	set("long", @LONG
此间花香满堂，一进到这里就觉得精神气爽。房间里内外开满了许多黄菊，
一张淡黄色的大理石桌上铺着一块鹅戎布，上面写着东，南，西，北，桌上摆着
一副麻将，四周的小凳皆以鹅戎所罩。墙上的计分板(Board)是以山羌木所雕制。
LONG);
	set("exits", ([
		"east" : __DIR__"mjroom",
		]));
	set("objects", ([
		__DIR__"npc/mjxiaosi" : 1,
		__DIR__"obj/ytable" : 1,
		]));
	set("item_desc", ([
		"board": YEL"    一块以山羌木所雕制的计分板，上面记满了以往牌局\n"
					"的分数。你可一用mjscore来查询自己的分数，mjscore <ip>\n"
					"来查某人的分数，mjscore -l看全部的资料。\n"NOR,
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
	if (this_object()->query_temp("mjstart") && dir == "east")	return notify_fail("牌局进行中你跑来跑去会影响他人，等这局完了在走吧。\n");
	return ::valid_leave(me, dir);
}
