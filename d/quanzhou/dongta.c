//Cracked by Roath
// dongta.c 东塔
// qfy Nov 3, 1996

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "东塔");
	set("long", @LONG
东塔又名镇国塔，完工于南宋淳佑十年，共耗时十二年。建塔时是用堆土
坡运石办法，逐级建筑上去的。它浑体花岗石的仿木结构的楼阁式建筑，平面
八方，五层五楼，颇为少见。塔座作须弥作形，塔檐高翘，呈弯弧状向外舒展。
塔每层开四门设四龛，门外均伸出平座勾栏。塔顶高托沃金铜葫芦，映日闪闪
发光。八条铁链从塔顶上斜系于八个角脊(jiaoji)。塔每层的门龛两旁有武士、
天王、金刚、罗汉等浮雕计八十尊，神态各异。东塔须弥座束腰部分还有三十
九幅难得一见的青石浮雕佛传图。
LONG
        );

        set("exits", ([ /* sizeof() == 4 */
		"west" : __DIR__"yuetai",
	]));

        set("objects", ([ 
        ]));

        set("no_clean_up", 0);
	set("outdoors", "quanzhou");

	set("item_desc",([
                "jiaoji" : "每个角脊下还悬挂着小铜钟，全塔共四十个，风一吹便叮当作响。\n",
	]));

	set("cost", 1);
        setup();
	replace_program(ROOM);
}
