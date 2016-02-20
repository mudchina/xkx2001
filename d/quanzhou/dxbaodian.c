//Cracked by Roath
// dxbaodian.c 大雄宝殿
// qfy Nov 3, 1996

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "大雄宝殿");
	set("long", @LONG
石庭尽头，便是大雄宝殿。相传建殿之日，有紫云飘绕盖地，故又称「紫
云大殿」。殿上斗拱间雕着二十四尊美丽的「飞天」(fairies)， 雁行整齐，
展翅欲飞。殿内安祥跌坐五尊大佛，中间是唐玄宗的「御赐佛像」释加牟尼佛，
余者依次为南方宝生佛，西方阿弥陀佛，东方阿众佛，北方成就佛。后面是形
态各异的十八罗汉。
LONG
        );

        set("exits", ([ /* sizeof() == 4 */
		"north" : __DIR__"yuetai",
		"south" : __DIR__"tianwang",
	]));

	set("item_desc",([
                "fairies" : "有的飞仙手持民间乐器，有的捧着文房四宝，清歌曼舞\n"
			    "屋梁之间，叫人仿佛听见一派仙乐从天而降，隐约耳际。\n",
	]));

        set("objects", ([ 
		__DIR__"npc/monk" : 1,
        ]));

        set("no_clean_up", 0);

	set("cost", 0);
        setup();
	replace_program(ROOM);
}
