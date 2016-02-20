//Cracked by Roath
// snake_room.h 蛇谷中有蛇的房间

void python_attack(object);

#include <ansi.h>

void init()
{
	object me, here;

	string *msg = 
	({
		HIR"你走到这里，突然觉得有股腥臭的气味……\n"NOR,
		HIR"你耳边听到一阵沙沙的细碎声响，心里提高了警觉。\n"NOR,
		HIR"你一走到这地方，突然有点心神不宁……\n"NOR,
	});

	me = this_player();
	here = this_object();

	me->set("enter_shegu", 1);
	me->add("jingli", -5);

	if( time() - here->query("last_comeout") > 180 || !here->query("last_search")  )
		here->set("hide_python", 1 );


	if( random(query("hide_python") + 1 ) != 0 && me->query("race") != "蛇类") {
		remove_call_out("python_attack");
		call_out("python_attack", 6+random(3), me); 
		if( me->query("family/family_name") == "白驼山" ) 
		tell_object(me, msg[random(sizeof(msg))]);
	}
}

void python_attack(object me)
{
	object python, here;
	here = this_object();

	if ( environment(me) != here) return;

	if ( query("hide_python") < 1) return;

	add("hide_python", -1);
	python = new("/d/baituo/npc/bt_python");
	python->move(here);
	set("last_comeout", time() );

	message("vision", HIR"你忽然闻得一阵腥风，猛见一条"+python->name()+HIR"窜了出来，露出獠牙，疾向"+me->name()+"咬去！\n"NOR, environment(me), me);
	tell_object(me, HIR"你耳中忽闻嘶嘶声响，一迟疑间，蓦地腥臭迎面，一条"+python->name()+HIR"从旁窜出，猛然向你张口扑来！\n"NOR);

	python->kill_ob(me);

}
