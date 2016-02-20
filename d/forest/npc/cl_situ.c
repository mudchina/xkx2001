//Cracked by Roath
// /d/huanghe/changle/npc/situheng.c 司徒横
// by aln 2 / 98

#ifndef BANGS
#define BANGS  "/d/huanghe/"
#endif

#define BANGYIN     BANGS + "obj/bangyin"
#define BANGLING    BANGS + "obj/bangling"
#define BANGSKILLS  BANGS + "skills"
#define OFFICE  "/d/forest/clxiaoting"

inherit NPC;

#include <ansi.h>
#include <localtime.h>

#include "/d/huanghe/changle/info_beauty.h"

int ask_join();
string ask_job();
string ask_skills();
string ask_position();
string ask_life();

string *positions = ({
        "龙灵堂",
        "狮敏堂",
        "熊威堂",
});

void create()
{
	set_name("司徒横", ({ "situ heng", "situ" }));
	set("nickname", "八爪金龙");
        set("fam", "长乐帮");
	set("long",
"他是一个身材高大，但有些干瘦的中年人，双臂很长，飞抓功夫\n"
"在武林中也堪称一绝。\n");
	set("gender", "男性");
	set("age", 45);
	set("attitude", "friendly");
	set("shen_type", -1);
	set("str", 50);
	set("int", 28);
	set("con", 24);
	set("dex", 25);

	set("max_qi", 1000);
	set("max_jing", 800);
	set("max_neili", 1000);
        set("neili", 1000);
	set("jiali", 60);
	set("combat_exp", 300000);
	set("score", 10000);

	set_skill("force", 120);
        set_skill("dodge", 120);
        set_skill("parry", 120);
        set_skill("claw",  120);
        set_skill("strike", 80);
        set_skill("staff", 80);

        set_skill("poison", 80);

        set_skill("huagong-dafa", 120);
	set_skill("zhaixinggong", 120);
        set_skill("sanyin-zhua",  120);
        set_skill("chousui-zhang", 80);
        set_skill("tianshan-zhang", 80);

	map_skill("force", "huagong-dafa");
	map_skill("dodge", "zhaixinggong");
        map_skill("parry", "sanyin-zhua");
        map_skill("claw",  "sanyin-zhua");
        map_skill("strike", "chousui-zhang");
        map_skill("staff", "tianshan-zhang");

        prepare_skill("claw",  "sanyin-zhua");

        set("inquiry", ([
                "入帮" : (: ask_join :),
                "join" : (: ask_join :),
                "帮务" : (: ask_job :),
                "job" : (: ask_job :),
                "武功" : (: ask_skills :),
                "skills" : (: ask_skills :),
                "长乐帮" : "长乐帮威震江湖，指日可待！哈！哈！哈！",
                "贝先生" : "贝先生劳苦功高，所以我任命他为总管。",
                "贝大夫" : "贝先生劳苦功高，所以我任命他为总管。",
                "贝海石" : "贝先生劳苦功高，所以我任命他为总管。",
                "香主" : (: ask_position :),
                "position" : (: ask_position :),
                "生活" : (: ask_life :),
                "life" : (: ask_life :),
        ]));

	setup();

        carry_object("/clone/misc/cloth")->wear();
 //     carry_object("/clone/weapon/feizhua")->wield();
}

string ask_job()
{
        object ob = this_player();

        if( (string)ob->query_temp("bangs/fam") != "长乐帮" )
                return RANK_D->query_rude(ob) + "莫非是想打听我帮的秘密吧。";

        return "有关具体帮务方面的事你去问贝先生。";
}

