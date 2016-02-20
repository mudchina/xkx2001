//Cracked by Roath
///kungfu/class/gaibang/jian.c
//Modified by xbc: 03/30/97
//MOdified By Wzfeng 10/5/2000,Fix -Exp bug.



inherit NPC;
inherit F_MASTER;

string ask_me(string, object);
int auto_perform();

void create()
{
        set_name("简长老", ({"jian zhanglao", "jian", "zhanglao"}));
        set("title", "丐帮九袋长老");
        set("nickname", "执法长老");
        set("gender", "男性");
        set("age", 50);
        set("long", 
                "简长老是丐邦的执法长老，代帮主执掌法刀以及青竹令等。\n"
                "他向来嫉恶如仇，弟子中有谁犯过，出手决不容情。\n");

        set("attitude", "peaceful");
        
        set("rank", 9);

        set("str", 24);
        set("int", 20);
        set("con", 24);
        set("dex", 20);

        set("rank", 9);

        set("qi", 900);
        set("max_qi", 900);
        set("jing", 100);
        set("max_jing", 100);
        set("neili", 1500);
        set("max_neili", 1500);
        set("jiali", 100);
        
        set("combat_exp", 750000);
        set("score", 20000);
        
        set_skill("force", 135); // 基本内功
        set_skill("huntian-qigong", 135); // 混天气功
        set_skill("strike", 130); // 基本拳脚
        set_skill("xianglong-zhang", 130); // 降龙十八掌
        set_skill("dodge", 120); // 基本躲闪
        set_skill("xiaoyaoyou", 120); // 逍遥游
        set_skill("parry", 125); // 基本招架
        set_skill("staff", 150); // 基本杖法
        set_skill("fengmo-zhang", 150); // 疯魔杖法
        
        map_skill("force", "huntian-qigong");
        map_skill("strike", "xianglong-zhang");
        map_skill("dodge", "xiaoyaoyou");
        map_skill("staff", "fengmo-zhang");
        map_skill("parry", "fengmo-zhang");
        
        prepare_skill("strike", "xianglong-zhang");

        create_family("丐帮", 18, "九袋长老");

        set("chat_chance", 1);
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: auto_perform :),
        }) );

        set("inquiry", ([
                "青竹令" :     (: ask_me, "ling" :),
                "退帮" :     (: ask_me, "leave" :),
                "离帮" :     (: ask_me, "leave" :),
                "退休" :     (: ask_me, "leave" :),
                "惩罚" :     (: ask_me, "penalty" :),
        ]));

        setup();

        carry_object("/d/gaibang/obj/budai")->set_amount(8);
        carry_object("/d/gaibang/obj/budai")->wear();
        carry_object("/clone/weapon/gangzhang")->wield();
        
}

init()
{
        object ob;
        mapping myfam;
        
        ::init();
        set_heart_beat(1);      
        if (interactive(ob = this_player()) && !is_fighting() 
        && file_name(environment(this_object())) == "/d/city/gbandao" ) {
                myfam = (mapping)ob->query("family");
          if ((!myfam || myfam["family_name"] != "丐帮") &&
                        (!wizardp(ob))) {
                        remove_call_out("saying");
                        call_out("saying",2,ob);
                }
        }
}

void saying(object ob)
{
        if (!ob || environment(ob) != environment())
                return;

        message_vision("\n简长老看了$N一眼，冷冷地说到：“洪帮主他老人家说我不该"
            "随意责打丐帮弟子，\n你又不属我丐帮，我打你总可以吧？”\n"
            "说完右腿一抬，$N顺势应了一招青城派的「屁股向后，平沙落雁式」"
            "－－叭叽\n\n", ob);
        remove_call_out("kicking");
        call_out("kicking",1,ob);
        
}

void kicking(object ob)
{
        if (!ob || environment(ob) != environment())
                return;

        ob->move("/d/city/pomiao");
         message("vision","只听“嘭”地一声，紧接着" +  ob->query("name") +
                "从小门里飞了出来，屁股上有一个清楚的鞋印。\n", environment(ob), ob);
}

