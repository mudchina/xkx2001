//Cracked by Roath
int auto_perform();

inherit NPC;
void create()
{
        set_name("葛伦布", ({ "ge lunbu", "ge", "lunbu" }));
        set_weight(3000000);
        set("long", 
"他是密宗的戒律僧，长得膀大腰，手中提着法器，身着黄袍，头戴黄帽，\n"
"满面肃杀之气。\n");
        set("gender", "男性");
        set("age", 70);
        set("attitude", "heroism");
        set("class","lama");
        set("str", 20);
        set("int", 20);
        set("con", 20);
        set("dex", 20);
        
       set("neili", 8000);
        set("eff_neili", 8000);
        set("max_neili", 8000);
        set("jingli", 5000);
        set("max_jingli", 5000);
        set("eff_jingli", 5000);
        set("jiali", 200);
        set("jiajin",30);


        set("combat_exp", 6400000);
        set("score", 5000);

        set_skill("force", 400);
        set_skill("dodge", 400);
        set_skill("parry", 400);
        set_skill("staff", 400);
   set_skill("lamaism", 400);
        set_skill("strike", 400);
        set_skill("cuff", 400);
   set_skill("hammer", 400);
   set_skill("blade", 400);
        set_skill("jingang-chu", 400);
        set_skill("longxiang-banruo", 400);
        set_skill("huoyan-dao", 400);
        set_skill("sword", 400);
        set_skill("mingwang-jian", 400);
        set_skill("necromancy", 400);
        set_skill("shenkongxing", 400);
        set_skill("xiaowuxiang", 400);
        set_skill("yujiamu-quan", 400);
        set_skill("riyue-lun", 400);
   set_skill("xue-dao", 400);

        map_skill("force", "longxiang-banruo");
        map_skill("parry", "huoyan-dao");
        map_skill("sword", "mingwang-jian");
        map_skill("staff", "jingang-chu");
        map_skill("strike", "huoyan-dao");
        map_skill("dodge", "shenkongxing");
        map_skill("cuff", "yujiamu-quan");
        map_skill("hammer", "riyue-lun");
        map_skill("blade", "xue-dao");
        prepare_skill("strike", "huoyan-dao");

   create_family("雪山派", 12, "弟子");

        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: auto_perform :),
        }) );

        setup();
        carry_object("/d/xueshan/obj/lamajiasha")->wear();
        carry_object("/clone/weapon/falun")->set_amount(5);
        carry_object("/clone/weapon/gangdao");
}

void init() 
{
   ::init();
   add_action("do_unarmed", "unarmed");
   add_action("do_hammer", "hammer");
   add_action("do_blade", "blade");
}

int auto_perform()
{
        object me = this_object();
        object target = me->select_opponent();
        object weapon = me->query_temp("weapon");

        if( !(int)me->query_temp("shielded") && ( me->query("neili") > 600 ) )
           return exert_function("shield");

        if ( objectp(weapon) && weapon->query("skill_type") == "blade")
           return perform_action("blade.shendao");

        if ( objectp(weapon) && weapon->query("skill_type") == "hammer")
           return perform_action("hammer.riyue");
 
        if ( !objectp(target)
          || !random( (int)me->query("combat_exp") * 2
                   / (int)target->query("combat_exp") + 1) ) return 0;
        return perform_action("strike.fen");
}

int do_unarmed ()
{
    command("unwield lun");
    command("unwield blade");
    return 1;
}

int do_hammer ()
{
    command("unwield blade");
    command("wield lun");
    return 1;
}
int do_blade ()
{
    command("unwield lun");
    command("wield blade");
    return 1;
}
  