string ask_position()
{
        object *obj, ling, wage, me = this_player();
        string *poss, pos, myfam;
        int i, score, bonus, period, record;

        if( is_fighting() )
                return RANK_D->query_rude(me) + "瞎了眼没见我正忙着？！";

        myfam = (string)query("fam");
        if( (string)me->query_temp("bangs/fam") != myfam )
                return RANK_D->query_rude(me) + "莫非是想打听我帮的秘密吧。";

        if( !(ling = present("bang ling", me)) )
                return RANK_D->query_rude(me) + "竟连自己的帮令都管不住！";

        if( (string)ling->query("owner") != me->query("id") )
                return RANK_D->query_rude(me) + "竟连自己的帮令都管不住！";

        if( stringp(pos = me->query_temp("bangs/pos")) ) {
                period = uptime() - (int)me->query_temp("bangs/pos_time");
                if( period < 1800 )
                        return "你在这么短的时间内不可能有多大作为，以后再让帮主巡视" + pos + "吧。";

                score = (int)ling->query("score");
                bonus = score - (int)me->query_temp("bangs/pos_score");
                me->set_temp("bangs/pos_score", score);
                me->set_temp("bangs/pos_time", uptime());

                if( bonus < period / 10 )
                        return pos + "最近表现很差呀，你这些日子在干吗？";

                command("nod");
//              bonus *= (score / 1000 + 1);
//              This line is the old code, if player stays on line and cumulates the
//              score, it can be very big, for example, online 15 hours can get about 20k score
//              20000 / 1000 + 1 = 21, if he only ask xiang zhu one
//              bonus = (20000 - 500) * 21 = 409500, and later bonus /= 3, add_exp = bonus +random(bonus)
//              So a player can get 200k exp like this.

//              So instead of multiply, add the bonus, so it won't increase by factors. 
				bonus += (score / 50 +1);
                wage = new("/clone/money/silver");
                record = bonus + random(bonus);
                wage->set_amount(record);
                wage->move(me);
                message_vision("$N转身拿出一个红包递给$n。\n", this_object(), me);
                log_file("test/BangPos", sprintf("%s于%s时因管辖%s%s获利%s两银子\n", me->query("name"), ctime(time()), myfam, pos, chinese_number(record)));

                bonus /= 3;
                me->add("combat_exp", bonus + random(bonus));
                return pos + "在你的管辖下，最近表现不错。";
        }

        if( (int)me->query("combat_exp") < 10000 )
                return RANK_D->query_rude(me) + "当香主未免太嫩了吧。";

        if( (score = (int)ling->query("score")) < 500 )
                return "就凭你这点功劳也窥视香主之位？";

        obj = users();
        poss = positions;
        for(i = 0; i < sizeof(obj); i++) {
                if( obj[i]->query_temp("bangs/fam") == myfam ) {
                if( stringp(pos = obj[i]->query_temp("bangs/pos")) )
                        poss -= ({pos});
                }
        }

        if( !sizeof(poss) )
                return "现在所有的香主之位都有人占着。";

        pos = poss[random(sizeof(poss))];
        me->set_temp("bangs/pos", pos);
        me->set_temp("bangs/pos_time", uptime());
        me->set_temp("bangs/pos_score", score);
        
        me->set_temp("apply/short",
   ({ HIR + myfam + pos + "香主"NOR + me->query("name")+"("+capitalize(me->query("id"))+")" }));
        log_file("test/BangPos", sprintf("%s于%s时当上%s%s香主\n", me->query("name"), ctime(time()), myfam, pos));
        command("congra");
        return "我把" + pos + "托付给你，你可要不负众望。";
}

string ask_life()
{
        object me = this_player();
        string myfam, *beautys, beauty;

        if( is_fighting() )
                return RANK_D->query_rude(me) + "瞎了眼没见我正忙着？！";

        myfam = (string)query("fam");
        if( (string)me->query_temp("bangs/fam") != myfam )
                return RANK_D->query_rude(me) + "莫非是想打听我帮的秘密吧。";

        if( uptime() < (int)query("joytime") + 20 + random(20) ) {
                command("lazy");
                return "老夫最近对此没有兴趣。";
        }

        beautys = keys(info_beauty);
        beauty = beautys[random(sizeof(beautys))];

        command("hehe " + query("id"));
        me->set_temp("bangs/beauty", beauty);
        set("joytime", uptime());
        return "最近" + beauty + "这娘们怎么样啦？老夫这几天都没睡稳觉。";
}

int accept_object(object who, object ob)
{
        object ling, room;
        string myfam, beauty;
        int bonus, record;

        myfam = query("fam");
        if( who->query_temp("bangs/fam") != myfam ) 
                return notify_fail(name() + "大怒道：大胆！想谋害本帮主？！\n");

        if( !(room = environment()) )
                return notify_fail(name() + "大怒道：等我回总舵再说吧！\n");

        if( base_name(room) != OFFICE )
                return notify_fail(name() + "大怒道：等我回总舵再说吧！\n");

        if( !stringp(beauty = who->query_temp("bangs/beauty")) )
                return notify_fail(name() + "大怒道：滚！老夫的私事不用你操心！\n");

        if( !ob->is_character() )
                return notify_fail(name() + "大怒道：这种烂东西你自己用吧！\n");

        if( ob->query("gender") != "女性" )
                return notify_fail(name() + "大怒道：老夫对人妖没兴趣！\n");

        if( ob->query("name") != beauty )
                return notify_fail(name() + "大怒道：连老夫的话都记不住！");

	if( userp(ob) )
		return notify_fail(name() + "大怒道：滚！随便找个人回来竟想蒙骗老夫！");

        if( (int)ob->query("eff_qi")*10 < (int)ob->query("max_qi")*9
        ||  (int)ob->query("eff_jing")*10 < (int)ob->query("max_jing")*9 )
                return notify_fail(name() + "大怒道：伤成这个样子，老夫还有什么兴趣！");

        command("haha");
        who->delete_temp("bangs/beauty");
        ob->move(this_object());
        call_out("destroy_beauty", 1, ob);
        bonus = info_beauty[beauty] * 100000 / (100000 + (int)who->query("combat_exp"));
        record = bonus + random(bonus);
        who->add("combat_exp", record);
        who->add("shen", -record);
        log_file("test/BangWomen",  sprintf("%s于%s时上贡%s得%s经验点\n", who->query("name"), ctime(time()), beauty, chinese_number(record)));

        if( ling = present("bang ling", who) ) {
                if( (string)ling->query("owner") == who->query("id") )
                        ling->add("score", bonus + random(bonus));
        }

        command("say 好！好！好！" + myfam + "上上下下几千人中数你最讨帮主的欢心！");
        return 1;
}       

void destroy_beauty(object ob)
{
        if( ob )  destruct(ob);
}

#include "/d/huanghe/npc/bangzhu.h";
