//Cracked by Roath
// Jay 8/9/96
#include <ansi.h>

inherit NPC;

void create()
{
        set_name("任我行",({ "ren woxing","ren" }) );
        set("gender", "男性");
        set("age", 55);
	set("long",
		"他花白长须垂在胸前，胡子满脸，看不清他的本来面容。\n");
      //  set("nickname","");
        set("title","日月神教前教主");
        set("combat_exp", 180000);
        set("shen_type", 0);
        set("attitude", "peaceful");
        set_skill("unarmed", 180);

	set_skill("force",180);
        set_skill("parry", 180);
        set_skill("dodge", 180);
	set_skill("huagong-dafa",180);
	set_skill("sword",150);
	map_skill("force","huagong-dafa");

	set("max_neili",5000);
	set("neili",5000);
	set("jiali",100);
       setup();
        carry_object("/clone/misc/cloth")->wear();
	carry_object("/clone/weapon/zhujian")->wield();
}

int accept_fight()
{
        object me, ob;

        me = this_object();
        ob = this_player();

        if(!ob->query_temp("renqiu")) {
		command("say 我十多年不动剑，剑法早已忘得干干净净了，"
			"操你奶奶的王八羔子，快给我夹着尾巴滚吧。");
		return 0;
	}
	command("say 老夫十余年不动兵刃，不知当年所学的剑法还记不记得。");
	command("say 就跟你比两招吧。");
	remove_call_out("bijian");
	call_out("bijian",1,me,ob);
	return 1;
}

void bijian(object ren, object player)
{
	object *ob, *inv;
	object liaokao;
	int i;

        message_vision(
                HIY "\n忽然间，$N深深地吸一囗气，石破天惊般一声狂啸。\n" NOR,
                 ren);

        ob = all_inventory(environment(ren));
        for(i=0; i<sizeof(ob); i++) {
                if( !living(ob[i]) || ob[i]==ren || ob[i]==player ) continue;
        tell_object(ob[i], "你耳中嗡的一声，耳骨都似被他震破了，脑中一阵晕眩。\n");

		ob[i]->unconcious();
	}


        tell_object(player, "你耳中嗡的一声，耳骨都似被他震破了，脑中一阵晕眩。\n");

	ren->remove_all_enemy();
	player->remove_all_enemy();
	liaokao=new(__DIR__"obj/liaokao");

	inv = all_inventory(player);
        for(i=0; i<sizeof(inv); i++)
            if( inv[i]->query("weapon_prop/damage"))
		destruct(inv[i]);

	player->set("startroom","/d/jiaxing/dilao");

	liaokao->move(player);
	player->move("/d/jiaxing/dilao");
//	call_out("zhenyun",1,player);
//        player->unconcious();
//        message_vision("等你清醒过来，任我行和"+player->name()+"已无影无综了。\n",
//		ren);
	destruct(ren);
	return;
}

//void zhenyun(object ob)
//{
//	ob->unconcious();
//}

int accept_object(object me, object obj)
{
        if ((string)obj->query("name")=="铁球") {
        message("vision",me->name()+"给任我行一只铁球。\n",environment(me),
            ({me}));
	write("你看到任我行转过身去看了几眼铁球，然後转回身来。\n");
	command("say 多谢你来给老夫解闷。咱们就过几招吧。");
	me->set_temp("renqiu",1);
	return 1;
	}
}

