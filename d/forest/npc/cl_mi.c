//Cracked by Roath
//  /d/forest/npc/cl_mi.c  米横野
//  by aln 2 / 98

#include <ansi.h>

inherit NPC;

string ask_job();
string ask_over();

void create()
{
        set_name("米横野", ({ "mi hengye", "mi" }));
        set("title", "长乐帮长信堂香主");
        set("fam", "长乐帮");
        set("long",
"他是一位四十来岁的瘦子，因功高而升任长乐帮内三堂香主。\n");
        set("gender", "男性");
        set("age", 43);
        set("attitude", "friendly");
        set("shen_type", -1);
        set("str", 25);
        set("int", 25);
        set("con", 24);
        set("dex", 25);

        set("max_qi", 800);
        set("max_jing", 500);
        set("max_neili", 700);
        set("neili", 700);
        set("jiali", 30);
        set("combat_exp", 180000);
        set("score", 8000);

        set_skill("force", 100);
        set_skill("dodge", 100);
        set_skill("parry", 100);
        set_skill("strike", 100);
        set_skill("sword", 100);

        set_skill("ding-force", 100);
        set_skill("wuxingbu", 100);
        set_skill("cuixin-zhang", 100);
        set_skill("tangshi-jian", 100);

        map_skill("force", "ding-force");
        map_skill("dodge", "wuxingbu");
        map_skill("strike", "cuixin-zhang");
        map_skill("parry", "tangshi-jian");
        map_skill("sword", "tangshi-jian");

        prepare_skill("strike", "cuixin-zhang");

        set("inquiry", ([
                "长乐帮" : "长乐帮现在在江南一带威势日盛。",
                "司徒横" : "我对我们帮主老人家的景仰之情，有如滔滔江水连绵不绝。",
                "香主" : "各位香主的任命由帮主老人家说了算。",
                "贝海石" : "贝大夫在弊帮劳苦功高，颇得帮主信任。",
                "帮主" : "我家帮主司徒大爷乃威镇江南的“东霸天”也。",
                "长信堂" : "长信堂是长乐帮内三堂之一，管辖生意方面的帮务。",
                "天宝阁" : "天宝阁孙老板破产了，现将店出租给长乐帮。",
                "孙老板" : "这下这老头发了，光租金可以养他十辈子。",
                "工作" : (: ask_job :),
                "job" : (: ask_job :),
                "收工" : (: ask_over :),
                "over" : (: ask_over :),
        ]));

        setup();

        carry_object("/clone/weapon/changjian")->wield();
}

string ask_job()
{
        object ling, me = this_player();
        string myfam;
        mapping job;

        myfam = (string)query("fam");
        if( (string)me->query_temp("bangs/fam") != myfam )
                return RANK_D->query_rude(me) + "莫非是想打听我帮的秘密吧。";

        if( me->query_temp("bangs/shoptime") )
                return RANK_D->query_rude(me) + "还不快好好干活，多问什么？";

        if( !(ling = present("bang ling", me)) )
                return RANK_D->query_rude(me) + "竟连自己的帮令都管不住！";

        if( (string)ling->query("owner") != me->query("id") )
                return RANK_D->query_rude(me) + "竟连自己的帮令都管不住！";

        if( !mapp(job = ling->query("job")) ) 
                return RANK_D->query_rude(me) + "先去贝总管那儿询问帮务。";

        if( job["type"] != "伙计" )
                return RANK_D->query_rude(me) + "怎么连自己的帮务都搞不清楚？";

        me->set_temp("bangs/shoptime", uptime());
        me->set_temp("apply/short",
   ({ HIR + myfam + "伙计"NOR + me->query("name")+"("+capitalize(me->query("id"))+")" }));

        command("nod");
        return "最近生意不错，这儿正缺人手。";
}

string ask_over()
{
        object ling, me = this_player();
        string myfam;
        int shoptime, record;

        myfam = (string)query("fam");
        if( (string)me->query_temp("bangs/fam") != myfam )
                return RANK_D->query_rude(me) + "莫非是想打听我帮的秘密吧。";

        if( !(shoptime = (int)me->query_temp("bangs/shoptime")) )
                return RANK_D->query_rude(me) + "还没开始干活，就想收工？";

        if( uptime() < shoptime + 60 )
                return RANK_D->query_rude(me) + "快干活，还没到收工。";

        command("nod");
        me->delete_temp("bangs/shoptime");
        me->set_temp("apply/short", 
                ({ HIR + myfam + "帮众"NOR + me->query("name")+"("+capitalize(me->query("id"))+")" }));

        record = 1 + random(10);
        me->add("combat_exp", record);
        log_file("BangJob", sprintf("%s于%s时因做伙计得%s经验点\n", me->query("name"), ctime(time()), chinese_number(record)));

        if( ling = present("bang ling", me) ) {
                ling->delete("job");
                ling->add("score", 1 + random(10));
        }

        return "干得不错，你可以走了。";
}
