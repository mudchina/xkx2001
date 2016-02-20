//Cracked by Roath
// yaolu.c 药炉
// Kane

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIC"寒玉药炉"NOR, ({ "yao lu", "lu" }) );
	set_weight(300000);
	set_max_encumbrance(5000000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "个");
                set("long",
"这是一座约摸一人多高的药炉，常年煎熬着各种毒物药材，散发出阵阵药气，\n"
"仔细一闻，药气中似乎夹杂着大量腐臭腥气，中之欲呕。\n");
		set("value", 1000);
		set("material", "wood");
		set("no_get",1);
	}
	setup();
}

int is_container() { return 1; }

void init()
{
	add_action("do_put", "put");
	add_action("do_light", "light");
}

int do_put(string arg)
{
	object me, obj;
	string item, target; 
	int amount;

	me = this_player();

	if( !arg || sscanf(arg, "%s in %s", item, target) != 2 )
                return notify_fail("你要将什么东西放进哪里？\n");
                
        if( item == "all" ) {
		write("还是一样一样来吧。\n");
		return 1;
	}
                                                                
	sscanf(item, "%d %s", amount, item);
	
	if( !objectp(obj = present(item, me)) )
		return notify_fail("你身上没有这样东西？\n");

	if( query_temp("corpse_in") )
		return notify_fail("你一次只能放一具尸体。\n");

	if( obj->query("id") != "corpse"
        && obj->query("name") != "毒蛛丝"
        && obj->query("name") != "毒蛇胆"
        && obj->query("name") != "蜈蚣壳"
        && obj->query("name") != "蝎子壳"
        && obj->query("name") != "沙虫壳" ) {
		write("你不能往药炉里放这样东西。\n");
		return 1;
	}
	if( obj->query("name") == "毒蛛丝" )
		add_temp("mark1", 1);
        if( obj->query("name") == "毒蛇胆" )
                add_temp("mark2", 1);
        if( obj->query("name") == "蜈蚣壳" )
                add_temp("mark3", 1);
        if( obj->query("name") == "蝎子壳" )
                add_temp("mark4", 1);
        if( obj->query("name") == "沙虫壳" )
                add_temp("mark5", 1);
	if( obj->query("id") == "corpse" )
		set_temp("corpse_in", 1);
}

int do_light(string arg)
{
	object  me = this_player();

	if (!present("fire", me))
		return notify_fail("你要用什么点火？\n");
/*
	if(!query_temp("mark1") || !query_temp("mark2")
	|| !query_temp("mark3") || !query_temp("mark4")
	|| !query_temp("mark5") || !query_temp("corpse_in") )
		return notify_fail("药材品种不齐！\n");
*/
        if (!id(arg))
                return notify_fail("你要点燃什么？\n");
	message_vision(HIG"$N点燃了药炉下的火堆，一团绿色火焰陡然一亮。\n"NOR,me);
	set("long", query("long") + CYN"里面冒出缕缕青烟。\n"NOR);
	remove_call_out("burning1");
	remove_call_out("burning2");
	remove_call_out("burning3");
        call_out("burning1",2, me);
	call_out("burning2",4, me);
	call_out("burning3",6, me);
	return 1;
}

void burning1(object me)
{
	object *ob, obj;
	int i;

	ob = all_inventory(this_object());
	
	for(i=0; i<sizeof(ob); i++) {
/*
	if( ob[i]->query("name") == "毒蛛丝"
        || ob[i]->query("name") == "毒蛇胆"
        || ob[i]->query("name") == "蜈蚣壳"
        || ob[i]->query("name") == "蝎子壳"
        || ob[i]->query("name") == "沙虫壳" ) {
		obj = ob[i];
		destruct(obj);
		ob = all_inventory(this_object());
		}
*/
	if( ob[i]->query("id") == "corpse")
		ob[i]->set("name","焦臭的尸体");
	}

	message_vision(MAG"$N中不断冒出浓烟，炉中各种毒物开始慢慢融化！\n"NOR,this_object());
}

void buring2(object me)
{
        object *ob, obj;
        int i,skill,extra;

        ob = all_inventory(this_object());

/*
	for(i=0; i<sizeof(ob); i++) {
	if( ob[i]->query("id") == "corpse")
		obj = ob[i];
	}
*/
	message_vision(HIB"$N中青烟渐渐消散，炉中的尸体渐渐缩小，肤色转蓝！\n",this_object());
	obj = new("/d/xingxiu/obj/dushi");
	skill = me->query_skill("poison",1);
	extra = query_temp("mark1")+query_temp("mark2")+query_temp("mark3")+query_temp("mark4")+query_temp("mark5");
	obj->set("weapon_prop/damage", skill);
	obj->set("poison_effect", extra*3);
	obj->move(this_object());
}

void buring3(object m)
{
        object *ob;
        int i, extra;

	message_vision(YEL"$N中的尸体渐渐焦黑发臭，散发出一阵阵毒烟！\n"NOR,this_object());
        extra = query_temp("mark1")+query_temp("mark2")+query_temp("mark3")+query_temp("mark4")+query_temp("mark5");
        ob = all_inventory(environment(this_object()));
	for(i=0; i<sizeof(ob); i++) 
		ob[i]->apply_condition("xx_poison", extra);

}
