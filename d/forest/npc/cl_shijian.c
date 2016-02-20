//Cracked by Roath
// /d/huanghe/changle/npc/shijian.c 侍剑
// by aln 2 / 98

inherit NPC;

void create()
{
	set_name("侍剑", ({ "shijian" }));
	set("long", 
"她是长乐帮主的小丫鬟，脸庞略作圆形，倒也妩媚可喜。\n"
"她头发略见蓬松，雪白的赤足踏在一双绣花拖鞋中。\n");
	set("gender", "女性");
	set("age", 16);
	set("attitude", "friendly");
	set("shen_type", 1);
	set("str", 18);
	set("int", 28);
	set("con", 20);
	set("dex", 20);
   
	set("max_qi", 500);
	set("max_jing", 200);
	set("neili", 200);
	set("max_neili", 200);
	set("jiali", 10);
	set("combat_exp", 5000);
	set("score", 100);

	set_skill("force", 40);
	set_skill("dodge", 30);
	set_skill("unarmed", 30);
	set_skill("parry", 20);

	setup();
	carry_object("/d/city/obj/pink_cloth")->wear();
}
