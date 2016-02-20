//Cracked by Roath
// huolu.c 火炉
// by zhangchi

#include <ansi.h>
inherit ITEM;

int check_busy(object me);

// #define OBJ_PATH "/u/zhangchi/mingjiao/upload"
#define OBJ_PATH "/d/kunlun/obj"

void create()
{
        set_name(HIR"火炉"NOR, ({ "huo lu", "lu" }) );
        set_weight(9000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "这是座大火炉，里面雄火燃烧，可以用来炼铁。\n");
                set("unit", "座");
		set("no_get", 1);
        }
}

void init()
{
	add_action("do_tou","tou");
	add_action("do_tou","put");
}

int do_tou(string arg)
{
        object me, ob,kuangshi;
        string item, target; 

        me = this_player();
        ob = this_object();
        
        if( me->is_busy() || me->query_temp("pending/job_busy") )
                return notify_fail("你正忙着呢。\n");

        if (!arg || sscanf(arg, "%s in %s", item, target) != 2 )
            return notify_fail("你要将什么东西放进哪里？\n");

	if (item != "矿石" || target != "火炉")
		return notify_fail("你要将什么东西放进哪里？\n");

	if ( !kuangshi=present("wujin kuangshi",me) )
		return notify_fail("你身上并没有矿石。\n");

	if (query_temp("in_use"))
		return notify_fail("这个火炉已经有人在用了！\n");

	message_vision("$N把一"+kuangshi->query("unit")+kuangshi->query("name")+"投进火炉。\n",me);
	destruct(kuangshi);
	message_vision(HIC"$N拉动风箱，火焰由红慢慢变青，冲起一丈多高！\n"NOR,me);
	
	set_temp("in_use",1);
	me->set_temp("pending/job_busy",1);
	me->set_temp("refining",1);

	remove_call_out("burning");
	call_out("burning",10+random(5),me);
	me->start_busy((: check_busy :));

	return 1;
}

void burning(object me)
{
	write(HIW"矿石已经被烧的通红，看来可以开始锤打了\n"NOR);
	add_action("do_datie","da");
	add_action("do_datie","refine");
	me->delete_temp("pending/job_busy");
}

int do_datie(string arg)
{	
	object me=this_player();

        if( me->is_busy() || me->query_temp("pending/job_busy") )
                return notify_fail("你正忙着呢。\n");

	if (arg != "tie" && arg != "铁")
		return notify_fail("你要打什么？\n");

	if (!present("tie chui",me))
		return notify_fail("你没有铁锤，用什么打？\n");

	if (me->query("neili") < 50 || me->query("jingli") < 50)
		return notify_fail(RED"你已经精疲力竭了！\n"NOR);

	message_vision("$N挥动大铁锤，朝着烧红的铁矿石狠狠地打了下去！\n",me);
	me->add("neili",-30);
	me->set_temp("pending/job_busy",1);

// let player improve their force level //add later
	remove_call_out("job_done");
	call_out("job_done",5+random(10),me);
	me->start_busy( (: check_busy :) );

	return 1;
}

void job_done(object me)
{
	object jingtie;

	if (random(me->query_str()) > 20 && random(10) > 5 )
	{
		message_vision(HIC"经过千锤百炼，精铁终于炼出来了！$N浑身汗如雨下，几乎累得喘不过气来。\n"NOR,me);
		jingtie=new(OBJ_PATH"/jingtie");
		jingtie->move(me);
		remove_action("do_datie","da");
		remove_action("do_datie","refine");
		delete_temp("in_use");
		me->delete_temp("refining");
	}
	else
	{
		tell_object(me,HIR"你擦了擦脸上的汗，看了看矿石，看来还得再打！\n"NOR);
	}
	me->delete_temp("pending/job_busy");
}

int check_busy(object me)
{
	if (me->query_temp("pending/job_busy"))
		return 1;
	return 0;
}

