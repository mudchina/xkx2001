//Cracked by Roath
// xu.c 许老板/d/quanzhou/npc/xu.c
// modified by aln  2 / 98

#include <ansi.h>
#include <dbase.h>

inherit NPC;
inherit F_DEALER;

#include "/d/REGIONS.h"

string ask_me();

void create()
{
	set_name("许老板", ({ "xu laoban", "xu" }));
        set_color("$YEL$");
	set("title", "鸿翔绸缎庄老板");
	set("shen_type", 1);

	set("str", 20);
	set("gender", "男性");
	set("age", 45);
	set("long", "鸿翔绸缎庄乃是许老板祖传的生意，到许老板已是第四代了。\n");
	set("combat_exp", 10000);
        set("qi", 300);
        set("max_qi", 300);
	set("attitude", "friendly");
	set_skill("unarmed", 50);
        set_skill("dodge", 50);
        set_temp("apply/attack", 30);
        set_temp("apply/defense", 30);

	set("vendor_goods", ({
		__DIR__"obj/gua",
		__DIR__"obj/jin_ao",
		__DIR__"obj/red_cloth",
		__DIR__"obj/qun",
		__DIR__"obj/guazi",
		__DIR__"obj/green_beixin",
		__DIR__"obj/xiupao",
		__DIR__"obj/zhouqun",
		__DIR__"obj/chaoxue",
	}));

        set("inquiry", ([
               "绸缎" : (: ask_me :),
               "silk" : (: ask_me :),
        ]));

            	
	setup();
        add_money("silver", 50);
}

void init()
{
	::init();
        add_action("do_list", "list");
        add_action("do_buy", "buy");
}

int accept_kill(object me)
{
        command("say 光天化日之下竟敢行凶杀人，没王法了吗？\n");
        me->apply_condition("killer", 100);
        kill_ob(me);
        return 1;
}

string ask_me()
{
        object obj, me = this_player();
        mapping prices;
        string *places, place;
        int price;

        if( !(obj = present("bang ling", me)) )
                return RANK_D->query_respect(me) + "不做生意，不必操心绸价。";

        if( (string)obj->query("job/type") != "买卖" )
                return RANK_D->query_respect(me) + "不做生意，不必操心绸价。";

        if( (string)obj->query("job/name") != CYN"绸缎"NOR )
                return "我只知道绸价，" + RANK_D->query_respect(me) + "还是去向别人打听吧。";

        if( !mapp(prices = obj->query("job/prices")) )
                return "最近绸价混乱，我不是太清楚。";

        price = 0;
        place = "city";
        places = keys(prices);
        for(int i = 0; i < sizeof(places); i++) {
                if( prices[places[i]] > price ) {
                        price = prices[places[i]];
                        place = places[i];
                }
        }

        return "听说" + region_names[place] + "一带绸价最高。";
}

