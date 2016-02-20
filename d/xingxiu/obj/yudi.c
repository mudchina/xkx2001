//Cracked by Roath
// Ryu 4/17/97

inherit ITEM;
inherit F_AUTOLOAD;
#include <ansi.h>;
int is_container() { return 1; }
int do_put(string);
void create()
{
        set_name("玉笛", ({"yu di", "flute", "di"}));
        set_weight(80);
	set_max_encumbrance(10);
        if (clonep())
                set_default_object(__FILE__);
        else {
         set("long", "这玉笛短得出奇，只不来七寸来长、通体洁白，晶莹可爱。\n");
                set("unit", "支");
                set("value", 1000);
		set("no_sell", 1);
		set("fire_source", 3);
		set("no_drop", 1);
		set("no_get", 1);
		set("no_steal", 1);
        }
}
int query_autoload() { return 1; }
void init()
{
	add_action("do_blow", "blow");
	add_action("do_blow", "chui");
	add_action("do_put", "put");
}
int do_blow(string arg)
{
	object ob, me=this_player();

	if (!id(arg)) return 0;
	
	if (me->is_busy())
        return notify_fail("你前一个动作还没有做完。\n");

	message_vision("$N把玉笛放到口边，轻轻一吹，只听一阵极尖极细的哨子声远远传了出去。\n", me);

	if( !environment(me)->query("no_fight") 
	&& query("fire_source") > 0 && me->query_skill("poison", 1) > 99){	

	message_vision(HIR"随着哨子声，玉笛里突然飞出蓝印印的一点火星，火星陡地熄灭，随即大亮，蓬的一声响，腾向半空，升起有丈许，这才缓缓降落。\n"NOR, me);

	add("fire_source", -1);
	ob=new("/d/xingxiu/obj/flute_fire");
	ob->move(environment(me));
	}
	return 1;
}
int do_put(string arg)
{
        object ob, obj, me = this_player();
        string item, target;
        int amount;

        if( !arg || sscanf(arg, "%s in %s", item, target) != 2 )
                return notify_fail("你要将什么东西放进哪里？\n");
	
	if( !objectp(obj = present(item, me)) )
                return notify_fail("你要给谁什么东西？\n");

	if (!id(target)) return 0;

	if( item == "all" ) {
                write("还是一样一样来吧。\n");
                return 1;
        }
	if( obj->query("id") != "liuhuang"){
                write(obj->query("name")+"对玉笛而言太重了。\n");
                return 1;
        }
                message_vision( sprintf(HIY "$N将一%s%s放进%s。\n" NOR,
                        obj->query("unit"), obj->name(),
                        this_object()->name()),me );
                destruct(obj);
		add("fire_source", 1);
	return 1;
}
