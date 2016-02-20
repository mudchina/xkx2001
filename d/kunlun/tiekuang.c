//Cracked by Roath
// Room: /d/mingjiao/luanshidui.c
// Zhangchi 3/00

#include <ansi.h>
inherit ROOM;

int start_wa(object me);
int check_busy(object me);

void create()
{
        set("short",HIR "铁矿" NOR);
        set("long", HIW @LONG
这里是一个光秃秃的小山丘，四周什么花草树木也没有。仔细一看，
发现山丘周围有些黑黝黝的大石头，这就是光明顶盛产的乌金铁矿石。明
教教众用的兵器都是用这种矿石铸造而成，比之寻常精铁铸造的兵器更为
坚固，锋利。
LONG NOR
);      
        set("exits", ([ /* sizeof() == 1 */
	  "northeast" : __DIR__"shanlu23",
	]));

         set("invalid_startroom", 1);
		 set("wa_times",15);
		setup();

}

void init()
{
          add_action("do_save", "save");
		  add_action("do_wa", "excavate");
		  add_action("do_wa", "dig");
}

int do_save(string arg)
{
           
	write("这里并非一般地方,不能在这里纪录。\n");
	return 1;
	
}

int do_wa(string arg)
{
	object qiao,me;

	me = this_player();

	if( me->is_busy() || me->query_temp("pending/job_busy") )
		return notify_fail("你正忙着呢。\n");

	if( me->query("mingjiao/job") != "jin_caikuang")
		return notify_fail("这里不能随便乱挖！\n");

	if( present("wujin kuangshi", me) )
		return notify_fail("你已经有一块矿石，实在抱不动第二块了。\n");

	if( !objectp(qiao = present("tie qiao", me)) )
		 return notify_fail("你没有趁手的工具，无法开采铁矿\n");

	if (me->query("jingli") < 90)
		return notify_fail("你已经精疲力竭了！\n");

	if(query("wa_times")>0)
	{
		message_vision("$N将铁锹拿在手上，看准了一块黑黝黝的乌金铁矿石，用力向下挖去。\n",me);
		me->set_temp("pending/job_busy",1);
		call_out("start_wa", 10, me);
		me->start_busy( (: check_busy :) );
	}
	else
		tell_object(me,"矿石似乎都被挖光了。\n");
	
	return 1;
	
}

int check_busy(object me)
{
	if (me->query_temp("pending/job_busy")) return 1;
	return 0;
}

int start_wa(object me)
{
	object kuangshi;

	if(me->query("jingli")>90&&random(3)==1)
	{
		message_vision("$N将一小块"+HIB"乌金矿石"NOR+"挖了出来放在身上。\n",me);
		add("wa_times",-1);
		kuangshi=new("/d/kunlun/obj/kuangshi");
		kuangshi->move(me);
		me->add("jingli",-70);
	}
	else
	{
		tell_object(me,HIR"你突然觉得气力不济，怎样也无法将那块矿石挖出。\n"NOR);
		me->add("jingli",-70);

	}

	me->delete_temp("pending/job_busy");
	return 1;

}

int valid_leave(object me, string dir)
{
        object ob;

        if (dir == "northeast" && me->query_temp("job_busy") )
               return notify_fail("你正忙着挖矿呢！\n");

        return ::valid_leave(me, dir);
}
