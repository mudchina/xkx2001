//Cracked by Roath
// 白玉峰
// maco
#include <ansi.h>

inherit ROOM;
string look_skeleton();
string look_sword();

void create()
{
	set("short", "白玉峰大殿");
	set("long", @LONG
大殿上到处都是骸骨(skeleton)，殿中地下到处是大大小
小的玉制武器，刀枪剑戟都有，只是形状奇特，与中土习见的
迥然不同。
LONG
	);

	set("exits", ([
		"south" : __DIR__"jaderoad5",
		"north" : __DIR__"jadehall2",

	]));
	set("item_desc", ([
	"skeleton" : (: look_skeleton :),
	"white sword" : (: look_sword :),
	"sword" : (: look_sword :),
	]));
	set("jade_sword",1);
	set("cost", 1);
	setup();
}
void init()
{       
	object me, *obj, *inv;
	int i, j;
	me = this_player();
	obj = all_inventory(environment(me));
	for( i=0; i < sizeof(obj); i++ )
	{
		inv = all_inventory(obj[i]);
		for( j=0; j < sizeof(inv); j++ )
		{
			if( inv[j]->query("material") != "steel" 
			&& inv[j]->query("material") != "blacksteel" 
			&& inv[j]->query("material") != "iron" ) continue;
			if( inv[j]->query("equipped") && inv[j]->query("armor_type") == "cloth") {
			message_vision(HIW"一股巨大的磁力吸动$N身上所穿"+inv[j]->name()+HIW"，“磅”地一声，$N已被磁山吸得摔倒在地，一时爬也爬不起来！\n"NOR, obj[i]);
			me->add("jingli", -50);
			me->start_busy(3);
			}
			else if( inv[j]->query("equipped") && inv[j] == me->query_temp("weapon"))
			{
				message_vision(HIW"$N突觉一股极大力量拉动手中"+inv[j]->name()+HIW"，当的一声，"+inv[j]->name()+HIW"竟尔脱手，落在地上！\n"NOR, obj[i]);
			}
			else message_vision(HIW"$N身上"+inv[j]->name()+HIW"忽然被一道无形力量拉得飞出，铮地一声，掉在地下！\n"NOR, obj[i]);
			inv[j]->move(environment(me));

			if(inv[j]->query("weapon_prop/damage") >= 1 && inv[j]->query("weapon_prop/damage") < 30 ) {
			message_vision(HIW "只听见「啪」地一声，"+inv[j]->name()+ HIW"已在地上撞断成两截！\n" NOR,  obj[i] );
			inv[j]->set("name", "断掉的" + inv[j]->name());
			inv[j]->set("value", 0);
			inv[j]->set("weapon_prop", 0);
			}
			if(!me->is_busy()) me->start_busy(1);
		}
	}
}

string look_skeleton()
{
	string desc;
	if(query("jade_sword")) 
	desc = "一具直立的骸骨，身上还挂着七零八落的衣服，骨格形状仍然完整。\n"
	"骸骨右手抓着一柄白色长剑(white sword)，刺在另一具骸骨身上，看来当年是用这白剑杀死了那人。\n";
	else desc = "骸骨在地上垮作一堆。\n";
	return desc;

}

string look_sword()
{
	object sword = new("/d/xingxiu/obj/yujian");
	object me = this_player();
	string desc;
	if(query("jade_sword")) {
	message_vision("$N将玉剑轻轻从骸骨手中取过，两具骸骨支撑一失，登时喀喇喇一阵响，垮作一堆。\n", me);
	sword->move(this_player());
	delete("jade_sword");
	return "";
	}
	else return "你要看什么？\n";
}
