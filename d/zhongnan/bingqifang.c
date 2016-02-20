//Cracked by Roath
// /d/zhongnan/bingqifang.c 兵器房
// sdong

inherit ROOM;

void create()
{
        set("short", "兵器房");
        set("long", @LONG
这里是重阳宫的兵器房，墙上各处挂了许多长剑，短剑，竹剑和拂尘。
LONG
		  );

		  set("exits", ([
					 "south" : __DIR__"yinwutin",
		  ]));

        set("objects", ([
                __DIR__"obj/changjian" : 3,
                __DIR__"obj/duanjian" : 1,
                __DIR__"obj/zhujian" : 1,
                "/clone/weapon/fuchen" : 4,
        ]));

        set("cost", 0);
        setup();
}

int valid_leave(object me, string dir)
{
        object *inv;
        int i, j=0;

        inv = all_inventory(me);

        for (i=0; i<sizeof(inv); i++) {
                if ((string)inv[i]->query("skill_type")=="sword") j++;
                if ((string)inv[i]->query("skill_type")=="blade") j++;
        }
        
        if ( j == 1 ) me->set_temp("marks/剑", 1);
        if ( j > 1 ) return notify_fail("别那么自私！你不能带走超过一把兵器。\n");

        return ::valid_leave(me, dir);
}

