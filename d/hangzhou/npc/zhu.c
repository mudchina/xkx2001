//Cracked by Roath
// /d/hangzhou/npc/zhu.c  祝镖头
// by aln  4 / 98
// modified by sdong 07/98 add badman

inherit NPC;

mapping *uskills = ({
/*
([      "type"   :  "hand",
        "skills" :  ({
                "fengyun-shou",
                "qianye-shou",
                }),
])
,*/

([      "type"   :  "strike",
        "skills" :  ({
                "banruo-zhang",
                "sanhua-zhang",
                }),
]),

([      "type"   :  "cuff",
        "skills" :  ({
                "jingang-quan",
//                "luohan-quan", 
                }),
]),

([      "type"   :  "finger",
        "skills" :  ({
                "nianhua-zhi",
                "yizhi-chan",
                }),
]),
/*
([      "type"   :  "claw",
        "skills" :  ({
                "yingzhua-gong",
                "longzhua-gong",
                }),
]),
*/
});

mapping *wskills = ({
/*
([      "type"   :  "blade",
        "weapon" :  "/clone/weapon/gangdao",
        "skills" :  ({
                "cibei-dao",
                "xiuluo-dao",
                }),
]),
*/

([      "type"   :  "club",
        "weapon" :  "/clone/weapon/panguanbi",
        "skills" :  ({
//                "weituo-gun",
                "zui-gun",
                }),
]),
/*
([      "type"   :  "staff",
        "weapon" :  "/clone/weapon/chanzhang",
        "skills" :  ({
                "wuchang-zhang",
                "pudu-zhang",   
                }),
]),
*/
([      "type"   :  "sword",
        "weapon" :  "/clone/weapon/gangjian",
        "skills" :  ({
                "fumo-jian",
                "damo-jian",
                }),
]),
});


mapping bt_ids = ([
        "赵" : "zhao",
        "钱" : "qian",
        "孙" : "sun",
        "李" : "li",
        "周" : "zhou",
        "吴" : "wu",
        "郑" : "zheng",
        "王" : "wang",
        "冯" : "feng",
        "陈" : "chen",
        "卫" : "wei",
        "高" : "gao",
        "云" : "yun",
        "张" : "zhang",
        "刘" : "liu",
        "马" : "ma",

        "屠" : "tu",
        "俞" : "yu",
        "殷" : "yin",
        "祝" : "zhu",
        "史" : "shi",
        "宋" : "song",
        "莫" : "mo",
        "龙" : "long",
        "林" : "lin",
        "贾" : "jia",
        "包" : "bao",
        "程" : "cheng",
        "丁" : "ding",
        "黄" : "huang",
        "江" : "jiang",
        "宁" : "ning",
        "夏" : "xia",
        "翁" : "weng",
]);

#define TIMEOUT 10
#define ZHIKE "/kungfu/class/wudang/zhike.c"

string go_kill();
string go_back();

