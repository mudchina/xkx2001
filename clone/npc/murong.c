//Cracked by Roath
// murong.c 慕容博
// ALN  1/98

#include <ansi.h>

inherit NPC;

// int random_walk();
void do_copy(object);
string *is_unarmed(string);

string* homes = ({
        "/d/city/guangchang",
        "/d/quanzhou/zhongxin",
        "/d/wudang/shanmen",
        "/d/shaolin/fzlou",
        "/d/shaolin/guangchang1",
        "/d/taishan/fengchan",
        "/d/xingxiu/xxroad2",
        "/d/huashan/laojun",
        "/d/village/square",
        "/d/xingxiu/tianroad3",
        "/d/forest/bank3",
        "/d/emei/baoguomen",
        "/d/emei/xixiang",
        "/d/qilian/qilian",
        "/d/dali/wangfu1",
        "/d/xixia/square",
});

void create()
{
        set_name("慕容博", ({ "murong bo", "murong" }));
        set("long",
"一个灰衣僧人，语音颇为苍老。\n"
"他神清目秀、白眉长垂。\n");
        set("gender", "男性");
        set("age", 60);
        set("attitude", "peaceful");
        set("shen_type", -1);
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);

        set("max_qi", 3000);
        set("max_jing", 2000);
        set("neili", 3000);
        set("max_neili", 3000);
        set("jiali", 100);
        set("combat_exp", 1800000);
        set("score", 5000);

        set_temp("apply/armor", 100);
        set_temp("apply/damage", 60);
        set_temp("apply/dodge", 30);
        set_temp("apply/attack", 30);

        set_skill("force", 200);
        set_skill("dodge", 200);
        set_skill("parry", 200);
        set_skill("finger", 200);
        set_skill("strike", 200);

        set_skill("hunyuan-yiqi", 200);
        set_skill("shaolin-shenfa", 200);
        set_skill("sanhua-zhang", 200);
        set_skill("yizhi-chan", 200);

        map_skill("force", "hunyuan-yiqi");
        map_skill("dodge", "shaolin-shenfa");
        map_skill("parry", "sanhua-zhang");
        map_skill("strike", "sanhua-zhang");
        map_skill("finger", "yizhi-chan");

        prepare_skill("strike", "sanhua-zhang");
        prepare_skill("finger", "yizhi-chan");

        set("chat_chance", 40);
        set("chat_msg", ({
                (: random_move :)
        }) );

        set("inquiry", ([
                  "慕容复" : "我给我孩儿取名为“复”，就是命他时刻不忘列祖列宗的遗训，须当兴复大燕，夺还江山。",
                  "慕容" : "嘿嘿，大燕国当年慕容、慕容恪、慕容 垂、慕容德何等英雄！",
                  "慕容氏" : "嘿嘿，大燕国当年慕容、慕容恪、慕容 垂、慕容德何等英雄！",
                  "大燕国" : "昔年大燕国威震河朔，打下了锦绣江山，只可惜敌人凶险狠毒，颠覆我邦。",
                  "邪派" : "天下邪派有星宿派，白驼山，雪山派和血刀门。",
                  "正派" : "天下名门正派有武当派，华山派和峨嵋派。",
                  "名门正派" : "天下名门正派有武当派，华山派和峨嵋派。",
        ]));

        set("stay_chance", 1);

        set("no_clean_up", 1);

        setup();

        carry_object("/clone/misc/cloth")->wear();
}

void init()
{
        object ob = this_player();
        object me = this_object();
        object ob1;
        mapping spouse;
        string fam;

        ::init();

        set_heart_beat(1);

        if( !living(me) || me->is_busy() || me->is_fighting() ) return;

        if( (int)ob->query("combat_exp") < 100000 )  return;

        fam = (string)ob->query("family/family_name");
        if( fam != "星宿派"
        &&  fam != "白驼山"
        &&  fam != "雪山派"
        &&  fam != "血刀门" ) return;

        if( interactive(ob) && (int)ob->query("shen") > 1000 ) {
                message_vision(HIR"\n$N对$n大声喝道：" + RANK_D->query_rude(ob) 
+ "！我辈学武之人，最讲究的是正邪是非之辨。\n"NOR, me, ob);
                command("say 实在是你犯了武林的大忌，不能原宥你的过失。");
                set_leader(ob);
                do_copy(ob);
                kill_ob(ob);
                return;
        }

        if( !mapp(spouse = ob->query("spouse")) ) return;

        if( !(ob1 = find_player(spouse["id"])) ) {
                ob1 = new(USER_OB);
                ob1->set("id",  spouse["id"]);
                if( !ob1->restore() ) return;
                call_out("do_destory", 1, ob1);
        }

        fam = (string)ob1->query("family/family_name");
        if( fam != "武当派"
        &&  fam != "少林派"
        &&  fam != "华山派"
        &&  fam != "大理段家"
        &&  fam != "峨嵋派" )  return;

//        if( interactive(ob) ) {
//                message_vision(HIR"\n$N对$n大声喝道：" + RANK_D->query_rude(ob) + "！居然和名门正派勾搭成奸！\n"NOR, me, ob);
//                command("say 实在是你犯了武林的大忌，不能原宥你的过失。");
//                set_leader(ob);
//                do_copy(ob);
//                kill_ob(ob);
//                return;
//        }
}

void do_destory(object ob)
{
        destruct(ob);
}

int accept_fight(object ob)
{
        object me = this_object();

        int my_max_qi = (int)me->query("max_qi");

        if ( (int)me->query("qi")*100 / my_max_qi <= 80 ) {
                return 0;
        }

        command("sneer");
        message_vision("$N喝道：" + RANK_D->query_rude(ob) + "！你也配和我交手？\n", me);
        do_copy(ob);
        kill_ob(ob);
        return 1;
}

