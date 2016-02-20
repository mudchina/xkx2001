//Cracked by Roath
// /kungfu/class/quanzhen/qiu.c
// qiu.c 丘处机
// sdong 08/01/98
// xQin 8/00 加入还俗功能

inherit NPC;
inherit F_MASTER;
inherit F_SAVE;
inherit F_UNIQUE;
#include <ansi.h>

#define OFFICE "/d/zhongnan/dadian"

int auto_check();
void waiting();
void checking();
void do_chase();
void do_kill(object);
void full_all(object me);
void die();
void do_inquiry();
string ask_me();
string ask_me2();
string ask_job();
void reward_dest(object obj,object ob);
void thank_dest(object obj,object ob);
string ask_me_revenge();
string ask_huansu();
int do_kill_sb(string arg);
int do_throw(string arg);
int auto_perform();
void thank_feng(object obj,object ob);
void reward_feng(object obj,object ob);

string query_save_file()
{
                  return "/data/npc/qiu";
}


void create()
{
        seteuid(getuid());

        if(!restore())
        {
        set_name("丘处机", ({ "qiu chuji", "qiu" }));
        set("nickname", "长春子");
        set("long",
                "他就是全真七子中最负盛名的丘处机，道号长春子，现任全真教掌教真人。\n"
                "他已年近七十，身材魁梧，满脸红光，气宇不凡。\n");
        set("gender", "男性");
        set("age", 69);
        set("attitude", "heroic");
        set("shen_type", 1);
        set("str", 27);
        set("int", 25);
        set("con", 25);
        set("dex", 26);
        set("max_qi", 5000);
        set("max_jing", 3100);
        set("neili", 3800);
        set("max_neili", 3800);
        set("jiali", 80);
        set("combat_exp", 1800000);
        set("score", 5000);

        set_skill("force", 300);
        set_skill("dodge", 300);
        set_skill("parry", 300);
        set_skill("sword", 320);
        set_skill("strike", 300);
        set_skill("cuff", 300);
        set_skill("beidou-zhenfa", 300);

        set_skill("xiantian-gong", 300);
        set_skill("jinyangong", 300);
        set_skill("chunyang-quan", 300);
        set_skill("sanhua-juding", 300);
        set_skill("quanzhen-jian", 320);
        set_skill("literate", 300);
        set_skill("taoism", 300);

        map_skill("force", "xiantian-gong");
        map_skill("dodge", "jinyangong");
        map_skill("cuff", "chunyang-quan");
        map_skill("strike", "sanhua-juding");
        map_skill("parry", "quanzhen-jian");
        map_skill("sword", "quanzhen-jian");

	prepare_skill("cuff", "chunyang-quan");
        prepare_skill("strike", "sanhua-juding");

        set("class","taoist");

        create_family("全真教", 2, "弟子、掌教真人");

        setup();
        }
        else {
        set_name("丘处机", ({ "qiu chuji", "qiu" }));
        set("nickname", "长春子");
        set("long",
                "他就是全真七子中最负盛名的丘处机，道号长春子，现任全真教掌教真人。\n"
                "他已年近七十，身材魁梧，满脸红光，气宇不凡。\n");
        set("gender", "男性");
        set("age", 69);
        set("attitude", "heroic");
        set("shen_type", 1);
        set("str", 27);
        set("int", 25);
        set("con", 25);
        set("dex", 26);

        set("max_qi", 5000);
        set("max_jing", 3100);
        set("neili", 3800);
        set("max_neili", 3800);
        set("jiali", 80);
        set("combat_exp", 1800000);
        set("score", 5000);

        set_skill("force", 300);
        set_skill("dodge", 300);
        set_skill("parry", 300);
        set_skill("sword", 320);
        set_skill("strike", 300);
        set_skill("cuff", 300);
        set_skill("beidou-zhenfa", 300);

        set_skill("xiantian-gong", 300);
        set_skill("jinyangong", 300);
        set_skill("chunyang-quan", 300);
        set_skill("sanhua-juding", 300);
        set_skill("quanzhen-jian", 320);

        set_skill("literate", 300);
        set_skill("taoism", 300);

        map_skill("force", "xiantian-gong");
        map_skill("dodge", "jinyangong");
        map_skill("cuff", "chunyang-quan");
        map_skill("strike", "sanhua-juding");
        map_skill("parry", "quanzhen-jian");
        map_skill("sword", "quanzhen-jian");

        prepare_skill("cuff", "chunyang-quan");
        prepare_skill("strike", "sanhua-juding");

        set("class","taoist");

        create_family("全真教", 2, "弟子、掌教真人");
                 setup();
                 clear_condition();
        }

        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
               (: auto_perform :),
        }));
        set("chat_chance", 3);
        set("chat_msg",({
               (: auto_check :),
        }));

        set("inquiry", ([
                "报仇" : (: ask_me_revenge :),
                "baochou" : (: ask_me_revenge :),
                "秘籍" : (: ask_me :),
                "miji" : (: ask_me :),
                "任务" : (: ask_job :),
                "job" : (: ask_job :),
                "纯阳神通功": "纯阳神通功是本门第一绝技，可惜我辈愚昧不堪，都没有练成。",
                "王重阳": "先师的名讳岂是可以随便说的？",
                "欧阳锋": "西毒欧阳锋一身是毒，为害武林。谁若能将他除去，必可告慰祖师爷。",
                "西毒": "西毒欧阳锋一身是毒，为害武林。谁若能将他除去，必可告慰祖师爷。",
                "祖师爷" : (: ask_me2 :),
                "还俗" : (:ask_huansu:),
        ]));
        set("book_count", 1);
        set_temp("job_pos",10);
        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/d/wudang/obj/greyrobe")->wear();
}


