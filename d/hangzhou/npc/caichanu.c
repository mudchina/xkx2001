//Cracked by Roath
// caichanu.c

inherit NPC;

void create()
{
	set_name("采茶女",({ "girl" }) );
        set("gender", "女性" );
        set("age", 19);
        set("long", "这是个水灵灵的农家女，正在嘻嘻哈哈的忙碌着。\n");

//      set("shen", -100);
        set("shen_type", 1);
        set("str", 15);
        set("dex", 18);
        set("con", 15);
        set("int", 17);
        set("combat_exp", 200);
        set_temp("apply/attack", 5);
        set_temp("apply/defense", 10);
	set("chat_chance", 5);
	set("chat_msg", ({
                "采茶女说道：侬今早去庙里上香伐，带我一道去好勿好？\n",
                "采茶女回答道：可以咯，不过侬要乖，勿要到处乱走呀。\n",
		"采茶女问道：明朝侬何去采花伐。\n",
		"采茶女笑道：侬可爱的伐得格啦。\n",
        }) );
        set("attitude", "peaceful");
        setup();

        carry_object("/d/city/obj/flower_shoe")->wear();
	carry_object("/d/quanzhou/obj/pink_cloth")->wear();
}

