//Cracked by Roath
// hongyao.c 何红药 

#include <ansi.h>
inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("何红药", ({ "he hongyao", "he", "hongyao" }));
	set_color("$YEL$");
	set("title", "五毒教堂主");
	set("shen_type", 0);
	set("gender", "女性");
	set_max_encumbrance(100000000);
	set("age", 45);
	set("long", "　　这女人就象个老乞婆，蓬头垢面，头发乱得象鸡窝，十指尤如鸡爪。满脸都\n是奇怪的伤痕，好象是被虫蛇撕咬所致，伤痕青黑不堪入目。\n");
	set("no_get_from", 1);
	set("max_jing", 5000);
	set("jing", 5000);
	set("max_jingli", 500);
	set("jingli", 500);
	set("max_qi", 500);
	set("qi", 500);
	set("PKS", 1000000);
	set("vendor_goods", ({
		 DRUG_D("jinchuang"),
		 DRUG_D("sheyao"),
		}) );
	set_skill("force", 100);
	set_skill("parry", 100);
	set_skill("unarmed", 100);
	set_skill("dodge", 100);
	set_temp("apply/attack", 120);
	set_temp("apply/attack", 120);
	set_temp("apply/damage", 50);
	set("combat_exp", 40000);
	set("attitude", "friendly");
	setup();
	carry_object(DRUG_D("guiyuan"))->set("quantity", 3);
	carry_object(DRUG_D("yangxin"))->set("quantity", 3);
	carry_object("/d/dali/obj/shedu.c")->set("quantity", 3);
}
void init()
{
	::init();
	add_action("do_list", "list");
	add_action("do_buy", "buy");
	add_action("do_sell", "sell");
	add_action("do_value", "value");
}
void unconcious()
{
	message_vision("\n突然，只见$N闪身拉开柜台下一道暗门，钻了进去，咔嚓从里边把门锁上了。\n", this_object());
	destruct(this_object());
}
void die()
{
	message_vision("\n$N死了。\n", this_object());
	destruct(this_object());
}
int do_sell(string arg)
{
	object ob;
	int value;

	if (!arg || !(ob = present(arg, this_player()))) return notify_fail("你要卖什么？\n");
	if (ob->query("money_id")) return notify_fail("你想卖「钱」？？\n");
	if (is_vendor_good(arg) != "") return notify_fail("卖给你好不好？\n");
	if (ob->query("medicine") < 1) return notify_fail("这东西你还是自己留着吧。\n");

	value = ob->query("value");
	if (value < 30) write(ob->query("name") + "一文不值！\n");
	else if (value > 1000000 ) return notify_fail("此乃至宝，小的可买不起！\n");
	else
	{
		message_vision("$N卖掉了一" + ob->query("unit") + ob->query("name") + "给$n。\n", this_player(), this_object());
		MONEY_D->pay_player(this_player(), value * 70 / 100);
		if (value < 50) destruct(ob);
		else
		ob->move(this_object());
		ob->set("quantity", 1);
	}
	return 1;
}
int do_list()
{
	string *goods;
	object *inv;
	int i;

	inv = all_inventory(this_object());

	if (!sizeof(inv) && !arrayp(goods = query("vendor_goods"))) return notify_fail("目前没有可以卖的东西。\n");
	printf("你可以向%s购买下列物品：\n", query("name"));
	for (i = 0; i < sizeof(inv); i++)
	if (!inv[i]->query("equipped") && !inv[i]->query("money_id"))
	printf("%30-s：%s\n", inv[i]->short(), MONEY_D->price_str(inv[i]->query("value") * 6 / 5));
	if (arrayp(goods = query("vendor_goods")))
	for (i = 0; i < sizeof(goods); i++)
	printf("%30-s：%s\n", goods[i]->short(), MONEY_D->price_str(goods[i]->query("value")));
	return 1;
}