init()
{
        object ob = this_player();

        ::init();
        if( interactive(ob))
        {
	        if( ob->query("id") == query_temp("target/id") )
                {
         	        do_kill(ob);
                 }
        }

        add_action("do_name", "复仇");
        add_action("do_name", "fuchou");
        add_action("do_kill_sb","kill");
        add_action("do_kill_sb","hit");
        add_action("do_throw","throw");
        add_action("do_inquiry", "inquiry");
}


int do_throw(string arg)
{
        object victim, ob1, ob, me = this_player();
        string what, who;

      	if( !arg || sscanf(arg, "%s at %s", what, who)!=2)
        	return notify_fail("命令格式: throw <物品> at <某人>。\n");
        ob = present(what, me);
        if( !ob ) ob = present(arg, environment(me));
        if( !ob ) return notify_fail("你要扔什么？\n");

        if (ob->query("no_drop"))
                  return notify_fail("这个东西不能离开你。\n");

        if (!(victim = present(who, environment(me))))
                  return notify_fail("这里没有你的目标。\n");

        if (!victim) return notify_fail("这里并无此人！\n");

        if (!living(victim)) return notify_fail("这不是活物！\n");

        if ( victim->query("id") == me->query("id")  ) {
        	return notify_fail("自己杀自己？\n");
        }

        if ( victim->query("family/family_name") == "全真教"  && victim != this_object() ) {
                message_vision("$n对著$N喝道：「"+RANK_D->query_rude(ob)+"！看招！」\n", victim, me);
                message_vision( "$N一声冷笑：大胆狂徒！竟敢当着我面行凶伤人，当我全真教好欺负么？\n", this_object() );
                this_object()->kill_ob(me);
                return 1;
        }

        return 0;
}


int do_kill_sb(string arg)
{
        object ob, ob1=this_object(), me = this_player();

        if ( !arg || arg == "" ) return 0;

        if ( !ob=present(arg, environment(me)) ) return 0;

        if ( ob->query("id") == me->query("id")  ) {
	        return notify_fail("自己杀自己？\n");
        }

        if ( ob->query("family/family_name") == "全真教"  && ob != this_object() ) {
                 message_vision("$n对著$N喝道：「"+RANK_D->query_rude(ob)+"！今日不是你死就是我活！」\n", ob, me);
                 message_vision("$N一声冷笑：大胆狂徒！竟敢当着我面行凶杀人，当我全真教好欺负么？\n", ob1);
                 ob1->kill_ob(me);
                 return 1;
         }

          //message_vision("$n对著$N喝道：「"+RANK_D->query_rude(ob)+"！今日不是你死就是我活！」\n", ob, me);
         return 0;
}


void attempt_apprentice(object ob)
{
        mapping fam;
        string name,new_name;

        if( mapp(fam = ob->query("family")) && fam["family_name"] != "全真教" )
        {
                command ("say " + RANK_D->query_respect(this_player())
                        + "并非我门中人，习武还是先从各位道长起吧！");
                return;
        }

        if ((int)ob->query_skill("xiantian-gong", 1) < 80) {
                command("say 我全真教乃内家武功，最重视内功心法。");
                command("say " + RANK_D->query_respect(ob) +
                        "是否还应该在玄门先天功上多下点功夫？");
                return;
        }

        if ((int)ob->query("shen") < 50000) {
                command("say 我全真教乃是堂堂名门正派，对弟子要求极严。");
                command("say 在德行方面，" + RANK_D->query_respect(ob) +
                        "是否还做得不够？");
        return;
        }

        command("say 好吧，贫道就收下你了。");
        name = ob->query("name");
        new_name = name[0..01]+"志" + name[4..5];
        command("say 从今以后你就叫做" + new_name + "。");
        ob->set("name",new_name);
        command("recruit " + ob->query("id"));
}

