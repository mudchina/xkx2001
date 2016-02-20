//Cracked by Roath
// si-cloth.c 丝绢
//

#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
        set_name("丝绢", ({ "si juan","si" }) );
        set_weight(2000);
	
        if( clonep() )
                set_default_object(__FILE__);
        else {
	        set("unit", "件");
		set("long", "一块洁白的丝绢，可以用来包(bao)东西。\n");
                set("material", "cloth");
                set("value", 500);
                set("armor_prop/armor", 5);
        }
        setup();
}

void init()
{
	add_action("do_bao","bao");
}


int is_special() {return 1;}

int do_bao(string arg)
{	string what;
	object ob,temp,obj=this_object();

        if(!arg || sscanf(arg,"%s",what)!=1)
                return notify_fail("你要往什么东西上包丝绢？\n");

        if (!arg || !(ob = present(arg, this_player())))
                return notify_fail("你身上没有" + what + "！\n");

        if (! ob->query("armor_prop/armor"))
                return notify_fail("这么辛苦得来的丝绢可不能瞎包。\n");

	if (ob->query("id")=="si juan")
		return notify_fail("它已经包上丝绢了！\n");

	if ( ob->is_unique() ) // added by sdong so that unique stuff cannot be duplicated
		return notify_fail("它太大了，包不住！\n");


        message_vision(GRN"$N小心翼翼地把丝绢包在" +ob->query("name")+"上。\n"NOR, this_player());
	obj->weight(ob->weight());
	obj->set("name","丝绢包裹的"+ob->query("name"));
	obj->set("long",ob->query("long")+"现在外面包裹着一层丝绢。\n");
	obj->set("armor_prop/armor",ob->query("armor_prop/armor"));
//	obj->set("no_sell");
	obj->set("value",0);
	
	if (temp=this_player()->query_temp("armor/cloth") && temp==ob)
		{destruct(ob);
		 obj->wear();
		}		
	destruct(ob);
	return 1;
}
