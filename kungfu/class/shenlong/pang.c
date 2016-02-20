//Cracked by Roath
// pangtoutuo 胖头陀
// by ALN 10 / 97
// by ALN 12 / 97
// by ALN  1 / 98

inherit F_UNIQUE;
inherit NPC;

#include <ansi.h>
#include <room.h>

#define PANGHOME "/d/city/zuixianlou2"
#define SGCANGKU "/d/shenlong/cangku"
#define SGZHAO   "/d/shenlong/obj/sg_mianzhao"
#define SGJOBS   "/d/shenlong/sgjob/sgjob"

int auto_perform();
int random_walk();

int ask_jiao();
string ask_task();
string ask_wan();
string ask_exp();

int is_other(object, object);
int is_suitable(object, object);
int is_candidate(object, object);

string assign_job(object);
void apply_gift(object, int);

void gototalk(object);
void set_pang(object, string);
void del_busyfor();

string *homes = ({
        "/d/city/zuixianlou2",
        "/d/city/wumiao",
        "/d/city/kedian",
        "/d/city/duchang",
        "/d/city/biaoju",
        "/d/city/qianzhuang",
        "/d/city/yaopu",
        "/d/city/jujinge",
        "/d/city/lichunyuan",
        "/d/city/chaguan",
});

string *meetplaces = ({
        "/d/city/dongjiao2",
        "/d/city/xijiao2",
        "/d/city/beijiao2",
        "/d/city/nanjiao2",
});

mapping nondirs = ([
        "/d/city/dongdajie3": "east",
        "/d/city/nandajie3" : "south",
        "/d/city/xidajie2"  : "west",
        "/d/city/beidajie2" : "north",
]);

string *shaolinbooks = ({
        "罗汉拳法",
        "风云手手法",
        "般若掌法",
        "普渡杖法",
        "伏魔剑法",
        "达摩剑法",
        "如来千叶手手法",
        "大金刚拳法",
        "无常杖法",
        "慈悲刀法",
        "修罗刀法",
        "醉棍棍法",
        "散花掌法",
        "拈花指法",
        "韦陀棍法",
        "鹰爪功法",
        "龙爪功法",
        "一指禅功",
});


void create()
{
	set_name("胖头陀",({"pang toutuo","pang","toutuo"}));
	set("long",
		"身材奇高，瘦得出奇，脸上皮包骨头，双目深陷，\n"
		"当真便如僵尸一般长发垂肩，头顶一个铜箍束住了长发，\n"
		"身上穿一件布袍，宽宽荡荡，便如是挂在衣架上。\n");
	set("gender","男性");
	set("age",41);
	set("attitude","peaceful");
	set("shen_type",-1);
	set("str",28);
	set("int",28);
	set("con",28);
	set("dex",30);
	set("max_qi",1000);
	set("max_jing",1000);
	set("neili",1500);
	set("max_neili",1500);
	set("jingli",1200);
	set("max_jingli",1500);
	set("jiali", 100);
	set("combat_exp", 600000);
	set("score",60000);

	set_skill("force", 150);
	set_skill("dulong-dafa", 150);
	set_skill("dodge", 150);
	set_skill("lingshe-shenfa", 150);
	set_skill("strike", 150);
	set_skill("huagu-mianzhang", 150);
	set_skill("parry", 150);
	set_skill("blade", 150);
        set_skill("xiuluo-dao", 150);

        set_temp("apply/attack", 20);
        set_temp("apply/damage", 20);
        set_temp("apply/defense", 20);
        set_temp("apply/armor", 50);

	map_skill("force","dulong-dafa");
	map_skill("dodge","lingshe-shenfa");
	map_skill("strike","huagu-mianzhang");
        map_skill("blade", "xiuluo-dao");
	map_skill("parry","xiuluo-dao");

	prepare_skill("strike","huagu-mianzhang");

	create_family("神龙教", 2, "教众");

        set("chat_msg_combat",({
                (:auto_perform:),
        }));

        set("stay_chance",1);
        set("no_clean_up",1);
        set("chat_chance", 50);
        set("chat_msg",({
		(: random_walk :)
	}));

        set("amount", 5 + random(5));

	setup();
        ::create();

        set("inquiry",([
                  "神龙教" : (:ask_jiao:),
                  "jiao" : (:ask_jiao:),
                  "洪安通" : "这三个字是你说的吗？",
                  "洪教主" : "洪教主仙福永享，寿与天齐，洪教主神目如电，烛照四方。",
                  "豹胎易筋丸" : (:ask_wan:),
                  "效命"   : (:ask_task:),
                  "task" : (:ask_task:),
                  "job"  : (:ask_task:),
                  "任务"   : (:ask_task:),
                  "功劳"   : (:ask_exp:),
                  "point" : (:ask_exp:),
                  "瘦头陀" : "别提了，咱哥儿俩换了这副身胚。",
                  "神龙岛" : "神龙岛在汝州的东北方向，从塘沽口出海便到。",
	]));

	carry_object("/d/shenlong/obj/dahuandao")->wield();
	carry_object("/clone/misc/cloth")->wear();
}

