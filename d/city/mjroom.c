//Cracked by Roath
// Room: mjroom place to play mj 
// Mantian 05/12/2001

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", GRN"麻将堂"NOR);
	set("long", @LONG
鹿鼎公的生意越做越大，新开张的麻将堂整天聚着很多人。虽然韦小宝自己
大字不识一箩，却也附庸风雅地命人在墙上写上一段古训：“入局斗牌，必先炼
品，品宜镇静，不宜躁率，得勿骄，失勿吝，顺时勿喜，逆时勿愁，不形于色，
不动乎声，浑涵宽大，品格为贵，尔雅温文，斯为上乘。”有面记事板(Board)
被放置在入口处的地方。
LONG);
	set("exits", ([
		"south" : __DIR__"mjroom1",
		"west" : __DIR__"mjroom2",
		"north" : __DIR__"mjroom3",
		"east" : __DIR__"mjroom4",
		"down" : __DIR__"xiaobaozhai",
		]));
	set("no_fight", 1);
	set("no_sleep_room", 1);
	set("no_clean_up", 0);
	set("cost", 3);
	setup();
}
void init()
{
    add_action("do_look", "look");
    add_action("do_look", "l");
}

int do_look(string arg)
{
	object env1, env2, env3, env4;
    object *obj1, *obj2, *obj3, *obj4;
    object me = this_player();
	string msg;
    int i, i1, i2, i3, i4;

	if (!arg || arg != "board") return 0;

	env1 = load_object(__DIR__"mjroom1.c");
	obj1 = all_inventory(env1);

	env2 = load_object(__DIR__"mjroom2.c");
	obj2 = all_inventory(env2);

	env3 = load_object(__DIR__"mjroom3.c");
	obj3 = all_inventory(env3);

	env4 = load_object(__DIR__"mjroom4.c");
	obj4 = all_inventory(env4);

	msg ="";
	if (env1->query_temp("mjstart")  ==  1) msg += RED"红木亭"NOR"：牌局正在进行中。\n";
	if (env2->query_temp("mjstart")  ==  1) msg += YEL"黄菊苑"NOR"：牌局正在进行中。\n";
	if (env3->query_temp("mjstart")  ==  1) msg += HIC"蓝天阁"NOR"：牌局正在进行中。\n";
	if (env4->query_temp("mjstart")  ==  1) msg += GRN"绿竹馆"NOR"：牌局正在进行中。\n";

	for (i = 0; i < sizeof(obj1); i++) 
        if (userp(obj1[i]))
            i1++;

    for (i = 0; i < sizeof(obj2); i++) 
        if (userp(obj2[i]))
            i2++;

    for (i = 0; i < sizeof(obj3); i++) 
        if (userp(obj3[i]))
            i3++;

    for (i = 0; i < sizeof(obj4); i++) 
        if (userp(obj4[i]))
            i4++;

        tell_object(me, "现在各麻将室里的人数有：\n"+ 
		"　　　　"HIC"蓝天阁\n"+
		"　　　　　"+i3+NOR"\n"+
		YEL" 黄菊苑 "+i2+NOR"　　"GRN+i4+" 绿竹馆\n"NOR+ 
		"　　　　　"RED+i1+"\n"+
		"　　　　红木亭\n\n"NOR+msg);
    return 1;
}
int valid_leave(object me, string dir)
{
	object room;
	mapping exit;

	exit = environment(me)->query("exits");

	if ( dir == "east" || dir == "north" || dir == "west" || dir == "south" )
	{
		if( !( room = find_object(exit[dir])) )
			room = load_object(exit[dir]);
		if( room->query_temp("mjstart")  ==  1 )
			return notify_fail("那间麻将室的牌局正在进行中，请等这局结束再进去。\n");
	}
	return ::valid_leave(me, dir);
}
