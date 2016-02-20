//Cracked by Roath
// dao-ke.c

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("哈萨克", ({ "hazakh","hasake"}) );
	set("gender", "男性");
	set("age", 30);
	set("long",
		"这是个哈萨克牧民，正悠闲自在地哼着牧歌。\n");
	set("combat_exp", 35000);
        set("shen_type", 1);
	set("attitude", "heroism");

	set_skill("unarmed", 65);
	set_skill("whip", 65);
	set_skill("parry", 65);
	set_skill("dodge", 65);
	set_skill("training", 100);

	set("chat_chance", 15);
/*	set("chat_msg", ({
			(: random_move :)
        }) );
*/
	setup();

        carry_object("/clone/weapon/mabian")->wield();
        carry_object("/d/xingxiu/obj/ha-robe")->wear();
	carry_object("/d/xingxiu/obj/pi-xue")->wear();

	add_money("silver", 10);
}
/*void init()
{
	int i;
	object *ob;
	ob  = all_inventory(environment());

        ::init();
	for(i=sizeof(ob)-1; i>=0; i--) {
        if( ob[i]->query("ridable") 
	&& ob[i]->query_lord() == this_object()) continue; 
                       command("train " + ob[i]->query("id"));
                       command("taste " + ob[i]->query("id"));
                       command("put 1 silver in " + ob[i]->query("id"));
		       command("come " + ob[i]->query("id"));
                       break;
		}
}
*/	
