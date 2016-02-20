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

#define UNIQUE  10000
#include <weapon.h>
#include <ansi.h>

inherit SWORD;
inherit F_UNIQUE;
inherit F_AUTOLOAD;

int query_autoload() { return 1; }

void create()
{
	set_name(MAG"紫晶箫"NOR, ({ "zijing xiao", "zijing", "xiao" }) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("long", "这是一把由水晶制成的洞箫，箫身隐隐有紫色光华在流动，一看即知此品绝非俗物。\n");
		set("wield_msg", HIM"只见紫光一闪，$N从腰间抽出一把晶莹剔透的$n"+HIM"握在手中。\n"NOR);
		set("unwield_msg", HIM"见紫光顿逝，$N潇洒的把$n"+HIM"别在腰後。\n"NOR);
		set("unit", "支");
		set("material", "amethystum");
		set("value", UNIQUE);
		set("shape", "flute");
		set("sharpness", 2);
		set("rigidity", 3.8);
		set("ductile", 0.4);
	}
	init_sword(100);
	setup();
}

int wield()
{
	object me = environment();
	object ob = this_object();

	if( !wizardp(me) && me->query("id") != "txy" )
	{
		message_vision(MAG"祗见紫光一闪，$N手中$n"MAG"剧烈震荡，如箭离弦般地飞出，“铿啷啷”滚落在地。\n"NOR, me, ob);
		ob->move(environment(me));
		return 0;
	}
	else if (::wield())
	{
		return 1;
	}
		return 1;
}

#include "/d/taohua/obj/flute.h"
#include "/d/taohua/obj/music.h"
