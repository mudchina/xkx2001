//Cracked by Roath
// houyuan.c 后院
// xQin 11/00

inherit ROOM;

void create()
{
	set("short", "后院" );
	set("long", @LONG
这里是后院，北面是三清殿，西南面是一个圆形的门洞，有一条小路通
往后山。抬头可见东边天井大榕树的树冠。
LONG
	);
	set("exits", ([
		"southwest" : __DIR__"xiaolu1",
		"north" : __DIR__"hd_zoulang",
		"east" : __DIR__"tianjing",
	]));
	
	setup();
	replace_program(ROOM);
}