string ask_me()
{
        mapping fam;
        object ob, *obs,ob2 ;

        if (!(fam = this_player()->query("family")) || fam["family_name"] != "全真教")
                return RANK_D->query_respect(this_player()) +
                "与本派素无来往，不知此话从何谈起？";

        if (query("book_count") < 1)
                return "你来晚了，本派的内功心法不在此处。";

        obs = filter_array(children("/d/zhongnan/obj/qz_force"), (: clonep :));
                  if (sizeof(obs) > 5)
                return "你来晚了，本派的内功心法不在此处。";

        ob=new("/d/zhongnan/obj/qz_force");
        ob->move(this_player());
        add("book_count", -1);
        command ("rumor "+this_player()->query("name")+"弄到了一册玄门内功心法。");
        return "好吧，这本「玄门内功心法」你拿回去好好钻研。";
}

string ask_me2()
{
        mapping fam;
        string msg;

        if (!(fam = this_player()->query("family")) || fam["family_name"] != "全真教")
                return RANK_D->query_respect(this_player()) +
                "与本派素无来往，不知此话从何谈起？";

        if( random(7)==3 )
                msg = "祖师爷和古墓派素有渊缘。凡古墓派传人，我等务必善待之。";
        else if( random(7)==3 )
                msg = "祖师爷神功盖世，又是抗金的大英雄。我辈当时时以祖师爷为丰碑。";
        else if( random(7)==3 )
                msg = "祖师爷当年料知西毒欧阳锋一定会不利于全真教，所以设计用纯阳神通功和一阳指废去了欧阳锋的哈蟆功。可惜自己也元气大伤，不幸英年早逝。";
        else if( random(7)==3 )
                msg = "祖师爷的独门绝技是纯阳神通功，可惜我辈愚昧，居然无人能学成。";
        else if( random(7)==3 )
                msg = "西毒欧阳锋一身是毒，为害武林。谁若能将他除去，必可告慰祖师爷。";
        else if( random(7)==2 )
                msg = "祖师爷料知西毒欧阳锋难以对付，所以传下了天罡北斗阵。只要好好练，自可擒拿强敌。";
        else
                msg = "祖师爷当年在第一次华山论剑力败群雄，夺得天下第一的美名。";

        return msg;
}


string ask_job()
{
          mapping job_stat;
          object ob2;
          object ob = this_player();
          object me = this_object();
          object yaochu;
          int good_skill;

          job_stat = ob->query_temp("qz/caiyao");

          if ( ob->query("family/family_name") != "全真教" )
      	  	return "这位"+RANK_D->query_respect(ob)+"非我全真教弟子，岂敢劳烦。\n";

          if( ob->is_busy() ){
                command("hmm "+ob->query("id"));
                return "你还在忙着干别的事呢！\n";
          }


          if(job_stat || ob->query_temp("qz/bdgranted") ){
                command("hmm "+ob->query("id"));
                return "你还没完成任务，就又想要新的？\n";
          }

          ob->start_busy(random(2));
          good_skill = (int)( pow(ob->query("combat_exp")*10,0.33333) * 0.7 ) * 3/2 ;

          if( ob->query("combat_exp") > 20000 && ( (ob->query_skill("sword",1)/2+ob->query_skill("quanzhen-jian",1)) < good_skill ||
                        (ob->query_skill("dodge",1)/2+ob->query_skill("jinyangong",1)) < good_skill ||
                        (ob->query_skill("parry",1)/2+ob->query_skill("quanzhen-jian",1)) < good_skill ) && random(15) > 0
          )
                        {
                        command("say 你去好好练习一下剑法、身法和招架吧！");
                        return "千万不要偷懒！\n";
                        }

          if( ob->query("combat_exp") > 5000 &&
                        ob->query("max_neili") < ob->query_skill("force") * 7
                        )
                        {
                          command("say 你内力不够，去好好打坐一下吧！");
                          return "千万不要偷懒！\n";
                        }

          if( ob->query("combat_exp") > 100000 && !(random(3)==1) && ob->query_skill("quanzhen-jian",1) > 60 )
          {
                  command("nod");
                  command("say 好，最近听说有强敌要进攻我重阳宫。");
                  ob->set_temp("qz/bdgranted",1);
                  return "你去大校场赵志敬那儿好好练习一下「天罡北斗阵」!\n";
          }

          if( ob->query("combat_exp") > 80000 && random(4)==1  && ob->query_skill("quanzhen-jian",1) > 60 )
          {
                  command("nod");
                  command("say 好，最近听说有强敌要进攻我重阳宫。");
                  ob->set_temp("qz/bdgranted",1);
                  return "你去大校场赵志敬那儿好好练习一下「天罡北斗阵」!\n";
          }

          if ( me->query_temp("job_pos") == 0 ) {
                                if(random(8)==1)
                                  me->set_temp("job_pos",1);
                          return "现在没什么要紧的事去作，你去休息吧。\n";
          }

          me->add_temp("job_pos", -1);

          command("nod");
          command("say 好，最近炼丹用的草药都用完了，你去山下树林里去采一些回来。");
          yaochu = present("yao chu",ob );
          if(yaochu)destruct(yaochu);
          ob2 = new("/d/zhongnan/obj/yaochu");
          ob2->move(me);
          ob->set_temp("qz/caiyao",1);
          command("give yao chu to "+ob->query("id"));

          return "早去早回，路上要小心一些！\n";
}

