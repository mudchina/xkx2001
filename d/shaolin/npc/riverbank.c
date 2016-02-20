//Cracked by Roath
//河边
//xiaojian May 20,2000

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "汉水岸边");
	set("long",@LONG
这里是汉水岸边，因为地势平坦开阔的缘故，这里的水流显
得缓和了许多，所以这里的河水看上去清澈干净。南阳城的居民
都在这里挑水喝，岸边还有几个农村妇女蹲着洗衣服。
LONG);
	
        set("exits", ([
        "northup" : __DIR__"shanlu",
		"west" : __DIR__"hanshui2",
        ]));

	set("no_fight",1);
	set("no_steal",1);
	set("cost",0);
        set("no_clean_up", 1);
        set("outdoors", "shaolin");
        set("resource/water", 1);
	setup();
}

int init()
{
	add_action("do_yao", "yao");
	
}

int do_yao(string arg)
{

	object me, ob;
	me = this_player();
		
	if(!arg || (arg != "shui" && arg != "water"))
		return notify_fail("你要舀什么？\n");	
	ob = present("shui piao", me);
        if (!ob)
		return notify_fail("你身上没有水瓢，怎么舀水? \n");
        if (me->is_busy())
                return notify_fail("你正忙着呢！\n");
	if (ob->query("water_filled"))
			return notify_fail("瓢里已经盛满了水了。\n");
	if (!me->query("shaolin/job_asked"))
        	return notify_fail("你又没有领任务，干吗何必往河边跑？当心淹死！\n");
	if (random(10) ==1)
	{ 
		message_vision(HIR"$N一不小心，手上一滑,把瓢掉到河里了。\n"NOR, me);
		destruct(ob);
		return 1;
	}
    message_vision("$N弯下腰，从清澈的河水中舀了一瓢水。\n",me);
	ob->set("water_filled",1);
	me->start_busy(3+random(2));
	me->receive_damage("jingli", (5+ random(5)));
	return 1;
}
int valid_leave(object me, string dir)
{
        if( dir=="west" && !wizardp(me) &&(me->query("shaolin/job_asked") ))
                return notify_fail("想偷懒？不怕戒律院的主持处你以杖刑? \n");
        return ::valid_leave(me, dir);
}

