//Cracked by Roath
// shuyuan.c 华山书院
// qfy July 7, 1996

inherit ROOM;

void create()
{
	set("short", "华山书院");
	set("long", @LONG
这里是华山书院，靠墙是一排书架，摆满了书籍。右侧有张书桌，桌
上四宝俱备。书院经长有人打扫，十分干净整齐。
LONG
	);

	set("exits", ([
		"west" : __DIR__"donglang",
	]));

	set("objects", ([
		__DIR__"obj/zhengqi_book1" : 1,
		__DIR__"obj/zhengqi_book2" : 1,
		__DIR__"obj/sword_book" : 1,
		__DIR__"obj/ziyin_book1" : 1,
		__DIR__"obj/ziyin_book2" : 1,
	]));

	set("cost", 1);
	setup();
//	replace_program(ROOM);
}

void init()
{
	object *inv, me = this_player();
        int i, j=0;

	inv = all_inventory(me);

        for (i=0; i<sizeof(inv); i++) {
                if ((string)inv[i]->query("id")=="ziyin book"
                || (string)inv[i]->query("id")=="zhengqi book"
                || (string)inv[i]->query("id")=="sword book" ) j++;
	}

	me->set_temp("possbooks", j);
}

int valid_leave(object me, string dir)
{
        object *inv;
        int i, j=0;

        inv = all_inventory(me);

        for (i=0; i<sizeof(inv); i++) {
                if ((string)inv[i]->query("id")=="ziyin book"
		|| (string)inv[i]->query("id")=="zhengqi book"
		|| (string)inv[i]->query("id")=="sword book" ) j++;
        }

        if ( j == (int)me->query_temp("possbooks")+1 ) 
		me->set_temp("huashan/书", 1);
        if ( j > (int)me->query_temp("possbooks")+1 ) 
		return notify_fail("你考状元啊？一下拿那么多书！\n");

        return ::valid_leave(me, dir);
}
