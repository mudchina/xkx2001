//Cracked by Roath
// sample master.c code
// modified by xxx@xkx 01.01 for shexin quest

#include <ansi.h>

#define NEED_MONEY 20000000      // need 2k gold!!! 我真是狮子大开口。
#define ACCEPT_SPECIAL_OBJECT    // For npc accept special object.
#define PENG_EMOTE 13

inherit NPC;
inherit F_MASTER;

string *moreMsg = ({
  "彭有敬顿了一顿，又对$N嬉皮笑脸地说道：“不过，你应该多孝敬点儿给我。”\n",
  "彭有敬顿了顿，马上板起了脸，对$N说道：“你不觉得你孝敬得少了点吗？”\n",
  "彭有敬打了个哈欠，无聊地对$N说道：“你怎么这么没有"HIY"钱"NOR+CYN"途？”\n",
  "彭有敬望着$N忍俊不禁，纵声大笑道：这么少钱，你不是癞蛤蟆想去吃天鹅肉吗？哈哈，笑死人了！\n",
});

string *Pengemote = ({ "kick ", "kick2 ", "kick3 ", "consider ", "slap ", "slap2 ", "slap3", "smash ", "cut ", "hammer ", "sneer ", "hate ", "idle " });

string ask_me();
int accept_special_object(object ob, object obj); // for GOLD !!!!!
private void notEnough(object);
private void enough(object);
private void teachSheXin(object);
private void pengsResponse(object me);
private void recoverPeng(int pExp, int pSkill, object me);

void create()
{
        set_name("彭有敬", ({"peng youjing", "peng", "youjing"}));
        set("title", "丐帮九袋长老");
        set("nickname", "掌钵龙头");
        set("gender", "男性");
        set("age", 50);
        set("long", 
                "彭有敬是丐帮中净衣派的首领，衣着乾净华丽，不象叫化子。\n"
                "他脸上挂着慈祥的笑容，一双眼睛有摄人心魄的力量。\n");

        set("accept_special_object", 1);  // Allow this NPC call accept_special_object().
        set("attitude", "peaceful");
        set("GB_SheXin_OK", 1);
        set("str", 24);
        set("int", 20);
        set("con", 24);
        set("dex", 20);

        set("rank", 9);

        set("qi", 1200);
        set("max_qi", 1200);
        set("jing", 700);
        set("max_jing", 700);
        set("neili", 8000);
        set("max_neili", 8000);
        set("jiali", 100);
        
        set("combat_exp", 300000);
        set("score", 20000);
     
   
        set_skill("force", 120);
        set_skill("huntian-qigong", 120); 
        set_skill("hand", 105); 
        set_skill("shexing-diaoshou", 100); 
        set_skill("dodge", 125);
        set_skill("xiaoyaoyou", 105);
        set_skill("parry", 120);
        set_skill("stick", 120);
        set_skill("digging", 100);
        
        map_skill("force", "huntian-qigong");
        map_skill("hand", "shexing-diaoshou");
        map_skill("dodge", "xiaoyaoyou");
        
        prepare_skill("hand", "shexing-diaoshou");

        create_family("丐帮", 18, "九袋长老");
        
        set("inquiry", ([      
        "慑心术"   : (: ask_me() :),
        "净衣派"   : "我们净衣派可比污衣派有派头，风光多了。\n",
        "钱"       : "钱。。。。。。。。。。。。\n彭有敬吞了吞口水。\n",
        "岳阳楼"   : "那是一间很有名的酒楼，可惜价钱比较贵。\n",
        "黄蓉"     : "黄蓉？还不是栽在我手里？\n",
        "郭靖"     : "郭靖？还不是栽在我手里？\n",
        "秘技"     : "我的秘技？就是慑心术。\n",
        "君山大会" : "君山大会。。。幸好我有慑心术。\n彭有敬面露怯色，好像害怕什么。\n",
        "黄金"     : "黄金。。。。。。。。。。。。\n彭有敬吞了吞口水。\n",
        "独门秘技" : "我的独门秘技其实有很多呀。\n彭有敬「嘿嘿嘿」奸笑了几声。",
        "金子"     : "黄金。。。。。。。。。。。。\n彭有敬吞了吞口水。\n",
        "德高望重" : "这慑心术这么卑鄙，如果你太德高望重，也不好意思学吧？\n",
        ])); 

        setup();

        carry_object("/d/gaibang/obj/budai")->set_amount(8);
        carry_object("/d/gaibang/obj/budai")->wear();
}

