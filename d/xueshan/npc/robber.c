//Cracked by Roath
// npc: /d/city/npc/ftb_killer.c
// Chu 2/10/99

#include <ansi.h>
inherit NPC;

int setup_robber(int exp_level);
int set_random_name();
void start_checking(object target);
void start_job(object target);
void clear_dumudian();
void self_destruct();


static string *menpai_names1 = ({
    "华山派",
    "峨嵋派",
    "武当派",
    "少林派",
    "丐帮",
});

static string *menpai_names2 = ({
    "华山",
    "峨嵋",
    "武当",
    "少林",
    "丐帮",
});

static int random_id;

void create()
{
        set_random_name();
        set("gender", "男性" );
        set("age", 29);
        set("str", 25);
        set("dex", 30);
        set("con", 25);
        set("int", 23);
        set("shen_type", -1);

        set("max_qi", 300);
        set("max_jing", 100);
        set("neili", 200);
        set("max_neili", 200);
        set("no_refresh", 1);

//        setup_robber();

        setup();
        carry_object("/clone/armor/beixin")->wear();
        carry_object("/d/xingxiu/obj/fire");
 	    remove_call_out("self_destruct");
	    call_out("self_destruct", 1200);

}

int set_random_name()
{
    string my_name;

    random_id=random(5);
    my_name = menpai_names2[random_id] + "弟子";
    set_name(my_name, ({"dizi"}));
    set("long", "他看起来是一个年轻的"+menpai_names1[random_id]+"弟子。\n");
    
    return random_id;   
}

int setup_robber(int exp_level)
{
    int level, menpai, exp;

    menpai = random_id;

//    printf("exp_factor = %f.\n",exp_factor); 

    exp = exp_level*(random(50)+130)/100;

    if (exp < 0 ) return;
    
    level = pow(10*exp, 0.333334);
    
//    level = level - 5;

    if (level < 20) level = 20;

    set("max_neili", level*12);
    set("neili", level*12);
    set("eff_jingli", level*10);
    set("max_jingli", level*10);
    set("jingli", level*10);
    set("max_qi", level*12);
    set("eff_qi", level*12);
    set("qi", level*12);
    set("max_jing", level*10);
    set("eff_jing", level*10);
    set("jing", level*10);
    set("jiali", level/2);

    set("combat_exp", exp);
    set_skill("force", level);
    set_skill("dodge", level);
    set_skill("parry", level);
    set_skill("sword", level);
    set_skill("blade", level);
    set_skill("strike", level);
    set_skill("cuff", level);
    set_skill("finger", level);
    set_skill("claw", level);
    set_skill("club", level);
    set_skill("kick", level);
    set_skill("staff", level);
    set_skill("whip", level);

    switch (menpai){
    // Huashan
    case 0:
        set_skill("huashan-jianfa", level);
        set_skill("liangyi-dao", level);
        set_skill("huashan-shenfa", level);
        set_skill("zixia-gong", level);
        set_skill("pishi-poyu", level);
        set_skill("hunyuan-zhang", level);
 
        map_skill("force", "zixia-gong");
        map_skill("dodge", "huashan-shenfa");
        map_skill("parry", "huashan-jianfa");
        map_skill("strike", "hunyuan-zhang");
        map_skill("cuff", "pishi-poyu");
        map_skill("sword", "huashan-jianfa");
        map_skill("blade", "liangyi-dao");
        
        prepare_skill("cuff", "pishi-poyu");
        prepare_skill("strike", "hunyuan-zhang");
        
        set("default_weapon", "/clone/weapon/gangjian");

        break;
    // emei
    case 1:
        set_skill("huifeng-jian", level);
        set_skill("yanxing-dao", level);
        set_skill("jinding-zhang", level);
        set_skill("tiangang-zhi", level);
        set_skill("linji-zhuang", level);
        set_skill("zhutian-bu", level);

        map_skill("force", "linji-zhuang");
        map_skill("sword", "huifeng-jian");
        map_skill("blade", "yanxing-dao");
        map_skill("strike", "jinding-zhang");
        map_skill("finger", "tiangang-zhi");
        map_skill("dodge", "zhutian-bu");
        map_skill("parry", "huifeng-jian");

        prepare_skill("finger", "tiangang-zhi");
        prepare_skill("strike", "jinding-zhang");
        set("default_weapon", "/clone/weapon/gangdao");
        break;
    // wudang
    case 2:
        set_skill("taiji-shengong", level);
        set_skill("taiji-jian", level);
        set_skill("tiyunzong", level);
        set_skill("taiji-quan", level);
 
        map_skill("force", "taiji-shengong");
        map_skill("parry", "taiji-jian");
        map_skill("cuff", "taiji-quan");
        map_skill("dodge", "tiyunzong");
        map_skill("sword", "taiji-jian");
        
        prepare_skill("cuff", "taiji-quan");
        set("default_weapon", "/clone/weapon/gangjian");
        break;
    // shaolin
    case 3:
        set_skill("damo-jian", level);
        set_skill("xiuluo-dao", level);
        set_skill("wuchang-zhang", level);
        set_skill("zui-gun", level);
        set_skill("shaolin-shenfa", level);
        set_skill("hunyuan-yiqi", level);
        set_skill("yizhi-chan", level);
        set_skill("banruo-zhang", level);
 
        map_skill("force", "hunyuan-yiqi");
        map_skill("dodge", "shaolin-shenfa");
        map_skill("parry", "damo-jian");
        map_skill("sword", "damo-jian");
        map_skill("blade", "xiuluo-dao");
        map_skill("club", "zui-gun");
        map_skill("staff", "wuchang-zhang");
        map_skill("finger", "yizhi-chan");
        map_skill("strike", "banruo-zhang");
        
        prepare_skill("finger", "yizhi-chan");
        prepare_skill("strike", "banruo-zhang");
        set("default_weapon", "/clone/weapon/gangjian");
        break;

    // gaibang
    case 4:
    default:    
        set_skill("liuhe-dao", level);
        set_skill("xiaoyaoyou", level);
        set_skill("huntian-qigong", level);
        set_skill("shexing-diaoshou", level);
 
        map_skill("force", "huntian-qigong");
        map_skill("dodge", "xiaoyaoyou");
        map_skill("parry", "liuhe-dao");
        map_skill("blade", "liuhe-dao");
        map_skill("hand", "shexing-diaoshou");
        
        prepare_skill("hand", "shexing-diaoshou");
        set("default_weapon", "/clone/weapon/gangdao");
        break;
    }
    if (random(2) > 0) carry_object(query("default_weapon"))->wield();

    return menpai;
}

