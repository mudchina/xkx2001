//Cracked by Roath
// dali 花匠
// by acep , mantian , mantian
// edit by mantian

inherit NPC;

int do_work();
string ask_me();

void create()
{
        set_name("花匠", ({ "hua jiang","huajiang" }) );
        set("gender", "男性");
        set("age", 50);
        set("long",
                "这是一位老花匠，在王府理从事养护花草的工作，由于大理皇室酷爱茶花，他的工作很受重视。\n");
        set("combat_exp", 3000);
        set("shen_type", 1);
        set("attitude", "peaceful");

        set("apply/attack", 10);
        set("apply/defense", 10);

        set_skill("blade", 35);
        set_skill("unarmed", 35);
        set_skill("parry", 35);
        set_skill("dodge", 35);
        
        set("inquiry", ([
                "茶花" : "我就是这里专门负责种茶花的，这里大部分的名贵品种都是我种的。",
                "工作" : "大理弟子是应该为王府义务做事的，不少弟子经常在这花园里干点儿活。",
                "干活" : (: ask_me :),
                ]));

        setup();

        carry_object("/d/dali/obj/huachu")->wield();
        carry_object("/clone/misc/cloth")->wear();
        add_money("silver", 1);
}

void init()
{
        add_action("do_work", "work");
}

string ask_me()
{
        object me;
        me=this_player();

        if (strsrch(file_name(environment(me)), "/d/dali/garden3") == -1)
                return "要干活到花园去找我吧。";
        if (me->query("family/family_name")!="大理段家")
                return "对不起，你问的问题我一点儿都听不懂。";
        if (me->query_temp("garden_working"))
                return "你先把手头的活干完再说吧。";
        if (me->query("dali/rank")==5)
                return "您老贵为王爷，怎么能和我们下人一起干活呢，还是别跟小的开玩笑了。";

        if (me->query("dali/worktimes",1) > 7)
                {
				me->apply_condition("work", 100);
				me->delete("dali/worktimes"); 
				me->set("dali/garden_worked",me->query("dali/arrestmade"));
                return "您干了不少活了，先去做点别的吧。";
                }
        if (me->query("dali/arrestmade") - me->query("dali/garden_worked") >=5){
			if (me->query_condition("work",1) >0)
                return "您干了不少活了，先去休息一阵吧。";
			me->set_temp("garden_working",random(10)+20);
		    me->set_temp("working_times",0);
			return "好极了。我这里正需要人手修整园子，你帮我除草松土吧。";
			}
			else return "您干了不少活了，先去做点别的吧。";
}
int do_work()
{
        object me, ob, weapon;
        me=this_player();

        if( strsrch(file_name(environment(me)), "/d/dali/garden3") == -1 )
                return notify_fail("不是在大理花院里，不能干活。");

        if (me->query_temp("garden_working")) {
                if (me->is_busy())
                        return notify_fail("你正忙着呢。\n");

                tell_object(me, "你弯下腰去除草挖泥。\n");

                if (!objectp(weapon=me->query_temp("weapon"))
                        || weapon->query("id")!="huachu")
                {
                        message_vision("$N用手去拔草挖泥，搞的满手是刺，鲜血淋淋。\n", me);
                        me->add("jingli",-20);
                        me->add("qi", -10);
                        me->set_temp("working_times",me->query_temp("working_times")+1);
                        me->start_busy(1);
                }
                else {
                        message_vision("$N用花锄轻松地对付着杂草和泥土。\n", me);
                        me->add("jingli",-10);
                        me->set_temp("working_times",me->query_temp("working_times")+1);
                        me->start_busy(1);
                }

                if ( random(me->query("dali/jobdone")) > 650
                && (!present("dang gui", me)) && (!present("da xueteng", me))
                && (me->query("dali/jobdone")) >= 200
                && me->query("combat_exp",1) > 200000 && random(6) == 1 ) {
                        switch (random(3)) {
                        case 0:
                                ob=new(DRUG_D("danggui"));
                                break;
                        case 1:
                                ob=new(DRUG_D("xueteng"));
                                break;
                        case 2:
                                ob=new(DRUG_D("swjing"));
                                break;
                        }
                        message_vision("$N用心地干着活，突然间发现杂草下泥巴中似乎有什么特别的东西。\n", me);
                        message_vision("$N从泥里挖出一个"+ob->name()+"！\n", me);
                        ob->move(me);
                }

                if (me->query_temp("working_times")>=me->query_temp("garden_working"))
                {
                        message_vision("花匠对$N点点头，满意地说：“够了，够了，今天的活就干到这里吧。\n", me);
                        message_vision("花匠对$N竖起大拇指：“你如此勤勉，有朝一日必成一个大花匠。\n", me);
                        me->delete_temp("working_times");
                        me->delete_temp("garden_working");
                        me->add("dali/jobdone", 1);
                        me->add("dali/worktimes", 1);
                }
                return 1;
        }
        return 0;
}

int accept_object(object who, object ob)
{
        if (ob->query("id")=="cha hua"
                && ob->query("material")=="wood")
        {
                message_vision("花匠兴高彩烈地从$N手里接过茶花，“好极了，正是这里需要的品种！”\n",who);
                command("thank "+getuid(who));
                who->set("dali/jobdone", who->query("dali/jobdone")+1);
//              remove_call_out("destroying");
                call_out("destroying", 1, ob);
                return 1;
        }
}

void destroying(object obj)
{
        destruct(obj);
        return;
}
