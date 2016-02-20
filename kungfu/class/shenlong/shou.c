//Cracked by Roath
// shou toutuo 瘦头陀

inherit NPC;
// inherit F_MASTER;

#include <ansi.h>
#include <room.h>
#include "/d/REGIONS.h"
#include "/kungfu/class/shenlong/sg_ids.h"

#define SGDATA "/d/shenlong/data/"
#define SGCANGKU "/d/shenlong/cangku"

int auto_perform();

string ask_jiao();
string ask_wan();
string ask_exp();
string ask_task();
string ask_victim();
int ask_ob(string);

void create()
{
	set_name("瘦头陀", ({ "shou toutuo", "shou","toutuo" }));
//      set("nickname", "武当首侠");
	set("long",
		"又矮又胖，全身宛如个肉球。\n"
		"衣饰偏又十分华贵，长袍马褂都是锦缎。\n"
		"脸上五官挤在一起，倒是给人硬生生的搓成了一团。\n");
	set("gender", "男性");
	set("age", 44);
	set("attitude", "peaceful");
	set("shen_type", -1);
	set("str", 30);
	set("int", 28);
	set("con", 28);
	set("dex", 28);
	set("max_qi", 1000);
	set("max_jing", 1000);
	set("neili", 1200);
	set("max_neili", 1200);
	set("jingli", 1200);
	set("max_jingli", 1200);
	set("jiali", 60);
	set("combat_exp", 300000);
	set("score", 50000);

	set_skill("force", 120);
	set_skill("dulong-dafa", 100);
	set_skill("dodge", 100);
	set_skill("lingshe-shenfa", 100);
	set_skill("strike", 120);
	set_skill("huagu-mianzhang", 120);
	set_skill("parry", 120);
	set_skill("hook", 120);
	set_skill("ruyi-gou", 120);

	map_skill("force", "dulong-dafa");
	map_skill("dodge", "lingshe-shenfa");
	map_skill("strike", "huagu-mianzhang");
	map_skill("parry", "ruyi-gou");
	map_skill("hook", "ruyi-gou");

	prepare_skill("strike", "huagu-mianzhang");

	create_family("神龙教", 2, "教众");

        set("chat_chance", 20);
        set("chat_msg_combat",({
                (:auto_perform:),
        }));

        set("inquiry", ([
                "神龙教" : (:ask_jiao:),
                "豹胎易筋丸" : (:ask_wan:),
                "教务" : (:ask_task:),
                "功劳"   : (:ask_exp:),
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

	carry_object("/clone/misc/cloth")->wear();
	carry_object("/clone/weapon/hook")->wield();
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

string ask_task()
{
        object me = this_player();

        if( me->query("sg/cured") )
                return "无耻的叛徒，还不给我滚！！！\n";

        if( !me->query("sg/spy") )
                return "这是敝教的秘密，有什么好问的？！\n";

        return "想专门杀人找青龙使，否则找我师弟胖头陀。";
}

string ask_victim()
{
        object me = this_player();

        if( me->query("sg/cured") ) 
                return "无耻的叛徒，还不给我滚！！！";

        if( !me->query("sg/spy") )
                return "你不在敝教，功劳何从谈起？";

        return "我只知道教中人士的方位，你可以向黑龙使打听教外的消息。";       
}

int ask_ob(string id)
{
        object *obj, ob, place, cangku;

        if( !this_player()->query("sg/spy") ) { 
                say("这是敝教的秘密，有什么好问的？！\n");
                return 1;
        }

        if( !(cangku = find_object(SGCANGKU)) )
                cangku = load_object(SGCANGKU);

        if( member_array(id, keys(ids)) == -1)
                return 0;

        obj = filter_array(children("/kungfu/class/shenlong/" + id + ".c"), (: clonep :));

        if( !sizeof(obj) ) {
                command("whisper " + this_player()->query("id") + " " + "叹！" + ids[id] + "被人杀了！");
                return 1;
        }

        ob = obj[random(sizeof(obj))];
        place = environment(ob);

        command("whisper " + this_player()->query("id") + " " + ids[id] + "现在在" + region_names[explode(base_name(place), "/")[1]] + (string)place->query("short") + "。");
        return 1;
}