void start_checking(object target)
{
    call_out("start_job", 15+random(10), target);
    return;
}


void self_destruct() {
    object me = this_object();
    
    clear_dumudian(); 
    message("vision", name(1)+"急急忙忙地离开了.\n", environment(me), me);
    destruct(me);
}

void start_job(object target)
{
    object me = this_object();
    object target_obj, gang;

    gang = present("tong gang", environment(me));

    if (!gang) {
        // Tong gang is not here, just go
        self_destruct();
        return;
    }
    if ( !me->is_fighting() && !me->query_temp("disabled") ) 
    {
        // only check if I am not fighting
       if (present(target->query("id"), environment(me))) {
           // if the player still here, attack him
           message_vision(HIR"\n$N对$n大声喝道：" + RANK_D->query_rude(target) + "竟敢不识好歹？！\n\n"NOR, me, target);
           kill_ob(target);
       }
       else
       {
           target_obj = present("zhiri lama", environment(me));
           if (target_obj) 
           {
//               EMOTE_D->do_emote(this_object(), vb, emote_arg, 0, 0);

               command("hehe "+target_obj->query("id"));
               kill_ob(target_obj);
           }
           else    
           {
               if (gang->query_current_liquid() > 0) 
               {
                    // set gang on fire.
                    command("say "+"老子看死秃驴们还怎么做法事");
                    message_vision(HIR"$N从怀中掏出一支火折，点燃了铜缸中的酥油。\n"NOR, me);               
                    gang->burn_out_gang();
               }
               self_destruct();
               return;
           }
       }
    }
    call_out("start_job", 15+random(10), target);
    return;
}

void clear_dumudian()
{
    object room1;

    if(!( room1 = find_object("/d/xueshan/dumudian")) )
         room1 = load_object("/d/xueshan/dumudian");
    room1->reset_to_normal();
    return;
}

void die()
{
    clear_dumudian();
    ::die();
}

