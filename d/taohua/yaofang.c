//Cracked by Roath
//Kane

inherit ROOM;

void create()
{
	set("short", "药房");
	set("long", @LONG
这里是黄药师储藏平日炼制药材的地方，桃花岛弟子也经常到这里来取用
一些自己合用的药物。散发出阵阵沁人心肺花香的就是桃花岛名闻天下的九花
玉露丸，气味刺鼻的则是解毒灵药田七鲨胆散，颜色猩红如血的是疗伤圣药无
常丹。北面是一道长廊。
LONG
	);
	 set("exits", ([
                "north" : __DIR__"changlang2",
        ]));
        
	set("objects", ([
                __DIR__"npc/mianfeng" : 1,
        ]));
	
	setup();
	replace_program(ROOM);
}

/*
int valid_leave(object me, string dir)
{
        mapping myfam;
        myfam = (mapping)me->query("family");

        if ( (!myfam || myfam["family_name"] != "桃花岛") && dir == "north" )
                return notify_fail("桃花岛不留外客，你不能住在这里！\n");

        if ( me->query("gender") == "无性" && dir == "north" )
                return notify_fail("你不能住在这里！\n");

        return ::valid_leave(me, dir);
}
*/