void init()
{
        object me = this_player();
        string room, myid;

        ::init();

        if( !living(this_object()) || !interactive(me) 
         || !living(me) || is_fighting(me)
         || !filter_array(all_inventory(environment()), "is_other", this_object(), me) )
                return;

        if( me->query("sg/spy") )
                tell_object(me, "胖头陀朝你神秘地笑了一笑。\n");

        myid = me->query("id");
        if( me->query_temp("pang/a") && query_temp("busyfor") == myid 
        &&  member_array(base_name(environment()), meetplaces) != -1 ) {
                if( me->query("family/family_name") != "神龙教" && !me->query("sg/spy") && !me->query("sg/cured") ) {
                        command("welcome " + myid);
                        say("胖头陀说道：你必须服了豹胎易筋丸后，才能算加入神龙教。\n");
		} else {
                        command("addoil " + myid);
                        say("胖头陀说道：托教主的洪福，神龙教越来越兴旺了。\n");
                }

                return set_pang(me, "c");
        }

        if( me->query_temp("pang/b") && query_temp("busyfor") == myid ) 
                return gototalk(me);
}

int ask_jiao()
{
        object cangku, victim, obj, me = this_player();
        object ob = this_object();
        mixed victim_list;
        string dayphases, myid;
        int myexp;

        if( me->query("sg/cured") ) {
                say("胖头陀大怒道：无耻的叛徒，还不给我滚！！！\n");
                return 1;
        }

        if( !(cangku = find_object(SGCANGKU)) )
                cangku = load_object(SGCANGKU);

        if( is_fighting() || is_busy() 
        || (stringp(query_temp("busyfor")) && (string)query_temp("busyfor") != myid) ) {
                command("say 你没见我正忙着？");
                return 1;
        }

        if( query("eff_qi") * 10 < query("max_qi") * 4 ) {
                command("say 我身负重伤，恐怕快不行了。你一定要替我报仇。。。");
                return 1;
        }

        myid = me->query("id");
        myexp = (int)me->query("combat_exp");

        if( !me->query("sg/spy") && !me->query("sg_ok/join") ) {
                if( myexp < 10000 ) {
                        command("say " + RANK_D->query_respect(me) + "还是在江湖上多混几年吧。");
                        return 1;
                } else if( myexp > 100000 ) {
                        command("say " + RANK_D->query_rude(me) + "莫不是想在神龙教窝底？");
                        return 1;
                }

                if( time() > (int)me->query("sgjob_join/assigntime") + 86400 ) {
                        if( !sizeof(victim_list = filter_array(users(), "is_suitable", this_object(), me)) ) {
                                command("whisper " + myid + " " + "今天很不巧，你下次再来吧。");
                                return 1;
                        }

                        if( !present("mianzhao", me) ) {
                                obj = new(SGZHAO);
                                obj->set("owner", me);
                                obj->move(me);
                        }

                        message_vision("$N给了$n一" + obj->query("unit") + obj->name() + "。\n", this_object(), me);

                        victim = victim_list[random(sizeof(victim_list))];

                        me->set("sgjob_join/victim_name", victim->query("name"));
                        me->set("sgjob_join/victim_id", victim->query("id"));
                        me->set("sgjob_join/assigntime", time());

                        log_file("test/ShenlongJointask", sprintf("%s于%s时被指派去追杀%s\n", me->query("name"), ctime(time()), me->query("sgjob_join/victim_name")));
                        command("whisper " + myid + " " + "你去把" + me->query("sgjob_join/victim_name") + "(" + me->query("sgjob_join/victim_id") + ")" + "杀了，我才能让你入教。");
                        return 1;
                }

                command("whisper " + myid + " " + "没有投名状，我怎么能相信你的诚意？");
                return 1;
        }

        set_temp("busyfor", myid);

        if( !sizeof(filter_array(all_inventory(environment()), "is_other", this_object(), me))  )
                gototalk(me);
        else {
                tell_object(me, "胖头陀向你努了努嘴。\n");
                set_pang(me, "b");
                return random_move();
	}

        return 1;
}

