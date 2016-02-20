//Cracked by Roath
// /d/xingxiu/house.c
// Jay 3/26/96

inherit ROOM;

void create()
{
        set("short", "巴依家院");
        set("long", @LONG
这是一个巴依家的庭院。门口大树的树荫投到院子里，让人觉得很凉快。
院子东面是巴依的客厅，西边就是小镇大街。
LONG
        );
        set("exits", ([ 
        "west" : __DIR__"beijiang",
        "east" : __DIR__"house1",
]));
        set("objects", ([
                __DIR__"npc/kid": 1,
                __DIR__"npc/bayi": 1 ]) );
        set("no_clean_up", 0);
        set("outdoors", "xingxiuhai");

	set("cost", 1);
        setup();
//        replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
        if (!wizardp(me) && objectp(present("hu laoye", environment(me))) && 
                dir == "east")
                return notify_fail("胡老爷说: 我把阿凡提关在我的客厅里了，谁也不许进去。\n");
        return ::valid_leave(me, dir);
}