int accept_object(object me, object obj)
{
          object ob = this_player();

          command( "say "+obj->name()+"?");

          if (
          	obj->query("id") == "chuanbei" ||
                obj->query("id") == "fuling" ||
                obj->query("id") == "gouzhi zi" ||
                obj->query("id") == "heshouwu" ||
                obj->query("id") == "huanglian" ||
                obj->query("id") == "jugeng" ||
                obj->query("id") == "jinyin hua" ||
                obj->query("id") == "shengdi"
           ) {

                if ( (ob->query("family/family_name") == "全真教") && (ob->query("id")==obj->query("player"))) {
	                call_out("reward_dest", 1, obj, ob);
                }
                else {
                        call_out("thank_dest", 1, obj, ob);
                }

                return 1;
           }

           if ( obj->query("id") == "ouyang feng" )
           {
           	if ( ob->query("family/family_name") == "全真教" ) {
                	call_out("reward_feng", 1, obj, ob);
                }
                else {
                        call_out("thank_feng", 1, obj, ob);
                }
                return 1;
           }

           command( "hmm" );
           command( "say 你给我这东西做什麽？" );
           return 0;
}

void reward_dest(object obj,object ob)
{
        object yaochu = present("yao chu",this_player() );
        if(yaochu)destruct(yaochu);
        command( "pat "+ob->query("id"));
        command( "say "+ob->query("name")+"干的不错，下去休息一下吧！\n");
        if(ob->query_temp("qz/caiyao",1) )
        {
                ob->delete_temp("qz/caiyao");
                add_temp("job_pos", 1);
        }
        destruct(obj);
}


void thank_dest(object obj,object ob)
{
        command( "jump");
        command( "say 我们很需要这些药材，多谢啦！\n");
	destruct(obj);
}

void reward_feng(object obj,object ob)
{
        object lingpai = present("ling pai",ob );

        command( "jump");
        command( "say 真没想到你能将欧阳锋擒来，太好啦！\n");

        command( "thumb "+ob->query("id"));
        command( "say 虽然欧阳锋作恶多端，不过我道家一向以替天行道，救世渡人为己任，\n若能点化欧阳锋一定功德无量。不如你把他带往后山玉虚洞严加看管。\n");
        command("drop feng");

        if(lingpai)destruct(lingpai);

        lingpai = new("/d/zhongnan/obj/lingpai");

        lingpai->move(this_object());
        lingpai->set("owner",ob->query("id"));

        command("give ling pai to "+ob->query("id"));
        command("say 你替天行道，办事得力，深得我心。现赐你令牌，从今以后本教弟子见你如见本人。\n");
}

void thank_feng(object obj,object ob)
{
        command( "jump");
        command( "say 真没想到你能将欧阳锋擒来，多谢啦！\n");
        destruct(obj);
}


string ask_me_revenge()
{
        object me = this_player();

        if( me->query_temp("asked") )
	        return ("你已经说过了，时候一到，自然会动手。\n");


        command("say 本教一向以行侠仗义为己任。谁杀害你了？快告诉我，如果确实的话我们一定助你申冤报仇！");
        tell_object(me, "请键入：复仇 目标ID or fuchou ID\n");
        me->set_temp("qiuwait",1);
        return ("快点！");
}

