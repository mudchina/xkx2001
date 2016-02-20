//Cracked by Roath
// huoji. 伙计

inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("伙计", ({ "huo ji" }));
	set("str", 20);
	set("gender", "男性");
	set("age", 18);
	set_max_encumbrance(100000000);
	set("long", "他是这儿的伙计，正在店里忙里忙外。\n");
	set("combat_exp", 250);
	set("attitude", "friendly");
	set("vendor_goods", ({
		"/d/qilian/obj/goupi",
		"/d/qilian/obj/pi-beixin",
		DRUG_D("gaoyao"),
	}));

	setup();
}

void init()
{
	::init();
        add_action("do_list", "list");
        add_action("do_buy", "buy");
//	add_action("do_make", "make");
}

int accept_object(object who,object ob)
{
        int a;
	object money, cloth;
	string *beast_list = ({
	"梅花鹿",
	"野狗",
	"老虎",
	"猴子",
	"小猴",
	"母狼",
	"绵羊"
	});
	a = ob->query("combat_exp");
 if ( member_array(ob->query("victim_name"), beast_list) != -1 )

 	{
	call_out("destroy", 1, ob);
	command("say 这头"+ob->query("victim_name")+"值不了几个大钱。");	
	money=new("/clone/money/silver");
	money->set_amount((int)a/100);
	if ((int)a/100 > 300)
	money->set_amount(300);
	money->move(who);
	say("伙计递给你几锭银子，说道：请收好。\n");
	return 1;	
	}
	if( ob->value() >= 1000 )
	{
	who->set_temp("cloth", 2);
	return 1;
	}
}
void destroy(object ob)
{
	if (ob);
        destruct(ob);
        return;
}

int do_make(string arg)
{
        object me, obj, ob;
        string item; 
        int amount;
	string *beast_list = ({
        "梅花鹿",
        "野狗",
        "老虎",
        "猴子",
        "小猴",
        "母狼",
        "绵羊"
        });

	
        me = this_player();
        ob = new("/d/qilian/obj/leather.c");

        if( !arg || sscanf(arg, "%s into cloth", item) != 1 )
                return notify_fail("你要将什么东西做成衣服？\n");
	if (me->query_temp("cloth") < 1)
		return notify_fail("你没付钱，人家不会给你做衣服。\n");         
        if( item == "all" ) {
                write("还是一样一样来吧。\n");
                return 1;
        }
                                                                
        sscanf(item, "%d %s", amount, item);
        
        if( !objectp(obj = present(item, me)) )
                return notify_fail("你要给谁什么东西？\n");

        if( obj->query("id") != "corpse"){
                write("你不能将这样东西做成衣服。\n");
                return 1;
        }
        if ( member_array(ob->query("victim_name"), beast_list) != -1  )
	{
        message_vision("$N把"+obj->query("name")+"交给了店里的伙记。\n",
me);

        message_vision("$N从店伙记中接过了一件皮衣！\n",
me);
        ob->set("name", obj->query("victim_name")+"皮大衣");
        ob->set("armor_prop/armor",(int)obj->query("combat_exp")/1000);
	ob->move(me);
        destruct(obj);
	me->delete_temp("cloth");
	        
        return 1;
}
}