void init()
{
  ::init();
  add_action("do_kick", "kick");
  add_action("do_kick", "kick2");
  add_action("do_kick", "kick3");
  add_action("do_kick", "kick4");
  add_action("do_kick", "kick5");
  add_action("do_kick", "slap");
  add_action("do_kick", "slap2");
  add_action("do_kick", "slap3");
  add_action("do_kick", "smash");
  add_action("do_kick", "hammer");
  add_action("do_kick", "idle");
  add_action("do_kick", "bored");
  add_action("do_kick", "grin");
  add_action("do_kick", "ugly");
  add_action("do_kick", "cut");
  add_action("do_kick", "bite");
  add_action("do_kick", "rob");
  add_action("do_kick", "slogan");
  add_action("do_kick", "sneer");
  add_action("do_kick", "consider");
}

void attempt_apprentice(object ob)
{
        if( ob->query("family") && ob->query("family/family_name") != "丐帮" ) {
                command("say 你不是丐帮弟子，老夫不能收你。" + RANK_D->query_respect(ob) + "还是请回吧。");
                return;
        }

        if( ob->query("combat_exp") < 1000 ) {
                command("say 你似乎还没学过什么功夫吧。");
                command("say 你不如先去武馆或其他丐帮弟子那里学些基本功再回头来找我。");
                return;
        }

        if( !ob->query("family") ) {
                command("say 好吧，希望" + RANK_D->query_respect(ob) + "能好好学习本门武功，将来在江湖中闯出一番作为。");
                ob->set("rank", 1); 
                command("recruit " + ob->query("id"));
                ob->set("title", "丐帮一袋弟子");
        } 

        else {
                ob->set_temp("title", ob->query("title"));
                command("recruit " + ob->query("id"));
                ob->set("title", ob->query_temp("title"));
                ob->delete_temp("title");
        }

        return;
}

string ask_me()
{
  object who = this_player();
  int pExp;
  int pSkill;

  if( who->is_busy() ){
    return ;
  }

  if(who->query("GB_SheXin_OK")) {
    command("grin");
    command("congra " + who->query("id") );
    return "“你如今可是如虎添翼了！”";
  }
  
  if( !who->query("GB_SheXin_PAY") && !who->query("GB_SheXin_OK") )
    who->set("GB_SheXin_PAY", 1);
    
  command("hehe " + who->query("id"));
  
  if( ! random(5) ) {
    command("say 慑心术？好，我让你见识见识什么是慑心术！！！\n");
    pExp = query("combat_exp");   
    pSkill = query_skill("huntian-qigong");
    set("combat_exp", 10000000);
    set_skill("huntian-qigong", 400);
    command("yun shexin " + who->query("id") );
    call_out("recoverPeng", 2, pExp, pSkill, who);
  }
  
  if( !random(10)) return "慑心术是我的独门秘技。如果你孝敬我的话。。。。”\n";
  else return "“慑心术能慑人之心神。当年在洞庭湖岳阳楼，黄蓉和郭靖就因此栽在我手里。\n"+
              "而这慑心术则是我的独门秘技。”\n";
}

private void recoverPeng(int pExp, int pSkill, object me)
{
    set("combat_exp", pExp);
    set_skill("huntian-qigong", pSkill);
    command("get gold from " + me->query("id") );
    command("hehe " + me->query("id"));
}

