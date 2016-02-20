//Cracked by Roath
// 神雕
// qfy July 10, 1996

inherit NPC;

void create()
{
        set_name("神雕", ({ "shen diao", "diao" }) );
        set("race", "飞禽");
	set("subrace","走禽");
        set("age", 60);
        set("long", 
"一头丑陋之极的大雕，全身羽毛疏疏落落，似是被人拔去了一大半似\n"
"的，毛色黄黑，显得甚是肮脏。这雕钓嘴弯曲，头顶生著个血红的大\n"
"肉瘤，双腿奇粗，羽翼甚短，不知如何飞翔，只是高视阔步，自有一\n"
"番威武气概。\n");
        set("attitude", "peaceful");

        set("limbs", ({ "头部", "身体", "翅膀", "爪子", "尾巴" }) );
        set("verbs", ({ "bite", "claw" }) );

        set("max_jing", 1000);
        set("max_qi",   1000);
        set("max_neili",1000);
        set("neili",    1000);
        set("jiali",     100);

        set("combat_exp", 100000);
        set_temp("apply/attack", 90);
        set_temp("apply/damage", 90);
        set_temp("apply/dodge",  90);
        set_temp("apply/armor",  90);

	set_skill("dodge", 120);
	set_skill("claw", 120);

        set("chat_chance", 10);
        set("chat_msg", ({
		"神雕正满含敌意地瞪视着你。\n",
		"神雕“呱”的叫了一声。\n",
                "神雕迈著大步在洞前走来走去。\n",
		"神雕在山洞前点了三下头，叫了三声，回头望著你。\n",
        }) );

	setup();
}