string ask_wan()
{
        object cangku, me = this_player();
        string str, v_id;
        mapping pkjob;
        int exp;

        if( me->query("sg/cured") )
                return "无耻的叛徒，还不给我滚！！！\n";

        if( !me->query_temp("pang/c") )
                return "这种药你也吃？你瞎了眼没见我成了瘦头陀？\n";
        me->delete_temp("pang");

        if( !me->query("sg/spy") ) {
                if( !me->query("sg_ok/join") )
                return "没有投名状，我怎么能相信你的诚意？";

                command("touch " + me->query("id"));
                me->delete("sg_ok");
                me->set("sg/spy", 1);
                me->set("sg/joinage", (int)me->query("age"));
                log_file("test/ShenlongJoin", sprintf("%s于%s时加入神龙教\n", me->query("name"), ctime(time())));
                message_vision("胖头陀从衣袋里掏出一粒豹胎易筋丸塞进了$N的嘴里。……\n\n", me);
                call_out("apply_yj", 1, me);
                return "从现在起，你是一名神龙教秘密教众，你的职责就是为教主赴汤蹈火，在所不辞！";
        }

        exp = (int)me->query("combat_exp");
        if( (int)me->query("sg/exp") < exp / 200 && exp > 100000 )
                return "入神龙教应该心狠手辣，你做得太差了，不给你新的易筋丸。";

        if( !mapp(me->query("sgjob")) && !mapp(me->query("sg_ok")) ) {
                if( !(str = assign_job(me)) )
                        return "我是想给你吃豹胎易筋丸，只不过眼下没有适合你的教务，你下次再来吧。";
                else    return str + "，然而我才能给你一粒豹胎易筋丸。";
        }

        if( mapp(me->query("sg_ok")) ) {
                me->delete("sg_ok");
                command("nod " + me->query("id"));
                message_vision("胖头陀从衣袋里掏出一粒豹胎易筋丸塞进了$N的嘴里。……\n\n", me);
                call_out("apply_yj", 1, me);
                return "干得不错，奖励你一粒豹胎易筋丸！";
        }

        command("slap " + me->query("id"));

        if( (int)me->query("sg/exp") > 0 && time() > me->query("sgjob/assigntime") + 1800 ) { 
                me->delete("sgjob");
                me->add("sg/failure", 1);
                me->add("sg/exp", -1);
                if( (int)me->query("sg/exp") < 0 ) me->set("sg/exp", 0);
                say("胖头陀大怒道：还有脸来见我？\n");
                if( !(str = assign_job(me)) )
                        return "我是想给你吃豹胎易筋丸，只不过眼下没有适合你的教务，你下次再来吧。";
                else    return "再给你一次机会，" + str + "，然而我才能给你一粒豹胎易筋丸。";
        }

        return "还不再去试一试？！";
}