void create()
{
        object *obj;
        string *bt_names, bt_name, *bt_id;
        int temp, i, w;

        string bcskill, *bcskills, spskill, *spskills;

        bt_names = keys(bt_ids);
/*
        obj = filter_array(children(__FILE__), (: clonep :));
        if( temp = sizeof(obj) ) {
                for(i = 0; i < temp; i++) {
                        bt_name = obj[i]->query("name");
                        bt_names -= ({bt_name[0..0]});
                }
        }
*/
        if( !sizeof(bt_names) ) {
                bt_name = "镖头",
                bt_id = ({ "biaotou" });
        } else {
                bt_name = bt_names[random(sizeof(bt_names))];
                bt_id = ({ bt_ids[bt_name] + " biaotou", "biaotou" });
                bt_name += "镖头";
        }


        set_name(bt_name, bt_id);
        set("gender", "男性");
        set("age", 20 + random(40));
	set("jiali", 50);

        set("combat_exp", 100000 + random(50000));
        set("shen_type", 1);

	set("str", 25);
	set("dex", 25);
        set("con", 30);
        set("period", 600 + random(600));

        set("max_neili", 1000);
        set("neili", 1000);
        set("max_qi", 1000);
        set("eff_qi", 1000);
        set("qi", 1000);

        set_skill("force", 150 + random(20));
        set_skill("hunyuan-yiqi", 100 + random(20));
        set_skill("parry", 150 + random(20));
	set_skill("dodge", 150 + random(20));
	set_skill("shaolin-shenfa", 140 + random(20));
	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "shaolin-shenfa");

        setup();

        switch(random(2)) {
        case 0:
	i = random(sizeof(uskills));
	bcskill = uskills[i]["type"];
        set_skill(bcskill, 140 + random(20));
        spskills = uskills[i]["skills"];
        spskill = spskills[random(sizeof(spskills))];
        set_skill(spskill, 10 + random(20));

        map_skill(bcskill, spskill);
        map_skill("parry", spskill);
        prepare_skill(bcskill, spskill);
        break;

        case 1:
        i = random(sizeof(wskills));
	bcskill = wskills[i]["type"];
        set_skill(bcskill, 140 + random(20));
        spskills = wskills[i]["skills"];
	spskill = spskills[random(sizeof(spskills))];
        set_skill(spskill, 10 + random(20));

        map_skill(bcskill, spskill);
        map_skill("parry", spskill);
        carry_object(wskills[i]["weapon"])->wield();
        break;
        }

        set("learning", spskill);

        set("chat_chance", 10);
        set("chat_msg", ({
                (: go_kill :)
        }) );

        carry_object("/clone/misc/cloth")->wear();
}


/*
 * New feature added by chu:
 *
 * Biaotou will go out to kill zhike daozhang once it thinks itself is
 * strong enough.  This check is done every 10 minutes.
 *
 * It is the best if the biaotou can be strong enough to kill yuebuqun
 * and lu youjiao, if we can find a reasonable way to make them do it.
 *
 * find_target looks for a suitable target, and go_kill keeps the cycle going.
 */

void debug(string s) 
{
  // message("info", "debug: "+s, environment(this_object()), 0);
}

/*
 * find_target looks for the target object that is suitable for me.
 *
 * return value: 
 *     target  : the target object
 *     msg_out : an optional message that should be printed before leaving
 *               the current room
 *     msg_in  : an optional message printed after entering the target room
 *
 */
mapping find_target(object me)
{
  mapping ret = ([]);
  mapping skl;
  string  *sname;
  int     i, min_lvl;
  object  *obs;

  debug("checking target.\n");

  skl = query_skills();
  sname = keys(query_skills());

  min_lvl = 400;
  for(i = 0; i < sizeof(sname); i++) {
    if (skl[sname[i]] < min_lvl) {
      min_lvl = skl[sname[i]];
    }
  }
  
  if (min_lvl >= 45) {  // enough for zhike?

    obs = filter_array(children(ZHIKE), (: clonep :));
    if (!obs || sizeof(obs) < 1) {
      debug("array is empty\n");
      return 0;
    }

    ret["target"] = obs[0];
    if (! objectp(ret["target"])) {
      debug("no zhike.\n");
      return 0;
    }
    ret["msg_out"] = me->query("name")+
		"急道：都总镖头给武当派的臭道士给欺负了，"+
		"我得去帮忙．\n";
    ret["msg_in"] = me->query("name") + "对着知客道长喝道：臭牛鼻子，你敢"+
		"欺负我们都总镖头，我跟你没完．!\n";
    debug("got target.\n");
  }else{
    debug("skill not enough.\n");
    return 0;  // no target
  }
  return ret;
}

