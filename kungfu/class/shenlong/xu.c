//Cracked by Roath
// qinglong shi 青龙使
// by aln 1 / 98

inherit F_UNIQUE;
inherit NPC;
// inherit F_MASTER;

#include <ansi.h>
#include <room.h>

#define SGDATA "/d/shenlong/data/"
#define SGCANGKU "/d/shenlong/cangku"
#define SGZHAO "/d/shenlong/obj/sg_mianzhao"

string ask_jiao();
string ask_wan();
string ask_exp();
string ask_task();
string ask_victim();
string ask_ob(string);

int is_suitable(object, object);
string assign_job(object);

/*
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
*/

void create()
{
	set_name("许雪亭", ({ "xu xueting","qinglong shi", "shi","xu" }));
	set("nickname", "青龙使");
	set("long",
		"高瘦汉子，目光炯炯，看上去十分干练。\n");
	set("gender", "男性");
	set("age", 48);
	set("attitude", "peaceful");
	set("shen_type", -1);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 32);
	set("max_qi", 1200);
	set("max_jing", 1200);
	set("neili", 1500);
	set("max_neili", 1500);
	set("jingli", 1200);
	set("max_jingli", 1800);
	set("jiali", 70);
	set("combat_exp", 460000);
	set("score", 50000);
	set("shen", -25000);

	set_skill("force", 150);
	set_skill("dulong-dafa", 120);
	set_skill("dodge", 140);
	set_skill("lingshe-shenfa", 130);
	set_skill("strike", 130);
	set_skill("huagu-mianzhang", 130);
	set_skill("parry", 130);
	set_skill("finger", 120);
        set_skill("club", 130);
        set_skill("weituo-gun", 130);

	map_skill("force", "dulong-dafa");
	map_skill("dodge", "lingshe-shenfa");
	map_skill("strike", "huagu-mianzhang");
	map_skill("parry", "weituo-gun");
        map_skill("club", "weituo-gun");

	prepare_skill("strike", "huagu-mianzhang");

	create_family("神龙教", 2, "使者");

        set("chat_chance", 20);
        set("chat_msg",({
                (:random_move:)
        }));

        set("inquiry", ([
                "神龙教" : (:ask_jiao:),
                "豹胎易筋丸" : (:ask_wan:),
                "功劳"   : (:ask_exp:),
                "教务" : (:ask_task:),
                "job" : (:ask_task:),
                "方位" : (:ask_victim:),
                "洪安通" : "这三个字是你说的吗？",
                "教主" : (: ask_ob, "hong" :),
                "苏荃"   : "没规没矩的。",
                "夫人" : (:ask_ob, "su":),
                "胖头陀" : (: ask_ob, "pang" :),
                "陆高轩" : (:ask_ob, "lu":),
                "陆大夫" : (:ask_ob, "lu":),
                "无根道人" : (:ask_ob, "wu":),
                "赤龙使" : (:ask_ob, "wu":),
                "许雪亭" : (:ask_ob, "xu":),
                "青龙使" : (:ask_ob, "xu":),
                "殷锦" : (:ask_ob, "yin":),
                "黄龙使" : (:ask_ob, "yin":),
                "张淡月" : (:ask_ob, "zhang":),
                "黑龙使" : (:ask_ob, "zhang":),
                "zhang" : (:ask_ob, "zhang":),
                "钟志灵" : (:ask_ob, "zhong":),
                "白龙使" : (:ask_ob, "zhong":), 
                "神龙岛" : "神龙岛在汝州的东北方向，从塘沽口出海便到。",
        ]));

	setup();
        ::create();

	carry_object("/clone/weapon/panguanbi")->wield();
	carry_object("/clone/misc/cloth")->wear();
}

string ask_jiao()
{
        object me = this_player();

        if( me->query("sg/cured") ) 
                return "无耻的叛徒，还不给我滚！！！";

        if( !me->query("sg/spy") )
                return "这是敝教的秘密，有什么好问的？！";

        return "关于教中的详情，你去问胖头陀吧。";
}

string ask_wan()
{
        object me = this_player();

        if( me->query("sg/cured") ) 
                return "无耻的叛徒，还不给我滚！！！";

        if( !me->query("sg/spy") )
                return "这是敝教的秘密，有什么好问的？！";

        return "豹胎易筋丸在胖头陀那儿。";
}

string ask_exp()
{
        object me = this_player();

        if( me->query("sg/cured") ) 
                return "无耻的叛徒，还不给我滚！！！";

        if( !me->query("sg/spy") )
                return "你不在敝教，功劳何从谈起？";

        return "我不太清楚，你还是去问胖头陀吧。";
}

string ask_victim()
{
        object me = this_player();

        if( me->query("sg/cured") ) 
                return "无耻的叛徒，还不给我滚！！！";

        if( !me->query("sg/spy") )
                return "你不在敝教，功劳何从谈起？";

        return "我不太清楚，你还是去问黑龙使吧。";
}

string ask_ob(string id)
{
        object me = this_player();

        if( me->query("sg/cured") ) 
                return "无耻的叛徒，还不给我滚！！！";

        if( !me->query("sg/spy") )
                return "你不在敝教，功劳何从谈起？";

        return "关于教中的详情，你去问瘦头陀吧。";
}

string ask_task()
{
        object me = this_player();
        string str;

        if( me->query("sg/cured") )
                return "无耻的叛徒，还不给我滚！！！\n";

        if( !me->query("sg/spy") )
                return "这是敝教的秘密，有什么好问的？！\n";

        if( (int)me->query("sg/exp") < 100 )
                return "就凭你在教中的表现，我怎么能付于你重任？";

        if( !me->query("sgjob") ) {
                if( mapp(me->query("sg_ok")) ) {
                        me->delete("sg_ok");
                        command("thumb " + me->query("id"));
                }
                if( !(str = assign_job(me)) )
                        return "眼下没有适合你的教务，你下次再来吧。";
                return  str + "。";
        }

        if( time() > (int)me->query("sgjob/assigntime") + 3600 ) {
                me->delete("sgjob");
                command("nod " + me->query("id"));
                if( !(str = assign_job(me)) )
                        return "眼下没有适合你的教务，你下次再来吧。";
                return  str + "。";
        }

        return "你先去把当前的任务完成了，再来问我。";
}

private int is_suitable(object victim, object killer)
{
        mapping map;
        object room;

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

string assign_job(object me)
{
        object ob, victim;
        mapping map;
        string *times;
        mixed victim_list;

        if( !present("mianzhao", me) ) {
                ob = new(SGZHAO);
                ob->set("owner", me);
                ob->move(me);
                message_vision("$N给了$n一" + ob->query("unit") + ob->name() + "。\n", this_object(), me);
        }

        if( mapp(map = me->query("sg_victim")) ) {
                times = keys(map);
                for(int i = 0; i < sizeof(times); i++) {
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

        log_file("test/ShenlongJob", sprintf("%s于%s时被指派去追杀%s\n", me->query("name"), ctime(time()), me->query("sgjob/victim_name")));

        return "你去把" + me->query("sgjob/victim_name") + "(" + me->query("sgjob/victim_id")  + ")" + "杀了";
}

/*
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
*/
