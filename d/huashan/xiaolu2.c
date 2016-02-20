//Cracked by Roath
// xiaolu2.c 华山后山小路
// qfy 7/9/1996

inherit ROOM;

void create()
{
        set("short", "小山路");
	set("long", @LONG
小路顺着山脊一路宛延而下至华山后山里。此处是华山前辈避世之处
，轻易见不得人迹。就连华山弟子若是不得传招，也不能来此。南方的几
栋小屋，便是华山前辈的居所。
LONG
        );

        set("exits", ([ /* sizeof() == 2 */
	  	"northup" : __DIR__"xiaolu1",
		"west" : __DIR__"xiaozhu",
	]));

        set("objects", ([
                CLASS_D("huashan") + "/daizi" : 1, 
        ]));

	set("outdoors","huashan");

	set("cost", 2);
        setup();
}

int valid_leave(object me, string dir)
{
    mapping myfam;
    myfam = (mapping)me->query("family");

    if ( (!myfam || myfam["family_name"] != "华山派") && dir == "west" 
    && objectp(present("shi daizi", environment(me))) )
           return notify_fail("施戴子拦住你说：两位师叔祖不欲见客，请回吧。\n");

    return ::valid_leave(me, dir);
}