void attempt_apprentice(object ob)
{
        if ((int)ob->query_str() < 25) {
                command("say 我们丐帮的武艺一向以刚猛为主，" + 
                RANK_D->query_respect(ob) + "臂力太弱，似乎不宜学丐帮的功夫？");
                return;
        }

        if( ob->query("family/family_name") != "丐帮" )
        {
                if( ob->query("rank") > 1 ) {
                        command("say 哼！本帮以忠义为先，可容不下你这种无信无义的家伙！\n");
                        return;
                }

                command("say 好吧，希望" + RANK_D->query_respect(ob) +
                "能好好学习本门武功，将来在江湖中闯出一番作为。");
                ob->set("rank", 1); 
                command("recruit " + ob->query("id"));
                ob->set("title", "丐帮一袋弟子");
        } 
        else
        {
                ob->set_temp("title", ob->query("title"));
                command("recruit " + ob->query("id"));
                ob->set("title", ob->query_temp("title"));
                ob->delete_temp("title");
        }

//      command("say 老夫不收徒弟，" + RANK_D->query_respect(ob) + "还是请回吧。");
}

int accept_object(object ob, object obj)
{
        int rank;
        object me = this_object();

 if( ob->query("family/family_name") != me->query("family/family_name") ) {
                command("say 你我不属同一门派，你给我青竹令又有何用？！ 请回吧！");
                return 0;
        }

        rank = ob->query("rank");
        if( rank >= 9 ) {
                command("say 你在帮中位属九袋长老，地位仅次于帮主，已无法再升了！");
                return 0;
        }

        if( obj->query("id") == "qingzhu ling" ) 
        {
                if( obj->query_temp("owner") != ob->query("name") ) {
                        command("say 你不是这快青竹令的主人！");
                        return 0;
                }
                if( !obj->query_temp("win_times") ) {
                        command("say 你尚未战胜一个同门师兄弟，不符合晋升的条件。");
                        return 0;
                }
                if( !obj->query_temp("win_last") ) {
                        command("say 你尚未战胜同辈大师兄，不符合晋升的条件。");
                 return 0;
                }
                if( ob->query("combat_exp") < ((2000 + 500*(rank-1)) * rank*rank)) {
                        command("say 你的战斗经验不足，不符合晋升的条件。");
                        return 0;
                }
                if( !objectp(present("bu dai", ob)) ) {
                        command("say 你身上的布袋哪儿去了？！身为丐帮弟子，袋在人在，袋亡人亡！");
                        return 0;
                }

                command("say 好，我收下你的青竹令了。" + ob->query("name") + "，你愿意晋升为丐帮" +
                                chinese_number(ob->query("rank")+1) + "袋弟子吗？");

                add_action("do_say", "say");
                ob->delete_temp("leaving", 1);
                ob->set_temp("thinking", 1);
                ob->set_temp("new_rank", ob->query("rank")+1);

                remove_call_out("destroying");
                call_out("destroying", 1, ob, obj);
                return 1;
        }

        command("smile");
        command("say 这东西给我可没有什么用。");
        command("give " + obj->query("id") + " to " + me->query("id"));
        return 0;
}

void destroying(object ob, object obj)
{
        int i;
        object *inv;
        inv = all_inventory(ob);
        for(i=0; i<sizeof(inv); i++) {
                if(inv[i]->query("id") == obj->query("id"))
                        destruct(inv[i]);
        }

        //destruct(obj);
        
        return;
}