void do_destroy(object ob)
{
        if( ob ) destruct(ob);
}

int do_name(string target)
{
        object me, asker,ob;
        int i;
        asker = this_player();
        me = this_object();

        if( asker->query_temp("asked") )
  	      return notify_fail("你已经说过了，时候一到，自然会动手。\n");

        if(me->query("waiting_target"))
              return notify_fail("丘处机说道：我现在正忙着呢！\n");

        if( !this_player()->query_temp("qiuwait") )
              return notify_fail("丘处机说道：不知施主什么意思？\n");

        if( !target || target==" ") return notify_fail("丘处机说道：什么？快告诉我名字\n");

        if( !(ob = find_player(target)) ) {
        	ob = new(USER_OB);
                ob->set("id", target);
                if( !ob->restore() ) {
                	destruct(ob);
                        return notify_fail("丘处机说道：没有这个人。\n");
                                         }
                 }
                 if( this_player()->query("combat_exp") < 10000 )
                 {
                        return notify_fail("丘处机说道：小孩子说的话不算数！\n");
                 }

                 if( ob->query("combat_exp") < this_player()->query("combat_exp")  )
                 {
                         return notify_fail("丘处机说道：这个人武功这么差，你自己不会动手？\n");
                 }

                 if( this_player()->query("combat_exp") >50000 )
                 {
                         return notify_fail("丘处机说道：你武功已经有基础了，该自强不息，努力解决自己的事！\n");
                 }

                 if (ob->is_ghost())
                         return notify_fail("丘处机高兴地说：他已经受到报应死了，老天有眼，贫道也不必出马了。\n");

                 if (ob->query("id") != asker->query_temp("my_killer"))
                         return notify_fail("丘处机摇摇头：此人最近又没杀你。\n");

                  if( asker->query_temp("pking/" + ob->query("id")) ) {
                         command("say 你自己闯的祸，不能怨别人。");
                         return 1;
                  }

                  if( asker->query("PKS") > 20 ) {
                         command("say 你杀人无数，自己解决吧。");
                         return 1;
                  }

                  asker->set_temp("asked",1);

  		  if ( asker->query("family/family_name") != "全真教" && random(3)==1 ) {
                	command("say 这个嘛，贫道要调查清楚才好。你先回去吧！\n");
                	return ;
        	  }

                  set("job/" + time(), target);
                  set("job_time/" + time(), time() );
                  save();

                  log_file("Qiu_Anti_Pker", sprintf("丘处机(qiu chuji) is called by %s(%s) at %s to kill %s(%s) \n",
                                asker->query("name"), asker->query("id"), ctime(time()), ob->query("name"), target ));

                  message("vision", HIG "丘处机笑了笑，说道：好，你放心，贫道会为你复仇。\n"NOR, environment());


                  call_out("do_chase", 1, me);
                  return 1;
}


void full_all(object me)
{
          me->set("eff_jing", (int)me->query("max_jing"));
          me->set("jing", (int)me->query("max_jing"));
          me->set("eff_qi", (int)me->query("max_qi"));
          me->set("qi", (int)me->query("max_qi"));
          me->set("jingli", (int)me->query("max_jingli"));
          me->set("neili", (int)me->query("max_neili"));
          me->set("food", (int)me->max_food_capacity());
          me->set("water", (int)me->max_water_capacity());
          me->set_temp("apply/armor", 120);
          me->set_temp("apply/damage", 50);
          me->set_temp("apply/dodge", 120);
          me->set_temp("apply/attack", 50);
          me->set("env/wimpy",60);
}

