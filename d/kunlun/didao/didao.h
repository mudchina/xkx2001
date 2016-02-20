//Cracked by Roath
// didao.h 
// zhangchi 7/00

#include <ansi.h>

int get_room(string);
int do_dig(string);

void reset()
{
        ::reset();
        set("no_clean_up", 1);
}

int get_room(string dir)
{
	object center;
	int num;

	if (!(center=find_object("/d/kunlun/mj_center.c")))
		center=load_object("/d/kunlun/mj_center.c");

	num = (int)center->query("didao/"+dir);

	return num;
}

int do_dig(string dir)
{
	object center;
	object me=this_player();

	if (me->is_busy() || me->is_fighting())
		return notify_fail("你正忙着呢！\n");

	if (!dir || dir!=query("valid_dig"))
		return notify_fail("你要往哪挖？\n");

	if (!present("tie qiao",me))
		return notify_fail("你没有趁手的工具。\n");

	if (!me->query("mingjiao/job") || me->query("mingjiao/job")!="tu_didao")
		return notify_fail("你并没有挖地道的工作。\n");

	if (me->query_temp("didao_done"))
		return notify_fail("你已经完成任务了，赶快回去复命吧！\n");

	if (query("exits/"+dir))
		return notify_fail("这段地道已经挖通了。\n");

	if (get_room(dir) >= 5)
		return notify_fail("你怎么挖也挖不动了。\n");

	if (me->query("jingli") < 50 || me->query("neili") < 30)
		return notify_fail("你已经精疲力竭了。\n");

	message_vision("$N挥动铁锹，朝前使劲地挖着。\n",me);
	me->add("neili",-30);
	me->add("jingli",-40);
	me->add_temp("wa_times",1);
	me->start_busy(3);
	if (me->query_temp("wa_times") > 10+random(10) )
	{
		tell_object(me,HIG"密道终于又向前挖进了一步！\n"NOR);
		me->delete_temp("wa_times");
		me->set_temp("didao_done",1);
		add("improve",1);
		if (query("improve") >= 5)
		{
			if (!(center=find_object("/d/kunlun/mj_center.c")))
				center=load_object("/d/kunlun/mj_center.c");
			center->add("didao/"+dir, 1);
			tell_object(me,HIG"恭喜！你又挖通了一段地道。\n"NOR);
			me->add("exp",300);
			tell_object(me,HIG"你的经验涨了300点！\n"NOR);
			load_object(__FILE__);
		}
	}

	return 1;
}