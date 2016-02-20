//Cracked by Roath
inherit NPC;
#include <ansi.h>
int auto_perform();
int use_sword();
int use_unarmed();

void create()
{
        set_name("枯荣大师", ({ "dl_npc","kurong dashi", "kurong", "dashi" }));
        set("nickname", "天龙寺长老");
        set("long", "此人身形高大，但他的那张面容奇特之极，\n
		左边的一半脸色红润，皮光肉滑，有如婴儿，\n
		右边的一半却如枯骨，除了一张焦黄的面皮之外\n
		全无肌肉，骨头突了出来，宛然便是半个骷髅骨头。\n");
        set("gender", "男性");
        set("age", 70);
        set("attitude", "heroism");
        set("shen_type", 1);
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
	set("score", 500000);
        set_skill("force", 400);
        set_skill("dodge", 400);
        set_skill("parry", 400);
        set_skill("finger", 400);
        set_skill("kurong-changong", 400);
        set_skill("yiyang-zhi", 400);
        set_skill("cuff", 400);
        set_skill("strike", 400);
        set_skill("buddhism", 400);
        set_skill("sword", 400);
        set_skill("duanshi-shenfa", 400);
        set_skill("duanjia-jian", 400);
        set_skill("qingyan-zhang", 400);
        set_skill("jinyu-quan", 400);
        set_skill("medicine", 400);
        
        map_skill("dodge","duanshi-shenfa");
        map_skill("cuff", "jinyu-quan");
        map_skill("strike","qingyan-zhang");
        map_skill("force", "kurong-changong");
        map_skill("sword","duanjia-jian");
        map_skill("parry", "yiyang-zhi");
        map_skill("finger", "yiyang-zhi");
        prepare_skill("finger", "yiyang-zhi");
        prepare_skill("strike", "qingyan-zhang");

        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: auto_perform :),
        }) );

        set("inquiry", ([
                "sword" : (: use_sword :),
                "unarmed" : (: use_unarmed :),
        ]) );

        create_family("大理段家", 13, "弟子");
        setup();
        carry_object("/d/shaolin/npc/obj/cloth")->wear();
        carry_object("/clone/weapon/changjian");
}
int auto_perform()
{
        int tempjiali;
        object me = this_object();
        object target = me->select_opponent();
        object weapon = me->query_temp("weapon");

        if (!me->is_fighting()) {
                if ( me->query("eff_qi") < me->query("max_qi") ) {
                        tempjiali=me->query("jiali");
                        exert_function("heal");
                        me->set("jiali", tempjiali);
                }
                return 1;
        }

        if (!objectp(target)
                || !random( (int)me->query("combat_exp") * 2 / (int)target->query("combat_exp") + 1) )
                return 0;

        if (objectp(weapon)) {
                if (weapon->query("skill_type") == "sword")
                        return perform_action("sword.ailao");
        }

        if (!objectp(weapon)) {
		/*if (me->query_temp("kurong"))
		{ command("yun reverse");
		  command("yun kurong");
		}
		else */
		command("exert kurong");
                return perform_action("finger.qiankun");
        }
        else

        return 1;
}
int use_sword()
{
	command("nod");
	command("wield jian");
	map_skill("parry", "duanjia-jian");
	return 1;
}
int use_unarmed()
{
	command("nod");
	command("unwield jian");
	map_skill("parry", "yiyang-zhi");
	return 1;
}