int auto_check()
{
          object fae, mengzhu, shangshan;
          string name1, name2,name3;
          object ob, dest;
          mapping job, job_time;
          int i, *times;

          string *parts, *safp = ({
 	         "death",
                 "island",
                 "wizard",
                 "xiakedao",
          });

          if(!( mengzhu = find_living("mengzhu")) )
          	mengzhu = load_object("/clone/npc/meng-zhu");
                name1 = mengzhu->query("winner");

          if(!( shangshan = find_living("shangshan")) )
	        shangshan = load_object("/clone/npc/shang-shan");
                name2 = shangshan->query("winner");

          if(!( fae = find_living("fae")) )
                fae = load_object("/clone/npc/fa-e");
                name3 = fae->query("winner");

          if( !living(this_object()) || is_busy() || is_fighting() )
                return 0;

          if( base_name(environment()) != OFFICE )
                return 0;

          if( query_temp("target/id") )
          {
                ob = find_player(query_temp("target/id"));
                if(ob)
                {
	                message_vision("$N匆匆忙忙离开了。\n", this_object());
                        full_all(this_object());
                        call_out("do_chase", 1);
                         return 1;
                }
           }

           if( !(job = query("job")) )
                return 0;
           job_time = query("job_time");

           times = keys(job_time);
           for(i = 0; i < sizeof(times); i++) {
  	         if( time() < job_time[times[i]] )
        	         continue;
                 if( !(ob = find_player(job[times[i]])) )
                         continue;
                 if( !(dest = environment(ob)) )
                         continue;
                 if( dest->query("no_fight") )
                         continue;
                 parts = explode(base_name(dest), "/");
                 if( parts[0] != "d" )
                 	continue;
                 if( member_array(parts[1], safp) != -1)
                        continue;
                 if( parts[2] == "duchuan" || parts[2] == "ship" || parts[2] == "dache" )
                        continue;
                 if( ob->query("combat_exp") > 800000 && !ob->is_busy() &&!ob->is_fighting() && ob->query("qi")*2 > ob->query("max_qi") &&
 	             ob->query("neili")*5 > ob->query("max_neili"))
                        continue;

                 if( base_name(environment(ob)) == "/d/city/leitai" ) return;

                 if( ob->query("id") == name1 ) //武林盟主
                        continue;
                 if( ob->query("id") == name2 ) //赏善使者
                        continue;
                 if( ob->query("id") == name3 ) //fae使者
                        continue;

                 break;
                 }

                  if( i >= sizeof(times) )
                                         return 0;

                  map_delete(job, times[i]);
                  map_delete(job_time, times[i]);

                  set_temp("target/id", ob->query("id"));
                  set_temp("target/name", ob->query("name"));
	          message_vision("$N匆匆忙忙离开了。\n", this_object());
                  full_all(this_object());
                  remove_call_out("do_chase");
                  call_out("do_chase", 1);
                  return 1;
}


void do_chase()
{
                  object ob = find_player(query_temp("target/id"));

                  if( !objectp(ob) || !environment(ob) )
                  {
                         remove_call_out("waiting");
                         call_out("waiting", 0);
                         return;
                  }
                  move(environment(ob));
}


void do_kill(object ob){

	if( objectp(ob) && present(ob, environment())
            && !environment()->query("no_fight") )
        {
        	message_vision("$N突然出现在你眼前。\n", this_object());
                set_leader(ob);
                command("look " + ob->query("id"));

                message_vision(HIR "$N对$n说道：你作恶多端，贫道我为民除害来了！\n"
                               +RANK_D->query_respect(ob)+"，看招！\n" NOR, this_object(), ob);
                set_leader(ob);
                kill_ob(ob);
                ob->fight_ob(this_object());
                auto_perform();

                remove_call_out("checking");
                call_out("checking", 2);
         } else
         {
                remove_call_out("waiting");
                call_out("waiting", 1);
         }

}


void waiting()
{
	object ob = find_player(query_temp("target/id"));
        object me = this_object();

        if ( me->query("qi") < me->query("max_qi")/2  && me->query("qi") >20)
        {
        	exert_function("recover");
                message_vision("$N说道：好，算你厉害，改日再来领教。\n", this_object());
                message_vision("$N匆匆忙忙离开了。\n", this_object());
                move(OFFICE);
                message("vision", "丘处机走了进来说道：这小子武功高，下次再找他麻烦。\n",
                         environment());

                full_all(this_object());
                return ;
         }

         if ( objectp(ob) )
         {
         	if( ob->is_ghost())
                {
                	delete_temp("target");
                        remove_call_out("do_back");
                        call_out("do_back", 1);
                        return;
                 }else if( is_fighting() && present(ob, environment()))
                 {
                        remove_call_out("checking");
                        call_out("checking", 1);
                        return;
                 }else if( living(this_object()) && !environment(ob)->query("no_fight") && !is_busy() )
                 {
                        if ( me->query("eff_qi")*3 < me->query("max_qi")*2 )
                        exert_function("heal");
                        remove_call_out("do_chase");
                        call_out("do_chase", 2);
                        return;
                  }
         }
         else
         {
                  message_vision("$N说道：这小子溜的快，下次再找他麻烦。\n", this_object());
                  message_vision("$N匆匆忙忙离开了。\n", this_object());
                  move(OFFICE);
                  message("vision", "丘处机走了进来，说道：这小子溜的快，下次再找他麻烦。\n",
                  environment());
                  return;
         }

         remove_call_out("waiting");
         call_out("waiting", 20);
}

