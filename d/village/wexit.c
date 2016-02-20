//Cracked by Roath
// Room: /d/village/eexit.c

inherit ROOM;

void create()
{
	set("short", "西村口");
	set("long", @LONG
这里是华山脚下，虽然远离县城，却没有什麽山贼草寇在附近出没。
东面是一个小村庄，看来村子里人家不多，村民们过着日出而作，日落而
息的宁静生活。北边有间破房子。村外是一座小山丘。
LONG
	);

	set("exits", ([ /* sizeof() == 2 */
	"east" :__DIR__"nwroad1",
	"north" : __DIR__"shack",
	"westup" : "/d/xingxiu/xxroad3",
]));
	
        set("objects", ([ __DIR__"npc/kid": 2 ]) );
        set("no_clean_up", 0);
        set("outdoors", "xx" );

	set("cost", 1);
        setup();
}
int valid_leave(object me, string dir)
{
    if ( dir == "westup" && me->query_condition("hz_job") )
           return notify_fail("你身负巡山任务，不能轻离职守！\n");

    return ::valid_leave(me, dir);
}

