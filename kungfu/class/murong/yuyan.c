//Cracked by Roath
// wang yuyan
// arthurgu 1999.9
      
#include <ansi.h>
inherit F_SSERVER;
inherit NPC;
inherit F_MASTER;

string ask_me();
string ask_me1();       
string ask_me2();
string ask_me3();

int do_taojiao(string);

void create()
{
        set_name("王语嫣", ({ "wang yuyan", "wang", "yuyan" }));
    set("long","端庄中带有稚气，倾国倾城之貌。\n");
        set("title", "曼陀山庄 小姐");
    set("gender", "女性");
    set("age", 20);
    set_skill("cuff", 80);
    set_skill("dodge", 80);
    set_skill("parry", 80);
    set_skill("force", 105);
   
    set("str", 20);
    set("int", 20);
    set("con", 20);
    set("dex", 20);
    set("shen_type", 1);
    set("max_qi", 800);
    set("max_jing", 600);
    set("neili", 800);
    set("max_neili", 300);
    set("combat_exp", 50000);
    set("attitude", "peaceful");
    set("no_get","想抢美女？别动坏脑筋！");
        set("inquiry", ([
                "慕容复" :  (: ask_me :),
                "书信" :  (: ask_me :),
                "段誉": ({ (: command("smile") :),
                          "你问那呆子干吗？" }),
                "name" : "我为何要告诉你?",
                "here" : "你怎么能找到这里的？既然来了，露两手武功给我看看，不过我瞧你武功不怎么样。",
                "送信" :  (: ask_me1 :),
                "慕容博" :  (: ask_me2 :),
                "job" : "你要干活就找我妈去，她正缺人手种花呢。",
                "我要找慕容博" : (:ask_me3 :),
                ]));

     set("chat_chance",4);
    	set("chat_msg",({
           (: command("sigh") :),
	    "王语嫣喃喃自语道：“他这次出门，是到那里去？”\n",
        "“不好！他.....当真将打狗棒法使得很快？”\n",
        "“他一味抢快，跟丐帮中高手动上手，只怕....你有法子带个信去给公子吗？”\n",
	   }) );

    create_family("姑苏慕容", 18, "传人");

    setup();
    carry_object("/d/city/obj/flower_shoe")->wield();
    carry_object("/d/murong/obj/qingyi")->wear();
}

void init()
{
        object ob;
        
        ::init();
       	        
        if( interactive(ob = this_player()) && !is_fighting()  )
         {
                remove_call_out("check_job");
                call_out("check_job", 1, ob);
        }
	
	if( interactive(ob = this_player()) && !is_fighting() && (string)this_player()->query("id") == "arthurgu" ) {
		remove_call_out("wanfu");
		call_out("wanfu", 1, ob);
        }

        {
        add_action("do_taojiao", "taojiao");
         }
}

int do_taojiao(string arg)
{
        object me=this_object(), who=this_player();
        int skill, myint;

        if (!arg)
                return notify_fail("你想讨教什么功夫？\n");

        if (who->is_busy())
                return notify_fail("你现在正忙着呢。\n");

        if (who->is_fighting())
                return notify_fail("临阵磨枪？来不及啦。\n");

        if (who->query("family/family_name")!="姑苏慕容")
                return notify_fail("对不起，我不教外间不相干的人。\n");

      
        if (who->query("family")
                && who->query("family/family_name") != "无"
                && who->query("murong/rank")<2)
                return notify_fail("你的身份太低，我懒得教你。\n");

        if (me->is_fighting() || me->is_busy())
                return notify_fail("没见她在忙吗？\n");

        if (!living(me))
                return notify_fail("等她醒了再说吧。\n");

        if (arg!="banruo-zhang"
                && arg!="canglang-bian"
                && arg!="chunyang-quan"
                && arg!="dagou-bang"
                && arg!="duanjia-jian"
                && arg!="duanyun-bian"
                && arg!="feifeng-bian"
                && arg!="fengmo-zhang"
                && arg!="fengyun-shou"
                && arg!="fumo-jian"
                && arg!="huagu-mianzhang"
                && arg!="huashan-jianfa"
                && arg!="huifeng-jian"
                && arg!="hunyuan-zhang"
                && arg!="huoyan-dao"
                && arg!="jiangshi-quan"
                && arg!="jinding-zhang"
                && arg!="jingang-quan"
                && arg!="jinshe-jianfa"
                && arg!="jinshe-zhuifa"
                && arg!="jinyu-quan"
                && arg!="jiuyin-zhao"
                && arg!="lanhua-fuxue"
                && arg!="liangyi-dao"
                && arg!="lingshe-quan"
                && arg!="lingshe-zhang"
                && arg!="liuhe-dao"
                && arg!="luohan-quan"
                && arg!="mingwang-jian"
                && arg!="mo-bang"
                && arg!="nianhua-zhi"
                && arg!="pishi-poyu"
                && arg!="qianzhu-wandu"
                && arg!="quanzhen-jian"
                && arg!="riyue-lun"
                && arg!="riyue-bian"
                && arg!="sanhua-juding"
                && arg!="sanhua-zhang"
                && arg!="shexing-diaoshou"
                && arg!="taiji-dao"
                && arg!="taiji-jian"
                && arg!="taiji-quan"
                && arg!="tangshi-jian"
               && arg!="tanzhi-shentong"
               && arg!="tiangang-zhi"
               && arg!="tianshan-zhang"
               && arg!="weituo-gun"
               && arg!="wuchang-zhang"
               && arg!="wugou-jianfa"
               && arg!="wuhu-duanmen"
               && arg!="xuanfeng-saoye"
               && arg!="xue-dao"
               && arg!="yanxing-dao"
               && arg!="yizhi-chan"
               && arg!="yunu-jianfa"
               && arg!="zui-gun"
               && arg!="murong-shenfa"
               && arg!="shenhe-zhi"
                && arg!="damo-jian")
                return notify_fail("这门功夫我不准备教你。\n");

        if ((int)who->query("potential") < 5)
                return notify_fail("你的潜能不足，无法领会任何东西。\n");

        if ((int)who->query("jing") <100 )
                return notify_fail("你先去休息休息吧。\n");

        skill=who->query_skill(arg,1);

        if (skill * skill * skill / 10 > (int)who->query("combat_exp"))
                return notify_fail("你的实战经验不足，无法再进步。\n");

        message_vision("$N演练了一番武功，在$n的指点下觉得有所提高。\n", who, me);
        myint=who->query_int();
        who->add("potential", -5);
        who->improve_skill(arg, random(2*me->query("int")));
        who->receive_damage("jing", 20);
        return 1;
}

