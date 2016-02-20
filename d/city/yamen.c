//Cracked by Roath
// Room: /city/yamen.c
// modified by aln  2 / 98

#define BANGZHU "/d/huanghe/npc/bangzhu"

#include <ansi.h>
inherit ROOM;

#include "/d/REGIONS.h"

string look_gaoshi();

void create()
{
	set("short", RED"衙门"NOR);
	set("long", @LONG
这里是衙门大门，两扇朱木大门紧紧关闭着。“肃静”“回避”的牌子分放
两头石狮子的旁边。前面有一个大鼓，显然是供小民鸣冤用的。几名衙役在门前
巡逻。大门边贴了一张安民告示(gaoshi)。
LONG
	);

        set("item_desc", ([
                "gaoshi" : (:look_gaoshi:),
        ]));

	set("exits", ([
		"north" : __DIR__"xidajie2",
		"south" : __DIR__"ymzhengting",
	]));

	set("objects", ([
		__DIR__"npc/yayi" : 4,
	]));

	set("cost", 1);
	setup();
}

int valid_leave(object me, string dir)
{
	if (!wizardp(me) && !me->query_temp("mark/巡捕") && dir == "south" 
	&& objectp(present("ya yi", environment(me))) )
		return notify_fail("衙役喝道：“威……武……。”\n");
	return ::valid_leave(me, dir);
}

string look_gaoshi()
{
        object *obj, room;
        string file, region, str = "";

        obj = filter_array(children(BANGZHU), (: clonep :));     
        if( sizeof(obj) ) {
                for(int i = 0; i < sizeof(obj); i++) {
                if( room = environment(obj[i]) ) {
                file = base_name(room);
                if( strsrch(file, "/d/") == 0 && mapp(room->query("exits")) ) {
                region = explode(file, "/")[1];
                str += obj[i]->query("fam") + "  " + "最近经常出没在" + region_names[region] + room->query("short") + "。\n";
                }
		}
	        }
	}

        if( str == "" )
                str += "最近帮派活动萧条。\n";

        str += "\n浙江提督\n李克秀\n";
	return str;
}