string go_kill()
{
  object me = this_object();
  object target, env;
  mapping ret;

  if (me->is_busy()) return 0;

  if (mapp(me->query("killing"))) {
    return go_back(); // check if we should go back
  }

  ret = find_target(me);
  
  if (ret) {  // there is a target for us to kill
    target = ret["target"];
    env = environment(target);

    if (! objectp(target)) {
      debug("target is not an object!!!\n");
      return 0;
    }

    if (! objectp(env)) {
      debug("target is not at an environment.\n");
      return 0;
    }

    if (ret["msg_out"]) {
      message("info", ret["msg_out"], environment(me), 0);
    }
    message_vision("$N急急忙忙地离开了．\n", me);

    me->set("killing/origin", environment(me));
    me->set("killing/target", target);
    me->set("killing/env", env);

    me->move(env);
    debug(sprintf("I am at %O", environment(me)));
    message_vision("$N快步走了过来．\n", me);
    if (ret["msg_in"]) {
      message("info", ret["msg_in"], environment(me), 0);
    }
    me->kill_ob(target);
    target->kill_ob(me);
  }else{
    debug("didn't find any target\n");
  }
  return 0;
}

string go_back()
{
  object me = this_object();
  object target = me->query("killing/target");
  object env = me->query("killing/env");
  mapping ret;

  if (! objectp(target) || ! objectp(env) ||
      environment(target) != env) {  // target is gone somehow

    message_vision("$N急急忙忙地离开了．\n", me);
    me->move(me->query("killing/origin"));
    me->delete("killing");
    message_vision("$N快步走了过来．\n", me);

  }else{ // make sure we kill each other

    me->kill_ob(target);
    target->kill_ob(me);

  }
  return 0;
}

void init()
{
  object badman, me=this_player(),ob=this_object();

  if ( interactive(me) && living(me) && me->query_condition("lmjob") ) {
    if (random(20) == 1) {
      message_vision("突然头顶上一阵劲风，一个大汉由墙上跳了进来！\n", me);
      badman = new(__DIR__"badman");
      badman->move(environment(me));
      /* don't let badman kill biaotou
      if( random(50) ==1 )
	{
	  badman->kill_ob(ob);
	}
      if( random(15) == 1)
	ob->kill_ob(badman);
	*/
    }
  }
  add_action("do_teach", "teach");
  add_action("do_check", "check");
}

