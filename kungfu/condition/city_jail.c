//Cracked by Roath

#include <ansi.h>
#include <login.h>

int update_condition(object me, int duration)
{
	if (duration < 1) {
		me->move("/d/city/yamen");
		message("vision",
			HIY "只听乒地一声，你吓了一跳，定睛一看，\n"
			"原来是一个昏昏沉沉的家伙从衙门里被扔了出来！\n" NOR, environment(me), me);
		tell_object(me, HIY "只觉一阵腾云驾雾般，你昏昏沉沉地被扔出了衙门！\n" NOR);
		me->set("startroom", "/d/city/yamen");

		if(me->query_temp("armor/shoulder"))
		log_file("Jail", sprintf("%s(%s) released from city jail on %s.\n",
                	me->query("name"), me->query("id"), ctime(time())));

		return 0;
	}
	me->apply_condition("city_jail", duration - 1);
	return 1;
}
