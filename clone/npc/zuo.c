//Cracked by Roath
// zuo.c 左冷禅
// ALN   1/98

#include <ansi.h>

inherit NPC;

int auto_perform();
// int random_walk();

string* homes = ({
        "/d/city/guangchang",
        "/d/quanzhou/zhongxin",
        "/d/wudang/shanmen",
        "/d/shaolin/fzlou",
        "/d/shaolin/guangchang1",
        "/d/taishan/fengchan",
        "/d/taishan/yidao1",
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
        set_name("左冷禅", ({ "zuo lengchan", "zuo" }));
        set("long",
"这便是当代武学大宗师左冷禅。\n"
"他身穿杏黄色布袍，其时夕阳即将下山，日光斜照，映射其身，\n"
"显得金光灿烂，大增堂皇气象。\n");
        set("gender", "男性");
        set("age", 50);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);

        set("max_qi", 3000);
        set("max_jing", 1800);
        set("neili", 3000);
        set("max_neili", 3000);
        set("jiali", 100);
        set("combat_exp", 1200000);
        set("score", 5000);

        set_temp("apply/armor", 100);

        set_skill("force", 180);
        set_skill("dodge", 180);
        set_skill("parry", 180);
        set_skill("sword", 180);
        set_skill("strike", 180);
        set_skill("zixia-gong", 180);
        set_skill("huashan-shenfa", 180);
        set_skill("hunyuan-zhang", 180);

        set_skill("taiji-jian", 180);
        set_skill("huashan-jianfa", 180);
        set_skill("damo-jian", 180);
        set_skill("huifeng-jian", 180);
        set_skill("duanjia-jian", 180);
        set_skill("pixie-jian", 100);

        set_skill("taiji-shengong", 120);
        set_skill("hunyuan-yiqi", 120);
        set_skill("linji-zhuang", 120);
        set_skill("kurong-changong", 120);

        map_skill("force", "zixia-gong");
        map_skill("dodge", "huashan-shenfa");
        map_skill("parry", "huashan-jianfa");
        map_skill("sword", "huashan-jianfa");
        map_skill("strike", "hunyuan-zhang");

        prepare_skill("strike", "hunyuan-zhang");

        create_family("五岳剑派", 1, "五岳盟主");

        set("chat_chance", 40);
        set("chat_msg", ({
                (: random_move :)
        }) );

        set("chat_chance_combat", 20);
        set("chat_msg_combat", ({
                (: auto_perform :),
        }) );

        set("inquiry", ([
                  "五岳剑派" : "五岳剑派由泰山派、衡山派、华山派、恒山派、嵩山派合并而成。",
                  "嵩山派" : "自从合并五岳剑派后，就没有嵩山派了。",
                  "邪派" : "天下邪派有星宿派，白驼山，雪山派和血刀门。",
                  "正派" : "天下名门正派有少林派，武当派，华山派，大理段家和峨嵋派。",
                  "名门正派" : "天下名门正派有少林派，武当派，华山派，大理段家和峨嵋派。",
        ]));

        set("stay_chance", 1);
        set("no_clean_up", 1);

        set("amount", 1 + random(3));

        setup();

        carry_object("/d/changbai/obj/qinggang-jian")->wield();
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

        if( interactive(ob) && time() < (int)ob->query("incharge") + 864000 ) {
                 message_vision(HIR"\n$N对$n喝道：" + RANK_D->query_rude(ob) + "居然敢危害武林，实在是死有余辜。\n"NOR, me, ob);
                 set_leader(ob);
                 kill_ob(ob);
                 return;
        }

        if( (int)ob->query("combat_exp") < 100000 )  return;

        fam = (string)ob->query("family/family_name");
        if( fam != "武当派"
        &&  fam != "少林派"
        &&  fam != "华山派"
        &&  fam != "大理段家"
        &&  fam != "峨嵋派" )  return;

        if( interactive(ob) && (int)ob->query("shen") < -1000 ) {
                message_vision(HIR"\n$N对$n大声喝道：" + RANK_D->query_rude(ob) + "！我辈学武之人，最讲究的是正邪是非之辨。\n"NOR, me, ob);
                command("say 实在是你犯了武林的大忌，不能原宥你的过失。");
                set_leader(ob);
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
        if( fam != "星宿派"
        &&  fam != "白驼山"
        &&  fam != "雪山派"
        &&  fam != "血刀门" ) return;
               
//        if( interactive(ob) ) {
//                message_vision(HIR"\n$N对$n大声喝道：" + RANK_D->query_rude(ob) + "！居然和妖魔勾搭成奸！\n"NOR, me, ob);
//                command("say 实在是你犯了武林的大忌，不能原宥你的过失。");
//                set_leader(ob);
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
        return 1;
}

int accept_kill(object ob)
{
        command("haha");
        command("say 天底下居然还有这种傻瓜？！");
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

/*
        if( !objectp(w1 = present("qinggang jian", me))
        &&  !objectp(w2 = present("xiuhua zhen", me)) ) {
                if( (int)me->query_skill("zixia-gong") < 180 ) {
                        me->set_skill("zixia-gong", 180);
                        me->map_skill("force", "zixia-gong");
                }

                me->reset_action();
                return perform_action("strike.wuji");
        }

        if( !objectp(w1 = present("qinggang jian", me))
        &&  !objectp(w2 = present("xiuhua zhen", me)) ) {
                w2 = new("/d/jiaxing/obj/xiuhua");
                w2->move(me);
        }
*/

        if( !objectp(w2 = present("xiuhua zhen", me)) 
        && query("amount") ) {
                add("amount", -1);
                w2 = new("/d/jiaxing/obj/xiuhua");
                w2->move(me);
        }

        w1 = present("qinggang jian", me);
        if( objectp(w1) && objectp(w2) ) n = random(6);
        else if( objectp(w1) && !objectp(w2) ) n = random(5);
        else if( !objectp(w1) && objectp(w2) ) n = 5;
        else {
                me->set_skill("zixia-gong", 180);
                me->map_skill("force", "zixia-gong");
                me->reset_action();
                return perform_action("strike.wuji");
        }                

        switch(n) {
        case 0:
                skill = "taiji-jian";
                action = "sword.chan";
                spforce = "taiji-shengong";
                break;
        case 1:
                skill = "huashan-jianfa";
                action = "sword.jianzhang";
                spforce = "zixia-gong";
                break;
        case 2:
                skill = "damo-jian";
                action = "sword.sanjue";
                spforce = "hunyuan-yiqi";
                break;
        case 3:
                skill = "huifeng-jian";
                action = "sword.mie";
                spforce = "linji-zhuang";
                break;
        case 4:
                skill = "duanjia-jian";
                action = "sword.ailao";
                spforce = "kurong-changong";
                break;
        case 5:
                skill = "pixie-jian";
                action = "sword.cimu";
                spforce = "zixia-gong";
                break;
        }

        if( objectp(w = me->query_temp("weapon")) ) {
                if( w == w1 && n < 5 ) {
                        message_vision(HIR"\n突然间$N嘿嘿冷笑几声。\n随即手中" + w->name() + "似曲似直，便如一件活物一般，顿时招式大变！！！\n"NOR, me);
                } else if( w == w1 && n == 5 ) {
                        w->unequip();
                        message_vision(w->query("unwield_msg"), me, w);
                        w2->wield();
                        message_vision(w2->query("wield_msg"), me, w2);
                        message_vision(HIR"\n突然间$N剑法一变，手中" + w2->name() + "忽伸忽缩，招式诡奇绝伦。\n"NOR, me);
                } else if( w == w2 && n < 5) {
                        w->unequip();
                        message_vision(w->query("unwield_msg"), me, w);
                        w1->wield();
                        message_vision(w1->query("wield_msg"), me, w1);
                        message_vision(HIG"\n$N似乎有意放慢了进攻，然。。。\n"NOR, me);
                }
        } else {
                if( n < 5 ) {
                        w1->wield();
                        message_vision(w1->query("wield_msg"), me, w1);
                        message_vision(HIG"\n$N似乎有意放慢了进攻，然。。。\n"NOR, me);
                } else {
                        w2->wield();
                        message_vision(w2->query("wield_msg"), me, w2);
                        message_vision(HIR"\n突然间$N剑法一变，手中" + w2->name() + "忽伸忽缩，招式诡奇绝伦。\n"NOR, me);
                }
        }              

	me->map_skill("sword", skill);
        me->map_skill("parry", skill);
        me->map_skill("force", spforce);
        me->reset_action();
        return perform_action(action);
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
