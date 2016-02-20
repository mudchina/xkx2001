//Cracked by Roath
// huoji.c  药铺伙计
// modified by aln  2 / 98

inherit NPC;
inherit F_DEALER;

#include "/d/REGIONS.h"

string ask_me();

void create()
{
	set_name("药铺伙计", ({ "yaopu huoji", "huoji" }));
	set("str", 20);
	set("gender", "男性");
	set("age", 18);
	set("long", "他是平神医从乡下招来帮忙的。\n");
	set("combat_exp", 250);
	set("attitude", "peaceful");
	set("vendor_goods", ({
		DRUG_D("jinchuang"),
		DRUG_D("sheyao"),
		DRUG_D("yangjing")
	}));

        set("inquiry", ([
               "长白山人参" : (: ask_me :),
               "renshen" : (: ask_me :),
        ]));

	setup();
}

void init()
{
	::init();
        add_action("do_list", "list");
        add_action("do_buy", "buy");
}

string ask_me()
{
        object obj, me = this_player();
        mapping prices;
        string *places, place;
        int price;

        if( !(obj = present("bang ling", me)) )
                return RANK_D->query_respect(me) + "不做生意，不必操心参价。";

        if( (string)obj->query("job/type") != "买卖" )
                return RANK_D->query_respect(me) + "不做生意，不必操心参价。";

        if( (string)obj->query("job/name") != "长白山人参" )
                return "我只知道参价，" + RANK_D->query_respect(me) + "还是去向别人打听吧。";

        if( !mapp(prices = obj->query("job/prices")) )
                return "最近参价混乱，我不是太清楚。";

        price = 0;
        place = "city";
        places = keys(prices);
        for(int i = 0; i < sizeof(places); i++) {
                if( prices[places[i]] > price ) {
                        price = prices[places[i]];
                        place = places[i];
                }
        }

        return "听说" + region_names[place] + "一带参价最高。";
}
        
        
