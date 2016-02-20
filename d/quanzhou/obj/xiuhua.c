//Cracked by Roath
#include <ansi.h>
#include <weapon.h>
inherit SWORD;

void setup()
{}

void init()
{
        add_action("do_make", "make");
}

void create()
{
        set_name("绣花针", ({ "xiuhua zhen", "zhen", "needle" }));
        set_weight(5);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "根");
                set("long", "这是一根精钢细磨的绣花针，是绣花用的绝佳工具。\n");
                set("value", 100);
                set("material", "steel");
                set("wield_msg", "$N用拇指和食指从鬓间拈出一根$n。\n");
                set("unwield_msg", "$N将手中的$n插回鬓间。\n");
        }
        init_sword(10);
        setup();
}
int do_make(string arg)
{
	object  ob, *obj, me = this_player();
	int i;
	if( !arg || arg!="bilin zhen" )
                return notify_fail("你要做什么？\n");
	if( me->query_skill("poison", 1) < 120)
		return notify_fail("你的毒技火侯不够，不能制作炼心弹。\n");
	if(! present("wugong ke", me) && !present("xiezi ke", me)
	&& !present("shedan", me) && !present("du zhusi", me)
	&& !present("shachong ke", me))
		return notify_fail("你没有足够的原料！\n");
        message_vision(CYN"$N小心翼翼地把一根绣花针插进毒药捏碎，注进内力，搓成了一篷碧磷针。\n"NOR, me );
		ob = new("/d/xingxiu/obj/blzhen.c");
	        ob->move(me);
		me->add("jingli", -5);
	obj = all_inventory(me);
        for(i=sizeof(obj)-1; i>=0; i--) {
        if( obj[i]->query("name") == "蜈蚣壳" || obj[i]->query("id") == "xiezi ke"
	|| obj[i]->query("id") == "shedan" || obj[i]->query("id") == "du zhusi"
	|| obj[i]->query("id") == "shachong ke")
	destruct(obj[i]);
        }	
		destruct(this_object());
        return 1;
}