string ask_task()
{
        object cangku, me = this_player();
        string str, v_id, *v_list;
        mapping pkjob;
        int punish, exp;

        if( me->query("sg/cured") )
                return "无耻的叛徒，还不给我滚！！！";

        if( !me->query("sg/spy") )
                return "这是敝教的秘密，有什么好问的？！";

        if( !me->query_temp("pang/c") )
                return "问什么问？也不看看时间地点！白在神龙教呆了那么久！";
        me->delete_temp("pang");

        exp = (int)me->query("combat_exp");
        if( (int)me->query("sg/exp") < exp / 200 && exp > 100000 )
                return "入神龙教应该心狠手辣，你做得太差了，还是去青龙使那儿练一练吧。";
                 
        if( !me->query("sgjob") ) {
                if( mapp(me->query("sg_ok")) ) {
                        me->delete("sg_ok");
                        command("thumb " + me->query("id"));
                }
                if( !(str = assign_job(me)) )
                        return "眼下没有适合你的教务，你下次再来吧。";
                return  str + "。";
        }

        command("slap " + me->query("id"));

        if( (int)me->query("sg/exp") > 5 && time() < me->query("sgjob/assigntime") + 1800 ) {
                punish = 3 + random(6);
                me->add("sg/failure", punish);
                me->add("sg/exp", -punish);
                if( (int)me->query("sg/exp") < 0 ) me->set("sg/exp", 0);
                say("养兵千日，用兵一时！推三推四的罚你" + chinese_number(punish) + "个功劳点！\n");

                me->delete("sgjob");
                if( !(str = assign_job(me)) )
                        return "眼下没有适合你的教务，你下次再来吧。";
                return  str + "。";
        }

        if( time() >= me->query("sgjob/assigntime") + 1800 ) { 
                me->delete("sgjob");
                me->add("sg/failure", 1);
                me->add("sg/exp", -1);
                if( (int)me->query("sg/exp") < 0 ) me->set("sg/exp", 0);
                say("胖头陀大怒道：还有脸来见我？\n");

                if( !(str = assign_job(me)) )
                        return "眼下没有适合你的教务，你下次再来吧。";
                return  str + "。";
        }

        return "还不再去试一试？！";
}

string ask_exp()
{
        object me = this_player();
        if( me->query("sg/cured") )
                return "无耻的叛徒，还不给我滚！！！\n";

        if( !me->query("sg/spy") )
                return "这是敝教的秘密，有什么好问的？！\n";

        if( !me->query_temp("pang/c") )
                return "问什么问？也不看看时间地点！白在神龙教呆了那么久！\n";
//      me->delete_temp("pang");

        command("thumb " + me->query("id"));
        return RANK_D->query_respect(me) + "劳苦功高，我在功劳簿上给你记了" + chinese_number((int)me->query("sg/exp")) + "点。";
}

int random_walk()
{
        mapping exits, doors;
        string *dirs, dir, file;

        if( !objectp(environment()) 
        || !mapp(exits = environment()->query("exits")) 
        || is_fighting() || is_busy()
        || query("jingli") < query("max_jingli") / 2 ) return 0;

        file = base_name(environment());
        if( strsrch(file, "/d/city/") != 0 ) {
                message("vision", name() + "急急忙忙地离开了。\n",
                environment(), this_object());
                move(homes[random(sizeof(homes))]);
                message("vision", name() + "走了过来。\n",
                environment(), this_object());
        }

        dirs = keys(exits);
        if( mapp(doors = environment()->query_doors()) ) {
                dirs += keys(doors);
        }

        if( member_array(file, keys(nondirs)) != -1 ) {
                say("胖头陀摇了摇头，说道：我怎舍得离开扬州这个花花世界？\n");
	        dirs -= ({nondirs[file]});
	}

        if( sizeof(dirs) == 0 ) return 0;

        dir = dirs[random(sizeof(dirs))];
        if ( mapp(doors) && !undefinedp(doors[dir])
          && (doors[dir]["status"] & DOOR_CLOSED) )
                command("open " + dir);
        command("go " + dir);
        return 1;
}

