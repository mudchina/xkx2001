//Cracked by Roath
// /d/forest/npc/cl_bangzhong3.c  帮众
// by aln 2 / 98

inherit NPC;

string ask_food();

void create()
{
	set_name("帮众", 
              ({ "changle bangzhong", "bangzhong" }));
        set("title", "长乐帮豹捷堂");
        set("fam", "长乐帮");
	set("long", 
		"这是一个惯于为非作歹的长乐帮众。\n"
		"他眼珠乱转，似乎正在想什么坏主意。\n");
	set("gender", "男性");
	set("age", 25);
	set("attitude", "friendly");
	set("shen_type", -1);
	set("str", 23);
	set("int", 20);
	set("con", 20);
	set("dex", 23);

	set("max_qi", 300);
	set("max_jing", 200);
	set("max_neili", 100);
        set("neili", 100);
	set("combat_exp", 20000);
	set("score", 1000);

	set_skill("force", 50);
	set_skill("dodge", 40);
	set_skill("cuff", 50);
	set_skill("parry", 50);

        set("inquiry", ([
                "长乐帮" : "这里就是长乐帮总舵所在地。",
                "司徒横" : "我对我们帮主老人家的景仰之情，有如滔滔江水连绵不绝。",
                "豹捷堂" : "自从展香主蒙冤后，豹捷堂就每况愈下。",
                "展香主" : "他被关在石室。",
                "展飞" : "他被关在石室。",
                "香主" : "各位香主的任命由帮主老人家说了算。",
                "贝海石" : "贝大夫在弊帮劳苦功高，颇得帮主信任。",
                "帮主" : "我家帮主司徒大爷乃威镇江南的“东霸天”也。",
                "食物" : (: ask_food :),
                "菜" : (: ask_food :),
                "food" : (: ask_food :),
                "酒" : "你帮务在身，还是喝点水解解渴吧。",
                "drink" : "你帮务在身，还是喝点水解解渴吧。",
                "水" : "你随便拿一个能装水的来装。",
                "water" : "你随便拿一个能装水的来装。",
        ]));

	setup();

 	carry_object("/clone/weapon/changjian")->wield();
}

string ask_food()
{
        object ob, ling, me = this_player();
        string myfam;

        if( is_fighting() )
                return RANK_D->query_rude(me) + "瞎了眼没见我正忙着？！";

        myfam = (string)query("fam");
        if( (string)me->query_temp("bangs/fam") != myfam )
                return RANK_D->query_rude(me) + "莫非是想打听我帮的秘密吧。";

        if( uptime() < (int)query("foodtime") + 30 )
                return "现在没有酒菜。";

        if( stringp(me->query_temp("bangs/pos")) ) {
                command("bow " + me->query("id"));
                set("foodtime", uptime());
                ob = new("/d/hangzhou/obj/fish");
                ob->move(me);
                message_vision("$N将一" + ob->query("unit") + ob->name() + "奉给$n。\n", this_object(), me);
                return "香主您老人家辛苦了。";
        }

        if( !(ling = present("bang ling", me)) )
                return RANK_D->query_rude(me) + "竟连自己的帮令都管不住！";

        if( (string)ling->query("owner") != me->query("id") )
                return RANK_D->query_rude(me) + "竟连自己的帮令都管不住！";

        command("nod");
        set("foodtime", uptime());
        switch((int)ling->query("score")/50) {
        case 0: ob = new("/d/city/obj/peanut"); break;
        case 1: ob = new("/d/city/obj/tofu"); break;
        case 2: ob = new("/d/city/obj/baozi"); break;
        case 3: ob = new("/d/city/obj/jitui"); break;
        case 4: ob = new("/d/hangzhou/obj/shrimp"); break;
        case 5: ob = new("/d/city/obj/gourou"); break;
        case 7: ob = new("/d/city/obj/ham"); break;
        default: ob = new("/d/city/obj/kaoya"); break;
        }

        ob->move(me);
        message_vision("$N将一" + ob->query("unit") + ob->name() + "奉给$n。\n", this_object(), me);
        return RANK_D->query_respect(me) + "辛苦了。";
}
