//Cracked by Roath
// /d/emei/cangjing.c 藏经阁
// Shan: 96/09/23

#include <room.h>
inherit ROOM;

void create()
{
        set("short", "藏经阁");
	set("long", @LONG
小阁楼上便是峨嵋派的藏经阁了。这里都是密密麻麻，高及顶棚的书架。
窗口下有一张大桌子，桌上放了几本佛经。有个小师太正在向静道师太借书。
LONG
	);
	set("exits", ([
		"down" : __DIR__"chuwu",
	]));

        set("objects",([
                "d/emei/obj/yugajing0" : 1,
                "d/emei/obj/yugajing2" : 1,
                CLASS_D("emei") + "/jingdao" : 1,
        ]));

	set("cost", 0);
	setup();

}

int valid_leave(object me, string dir)
{
        if (  (dir == "down") && ( present("shu", this_player()) ) 
           && objectp(present("jingdao shitai", environment(me))) ) {
        message_vision("静道师太见$N想把经书拿走，上前说道：本阁经书不外借。\n", me);
        return notify_fail("\n");
        }

        return ::valid_leave(me, dir);
}