int accept_object(object who, object ob)
{
        mapping sgjob;
        string chname = "", name;
        int bonus;

        if( who->query("sg/cured") )
                return notify_fail("胖头陀大怒道：无耻的叛徒，还不给我滚！！！\n");

        if( !who->query("sg/spy") )
                return notify_fail("胖头陀说道：" + RANK_D->query_respect(ob) + "与敝教素无往来，我不能收你的东西。\n");

        if( !(sgjob = who->query("sgjob")) )
                return notify_fail("胖头陀说道：这不是我想要的。\n");

        name = ob->name();
        for(int i = 0; i < strlen(name); i++)
                if(name[i] > 160 && name[i] < 255) chname += name[i..i];

        if( chname != sgjob["sgjob"] )
                return notify_fail("胖头陀说道：这不是我想要的。\n");

        bonus = sgjob["exp_bonus"];
        bonus = bonus + random(bonus);
        who->add("combat_exp", bonus);
        who->add("shen", -bonus);

        bonus = sgjob["score"];
        bonus = bonus + random(bonus);
        who->add("sg/exp", bonus);

        who->delete("sgjob");
        who->set("sg_ok/stuff", 1);

        remove_call_out("store");
        call_out("store", 1, ob);

        log_file("test/Sgstff", sprintf("%s于%s时上交了%s\n", who->query("name"), ctime(time()), chname));
        command("nod " + who->query("id"));
        return 1;
}

void gototalk(object me)
{
        object ob = this_object();
        string str;

        str = meetplaces[random(sizeof(meetplaces))];

        command("whisper " + me->query("id") + " " + "这儿说话不方便，我们去城外" + (load_object(str))->query("short") + "谈吧。");

        set_pang(me, "a");

        message("vision", 
                "急急忙忙地离开了。\n", 
                environment(ob), ({ob}));

        ob->move(str);
        message("vision", 
                "胖头陀走了过来。\n",
                environment(ob), ({ob}));

        remove_call_out("do_back");
        call_out("do_back", 30 + random(30), ob);
}

void do_back(object ob)
{
        if( !ob )  return;

        if( ob->is_busy() || ob->is_fighting() || !living(ob) )
                call_out("do_back", 10 + random(10));
        else {
                message("vision", 
                        "胖头陀一转眼便消失了。\n", 
                        environment(ob), ({ob}));
//              ob->move(PANGHOME);
                ob->move(homes[random(sizeof(homes))]);
                message("vision", 
                        "胖头陀大步走了过来。\n", 
                        environment(ob), ({ob}));

                del_busyfor();
        }
}

void set_pang(object ob, string type)
{
        string *types = ({"a", "b", "c"});

        if( member_array(type, types) == -1 )
                return;

        types -= ({type});

        ob->set_temp("pang/" + type, 1);
        for(int i = 0; i < sizeof(types); i++)
                ob->delete_temp("pang/" + types[i]);

        remove_call_out("del_busyfor");
        call_out("del_busyfor", 20 + random(20));
}

void del_busyfor()
{
        object ob;
        string p_id;

        if( !stringp(p_id = (string)query_temp("busyfor")) ) return;

        if( ob = find_player(p_id) ) 
                 ob->delete_temp("pang");

        delete_temp("busyfor");
}

void store(object ob)
{
        if( !ob ) return;

        if( !ob->is_unique() )  destruct(ob);
        else ob->move(SGCANGKU);
}

private int is_other(object ob, object me)
{
        if( userp(ob) && ob != me && living(ob) )  return 1;
        return 0;
}

