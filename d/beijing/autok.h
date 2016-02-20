//Cracked by Roath
#ifndef _AUTO_K_H_
#define _AUTO_K_H_

int auto_kill(object player)
{
    object me = this_object();

    if (interactive(player) && 
	player->query_condition("bjkiller")) {
	remove_call_out("kill_ob");
	call_out("kill_ob", 1, this_player());
	if (me->query("follow_killer"))
	    command("follow "+player->query("id"));
 	return 1;
    }
    return 0;
}

int accept_fight(object player)
{
	object me=this_object();

        command("say 大爷我正想找人杀呐，今天算你倒霉。\n");
        player->apply_condition("bjkiller", 100);
        me->kill_ob(player);
        return 1;
}

int accept_kill(object player)
{
	object me=this_object();
        command("say 大爷我正想找人杀呐，今天算你倒霉。\n");
        player->apply_condition("bjkiller", 100);
        me->kill_ob(player);
        return 1;
}

void set_shiwei_status(int lvl)
{
	int exp;
	object me=this_object();

	me->set("gender", "男性");
	me->set("attitude", "heroism");
	me->set("shen_type",0);
	me->set("score", 100);
	me->set("str", 30);
	me->set("int", 30);
	me->set("con", 30);
	me->set("dex", 30);

	me->set("max_qi", lvl*10);
	me->set("eff_qi", lvl*10);
	me->set("qi", lvl*10);

	me->set("max_jing", lvl*10);
	me->set("eff_jing", lvl*10);
	me->set("jing", lvl*10);

	me->set("jingli", lvl*20);
	me->set("max_jingli", lvl*20);

	me->set("neili", lvl*20);
	me->set("max_neili", lvl*20);

	me->set("jiali", lvl);

	exp = lvl*lvl/10*lvl;

	me->set("combat_exp", exp+random(exp/4));

	me->set_skill("force", lvl);
	me->set_skill("dodge", lvl);
	me->set_skill("cuff", lvl);
	me->set_skill("strike",lvl);
	me->set_skill("parry", lvl);
	me->set_skill("blade",lvl);
	me->set_skill("sword",lvl);
	

        me->set_skill("liuxing-bu", lvl);
        me->set_skill("wuyu-zhangfa", lvl);
        me->set_skill("wuxing-quan", lvl);
        me->set_skill("wugou-jianfa", lvl);
        me->set_skill("wuhu-duanmen", lvl);
 
        me->map_skill("force", "taixuan-gong");
        me->map_skill("dodge", "liuxing-bu");
        me->map_skill("cuff", "wuxing-quan");
        me->map_skill("strike", "wuyu-zhangfa");
        me->map_skill("parry", "wuhu-duanmen");
        me->map_skill("blade", "wuhu-duanmen");
        me->map_skill("sword", "wugou-jianfa");
 
        me->prepare_skill("cuff", "wuxing-quan");

	me->carry_object("/d/beijing/obj/shiweicloth")->wear();
	if (random(2) == 1)
	    me->carry_object("/clone/weapon/gangjian")->wield();
	else
	    me->carry_object("/clone/weapon/gangdao")->wield();
}

#endif

