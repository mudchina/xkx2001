//Cracked by Roath
#ifndef __KILLME_H__
#define __KILLME_H__

int accept_fight(object player)
{
    command("say 京城里怎么好随便动粗？\n");
    return 0;
}

int accept_kill(object player)
{
    object me=this_object();
    command("say 你我无怨无仇，既然如此相逼，我就跟你拼了。\n");
    player->apply_condition("bjkiller", 100);
    me->kill_ob(player);
    return 1;
}

void set_vendor_status(int lvl)
{
    object me = this_object();

    me->set("str", 20);
    me->set("dex", 20);
    me->set("con", 20);
    me->set("int", 20);
    me->set("attitude", "friendly");
    me->set("combat_exp", lvl*1000);

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

    me->set_skill("dodge", lvl);
    me->set_skill("cuff", lvl);
    me->set_skill("strike",lvl);
    me->set_skill("parry", lvl);
    me->set_skill("blade",lvl);
    me->set_skill("sword",lvl);
 
/*
    set_skill("liuxing-bu", lvl);
    set_skill("wuyu-zhangfa", lvl);
    set_skill("wuxing-quan", lvl);
    set_skill("wugou-jianfa", lvl);
    set_skill("wuhu-duanmen", lvl);
 
    map_skill("force", "taixuan-gong");
    map_skill("dodge", "liuxing-bu");
    map_skill("cuff", "wuxing-quan");
    map_skill("strike", "wuyu-zhangfa");
    map_skill("parry", "wuhu-duanmen");
    map_skill("blade", "wuhu-duanmen");
    map_skill("sword", "wugou-jianfa");
 
    me->prepare_skill("cuff", "wuxing-quan");
*/
}
#endif
