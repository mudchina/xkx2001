//Cracked by Roath
// hz_chanfang.c 华藏庵禅房
// Shan: 96/06/22

#include <room.h>
inherit ROOM;

string look_door();

void create()
{
        set("short", "华藏庵禅房");
	set("long", @LONG
这里便是峨嵋华藏庵的禅房。地下散乱地放着许多蒲团，木鱼等，此处
正是本派弟子打坐修行之所。几位年轻师太和俗家女弟子正肃容入定。
　　禅房后面有一道门通往华藏庵休息室，北边的走廊通向广场。
LONG
	);
	set("exits", ([
		"south" : __DIR__"sleeproom",
		"north" : __DIR__"hz_xilang2",
	]));

	set("jingzuo_room", 1);

        set("item_desc",([
                "door"          :       (: look_door :),
        ]));

        create_door("south", "木门", "north", DOOR_CLOSED);

	set("no_fight", 1);

	set("cost", 0);
	setup();
//	replace_program(ROOM);

}

string look_door()
{
        return "一道小门连通禅房与休息室，门上挂着个小牌子：休息室。\n";

}

void init()
{
	add_action("do_jingzuo", "jingzuo");
}

int do_jingzuo(string arg)
{
	object me = this_player();
        if ( me->query("family/family_name") != "峨嵋派" || me->is_busy() )
                return command("jingzuo "+arg);
	if(random(9) == 3) {
		tell_object(me, "忽然外面传来一阵噪杂声，你只觉心烦意乱，不能静心修练，\n只好改去别庵禅房继续修行。\n");
		tell_room(environment(me),(string)me->query("name")+"走啦，去别庵禅房继续修行了。\n", me);
		switch (random(3)) {
			case 0: me->move("/d/emei/chanfang_fs");
				break;
			case 1: me->move("/d/emei/chanfang_wn");
				break;
			case 2: me->move("/d/emei/chanfang_qf");
				break;
		}
		tell_room(environment(me),(string)me->query("name")+"从别庵禅房来这里继续修行啦。\n", me);
		return 1;
	}
	return command("jingzuo "+arg);
}

int valid_leave(object me, string dir)
{
	if ( me->query("gender") != "女性" && dir == "south" ) 
		return notify_fail("南面乃峨嵋女侠休息之所，这位" + 
			RANK_D->query_respect(me) + "还请留步。\n");
		
	return ::valid_leave(me, dir);
}
