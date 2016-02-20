//Cracked by Roath
// Room: /d/quanzhou/tieqiang.c
// Date: May 21, 96   Jay
#include "ansi.h"
inherit ROOM;

int do_break(string);

void create()
{
	set("short", "铁枪庙");
	set("long", @LONG
这庙很破旧，中间竖着一尊塑像(xiang)。庙旁有座高塔，塔顶
群鸦世代为巢，当地乡民传说铁枪庙的乌鸦是神兵神将，向来不敢侵
犯，以致生养繁殖，越来越多。
LONG
	);

	set("no_fight", "1");

	set("item_desc", ([
                "xiang" : "这是五代时名将铁枪王彦章的塑像。\n",
        ]));


	set("exits", ([
                "west" : __DIR__"jxnanmen",
		"north" : __DIR__"nanhu",
	]));

        set("objects", ([
		__DIR__"npc/wuya": 4]));

	set("outdoors", "quanzhou");
	set("cost", 0);
	setup();
}
void init()
{
        add_action("do_break","break");
}

int do_break(string arg)
{
    int n;
    object me = this_player();
    object gold,ring,mo;

    n = me->query("neili");
    if( !arg || arg!="xiang" ) {
        write("不要随便打碎别人的东西！\n");
        return 1;
    }


    message_vision(
    "$N绕到塑像后，拜出骑马蹲裆式，深吸一口气，双掌同时拍出。\n", me);
        
    if (n>=500 && me->query_temp("qi/tangshi") && !me->query("连城诀")
	&& me->query("max_neili") >= 1000) {
        message_vision(
        "只听一声轰响，$N把塑像的背后硬生生震开了一个大口子！\n", me);
	tell_object(me,HIR "你发现原来塑像是空心的。\n" NOR);
	
		if(query("broken")){
		tell_object(me, "塑像中空空如野，什麽也没有。\n");
		return 1;
		}

        me->set("neili",n-200);
	ring = new ("/d/city/obj/goldring");
	mo = new ("/d/foshan/obj/huimo");
	gold = new("/clone/money/gold");
	gold->set_amount(200);
	ring -> move(me);
	mo -> move(me);
	gold->move(me);
	tell_object(me,HIR "你发现原来塑像是空心的。\n" NOR);
	tell_object(me,HIY "你从塑像中得到了一大堆黄金！\n" NOR);
	tell_object(me,HIB "你还从里面找到了一个金戒指和一端徽墨！\n" NOR);
	me->set("连城诀",1);
	me->delete_temp("qi/tangshi");
	set("broken", 1);
    }
    else {
        message_vision(
        "$N大吼一声“开！”，结果虽然内力耗尽，什么也没发生。\n", me);
        me->set("neili",0);
    }

    return 1;
}