int accept_kill(object ob)
{
        command("haha");
        command("say 天底下居然还有这种傻瓜？！");
        do_copy(ob);
        return 1;
}

void do_copy(object ob)
{
        object me = this_object();
        mapping fam, hp_status, skill_status, map_status, prepare_status;
        string *sname, *mname, *pname, *umname;
        string pre1, pre2;
        int i, temp;

/* delete all skills except dodge, force, parry */

        if ( mapp(skill_status = me->query_skills()) ) {
                skill_status = me->query_skills();
                sname  = keys(skill_status);

                temp = sizeof(skill_status);
                for(i=0; i<temp; i++) {
                        if( sname[i] != "force" && sname[i] != "dodge" && sname[i] != "parry" )
                                me->delete_skill(sname[i]);
                }
        }

/* delete all skill maps */

        if( mapp(map_status = me->query_skill_map()) ) {
                mname  = keys(map_status);

                temp = sizeof(map_status);
                for(i=0; i<temp; i++) {
                        me->map_skill(mname[i]);
                }
        }

/* delete all skill prepares */
        if ( mapp(prepare_status = me->query_skill_prepare()) ) {
                pname  = keys(prepare_status);

                temp = sizeof(prepare_status);
                for(i=0; i<temp; i++) {
                        me->prepare_skill(pname[i]);
                }
        }

/* copy those skills for special dodge, special force, and unarmed */

        if( mapp(skill_status = ob->query_skills()) ) {
                sname  = keys(skill_status);
                for(i=0; i<sizeof(sname); i++) {
                       if( sizeof(is_unarmed(sname[i]))
                       || SKILL_D(sname[i])->valid_enable("force")
                       || SKILL_D(sname[i])->valid_enable("dodge") )
                              me->set_skill(sname[i], 200);
                }
        }

/* set new skill maps and prepares */
/* only for those skills for dodge, force, and unarmed */

        skill_status = me->query_skills();
        sname = keys(skill_status);
        for(i = 0; i < sizeof(sname); i++) {
                if( sizeof(umname = is_unarmed(sname[i])) == 2 ) {
                         if( (int)me->query_skill(umname[0], 1) < 1 )
                         me->set_skill(umname[0], 200);
                         if( sizeof(me->query_skill_prepare()) == 0 ) {
                                pre1 = sname[i];
                                me->map_skill(umname[0], pre1);
                                me->prepare_skill(umname[0], pre1);
                         } else if(sizeof(me->query_skill_prepare()) == 1
                         && SKILL_D(pre1)->valid_combine(sname[i])) {
                                pre2 = sname[i];
                                me->map_skill(umname[0], pre2);
                                me->prepare_skill(umname[0], pre2);
                        }
                } else if( SKILL_D(sname[i])->valid_enable("force") ) {                                me->map_skill("force", sname[i]);
                } else if( SKILL_D(sname[i])->valid_enable("dodge") ) {
                        me->map_skill("dodge", sname[i]);
                }        
        }

        if( sizeof(me->query_skill_prepare()) == 0 ) {
                me->set_skill("finger", 200);
                me->set_skill("strike", 200);
                me->set_skill("sanhua-zhang", 200);
                me->set_skill("yizhi-chan", 200);
                me->map_skill("finger", "yizhi-chan");
                me->map_skill("strike", "sanhua-zhang");
                me->prepare_skill("strike", "sanhua-zhang");
                me->prepare_skill("finger", "yizhi-chan");
                me->map_skill("parry", "sanhua-zhang");
        }

        me->reset_action();
}

int return_home(object home)
{
                // Are we at home already?
        if( !environment()
        ||      environment()==home )
                return 1;

        // Are we able to leave?
        if( !living(this_object())
        ||  is_fighting() || is_busy() ) return 0;

        // Leave for home now.
        message("vision", this_object()->name() + "急急忙忙地离开了。\n",
                environment(), this_object());

        home = load_object(homes[random(sizeof(homes))]);
        if (home) return move(home);
        return 0;
}

/*
int random_walk()
{
        mapping exits, doors;
        string *dirs, dir, last_room, this_room;
        object here = environment();

        if( !objectp(here) 
        || is_fighting() || is_busy()
        || !mapp(exits = here->query("exits")) 
        || query("jingli") < query("max_jingli") / 2 ) return 0;

        dirs = keys(exits);

        if( mapp(doors = here->query_doors()) ) {
                dirs += keys(doors);
        }
        if( sizeof(dirs) == 0 ) return 0;

        dir = dirs[random(sizeof(dirs))];
        if( stringp(last_room = query_temp("last_room"))
        &&  sizeof(dirs) > 1 && exits[dir] == last_room ) {
                dirs -= ({dir});
                dir = dirs[random(sizeof(dirs))];
        }

        if( mapp(doors) && !undefinedp(doors[dir])
        && (doors[dir]["status"] & DOOR_CLOSED) )
                command("open " + dir);
        command("go " + dir);
        set_temp("last_room", this_room);

        return 1;
}
*/

private string *is_unarmed(string skill)
{
        string *result = ({});
        int m;

        string *unarmed_types = ({
        "finger",
        "hand",
        "cuff",
        "claw",
        "strike",
        "kick",
        });


		  if( member_array(skill, unarmed_types) != -1 ) {
					 result += ({skill});
		  } else {
					 for(m = 0; m < sizeof(unarmed_types); m++) {
					 if( SKILL_D(skill)->valid_enable(unarmed_types[m]) ) {
					 result += ({unarmed_types[m]});
					 result += ({skill});
					 }
					 }
		  }

		  return result;
}





