//Cracked by Roath
// shaluo.c 莎萝坪
// modified by qfy July 7, 1996

inherit ROOM;

void create()
{
        set("short", "莎萝坪");
	set("long", @LONG
沿着玉泉，踏过累累石涧，由山径迤逦而上，就来到了莎萝坪。从这
里山路开始陡峭，南面一条迂回盘旋的山道，称作「十八盘」，通往山上
。东北方隐隐听到轰轰之声，不绝於耳，好象有个瀑布。
LONG
        );

        set("exits", ([ /* sizeof() == 2 */
  	    "northwest" : __DIR__"path1",
  	    "southup" : __DIR__"qingke",
	    "northeast" : __DIR__"shanhong",
	]));

	set("objects", ([
		CLASS_D("huashan") + "/buyou" : 1,
        ]));

        set("no_clean_up", 0);
        set("outdoors", "huashan" );

	set("cost", 2);
        setup();
        replace_program(ROOM);
}
 
