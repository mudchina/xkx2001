//Cracked by Roath
// 大厅口 /d/shenlong/datingkou
// ALN Sep / 97

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "大厅口");
	set("long", @LONG
这是大厅的门口，向内可进入神龙教的大厅，门口站着许多神龙教的教徒，
全副武装，警惕地注视四周，从厅内依稀传来一个浑厚的声音，似乎里面正在
召开什么重要会议。
LONG
	);

	set("valid_startroom",1);
	set("exits", ([
		"enter" : __DIR__"dating",
                "west" : __DIR__"changlang",
	]));

	set("objects", ([
          //      "/kungfu/class/shenlong/heilong" : 1,
                "/d/shenlong/npc/hei" : 1,
                "/d/shenlong/npc/chi" : 1,
          //      "/kungfu/class/shenlong/dengbing" : 1,
	]));
	set("cost", 1);

	set("no_clean_up",0);
	setup();
	"/clone/board/shenlong_b"->foo();
}

int valid_leave(object me, string dir)
{
	mapping myfam = (mapping)me->query("family");
        object *inv;
        int haveguarder;

	if( !(me->query("sg/spy") || me->query("family/family_name") == "神龙教") && dir == "enter" ) {
                inv = all_inventory(this_object());
                for(int i = 0; i < sizeof(inv); i++ )
                        if( inv[i]->query("family/family_name") == "神龙教" || inv[i]->query("sg/spy") ) {
                                 haveguarder++;
                                 if( living(inv[i]) ) inv[i]->kill_ob(me);
                        }

                if( haveguarder > 0 )
		        return notify_fail("你也太目中无人了吧，这儿还有人守着呢。\n");
         }

	 return ::valid_leave(me, dir);
}

