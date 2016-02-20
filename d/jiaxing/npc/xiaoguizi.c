//Cracked by Roath
// Jay 9/26/96

inherit NPC;

string ask_for_zigong();

void create()
{
        set_name("小桂子", ({"xiao guizi", "guizi"}));
        set("title", "御膳房小太监");
        set("long",
                "这是御膳房小太监，有十四五岁的样子，是海老公的跟班。\n"
        );

        set("gender", "无性");

        set("attitude", "friendly");
        set("class", "eunach");

        set("age", 15);
        set("shen_type", 1);
        set("str", 25);
        set("int", 20);
        set("con", 20);
        set("dex", 25);
        set("max_qi", 100);
        set("max_jing", 100);
        set("combat_exp", 50);

        setup();

        carry_object("/clone/misc/cloth")->wear();
}

