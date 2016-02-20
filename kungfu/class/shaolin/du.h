//Cracked by Roath
// du.h for fight and apprentice Du
//modified by xiaojian for not attacking outside fmq on Nov18,2000

#include <ansi.h>

void init()
{
  object me, ob, room1, room2;
  mapping fam;
  string name;

  me = this_player();
  ob = this_object();
  name = this_player()->query("name") ;

  if(!( room1 = find_object("/d/shaolin/fumoquan")) );
  room1 = load_object("/d/shaolin/fumoquan");

  if(!( room2 = find_object("/d/shaolin/dmyuan2")) );
  room2 = load_object("/d/shaolin/dmyuan2");

  ::init();
  if( interactive(me) ) 
    {
      if ( mapp(fam = me->query("family")) && fam["family_name"] == "少林派" 
	   && fam["generation"] <= 37 && (name[0..1] == "玄" || name[0..1] == "渡")) {
	me->set_temp("fighter", 1);
	return;
      }
 
      if ( me->query_temp("calling") )
	{
	  if( environment(me) == room1 && present(me, room1) ) {
	    say(ob->name() + "说道：你怎么不听玄辈大师的吩咐，擅自闯到这里来！ 还不给我滚出去！\n");
	    message_vision("$N说完衣袖一卷，一股猛烈无比的罡风把$n直推了出去！\n", ob, me);
	    call_out("move_out", 1, me);
	  }
	  else if( environment(me) == room2 && present(me, room2) ) {
	    message_vision("\n只见灰影一闪，一位老僧忽然出现在$N的面前，对着玄悲合什为礼。\n\n", me);
	    message_vision("$N走上来，冲着$n端详了半饷，点了点头，说道：想拜我为师可不容易啊！\n" +
			   "我有个规矩，能在我手底下走出十招的，才有资格做我们的徒弟，你愿意的话，" +
			   "就说(answer)一声。\n", ob, me);
	    me->delete_temp("calling");
	    me->set_temp("testing", 1);
	    add_action("do_say", "answer");
	    return;
	  }
	}
      else if( environment(me) == room2 && present(me, room2) ) return;

      if ( mapp(fam = me->query("family")) && fam["family_name"] == "少林派" 
	   && fam["generation"] > 36               
	   && me->query("qi") < 50) 
	{
	  me->unconcious();
	  call_out("move_out", 1, me);
	  return;
	}
	//check condition to see if 3 du is in fmq or sjsz,if not,no attack
	//xiaojian
	  if(environment(ob) != room1 && strsrch(base_name(environment(me)),"/d/bwdh/sjsz")!= 0)
		  return;
      COMBAT_D->do_attack(ob, me, query_temp("weapon") );
		
      me->set_temp("fighter", 1);

      ob->fight_ob(me);
      me->fight_ob(ob);

      call_out("halt", 10);

      return;
    }
  return;
}

void debug(string s)
{
  // message_vision("debug $N: "+s+"\n", this_object());
}

int do_say(string arg)
{
  object me, ob;
  int i, count;

  me = this_player();
  ob = this_object();
		
  debug("do_say "+arg);
  if( !arg || arg=="" ) return 0;

  debug("checking args");
  if( arg=="愿意" && me->query_temp("testing")) {

    debug("checking armor");
    if( this_player()->query_temp("apply/armor") >= 100 
	||  this_player()->query_temp("apply/damage") >= 100)
      return notify_fail("渡厄摇头道：你身带利器宝甲，不能参加试招！\n");

    message_vision("渡厄点点头，说道：好，我出招了！\n\n", me);

    for(i=0; i<10; i++) 
      {
	COMBAT_D->do_attack(ob, me, ob->query_temp("weapon"));
	if( me->query("qi") >= 10 ) count++;
	else break;
      }

    if( count >= 7 ) {
      message_vision("\n渡厄长笑一声，说道：不错不错，是个可教之才！ 我就成全了你吧！\n\n", me);
      me->set_temp("apprentice_ok", 1);
    }
    else    message_vision("\n渡厄笑道：小子勇气可嘉，异日必能有所造诣，今日不成，望加倍努力！\n\n", me);

    me->delete_temp("testing");

    call_out("leaving", 1, ob, 0, 900);

    return 1;
  }
}

int leaving(object ob, int time, int ready)
{       
  if ( time < ready ) {
    time = time + 100;
    call_out("leaving", 100, ob, time, ready);
    return 1;
  }
  else {
    message_vision( "$N点点头，说道：此间事已了，我去了。\n" + 
		    "他说罢大袖飘飘，扬长而出，只一会便消失了踪迹。\n", ob);
    ob->move("/d/shaolin/fumoquan");
    return 1;
  }       
}

