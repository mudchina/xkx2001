//Cracked by Roath
// Room: /d/beijing/shizilukou.c

inherit ROOM;

void fix_exits_for_night(int is_night)
{
    if (is_night) {
	set("exits", ([ 
  	"north" : __DIR__"zhengyangdajie",
	]));
    }else{
	set("exits", ([ 
  	"north" : __DIR__"zhengyangdajie",
	"south" : __DIR__"yonganmen",
	]));
    }
}

void create()
{
	set("short", "十字路口");
	set("long", @LONG
这是一个普通的十字路口，路上行人来来往往，周围有些小贩，
兜售各种零碎百货。东面可以看到天坛祈年殿的殿顶，西面是山川
坛，南面是永安门，北面是正阳门外大街。
LONG
	);
	fix_exits_for_night(0);
	
	set("objects", ([
	__DIR__"npc/miscseller":1,
]));
	set("no_clean_up", 0);
	set("outdoors", "beijing");
	set("cost", 2);
	setup();
}

