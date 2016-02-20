//Cracked by Roath
// jinjing-shou 碧水金睛兽

#include <ansi.h>

inherit NPC_TRAINEE;

void create()
{
	set_name("碧水金睛兽", ({ "jinjing shou", "shou", "beast" }) );
	set_weight(6000000);
	set("race", "野兽");
	set("age", 1000);
	set("long", "它是此处的守潭神兽，据传是当年赤松子的坐骑，力大无穷，乃是千年一现的洪荒异兽。\n" +
			"尤其是它头上那一枝金光闪闪的兽角，据传割下制炼后能让佩戴者寒毒不侵，洪波辟易。\n");
	set("msg_fail",   "$n冲着$N怒吼一声，随时准备猛扑过来");
	set("msg_succ",   "$n鼻孔中喷着粗气，脑袋不停地摇晃着奔来奔去");
	set("msg_trained","$n低啸一声，伸开前爪在$N的面前伏了下来");
	set("auto_follow",1);
	set("attitude", "heroism");

	set("wildness", 50);
	
	set("combat_exp", 100000);
	set("shen_type", 0);
	set("env/wimpy", 50);

	set("str", 100);
	set("int",  20);
	set("con", 100);
	set("dex",  50);

	set("max_jing", 1000);
	set("max_qi",   2000);
	set("max_neili",1000);
	set("neili",    1000);
	set("jiali",     100);

	set("chat_chance", 5);
	set("chat_msg", ({
		(: this_object(), "random_move" :),
	}) );
	
	set("unicorn", 1);

	set_temp("apply/attack", 100);
	set_temp("apply/damage", 100);
	set_temp("apply/dodge",  100);
	set_temp("apply/armor",  100);

	setup();
}

void init()
{
	::init();
	if( this_object()->query_lord() != this_player() ) {
		this_object()->kill_ob(this_player());
		this_object()->set_leader(this_player());
	}
	else {
		add_action("do_qie", "qie");
		add_action("do_qie", "ge");
		add_action("do_ride", "ride");
		add_action("do_ride", "qi");
		add_action("do_unride", "unride");
		add_action("do_unride", "xia");
	}
}

int accept_object(object ob, object obj)
{
	object me = this_object();

	if( obj->query("id") == "gold" ) {
		if(me->is_fighting(ob)) me->remove_all_enemy();
		message_vision("\n$N一口把黄金吞了下去，伸出舌头满意地舔了舔嘴唇。\n\n", me);
		me->add_temp("gold_feed", 1);
	}

	if( me->query_temp("gold_feed") >= 10 ) {
		if(me->query("auto_follow")) me->set_leader(ob);
		message_vision(me->query("msg_trained") + "。\n", ob, me);
		me->set_lord(ob);
		me->delete("chat_msg");

		add_action("do_qie", "qie");
		add_action("do_qie", "ge");
		add_action("do_ride", "ride");
		add_action("do_ride", "qi");
		add_action("do_unride", "unride");
		add_action("do_unride", "xia");
	}

	if( me->query_temp("gold_feed") >= 1 ) return 1;
	else return 0;
}

int do_qie(string arg)
{
	object ob, *inv;
	string tool;
	int i;

	if( !arg || (arg != "shou jiao" && arg != "shou" && arg != "jiao") ) 
		return notify_fail("你要切割什么？\n");	

	if( !this_object()->query("unicorn") )
		return notify_fail("兽角已经被人取走了！\n");	

//	if( this_object()->query("qi")*100 / this_object()->query("max_qi") < 10 
//	&&  this_object()->query("qi")*100 / this_object()->query("max_qi") >  5 )
//		return notify_fail("兽角要趁碧水金睛兽阳气全消，阴气渐生的时候方能下手切除！\n");	

	inv = all_inventory(this_player());
        
	for(i=0; i<sizeof(inv); i++) {
          if( inv[i]->query("weapon_prop") 
	    &&  inv[i]->query("equipped") 
	    && (inv[i]->query("skill_type") == "blade"
	    ||  inv[i]->query("skill_type") == "sword") )
		tool = 	inv[i]->query("name");
	}	

	if( !stringp(tool) ) return notify_fail("你没有趁手的工具来切割兽角！\n");	

	if( this_object()->query_lord() != this_player() ) {
		message_vision(HIR "\n一看$N扬起了" + tool + "，碧水金睛兽惊天动地地巨吼一声，扑了上来！\n" NOR,
					this_player());
		this_object()->kill_ob(this_player());
		this_object()->set_leader(this_player());
	}

	this_object()->set("unicorn", 0);

	ob = new("/d/shaolin/obj/shou-jiao");
	ob->move(this_player());
	message_vision("\n$N用" + tool + "把碧水金睛兽那只金光闪闪的兽角切了下来，放在怀里。\n", 
				this_player());

	return 1;
}

int do_ride(string arg)
{
	object me, ob;
	me = this_object();
	ob = this_player();

	if ( !arg || (arg != "jinjing shou" && arg != "shou" && arg != "beast")) 
		return notify_fail("你要骑什么？\n");

	if( me->query_lord() == ob ) 
	{
		if( !ob->query_temp("riding") )
		{
			if( !me->query_temp("rider") ) 
			{
				ob->set_temp("riding", me->name());
				me->set_temp("rider",  ob->name());
				me->set_leader(ob);

				message_vision("\n$N一纵身，威风凛凛地骑在了" + me->name() +"身上。\n", ob);
				return 1;
			}
			else    return notify_fail( me->query_temp("rider") + "已经骑在它身上上了！\n");
		}
		else	return notify_fail("你已经骑在" + ob->query_temp("riding") + "上了！\n");
	}
	else return notify_fail("你不是它的主人！\n");

	return 0;
}

int do_unride()
{
	object me, ob;
	me = this_object();
	ob = this_player();

	if( ob->query_temp("riding") == me->name() && me->query_temp("rider") == ob->name() ) 
	{
		ob->delete_temp("riding");
		me->delete_temp("rider" );
		message_vision("\n$N一纵身，从" + me->name() +"身上跃了下来。\n", ob);
		return 1;
	}
	else return notify_fail("你还没骑它呢！\n");

	return 0;
}

void die()
{
	message_vision("\n紧接着碧水金睛兽化成一道金光，突地钻进泥土里消失了。\n", 
			this_object());
	destruct(this_object());
}

