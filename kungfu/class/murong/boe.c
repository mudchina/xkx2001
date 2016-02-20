//Cracked by Roath
// /kungfu/class/murong/boe.c
//Sure /9/17/2000

inherit NPC;
//inherit F_SSERVER;
int auto_perform();

#include <ansi.h>

void create()
{
        set_name("风波恶", ({"feng boe", "feng", "boe"}));
        set("long",  "此人面黄肌瘦，下颌挂着两撇鼠须，像大病初愈。\n" );
        set("title", WHT"江南一阵风" NOR);
        set("gender", "男性");
        set("age", 32);
        set("max_qi", 4000);
        set("max_jing", 3500);
        set("neili", 5000);
        set("max_neili", 5000);
        set("jiali", 100);
        set("attitude", "heroism");
        set("shen_type", 1);
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);
	set("combat_exp",3000000);

        set_skill("force", 300);
        set_skill("dodge", 300);
        set_skill("strike", 300);
        set_skill("parry", 300);
        set_skill("blade", 300);
        set_skill("yanxing-dao",300);
        set_skill("murong-shenfa",300);
        set_skill("douzhuan-xingyi",300);
        set_skill("strike",300);
        set_skill("mian-zhang",300);
        set_skill("finger",300);
        set_skill("canhe-zhi",300);
	set_skill("liuhe-dao",300);
	set_skill("literate",220);
	set_skill("xiuluo-dao",300);
	set_skill("xue-dao",300);
	set_skill("liangyi-dao",300);
	set_skill("zixia-gong",300);
	set_skill("linji-zhuang",300);
	set_skill("xiaowuxiang",300);
	set_skill("hunyuan-yiqi",300);
	set_skill("huntian-qigong",300);

        map_skill("dodge", "murong-shenfa");
        map_skill("blade", "liangyi-dao");
        map_skill("finger","canhe-zhi");
        map_skill("parry","liangyi-dao");
	map_skill("force","zixia-gong");

        prepare_skill("finger","canhe-zhi");
	
	create_family("姑苏慕容", 19, "传人");

	set("chat_chance", 70);
        set("chat_msg", ({
                (: random_move :)
        }) );

        setup();

        carry_object("/d/murong/obj/qingyi")->wear();
        carry_object("/d/murong/obj/guitou-dao")->wield();

}

int accept_kill(object ob)
{
        command("haha");
        command("say 老子正愁找不到人打架呢。来来来，我与你大战三百回合！");
        return 1;
}

int auto_perform()
{
        object me = this_object();
        object ob = me->select_opponent();
        object w, w1, w2;
        string skill, action, spforce;
        int n;

        if ( !me->is_fighting() ) {
                if ( (int)me->query("eff_qi") < (int)me->query("max_qi") )
                        exert_function("heal");
                me->set("jiali", 100);

                return 1;
        }

        if( !objectp(w1 = present("guitou dao", me))
        &&  !objectp(w2 = present("dahuan dao", me)) ) {
                if( (int)me->query_skill("douzhuan-xingyi") < 300 ) {
                        me->set_skill("douzhuan-xingyi", 300);
                        me->map_skill("force", "douzhuan-xingyi");
                }

                me->reset_action();
                return perform_action("blade.shendao");
        }

        if( !objectp(w1 = present("guitou dao", me))
        &&  !objectp(w2 = present("dahuan dao", me)) ) {
                w2 = new("/d/murong/obj/guitou-dao");
                w2->move(me);
        }

        if( !objectp(w2 = present("dahuan dao", me)) 
        && query("amount") ) {
                add("amount", -1);
                w2 = new("/d/shenlong/obj/dahuan-dao");
                w2->move(me);
        }

        w1 = present("guitou dao", me);
        if( objectp(w1) && objectp(w2) ) n = random(6);
        else if( objectp(w1) && !objectp(w2) ) n = random(5);
        else if( !objectp(w1) && objectp(w2) ) n = 5;
        else {
                me->set_skill("douzhuan-xingyi", 180);
                me->map_skill("force", "douzhuan-xingyi");
                me->reset_action();
                return perform_action("blade.huanying");
        }                

        switch(n) {
        case 0:
                skill = "xue-dao";
                action = "blade.shendao";
                spforce = "xiaowuxiang";
                break;
        case 1:
                skill = "liangyi-dao";
                action = "blade.sanshen";
                spforce = "zixia-gong";
                break;
        case 2:
                skill = "liuhe-dao";
                action = "blade.luanhuan";
                spforce = "huntian-qigong";
                break;
        case 3:
                skill = "yanxing-dao";
                action = "blade.huanying";
                spforce = "linji-zhuang";
                break;
        }

        if( objectp(w = me->query_temp("weapon")) ) {
                if( w == w1 && n < 5 ) {
                        message_vision(HIR"\n突然间$N嘿嘿干笑几声。\n手中抽出一柄" + w->name() + "说道：“你得陪我打架，不准跑才行呀！”\n"NOR, me);
                } else if( w == w1 && n == 5 ) {
                        w->unequip();
                        message_vision(w->query("unwield_msg"), me, w);
                        w2->wield();
                        message_vision(w2->query("wield_msg"), me, w2);
                        message_vision(HIR"\n突然间$N刀法一变，手中" + w2->name() + "如灵蛇一般直缠上来。\n"NOR, me);
                } else if( w == w2 && n < 5) {
                        w->unequip();
                        message_vision(w->query("unwield_msg"), me, w);
                        w1->wield();
                        message_vision(w1->query("wield_msg"), me, w1);
                        message_vision(HIG"\n$N似乎有意放慢了进攻，然而……\n"NOR, me);
                }
        } else {
                if( n < 5 ) {
                        w1->wield();
                        message_vision(w1->query("wield_msg"), me, w1);
                        message_vision(HIG"\n$N似乎有意放慢了进攻，然而……\n"NOR, me);
                } else {
                        w2->wield();
                        message_vision(w2->query("wield_msg"), me, w2);
                        message_vision(HIR"\n突然间$N刀法一变，手中" + w2->name() + "招式诡异，直奔你的要害攻来！\n"NOR, me);
                }
        }              

        me->map_skill("sword", skill);
        me->map_skill("parry", skill);
        me->map_skill("force", spforce);
        me->reset_action();
        return perform_action(action);
}
