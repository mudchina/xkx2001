//Cracked by Roath
// room: /d/xingxiu/btshan
// Jay 3/27/96
// maco 2/17/2000

inherit ROOM;

void create()
{
	set("short", "白驼山山门");
	set("long", @LONG
这是传说中神秘的白驼山。远远望去，两座白沙堆积形成的山峰好
像一只骆驼的脊背。一座山门立在你的眼前。山门后一条大道通向一座
山腰上的山庄。那里是「西毒」欧阳锋的白驼山庄。另有一条小路曲折
通往西北。
LONG
	);
	set("exits", ([ 
	    "east" : __DIR__"btshan",
	    "northwest" : "/d/baituo/road3",
	    "westup" : "/d/xingxiu/btyard",
	]));
	set("objects", ([ 
	    CLASS_D("baituo")+"/yin" : 1,
	    "/d/baituo/npc/jiading" : 2,
	]) );
	set("outdoors","xingxiuhai");

	set("cost", 1);
	setup();
}
int valid_leave(object me, string dir)
{
   if (dir =="westup" && me->query("family/family_name")!="白驼山" ) {
	if (objectp(present("jiading", environment(me))))
		return notify_fail("家丁挡住了你的去路：老爷正在练功，请改日再来。\n");
   }      
   return ::valid_leave(me, dir);
}

