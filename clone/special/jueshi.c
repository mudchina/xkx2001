//Cracked by Roath
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\
 * // Weapon sample for xkxII.							*
 * // Experiment by xQin on 9/99						*
 *										*
 * 名称(name)：器械的常用名称。同器械多名者，则采用金庸小说的说法或其最常用	*
 * 的名称。（如：马尾鬃做的长柄蝇拂，佛家称拂尘、道家称云扫、内宫称净鞭。因	*
 * 金庸小说通用拂尘，故为名。）							*
 *										*
 * 描述(description)：器械的模样描述。应该根据实际器械叙出该物的外形、特征、	*
 * 类型、用法、长处等等。							*
 *										*
 * wield_msg：装备该件器械时的动作描述。					*
 *										*
 * unwield_msg：收回该件器械时的动作描述。					*
 *										*
 * 单位(unit)：器械的数量单位，如果侠客行Ⅱ可以装备两件以上兵器，应该考虑增	*
 * 设一副、一对等多量单位的变化。						*
 *										*
 * 材料(material)：制造该件器械所用的主要材料。					*
 *										*
 * 价值(value)：器械的物价。稀世神兵(unique weapon)大都是无价之宝，应该避免	*
 * 再出现当今倚天剑值一两黄金的情况。						*
 *										*
 * 重量(weight)：器械的重量主要决定於该器械的材料与体积，换个说法同样也代表	*
 * 了该器械的材料与体积。打击型兵器，其重量越高，攻击力也就越大。同样，其打	*
 * 断对方兵器的击率也随之而增。							*
 *										*
 * 锋利(sharpness)：器械攻击时的接触面积。削刺类兵器，其接触面积越细微，伤	*
 * 害力也就越大。								*
 *										*
 * 硬度(rigidity)：器械材料的硬度，高硬度的器械耐压，在受切割时不容易断。	*
 *										*
 * 韧性(ductile)：韧性高的器械耐撞。（以上四项需要补充完整。）			*
 *										*
 * 特殊作用(special effect)：如有些兵器中可以放出暗器，有的兵器可以变为两件	*
 * 兵器，有些则可以锁拿打断对方兵器，有些有特殊的防御效果，有些兵器打斗中会	*
 * 发出声音扰乱对方。诸如此类等等...						*
 *										*
 * 形状(shape)：长、短、硬、软、曲、直、圆、方、钝、锐、粗、细、宽、窄、厚、	*
 * 扁等等，具体作用请补充。							*
 *										*
 * （请补充完整）								*
\* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#define UNIQUE	10000
#include <weapon.h>
#include <ansi.h>

inherit SWORD;
inherit F_UNIQUE;
inherit F_AUTOLOAD;

int query_autoload() { return 1; }

void create()
{
	set_name("绝世好剑", ({ "jueshi haojian", "jueshi", "sword", "jian" }) );
	set_color(HIW+BLK);
	set_weight(20000);
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("long", "这是一柄四尺来长，全身乌黑，出自东海拜剑山庄，经山庄三代铸剑师历时百年而成的剑中之王。\n");
		set("wield_msg", "刹那间，一道气壮山河的黑虹，宛似天际间忽起的闪电一般，出现在众人眼前！\n");
		set("unwield_msg", "但见$N将$n向天一直，数匹布条随风而起，将$n严严实实地裹了起来！\n");
		set("unit", "柄");
		set("material", "steel");
		set("value", UNIQUE);
		set("sharpness", 10);
		set("rigidity", 10);
		set("ductile", 10);
		set("shape", ({ "long", "sword" }) );
	}
	init_sword(140);
	setup();
}

int wield()
{
	object me = environment();
	object ob = this_object();
	int ret;

	if( !wizardp(me) && me->query("id") != "godness" )
	{
		message_vision(HIR"$N的手刚刚触摸到$n的剑柄，突然一股由天而生的力量自剑中穿来，将$N击出丈远！$n也随之掉落地上。\n"NOR, me, ob);
		me->receive_damage("qi", 500, "被绝世好剑击死了");
		me->receive_wound("qi", 100, "被绝世好剑击死了");
		ob->move(environment(me));
		return 0;
	}
	else if( ret = ::wield() )
	{
		message_vision(HIW+BLK"只见$N将一柄裹在帆布里的长剑缓缓抽出，乌黑的剑身带出来的却是王霸的气势！\n"NOR, me);
		me->add("neili", -200);
		call_out("special_effect", 1, me);
		return ret;
	}
}

int special_effect(object me)
{
	mapping weapon_prop;
	object *obj, *inv, weapon;
	int i, j;

	obj = all_inventory(environment(me));
	for( i=0; i < sizeof(obj); i++ )
	{
		if( obj[i]==me ) continue;
		inv = all_inventory(obj[i]);
		for( j=0; j < sizeof(inv); j++ )
		{
			if( !mapp(weapon_prop = inv[j]->query("weapon_prop")) ) continue;        
			if( inv[j]->query("skill_type")!="sword" ) continue;
			if( inv[j]->query("equipped") )
			{
				if(obj[i]->query("neili") > 5000)
				{
					obj[i]->add("neili", -100);
					tell_object(obj[i], HIW"你觉得手中之"+inv[j]->name()+HIW"在猛烈震动，幸而你双手紧握，才没有让它飞出！\n"NOR);
					continue;  
				}
				else
				{
					tell_object(obj[i], HIW"你觉得手中之"+inv[j]->name()+HIW"在猛烈震动，你把握不住，竟然脱手飞出！\n"NOR);
					tell_room(environment(me), YEL+obj[i]->name()+"一个把握不住，手中"+inv[j]->name()+YEL"竟然脱手飞出！\n"NOR, ({ obj[i] }));
				}
			}
			else if( obj[i]->is_character() )
				message_vision(HIY"$n身上所带之"+inv[j]->name()+HIY"忽然自动跃出，插在$N身前的地上，剑尖指天！\n"NOR, me, obj[i]);
			else message_vision(HIY+inv[j]->name()+HIY"忽然自$n飞出，插在$N身前的地上，剑尖指天！\n"NOR, me, obj[i]);
			inv[j]->move(environment(me));
		}
	}
}