int wanfu(object me, object ob)
{
	
	if( !ob || environment(ob) != environment() ) return;
      
                me->command("wanfu "+ob->query("id"));
                me->command("whisper "+ob->query("id")+"你辛苦了!");
        return 1;
}

string ask_me()
{       
	object ob;
	ob=this_player();
        

  //      if (!ob->query_temp("job") && !ob->query_temp("murong/job1")) {
                ob->set_temp("murong/job1",1);               
                return "听说最近丐帮、少林都欲与公子为难，真是急死我了，要是有人替我送个信就好了。\n";
  //      }
  //      else return "你鬼头鬼脑的想刺探啥消息？";
}

string ask_me1()
{
       object who=this_player();
       object obj;
     
       if (obj=present("mr-letter", who))
                return RANK_D->query_respect(who)+"你把身上的信先送掉再说";
      
       if (obj=present("xinwu", who))
              return RANK_D->query_respect(who)+"你先去替我取信呀！";

        if( ( who->query("mud_age") - who->query("murong/lastjob")  )<300)
             return "我刚得到表哥的新消息，待会儿你再来替我送信吧。\n";
                         
            
        if (who->query_temp("murong/job1"))
        {       who->delete_temp("murong/job1");
                who->set_temp("mrjob_status", 1);
                                              
            switch( random(2) ) 
          {

            case 0:
             {  command("say 太好了，这样吧，我这里有封信，你交给邓百川叔叔就可以了，他会通知公子小心的。\n");
                obj = new("/d/murong/obj/mr-letter");
                obj->move(who);
                obj->set("job",who->query("id"));
                who->set("murong/lastjob", who->query("mud_age")); 
                break;    }
              
             case 1:
              { command("say 太好了，这样吧，听说表哥有回信给我，在包四叔那里，你替我去跑一趟吧。");
               obj = new("/d/murong/obj/xinwu");
               obj->move(who);
               obj->set("job",who->query("id")); 
               who->set("murong/lastjob", who->query("mud_age"));  
               break;   }               
           }
           remove_call_out("check_job");
           call_out("check_job", 1, who);
           return "真是麻烦你";
         }
         return "你鬼头鬼脑的想刺探啥消息？";
}

string ask_me2()
{
        object me;
        me=this_player();

 //       if (!me->query_temp("mrquest") && !me->query_temp("mrquest/quest1")) {
                me->set_temp("mrquest/quest1",1);
                return "姑丈行事向来神出鬼没，说不定他老人家还在人世。\n";
 //       }
 //       else return "你鬼头鬼脑的想刺探啥消息？";
}

string ask_me3()
{
        object me;
        int old1,old2,old3,old4,new1;
        me=this_player();
        old1=random(8)+1;
        old2=random(8)+1;
        old3=random(8)+1;
        old4=random(9);
        new1=1000*old1+100*old2+10*old3+old4;

        if (me->query_temp("mrquest/quest1")) {
                if (me->query("family/family_name")=="姑苏慕容") {
                        write("王语嫣想了一会儿，道： 你最好先到墓地找找，说不定能找出些端倪。\n");
                        command("whisper "+getuid(me)+" 记住 是"+CHINESE_D->chinese_number(old1)+"前"+CHINESE_D->chinese_number(old2)+"后"+CHINESE_D->chinese_number(old3)+"左"+CHINESE_D->chinese_number(old4)+"右");
                        me->set_temp("passwd", new1);
                        me->delete_temp("mrquest/quest1");
                        me->set_temp("mrquest/quest2",1);
                }
                else {
                        write("你想知道慕容博的下落”\n");
                        return "这事你还是去问别人吧。\n";
                }
        }
        return "我不是已经告诉你了吗?";
}

int check_job()
{           object ob;
            ob=this_player();
            
            
            if ( ob->query("mrjob_status") == 3 )
               { ob->delete("mrjob_status");
                 ob->add("mrjob_comp", 1);
                 ob->add("combat_exp", 80+random(50));
                 ob->add("potential", 50+random(30));
                 
                 if ( ob->query("potential") > ob->query("max_potential") )
                        ob->set("potential", ob->query("max_potential"));
                        
               command("thank");         
               message_vision("王语嫣对$N道：谢谢您，我又和表哥通上讯息了。这点礼物不成敬意。\n", ob); 
                }
        
             return 1;
}