int do_teach(string arg)
{
  object me = this_player();
  mapping lrn, skl, mylearned;
  string who, skill;
  int bonus, level1, level2;

  // first check if we are killing
  if (query("killing")) return 0;

  // then, check if we should go out to kill
  go_kill();

  // are we killing?
  if (query("killing")) return 0;

  // ok. we have nothing else to do, learn some skills now
  if( !me->query_condition("lmjob") && 
      me->query("id") != "sdong" && 
      !wizardp(this_player()))
    return notify_fail("你必须先得到都总镖头的允许。\n");

  if( !arg || (sscanf(arg, "%s %s", who, skill) != 2) )
    return notify_fail("指令格式：teach <某人> <技能>\n");

  if( who != "biaotou" )
    return 1;

/*
  if( member_array(skill, slskills) == -1 )
  return notify_fail(query("name") + "说道：对不起，我只学少林十八绝技。\n");
*/

/*
  if( time() > (int)query("learned") + query("period")  ) {
  set("learned", time());
  
  if( random(2) ) set("learning", query("wlearning"));
  else            set("learning", query("ulearning"));  
  }
*/

  if( skill != query("learning") )
    return notify_fail(query("name") + "说道：对不起，我在学" + 
		       to_chinese(query("learning")) + "。\n");

  level1 = query_skill(skill, 1);
  level2 = (int)me->query_skill(skill, 1);

  if( level1 > level2 )
    return notify_fail(query("name") + "说道：对不起，我已经学会" + 
		       to_chinese(skill) + "。\n");

  if( me->is_busy() || me->is_fighting() )
    return notify_fail("你正忙着。\n");

  if( is_busy() || is_fighting() )
    return notify_fail(query("name") + "正忙着。\n");

  message_vision("$N累得满头大汗向$n指点了一下" + 
		 to_chinese(skill) + "。\n", me, this_object());

  bonus = (level1 + level2)/2;

  debug(sprintf("lvl bonus: %d\n", bonus));

  // let them grow faster when levels are higher
  add("learned/" + skill, bonus + random(bonus));
  if (level1 < 50) {
    if (level1 > 30)     add("learned/" + skill, bonus);
    if (level1 > 35)     add("learned/" + skill, bonus);
    if (level1 > 40)     add("learned/" + skill, bonus);
  }
    
  add("taught", 1);

  skl = query_skills();
  //   if( undefinedp(skills[skill]) ) skills[skill] = 0;

  if( query("learned/" + skill) > (skl[skill] + 1) * (skl[skill] + 1) ) {
    skl[skill]++;
    set("learned/" + skill, 0);
    //       SKILL_D(skill)->skill_improved(this_object());
  }

  bonus /= 2;
  debug(sprintf("biaotou bonus: %d\n", bonus));

  if(bonus>60)bonus=60;
  if(bonus<8)bonus=8;

  add("combat_exp", 2*bonus + random(bonus));

  receive_damage("jing", bonus/8 + random(bonus/4));
  receive_damage("jingli", bonus/2 + random(bonus));

  debug(sprintf("raw bonus: %d\n", bonus));
  bonus = bonus * query("combat_exp") * 3 / (100000 + me->query("combat_exp"));
  debug(sprintf("after exp adjustment bonus: %d\n", bonus));
  
  debug(sprintf("after boundary bonus: %d\n", bonus));

  /*
   * bonus for biaotou's level, promoting conflict among shaolin and wudang
   */
  if (bonus > 20) bonus = 20;
  if (bonus < 5) bonus = 5;
  bonus = bonus + (level1 - 45)/3;
  if (level1 >= 40) bonus += 2;
  if (level1 >= 45) bonus += 5;
  if (level1 >= 50) bonus += 5;

  debug(sprintf("after lvl1 adjustment bonus: %d\n", bonus));

  /*
   * at this point, the bonus should be in the range of 10-20 normally
   * for monks that don't have skills at exp limit, or monks that are 
   * too high, they might get <10
   */
  if(bonus>30) bonus=30;
  if(bonus<4)  bonus=4;
  bonus = bonus/2 + random(bonus/2);
  me->add("combat_exp", bonus);

  log_file("lmjob", 
	   sprintf("%s: %s got %d exp, level1= %d, level2=%d, exp=%d\n", 
		   ctime(time()), me->query("name"), bonus, level1,
		   level2, me->query("combat_exp")));

  bonus *= 5;
  mylearned = me->query_learned();
  if( undefinedp(mylearned[skill]) ) mylearned[skill] = 0;
  mylearned[skill] += bonus * 2  + random(bonus * 2);

  me->receive_damage("jing", bonus + random(bonus));
  me->receive_damage("jingli", bonus + random(bonus));

  me->start_busy(8 + random(5));
  start_busy(20 + random(25));

  return 1;
}

int do_check(string arg)
{
  string *sname, who;
  mapping lrn, skl;
  int i;

  if( !this_player()->query_condition("lmjob") && 
      this_player()->query("id") != "sdong" && !wizardp(this_player()) ) {
    write("你必须先得到都总镖头的允许。\n");
    return 1;
  }

  if( !arg || arg != "biaotou" )
    return 1;

  skl = query_skills();
  sname = keys(query_skills());
  lrn = query("learned");
  if( !mapp(lrn) ) lrn = ([]);

  write("\n" + name() + "所学过的技能：\n\n");
  for(i = 0; i < sizeof(sname); i++)
    printf("%-50s   %3d/%5d\n",
	   (to_chinese(sname[i]) + " (" + sname[i] + ")"),
	   skl[sname[i]], (int)lrn[sname[i]]);
  
  return 1;
}