int do_say(string arg)
{
        object me, ob, dai;
        int i_rank, exp_substracted = 0;

        me = this_object();
        ob = this_player();
                
        if( !arg || arg=="" ) return 0;

        if ( arg == "接受" && ob->query_temp("leaving"))
        {
                ob->delete_temp("leaving");
                for ( i_rank = ob->query("rank"); i_rank > 1; i_rank --) {
                        exp_substracted += 1500 * (i_rank-1);
                        ob->add("combat_exp", -1500 * (i_rank-1));
                }
                if(ob->query("combat_exp")<0)
                ob->set("combat_exp",0);

                message_vision("\n简长老从$N身上摘下" +
                                chinese_number(ob->query("rank")) +  "只布袋。\n\n", ob);
                ob->set("rank", 9);
                ob->delete("family");
                ob->set("family/family_name", "无");            
                ob->set("title", "普通百姓");   

                tell_object(ob, "你的经验值降低了" + chinese_number(exp_substracted) + "点。\n");

                command("say 从今以后你就不再是本帮弟子了。你好自为之吧！");
                
                if (objectp(dai=present("bu dai", ob))) {
                        dai->unequip();
                        destruct(dai);
                }
                return 1;
        }

        if( arg=="愿意" && ob->query_temp("thinking") 
        && ob->query_temp("new_rank") == ob->query("rank") + 1
        && objectp(present("bu dai", ob)) ) 
        {
                if( ob->query("rank") < 9 )
                        ob->set("rank", ob->query_temp("new_rank"));
                else return 0;

                ob->delete_temp("thinking");
                ob->delete_temp("gaibang_winner");
                ob->delete_temp("new_rank");

                if( ob->query("rank") >= 9 )
                        ob->set("title", "丐帮" + chinese_number(ob->query("rank")) + "袋长老");
                else
                        ob->set("title", "丐帮" + chinese_number(ob->query("rank")) + "袋弟子");

                ob->add("combat_exp", 1500 * (ob->query("rank")-1));
                tell_object(ob, "你的经验值提高了" + chinese_number(1500 * (ob->query("rank")-1)) + "点！\n");

                command("say 恭喜恭喜，从今以后你就是本帮" + chinese_number(ob->query("rank")) + "袋弟子了！");

                if(objectp(dai = present("bu dai", ob)) ){
                        dai->unequip();
                        dai->add_amount(1);
                        message_vision("\n简长老从$N身上摘下布袋，另外又取出个布袋，将" +
                                chinese_number(ob->query("rank")) + 
                                "个布袋紧紧绑在一起，亲自将它们披在$N身上。\n\n", ob);
                        dai->wear();
                } else {
                        dai=new("/d/gaibang/obj/dai");
                        dai->move(ob);
                        message_vision("\n简长老取出一个布袋，亲自将它披在$N身上。\n\n", ob);
                        dai->wear();
          }

                return 1;
        }

        return 0;

}

string ask_me(string name, object obj)
{
        mapping fam; 
        object me = this_player();
        
        if( !(fam = this_player()->query("family")) || fam["family_name"] != "丐帮")
                return RANK_D->query_respect(this_player()) + 
                "不是丐帮弟子，不知此话从何谈起？";

        if ( name == "ling") {
                if( this_player()->query("combat_exp") < 1000 ) 
                        return RANK_D->query_respect(this_player()) + 
                        "战斗经验不足，尚无资格领取青竹令。";

          obj=new("d/gaibang/obj/qingzhu-ling");
                obj->move(this_player());
                obj->set_temp("owner", this_player()->query("name"));
                message_vision("$N交给$n一面青竹令。\n", this_object(), this_player());

                return "凭这面青竹令，你可自由向你的师兄弟们比划武功。";
        }

        else if (name == "leave") {
                add_action("do_say", "say");
                me->set_temp("leaving", 1);
                me->delete_temp("thinking", 1);
                return "人各有志，你要是真想离开丐帮，我也不强留你，但是你将受到一些惩罚。你可接受？";
        }

        else if (name == "penalty") {
                return "你在丐帮升袋所得的奖励将被减去。";
        }
}
                

int auto_perform()
{
        object me = this_object();
  object target = me->select_opponent();
        object weapon = me->query_temp("weapon");

        if ( !me->is_fighting() ) {
                if ( me->query("eff_qi") < me->query("max_qi") )
                        exert_function("heal");
                me->set("jiali", 100);

                return 1;
        }

        if ( !me->query_temp("powerup") ) {
                return exert_function("powerup");
        }

        if ( objectp(weapon) ) {
                if ( !random( (int)me->query("combat_exp") * 2
                   / (int)target->query("combat_exp") + 1) 
                && !me->query_temp("shengang") ) 
                        return exert_function("shengang");

                if ( weapon->query("skill_type") == "staff" )
                        return perform_action("staff.feizhang");
 }
        else
                return perform_action("strike.leiting");
}

