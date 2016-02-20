//Cracked by Roath
// 11/5/96. Ryu 
inherit F_UNIQUE;
inherit ITEM;
#include <ansi.h>
int do_put(string);
int do_squeeze(string);
int do_coat(string);
void setup()
{}


void create()
{
        set_name(BLU "蓝玉钵" NOR, ({"lanyu bo", "yao bo", "bo"}));
        set_weight(15000);
        set_max_encumbrance(1000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "只");
                set("long", "一只蓝玉制药钵，玉质间泛着阴森森的蓝光。\n");
                set("value", 7000000);
        }
	::create();
}
int is_container() { return 1; }
void init()
{
   add_action("do_put","put");
   add_action("do_squeeze", "squeeze");
   add_action("do_squeeze", "ji");
   add_action("do_coat", "coat");
   add_action("do_coat", "tu");
}
int do_put(string arg)
{
	object ob, obj, me = this_player();
	string item, target;
        int amount;
        int check, wait_time = 0;
	remove_call_out("open_up");
        if( !arg || sscanf(arg, "%s in %s", item, target) != 2 )
                return notify_fail("你要将什么东西放进哪里？\n");

        if( item == "all" ) {
                write("还是一样一样来吧。\n");
                return 1;
        }

        sscanf(item, "%d %s", amount, item);

        if( !objectp(obj = present(item, me)) )
                return notify_fail("你要给谁什么东西？\n");
	if( obj->query("no_drop") ) {
                write("这样东西不能离开你。\n");
                return 1;
        }
	if( obj->name()=="毒蛇胆"){ 
                message_vision( sprintf(HIY "$N将一%s%s放进%s。\n" NOR,
                        obj->query("unit"), obj->name(),
                        this_object()->name()),me );
		call_out("destroy_it", 1, obj);
		if (me->query_skill("poison", 1) >= 120){
		this_object()->set("san", 1);
		}
		return 1;
	}
	if( obj->query("id")=="shachong ke" ){
                message_vision( sprintf(HIY "$N将一%s%s放进%s。\n" NOR,
                        obj->query("unit"), obj->name(),
                        this_object()->name()),me );
                call_out("destroy_it", 1, obj);
                if (me->query_skill("poison", 1) >= 120){
                if (this_object()->query("san") == 1)
                this_object()->set("san", 2);
                }
                return 1;
        }
	if( obj->query("id")=="xiezi ke" ){
                message_vision( sprintf(HIY "$N将一%s%s放进%s。\n" NOR,
                        obj->query("unit"), obj->name(),
                        this_object()->name()),me );
                call_out("destroy_it", 1, obj);
                if (me->query_skill("poison", 1) >= 120){
                if (this_object()->query("san") == 2)
                this_object()->set("san", 3);
                }
                return 1;
        }
	if( obj->name()=="毒蛛丝" ){
                message_vision( sprintf(HIY "$N将一%s%s放进%s。\n" NOR,
                        obj->query("unit"), obj->name(),
                        this_object()->name()),me );
		call_out("destroy_it", 1, obj);
		if (me->query_skill("poison", 1) >= 120){
		if (this_object()->query("san") == 3)
                this_object()->set("san", 4);
		}
		return 1;
        }
	if( obj->name()=="蜈蚣壳" ){
                message_vision( sprintf(HIY "$N将一%s%s放进%s。\n" NOR,
                        obj->query("unit"), obj->name(),
                        this_object()->name()),me );
		call_out("destroy_it", 1, obj);
                if (this_object()->query("san") == 4 
		&& me->query_skill("poison", 1) >= 120){
	if ( interactive(me)) {
		remove_call_out("open_up");
           call_out("open_up", random(10)+10, this_object());
		}
	}
	return 1;
	}
	else if (present(item, me) != this_object()){
                write(obj->name()+"对蓝玉钵而来说太重了。\n");
                return 1;
        }
}
int open_up()
{
	object ob, obj = this_object();
	ob=new("/d/xingxiu/obj/sanxiao");
        ob->move(obj);
	obj->set("san", 0);
	return 1;
}
int do_squeeze(string arg)
{
	string me, what;
        object ob, obj;

        if( !arg
        ||      sscanf(arg, "%s to %s", what, me)!=2
        ||      !id(me) )
                return notify_fail("命令格式: squeeze <物品> to <物品>。\n");

        ob = present(what, this_player());
        if( !ob )
                return notify_fail("你身上没有" + what + "这样东西。\n");
	if( ob->query("name") != "蝮蛇")
		return notify_fail("你想从这样东西里挤出什么？\n");
	obj=new("/d/xingxiu/obj/fushe-xian");
	obj->move(this_object());
	add("venom", 1);
	message_vision(GRN"$N掐住蝮蛇的上颚，挤出一些蛇涎，用蓝玉钵接住。\n"NOR, this_player());
	if (query("venom")>random(7)){
	message_vision("蝮蛇被$N掐死了。\n", this_player());
	ob->die();
	}
	return 1;
}
int do_coat(string arg)
{
        object ob, obj;
	function f;

        if (!arg || !(ob = present(arg, this_player())))
                return notify_fail("你要干什么？\n");

	if (!present("venom", this_object()))
		return notify_fail("你要干什么？\n");

        if (! ob->query("weapon_prop/damage"))
                return notify_fail("蝮蛇涎可不能瞎涂。\n");

	if ( ob->query("poison_applied") > 0)
		return notify_fail("这样东西上已经喂有毒药了。\n");

	if (this_player()->query_skill("poison", 1) < 100)
		return notify_fail("你还没有掌握在武器上喂毒的技能。\n");

	message_vision(RED"$N小心翼翼地把一些蝮蛇涎涂在" +ob->query("name")+"上。\n"NOR, this_player());
	ob->set("poison_applied", this_player()->query_skill("poison", 1)/3);
	ob->set("no_sell");
	ob->set("long", ob->query("long") + BLU"上面似乎喂有剧毒。\n"NOR);
	obj = present("venom", this_object());	
	call_out("destroy_it", 1, obj);
	return 1;
}
void destroy_it(object obj)
{
        destruct(obj);
        return;
}

