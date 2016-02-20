//Cracked by Roath
inherit NPC;
int ask_aoyao();
void create()
{
        set_name("药铺小厮", ({ "yaopu xiaosi","xiaosi"}) );
        set("gender", "男性" );
        set("age", 17);
        set("long","他肌肤黄瘦，脸有菜色，可知经常受掌柜的刻薄。\n");
        set("str", 12);
        set("dex", 20);
        set("con", 13);
        set("shen_type", 0);
        set("combat_exp", 200);
        set("max_qi", 200);
        set("max_jing", 100);
        set("neili", 200);
        set("max_neili", 200);

        set("attitude", "friendly");
        set("inquiry", ([
            "配药" : (: ask_aoyao :),
            "炼药" : (: ask_aoyao :),
            "制药" : (: ask_aoyao :),
            "熬药" : (: ask_aoyao :),
            "药炉" : "客人是想自己「熬药」吗？",
       ]) );
        setup();
}

int ask_aoyao()
{
	object me = this_player();
	message_vision(query("name")+"向$N解释道：\n",me);
	message_vision("你先将盖子打开\[open lip\]，然后加入所需的药材\[add **** in lu\]\n",me);
	message_vision("记着倒一些水\[pour water\]，以免药材烧掉了。再扣好盖子\[close lip\]\n",me);
	message_vision("把炭盆点燃\[burn coal\]，等炉火旺起来了。就可以熬药了\[aoyao\]。\n",me);
	message_vision("熬药时要随时控制火候，还要不停搅拌，很累人的。药熬好了之后，\n",me);
	message_vision("记得先灭了火\[mie huo\]再取药\[qu yao\]，以免被烫伤。\n",me);
	return 1;
}