void attempt_apprentice(object ob)
{
  object me, zi; 
  mapping ob_fam, my_fam;
  string name, new_name;

  me = this_object();
  my_fam  = me->query("family");

  name = ob->query("name");

  if (!(ob_fam = ob->query("family")) || ob_fam["family_name"] != "少林派")
    {
      command("say " + RANK_D->query_respect(ob) + "与本派素无来往，不知此话从何谈起？");
      return;
    }

  if ( (string)ob->query("class")!="bonze" && ob_fam["family_name"] == "少林派") 
    {
      command("say " + RANK_D->query_respect(ob) + "是俗家弟子，不能在寺内学艺。");
      return;
    }

  if ( ob_fam["generation"] <= my_fam["generation"] )
    {
      command("say " + RANK_D->query_respect(ob) + "，贫僧哪里敢当 !");
      return;
    }

  if ( ob_fam["generation"] == (my_fam["generation"] + 1) || name[0..1] == "玄")
    {
      command("say " + ob_fam["master_name"] + "的徒弟怎么跑到我这儿来了，哈哈哈 !");
      command("recruit " + ob->query("id"));
      return;
    }

  if ( ob_fam["generation"] == (my_fam["generation"] + 2) )
    {
      if ( ob->query_temp("apprentice_ok") )
	{       
	  command("say 老衲百岁之龄，得此衣钵传人，真是可喜可贺！");

	  name = ob->query("name");
	  new_name = "玄" + name[2..3];
	  ob->set("name", new_name);
	  command("recruit " + ob->query("id"));
	  command("say 从今以后你的法名叫做" + new_name + "，恭喜你荣升为少林派玄字辈圣僧之一！");

	  if (!ob->query("shaolin/baidu_bonus")) {
	    ob->set("shaolin/baidu_bonus", 1);
	    command("say 现在老衲就用菩提摩顶大法，为你脱胎换骨，成就金身之基！");
	    message_vision(HIY "\n" + me->name() + 
			   "猛喝一声：般若波罗谛！ 只见一道白气从他的手掌飞出，在$N头上盘绕三匝，呼地没入顶心，\n" +
			   "$N顿时脸色血红，一下子跌倒在地，四肢抖颤，过了一会，才渐渐恢复原状，站了起来。\n\n" NOR, ob);

	    command("say 老衲再给你三颗菩提子，助你增长内力之用，注意不可一次全部服用，以免伤身！");
	    
	    ob->add("str",1);
	    ob->add("con",1);
	    ob->add("int",1);
	    ob->add("dex",1);
			
	    zi=new(DRUG_D("puti-zi"));
	    zi->move(ob);
	    zi=new(DRUG_D("puti-zi"));
	    zi->move(ob);
	    zi=new(DRUG_D("puti-zi"));
	    zi->move(ob);
	  }

	  ob->delete_temp("apprentice_ok");

	  command("say 你去罢！ 练功有什么疑难，可以随时来找我们。");
	}
      else
	{
	  command("say " + RANK_D->query_respect(ob) + "，老衲收徒甚严，你还没有资格做我的徒弟。");
	  return;
	}
    }

  return;
}