void checking()
{
                  object ob,me;
                  me = this_object();

                  ob = find_player(query_temp("target/id"));
                 if ( me->query("qi") < me->query("max_qi")/2  && me->query("qi") > 20)
                 {
                                exert_function("recover");
                                message_vision("$N说道：好，算你武功高，改日再来领教。\n", this_object());
                                message_vision("$N匆匆忙忙离开了。\n", this_object());
                                move(OFFICE);
                                message("vision", "丘处机走了进来，说道：这小子武功高，下次再找他麻烦。\n",
                                         environment());

                                full_all(this_object());
                                return ;
                 }

                  if(!ob)
                  {
                                message_vision("$N说道：这小子溜的快，下次再找他麻烦。\n", this_object());
                                message_vision("$N匆匆忙忙离开了。\n", this_object());
                                move(OFFICE);
                                message("vision", "丘处机走了进来，说道：这小子溜的快，下次再找他麻烦。\n",
                                         environment());
                          return;
                  }

                  if( is_fighting() ) {
                                         auto_perform();
                                         remove_call_out("checking");
                                         call_out("checking", 2);
                                         return;
                  }

                  if( objectp(ob = present("corpse", environment()) )
                  && ob->query("victim_name") ==  query_temp("target/name") )
                  {
                        
                 delete_temp("target/id");
                                         delete_temp("target/name");
                                         delete_temp("target");
                                         remove_call_out("do_back");
                                         call_out("do_back", 1);
                                         return;
                  }

                  remove_call_out("waiting");
                  call_out("waiting", 1);
}

void do_back()
{
                object me = this_object();
                message_vision("$N匆匆忙忙离开了。\n", this_object());
                move(OFFICE);
                message("vision", "丘处机走了进来，笑道：总算又替天行道了一回。\n",
                                         environment());
                me->set_temp("apply/armor", 0);
                me->set_temp("apply/damage", 50);
                me->set_temp("apply/dodge", 0);
                me->set_temp("apply/attack", 0);

                command("follow none");
                save();
}

void die() {
                  object ob,me;

                  me = this_object();
                  if( !living(this_object()) ) {revive(1);reincarnate();}
                  if( base_name(environment()) != OFFICE || query_temp("target/id") == me->query_temp("last_damage_from")->query("id") )
                  {
                          ob = me->query_temp("last_damage_from");
                          if(ob)
                          {
                                 full_all(me);
                                 save();
                          }
                  }
            ::die();
}


int do_inquiry()
{
	object ob, dest, ob2;
        mapping job, job_time;
        int i, *times;
        string *parts, *safp = ({
        	"death",
                "island",
                "wizard",
                "xiakedao",
        });

        ob = this_player();
        if(!wizardp(ob))
        {
        	message_vision("丘处机向$N怒道：你算什么东西，也配来问贫道？\n",ob);
                command("kick "+ob->query("id") );
                return 1;
        }

        if( !living(this_object()) )
        {
                message_vision("丘处机没法回答$N的问题了。\n",ob);
                return 1;
        }

        if( query_temp("target/id") )
        {
        	tell_object(ob, "丘处机告诉你：现在贫道正在追杀"+query_temp("target/name")+"("+ query_temp("target/id")+").\n");
                return 1;
        }

        if( !(job = query("job")) )
        {
                 tell_object(ob, "丘处机告诉你：现在老夫没有任务.\n");
                 return 1;
        }
        
        job_time = query("job_time");

        times = keys(job_time);

        for(i = 0; i < sizeof(times); i++) {
        	tell_object(ob, "丘处机告诉你：有人让我在" + ctime( job_time[times[i]] )+ "杀" + job[times[i]] +".\n");
                if( time() < job_time[times[i]] )
                {
                	tell_object(ob, "丘处机告诉你：不过时间还没到.\n");
                        continue;
                }
                                         
                if( !(ob2 = find_player(job[times[i]])) )
                {
                	tell_object(ob, "丘处机告诉你：不过这家伙不在线上.\n");
                        continue;
                 }

                 if( !(dest = environment(ob2)) )
                 {
                         tell_object(ob, "丘处机告诉你：不过这家伙不知在哪儿.\n");
                         continue;
                  }
                 if( dest->query("no_fight") )
                 {
                          tell_object(ob, "丘处机告诉你：不过这家伙躲在安全地方.\n");
                          continue;
                  }

                  parts = explode(base_name(dest), "/");
                  if( parts[0] != "d" )
                  {
                           tell_object(ob, "丘处机告诉你：不过这家伙在非公众场所.\n");
                           continue;
                   }

                  if( member_array(parts[1], safp) != -1)
                  {
                            tell_object(ob, "丘处机告诉你：不过这家伙在限制地带.\n");
                            continue;
                  }
  
                  if( parts[2] == "duchuan" || parts[2] == "ship" )
                  {
                             tell_object(ob, "丘处机告诉你：不过这家伙在船上.\n");
                             continue;
                  }
                  if(  !ob2->is_busy() &&!ob2->is_fighting() && ob2->query("qi")*2 > ob2->query("max_qi") &&
                        ob2->query("neili")*5 > ob2->query("max_neili")
                        &&  ob2->query("combat_exp") > 800000 )
                  {
     			     tell_object(ob, "丘处机告诉你：不过这家伙武功较高.\n");
                             continue;
 		  }

        	  break;
        	  tell_object(ob, "丘处机告诉你：好，该动手了.\n");
        }

        if( i >= sizeof(times) )
        {
                  tell_object(ob, "丘处机告诉你：暂时都不能动手.\n");
                  return 1;
        }

        auto_check();
        return 1;
}