private int is_suitable(object victim, object killer)
{
        object room;
        mapping map;

        if( !(room = find_object("/d/taishan/fengchan")) )
                room = load_object("/d/taishan/fengchan");

        if( !mapp(map = killer->query("sg_victim")) )
                map = ([]);

        if( victim->query("combat_exp") * 4 < killer->query("combat_exp") * 3
         || victim->query("combat_exp") * 4 > killer->query("combat_exp") * 5
         || victim->query("sg/spy")
         || victim->query("family/family_name") == "神龙教"
         || victim->query("id") == room->query("winner")
         || victim == killer
         || member_array(victim->query("id"), values(map)) != -1
         || wizardp(victim) )
                return 0;

        return 1;
}

private int is_candidate(object victim, object forcer)
{
        string *no_force_list = ({
                "mu ren",
                "mengzhu",
                "shangshan shizhe",
                "fae shizhe",
                "xuantong dashi",
                "huang zhen",
                "juexin dashi",
                "ren woxing",
                "zhuoma",
        });

        if( victim->query("combat_exp") < forcer->query("combat_exp")
         || victim->query("combat_exp") > forcer->query("combat_exp") * 2
         || !clonep(victim) || userp(victim)
         || victim->query("race") != "人类"
         || victim->query("winner")
         || victim->query("family/family_name") == "神龙教"
         || victim->query("sg/spy") 
         || strsrch(base_name(victim), "/d/xiakedao/") == 0
         || strsrch(base_name(victim), "/d/death/") == 0
         || strsrch(base_name(victim), "/d/shenlong/") == 0
         || strsrch(base_name(victim), "/u/") == 0
         || base_name(victim) == "/kungfu/skill/yanxing-dao/copy/user"
         || member_array(victim->query("id"), no_force_list) != -1 )
                 return 0;

        return 1;
}

void apply_yj(object me)
{
        me = this_player();

        if ( me->query("yijin_wan") >= me->query("age") - 13 ) {
                me->add("max_neili",  -5);
                me->add("max_jingli", -5);
                apply_gift(me, -1);
                message("vision", me->name() + "一口把丸药吞了下去，接着就倒在地上，人事不知了。\n" NOR, environment(me), me);
                tell_object(me, HIR "你吞下一粒豹胎易筋丸，只觉得腹痛如绞，脑中天旋地转，原来服食太多，反中其剧毒！\n" NOR);
                me->unconcious();
        } else {
                me->add("max_neili",  5);
                me->add("max_jingli", 5);
                me->set("yijin_wan", me->query("age") - 13);
                apply_gift(me, 1);
                message("vision", me->name() + "一口吞下豹胎易筋丸，只见其脸色由白转绿，由绿转黑，又由黑转红，一直变了好几次，才渐渐恢复原样。\n" NOR, environment(me), me);
                tell_object(me, HIG "你一吞下豹胎易筋丸，便觉内息澎湃，急浪般涌入四肢百骸，全身骨节格格爆响。" 
                                + "\n接着又觉身轻如燕，几欲腾空飞去。看来你已经脱胎换骨，功力大进了！\n" NOR, me);

        }

        tell_object(me, "你既服此丸，当在一年后再次服用，否则功力大损！！！\n");

}

void apply_gift(object me, int flag)
{
        int i;
        int tmpstr, tmpint, tmpcon, tmpdex, tot;
        mapping my = me->query_entire_dbase();

        if( flag == -1 ) {
        tmpstr = tmpint = tmpcon = tmpdex = 10 + flag;

        for (i = 0; i < 40; i++) {
                switch (random(4)) {
                        case 0: tmpstr++; break;
                        case 1: tmpint++; break;
                        case 2: tmpcon++; break;
                        case 3: tmpdex++; break;
                }
        }

        if (tmpstr <= 30) my["str"] = tmpstr;   else my["str"] = 30;
        if (tmpint <= 30) my["int"] = tmpint;   else my["int"] = 30;
        if (tmpcon <= 30) my["con"] = tmpcon;   else my["con"] = 30;
        if (tmpdex <= 30) my["dex"] = tmpdex;   else my["dex"] = 30;
        return;
        }

        tot = 84 - my["str"] - my["int"] - my["con"] - my["dex"];
        for(i = 0; i < tot; i++) {
                switch (random(4)) {
                        case 0: my["str"]++; break;
                        case 1: my["int"]++; break;
                        case 2: my["con"]++; break;
                        case 3: my["dex"]++; break;
                }
        }
}

