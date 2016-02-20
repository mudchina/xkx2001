//Cracked by Roath
// npc: /d/xingxiu/npc/bayi.c
// Jay 3/25/96

inherit NPC;
void create()
{
        set_name("胡老爷", ({ "hu laoye", "hu", "bayi"}));
	set("title","巴依");
        set("gender", "男性");
        set("age", 55);
	set("long","胡老爷是本地的一个巴依，为富不仁。\n");
        set_skill("unarmed", 30);
        set_skill("dodge", 30);
        set_skill("parry", 30);
        set_temp("apply/attack", 40);
        set_temp("apply/defense", 40);
        set_temp("apply/damage", 10);
        set("attitude","heroism");
        set("inquiry", ([
           "金子" : "我照着阿凡提的办法种了好多金子，可什么也没长出来，连种子也没了。",
	   "铁锅" : "阿凡提借我大铁锅，只还了一个小的给我。",	
	   "锅" : "阿凡提借我大铁锅，只还了一个小的给我。",
           "阿凡提" : "我把他关到我的客厅里了。",
        ]) );

        set("combat_exp", 25000);
        set("shen_type", -1);
        setup();
        set("chat_chance", 10);
        set("chat_msg", ({
           "胡老爷嘟嘟囔囔：沙子一筐子金子一屋子，金子一筐子沙子一屋子。\n",
           "胡老爷冲着你大喊：你站在我的树荫里得付我钱!\n",
           "胡老爷叹了口气：阿凡提借我大铁锅，只还了一个小的给我。\n",
        }) );
        carry_object(__DIR__"obj/wcloth")->wear();
}

int accept_object(object who, object ob)
{
        object wage;

        if (who->query_temp("biao/bayi") && ob->name()=="红镖") {
                who->delete_temp("biao/bayi");
		who->delete_temp("apply/short");
                message_vision( "胡老爷冲着$N大骂：你怎么这么迟才将这镖运到？得扣你工钱才行！\n", who);
                wage = new("/clone/money/silver");
                wage->set_amount(4);
                wage->move(who);
                message_vision("胡老爷不情不愿地给$N四两白银作为走镖的酬劳。\n", who);
                remove_call_out("destroy_it");
                call_out("destroy_it", 1, ob);
                return 1;
        }

	return 0;
}

void destroy_it(object obj)
{
        destruct(obj);
}
