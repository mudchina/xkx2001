//Cracked by Roath
// room: /d/xingxiu/btroad
// Jay 10/8/96

inherit ROOM;

void create()
{
        set("short", "小路");
        set("long", @LONG
这里是扬州城外的一条小路，阴气森然。西面有个小土丘，东边是通往扬州
城的官道。
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