string ask_damo()
{
  mapping fam, skill; 
  string *sname, name;
  object ob;
  int i, j;
	
  name = this_player()->query("name");

  if ( name[0..1] == "渡" )
    return RANK_D->query_respect(this_player()) + 
      "已是渡字辈弟子，何苦跟老衲开这等玩笑！";

  if( this_player()->query_temp("win_times") >= 3 )
    return "就请大师到寺内鼓楼里，面见觉心师伯，必有所获！";

  if ( this_object()->query_temp("fighting") 
       ||   this_player()->query_temp("fighting") )
    return "废话少谈！你要面见觉心师伯，就得过了我们这一关！";

  if (!(fam = this_player()->query("family")) || fam["family_name"] != "少林派")
    return RANK_D->query_respect(this_player()) + 
      "与少林从无瓜葛，不知此话从何谈起？";

  if ( fam["generation"] != 36 )
    return RANK_D->query_respect(this_player()) + 
      "辈分不合，不能见觉心师伯。";

  if ( (int)this_player()->query("guilty") > 0 )
    return RANK_D->query_respect(this_player()) + 
      "你累犯数戒，身带重罪，如何配升渡字辈与我等同列！";

  skill = this_player()->query_skills();
  sname  = keys(skill);

  for(i=0; i<sizeof(skill); i++) {
    if ( skill[sname[i]] < 100 ) 
      return RANK_D->query_respect(this_player()) + 
	"的基本功力未达精深之境，我看尚不够资格晋见觉心师伯。";
  }

  for(i=0; i<sizeof(skill); i++) {
    if ( skill[sname[i]] >= 120 ) j++;
  }
  if ( j < 12 ) 
    return RANK_D->query_respect(this_player()) + 
      "的某些武功未臻大乘，尚不够资格晋见觉心师伯。";

  if ( skill["force"] < 150
       ||   skill["hunyuan-yiqi"] < 150            
       ||   skill["dodge"] < 150           
       ||   skill["shaolin-shenfa"] < 150          
       ||   skill["parry"] < 150 )         
    return RANK_D->query_respect(this_player()) + 
      "勇猛精进，武功修为远胜同门，若能再进一步，少林寺古往今来当以汝为第一耳！";

  if ( (int)this_player()->query_skill("buddhism",1) < 150 )
    return "觉心师伯乃上界真佛，" + RANK_D->query_respect(this_player()) + 
      "的佛法修为未证正果，凡眼俗胎，是无法见到师伯的。";
	
  ob=present("du nan", environment(this_object()));
  if( objectp(ob) )       ob->set_temp("fighting", 1);
  else    return "渡难大师不在，你还是等会再来吧！";

  ob=present("du jie", environment(this_object()));
  if( objectp(ob) )       ob->set_temp("fighting", 1);
  else    return "渡劫大师不在，你还是等会再来吧！";

  ob=present("du e", environment(this_object()));
  if( objectp(ob) )       ob->set_temp("fighting", 1);
  else    return "渡厄大师不在，你还是等会再来吧！";

  this_player()->set_temp("fighting", 1);

  call_out("fighting", 600, this_player());

  return "好，有志者事竞成，今日你如果能战胜我们三人，我就指点你面见觉心师伯！";
}

int fighting(object ob)
{
  return ob->delete_temp("fighting");
}

int accept_fight(object ob)
{
  object me  = this_object();
	
  if( ob->is_fighting() ) return 0;

  if ( !present("heilong bian", me) )
    return notify_fail( me->name() + "摇头道：我现在没有称手的兵器，你等会再说吧！\n");

  if( ob->query_temp("apply/armor") >= 300 )
    return notify_fail(me->name() + "摇头道：你身带宝甲，不能参加试招！\n");

  me->set("qi",      me->query("max_qi"));
  me->set("eff_qi",  me->query("max_qi"));
  me->set("jingli",  me->query("max_jingli"));
  me->set("jing",    me->query("max_jing"));
  me->set("eff_jing",me->query("max_jing"));
  me->set("neili",   me->query("max_neili"));

  me->delete("chat_msg_combat");

  if( !ob->query_temp("fighting") ) {
    if( me->query_temp("fighting") ) 
      return notify_fail( me->query("name") + 
			  "摇头道：你挑战我们三长老的时限已过，下次再来试吧。\n");
    else
      return notify_fail( me->query("name") + 
			  "摇头道：你无缘无故向贫僧挑战，似乎有些失礼吧！\n");
  }

  remove_call_out("checking");
  call_out("checking", 1, me, ob);
	
  return 1;
}

int checking(object me, object ob)
{
  object obj;
  int my_max_qi, his_max_qi;

  my_max_qi  = me->query("max_qi");
  his_max_qi = ob->query("max_qi");

  if (me->is_fighting()) 
    {
      call_out("checking", 2, me, ob);
      return 1;
    }

  if ( !present(ob, environment()) ) return 1; 

  if (( (int)me->query("qi")*100 / my_max_qi) <= 50 ) 
    {
      if( ob->query_temp("win_times") < 3 ) {
	command("say 大师武功卓绝，佛法高深。真是少林有史以来不世出的奇才！\n");
	ob->add_temp("win_times", 1);
      }

      if( ob->query_temp("win_times") >= 3 ) {
	command("say 就请大师到寺内鼓楼里，面见觉心师伯，必有所获！\n");
	ob->delete_temp("fighting");
      }
    }
  else if (( (int)ob->query("qi")*100 / his_max_qi) < 20 ) 
    {
      command("say " + RANK_D->query_respect(ob) + 
	      "虽略逊老衲一筹，但今后若能百尺竿头，再进一步，凭这份修为，我担保觉心师伯必能有所垂青！\n");
      ob->delete_temp("fighting");
    }

  me->set("chat_msg_combat", ({
    (: auto_perform :),
      }) );

  return 1;  
}


private void move_out(object player)
{
  if(objectp(player) && environment(player) == this_object())
    player->move("/d/shaolin/qyping");
}
