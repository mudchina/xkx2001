//Cracked by Roath
// room: /d/xingxiu/btroad
// Jay 10/8/96

inherit ROOM;

void create()
{
        set("short", "小路");
        set("long", @LONG
穿过了几片并不是很茂盛的树丛之后，一条崎岖的小土路从你的脚下延伸到
西边的一个小土丘，那里阴气森森，就连空气中似乎也布满了诡秘的味道。不禁
令你想转头回去扬州城里。
LONG
        );
        set("exits", ([ 
            "east" : __DIR__"xxroad2",
            "westup" : __DIR__"bthill",
        ]));
        set("objects", ([ 
            CLASS_D("baituo")+"/ma" : 1,
	    CLASS_D("baituo")+"/binu" : 2,
         ]) );
        set("outdoors","xingxiuhai");

	set("cost", 1);
        setup();
}
int valid_leave(object me, string dir)
{
   if (dir =="westup" && me->query("family/family_name")!="白驼山" ) {
        if (objectp(present("binu", environment(me))))
                return notify_fail(
	"婢女伸手挡住了你的去路：少庄主正在调训毒蛇，请改日再来。\n");

        if (objectp(present("qian yankai", environment(me))))
                return notify_fail(
	"马六德一伸手挡住了你的去路：少庄主正在调训毒蛇，请改日再来。\n");
   }      
   return ::valid_leave(me, dir);
}