string assign_job(object me)
{
        object ob, victim, cangku;
        mapping sgjob, map;
        string *times;
        mixed victim_list, stuff_list;
        int i, myexp;

        string *levels = ({
               "20000",
               "50000",
              "100000",
              "500000",
             "1000000",
             "2000000"
        });

        myexp = (int)me->query("combat_exp");
        myexp = (4 * myexp + random(2 * myexp)) / 5;
        if( myexp < 10000 ) return "";

        for( i = 0; i < sizeof(levels); i++ ) 
               if( myexp < atoi(levels[i]) ) break;

        sgjob = (SGJOBS + levels[i])->query_sgjob();
        if( !sgjob ) return "";

        if( !present("mianzhao", me) ) {
                ob = new(SGZHAO);
                ob->set("owner", me);
                ob->move(me);
                message_vision("$N给了$n一" + ob->query("unit") + ob->name() + "。\n", this_object(), me);
        }

        switch(sgjob["sgjob"]) {
        case "FORCEJOIN":
                if( !(victim_list = filter_array(livings(), "is_candidate", this_object(), me)) )
                        return "";
                victim = victim_list[random(sizeof(victim_list))];
                me->set("sgjob/forcejoin", victim->query("id"));
                me->set("sgjob/assigntime", time());
                log_file("test/ShenlongJob", sprintf("%s于%s时被指派去拉%s进神龙教\n", me->query("name"), ctime(time()), victim->name()));
                return "你去把" + victim->query("name") + "拉进神龙教来";
                break;

        case "PK":
                if( mapp(map = me->query("sg_victim")) ) {
                        times = keys(map);
                        for(i = 0; i < sizeof(times); i++) {
                                if( time() > atoi(times[i]) + 259200 )
                                map_delete(map, times[i]);
                        }
                        me->set("sg_victim", map);
                }
      
                if( !(victim_list = filter_array(users(), "is_suitable", this_object(), me)) )
                        return "";
                victim = victim_list[random(sizeof(victim_list))];

                me->set("sgjob/victim_name", victim->query("name"));
                me->set("sgjob/victim_id", victim->query("id"));
                me->set("sgjob/assigntime", time());

                log_file("test/ShenlongJob", sprintf("%s于%s时被指派去追杀%s\n", me->query("name"), ctime(time()), (string)me->query("sgjob/victim_name")));
                return "你去把" + (string)me->query("sgjob/victim_name") + "(" + (string)me->query("sgjob/victim_id") + ")" + "杀了";
                break;

        default: break;
        }

        if( sgjob["sgjob_type"] == "寻" ) {
                if( !(cangku = find_object(SGCANGKU)) )
                        cangku = load_object(SGCANGKU);

                if( stuff_list = cangku->query("stuff_list") ) 
                        if( member_array(sgjob["sgjob"], stuff_list) != -1 )
                                return "";

                if( sgjob["sgjob"] == "少林秘籍" )
                sgjob["sgjob"] = shaolinbooks[random(sizeof(shaolinbooks))];
                me->set("sgjob", sgjob);
                me->set("sgjob/assigntime", time());
                log_file("test/ShenlongJob", sprintf("%s于%s时被指派去找%s\n", me->query("name"), ctime(time()), sgjob["sgjob"] ));
                return "你去把" + sgjob["sgjob"] + "找来";
        }

        return "";
}








