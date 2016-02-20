//Cracked by Roath
// mianju.c

#include <ansi.h>

inherit F_UNIQUE;
inherit ITEM;

void create()
{
        set_name(YEL"人皮面具"NOR, ({ "mian ju", "mask" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "个");
                set("long", "这似乎是一个由人皮制成的面具。\n");
                set("no_drop", "这样东西不能离开你。\n");
                set("no_sell", 1);
                set("no_drop", 1);
                set("no_steal", 1);
                set("no_give", 1);
                set("usage", 3);
        }
        setup();
        ::create();
}

void init()
{
        add_action("do_pretend", "pretend");
        add_action("do_pretend", "ban");
}

int do_pretend(string arg)
{
	object who, me=this_player();
	if (!arg) return notify_fail("你想假装谁？\n");
	if ((arg == "none" || arg == "cancel") && me->query_temp("pretented")) {
		this_player()->delete_temp("apply/name");
		this_player()->delete_temp("apply/short");
		this_player()->delete_temp("apply/long");
		message_vision(HIB"$N伸手往脸上一抹，现出原来相貌。\n"NOR, this_player());
		me->delete_temp("pretented");
		set("no_get", 0);
	}
	if (arg == "biao shi" || arg == "robber" || arg == "tangzi shou" || arg == "biaoshi" || arg == "shou" || arg == "zei")
		return notify_fail("你不可以假扮这个人! \n");
	
	if(!objectp(who = present(arg, environment(this_player()))) || !living(who) || (string)who->query("race")!="人类")
		return notify_fail("你想假装谁？\n");
	
	if(wizardp(who)){
		command("say 大胆！敢假扮WIZ！");
		this_player()->unconcious();
		this_player()->announce();
		return 1;
	}

    	if((me->query_temp("can_ban")!=1 || query("usage")<=0) && me->query("id")!="shu shi"){
    		message_vision("$N从身上那出一张软皮，使劲往脸上按去。\n", this_player());
                message_vision(HIR"只听见咝地一声，软皮被$N撕的粉碎。\n"NOR, this_player());
                this_player()->delete_temp("apply/name");
                this_player()->delete_temp("apply/short");
                this_player()->delete_temp("apply/long");
                set("no_get", 1);
                destruct(this_object());
                return 1;
        }
        
        if(me->query("id")!="shu shi")
        	add("usage", -1);
        write("你开始假装" + who->name() + ".\n");
        this_player()->set_temp("pretented",1);
        this_player()->set_temp("apply/name", ({who->name()}));
        this_player()->set_temp("apply/short", ({who->short()}));
        this_player()->set_temp("apply/long", ({who->long()}));
        return 1;
}