int auto_perform()
{
        object me = this_object();
        object target = me->select_opponent();
        object weapon = me->query_temp("weapon");

        if ( !me->is_fighting() ) {
                if ( me->query("eff_qi") < me->query("max_qi") )
	                exert_function("heal");
                me->set("jiali", 300);
                return 1;
        }

        if ( !objectp(target)
          || !random( (int)me->query("combat_exp") * 2
                   / (int)target->query("combat_exp") + 1) ) return 0;

        if ( objectp(weapon) && weapon->query("skill_type") == "sword")
        {
                  if( me->query("eff_qi",1) > me->query("max_qi",1)*2/3 )
                        return perform_action("sword.sanqing");
                  else perform_action("sword.tonggui");
        }
        else if ( objectp(weapon) && weapon->query("skill_type") == "whip")
        {
                return perform_action("whip.riyue");
        }
        else
        {
                if( !me->query_temp("sanhua",1) )

                        return perform_action("strike.sanhua");
                else
                        return perform_action("cuff.lianhuan");
        }
}

string ask_huansu()
{
        object ob, me;
        me=this_player();
        ob=this_object();
        
        if (me->query("quit/taoist"))
        {
        command("hmm");
        return "你已经不是出家之人，何来还俗之说？！";
        }
        if (me->query("class") == "bonze" )
        {
        return "这位"+RANK_D->query_respect(me)+"乃佛门中人，还俗一事贫道实在作不了主，请回吧。";
        }
        if (me->query("family/family_name") == "全真教"
        && me->query("class") == "taoist" ){
        command("hmm "+me->query("id"));
        command("look "+me->query("id"));
        command("sigh "+me->query("id"));
        add_action("do_jueding", "决定了");
        me->set_temp("pending/quit_taoist", 1);
        return ""+RANK_D->query_respect(me)+"既然尘缘未了，贫道也不便强留，但如果"+RANK_D->query_respect(me)+
               "决定了要还俗，道学心法和学识会大打折扣，请"+RANK_D->query_respect(me)+"三思。决定了再告诉贫道吧。"
               "(type 决定了)";
        
        }
        else {
        return ""+RANK_D->query_respect(me)+"非我道中人，请恕贫道无能为力。";
        }
}

int do_jueding()
{
        object ob, me;
        me=this_player();
        ob=this_object();
        
        if(!me->query_temp("pending/quit_taoist"))
        return 0;
        message_vision("$N恭恭敬敬地跪了下来，$n对$N叹了口气。\n\n"
                       "$n把$N头上的发髻拆了下来，再帮$N梳上了俗装，又给了$N一件布衣。\n\n",me,ob);
        command("ok");
        command("say 从现在起你就是俗家弟子了。");
        me->delete("class", "taoist");
        ob=new("clone/misc/cloth.c");
        ob->move(me);
        me->delete_temp("pending/quit_taoist");
        me->set_skill("taoism", me->query_skill("taoism")*2/3);
        me->set_skill("literate", me->query_skill("literate")*2/3);
        write(HIY"你的道学心法降低了！你的读书写字降低了！\n"NOR);
        me->set("quit/taoist", 1);
        return 1;
        
}