int accept_special_object(object me, object money)
{
  // For 慑心术。
  
  if(!money->query("money_id")) {
    tell_object(me, CYN"彭有敬奸笑地说：“嘿嘿，我对这个没有什么兴趣。”\n"NOR);
    return 0;
  }
  
  if(!me->query("GB_SheXin_PAY") && !me->query("GB_SheXin_OK")) {
    tell_object(me, CYN"彭有敬奸笑地说：“无端端地，干吗对我献殷勤？”\n"NOR);
    return 0;
  }
  
  if(me->query("shen") > 150000) {
    tell_object(me, CYN"彭有敬吓得茶碗一下子打掉在地，对你颤声道：「这，这，这。。。\n"
    "你这么德高望重，无端端给我钱，可不是开玩笑吗？」 \n"NOR);
    return 0;
  }
  
  if(money->query("id") != "gold") {
    tell_object(me, CYN"彭有敬阴笑地说：“嘿嘿，"+money->query("name")+
      NOR + CYN"的成色这么差，你怎好意思拿来孝敬我？”\n"NOR);
    return 0;
  }
   
  if( me->query("GB_SheXin_OK")) {
    if(random(2) )
      say( CYN"彭有敬点头哈腰地笑道：“" + me->query("name")+ RANK_D->query_respect(me) + 
          "的好处，我今生今世，永不敢忘。不过够了，已经够了。”\n"NOR);
    else {
      say( CYN"彭有敬点头微笑道：“多谢了！不过够了，已经够了”\n"NOR);
      command("rich");
    }

    return 1;
  }

  if(random(2))
    command("joythank " + me->query("id"));
  else
    say(CYN"彭有敬数着钱袋里的金子，“一块，两块，... ，... ” 似乎脸上的每一块肉都在笑。\n"NOR);

  if(!me->query("family/family_name") || me->query("family/family_name") != "丐帮")
    return 1;
    
  if( me->query("GB_SheXin_PAY") > 10000000 && !random(5) ) 
    say( CYN"彭有敬点头微笑道：“如果有一两千黄金，我这辈子就不用愁了。。\n"NOR);
  me->add("GB_SheXin_PAY", money->value());

  if( me->query("GB_SheXin_PAY") < NEED_MONEY) {
    remove_call_out("notEnough");
    call_out("notEnough", 2, me);
  }
  
  else
    call_out("enough", 2, me);
  
  return 1;
}

private void notEnough(object me)
{
  message_vision(CYN + moreMsg[random(4)] + NOR, me);
  return;
}

private void enough(object me)
{
  message_vision(CYN"彭有敬顿了一顿，又对$N兴高采烈地说道：“看你这么有" + 
      HIY"钱"NOR + CYN"途。。。\n"
      "好！我就传授你我的独门秘技－慑心术！\n\n"NOR, me);
  call_out("teachSheXin", 1, me);
  return;
}

private void teachSheXin(object me)
{
  command("whisper " + me->query("id") + " 你要如此如此，这般这般。。。");
  tell_object( me, "\n你学会了慑心术！！！\n"NOR);
  me->delete("GB_SheXin_PAY");
  me->set("GB_SheXin_OK", 1);
  return;
}

int do_kick(string arg)
{
  if (!arg || (arg != "peng youjing" && arg != "peng" && arg != "youjing") )
    return 0;

  call_out("pengsResponse", 1, this_player() );
  return 0;
}

private void pengsResponse(object me)
{
  int pExp, pSkill;
  
  command( Pengemote[random(PENG_EMOTE)] + me->query("id") );

  if(!random(6)) {
    pExp = query("combat_exp");   
    pSkill = query_skill("huntian-qigong");
    set("combat_exp", 10000000);
    set_skill("huntian-qigong", 400);
    command("yun shexin " + me->query("id") );
    call_out("recoverPeng", 2, pExp, pSkill, me);
  }
  return;
}

#include "/kungfu/class/gaibang/promote.h"